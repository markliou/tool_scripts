/*
this script make the sequence permutation
2016/11/11 markliou 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h> 
#include <iostream> 

using namespace std ;

struct params{
    int m ;
    int n ;
    unsigned long long exp_no ;
    int* set;
    int position ;
    bool end_of_iter ;
};

unsigned long long factorial(int m, int n){
    int result = 1;
    for(int i=n ; i<=m ; i++)
        result *= i;
    return result;
}

void exp_permutate_go(struct params& param_iter) {
    
    if(param_iter.end_of_iter == true )
        return ;
    
    // itertion main body //
    if(param_iter.set[param_iter.n-1] == param_iter.m)
        param_iter.position--;
    else
        param_iter.position = param_iter.n - 1;

    param_iter.set[param_iter.position]++;

    // 調整右邊元素
    int j;
    for(j = param_iter.position + 1; j < param_iter.n; j++)
        param_iter.set[j] = param_iter.set[j-1] + 1;
    
    if(param_iter.set[0] >= param_iter.m - param_iter.n + 1){//if the all permutation is end, return the finalize sign
        param_iter.end_of_iter = true ;
    }
    // end of main body //
    
    return ;
}

struct params exp_permutate_init(int m, int n) {

    struct params param_iter ;
    param_iter.m = m ;
    param_iter.n = n ;
    param_iter.end_of_iter = false ;
    
    param_iter.set = new int[n];

    for(int i = 0; i < n; i++)
        param_iter.set[i] = i + 1;

    return param_iter ;

}

int main(){
    
    struct params param_iter ;
    param_iter = exp_permutate_init(5,3);
    
    while(param_iter.end_of_iter == false){
        for(int i = 0 ; i < param_iter.n ; i++)
            cout << param_iter.set[i] << " " ;
        cout << endl;
        exp_permutate_go(param_iter) ;
    }
    
    // for(int i = 0 ; i < param_iter.n ; i++)
        // cout << param_iter.set[i] << " " ;
    // cout << endl;
    
    // exp_permutate_go(param_iter) ;
    
    // for(int i = 0 ; i < param_iter.n ; i++)
        // cout << param_iter.set[i] << " " ;
    // cout << endl;
}
