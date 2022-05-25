/* Generated code for Python module 'cnn'
 * created by Nuitka version 0.6.8.4
 *
 * This code is in part copyright 2020 Kay Hayen.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nuitka/prelude.h"

#include "__helpers.h"

/* The "_module_cnn" is a Python object pointer of module type.
 *
 * Note: For full compatibility with CPython, every module variable access
 * needs to go through it except for cases where the module cannot possibly
 * have changed in the mean time.
 */

PyObject *module_cnn;
PyDictObject *moduledict_cnn;

/* The declarations of module constants used, if any. */
static PyObject *const_str_plain_nn;
static PyObject *const_str_digest_f91a67e9ac70ed2ea9f56633fb2f6965;
extern PyObject *const_str_plain___spec__;
static PyObject *const_str_plain_padding;
static PyObject *const_str_plain_fc2;
static PyObject *const_tuple_int_pos_2_int_pos_2_tuple;
static PyObject *const_str_plain_tf;
static PyObject *const_str_plain_numpy;
static PyObject *const_str_plain_filters;
extern PyObject *const_int_pos_1;
static PyObject *const_str_plain_inputs;
extern PyObject *const_str_plain___file__;
static PyObject *const_int_pos_256;
extern PyObject *const_int_0;
static PyObject *const_tuple_int_pos_1_int_pos_1_tuple;
static PyObject *const_dict_d0ba5f3dd7c471476029202081fc960e;
static PyObject *const_str_plain_Input;
static PyObject *const_str_plain_Flatten;
static PyObject *const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple;
static PyObject *const_str_plain_conv2;
static PyObject *const_str_digest_ce0fdd9c7f95120b14280047fb0d1caf;
static PyObject *const_tuple_int_pos_10_tuple;
static PyObject *const_str_plain_flatten;
static PyObject *const_int_pos_3;
static PyObject *const_str_plain_dtype;
static PyObject *const_dict_0571e0394168da9eab0afb771d437043;
static PyObject *const_str_plain_float32;
static PyObject *const_tuple_int_pos_3_int_pos_3_tuple;
static PyObject *const_str_plain_outputs;
static PyObject *const_str_plain_cnn_model;
static PyObject *const_str_plain_Dense;
static PyObject *const_str_plain_origin;
static PyObject *const_int_pos_128;
static PyObject *const_str_plain_keras;
static PyObject *const_str_plain_shape;
static PyObject *const_str_plain_x;
static PyObject *const_tuple_int_pos_32_int_pos_32_int_pos_3_tuple;
static PyObject *const_str_plain_activation;
extern PyObject *const_tuple_empty;
static PyObject *const_str_plain_kernel_size;
static PyObject *const_int_pos_64;
static PyObject *const_str_plain_Conv2D;
static PyObject *const_str_plain_has_location;
static PyObject *const_str_plain_np;
static PyObject *const_str_plain_relu;
static PyObject *const_int_pos_2;
static PyObject *const_str_plain_out;
static PyObject *const_str_plain_tensorflow;
static PyObject *const_str_plain_strides;
static PyObject *const_str_plain_conv3;
static PyObject *const_tuple_int_pos_128_tuple;
static PyObject *const_str_plain_conv4;
static PyObject *const_str_plain_layers;
static PyObject *const_int_pos_10;
static PyObject *const_tuple_int_pos_256_tuple;
static PyObject *const_str_plain_SAME;
static PyObject *const_str_plain_conv1;
extern PyObject *const_str_plain___doc__;
extern PyObject *const_str_plain___cached__;
static PyObject *const_str_plain_fc1;
static PyObject *const_int_pos_32;
static PyObject *const_str_plain_Model;
static PyObject *module_filename_obj;

/* Indicator if this modules private constants were created yet. */
static bool constants_created = false;

/* Function to create module private constants. */
static void createModuleConstants(void) {
    const_str_plain_nn = UNSTREAM_STRING_ASCII(&constant_bin[ 24 ], 2, 1);
    const_str_digest_f91a67e9ac70ed2ea9f56633fb2f6965 = UNSTREAM_STRING_ASCII(&constant_bin[ 26 ], 6, 0);
    const_str_plain_padding = UNSTREAM_STRING_ASCII(&constant_bin[ 32 ], 7, 1);
    const_str_plain_fc2 = UNSTREAM_STRING_ASCII(&constant_bin[ 39 ], 3, 1);
    const_tuple_int_pos_2_int_pos_2_tuple = PyTuple_New(2);
    const_int_pos_2 = PyLong_FromUnsignedLong(2ul);
    PyTuple_SET_ITEM(const_tuple_int_pos_2_int_pos_2_tuple, 0, const_int_pos_2); Py_INCREF(const_int_pos_2);
    PyTuple_SET_ITEM(const_tuple_int_pos_2_int_pos_2_tuple, 1, const_int_pos_2); Py_INCREF(const_int_pos_2);
    const_str_plain_tf = UNSTREAM_STRING_ASCII(&constant_bin[ 6 ], 2, 1);
    const_str_plain_numpy = UNSTREAM_STRING_ASCII(&constant_bin[ 42 ], 5, 1);
    const_str_plain_filters = UNSTREAM_STRING_ASCII(&constant_bin[ 47 ], 7, 1);
    const_str_plain_inputs = UNSTREAM_STRING_ASCII(&constant_bin[ 54 ], 6, 1);
    const_int_pos_256 = PyLong_FromUnsignedLong(256ul);
    const_tuple_int_pos_1_int_pos_1_tuple = PyTuple_New(2);
    PyTuple_SET_ITEM(const_tuple_int_pos_1_int_pos_1_tuple, 0, const_int_pos_1); Py_INCREF(const_int_pos_1);
    PyTuple_SET_ITEM(const_tuple_int_pos_1_int_pos_1_tuple, 1, const_int_pos_1); Py_INCREF(const_int_pos_1);
    const_dict_d0ba5f3dd7c471476029202081fc960e = _PyDict_NewPresized( 1 );
    const_str_plain_activation = UNSTREAM_STRING_ASCII(&constant_bin[ 60 ], 10, 1);
    PyDict_SetItem(const_dict_d0ba5f3dd7c471476029202081fc960e, const_str_plain_activation, Py_None);
    assert(PyDict_Size(const_dict_d0ba5f3dd7c471476029202081fc960e) == 1);
    const_str_plain_Input = UNSTREAM_STRING_ASCII(&constant_bin[ 70 ], 5, 1);
    const_str_plain_Flatten = UNSTREAM_STRING_ASCII(&constant_bin[ 75 ], 7, 1);
    const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple = PyTuple_New(9);
    const_str_plain_x = UNSTREAM_STRING_ASCII(&constant_bin[ 82 ], 1, 1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 0, const_str_plain_x); Py_INCREF(const_str_plain_x);
    const_str_plain_conv1 = UNSTREAM_STRING_ASCII(&constant_bin[ 83 ], 5, 1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 1, const_str_plain_conv1); Py_INCREF(const_str_plain_conv1);
    const_str_plain_conv2 = UNSTREAM_STRING_ASCII(&constant_bin[ 88 ], 5, 1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 2, const_str_plain_conv2); Py_INCREF(const_str_plain_conv2);
    const_str_plain_conv3 = UNSTREAM_STRING_ASCII(&constant_bin[ 93 ], 5, 1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 3, const_str_plain_conv3); Py_INCREF(const_str_plain_conv3);
    const_str_plain_conv4 = UNSTREAM_STRING_ASCII(&constant_bin[ 98 ], 5, 1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 4, const_str_plain_conv4); Py_INCREF(const_str_plain_conv4);
    const_str_plain_flatten = UNSTREAM_STRING_ASCII(&constant_bin[ 103 ], 7, 1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 5, const_str_plain_flatten); Py_INCREF(const_str_plain_flatten);
    const_str_plain_fc1 = UNSTREAM_STRING_ASCII(&constant_bin[ 110 ], 3, 1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 6, const_str_plain_fc1); Py_INCREF(const_str_plain_fc1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 7, const_str_plain_fc2); Py_INCREF(const_str_plain_fc2);
    const_str_plain_out = UNSTREAM_STRING_ASCII(&constant_bin[ 113 ], 3, 1);
    PyTuple_SET_ITEM(const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 8, const_str_plain_out); Py_INCREF(const_str_plain_out);
    const_str_digest_ce0fdd9c7f95120b14280047fb0d1caf = UNSTREAM_STRING_ASCII(&constant_bin[ 116 ], 12, 0);
    const_tuple_int_pos_10_tuple = PyTuple_New(1);
    const_int_pos_10 = PyLong_FromUnsignedLong(10ul);
    PyTuple_SET_ITEM(const_tuple_int_pos_10_tuple, 0, const_int_pos_10); Py_INCREF(const_int_pos_10);
    const_int_pos_3 = PyLong_FromUnsignedLong(3ul);
    const_str_plain_dtype = UNSTREAM_STRING_ASCII(&constant_bin[ 128 ], 5, 1);
    const_dict_0571e0394168da9eab0afb771d437043 = _PyDict_NewPresized( 2 );
    const_str_plain_shape = UNSTREAM_STRING_ASCII(&constant_bin[ 133 ], 5, 1);
    const_tuple_int_pos_32_int_pos_32_int_pos_3_tuple = PyTuple_New(3);
    const_int_pos_32 = PyLong_FromUnsignedLong(32ul);
    PyTuple_SET_ITEM(const_tuple_int_pos_32_int_pos_32_int_pos_3_tuple, 0, const_int_pos_32); Py_INCREF(const_int_pos_32);
    PyTuple_SET_ITEM(const_tuple_int_pos_32_int_pos_32_int_pos_3_tuple, 1, const_int_pos_32); Py_INCREF(const_int_pos_32);
    PyTuple_SET_ITEM(const_tuple_int_pos_32_int_pos_32_int_pos_3_tuple, 2, const_int_pos_3); Py_INCREF(const_int_pos_3);
    PyDict_SetItem(const_dict_0571e0394168da9eab0afb771d437043, const_str_plain_shape, const_tuple_int_pos_32_int_pos_32_int_pos_3_tuple);
    const_str_plain_float32 = UNSTREAM_STRING_ASCII(&constant_bin[ 138 ], 7, 1);
    PyDict_SetItem(const_dict_0571e0394168da9eab0afb771d437043, const_str_plain_dtype, const_str_plain_float32);
    assert(PyDict_Size(const_dict_0571e0394168da9eab0afb771d437043) == 2);
    const_tuple_int_pos_3_int_pos_3_tuple = PyTuple_New(2);
    PyTuple_SET_ITEM(const_tuple_int_pos_3_int_pos_3_tuple, 0, const_int_pos_3); Py_INCREF(const_int_pos_3);
    PyTuple_SET_ITEM(const_tuple_int_pos_3_int_pos_3_tuple, 1, const_int_pos_3); Py_INCREF(const_int_pos_3);
    const_str_plain_outputs = UNSTREAM_STRING_ASCII(&constant_bin[ 145 ], 7, 1);
    const_str_plain_cnn_model = UNSTREAM_STRING_ASCII(&constant_bin[ 152 ], 9, 1);
    const_str_plain_Dense = UNSTREAM_STRING_ASCII(&constant_bin[ 161 ], 5, 1);
    const_str_plain_origin = UNSTREAM_STRING_ASCII(&constant_bin[ 166 ], 6, 1);
    const_int_pos_128 = PyLong_FromUnsignedLong(128ul);
    const_str_plain_keras = UNSTREAM_STRING_ASCII(&constant_bin[ 172 ], 5, 1);
    const_str_plain_kernel_size = UNSTREAM_STRING_ASCII(&constant_bin[ 177 ], 11, 1);
    const_int_pos_64 = PyLong_FromUnsignedLong(64ul);
    const_str_plain_Conv2D = UNSTREAM_STRING_ASCII(&constant_bin[ 188 ], 6, 1);
    const_str_plain_has_location = UNSTREAM_STRING_ASCII(&constant_bin[ 194 ], 12, 1);
    const_str_plain_np = UNSTREAM_STRING_ASCII(&constant_bin[ 55 ], 2, 1);
    const_str_plain_relu = UNSTREAM_STRING_ASCII(&constant_bin[ 206 ], 4, 1);
    const_str_plain_tensorflow = UNSTREAM_STRING_ASCII(&constant_bin[ 210 ], 10, 1);
    const_str_plain_strides = UNSTREAM_STRING_ASCII(&constant_bin[ 220 ], 7, 1);
    const_tuple_int_pos_128_tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(const_tuple_int_pos_128_tuple, 0, const_int_pos_128); Py_INCREF(const_int_pos_128);
    const_str_plain_layers = UNSTREAM_STRING_ASCII(&constant_bin[ 227 ], 6, 1);
    const_tuple_int_pos_256_tuple = PyTuple_New(1);
    PyTuple_SET_ITEM(const_tuple_int_pos_256_tuple, 0, const_int_pos_256); Py_INCREF(const_int_pos_256);
    const_str_plain_SAME = UNSTREAM_STRING_ASCII(&constant_bin[ 233 ], 4, 1);
    const_str_plain_Model = UNSTREAM_STRING_ASCII(&constant_bin[ 237 ], 5, 1);

    constants_created = true;
}

/* Function to verify module private constants for non-corruption. */
#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants_cnn(void) {
    // The module may not have been used at all, then ignore this.
    if (constants_created == false) return;


}
#endif

// The module code objects.
static PyCodeObject *codeobj_2881f1a9b6a3f6265a1cd055d9c6d020;
static PyCodeObject *codeobj_13d7a984ecc78250017a622ad0b20003;

static void createModuleCodeObjects(void) {
    module_filename_obj = MAKE_RELATIVE_PATH(const_str_digest_f91a67e9ac70ed2ea9f56633fb2f6965);
    codeobj_2881f1a9b6a3f6265a1cd055d9c6d020 = MAKE_CODEOBJECT(module_filename_obj, 1, CO_NOFREE, const_str_digest_ce0fdd9c7f95120b14280047fb0d1caf, const_tuple_empty, 0, 0, 0);
    codeobj_13d7a984ecc78250017a622ad0b20003 = MAKE_CODEOBJECT(module_filename_obj, 4, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE, const_str_plain_cnn_model, const_tuple_59d0288dd44fee8188e679ddc6b79761_tuple, 0, 0, 0);
}

// The module function declarations.
static PyObject *MAKE_FUNCTION_cnn$$$function_1_cnn_model();


// The module function definitions.
static PyObject *impl_cnn$$$function_1_cnn_model(struct Nuitka_FunctionObject const *self, PyObject **python_pars) {
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *var_x = NULL;
    PyObject *var_conv1 = NULL;
    PyObject *var_conv2 = NULL;
    PyObject *var_conv3 = NULL;
    PyObject *var_conv4 = NULL;
    PyObject *var_flatten = NULL;
    PyObject *var_fc1 = NULL;
    PyObject *var_fc2 = NULL;
    PyObject *var_out = NULL;
    struct Nuitka_FrameObject *frame_13d7a984ecc78250017a622ad0b20003;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    int tmp_res;
    PyObject *tmp_return_value = NULL;
    static struct Nuitka_FrameObject *cache_frame_13d7a984ecc78250017a622ad0b20003 = NULL;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;

    // Actual function body.
    // Tried code:
    if (isFrameUnusable(cache_frame_13d7a984ecc78250017a622ad0b20003)) {
        Py_XDECREF(cache_frame_13d7a984ecc78250017a622ad0b20003);

#if _DEBUG_REFCOUNTS
        if (cache_frame_13d7a984ecc78250017a622ad0b20003 == NULL) {
            count_active_frame_cache_instances += 1;
        } else {
            count_released_frame_cache_instances += 1;
        }
        count_allocated_frame_cache_instances += 1;
#endif
        cache_frame_13d7a984ecc78250017a622ad0b20003 = MAKE_FUNCTION_FRAME(codeobj_13d7a984ecc78250017a622ad0b20003, module_cnn, sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *));
#if _DEBUG_REFCOUNTS
    } else {
        count_hit_frame_cache_instances += 1;
#endif
    }
    assert(cache_frame_13d7a984ecc78250017a622ad0b20003->m_type_description == NULL);
    frame_13d7a984ecc78250017a622ad0b20003 = cache_frame_13d7a984ecc78250017a622ad0b20003;

    // Push the new frame as the currently active one.
    pushFrameStack(frame_13d7a984ecc78250017a622ad0b20003);

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert(Py_REFCNT(frame_13d7a984ecc78250017a622ad0b20003) == 2); // Frame stack

    // Framed code:
    {
        PyObject *tmp_assign_source_1;
        PyObject *tmp_called_name_1;
        PyObject *tmp_expression_name_1;
        PyObject *tmp_expression_name_2;
        PyObject *tmp_expression_name_3;
        PyObject *tmp_mvar_value_1;
        PyObject *tmp_kw_name_1;
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_1 == NULL)) {
            tmp_mvar_value_1 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_1 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 5;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_3 = tmp_mvar_value_1;
        tmp_expression_name_2 = LOOKUP_ATTRIBUTE(tmp_expression_name_3, const_str_plain_keras);
        if (tmp_expression_name_2 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 5;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_expression_name_1 = LOOKUP_ATTRIBUTE(tmp_expression_name_2, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_2);
        if (tmp_expression_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 5;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_1 = LOOKUP_ATTRIBUTE(tmp_expression_name_1, const_str_plain_Input);
        Py_DECREF(tmp_expression_name_1);
        if (tmp_called_name_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 5;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_kw_name_1 = PyDict_Copy(const_dict_0571e0394168da9eab0afb771d437043);
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 5;
        tmp_assign_source_1 = CALL_FUNCTION_WITH_KEYARGS(tmp_called_name_1, tmp_kw_name_1);
        Py_DECREF(tmp_called_name_1);
        Py_DECREF(tmp_kw_name_1);
        if (tmp_assign_source_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 5;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_x == NULL);
        var_x = tmp_assign_source_1;
    }
    {
        PyObject *tmp_assign_source_2;
        PyObject *tmp_called_name_2;
        PyObject *tmp_called_name_3;
        PyObject *tmp_expression_name_4;
        PyObject *tmp_expression_name_5;
        PyObject *tmp_expression_name_6;
        PyObject *tmp_mvar_value_2;
        PyObject *tmp_kw_name_2;
        PyObject *tmp_dict_key_1;
        PyObject *tmp_dict_value_1;
        PyObject *tmp_dict_key_2;
        PyObject *tmp_dict_value_2;
        PyObject *tmp_dict_key_3;
        PyObject *tmp_dict_value_3;
        PyObject *tmp_dict_key_4;
        PyObject *tmp_dict_value_4;
        PyObject *tmp_dict_key_5;
        PyObject *tmp_dict_value_5;
        PyObject *tmp_expression_name_7;
        PyObject *tmp_expression_name_8;
        PyObject *tmp_mvar_value_3;
        PyObject *tmp_args_element_name_1;
        tmp_mvar_value_2 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_2 == NULL)) {
            tmp_mvar_value_2 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_2 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_6 = tmp_mvar_value_2;
        tmp_expression_name_5 = LOOKUP_ATTRIBUTE(tmp_expression_name_6, const_str_plain_keras);
        if (tmp_expression_name_5 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_expression_name_4 = LOOKUP_ATTRIBUTE(tmp_expression_name_5, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_5);
        if (tmp_expression_name_4 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_3 = LOOKUP_ATTRIBUTE(tmp_expression_name_4, const_str_plain_Conv2D);
        Py_DECREF(tmp_expression_name_4);
        if (tmp_called_name_3 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_key_1 = const_str_plain_filters;
        tmp_dict_value_1 = const_int_pos_64;
        tmp_kw_name_2 = _PyDict_NewPresized( 5 );
        tmp_res = PyDict_SetItem(tmp_kw_name_2, tmp_dict_key_1, tmp_dict_value_1);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = const_str_plain_kernel_size;
        tmp_dict_value_2 = const_tuple_int_pos_3_int_pos_3_tuple;
        tmp_res = PyDict_SetItem(tmp_kw_name_2, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_3 = const_str_plain_strides;
        tmp_dict_value_3 = const_tuple_int_pos_1_int_pos_1_tuple;
        tmp_res = PyDict_SetItem(tmp_kw_name_2, tmp_dict_key_3, tmp_dict_value_3);
        assert(!(tmp_res != 0));
        tmp_dict_key_4 = const_str_plain_padding;
        tmp_dict_value_4 = const_str_plain_SAME;
        tmp_res = PyDict_SetItem(tmp_kw_name_2, tmp_dict_key_4, tmp_dict_value_4);
        assert(!(tmp_res != 0));
        tmp_dict_key_5 = const_str_plain_activation;
        tmp_mvar_value_3 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_3 == NULL)) {
            tmp_mvar_value_3 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_3 == NULL) {
            Py_DECREF(tmp_called_name_3);
            Py_DECREF(tmp_kw_name_2);
            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_8 = tmp_mvar_value_3;
        tmp_expression_name_7 = LOOKUP_ATTRIBUTE(tmp_expression_name_8, const_str_plain_nn);
        if (tmp_expression_name_7 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_3);
            Py_DECREF(tmp_kw_name_2);

            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_value_5 = LOOKUP_ATTRIBUTE(tmp_expression_name_7, const_str_plain_relu);
        Py_DECREF(tmp_expression_name_7);
        if (tmp_dict_value_5 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_3);
            Py_DECREF(tmp_kw_name_2);

            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_res = PyDict_SetItem(tmp_kw_name_2, tmp_dict_key_5, tmp_dict_value_5);
        Py_DECREF(tmp_dict_value_5);
        assert(!(tmp_res != 0));
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 6;
        tmp_called_name_2 = CALL_FUNCTION_WITH_KEYARGS(tmp_called_name_3, tmp_kw_name_2);
        Py_DECREF(tmp_called_name_3);
        Py_DECREF(tmp_kw_name_2);
        if (tmp_called_name_2 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_x);
        tmp_args_element_name_1 = var_x;
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 6;
        tmp_assign_source_2 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_2, tmp_args_element_name_1);
        Py_DECREF(tmp_called_name_2);
        if (tmp_assign_source_2 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 6;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_conv1 == NULL);
        var_conv1 = tmp_assign_source_2;
    }
    {
        PyObject *tmp_assign_source_3;
        PyObject *tmp_called_name_4;
        PyObject *tmp_called_name_5;
        PyObject *tmp_expression_name_9;
        PyObject *tmp_expression_name_10;
        PyObject *tmp_expression_name_11;
        PyObject *tmp_mvar_value_4;
        PyObject *tmp_kw_name_3;
        PyObject *tmp_dict_key_6;
        PyObject *tmp_dict_value_6;
        PyObject *tmp_dict_key_7;
        PyObject *tmp_dict_value_7;
        PyObject *tmp_dict_key_8;
        PyObject *tmp_dict_value_8;
        PyObject *tmp_dict_key_9;
        PyObject *tmp_dict_value_9;
        PyObject *tmp_dict_key_10;
        PyObject *tmp_dict_value_10;
        PyObject *tmp_expression_name_12;
        PyObject *tmp_expression_name_13;
        PyObject *tmp_mvar_value_5;
        PyObject *tmp_args_element_name_2;
        tmp_mvar_value_4 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_4 == NULL)) {
            tmp_mvar_value_4 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_4 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_11 = tmp_mvar_value_4;
        tmp_expression_name_10 = LOOKUP_ATTRIBUTE(tmp_expression_name_11, const_str_plain_keras);
        if (tmp_expression_name_10 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_expression_name_9 = LOOKUP_ATTRIBUTE(tmp_expression_name_10, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_10);
        if (tmp_expression_name_9 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_5 = LOOKUP_ATTRIBUTE(tmp_expression_name_9, const_str_plain_Conv2D);
        Py_DECREF(tmp_expression_name_9);
        if (tmp_called_name_5 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_key_6 = const_str_plain_filters;
        tmp_dict_value_6 = const_int_pos_64;
        tmp_kw_name_3 = _PyDict_NewPresized( 5 );
        tmp_res = PyDict_SetItem(tmp_kw_name_3, tmp_dict_key_6, tmp_dict_value_6);
        assert(!(tmp_res != 0));
        tmp_dict_key_7 = const_str_plain_kernel_size;
        tmp_dict_value_7 = const_tuple_int_pos_3_int_pos_3_tuple;
        tmp_res = PyDict_SetItem(tmp_kw_name_3, tmp_dict_key_7, tmp_dict_value_7);
        assert(!(tmp_res != 0));
        tmp_dict_key_8 = const_str_plain_strides;
        tmp_dict_value_8 = const_tuple_int_pos_2_int_pos_2_tuple;
        tmp_res = PyDict_SetItem(tmp_kw_name_3, tmp_dict_key_8, tmp_dict_value_8);
        assert(!(tmp_res != 0));
        tmp_dict_key_9 = const_str_plain_padding;
        tmp_dict_value_9 = const_str_plain_SAME;
        tmp_res = PyDict_SetItem(tmp_kw_name_3, tmp_dict_key_9, tmp_dict_value_9);
        assert(!(tmp_res != 0));
        tmp_dict_key_10 = const_str_plain_activation;
        tmp_mvar_value_5 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_5 == NULL)) {
            tmp_mvar_value_5 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_5 == NULL) {
            Py_DECREF(tmp_called_name_5);
            Py_DECREF(tmp_kw_name_3);
            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_13 = tmp_mvar_value_5;
        tmp_expression_name_12 = LOOKUP_ATTRIBUTE(tmp_expression_name_13, const_str_plain_nn);
        if (tmp_expression_name_12 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_5);
            Py_DECREF(tmp_kw_name_3);

            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_value_10 = LOOKUP_ATTRIBUTE(tmp_expression_name_12, const_str_plain_relu);
        Py_DECREF(tmp_expression_name_12);
        if (tmp_dict_value_10 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_5);
            Py_DECREF(tmp_kw_name_3);

            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_res = PyDict_SetItem(tmp_kw_name_3, tmp_dict_key_10, tmp_dict_value_10);
        Py_DECREF(tmp_dict_value_10);
        assert(!(tmp_res != 0));
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 7;
        tmp_called_name_4 = CALL_FUNCTION_WITH_KEYARGS(tmp_called_name_5, tmp_kw_name_3);
        Py_DECREF(tmp_called_name_5);
        Py_DECREF(tmp_kw_name_3);
        if (tmp_called_name_4 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_conv1);
        tmp_args_element_name_2 = var_conv1;
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 7;
        tmp_assign_source_3 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_4, tmp_args_element_name_2);
        Py_DECREF(tmp_called_name_4);
        if (tmp_assign_source_3 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 7;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_conv2 == NULL);
        var_conv2 = tmp_assign_source_3;
    }
    {
        PyObject *tmp_assign_source_4;
        PyObject *tmp_called_name_6;
        PyObject *tmp_called_name_7;
        PyObject *tmp_expression_name_14;
        PyObject *tmp_expression_name_15;
        PyObject *tmp_expression_name_16;
        PyObject *tmp_mvar_value_6;
        PyObject *tmp_kw_name_4;
        PyObject *tmp_dict_key_11;
        PyObject *tmp_dict_value_11;
        PyObject *tmp_dict_key_12;
        PyObject *tmp_dict_value_12;
        PyObject *tmp_dict_key_13;
        PyObject *tmp_dict_value_13;
        PyObject *tmp_dict_key_14;
        PyObject *tmp_dict_value_14;
        PyObject *tmp_dict_key_15;
        PyObject *tmp_dict_value_15;
        PyObject *tmp_expression_name_17;
        PyObject *tmp_expression_name_18;
        PyObject *tmp_mvar_value_7;
        PyObject *tmp_args_element_name_3;
        tmp_mvar_value_6 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_6 == NULL)) {
            tmp_mvar_value_6 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_6 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_16 = tmp_mvar_value_6;
        tmp_expression_name_15 = LOOKUP_ATTRIBUTE(tmp_expression_name_16, const_str_plain_keras);
        if (tmp_expression_name_15 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_expression_name_14 = LOOKUP_ATTRIBUTE(tmp_expression_name_15, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_15);
        if (tmp_expression_name_14 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_7 = LOOKUP_ATTRIBUTE(tmp_expression_name_14, const_str_plain_Conv2D);
        Py_DECREF(tmp_expression_name_14);
        if (tmp_called_name_7 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_key_11 = const_str_plain_filters;
        tmp_dict_value_11 = const_int_pos_64;
        tmp_kw_name_4 = _PyDict_NewPresized( 5 );
        tmp_res = PyDict_SetItem(tmp_kw_name_4, tmp_dict_key_11, tmp_dict_value_11);
        assert(!(tmp_res != 0));
        tmp_dict_key_12 = const_str_plain_kernel_size;
        tmp_dict_value_12 = const_tuple_int_pos_3_int_pos_3_tuple;
        tmp_res = PyDict_SetItem(tmp_kw_name_4, tmp_dict_key_12, tmp_dict_value_12);
        assert(!(tmp_res != 0));
        tmp_dict_key_13 = const_str_plain_strides;
        tmp_dict_value_13 = const_tuple_int_pos_2_int_pos_2_tuple;
        tmp_res = PyDict_SetItem(tmp_kw_name_4, tmp_dict_key_13, tmp_dict_value_13);
        assert(!(tmp_res != 0));
        tmp_dict_key_14 = const_str_plain_padding;
        tmp_dict_value_14 = const_str_plain_SAME;
        tmp_res = PyDict_SetItem(tmp_kw_name_4, tmp_dict_key_14, tmp_dict_value_14);
        assert(!(tmp_res != 0));
        tmp_dict_key_15 = const_str_plain_activation;
        tmp_mvar_value_7 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_7 == NULL)) {
            tmp_mvar_value_7 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_7 == NULL) {
            Py_DECREF(tmp_called_name_7);
            Py_DECREF(tmp_kw_name_4);
            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_18 = tmp_mvar_value_7;
        tmp_expression_name_17 = LOOKUP_ATTRIBUTE(tmp_expression_name_18, const_str_plain_nn);
        if (tmp_expression_name_17 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_7);
            Py_DECREF(tmp_kw_name_4);

            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_value_15 = LOOKUP_ATTRIBUTE(tmp_expression_name_17, const_str_plain_relu);
        Py_DECREF(tmp_expression_name_17);
        if (tmp_dict_value_15 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_7);
            Py_DECREF(tmp_kw_name_4);

            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_res = PyDict_SetItem(tmp_kw_name_4, tmp_dict_key_15, tmp_dict_value_15);
        Py_DECREF(tmp_dict_value_15);
        assert(!(tmp_res != 0));
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 8;
        tmp_called_name_6 = CALL_FUNCTION_WITH_KEYARGS(tmp_called_name_7, tmp_kw_name_4);
        Py_DECREF(tmp_called_name_7);
        Py_DECREF(tmp_kw_name_4);
        if (tmp_called_name_6 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_conv2);
        tmp_args_element_name_3 = var_conv2;
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 8;
        tmp_assign_source_4 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_6, tmp_args_element_name_3);
        Py_DECREF(tmp_called_name_6);
        if (tmp_assign_source_4 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 8;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_conv3 == NULL);
        var_conv3 = tmp_assign_source_4;
    }
    {
        PyObject *tmp_assign_source_5;
        PyObject *tmp_called_name_8;
        PyObject *tmp_called_name_9;
        PyObject *tmp_expression_name_19;
        PyObject *tmp_expression_name_20;
        PyObject *tmp_expression_name_21;
        PyObject *tmp_mvar_value_8;
        PyObject *tmp_kw_name_5;
        PyObject *tmp_dict_key_16;
        PyObject *tmp_dict_value_16;
        PyObject *tmp_dict_key_17;
        PyObject *tmp_dict_value_17;
        PyObject *tmp_dict_key_18;
        PyObject *tmp_dict_value_18;
        PyObject *tmp_dict_key_19;
        PyObject *tmp_dict_value_19;
        PyObject *tmp_dict_key_20;
        PyObject *tmp_dict_value_20;
        PyObject *tmp_expression_name_22;
        PyObject *tmp_expression_name_23;
        PyObject *tmp_mvar_value_9;
        PyObject *tmp_args_element_name_4;
        tmp_mvar_value_8 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_8 == NULL)) {
            tmp_mvar_value_8 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_8 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_21 = tmp_mvar_value_8;
        tmp_expression_name_20 = LOOKUP_ATTRIBUTE(tmp_expression_name_21, const_str_plain_keras);
        if (tmp_expression_name_20 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_expression_name_19 = LOOKUP_ATTRIBUTE(tmp_expression_name_20, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_20);
        if (tmp_expression_name_19 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_9 = LOOKUP_ATTRIBUTE(tmp_expression_name_19, const_str_plain_Conv2D);
        Py_DECREF(tmp_expression_name_19);
        if (tmp_called_name_9 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_key_16 = const_str_plain_filters;
        tmp_dict_value_16 = const_int_pos_64;
        tmp_kw_name_5 = _PyDict_NewPresized( 5 );
        tmp_res = PyDict_SetItem(tmp_kw_name_5, tmp_dict_key_16, tmp_dict_value_16);
        assert(!(tmp_res != 0));
        tmp_dict_key_17 = const_str_plain_kernel_size;
        tmp_dict_value_17 = const_tuple_int_pos_3_int_pos_3_tuple;
        tmp_res = PyDict_SetItem(tmp_kw_name_5, tmp_dict_key_17, tmp_dict_value_17);
        assert(!(tmp_res != 0));
        tmp_dict_key_18 = const_str_plain_strides;
        tmp_dict_value_18 = const_tuple_int_pos_2_int_pos_2_tuple;
        tmp_res = PyDict_SetItem(tmp_kw_name_5, tmp_dict_key_18, tmp_dict_value_18);
        assert(!(tmp_res != 0));
        tmp_dict_key_19 = const_str_plain_padding;
        tmp_dict_value_19 = const_str_plain_SAME;
        tmp_res = PyDict_SetItem(tmp_kw_name_5, tmp_dict_key_19, tmp_dict_value_19);
        assert(!(tmp_res != 0));
        tmp_dict_key_20 = const_str_plain_activation;
        tmp_mvar_value_9 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_9 == NULL)) {
            tmp_mvar_value_9 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_9 == NULL) {
            Py_DECREF(tmp_called_name_9);
            Py_DECREF(tmp_kw_name_5);
            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_23 = tmp_mvar_value_9;
        tmp_expression_name_22 = LOOKUP_ATTRIBUTE(tmp_expression_name_23, const_str_plain_nn);
        if (tmp_expression_name_22 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_9);
            Py_DECREF(tmp_kw_name_5);

            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_value_20 = LOOKUP_ATTRIBUTE(tmp_expression_name_22, const_str_plain_relu);
        Py_DECREF(tmp_expression_name_22);
        if (tmp_dict_value_20 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_9);
            Py_DECREF(tmp_kw_name_5);

            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_res = PyDict_SetItem(tmp_kw_name_5, tmp_dict_key_20, tmp_dict_value_20);
        Py_DECREF(tmp_dict_value_20);
        assert(!(tmp_res != 0));
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 9;
        tmp_called_name_8 = CALL_FUNCTION_WITH_KEYARGS(tmp_called_name_9, tmp_kw_name_5);
        Py_DECREF(tmp_called_name_9);
        Py_DECREF(tmp_kw_name_5);
        if (tmp_called_name_8 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_conv3);
        tmp_args_element_name_4 = var_conv3;
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 9;
        tmp_assign_source_5 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_8, tmp_args_element_name_4);
        Py_DECREF(tmp_called_name_8);
        if (tmp_assign_source_5 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 9;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_conv4 == NULL);
        var_conv4 = tmp_assign_source_5;
    }
    {
        PyObject *tmp_assign_source_6;
        PyObject *tmp_called_name_10;
        PyObject *tmp_called_instance_1;
        PyObject *tmp_expression_name_24;
        PyObject *tmp_expression_name_25;
        PyObject *tmp_mvar_value_10;
        PyObject *tmp_args_element_name_5;
        tmp_mvar_value_10 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_10 == NULL)) {
            tmp_mvar_value_10 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_10 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 11;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_25 = tmp_mvar_value_10;
        tmp_expression_name_24 = LOOKUP_ATTRIBUTE(tmp_expression_name_25, const_str_plain_keras);
        if (tmp_expression_name_24 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 11;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_instance_1 = LOOKUP_ATTRIBUTE(tmp_expression_name_24, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_24);
        if (tmp_called_instance_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 11;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 11;
        tmp_called_name_10 = CALL_METHOD_NO_ARGS(tmp_called_instance_1, const_str_plain_Flatten);
        Py_DECREF(tmp_called_instance_1);
        if (tmp_called_name_10 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 11;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_conv4);
        tmp_args_element_name_5 = var_conv4;
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 11;
        tmp_assign_source_6 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_10, tmp_args_element_name_5);
        Py_DECREF(tmp_called_name_10);
        if (tmp_assign_source_6 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 11;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_flatten == NULL);
        var_flatten = tmp_assign_source_6;
    }
    {
        PyObject *tmp_assign_source_7;
        PyObject *tmp_called_name_11;
        PyObject *tmp_called_name_12;
        PyObject *tmp_expression_name_26;
        PyObject *tmp_expression_name_27;
        PyObject *tmp_expression_name_28;
        PyObject *tmp_mvar_value_11;
        PyObject *tmp_args_name_1;
        PyObject *tmp_kw_name_6;
        PyObject *tmp_dict_key_21;
        PyObject *tmp_dict_value_21;
        PyObject *tmp_expression_name_29;
        PyObject *tmp_expression_name_30;
        PyObject *tmp_mvar_value_12;
        PyObject *tmp_args_element_name_6;
        tmp_mvar_value_11 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_11 == NULL)) {
            tmp_mvar_value_11 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_11 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_28 = tmp_mvar_value_11;
        tmp_expression_name_27 = LOOKUP_ATTRIBUTE(tmp_expression_name_28, const_str_plain_keras);
        if (tmp_expression_name_27 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_expression_name_26 = LOOKUP_ATTRIBUTE(tmp_expression_name_27, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_27);
        if (tmp_expression_name_26 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_12 = LOOKUP_ATTRIBUTE(tmp_expression_name_26, const_str_plain_Dense);
        Py_DECREF(tmp_expression_name_26);
        if (tmp_called_name_12 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_args_name_1 = const_tuple_int_pos_256_tuple;
        tmp_dict_key_21 = const_str_plain_activation;
        tmp_mvar_value_12 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_12 == NULL)) {
            tmp_mvar_value_12 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_12 == NULL) {
            Py_DECREF(tmp_called_name_12);
            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_30 = tmp_mvar_value_12;
        tmp_expression_name_29 = LOOKUP_ATTRIBUTE(tmp_expression_name_30, const_str_plain_nn);
        if (tmp_expression_name_29 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_12);

            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_value_21 = LOOKUP_ATTRIBUTE(tmp_expression_name_29, const_str_plain_relu);
        Py_DECREF(tmp_expression_name_29);
        if (tmp_dict_value_21 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_12);

            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_kw_name_6 = _PyDict_NewPresized( 1 );
        tmp_res = PyDict_SetItem(tmp_kw_name_6, tmp_dict_key_21, tmp_dict_value_21);
        Py_DECREF(tmp_dict_value_21);
        assert(!(tmp_res != 0));
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 13;
        tmp_called_name_11 = CALL_FUNCTION(tmp_called_name_12, tmp_args_name_1, tmp_kw_name_6);
        Py_DECREF(tmp_called_name_12);
        Py_DECREF(tmp_kw_name_6);
        if (tmp_called_name_11 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_flatten);
        tmp_args_element_name_6 = var_flatten;
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 13;
        tmp_assign_source_7 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_11, tmp_args_element_name_6);
        Py_DECREF(tmp_called_name_11);
        if (tmp_assign_source_7 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 13;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_fc1 == NULL);
        var_fc1 = tmp_assign_source_7;
    }
    {
        PyObject *tmp_assign_source_8;
        PyObject *tmp_called_name_13;
        PyObject *tmp_called_name_14;
        PyObject *tmp_expression_name_31;
        PyObject *tmp_expression_name_32;
        PyObject *tmp_expression_name_33;
        PyObject *tmp_mvar_value_13;
        PyObject *tmp_args_name_2;
        PyObject *tmp_kw_name_7;
        PyObject *tmp_dict_key_22;
        PyObject *tmp_dict_value_22;
        PyObject *tmp_expression_name_34;
        PyObject *tmp_expression_name_35;
        PyObject *tmp_mvar_value_14;
        PyObject *tmp_args_element_name_7;
        tmp_mvar_value_13 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_13 == NULL)) {
            tmp_mvar_value_13 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_13 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_33 = tmp_mvar_value_13;
        tmp_expression_name_32 = LOOKUP_ATTRIBUTE(tmp_expression_name_33, const_str_plain_keras);
        if (tmp_expression_name_32 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_expression_name_31 = LOOKUP_ATTRIBUTE(tmp_expression_name_32, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_32);
        if (tmp_expression_name_31 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_14 = LOOKUP_ATTRIBUTE(tmp_expression_name_31, const_str_plain_Dense);
        Py_DECREF(tmp_expression_name_31);
        if (tmp_called_name_14 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_args_name_2 = const_tuple_int_pos_128_tuple;
        tmp_dict_key_22 = const_str_plain_activation;
        tmp_mvar_value_14 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_14 == NULL)) {
            tmp_mvar_value_14 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_14 == NULL) {
            Py_DECREF(tmp_called_name_14);
            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_35 = tmp_mvar_value_14;
        tmp_expression_name_34 = LOOKUP_ATTRIBUTE(tmp_expression_name_35, const_str_plain_nn);
        if (tmp_expression_name_34 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_14);

            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_value_22 = LOOKUP_ATTRIBUTE(tmp_expression_name_34, const_str_plain_relu);
        Py_DECREF(tmp_expression_name_34);
        if (tmp_dict_value_22 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_called_name_14);

            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_kw_name_7 = _PyDict_NewPresized( 1 );
        tmp_res = PyDict_SetItem(tmp_kw_name_7, tmp_dict_key_22, tmp_dict_value_22);
        Py_DECREF(tmp_dict_value_22);
        assert(!(tmp_res != 0));
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 14;
        tmp_called_name_13 = CALL_FUNCTION(tmp_called_name_14, tmp_args_name_2, tmp_kw_name_7);
        Py_DECREF(tmp_called_name_14);
        Py_DECREF(tmp_kw_name_7);
        if (tmp_called_name_13 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_fc1);
        tmp_args_element_name_7 = var_fc1;
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 14;
        tmp_assign_source_8 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_13, tmp_args_element_name_7);
        Py_DECREF(tmp_called_name_13);
        if (tmp_assign_source_8 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 14;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_fc2 == NULL);
        var_fc2 = tmp_assign_source_8;
    }
    {
        PyObject *tmp_assign_source_9;
        PyObject *tmp_called_name_15;
        PyObject *tmp_called_name_16;
        PyObject *tmp_expression_name_36;
        PyObject *tmp_expression_name_37;
        PyObject *tmp_expression_name_38;
        PyObject *tmp_mvar_value_15;
        PyObject *tmp_args_name_3;
        PyObject *tmp_kw_name_8;
        PyObject *tmp_args_element_name_8;
        tmp_mvar_value_15 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_15 == NULL)) {
            tmp_mvar_value_15 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_15 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 15;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_38 = tmp_mvar_value_15;
        tmp_expression_name_37 = LOOKUP_ATTRIBUTE(tmp_expression_name_38, const_str_plain_keras);
        if (tmp_expression_name_37 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 15;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_expression_name_36 = LOOKUP_ATTRIBUTE(tmp_expression_name_37, const_str_plain_layers);
        Py_DECREF(tmp_expression_name_37);
        if (tmp_expression_name_36 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 15;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_16 = LOOKUP_ATTRIBUTE(tmp_expression_name_36, const_str_plain_Dense);
        Py_DECREF(tmp_expression_name_36);
        if (tmp_called_name_16 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 15;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_args_name_3 = const_tuple_int_pos_10_tuple;
        tmp_kw_name_8 = PyDict_Copy(const_dict_d0ba5f3dd7c471476029202081fc960e);
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 15;
        tmp_called_name_15 = CALL_FUNCTION(tmp_called_name_16, tmp_args_name_3, tmp_kw_name_8);
        Py_DECREF(tmp_called_name_16);
        Py_DECREF(tmp_kw_name_8);
        if (tmp_called_name_15 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 15;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        CHECK_OBJECT(var_fc2);
        tmp_args_element_name_8 = var_fc2;
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 15;
        tmp_assign_source_9 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_name_15, tmp_args_element_name_8);
        Py_DECREF(tmp_called_name_15);
        if (tmp_assign_source_9 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 15;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        assert(var_out == NULL);
        var_out = tmp_assign_source_9;
    }
    {
        PyObject *tmp_called_name_17;
        PyObject *tmp_expression_name_39;
        PyObject *tmp_expression_name_40;
        PyObject *tmp_mvar_value_16;
        PyObject *tmp_kw_name_9;
        PyObject *tmp_dict_key_23;
        PyObject *tmp_dict_value_23;
        PyObject *tmp_dict_key_24;
        PyObject *tmp_dict_value_24;
        tmp_mvar_value_16 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf);

        if (unlikely(tmp_mvar_value_16 == NULL)) {
            tmp_mvar_value_16 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain_tf);
        }

        if (tmp_mvar_value_16 == NULL) {

            exception_type = PyExc_NameError;
            Py_INCREF(exception_type);
            exception_value = UNSTREAM_STRING(&constant_bin[ 0 ], 24, 0);
            exception_tb = NULL;
            NORMALIZE_EXCEPTION(&exception_type, &exception_value, &exception_tb);
            CHAIN_EXCEPTION(exception_value);

            exception_lineno = 18;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }

        tmp_expression_name_40 = tmp_mvar_value_16;
        tmp_expression_name_39 = LOOKUP_ATTRIBUTE(tmp_expression_name_40, const_str_plain_keras);
        if (tmp_expression_name_39 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 18;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_called_name_17 = LOOKUP_ATTRIBUTE(tmp_expression_name_39, const_str_plain_Model);
        Py_DECREF(tmp_expression_name_39);
        if (tmp_called_name_17 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 18;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        tmp_dict_key_23 = const_str_plain_inputs;
        CHECK_OBJECT(var_x);
        tmp_dict_value_23 = var_x;
        tmp_kw_name_9 = _PyDict_NewPresized( 2 );
        tmp_res = PyDict_SetItem(tmp_kw_name_9, tmp_dict_key_23, tmp_dict_value_23);
        assert(!(tmp_res != 0));
        tmp_dict_key_24 = const_str_plain_outputs;
        CHECK_OBJECT(var_out);
        tmp_dict_value_24 = var_out;
        tmp_res = PyDict_SetItem(tmp_kw_name_9, tmp_dict_key_24, tmp_dict_value_24);
        assert(!(tmp_res != 0));
        frame_13d7a984ecc78250017a622ad0b20003->m_frame.f_lineno = 18;
        tmp_return_value = CALL_FUNCTION_WITH_KEYARGS(tmp_called_name_17, tmp_kw_name_9);
        Py_DECREF(tmp_called_name_17);
        Py_DECREF(tmp_kw_name_9);
        if (tmp_return_value == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 18;
            type_description_1 = "ooooooooo";
            goto frame_exception_exit_1;
        }
        goto frame_return_exit_1;
    }

#if 0
    RESTORE_FRAME_EXCEPTION(frame_13d7a984ecc78250017a622ad0b20003);
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION(frame_13d7a984ecc78250017a622ad0b20003);
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION(frame_13d7a984ecc78250017a622ad0b20003);
#endif

    if (exception_tb == NULL) {
        exception_tb = MAKE_TRACEBACK(frame_13d7a984ecc78250017a622ad0b20003, exception_lineno);
    } else if (exception_tb->tb_frame != &frame_13d7a984ecc78250017a622ad0b20003->m_frame) {
        exception_tb = ADD_TRACEBACK(exception_tb, frame_13d7a984ecc78250017a622ad0b20003, exception_lineno);
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        frame_13d7a984ecc78250017a622ad0b20003,
        type_description_1,
        var_x,
        var_conv1,
        var_conv2,
        var_conv3,
        var_conv4,
        var_flatten,
        var_fc1,
        var_fc2,
        var_out
    );


    // Release cached frame.
    if (frame_13d7a984ecc78250017a622ad0b20003 == cache_frame_13d7a984ecc78250017a622ad0b20003) {
#if _DEBUG_REFCOUNTS
        count_active_frame_cache_instances -= 1;
        count_released_frame_cache_instances += 1;
#endif

        Py_DECREF(frame_13d7a984ecc78250017a622ad0b20003);
    }
    cache_frame_13d7a984ecc78250017a622ad0b20003 = NULL;

    assertFrameObject(frame_13d7a984ecc78250017a622ad0b20003);

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    CHECK_OBJECT(var_x);
    Py_DECREF(var_x);
    var_x = NULL;

    CHECK_OBJECT(var_conv1);
    Py_DECREF(var_conv1);
    var_conv1 = NULL;

    CHECK_OBJECT(var_conv2);
    Py_DECREF(var_conv2);
    var_conv2 = NULL;

    CHECK_OBJECT(var_conv3);
    Py_DECREF(var_conv3);
    var_conv3 = NULL;

    CHECK_OBJECT(var_conv4);
    Py_DECREF(var_conv4);
    var_conv4 = NULL;

    CHECK_OBJECT(var_flatten);
    Py_DECREF(var_flatten);
    var_flatten = NULL;

    CHECK_OBJECT(var_fc1);
    Py_DECREF(var_fc1);
    var_fc1 = NULL;

    CHECK_OBJECT(var_fc2);
    Py_DECREF(var_fc2);
    var_fc2 = NULL;

    CHECK_OBJECT(var_out);
    Py_DECREF(var_out);
    var_out = NULL;

    goto function_return_exit;
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(var_x);
    var_x = NULL;

    Py_XDECREF(var_conv1);
    var_conv1 = NULL;

    Py_XDECREF(var_conv2);
    var_conv2 = NULL;

    Py_XDECREF(var_conv3);
    var_conv3 = NULL;

    Py_XDECREF(var_conv4);
    var_conv4 = NULL;

    Py_XDECREF(var_flatten);
    var_flatten = NULL;

    Py_XDECREF(var_fc1);
    var_fc1 = NULL;

    Py_XDECREF(var_fc2);
    var_fc2 = NULL;

    Py_XDECREF(var_out);
    var_out = NULL;

    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    // End of try:

    NUITKA_CANNOT_GET_HERE("Return statement must have exited already.");
    return NULL;

function_exception_exit:
    assert(exception_type);
    RESTORE_ERROR_OCCURRED(exception_type, exception_value, exception_tb);

    return NULL;

function_return_exit:
   // Function cleanup code if any.


   // Actual function exit with return value, making sure we did not make
   // the error status worse despite non-NULL return.
   CHECK_OBJECT(tmp_return_value);
   assert(had_error || !ERROR_OCCURRED());
   return tmp_return_value;
}



static PyObject *MAKE_FUNCTION_cnn$$$function_1_cnn_model() {
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_cnn$$$function_1_cnn_model,
        const_str_plain_cnn_model,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_13d7a984ecc78250017a622ad0b20003,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_cnn,
        NULL,
        0
    );

    return (PyObject *)result;
}


extern PyObject *const_str_plain___compiled__;

extern PyObject *const_str_plain___package__;
extern PyObject *const_str_empty;

#if PYTHON_VERSION >= 300
extern PyObject *const_str_dot;
extern PyObject *const_str_plain___loader__;
#endif

#if PYTHON_VERSION >= 340
extern PyObject *const_str_plain___spec__;
extern PyObject *const_str_plain__initializing;
extern PyObject *const_str_plain_submodule_search_locations;
#endif

extern void _initCompiledCellType();
extern void _initCompiledGeneratorType();
extern void _initCompiledFunctionType();
extern void _initCompiledMethodType();
extern void _initCompiledFrameType();

extern PyTypeObject Nuitka_Loader_Type;

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
// Provide a way to create find a function via its C code and create it back
// in another process, useful for multiprocessing extensions like dill

function_impl_code functable_cnn[] = {
    impl_cnn$$$function_1_cnn_model,
    NULL
};

static char const *_reduce_compiled_function_argnames[] = {
    "func",
    NULL
};

static PyObject *_reduce_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    PyObject *func;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:reduce_compiled_function", (char **)_reduce_compiled_function_argnames, &func, NULL)) {
        return NULL;
    }

    if (Nuitka_Function_Check(func) == false) {
        SET_CURRENT_EXCEPTION_TYPE0_STR(PyExc_TypeError, "not a compiled function");
        return NULL;
    }

    struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)func;

    function_impl_code *current = functable_cnn;
    int offset = 0;

    while (*current != NULL) {
        if (*current == function->m_c_code) {
            break;
        }

        current += 1;
        offset += 1;
    }

    if (*current == NULL) {
        SET_CURRENT_EXCEPTION_TYPE0_STR(PyExc_TypeError, "Cannot find compiled function in module.");
        return NULL;
    }

    PyObject *code_object_desc = PyTuple_New(6);
    PyTuple_SET_ITEM0(code_object_desc, 0, function->m_code_object->co_filename);
    PyTuple_SET_ITEM0(code_object_desc, 1, function->m_code_object->co_name);
    PyTuple_SET_ITEM(code_object_desc, 2, PyLong_FromLong(function->m_code_object->co_firstlineno));
    PyTuple_SET_ITEM0(code_object_desc, 3, function->m_code_object->co_varnames);
    PyTuple_SET_ITEM(code_object_desc, 4, PyLong_FromLong(function->m_code_object->co_argcount));
    PyTuple_SET_ITEM(code_object_desc, 5, PyLong_FromLong(function->m_code_object->co_flags));

    CHECK_OBJECT_DEEP(code_object_desc);

    PyObject *result = PyTuple_New(4);
    PyTuple_SET_ITEM(result, 0, PyLong_FromLong(offset));
    PyTuple_SET_ITEM(result, 1, code_object_desc);
    PyTuple_SET_ITEM0(result, 2, function->m_defaults);
    PyTuple_SET_ITEM0(result, 3, function->m_doc != NULL ? function->m_doc : Py_None);

    CHECK_OBJECT_DEEP(result);

    return result;
}

static PyMethodDef _method_def_reduce_compiled_function = {"reduce_compiled_function", (PyCFunction)_reduce_compiled_function,
                                                           METH_VARARGS | METH_KEYWORDS, NULL};

static char const *_create_compiled_function_argnames[] = {
    "func",
    "code_object_desc",
    "defaults",
    "doc",
    NULL
};


static PyObject *_create_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    CHECK_OBJECT_DEEP(args);

    PyObject *func;
    PyObject *code_object_desc;
    PyObject *defaults;
    PyObject *doc;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "OOOO:create_compiled_function", (char **)_create_compiled_function_argnames, &func, &code_object_desc, &defaults, &doc, NULL)) {
        return NULL;
    }

    int offset = PyLong_AsLong(func);

    if (offset == -1 && ERROR_OCCURRED()) {
        return NULL;
    }

    if (offset > sizeof(functable_cnn) || offset < 0) {
        SET_CURRENT_EXCEPTION_TYPE0_STR(PyExc_TypeError, "Wrong offset for compiled function.");
        return NULL;
    }

    PyObject *filename = PyTuple_GET_ITEM(code_object_desc, 0);
    PyObject *function_name = PyTuple_GET_ITEM(code_object_desc, 1);
    PyObject *line = PyTuple_GET_ITEM(code_object_desc, 2);
    int line_int = PyLong_AsLong(line);
    assert(!ERROR_OCCURRED());

    PyObject *argnames = PyTuple_GET_ITEM(code_object_desc, 3);
    PyObject *arg_count = PyTuple_GET_ITEM(code_object_desc, 4);
    int arg_count_int = PyLong_AsLong(arg_count);
    assert(!ERROR_OCCURRED());
    PyObject *flags = PyTuple_GET_ITEM(code_object_desc, 5);
    int flags_int = PyLong_AsLong(flags);
    assert(!ERROR_OCCURRED());

    PyCodeObject *code_object = MAKE_CODEOBJECT(
        filename,
        line_int,
        flags_int,
        function_name,
        argnames,
        arg_count_int,
        0, // TODO: Missing kw_only_count
        0 // TODO: Missing pos_only_count
    );

    // TODO: More stuff needed for Python3, best to re-order arguments of MAKE_CODEOBJECT.
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        functable_cnn[offset],
        code_object->co_name,
#if PYTHON_VERSION >= 300
        NULL, // TODO: Not transferring qualname yet
#endif
        code_object,
        defaults,
#if PYTHON_VERSION >= 300
        NULL, // kwdefaults are done on the outside currently
        NULL, // TODO: Not transferring annotations
#endif
        module_cnn,
        doc,
        0
    );

    return (PyObject *)result;
}

static PyMethodDef _method_def_create_compiled_function = {
    "create_compiled_function",
    (PyCFunction)_create_compiled_function,
    METH_VARARGS | METH_KEYWORDS, NULL
};


#endif

// Internal entry point for module code.
PyObject *modulecode_cnn(PyObject *module) {
    module_cnn = module;

#if defined(_NUITKA_EXE) || PYTHON_VERSION >= 300
    static bool _init_done = false;

    // Modules might be imported repeatedly, which is to be ignored.
    if (_init_done) {
        return module_cnn;
    } else {
        _init_done = true;
    }
#endif

#ifdef _NUITKA_MODULE
    // In case of a stand alone extension module, need to call initialization
    // the init here because that's the first and only time we are going to get
    // called here.

    // May have to activate constants blob.
#if defined(_NUITKA_CONSTANTS_FROM_RESOURCE)
    loadConstantsResource();
#endif

    // Initialize the constant values used.
    _initBuiltinModule();
    createGlobalConstants();

    /* Initialize the compiled types of Nuitka. */
    _initCompiledCellType();
    _initCompiledGeneratorType();
    _initCompiledFunctionType();
    _initCompiledMethodType();
    _initCompiledFrameType();

#if PYTHON_VERSION < 300
    _initSlotCompare();
#endif
#if PYTHON_VERSION >= 270
    _initSlotIternext();
#endif

    patchBuiltinModule();
    patchTypeComparison();

    // Enable meta path based loader if not already done.
#ifdef _NUITKA_TRACE
    PRINT_STRING("cnn: Calling setupMetaPathBasedLoader().\n");
#endif
    setupMetaPathBasedLoader();

#if PYTHON_VERSION >= 300
    patchInspectModule();
#endif

#endif

    /* The constants only used by this module are created now. */
#ifdef _NUITKA_TRACE
    PRINT_STRING("cnn: Calling createModuleConstants().\n");
#endif
    createModuleConstants();

    /* The code objects used by this module are created now. */
#ifdef _NUITKA_TRACE
    PRINT_STRING("cnn: Calling createModuleCodeObjects().\n");
#endif
    createModuleCodeObjects();

    // PRINT_STRING("in initcnn\n");

    // Create the module object first. There are no methods initially, all are
    // added dynamically in actual code only.  Also no "__doc__" is initially
    // set at this time, as it could not contain NUL characters this way, they
    // are instead set in early module code.  No "self" for modules, we have no
    // use for it.

    moduledict_cnn = MODULE_DICT(module_cnn);

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
    {
        PyObject *function_tables = PyObject_GetAttrString((PyObject *)builtin_module, "compiled_function_tables");
        if (function_tables == NULL)
        {
            DROP_ERROR_OCCURRED();
            function_tables = PyDict_New();
        }
        PyObject_SetAttrString((PyObject *)builtin_module, "compiled_function_tables", function_tables);
        PyObject *funcs = PyTuple_New(2);
        PyTuple_SET_ITEM(funcs, 0, PyCFunction_New(&_method_def_reduce_compiled_function, NULL));
        PyTuple_SET_ITEM(funcs, 1, PyCFunction_New(&_method_def_create_compiled_function, NULL));
        PyDict_SetItemString(function_tables, module_full_name, funcs);
    }
#endif

    // Set "__compiled__" to what version information we have.
    UPDATE_STRING_DICT0(
        moduledict_cnn,
        (Nuitka_StringObject *)const_str_plain___compiled__,
        Nuitka_dunder_compiled_value
    );

    // Update "__package__" value to what it ought to be.
    {
#if 0
        UPDATE_STRING_DICT0(
            moduledict_cnn,
            (Nuitka_StringObject *)const_str_plain___package__,
            const_str_empty
        );
#elif 0
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___name__);

        UPDATE_STRING_DICT0(
            moduledict_cnn,
            (Nuitka_StringObject *)const_str_plain___package__,
            module_name
        );
#else

#if PYTHON_VERSION < 300
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___name__);
        char const *module_name_cstr = PyString_AS_STRING(module_name);

        char const *last_dot = strrchr(module_name_cstr, '.');

        if (last_dot != NULL)
        {
            UPDATE_STRING_DICT1(
                moduledict_cnn,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyString_FromStringAndSize(module_name_cstr, last_dot - module_name_cstr)
            );
        }
#else
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___name__);
        Py_ssize_t dot_index = PyUnicode_Find(module_name, const_str_dot, 0, PyUnicode_GetLength(module_name), -1);

        if (dot_index != -1)
        {
            UPDATE_STRING_DICT1(
                moduledict_cnn,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyUnicode_Substring(module_name, 0, dot_index)
            );
        }
#endif
#endif
    }

    CHECK_OBJECT(module_cnn);

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    if (GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___builtins__) == NULL)
    {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then but the module itself.
#if !defined(_NUITKA_EXE) || !0
        value = PyModule_GetDict(value);
#endif

        UPDATE_STRING_DICT0(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___builtins__, value);
    }

#if PYTHON_VERSION >= 300
    UPDATE_STRING_DICT0(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___loader__, (PyObject *)&Nuitka_Loader_Type);
#endif

#if PYTHON_VERSION >= 340
// Set the "__spec__" value

#if 0
    // Main modules just get "None" as spec.
    UPDATE_STRING_DICT0(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___spec__, Py_None);
#else
    // Other modules get a "ModuleSpec" from the standard mechanism.
    {
        PyObject *bootstrap_module = PyImport_ImportModule("importlib._bootstrap");
        CHECK_OBJECT(bootstrap_module);
        PyObject *module_spec_class = PyObject_GetAttrString(bootstrap_module, "ModuleSpec");
        Py_DECREF(bootstrap_module);

        PyObject *args[] = {
            GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___name__),
            (PyObject *)&Nuitka_Loader_Type
        };

        PyObject *spec_value = CALL_FUNCTION_WITH_ARGS2(
            module_spec_class,
            args
        );
        Py_DECREF(module_spec_class);

        // We can assume this to never fail, or else we are in trouble anyway.
        CHECK_OBJECT(spec_value);

// For packages set the submodule search locations as well, even if to empty
// list, so investigating code will consider it a package.
#if 0
        SET_ATTRIBUTE(spec_value, const_str_plain_submodule_search_locations, PyList_New(0));
#endif

// Mark the execution in the "__spec__" value.
        SET_ATTRIBUTE(spec_value, const_str_plain__initializing, Py_True);

        UPDATE_STRING_DICT1(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___spec__, spec_value);
    }
#endif
#endif

    // Temp variables if any
    struct Nuitka_FrameObject *frame_2881f1a9b6a3f6265a1cd055d9c6d020;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    bool tmp_result;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;

    // Module code.
    {
        PyObject *tmp_assign_source_1;
        tmp_assign_source_1 = Py_None;
        UPDATE_STRING_DICT0(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___doc__, tmp_assign_source_1);
    }
    {
        PyObject *tmp_assign_source_2;
        tmp_assign_source_2 = module_filename_obj;
        UPDATE_STRING_DICT0(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___file__, tmp_assign_source_2);
    }
    // Frame without reuse.
    frame_2881f1a9b6a3f6265a1cd055d9c6d020 = MAKE_MODULE_FRAME(codeobj_2881f1a9b6a3f6265a1cd055d9c6d020, module_cnn);

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStack(frame_2881f1a9b6a3f6265a1cd055d9c6d020);
    assert(Py_REFCNT(frame_2881f1a9b6a3f6265a1cd055d9c6d020) == 2);

    // Framed code:
    {
        PyObject *tmp_assattr_name_1;
        PyObject *tmp_assattr_target_1;
        PyObject *tmp_mvar_value_1;
        tmp_assattr_name_1 = module_filename_obj;
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___spec__);

        if (unlikely(tmp_mvar_value_1 == NULL)) {
            tmp_mvar_value_1 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain___spec__);
        }

        CHECK_OBJECT(tmp_mvar_value_1);
        tmp_assattr_target_1 = tmp_mvar_value_1;
        tmp_result = SET_ATTRIBUTE(tmp_assattr_target_1, const_str_plain_origin, tmp_assattr_name_1);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assattr_name_2;
        PyObject *tmp_assattr_target_2;
        PyObject *tmp_mvar_value_2;
        tmp_assattr_name_2 = Py_True;
        tmp_mvar_value_2 = GET_STRING_DICT_VALUE(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___spec__);

        if (unlikely(tmp_mvar_value_2 == NULL)) {
            tmp_mvar_value_2 = GET_STRING_DICT_VALUE(dict_builtin, (Nuitka_StringObject *)const_str_plain___spec__);
        }

        CHECK_OBJECT(tmp_mvar_value_2);
        tmp_assattr_target_2 = tmp_mvar_value_2;
        tmp_result = SET_ATTRIBUTE(tmp_assattr_target_2, const_str_plain_has_location, tmp_assattr_name_2);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assign_source_3;
        tmp_assign_source_3 = Py_None;
        UPDATE_STRING_DICT0(moduledict_cnn, (Nuitka_StringObject *)const_str_plain___cached__, tmp_assign_source_3);
    }
    {
        PyObject *tmp_assign_source_4;
        PyObject *tmp_name_name_1;
        PyObject *tmp_globals_name_1;
        PyObject *tmp_locals_name_1;
        PyObject *tmp_fromlist_name_1;
        PyObject *tmp_level_name_1;
        tmp_name_name_1 = const_str_plain_tensorflow;
        tmp_globals_name_1 = (PyObject *)moduledict_cnn;
        tmp_locals_name_1 = Py_None;
        tmp_fromlist_name_1 = Py_None;
        tmp_level_name_1 = const_int_0;
        frame_2881f1a9b6a3f6265a1cd055d9c6d020->m_frame.f_lineno = 1;
        tmp_assign_source_4 = IMPORT_MODULE5(tmp_name_name_1, tmp_globals_name_1, tmp_locals_name_1, tmp_fromlist_name_1, tmp_level_name_1);
        if (tmp_assign_source_4 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_tf, tmp_assign_source_4);
    }
    {
        PyObject *tmp_assign_source_5;
        PyObject *tmp_name_name_2;
        PyObject *tmp_globals_name_2;
        PyObject *tmp_locals_name_2;
        PyObject *tmp_fromlist_name_2;
        PyObject *tmp_level_name_2;
        tmp_name_name_2 = const_str_plain_numpy;
        tmp_globals_name_2 = (PyObject *)moduledict_cnn;
        tmp_locals_name_2 = Py_None;
        tmp_fromlist_name_2 = Py_None;
        tmp_level_name_2 = const_int_0;
        frame_2881f1a9b6a3f6265a1cd055d9c6d020->m_frame.f_lineno = 2;
        tmp_assign_source_5 = IMPORT_MODULE5(tmp_name_name_2, tmp_globals_name_2, tmp_locals_name_2, tmp_fromlist_name_2, tmp_level_name_2);
        if (tmp_assign_source_5 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 2;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_np, tmp_assign_source_5);
    }

    // Restore frame exception if necessary.
#if 0
    RESTORE_FRAME_EXCEPTION(frame_2881f1a9b6a3f6265a1cd055d9c6d020);
#endif
    popFrameStack();

    assertFrameObject(frame_2881f1a9b6a3f6265a1cd055d9c6d020);

    goto frame_no_exception_1;

    frame_exception_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION(frame_2881f1a9b6a3f6265a1cd055d9c6d020);
#endif

    if (exception_tb == NULL) {
        exception_tb = MAKE_TRACEBACK(frame_2881f1a9b6a3f6265a1cd055d9c6d020, exception_lineno);
    } else if (exception_tb->tb_frame != &frame_2881f1a9b6a3f6265a1cd055d9c6d020->m_frame) {
        exception_tb = ADD_TRACEBACK(exception_tb, frame_2881f1a9b6a3f6265a1cd055d9c6d020, exception_lineno);
    }

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto module_exception_exit;

    frame_no_exception_1:;
    {
        PyObject *tmp_assign_source_6;
        tmp_assign_source_6 = MAKE_FUNCTION_cnn$$$function_1_cnn_model();



        UPDATE_STRING_DICT1(moduledict_cnn, (Nuitka_StringObject *)const_str_plain_cnn_model, tmp_assign_source_6);
    }

    return module_cnn;
    module_exception_exit:
    RESTORE_ERROR_OCCURRED(exception_type, exception_value, exception_tb);
    return NULL;
}


/* Visibility definitions to make the DLL entry point exported */
#if defined(__GNUC__)

#if PYTHON_VERSION < 300
#define NUITKA_MODULE_INIT_FUNCTION PyMODINIT_FUNC __attribute__((visibility("default")))

#else

#ifdef __cplusplus
#define NUITKA_MODULE_INIT_FUNCTION extern "C" __attribute__((visibility("default"))) PyObject *
#else
#define NUITKA_MODULE_INIT_FUNCTION __attribute__((visibility("default"))) PyObject *
#endif

#endif

#else
#define NUITKA_MODULE_INIT_FUNCTION PyMODINIT_FUNC
#endif

/* The name of the entry point for DLLs changed between CPython versions, and
 * this is here to hide that.
 */
#if PYTHON_VERSION < 300
#define MOD_INIT_DECL(name) NUITKA_MODULE_INIT_FUNCTION init##name(void)
#else
#define MOD_INIT_DECL(name) NUITKA_MODULE_INIT_FUNCTION PyInit_##name(void)
#endif

#if PYTHON_VERSION >= 300
static struct PyModuleDef mdef_cnn = {
    PyModuleDef_HEAD_INIT,
    NULL,                /* m_name, filled later */
    NULL,                /* m_doc */
    -1,                  /* m_size */
    NULL,                /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
};

#endif

/* The exported interface to CPython. On import of the module, this function
 * gets called. It has to have an exact function name, in cases it's a shared
 * library export. This is hidden behind the MOD_INIT_DECL macro.
 */
MOD_INIT_DECL(cnn) {
    char const *module_full_name = "cnn";
    if (_Py_PackageContext != NULL) {
        module_full_name = _Py_PackageContext;
    }

#if PYTHON_VERSION < 300
    PyObject *module = Py_InitModule4(
        module_full_name,        // Module Name
        NULL,                    // No methods initially, all are added
                                 // dynamically in actual module code only.
        NULL,                    // No "__doc__" is initially set, as it could
                                 // not contain NUL this way, added early in
                                 // actual code.
        NULL,                    // No self for modules, we don't use it.
        PYTHON_API_VERSION
    );
#else
    mdef_cnn.m_name = module_full_name;
    PyObject *module = PyModule_Create(&mdef_cnn);
    CHECK_OBJECT(module);

    PyObject *module_name = PyUnicode_FromString(module_full_name);
    int res = PyDict_SetItem(PyImport_GetModuleDict(), module_name, module);
    assert(res != -1);
#endif

#if PYTHON_VERSION < 300
    modulecode_cnn(module);
#else
    PyObject *result = modulecode_cnn(module);
    return result;
#endif
}
