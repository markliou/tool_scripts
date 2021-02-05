#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h> 
#include <iostream> 

using namespace std ;

float* doubleArray(float* a, int array_size){
    float *r = new float[array_size]{0} ;

    for (int step = 0 ; step < array_size ; step++){
        r[step] = a[step] * 2 ;
    }

    return r ;
} 

void info(float* a, int array_size){
    for (int step = 0; step < array_size; step++){
        cout << " " << a[step] ;
    }
}


int main(){
    int array_size = 32 ;
    float* a = new float[array_size]{0} ;
    float* b = new float[array_size]{0} ;

    for (int step = 0; step < array_size; step++){
        a[step] = step ; 
        b[step] = a[step] * 2 ;
    }

    for (int step = 0; step < array_size; step++){
        cout << " " << b[step] ;
    }
    cout << endl ;
    
    float* c = doubleArray(b, array_size) ;
    info(c, array_size);
    cout << endl ;

    delete a ;
    delete b ;
    delete c ;

    return 0;
}
