import tensorflow as tf 
import numpy as np

def cnn_model():
    x = tf.keras.layers.Input(shape=(32, 32, 3), dtype="float32") # the input operator of keras is different from Placeholder of TF1
    conv1 = tf.keras.layers.Conv2D(filters=64, kernel_size=(3,3), strides=(1,1), padding='SAME', activation=tf.nn.relu)(x)
    conv2 = tf.keras.layers.Conv2D(filters=64, kernel_size=(3,3), strides=(2,2), padding='SAME', activation=tf.nn.relu)(conv1)
    conv3 = tf.keras.layers.Conv2D(filters=64, kernel_size=(3,3), strides=(2,2), padding='SAME', activation=tf.nn.relu)(conv2)
    conv4 = tf.keras.layers.Conv2D(filters=64, kernel_size=(3,3), strides=(2,2), padding='SAME', activation=tf.nn.relu)(conv3)
    # print(conv4)
    flatten = tf.keras.layers.Flatten()(conv4)
    # print(flatten)
    fc1 = tf.keras.layers.Dense(256, activation=tf.nn.relu)(flatten)
    fc2 = tf.keras.layers.Dense(128, activation=tf.nn.relu)(fc1) 
    out = tf.keras.layers.Dense(10, activation=None)(fc2) 
    # print(out)

    return tf.keras.Model(inputs=x, outputs=out) 
pass