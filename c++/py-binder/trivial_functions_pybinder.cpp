#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h> 
#include <iostream> 

#include <Python.h>
// -I/usr/include/python3.8

#include "trivial_functions.h"

using namespace std ;

/////////////////////////////////////////////////////////////////////
// good reference: https://github.com/starnight/python-c-extension //
/////////////////////////////////////////////////////////////////////


/***** Setion 1. 定義函數 *****/

// the original object from py need to be defined as the static funtion
// 規定就是要用static物件把c的function包起來。
static PyObject* pyDoubleArray(PyObject* self, PyObject* args, PyObject* kwargs){
    // 先宣告到時候要放到c/c++ function裡面的變數
    // 以 doubleArray 的 header 為例: float* doubleArray(float* a, int array_size) ;
    // 需要宣告 a 跟 array_size 兩個input變數
    // 還需要宣告 res 的 output變數
    float* a ;
    int array_size ;
    float* res ;
    PyObject* Pylst ;

    // 需要把這些 input 變數放到 keyword 管理名單中，方便送到python裡面
    // 記得最後要補上NULL    
    // static char* kwlist[] = {"a", "array_size", NULL} ;

    // 先測試一下變數的性質會不會過。變數會用"|"區隔出有預設值的變數。
    // 例如有個 python def 的 header 長這樣: def foo(a, b, c=1) 。同時(a, b, c)為(float, int, int)，
    // 測試的符號就會是 fi|i 。因為最後一個 c 有可能不會拿到值而是直接用預設的 1 。
    // 更多的測試型別可以看ref1。用法的說明則看ref2。
    // ref 1. https://docs.python.org/3/c-api/arg.html 
    // ref 2. https://stackoverflow.com/questions/10625865/how-does-pyarg-parsetupleandkeywords-work
    // ref 3. https://stackabuse.com/enhancing-python-with-custom-c-extensions/
    // if (!PyArg_ParseTupleAndKeywords(args, kwargs, "fi", kwlist, &a, &array_size)) {
    if (!PyArg_ParseTuple(args, "Oi", &Pylst, &array_size)) {
        return NULL;
    }
    // cout << "A." << array_size << " " << PyObject_Length(Pylst) << endl;

    // 把 pyobject 的 Array 轉成 c array
    // 更多型別轉換:
    // ref : https://www.mdeditor.tw/pl/pj72/zh-tw
    a = new float[PyObject_Length(Pylst)] ;
    float _temp ;
    for(int step = 0; step < array_size; step++){
        a[step] = (float)PyFloat_AsDouble(PyList_GetItem(Pylst, step)) ;
    }
    // cout << a[3] << endl ;
    // 釋放 pyobject ，避免 memory leakage
    Py_XDECREF(Pylst);


    // 透過上面的賦值後，已經可把在 python 裡面的數值放到 a 跟 array_size 裡面。
    // 這時候只需要呼叫 c 的 fucntion 就可以了
    res = doubleArray(a, array_size) ;
    // cout << "B." << res[4] << endl;
    
    // 製作 output 的 list
    // ref: https://bytes.com/topic/python/answers/167117-c-extension-return-array-longs-pointer
    PyObject *tup = PyList_New(array_size);
    for(int step = 0; step < array_size; step++){
        PyList_SET_ITEM(tup, step, Py_BuildValue("f", res[step]));
    }
    // cout << "C." << tup << endl;
    
    // 最後結果要回傳給 py
    return tup;
    // return Py_BuildValue("i", array_size) ;
} ;


/***** Section 2. 把方法包裝起來 *****/
// 需要對每個function都有說明
char pyDoubleArray_doc[] = "This function will give the double vaile of the given array" ;
static PyMethodDef arrayInC_funcs[] = { // method 名稱定義就隨意。這邊需要命名是為了要放到 section 3 的 initial 方法。原因是有可能會有不同的 module 要使用不同的 initial 方法。就可以在這邊處理
    {"pyDoubleArrayInPy", // 預計要在py裡面的名稱
     (PyCFunction) pyDoubleArray, // 目前在binder裡面的對應的
      METH_VARARGS, // 在py裡面會呈現的狀態。例如如果是沒有任何輸入就單純操作就可以用 METH_NOARGS
      pyDoubleArray_doc // function的說明，寫在上面
    }, 
    {NULL, 
     NULL, 
     0, 
     NULL} // 以 NULL 作結
} ;


/***** Section 3. 定義module結構 *****/ 
char trivial_functions_in_c_doc[] = "using c/c++ extention for handling array" ;
static PyModuleDef trivial_functions_in_c = {
    PyModuleDef_HEAD_INIT, // 起始方法，沒有特別的
    "trivial_functions_in_c", // module名稱 
    trivial_functions_in_c_doc, // module 說明
    -1, // 宣告需要多少記憶體。這邊預設是無上限
    arrayInC_funcs, // 上面有把function包裹起來的物件
    NULL
} ;


/***** Setion 4. module 初始化的方法 *****/
PyMODINIT_FUNC PyInit_trivial_functions_in_c() { // 把module的名稱前面加上 PyInit_
    return PyModule_Create(&trivial_functions_in_c); // 上面宣告的模組資訊放到這邊進行初始化
} ;



