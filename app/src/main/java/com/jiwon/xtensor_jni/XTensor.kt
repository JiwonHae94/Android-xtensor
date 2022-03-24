package com.jiwon.xtensor_jni

typealias xt  = XTensor

object XTensor {
    external fun <T> asarray(arr: Array<T>, shape : IntArray)

    init{
        System.loadLibrary("jni_xtensor")
    }
}