//
// Created by Jiwon_Hae on 2022/03/24.
//


#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <android/log.h>
#include <vector>
#include "jni.h"

namespace base {
    void JniFloatArrayToVector(JNIEnv *env, jfloatArray arr, std::vector<float> *out){
        int len = env->GetArrayLength(arr);
        if(!len)
            return;
        env->GetFloatArrayRegion(arr, 0, len, out->data());
    }

    void JniIntArrayToVector(JNIEnv *env, jintArray arr, std::vector<int> *out){
        int len = env->GetArrayLength(arr);
        if(!len)
            return;
        env->GetIntArrayRegion(arr, 0, len, out->data());
    }


    void JniDoubleArrayToVector(JNIEnv *env, jdoubleArray arr, std::vector<double> *out){
        int len = env->GetArrayLength(arr);
        if(!len)
            return;
        env->GetDoubleArrayRegion(arr, 0, len, out->data());
    }


    void JniLongArrayToVector(JNIEnv *env, jlongArray arr, std::vector<long> *out){
        int len = env->GetArrayLength(arr);
        if(!len)
            return;
        env->GetLongArrayRegion(arr, 0, len, out->data());
    }
}
