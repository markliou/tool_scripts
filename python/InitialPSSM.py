#!/bin/python3
###
# python3 InitialPSSM.py 
# makrliou 20171114
###

import sys
import argparse
import re
import Bio.SeqIO

arg = argparse.ArgumentParser(description='setting the enviroment variables')
arg.add_argument('-B', '--BLOSUM_FILE', help='setting the BLOUSOM file and its location')
arg.add_argument('F', '--FASTA', help='setting the target FASTA')
argp = arg.parse_args()

##### loading the BLOSUM matrix
#BLOSUM_content = open(argp.BLOSUM_FILE)
BLOSUM_content = open('BLOSUM62', 'r')

AA = list('ARNDCQEGHILKMFPSTWYVBZX*')
BLOSUM_ARR = {}
for i in AA:
    BLOSUM_ARR[i] = {}
pass

for line in BLOSUM_content.readlines():
    
    if re.match('^#',line) or re.match('^\s',line):
        continue
    pass
    
    content = re.split('\s+', line.rstrip('\n'))
    
    for ci in range(1,len(content)-1):
        BLOSUM_ARR[content[0]][AA[ci-1]] = content[ci]
    pass
    
   
    
pass
BLOSUM_content.close()

##### loading the FASTA file
PSSM_AA_Lookup = re.split('\s+','A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V')
lacking_list = open('PSSM_Lacking_list.txt','w')
for seq in Bio.SeqIO.parse('Tr.fasta_5048','fasta'):
    PSSM_o = open('pssmm/{}.pssmm'.format(seq.id),'w')
    PSSM_o.write('\nLast position-specific scoring matrix computed, weighted observed percentages rounded down, information per position, and relative weight of gapless real matches to pseudocounts\n')
    PSSM_o.write('        A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V   A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V\n')
    lacking_list.write('{}\n'.format(seq.id))
    seq_list = list(seq.seq)
    
    idn = 1
    for ci in seq_list:
        output_str = '  ' + str(idn) + ' ' + ci + '  '
        for claa in PSSM_AA_Lookup : # extract value
            output_str += BLOSUM_ARR[ci][claa]
            output_str += '  '
        pass
        
        for claa in PSSM_AA_Lookup : # append the dummy value for PSSM400 scripts
            output_str += '0'
            output_str += '  '
        pass
        
        PSSM_o.write(output_str + '\n')
        idn += 1
        
    pass
    
    PSSM_o.write('                      K         Lambda\n')
    #print(seq.seq)
    PSSM_o.close()
    exit()
pass
lacking_list.close()



