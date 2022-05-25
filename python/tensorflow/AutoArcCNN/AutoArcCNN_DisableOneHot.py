#!/usr/bin/python3
#####
# markliou 20171117
#####

import tensorflow as tf
import numpy as np
import tools


def construct_2dcnn(
                    x, # x = tf.placeholder(tf.float32, [batch_no, input_dim[0]*input_dim[1]]) # data entry point
                    struc_param,
                    input_dim, # 2D array
                    input_channel_dim,
                    output_dim
                    ):
    '''
    struc_param : [kernel size, layer number, output channel number ]
    x : data input point. This should be a flat form. 
    input_dim : the basic shape of x 
    input_channel_dim : the channel number of x 
    output_dim : how many labels need to be output
    '''
    kernel_size = struc_param[0]
    layer_no = struc_param[1]
    nodeno = struc_param[2]
    current_construct_layer_no = 0
    
    kernels, cl_biases, fc_weights, fc_biases = [], [], [], [] # building weights and biases containers
    
    ### construct weights and biases
    kernels.append(tf.Variable(tf.random_normal([kernel_size, kernel_size, 1, nodeno] ,stddev=(1/(input_dim[0]*input_dim[1])) ) ) ) # first layer
    cl_biases.append(tf.Variable( tf.zeros([nodeno] ))) # first layer's bias
    for i in range(1, layer_no): # create convlution layers (2~last layers)
        kernels.append(tf.Variable(tf.random_normal([kernel_size, kernel_size, nodeno, nodeno] ,stddev=(1/(nodeno)) ) ) )
        cl_biases.append(tf.Variable( tf.zeros([nodeno] )))
    pass
    
    fc_weights.append(tf.Variable(tf.random_normal([input_dim[0] * input_dim[1] * nodeno, nodeno] ,stddev=(1/(28*28*64)) ) )) # first fully connect layer
    fc_biases.append(tf.Variable( tf.zeros([nodeno] ))) # bias for first fully connect layer
    for i in range(1, 3): # create fully connect layers
        fc_weights.append(tf.Variable(tf.random_normal([nodeno, nodeno] ,stddev=(1/(nodeno)) ) ))
        fc_biases.append(tf.Variable( tf.zeros([nodeno] )))
    pass
    
    out_weights = tf.Variable(tf.random_normal([nodeno, output_dim]))
    out_bias = tf.Variable(tf.zeros([output_dim] ))
    
    ### construct the network
    
    # Reshape input picture
    x = tf.reshape(x, shape=[-1, input_dim[0], input_dim[1], input_channel_dim])
    
    layers = [] # initial the NN
    # building convolution layers
    layers.append(conv2d(x, kernels[0], cl_biases[0]))
    current_construct_layer_no += 1
    for i in range(1, layer_no):
        layers.append(conv2d(layers[i-1], kernels[i], cl_biases[i]))
        current_construct_layer_no += 1
    pass
    

    # building fully connected layers
    reshaped_feature_mapes = tf.reshape(layers[current_construct_layer_no - 1], [-1, fc_weights[0].get_shape().as_list()[0]])
    layers.append(fc(reshaped_feature_mapes, fc_weights[0], fc_biases[0]))
    current_construct_layer_no += 1
    
    for i in range(1, 3):
        layers.append(fc(layers[current_construct_layer_no - 1], fc_weights[i], fc_biases[i]))
        current_construct_layer_no += 1
        layers[current_construct_layer_no - 1] = tf.nn.elu(layers[current_construct_layer_no - 1])
    pass
    
    # output layer
    out = tf.add(tf.matmul(layers[current_construct_layer_no - 1], out_weights), out_bias)
    
    return out
pass

def conv2d(x, W, b, strides=1):
    x = tf.nn.conv2d(x, W, strides=[1, strides, strides, 1], padding='SAME')
    x = tf.nn.bias_add(x, b)
    return tf.nn.elu(x)
pass

def fc(x, W, b):
    x = tf.add(tf.matmul(x, W), b)
    return tf.nn.elu(x)
pass

def trans2onehot( sparse_ind, output_dim):
    onehoty = np.zeros([output_dim])
    try:
        for i in range(0,len(sparse_ind)):
            onehoty[i] = 1
        pass 
    except:
        onehoty[sparse_ind] = 1
    pass
    return onehoty
pass

###########################

# set the entry points for construct_2dcnn
input_dim = [28,28]
output_dim = 10
batch_size = 500
x = tf.placeholder(tf.float32, [None, input_dim[0]*input_dim[1]])
y = tf.placeholder(tf.float32, [None, output_dim])

pred = construct_2dcnn(x, 
                       struc_param = [3,6,32], 
                       input_dim = input_dim, 
                       input_channel_dim = 1, 
                       output_dim = output_dim)

###########################

# Import MNIST data
from tensorflow.examples.tutorials.mnist import input_data
# mnist = input_data.read_data_sets("./", one_hot=True)
# mnist = input_data.read_data_sets("/tmp/data/", one_hot=True)
mnist = input_data.read_data_sets("/tmp/data/") # This will disable the one hot transform function

# Parameters
learning_rate = 1E-3
training_iters = 10000000
display_step = 10

# Define loss and optimizer
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=pred, labels=y))
#cost = tf.reduce_mean(tf.nn.sigmoid_cross_entropy_with_logits(logits=pred, labels=y))
optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate).minimize(cost)

# Evaluate model
correct_pred = tf.equal(tf.argmax(pred, 1), tf.argmax(y, 1))
accuracy = tf.reduce_mean(tf.cast(correct_pred, tf.float32))

# Initializing the variables
init = tf.global_variables_initializer()

# Launch the graph
tfconfig = tf.ConfigProto()
tfconfig.gpu_options.allow_growth = True
model_saver = tf.train.Saver()
with tf.Session(config = tfconfig) as sess:

    tf_log_writer = tf.summary.FileWriter("./log", graph = sess.graph) # for tensorboard
    sess.run(init)
    step = 1
    epoch = 1
    
    # initial the stopping criteria
    validation_y = np.vstack([ trans2onehot(i, output_dim) for i in mnist.validation.labels[:5000] ])
    stop_criteria = tools.PQAlpha( sess.run(cost, feed_dict={x: mnist.validation.images[:5000], y: validation_y}) )
    # stop_criteria = tools.PQAlpha( sess.run(cost, feed_dict={x: mnist.validation.images[:5000], y_e: mnist.test.labels[:5000]}) )
    
    # Keep training until reach max iterations
    #while not (step * batch_size > training_iters) or (stop_criteria.Stop == True):
    while (stop_criteria.Stop == False):
        batch_x, batch_y = mnist.train.next_batch(batch_size)
        
        # trainform to one hot
        batch_y = np.vstack([ trans2onehot(i, output_dim) for i in batch_y ])
        
        sess.run(optimizer, feed_dict={x: batch_x, y: batch_y})
        stop_criteria.update(sess.run(cost, feed_dict={x: mnist.validation.images[:5000],
                                                       y: validation_y}))
        
        if( (step * batch_size % 55000) == 0): # epoch, training=55000, validation=5000, test=10000
            # print("validation:{}".format(sess.run(cost, feed_dict={x: mnist.validation.images[:5000],
                                                                   # y: mnist.test.labels[:5000]})))
            print("epoch {}".format(epoch))
            epoch += 1
        pass 
        
        if step % display_step == 0:
            # Calculate batch loss and accuracy
            loss, acc = sess.run([cost, accuracy], feed_dict={x: batch_x,
                                                              y: batch_y})
            print("Iter " + str(step*batch_size) + ", Minibatch Loss= " + \
                  "{:.6f}".format(loss) + ", Training Accuracy= " + \
                  "{:.5f}".format(acc))
        step += 1
        
        # # save models
        # model_saver.save(sess, './models/AutoArc', global_step=step)
        
    print("Optimization Finished!")
    
    # saving the model
    print(model_saver.save(sess, './models/AutoArc'))
    
    
    # Calculate accuracy for 256 mnist test images
    test_y = np.vstack([ trans2onehot(i, output_dim) for i in mnist.test.labels[:256] ])
    print("Test Accuracy:", \
        sess.run(accuracy, feed_dict={x: mnist.test.images[:256],
                                      y: test_y}))

pass 

# seperate the inference part into another session
model_container = tf.train.import_meta_graph('./models/AutoArc.meta')
with tf.Session() as sess:
    sess.run(init)
    model_container.restore(sess, './models/AutoArc')
    # Calculate accuracy for 256 mnist test images
    test_y = np.vstack([ trans2onehot(i, output_dim) for i in mnist.test.labels[:256] ])
    print("Test Accuracy:", \
        sess.run(accuracy, feed_dict={x: mnist.test.images[:256],
                                      y: test_y}))
pass

