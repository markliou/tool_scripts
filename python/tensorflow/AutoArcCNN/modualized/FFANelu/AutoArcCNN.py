#!/usr/bin/python3
#####
# markliou 20171117
#####

import tensorflow as tf
import numpy as np
import tools
import csv
import random

class AutoArc2DCNN():
    def __init__(self):
        pass
    pass
    
    def construct_2dcnn(
                        self,
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
        # kernel_size = struc_param[0]
        # layer_no = struc_param[1]
        # nodeno = struc_param[2]
        
        current_construct_layer_no = 0
        
        kernels, cl_biases, fc_weights, fc_biases = [], [], [], [] # building weights and biases containers
        
        ### construct weights and biases
        # the kernels and biases of 1st layer
        kernels.append([])
        cl_biases.append([])
        for j in range( 0, int(struc_param['Activated_CL_nodes'][0]) ):
            kernels[0].append(tf.Variable(tf.random_normal([struc_param['kernel'][0][j], struc_param['kernel'][0][j], input_channel_dim, 1] ,stddev= struc_param['CL_initial'][0][j]) ) )
            cl_biases[0].append(tf.Variable( tf.zeros([1] )))
        
        # the kernels and biases of 2~last layers
        for i in range(1, int(struc_param['Active_CL']) ): # create convlution layers (2~last layers)
            kernels.append([])
            cl_biases.append([])
            for j in range(0, struc_param['Activated_CL_nodes'][i]):
                kernels[i].append(tf.Variable(tf.random_normal([struc_param['kernel'][i][j], struc_param['kernel'][i][j], struc_param['Activated_CL_nodes'][i-1], 1] ,stddev= struc_param['CL_initial'][i][j]) ) )
                cl_biases[i].append(tf.Variable( tf.zeros([1] )))
        pass

        fc_weights.append(tf.Variable(tf.random_normal([input_dim[0] * input_dim[1] * struc_param['Activated_CL_nodes'][struc_param['Active_CL']-1], struc_param['FC_node'][0] ] ,stddev=struc_param['FC_initial'][0] ) )) # first fully connect layer
        fc_biases.append(tf.Variable( tf.zeros( [ struc_param['FC_node'][0] ] ))) # bias for first fully connect layer
        for i in range(1, int(struc_param['Active_FC']) ): # create fully connect layers
            fc_weights.append(tf.Variable(tf.random_normal([struc_param['FC_node'][i-1], struc_param['FC_node'][i]] ,stddev=struc_param['FC_initial'][i] ) ))
            fc_biases.append(tf.Variable( tf.zeros([struc_param['FC_node'][i]] )))
        pass
        
        # out_weights = tf.Variable(tf.random_normal([nodeno, output_dim]))
        out_weights = tf.Variable(tf.zeros([struc_param['FC_node'][struc_param['Active_FC']-1], output_dim]))
        out_bias = tf.Variable(tf.zeros([output_dim] ))
        
        ### construct the network
        # Reshape input picture
        x = tf.reshape(x, shape=[-1, input_dim[0], input_dim[1], input_channel_dim])
        
        layers = [] # initial the NN
        # building convolution layers
        layers.append(tf.concat( [ self.conv2d(x, kernels[0][j], cl_biases[0][j], struc_param['CL_lambda'][0][j], struc_param['CL_alpha'][0][j]) for j in range(0, struc_param['Activated_CL_nodes'][0]) ], 
                                   axis=3
                                )
                         
                      )
        current_construct_layer_no += 1
        for i in range(1, int(struc_param['Active_CL']) ):
            layers.append(tf.concat( [ self.conv2d(layers[i-1], kernels[i][j], cl_biases[i][j], struc_param['CL_lambda'][i][j], struc_param['CL_alpha'][i][j] ) for j in range(0, struc_param['Activated_CL_nodes'][i]) ], 
                                     axis=3
                                    )
                         
                         )
            # layers[current_construct_layer_no] = tf.nn.max_pool(layers[current_construct_layer_no],
                                                                # strides=[1, 1, 1, 1], 
                                                                # ksize=[1, 2, 2, 1],
                                                                # padding='SAME'
                                                                # )
            # layers[current_construct_layer_no] = tf.layers.batch_normalization(layers[current_construct_layer_no], training=True, trainable=True)
            current_construct_layer_no += 1
        pass
        

        # building fully connected layers
        reshaped_feature_mapes = tf.reshape(layers[current_construct_layer_no - 1], [-1, fc_weights[0].get_shape().as_list()[0]])
        layers.append(self.fc(reshaped_feature_mapes, fc_weights[0], fc_biases[0], struc_param['FC_lambda'][0], struc_param['FC_alpha'][0]))
        current_construct_layer_no += 1
        
        for i in range(1, int(struc_param['Active_FC']) ):
            layers.append(self.fc(layers[current_construct_layer_no - 1], fc_weights[i], fc_biases[i], struc_param['FC_lambda'][i], struc_param['FC_alpha'][i]))
            current_construct_layer_no += 1
        pass
        
        # output layer
        # out = tf.add(tf.matmul(layers[current_construct_layer_no - 1], out_weights), out_bias)
        out = tf.nn.sigmoid(tf.add(tf.matmul(layers[current_construct_layer_no - 1], out_weights), out_bias))
        
        self.pred = out
        return out
    pass

    def conv2d(self, x, W, b, FFANelu_alpha=1, FFANelu_lambda=1, strides=1):
        x = tf.nn.conv2d(x, W, strides=[1, strides, strides, 1], padding='SAME')
        x = tf.nn.bias_add(x, b)
        # return tf.nn.elu(x)
        # return tf.nn.sigmoid(x)
        # return self.selu(x)
        # return self.FFANelu(x, FFANelu_alpha, FFANelu_lambda)
        return self.FFANelu(x, 1.6732632423543772848170429916717, 1.0507009873554804934193349852946)
    pass
    
    def fc(self, x, W, b, FFANelu_alpha=1, FFANelu_lambda=1):
        x = tf.add(tf.matmul(x, W), b)
        # return tf.nn.elu(x)
        # return tf.nn.sigmoid(x)
        # return self.FFANelu(x, FFANelu_alpha, FFANelu_lambda)
        return self.FFANelu(x, 1.6732632423543772848170429916717, 1.0507009873554804934193349852946)
    pass

    def selu(self, x, alpha = 1.6732632423543772848170429916717, scale = 1.0507009873554804934193349852946):
        return scale*tf.where(x>=0.0, x, alpha*tf.nn.elu(x))
    pass
    
    def FFANelu(self, x, alpha = 1, lamb = 1):
        return tf.where(x>=0.0, lamb * x, alpha*tf.nn.elu(x))
    pass

    def TDCNN_run (
            self,
            # x, 
            # y, 
            TrainingBasicGenerator,
            TrainingDataHandler,
            struc_param,
            input_dim,
            input_channel_dim,
            output_dim,
            batch_size,
            
            # Parameters
            learning_rate = 1E-3,
            training_iters = 10000000,
            display_step = 10,
            pos_panalty = 1,
            PQAlpha = 2,
            stop_epoch = -1
            ):
            
        # construct the placeolder for input data
        x = tf.placeholder(tf.float32, [None, input_dim[0]*input_dim[1]])
        y = tf.placeholder(tf.float32, [None, output_dim])
        
        
        pred = self.construct_2dcnn( x, 
                                     struc_param = struc_param, 
                                     input_dim = input_dim, 
                                     input_channel_dim = input_channel_dim, 
                                     output_dim = output_dim)

                               
        # Define loss and optimizer

        cost = tf.reduce_mean(tf.nn.weighted_cross_entropy_with_logits(logits=pred, targets=y, pos_weight=pos_panalty))
        optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate).minimize(cost)

        # Evaluate model
        correct_pred = tf.equal(tf.round(pred), y)
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
            Tr_feature_batch, Tr_label_batch = TrainingDataHandler.training_batch(batch_size, TrainingBasicGenerator)
            validation_x = np.vstack(Tr_feature_batch)
            validation_y = np.vstack([ TrainingDataHandler.trans2onehot(i, output_dim) for i in Tr_label_batch ])
            c_loss = sess.run(cost, feed_dict={x: validation_x, y: validation_y})
            stop_criteria = tools.PQAlpha( c_loss, alpha = PQAlpha )
            print("Initial loss :{}  learning rate:{}".format(c_loss, learning_rate))
            
            # Keep training until reach max iterations
            # while not (step * batch_size > training_iters) or (stop_criteria.Stop == True):
            while (stop_criteria.Stop == False) and (not TrainingDataHandler.epoch == stop_epoch):
            # while (stop_criteria.Stop == False):
                
                Tr_feature_batch, Tr_label_batch = TrainingDataHandler.training_batch(batch_size, TrainingBasicGenerator)
                Tr_x = np.vstack(Tr_feature_batch)
                Tr_y = np.vstack([ TrainingDataHandler.trans2onehot(i, output_dim) for i in Tr_label_batch ])
                
                sess.run(optimizer, feed_dict={x: Tr_x, y: Tr_y})
                self.model_loss = sess.run(cost, feed_dict={x: Tr_x,
                                                            y: Tr_y})
                stop_criteria.update(self.model_loss)
                
                if step % display_step == 0:
                    # Calculate batch loss and accuracy
                    loss, acc = sess.run([cost, accuracy], feed_dict={x: Tr_x,
                                                                      y: Tr_y})
                    print("Sampling times: " + str(step*batch_size) + ", Minibatch Loss= " + \
                          "{:.6f}".format(loss) + ", Training Accuracy= " + \
                          "{:.5f}".format(acc))
                step += 1
                
                # # save models
                # model_saver.save(sess, './models/AutoArc', global_step=step)
                
            print("Optimization Finished!")
            
            # saving the model
            print(model_saver.save(sess, './models/AutoArc'))
            

        pass  # end 'with'
        
        tf.reset_default_graph()  
        
        return self.model_loss
    pass
    
pass


class Data_handler():
    def __init__(self):
        self.epoch = 0
    pass
    
    def trans2onehot(self, sparse_ind, output_dim):
        onehoty = np.zeros([output_dim])
        
        if type(sparse_ind) == list :
            for i in sparse_ind:
                onehoty[int(i)] = 1
            pass 
        else:
            onehoty[sparse_ind] = 1
        pass
        
        return onehoty
    pass

    def read_dataset(self, filename):
        content_container = []
        csvfile = open(filename)
        csvreader = csv.reader(csvfile)
        for content in csvreader:
            content_container.append(content)
        pass
        csvfile.close()
        
        # return np.vstack(content_container)
        return content_container
    pass 

    def training_data_generator(self, Tr_features, Tr_labels):
        assert len(Tr_features) == len(Tr_labels)
        self.epoch = 0
        s_index = [i for i in range(len(Tr_labels))]
        ss_index = s_index[:]
        random.shuffle(ss_index)
        while(1):
            if len(ss_index) == 0:
                self.epoch += 1
                ss_index = s_index[:]
                random.shuffle(ss_index)
                print("epoch: {} shuffle epoch!".format(self.epoch))
            else :
                pop_index = ss_index.pop()
                yield(Tr_features[pop_index], Tr_labels[pop_index])
            pass
        pass
    pass

    def training_data_generator_with_noise(self, Tr_features, Tr_labels, noise_rate):
    ##
    ## mode collapse would be solved using some noise
    ##
        assert len(Tr_features) == len(Tr_labels)
        epoch = 0
        s_index = [i for i in range(len(Tr_labels))]
        ss_index = s_index[:]
        random.shuffle(ss_index)
        while(1):
            if len(ss_index) == 0:
                epoch += 1
                ss_index = s_index[:]
                random.shuffle(ss_index)
                print("epoch: {} shuffle epoch!".format(epoch))
            else :
                pop_index = ss_index.pop()
                if random.random() < noise_rate :
                    pop_index_i = random.choice(s_index)
                    pop_index_j = random.choice(s_index)
                    yield(Tr_features[pop_index_i], Tr_labels[pop_index_j])
                    # yield(Tr_features[pop_index_i], [i for i in range(0,1169)])
                pass 
                yield(Tr_features[pop_index], Tr_labels[pop_index])
            pass
        pass
    pass

    def training_data_generator_2C(self, Tr_features1, Tr_features2, Tr_labels):
        assert len(Tr_features1) == len(Tr_labels)
        s_index = [i for i in range(len(Tr_labels))]
        ss_index = s_index[:]
        random.shuffle(ss_index)
        while(1):
            if len(ss_index) == 0:
                ss_index = s_index[:]
                random.shuffle(ss_index)
                #print("shuffle epoch!")
            else :
                pop_index = ss_index.pop()
                yield(Tr_features1[pop_index], Tr_features2[pop_index], Tr_labels[pop_index])
            pass
        pass
    pass

    def training_batch(self, batch_size, basic_generator):
        Tr_feature_batch, Tr_label_batch = [], []
        for i in range(0, batch_size):
            T_feature_batch, T_label_batch = next(basic_generator)
            Tr_feature_batch.append(T_feature_batch)
            Tr_label_batch.append(T_label_batch)
        pass 
        return Tr_feature_batch, Tr_label_batch
    pass 
pass



