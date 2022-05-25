#!/usr/bin/python3

import tensorflow as tf
import numpy as np
import tools
import csv
import random

import AutoArcCNN as AutoCNN


## read data and make the basic dataset generator
Data_handler = AutoCNN.Data_handler()
Tr_feature_container = Data_handler.read_dataset('Tr_81792.swPSSM400')
Tr_lable_container   = Data_handler.read_dataset('training_labels.labels')
TrainingBasicGenerator = Data_handler.training_data_generator(Tr_feature_container, Tr_lable_container)
# TrainingBasicGenerator = training_data_generator_with_noise(Tr_feature_container, Tr_lable_container, 0.02)



## set the entry points for construct_2dcnn
input_dim = [20,20]
output_dim = 1169
struc_param = [3,7,72]
batch_size = 800
# x = tf.placeholder(tf.float32, [None, input_dim[0]*input_dim[1]])
# y = tf.placeholder(tf.float32, [None, output_dim])

## first time
AACNN = AutoCNN.AutoArc2DCNN()
Data_handler.epoch = 0
score = AACNN.TDCNN_run(
                        # x, # x = tf.placeholder(tf.float32, [batch_no, input_dim[0]*input_dim[1]]) # data entry point
                        # y,
                        TrainingBasicGenerator = TrainingBasicGenerator,
                        TrainingDataHandler = Data_handler,
                        
                        struc_param = [3,7,72], 
                        input_dim = input_dim, 
                        input_channel_dim = 1, 
                        output_dim = output_dim,
                        batch_size = batch_size,
                        
                        learning_rate = 1E-16,
                        training_iters = 10000000,
                        display_step = 10,
                        pos_panalty = 25.78, 
                        stop_epoch = 3
                        )
print('model 1 score : {}'.format(score))

## second time
print('\n\nsecond time\n\n')     
# AACNN = AutoCNN.AutoArc2DCNN()
Data_handler.epoch = 0
score = AACNN.TDCNN_run(
                        # x, # x = tf.placeholder(tf.float32, [batch_no, input_dim[0]*input_dim[1]]) # data entry point
                        # y,
                        TrainingBasicGenerator = TrainingBasicGenerator,
                        TrainingDataHandler = Data_handler,
                        
                        struc_param = [1,7,72], 
                        input_dim = input_dim, 
                        input_channel_dim = 1, 
                        output_dim = output_dim,
                        batch_size = batch_size,
                        
                        learning_rate = 1E-15,
                        training_iters = 10000000,
                        display_step = 10,
                        pos_panalty = 25.78, 
                        stop_epoch = 3
                        )
print('model 2 score : {}'.format(score))

                 
