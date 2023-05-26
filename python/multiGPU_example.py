import tensorflow as tf
import tensorflow_addons as tfa
import numpy as np
import os
import cv2
import glob
import random

'''
env :  tensorflow 2.12
1. dataset透過DISTRIBUTE_STRATEGY.experimental_distribute_dataset進行加速(不用也可以跑，速度比較慢)
2. training程序切出來，裡面包括 1)loss計算 2)minimize。跟minize不同的地方在於tensorflow有提供arg
   項目，所以可以透過arg把參數傳進去(包括dataset)
3. training程序透過DISTRIBUTE_STRATEGY.run來跑。每一個shad都會自己計算loss跟跑梯度運算，但梯度
   應該有集中以後才更新模型weights。每一個shad可以透過DISTRIBUTE_STRATEGY.reduce把loss資訊收回來。
'''

def gen_tfdataset(fileList, bs=32):
    strategy = tf.distribute.MirroredStrategy()
    DataGen = gen_img_generator(fileList)
    dataset = tf.data.Dataset.from_generator(DataGen,
                                             output_signature=(
                                                 tf.TensorSpec(shape=(128, 128, 3), dtype=tf.int8))
                                             )
    dataset = dataset.batch(bs,
                            drop_remainder=True,
                            num_parallel_calls=tf.data.AUTOTUNE)
    dataset = dataset.map(
        lambda x: (tf.cast(x, tf.float32) - 128.) / 255.,
        num_parallel_calls=tf.data.AUTOTUNE,
        deterministic=False)
    dataset = dataset.prefetch(tf.data.AUTOTUNE)
    dataset = strategy.experimental_distribute_dataset(dataset)
    return dataset


def camoudet(embeddingDim = 128):
    x = tf.keras.layers.Input(shape=(128, 128, 3), dtype=tf.float32, name="camoumodel_input")
    conv1 = tf.keras.layers.Conv2D(64, [3,3], padding='same', strides=[2, 2], activation=tf.keras.activations.gelu, kernel_regularizer=tf.keras.regularizers.L1(0.01))(x)
    spaEmbConv1 = spaEmbConv(conv1, spEmbSize=32)
    conv2 = tf.keras.layers.Conv2D(128, [3,3], padding='same', strides=[2, 2], activation=tf.keras.activations.gelu, kernel_regularizer=tf.keras.regularizers.L1(0.01))(spaEmbConv1)
    spaEmbConv2 = spaEmbConv(conv2, spEmbSize=64)
    conv3 = tf.keras.layers.Conv2D(256, [3,3], padding='same', strides=[2, 2], activation=tf.keras.activations.gelu, kernel_regularizer=tf.keras.regularizers.L1(0.01))(spaEmbConv2)
    spaEmbConv2 = spaEmbConv(conv3, spEmbSize=embeddingDim)
    
    # looking for the embedding that have most high correlation to all embeddings
    queryNo = spaEmbConv2.shape[1] * spaEmbConv2.shape[2]
    embeddings = tf.reshape(spaEmbConv2, [-1, queryNo, embeddingDim])
    embeddings_T = tf.transpose(embeddings, [0, 2, 1])
    corMat = tf.matmul(embeddings, embeddings_T) * (-tf.eye(queryNo) + tf.ones(queryNo))
    mask = tf.nn.softmax(tf.reduce_sum(corMat,axis = -1, keepdims=True), axis=0)
    candidateEmbedding = tf.reduce_sum(embeddings * mask, axis = 1, keepdims=False)

    return tf.keras.Model(inputs=x, outputs=candidateEmbedding)

def spaEmbConv(x, conv2dKernelSize=3, spEmbSize=128):
    '''
    new propsoed: spatial embedding convolution
    Each channel information shold be thinked as a feature.
    So we shold use an operator to embedding the information into a presentation once time.
    '''
    conv = tf.keras.layers.Conv2D(x.shape[-1], [conv2dKernelSize, conv2dKernelSize], padding="same", strides=[1, 1], kernel_regularizer=tf.keras.regularizers.L1(0.01), activation=tf.nn.tanh)(x) 
    rconv = tf.reshape(conv, [-1, conv.shape[1] * conv.shape[2] , conv.shape[3]])
    spaEmb = tf.keras.layers.Conv1D(spEmbSize, 1, padding="valid", strides=[1], kernel_regularizer=tf.keras.regularizers.L1(0.01))(rconv)
    nSpaEmb = tf.keras.layers.LayerNormalization()(spaEmb)
    return tf.reshape(nSpaEmb, [-1, conv.shape[1], conv.shape[2], spEmbSize])
    pass
    


def gen_img_generator(imgList, imgSize=128):
    """
    generate the image generator by the dataset
    """
    def gen():
        while (True):
            # shuffling the file list array
            random.shuffle(imgList)
            for img in imgList:
                yield cv2.resize(cv2.imread(img), (imgSize, imgSize))
            pass
        pass
    return gen

def lr_warmup_cosine_decay(global_step,
                           warmup_steps,
                           hold = 0,
                           total_steps=0,
                           start_lr=0.0,
                           target_lr=1e-3):
    # source : https://stackabuse.com/learning-rate-warmup-with-cosine-decay-in-keras-and-tensorflow/
    # Cosine decay
    learning_rate = 0.5 * target_lr * (1 + np.cos(np.pi * (global_step - warmup_steps - hold) / float(total_steps - warmup_steps - hold)))

    # Target LR * progress of warmup (=1 at the final warmup step)
    warmup_lr = target_lr * (global_step / warmup_steps)

    # Choose between `warmup_lr`, `target_lr` and `learning_rate` based on whether `global_step < warmup_steps` and we're still holding.
    # i.e. warm up if we're still warming up and use cosine decayed lr otherwise
    if hold > 0:
        learning_rate = np.where(global_step > warmup_steps + hold,
                                 learning_rate, target_lr)
    
    learning_rate = np.where(global_step < warmup_steps, warmup_lr, learning_rate)
    return learning_rate

def main():
    """
    get a vector for describe the camouflage dress by using tensorflow
    """
    # training parameters 
    DISTRIBUTE_STRATEGY = tf.distribute.MirroredStrategy()
    TRAINING_ITER_NO = 5000
    with DISTRIBUTE_STRATEGY.scope():
        OPT = tf.keras.optimizers.AdamW(0.1, global_clipnorm=1)
    PIN_EMA = 1e-2

    """
    load the dataset
    """
    # setting the path of the dataset
    camouDatasetPath = "/workspace/stage2/dataset/camou_crop"
    normalDatasetPath = "/workspace/stage2/dataset/coco_crop"

    # list all the dataset
    camouFiles = glob.glob(os.path.join(camouDatasetPath, "*.jpg"))
    normalFiles = glob.glob(os.path.join(normalDatasetPath, "*.jpg"))

    # The tf.dataset will load the files by the file names
    camouTfDataset = gen_tfdataset(camouFiles, 128)
    normalTfDataset = gen_tfdataset(normalFiles, 128 * 4)

    iterCamouTfDataset = iter(camouTfDataset)
    iterNormalTfDataset = iter(normalTfDataset)

    global camouFeaPin
    camouFeaPin = tf.zeros([128], dtype=tf.float32)
    
    global model
    with DISTRIBUTE_STRATEGY.scope():
        model = camoudet()
    
    def training_step(camouImgs, normalImgs, iterNo):
        def loss():
            global camouFeaPin
            global model
            
            camouFeas = model(camouImgs)
            normalFeas = model(normalImgs)

            camouFeaPin = (1 - PIN_EMA) * camouFeaPin + PIN_EMA * tf.reduce_mean(camouFeas, axis=0) 

            # positive sample l2 distance
            posDist = tf.reduce_max(tf.square(camouFeas - tf.stop_gradient(camouFeaPin)))
            # negative sample l2 distance
            negDist = tf.reduce_min(tf.square(normalFeas -  tf.stop_gradient(camouFeaPin)))

            #triplet loss
            totalLoss = posDist - negDist + tf.reduce_sum(model.losses)
            
            return totalLoss
        
        # optimization
        OPT.lr = lr_warmup_cosine_decay(iterNo, 100, TRAINING_ITER_NO)
        OPT.minimize(loss, model.trainable_weights)
        # print("iter:{}  loss:{}".format(iterNo, loss()))
        return loss()

    for iterNo in range(TRAINING_ITER_NO):
        # loading the dataset
        camouImgs = next(iterCamouTfDataset)
        normalImgs = next(iterNormalTfDataset)
        
        ## single gpu
        # total_loss = training_step(camouImgs, normalImgs, iterNo)
        # print("iter:{}  loss:{}".format(iterNo, total_loss))

        ## multi gpus
        per_replica_losses = DISTRIBUTE_STRATEGY.run(training_step, args=(camouImgs, normalImgs, iterNo))
        total_replica_losses = DISTRIBUTE_STRATEGY.reduce(tf.distribute.ReduceOp.SUM, per_replica_losses, axis=None)
        print("iter:{}  loss:{}".format(iterNo, total_replica_losses))


        # save the model
        if (iterNo + 1) % 100 == 0 :
            model.save("/workspace/stage2/models/camoudet_{}.h5".format(iterNo))
                


    


if __name__ == '__main__':
    main()
    pass
