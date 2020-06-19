import tensorflow as tf 
import numpy as np
import cnn 

c_cnn_model = cnn.cnn_model()

# show the information about the model
print(c_cnn_model.summary())

# inferencing
print(c_cnn_model(np.random.random([10, 32, 32, 3]).astype(np.float32)))
