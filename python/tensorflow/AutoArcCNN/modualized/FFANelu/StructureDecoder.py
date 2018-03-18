#!/usr/bin/python3
#####
## Decode the list which have element in the range of 0~1 to the target hyperparameters
##    markliou 2017/12/2
#####

import numpy as np


def structure_decode(x, 
                     Max_kernel, 
                     MaxCLNo, 
                     MaxCLNodeNo, 
                     MaxFCLNo, 
                     input_dim,
                     output_dim):
    
    # initialize the parameters
    param = {'Active_CL':0,
             'Activated_CL_nodes':[],
             'kernel':[],
             'CL_lambda':[],
             'CL_alpha' :[],
             'CL_initial':[],
             
             'Active_FC':0,
             'FC_lambda':[],
             'FC_alpha':[],
             'FC_node':[],
             'FC_initial':[],
             
             'learning_rate': 1E-3, # 1E-n
             
             'BROKEN' : False
             
            }
    c_x = 0
    
    ##########
    ## parsing rule : ( activative_node, kernel_size, lambda, alpha, kernel_initial ) * MaxCLNo + => convoluational layers
    ##                ( activate_layer, node_no, lambda, alpha, node_initial) * MaxFCLNo ) + => fully connect layer
    ##                learning_rate
    ##                                                                                              markliou
    ##########
    
    # encoding the convolutional layer parameters
    ccl = 0
    for cl in range(0, MaxCLNo):
        LayerAlreadyActivation = False
        ActivationNodeNo = 0
        for i in range(0, MaxCLNodeNo):
            if x[c_x] >= np.random.random(): # if node activate
            
                # if the node is activate
                c_x += 1
                
                # if node "activate", but lambda and alpha are zeros, this also means "inactivation"
                if (x[c_x+2] == 0) and (x[c_x+3] == 0): 
                    c_x += 4 
                    continue 
                pass
                
                ActivationNodeNo += 1
                
                # check if the layer is activate, if not, appending a layer
                if LayerAlreadyActivation == False:
                    for i in ['kernel', 'CL_lambda', 'CL_alpha', 'CL_initial']:
                        param[i].append([])
                    pass
                    LayerAlreadyActivation = True
                pass
                
                # the kernel size => 0 ~ (kernel-1/2)
                Thresholds = np.sort(np.random.random([ np.int( ((Max_kernel-1)/2) ) ] ) )
                param['kernel'][ccl].append( np.searchsorted(Thresholds, x[c_x]) * 2 + 1)
                c_x += 1
                
                # the lambda => 0~2
                param['CL_lambda'][ccl].append(x[c_x] * 2)
                c_x += 1
                
                # the alpha => 0~2
                param['CL_alpha'][ccl].append(x[c_x] * 2)
                c_x += 1
                
                # the initial
                param['CL_initial'][ccl].append(x[c_x])
                c_x += 1
                        
            
            else: # if node is inactivate
                c_x += 5 # 5 parameters as a unit for a node, 1 layer have MaxCLNodeNo
            pass 
       
        if not ActivationNodeNo == 0:
            param['Active_CL'] += 1
            ccl += 1
            param['Activated_CL_nodes'].append(ActivationNodeNo)
        pass
    pass
    
    # encoding the fully connected layer parameters
    for fc in range(0, MaxFCLNo):
        if x[c_x] >= np.random.random(): # if layer activate
            
            # if layer activation is "activate", but lambda and alpha are zeros, this also means "inactivation"
            if (x[c_x+2] == 0) and (x[c_x+3] == 0): 
                c_x += 5
                continue 
            pass
            
            # if the layer is activate
            # # 'Active_FC':0,
            # # 'FC_node':[],
            # # 'FC_lambda':[],
            # # 'FC_alpha':[],
            # # 'FC_initial':[]
            c_x += 1
            param['Active_FC'] += 1
            
            # the kernel size => 0~3
            Thresholds = np.sort(np.random.random([3]))
            param['FC_node'].append( np.int( output_dim * (x[c_x] + 1) * 2) )
            c_x += 1
            
            # the lambda => 0~2
            param['FC_lambda'].append(x[c_x] * 2)
            c_x += 1
            
            # the alpha => 0~2
            param['FC_alpha'].append(x[c_x] * 2)
            c_x += 1
            
            # the initial
            param['FC_initial'].append(x[c_x])
            c_x += 1
                

            
        else: # if layer is inactivate
            c_x += 5
            continue
        pass 
    
    pass 
    
    # assign learning rate
    param['learning_rate'] = pow(0.1, int(x[c_x]*4+12))
    c_x += 1
    
    # check the broken individual
    if param['Active_CL'] == 0 or param['Active_FC'] ==0 :
        param['BROKEN'] = True
    pass
    
    
    return param
pass

def main():
    # kernel : 3   (7)
    # convolutional layer : 6
    # convolutional nodes : 64
    # fully connect layer : 3
    # fully connect nodes : 1169 * 2
    # learning rate : 1
    
    # total parameters : 1920 + 15 + 1 = 1936
    
    ParamArray = np.random.random([1936])
    # print(ParamArray)
    param = structure_decode(ParamArray, #x, 
                             7, # Max_kernel, 
                             6, #MaxCLNo, 
                             64, #MaxCLNodeNo, 
                             3, #MaxFCLNO,
                             1, #input_dim
                             1169 # output_dim
                             )
    
    
    print(param['Active_CL'])
    # print(param['Activated_CL_nodes'])
    # print(param['kernel'])
    # print(param['kernel'][0][1])
    # print(param['kernel'][1][2])
    #print(param['CL_lambda
    
    # print(param['Active_FC'])
    # print(param['FC_node'])
    # print(param['BROKEN'])
    
    # print(param['learning_rate'])
    
    # print(param)
    
    
pass

if __name__ == '__main__':
    main()
pass

