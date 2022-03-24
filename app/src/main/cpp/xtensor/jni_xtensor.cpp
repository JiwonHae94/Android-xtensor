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

namespace jni_xt {
    template <class T>
    xt::xarray<T> asarray(vector<T> arr, vector<int> shape){
        return xt::adapt(arr, shape);
    }
}



void JavaArrayToVector(JNIEnv *env, jobjectArray arr, jintArray shape){
    int len = env->GetArrayLength(arr);
    jclass arrClass = env->GetObjectClass(env->GetObjectArrayElement(arr, 0));
    std::string clz = JClass::getClassName(env, arrClass);

    if(strcmp(clz.c_str(), typeid(int).name()) == 0){
        LOGD("int class");
    }

    if(strcmp(clz.c_str(), typeid(double).name()) == 0){
        LOGD("double class");
    }

    if(strcmp(clz.c_str(), typeid(float).name()) == 0){
        LOGD("float class");
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jiwon_xtensor_1jni_XTensor_asarray(JNIEnv *env, jobject thiz, jobjectArray arr,
                                            jintArray shape) {
    // convert jniArray to c++ vector
    JavaArrayToVector(env, arr, shape);
    return;
}