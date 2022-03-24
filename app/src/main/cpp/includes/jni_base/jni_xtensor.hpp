//
// Created by Jiwon_Hae on 2022/03/24.
//
#ifndef XTENSOR_JNIBASE_XTENSOR
#define XTENSOR_JNIBASE_XTENSOR

#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <xtensor/xadapt.hpp>
#include <android/log.h>
#include <vector>
#include "jni.h"
#include "jni_array.hpp"

using namespace std;
using namespace xt;

namespace j_xtensor {
    xt::xarray<double> asarray(JNIEnv *env, jdoubleArray jarray, jintArray jshape) {
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
        return xarray;
    }

    xt::xarray<long> asarray(JNIEnv *env, jlongArray jarray, jintArray jshape) {
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
        return xarray;
    }

    xt::xarray<float> asarray(JNIEnv *env, jfloatArray jarray, jintArray jshape) {
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
        return xarray;
    }


    xt::xarray<int> asarray(JNIEnv *env, jintArray jarray, jintArray jshape) {
        // get length of the native array
        int len = env->GetArrayLength(jarray);
        vector<int> array(len);
        base::JniIntArrayToVector(env, jarray, &array);

        // get num dimension of the shape
        int numDimension = env->GetArrayLength(jshape);
        vector<int> shape(numDimension);
        base::JniIntArrayToVector(env, jshape, &shape);

        // warp vector in to xarray
        xt::xarray<int> xarray = xt::adapt(array, shape);
        return xarray;
    }
}
#endif