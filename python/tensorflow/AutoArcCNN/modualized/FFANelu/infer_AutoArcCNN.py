#!/usr/bin/python3

import tensorflow as tf
import numpy as np
import tools
import csv
import random

import AutoArcCNN as AutoCNN
from StructureDecoder import *

### seperate the inference part into another session
AACNN = AutoCNN.AutoArc2DCNN()
Data_handler = AutoCNN.Data_handler()
output_dim = 1169
input_dim = [20,20]
param_file = open('AutoArcCNN.param')
param = eval(param_file.readlines()[0])

Ts_feature_container = Data_handler.read_dataset('Ts_81792.swPSSM400')
Ts_lable_container   = Data_handler.read_dataset('test_labels.labels')
Ts_x = np.vstack(np.array(Ts_feature_container))
Ts_y = np.vstack([ Data_handler.trans2onehot(i, output_dim) for i in Ts_lable_container ])
_x = tf.placeholder(tf.float32, [None, input_dim[0]*input_dim[1]])
_y = tf.placeholder(tf.float32, [None, output_dim])

pred = AACNN.construct_2dcnn(
                             _x, 
                             param,
                             input_dim,
                             1,
                             1169
                             )

model_saver = tf.train.Saver()
model_container = tf.train.import_meta_graph('./models/AutoArc.meta')
predict_result_output = open('model_output.pred','w')

correct_pred = tf.equal(tf.round(pred), _y)
accuracy = tf.reduce_mean(tf.cast(correct_pred, tf.float32))
                             
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    model_container.restore(sess, './models/AutoArc')
    t_res, t_acc = sess.run( [tf.round(pred), accuracy],feed_dict={_x: Ts_x, _y: Ts_y})

    print("Test Accuracy: {}".format(t_acc))
    predict_result_output.write("Test Accuracy: {}".format(t_acc))
    predict_result_output.write("\n")

    for i in t_res:
        # print(','.join( [str(t) for t in i.tolist()] ))
        # predict_result_output.write(','.join( [str(t) for t in i.tolist()] ))
        # predict_result_output.write("\n")
        
        GO_indx = 0
        for j in i:
            if j :
                predict_result_output.write(str(GO_indx))
                predict_result_output.write(',')
            GO_indx += 1
        predict_result_output.write("\n")
pass


