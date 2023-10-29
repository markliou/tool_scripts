import tensorflow as tf
import tensorflow_datasets as tfds
import numpy as np
import random

def bean_img_iter(bs = 32):
    img_size = (500, 500)
    
    dataset = tfds.load("beans", split='train', shuffle_files=True)
    dataset = dataset.batch(bs, drop_remainder=True, num_parallel_calls=tf.data.AUTOTUNE)
    dataset = dataset.repeat()
    dataset = dataset.prefetch(tf.data.AUTOTUNE)

    return iter(dataset)

def main():
    ds_iter = bean_img_iter()
    ds_fetcher = next(ds_iter)
    print(ds_fetcher['image'])

    
if __name__ == "__main__":
    main()