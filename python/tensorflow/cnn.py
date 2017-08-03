'''
A Convolutional Network implementation example using TensorFlow library.
This example is using the MNIST database of handwritten digits
(http://yann.lecun.com/exdb/mnist/)

Author: Aymeric Damien
Project: https://github.com/aymericdamien/TensorFlow-Examples/
'''

from __future__ import print_function

import tensorflow as tf

# Import MNIST data
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets("/tmp/data/", one_hot=True)

# Parameters
learning_rate = 0.001
training_iters = 5000
batch_size = 1000
display_step = 10

# Network Parameters
n_input = 784 # MNIST data input (img shape: 28*28)
n_classes = 10 # MNIST total classes (0-9 digits)
dropout = 0.75 # Dropout, probability to keep units

# tf Graph input
x = tf.placeholder(tf.float32, [None, n_input])
y = tf.placeholder(tf.float32, [None, n_classes])
keep_prob = tf.placeholder(tf.float32) #dropout (keep probability)


# Create some wrappers for simplicity
def conv2d(x, W, b, strides=1):
    # Conv2D wrapper, with bias and relu activation
    x = tf.nn.conv2d(x, W, strides=[1, strides, strides, 1], padding='SAME')
    x = tf.nn.bias_add(x, b)
    #return tf.nn.relu(x)
    #return tf.nn.relu6(x)
    #return tf.nn.elu(x)
    return tf.nn.elu(2*x)
    #return tf.nn.crelu(x)
    #return tf.nn.tanh(x)
    #return tf.nn.sigmoid(x)
    #return tf.nn.softplus(x)


def maxpool2d(x, k=2):
    # MaxPool2D wrapper
    return tf.nn.max_pool(x, ksize=[1, k, k, 1], strides=[1, k, k, 1],
                          padding='SAME')


# Create model
def conv_net(x, weights, biases, dropout):
    # Reshape input picture
    x = tf.reshape(x, shape=[-1, 28, 28, 1])

    # Convolution Layer
    conv1 = conv2d(x, weights['wc1'], biases['bc1'])
    # Max Pooling (down-sampling)
    #conv1 = maxpool2d(conv1, k=2)

    # Convolution Layer
    conv2 = conv2d(conv1, weights['wc2'], biases['bc2'])
    # Max Pooling (down-sampling)
    #conv2 = maxpool2d(conv2, k=2)
    
    # Convolution Layer
    conv3 = conv2d(conv2, weights['wc3'], biases['bc3'])
    # Max Pooling (down-sampling)
    #conv3 = maxpool2d( conv3, k=2)
    
    # Convolution Layer
    conv4 = conv2d(conv3, weights['wc4'], biases['bc4'])
    # Max Pooling (down-sampling)
    #conv4 = maxpool2d( conv4, k=2)
    
    # Convolution Layer
    conv5 = conv2d(conv4, weights['wc5'], biases['bc5'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv6 = conv2d(conv5, weights['wc6'], biases['bc6'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv7 = conv2d(conv6, weights['wc7'], biases['bc7'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv8 = conv2d(conv7, weights['wc8'], biases['bc8'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv9 = conv2d(conv8, weights['wc9'], biases['bc9'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv10 = conv2d(conv9, weights['wc10'], biases['bc10'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv11 = conv2d(conv10, weights['wc11'], biases['bc11'])
    # Max Pooling (down-sampling)
    #conv1 = maxpool2d(conv1, k=2)

    # Convolution Layer
    conv12 = conv2d(conv11, weights['wc12'], biases['bc12'])
    # Max Pooling (down-sampling)
    #conv2 = maxpool2d(conv2, k=2)
    
    # Convolution Layer
    conv13 = conv2d(conv12, weights['wc13'], biases['bc13'])
    # Max Pooling (down-sampling)
    #conv3 = maxpool2d( conv3, k=2)
    
    # Convolution Layer
    conv14 = conv2d(conv13, weights['wc14'], biases['bc14'])
    # Max Pooling (down-sampling)
    #conv4 = maxpool2d( conv4, k=2)
    
    # Convolution Layer
    conv15 = conv2d(conv14, weights['wc15'], biases['bc15'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv16 = conv2d(conv15, weights['wc16'], biases['bc16'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv17 = conv2d(conv16, weights['wc17'], biases['bc17'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv18 = conv2d(conv17, weights['wc18'], biases['bc18'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv19 = conv2d(conv18, weights['wc19'], biases['bc19'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)
    
    # Convolution Layer
    conv20 = conv2d(conv19, weights['wc20'], biases['bc20'])
    # Max Pooling (down-sampling)
    #conv5 = maxpool2d( conv5, k=2)

    # Fully connected layer
    # Reshape conv2 output to fit fully connected layer input
    fc1 = tf.reshape( conv5, [-1, weights['wd1'].get_shape().as_list()[0]])
    fc1 = tf.add(tf.matmul(fc1, weights['wd1']), biases['bd1'])
    fc1 = tf.nn.relu(fc1)
    # Apply Dropout
    #fc1 = tf.nn.dropout(fc1, dropout)
    
    # # fully connect layer 2
    # fc2 = tf.add(tf.matmul(fc1, weights['wd2']), biases['bd2'])
    # fc2 = tf.nn.relu(fc2)
    # fc2 = tf.nn.dropout(fc2, dropout)
    # fc3 = tf.add(tf.matmul(fc2, weights['wd3']), biases['bd3'])
    # fc3 = tf.nn.relu(fc3)
    # fc3 = tf.nn.dropout(fc3, dropout)
        
    # Output, class prediction
    out = tf.add(tf.matmul(fc1, weights['out']), biases['out'])
    return out

# Store layers weight & bias
weights = {
    # 5x5 conv, 1 input, 32 outputs
    'wc1': tf.Variable(tf.random_normal([5, 5, 1, 64])),
    # 3x3 conv, 64 inputs, 64 outputs
    'wc2': tf.Variable(tf.random_normal([3, 3, 64, 64])),
    # 7x7 conv, 64 inputs, 64 outputs
    'wc3': tf.Variable(tf.random_normal([7, 7, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc4': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc5': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc6': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc7': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc8': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc9': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc10': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 3x3 conv, 64 inputs, 128 outputs
    'wc11': tf.Variable(tf.random_normal([3, 3, 64, 128])),
    # 7x7 conv, 128 inputs, 128 outputs
    'wc12': tf.Variable(tf.random_normal([7, 7, 128, 128])),
    # 3x3 conv, 128 inputs, 128 outputs
    'wc13': tf.Variable(tf.random_normal([3, 3, 128, 128])),
    # 5x5 conv, 128 inputs, 64 outputs
    'wc14': tf.Variable(tf.random_normal([5, 5, 128, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc15': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc16': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc17': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc18': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc19': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    # 5x5 conv, 64 inputs, 64 outputs
    'wc20': tf.Variable(tf.random_normal([5, 5, 64, 64])),
    
    # # fully connected, 7*7*64 inputs, 1024 outputs
    # 'wd1': tf.Variable(tf.random_normal([7*7*64, 1024])),
    # fully connected, 28*28*64 inputs, 1024 outputs (because we do not use polling)
    #'wd1': tf.Variable(tf.random_normal([28*28*64, 1024])),
    'wd1': tf.Variable(tf.random_normal([28*28*64, 2048])),
    # 'wd1': tf.Variable(tf.random_normal([28*28*64, 128])),
    # 'wd2':1024 inputs, 1024 outputs 
    'wd2': tf.Variable(tf.random_normal([1024, 128])),
    # 'wd3':1024 inputs, 1024 outputs
    'wd3': tf.Variable(tf.random_normal([128, 128])),
    # 1024 inputs, 10 outputs (class prediction)
    #'out': tf.Variable(tf.random_normal([128, n_classes])) # for fc3 and fc2 output
    'out': tf.Variable(tf.random_normal([2048, n_classes])) # for fc1 output
    
}

biases = {
    'bc1': tf.Variable(tf.random_normal([64])),
    'bc2': tf.Variable(tf.random_normal([64])),
    'bc3': tf.Variable(tf.random_normal([64])),
    'bc4': tf.Variable(tf.random_normal([64])),
    'bc5': tf.Variable(tf.random_normal([64])),
    'bc6': tf.Variable(tf.random_normal([64])),
    'bc7': tf.Variable(tf.random_normal([64])),
    'bc8': tf.Variable(tf.random_normal([64])),
    'bc9': tf.Variable(tf.random_normal([64])),
    'bc10': tf.Variable(tf.random_normal([64])),
    'bc11': tf.Variable(tf.random_normal([128])),
    'bc12': tf.Variable(tf.random_normal([128])),
    'bc13': tf.Variable(tf.random_normal([128])),
    'bc14': tf.Variable(tf.random_normal([64])),
    'bc15': tf.Variable(tf.random_normal([64])),
    'bc16': tf.Variable(tf.random_normal([64])),
    'bc17': tf.Variable(tf.random_normal([64])),
    'bc18': tf.Variable(tf.random_normal([64])),
    'bc19': tf.Variable(tf.random_normal([64])),
    'bc20': tf.Variable(tf.random_normal([64])),
    
    #'bd1': tf.Variable(tf.random_normal([1024])),
    #'bd1': tf.Variable(tf.random_normal([128])),
    'bd1': tf.Variable(tf.random_normal([2048])),
    'bd2': tf.Variable(tf.random_normal([128])),
    'bd3': tf.Variable(tf.random_normal([128])),
    'out': tf.Variable(tf.random_normal([n_classes]))
}

# Construct model
pred = conv_net( x, weights, biases, keep_prob)

# Define loss and optimizer
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=pred, labels=y))
optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate).minimize(cost)

# Evaluate model
correct_pred = tf.equal(tf.argmax(pred, 1), tf.argmax(y, 1))
accuracy = tf.reduce_mean(tf.cast(correct_pred, tf.float32))

# Initializing the variables
init = tf.global_variables_initializer()

# Launch the graph
with tf.Session() as sess:
    sess.run(init)
    step = 1
    # Keep training until reach max iterations
    #while step * batch_size < training_iters:
    while step < training_iters:
    #while 1:
        batch_x, batch_y = mnist.train.next_batch( batch_size)
        # Run optimization op (backprop)
        sess.run(optimizer, feed_dict={x: batch_x, y: batch_y,
                                       keep_prob: dropout})
        if step % display_step == 0:
            # Calculate batch loss and accuracy
            loss, acc = sess.run([cost, accuracy], feed_dict={x: batch_x,
                                                              y: batch_y,
                                                              keep_prob: 1.})
            print("Iters " + str(step) + ", Minibatch Loss= " + \
                 "{:.6f}".format(loss) + ", Training Accuracy= " + \
                 "{:.5f}".format(acc))
        step += 1
    print("Optimization Finished!")

    # Calculate accuracy for 256 mnist test images
    print("Test Accuracy:", \
        sess.run( accuracy, feed_dict={x: mnist.test.images[:256],
                                      y: mnist.test.labels[:256],
                                      keep_prob: 1.}))



