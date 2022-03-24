//
// Created by Jiwon_Hae on 2022/03/01.
//
#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <android/log.h>
#include <vector>
#include "jni.h"
#include "jni_base/jni_class.hpp"
#include "jni_base/jni_array.hpp"

// xadapt is required to print shapes
#include <xtensor/xadapt.hpp>
#include <jni.h>
#include <string>

using namespace xt;
using namespace std;

#define LOG_TAG "jni_xtensor"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG , LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO , LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN , LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR , LOG_TAG, __VA_ARGS__)

#define ASSERT(status, ret)     if (!(status)) { return ret; }
#define ASSERT_FALSE(status)    ASSERT(status, false)

extern "C"
JNIEXPORT void JNICALL
Java_com_jiwon_xtensor_1jni_XTensor_asarray___3D_3I(JNIEnv *env, jobject thiz,
                                                    jdoubleArray jarray,
                                                    jintArray jshape) {
    // get length of the native array
    int len = env->GetArrayLength(jarray);
    vector<double> array(len);
    base::JniDoubleArrayToVector(env, jarray, &array);

    // get num dimension of the shape
    int numDimension = env->GetArrayLength(jshape);
    vector<int> shape(numDimension);
    base::JniIntArrayToVector(env, jshape, &shape);

    // warp vector in to xarray
    xarray<double> xarray = xt::adapt(array, shape);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jiwon_xtensor_1jni_XTensor_asarray___3J_3I(JNIEnv *env, jobject thiz,
                                                    jlongArray jarray,
                                                    jintArray jshape) {
    // get length of the native array
    int len = env->GetArrayLength(jarray);
    vector<long> array(len);
    base::JniLongArrayToVector(env, jarray, &array);

    // get num dimension of the shape
    int numDimension = env->GetArrayLength(jshape);
    vector<int> shape(numDimension);
    base::JniIntArrayToVector(env, jshape, &shape);

    // warp vector in to xarray
    xarray<long> xarray = xt::adapt(array, shape);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jiwon_xtensor_1jni_XTensor_asarray___3F_3I(JNIEnv *env, jobject thiz,
                                                    jfloatArray jarray,
                                                    jintArray jshape) {
    // get length of the native array
    int len = env->GetArrayLength(jarray);
    vector<float> array(len);
    base::JniFloatArrayToVector(env, jarray, &array);

    // get num dimension of the shape
    int numDimension = env->GetArrayLength(jshape);
    vector<int> shape(numDimension);
    base::JniIntArrayToVector(env, jshape, &shape);

    // warp vector in to xarray
    xarray<float> xarray = xt::adapt(array, shape);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jiwon_xtensor_1jni_XTensor_asarray___3I_3I(JNIEnv *env, jobject thiz,
                                                    jintArray jarray,
                                                    jintArray jshape) {
    // get length of the native array
    int len = env->GetArrayLength(jarray);
    vector<int> array(len);
    base::JniIntArrayToVector(env, jarray, &array);

    // get num dimension of the shape
    int numDimension = env->GetArrayLength(jshape);
    vector<int> shape(numDimension);
    base::JniIntArrayToVector(env, jshape, &shape);

    // warp vector in to xarray
    xarray<int> xarray = xt::adapt(array, shape);
}