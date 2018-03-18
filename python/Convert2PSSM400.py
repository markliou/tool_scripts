##### Licensed with Apache 2.0 markliou 20170804
import re
import numpy as np
import sys

def make_PSSM400_output(pssm400filename, res_pssm_content, res_cnt, aa_list, pssm_min, pssm_max ):
    pssm400file = open(pssm400filename,'w')
    pssm400file.write(','.join(aa_list))
    pssm400file.write('\n')
    for i in aa_list:
        if res_cnt[i] == 0:
            res_pssm_content[i] /= 1
        else:
            res_pssm_content[i] /= res_cnt[i]
        pass
        
        # scaling the element
        for j in range(0,20):
            res_pssm_content[i][j] = (res_pssm_content[i][j] - pssm_min[j])/(pssm_max[j] - pssm_min[j]) 
        pass
        
        pssm400file.write(','.join([str(j) for j in res_pssm_content[i].tolist()]))
        pssm400file.write('\n')
    pass
    pssm400file.close()
pass

def update_min_max(c_res_pssm_content, pssm_min, pssm_max):
    for i in range(0,20):
        pssm_min[i] = min([c_res_pssm_content[i], pssm_min[i]])
        pssm_max[i] = max([c_res_pssm_content[i], pssm_max[i]])
    pass
pass

def main(argv):
    pssmfilename = argv[1]
    aa_list = list('ARNDCQEGHILKMFPSTWYV')
    res_cnt = []
    res_cnt = dict( (res,0) for res in aa_list )
    res_pssm_content = []
    res_pssm_content = dict( (res,np.zeros(20)) for res in aa_list )
    pssm_min, pssm_max = [], []
    pssm_min, pssm_max = dict( (res,0) for res in range(0,20) ), dict( (res,0) for res in range(0,20) )
    
    pssmfile = open(pssmfilename)
    for line in pssmfile:
        re_op = re.match('\s+K\s+Lambda',line) # test if the final line
        if re_op:
            make_PSSM400_output(pssmfilename+'.pssm400', res_pssm_content, res_cnt, aa_list, pssm_min, pssm_max)
            pssmfile.close()
            exit()
        pass
        
        re_op = re.match('\s*\d+ (.)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)',line) # pssm content extraction
        #             A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V
        #     1 G     0  -2   0  -1  -2  -2  -2   6  -2  -4  -4  -2  -3  -3  -2   0  -2  -2  -3  -3
        if re_op:
            if not re_op.group(1) in aa_list:
                continue
            pass
            res_cnt[re_op.group(1)] += 1
            c_res_pssm_content = np.array([np.float64(re_op.group(i)) for i in range(2,22)])
            res_pssm_content[re_op.group(1)] += c_res_pssm_content
            update_min_max(c_res_pssm_content, pssm_min, pssm_max)
        pass
    pass
pass
    
    
if __name__ == "__main__":
    # usage: python Convert2PSSM400.py PSSMFile
    main(sys.argv)