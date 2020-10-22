#####
# reshape the shapes of weights to flat form due to easy to handle 
# for other algorithms, such as evolutionary algorithmes.
# 
# This code is based on the TF2.4
# 
# 20201022 markliou
#####

import tensorflow as tf 
import numpy as np

def cnn():
    Input = tf.keras.Input([28, 28, 1])
    conv1 = tf.keras.layers.Conv2D(32, [3, 3], strides=(2, 2), padding="SAME", activation=tf.nn.relu)(Input) #[14,14]
    conv2 = tf.keras.layers.Conv2D(32, [3, 3], strides=(2, 2), padding="SAME", activation=tf.nn.relu)(conv1) #[7,7]
    conv3 = tf.keras.layers.Conv2D(32, [3, 3], strides=(2, 2), padding="SAME", activation=tf.nn.relu)(conv2) #[4,4]
    fc = tf.keras.layers.Flatten()(conv3)
    fc1 = tf.keras.layers.Dense(128, activation=tf.nn.relu)(fc)
    fc2 = tf.keras.layers.Dense(128, activation=tf.nn.relu)(fc1)
    fc3 = tf.keras.layers.Dense(128, activation=tf.nn.relu)(fc2)
    out = tf.keras.layers.Dense(1, activation=None)(fc3)

    return tf.keras.Model(inputs=Input, outputs=out)
pass 

def flatten_weights(model):
    flated_weights = np.concatenate([target_weights.numpy().flatten() for target_weights in model.weights])
    return flated_weights
pass 

def recover_flatten_weights(model, flated_weights):
    access_index = 0
    for model_tesnsor in model.weights:
        element_shape = model_tesnsor.shape.as_list()
        element_number = np.ones(element_shape).sum().astype('int')
        model_tesnsor.assign(flated_weights[access_index:access_index+element_number].reshape(element_shape))
        access_index += element_number
    pass
    return model
pass 

def main():
    cnn_model = cnn()
    # print(cnn_model.summary())
    
    # _output = cnn_model.predict(np.random.randn(32,28,28,1).astype('float32'))
    # print(_output)

    _output = cnn_model(np.random.randn(32,28,28,1).astype('float32'))
    print(_output)

    print(cnn_model.weights) # this give the all weights in the model
    # cnn_model.save('model')

    target_weights = cnn_model.weights[0] # assign the weights needed to be handled
    ## get the weights and store them
    target_weights_keeper = target_weights.numpy()
    print(target_weights_keeper)

    ## assign the 1 as the weights to model
    target_weights.assign(np.ones(target_weights.shape.as_list()))
    print(target_weights)

    ## assign the previous weihts to the mode
    target_weights.assign(target_weights_keeper)
    print(cnn_model.weights)

    ## flating the weights
    flated_weights = flatten_weights(cnn_model)
    print(flated_weights.shape)

    ## feed the flated weights to model
    recover_flatten_weights(cnn_model, flated_weights)
    print(cnn_model.weights)

    ## feed the flatten array to model
    print('=====')
    cnn_model_ts = cnn()
    flated_weights = flatten_weights(cnn_model_ts)
    print(cnn_model_ts(np.ones([32,28,28,1])))
    target_flated_weights = np.ones_like(flated_weights)
    recover_flatten_weights(cnn_model_ts, target_flated_weights)
    print(cnn_model_ts(np.ones([32,28,28,1])))
    # print(cnn_model.weights)
    recover_flatten_weights(cnn_model_ts, flated_weights)
    # print(cnn_model.weights)
    print(cnn_model_ts(np.ones([32,28,28,1])))
    print('=====')


pass 


if __name__ == "__main__":
    main()
pass 
