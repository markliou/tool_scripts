#!/usr/bin/python3

import tensorflow as tf
import numpy as np
import tools
import csv
import random

import AutoArcCNN as AutoCNN
from StructureDecoder import *


## read data and make the basic dataset generator
Data_handler = AutoCNN.Data_handler()
Tr_feature_container = Data_handler.read_dataset('Tr_81792.swPSSM400')
Tr_lable_container   = Data_handler.read_dataset('training_labels.labels')
TrainingBasicGenerator = Data_handler.training_data_generator(Tr_feature_container, Tr_lable_container)
# TrainingBasicGenerator = training_data_generator_with_noise(Tr_feature_container, Tr_lable_container, 0.02)



## set the entry points for construct_2dcnn
input_dim = [20,20]
output_dim = 1169
batch_size = 800
AACNN = AutoCNN.AutoArc2DCNN()

# ## first time
# Data_handler.epoch = 0
# score = AACNN.TDCNN_run(
                        # # x, # x = tf.placeholder(tf.float32, [batch_no, input_dim[0]*input_dim[1]]) # data entry point
                        # # y,
                        # TrainingBasicGenerator = TrainingBasicGenerator,
                        # TrainingDataHandler = Data_handler,
                        
                        # struc_param = [3,7,72], 
                        # input_dim = input_dim, 
                        # input_channel_dim = 1, 
                        # output_dim = output_dim,
                        # batch_size = batch_size,
                        
                        # learning_rate = 1E-16,
                        # training_iters = 10000000,
                        # display_step = 10,
                        # pos_panalty = 25.78, 
                        # stop_epoch = 3
                        # )
# print('model 1 score : {}'.format(score))

# ## second time
# print('\n\nsecond time\n\n')     
# Data_handler.epoch = 0
# score = AACNN.TDCNN_run(
                        # # x, # x = tf.placeholder(tf.float32, [batch_no, input_dim[0]*input_dim[1]]) # data entry point
                        # # y,
                        # TrainingBasicGenerator = TrainingBasicGenerator,
                        # TrainingDataHandler = Data_handler,
                        
                        # struc_param = [1,7,72], 
                        # input_dim = input_dim, 
                        # input_channel_dim = 1, 
                        # output_dim = output_dim,
                        # batch_size = batch_size,
                        
                        # learning_rate = 1E-15,
                        # training_iters = 10000000,
                        # display_step = 10,
                        # pos_panalty = 25.78, 
                        # stop_epoch = 3
                        # )
# print('model 2 score : {}'.format(score))

Data_handler.epoch = 0
param = structure_decode(np.random.random([1936]), #x, 
                         7, # Max_kernel, 
                         6, #MaxCLNo, 
                         64, #MaxCLNodeNo, 
                         3, #MaxFCLNO,
                         1, #input_dim
                         1169 # output_dim
                         )
if param['BROKEN']:
    print('model broken')
    exit()
score = AACNN.TDCNN_run(
                        # x, # x = tf.placeholder(tf.float32, [batch_no, input_dim[0]*input_dim[1]]) # data entry point
                        # y,
                        TrainingBasicGenerator = TrainingBasicGenerator,
                        TrainingDataHandler = Data_handler,
                        
                        struc_param = param, 
                        input_dim = input_dim, 
                        input_channel_dim = 1, 
                        output_dim = output_dim,
                        batch_size = batch_size,
                        
                        learning_rate = param['learning_rate'],
                        # learning_rate = 1E-15,
                        training_iters = 10000000,
                        display_step = 10,
                        pos_panalty = 25.78, 
                        stop_epoch = 3
                        )
print('model score (loss): {}'.format(score))
param_out = open('AutoArcCNN.param','w')
param_out.write(str(param))
param_out.close()

### seperate the inference part into another session
# AACNN = AutoCNN.AutoArc2DCNN()
# Data_handler = AutoCNN.Data_handler()
# output_dim = 1169
# input_dim = [20,20]
param_file = open('AutoArcCNN.param')
# param = eval(param_file.readlines()[0])

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


                 
