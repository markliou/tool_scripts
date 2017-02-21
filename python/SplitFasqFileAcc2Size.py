#!/usr/bin/pyton3
###########
# This script will split fasta1 and fasta2 into the fixed sized chop files.
# usage : SplitFileAcc2Size.py Read1File Read2File FileSize
# markliou 2017/2/21
###########

import sys
import os.path

W_file_size = 100000000 # 100MB
s_parts = 0

def read_fastaq_line(file_handle):
    line = ''
    for i in range(0,4):
        line += file_handle.readline()
    return line

# check the fastaq files
for t_file_name in sys.argv[1:3]:
    if os.path.exists(sys.argv[1]) == False :
        print('read1 or read2 is not exist!')
        exit()
        
# check the specifying of the file size
try:
    if int(sys.argv[3]) != W_file_size :
        W_file_size = int(sys.argv[3])
except:
    pass

# start to split file
with open(sys.argv[1],'r') as read1_file:
    read2_file = open(sys.argv[1],'r')
    wline_read1 = rline_read1 = read_fastaq_line(read1_file)
    wline_read2 = rline_read2 = read_fastaq_line(read2_file)
    while(rline_read1):
        rline_read1 = read_fastaq_line(read1_file)
        wline_read1 += rline_read1 
        rline_read2 = read_fastaq_line(read2_file)
        wline_read2 += rline_read2        
        if(sys.getsizeof(wline_read1) > W_file_size) or (sys.getsizeof(wline_read2) > W_file_size):
            wfile = open(sys.argv[1]+'_'+str(s_parts)+'.spi','w')
            wfile.write(wline_read1)
            wfile.close()
            wfile = open(sys.argv[2]+'_'+str(s_parts)+'.spi','w')
            wfile.write(wline_read2)
            wfile.close()            
            wline_read1 = wline_read2 = '' 
            
            s_parts += 1
            
wfile = open(sys.argv[1]+'_'+str(s_parts)+'.spi','w')
wfile.write(wline_read1)
wfile.close()
wfile = open(sys.argv[2]+'_'+str(s_parts)+'.spi','w')
wfile.write(wline_read2)
wfile.close()            
wline_read1 = wline_read2 = ''        

read1_file.close()
read2_file.close()
