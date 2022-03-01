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

// xadapt is required to print shapes
#include <xtensor/xadapt.hpp>
#include <jni.h>

using namespace xt;
using namespace std;

#define LOG_TAG "xtensor_jni"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG , LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO , LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN , LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR , LOG_TAG, __VA_ARGS__)

int xtensorAddition(){
    xarray<double> arr1
            {{1.0, 2.0, 3.0},
             {2.0, 5.0, 7.0},
             {2.0, 5.0, 7.0}};

    xarray<double> arr2{5.0, 6.0, 7.0};
    xarray<double> res = view(arr1, 1) + arr2;

    printf("XTensorTest Addition");
    cout << res << endl;;
    return 0;
}

int xtensorReshape(){
    xarray<int> arr{1, 2, 3, 4, 5 ,6, 7, 8, 9};
    arr.reshape({3,3});

    auto shapeTxt = xt::adapt(arr.shape());
    return 0;
}

void xtensorBroadCast(){
    xt::xarray<double> arr1
            {1.0, 2.0, 3.0};

    xt::xarray<unsigned int> arr2
            {4, 5, 6, 7};

    arr2.reshape({4, 1});
    xt::xarray<double> res = xt::pow(arr1, arr2);

    std::cout << res;
}

void arrayAccess(xarray<int>& arr, int pos){
    LOGD("XTensorArr %d", arr(pos));
}

void lazyEvaluation(){
    xt::xarray<double> a = {1, 2, 3};
    xt::xarray<double> b = {3, 2, 1};
    auto calc = a + b; // unevaluated xexpression!
    auto&& e = xt::eval(calc); // a rvalue container xarray!
// this just returns a reference to the existing container
    auto&& a_ref = xt::eval(a);
}

void shape(){
    using array_type = xt::xarray<double>;
    using shape_type = array_type::shape_type;

    shape_type shape = {3, 2, 4};
    array_type a(shape);
    size_t d = a.dimension();
    const shape_type& s = a.shape();
    bool res = (d == shape.size()) && (s == shape);

    LOGD("XTensor shape size %d", res);

    LOGD("XTensor shape size %zu ", d);
}

void arrAccess(){
    xt::xarray<double> a = {{{1., 2., 3.}}};
    std::vector<size_t> index = {1, 1, 1};
    double v1 = a(1, 1, 1);
    double v2 = a[index];
    double v3 = a.element(index.begin(), index.end());

    LOGD("XTensor arr access1 %Lf", v1);
    LOGD("XTensor arr access2 %Lf", v2);
    LOGD("XTensor arr access3 %Lf", v3);

    vector<size_t>::iterator ptr;
    for (ptr = index.begin(); ptr < index.end(); ptr++)
        cout << *ptr << " ";
        LOGD("XTensor arr %zu", ptr);
}

auto placeHolders(){
    using namespace xt::placeholders;  // required for `_` to work
    xarray<float> a = arange(0, 100, 1);
    auto v1 = view(a, range(50, _));

    for(int i = 0; i < v1.size(); i++){
        LOGD("XTensor v1 %f", v1(i));
    }
}

void transpose(){
    using array_type = xt::xarray<double>;
    using shape_type = array_type::shape_type;

    shape_type shape = {3, 2, 4};
    array_type a(shape);

    transpose(a, {1, 0, 2});
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jiwon_androidxtensor_XTensor_runPractice(JNIEnv *env, jobject thiz) {
//    xarray<int> arr{ 1, 2, 3, 4, 5 ,6, 7, 8, 9};
//
//    xtensorAddition();
//    xtensorReshape();
//
//    for(int i = 0; i< arr.size(); i++){
//        arrayAccess(arr, i);
//    }
//    xtensorBroadCast();

    shape();
    arrAccess();

    placeHolders();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jiwon_androidxtensor_XTensor_arrayCreation(JNIEnv *env, jobject thiz,
                                                    jfloatArray float_array,
                                                    jintArray shape) {

    int arrShape = env->GetArrayLength(shape);

}
extern "C"
JNIEXPORT jobject JNICALL
Java_com_jiwon_androidxtensor_XTensor_asarray(JNIEnv *env, jobject thiz, jobjectArray array,
                                              jintArray shape) {
    jclass arrClass = env->GetObjectClass(array);

    return NULL;
}

void JavaFloatArrayToFloatVector(JNIEnv *env, jfloatArray arr, vector<float> *out){
    int len = env->GetArrayLength(arr);
    if(!len)
        return;
    env->GetFloatArrayRegion(arr, 0, len, out->data());
}

void JavaIntArrayToIntVector(JNIEnv *env, jintArray arr, vector<int> *out){
    int len = env->GetArrayLength(arr);
    if(!len)
        return;
    env->GetIntArrayRegion(arr, 0, len, out->data());
}

vector<size_t> ToNativeShape(JNIEnv *env, jintArray shapes){
    int arrSize = env->GetArrayLength(shapes);
    vector<size_t> out(arrSize);
    jint *body = env->GetIntArrayElements(shapes, JNI_FALSE);

    for(int i = 0; i< arrSize; i++){
        int value = body[i];
        out[i] = value;
    }

    env->ReleaseIntArrayElements(shapes, body, 0);
    return out;
}


template <class A>
void jobjectArrayToXtensor(JNIEnv *env, jfloatArray arr, jintArray shape, A& a){
    int arrSize = env->GetArrayLength(arr);
    int shapeDim = env->GetArrayLength(shape);

    // get arr size
    vector<float> out(arrSize);
    JavaFloatArrayToFloatVector(env, arr, &out);

    // get arr dimension
    vector<int> shapeOut(shapeDim);
    JavaIntArrayToIntVector(env, shape, &shapeOut);

    a = adapt(out, shapeOut);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jiwon_androidxtensor_XTensor_createArr(JNIEnv *env,
                                                jobject thiz,
                                                jfloatArray arr,
                                                jintArray shape) {

    // find the dimension of the arr, len = Dimension
    xarray<float> result;
    jobjectArrayToXtensor(env, arr, shape, result);

    for(int i = 0; i < 1; i++){
        for(int j = 0 ; j < 1000; j++){
            LOGD("result %lf", result(i, j));
        }
    }
}

