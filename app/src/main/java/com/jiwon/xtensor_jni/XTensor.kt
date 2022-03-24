package com.jiwon.xtensor_jni

typealias xt  = XTensor

object XTensor {
    external fun asarray(arr: FloatArray, shape : IntArray)

    external fun asarray(arr: IntArray, shape : IntArray)

    external fun asarray(arr: LongArray, shape : IntArray)

    external fun asarray(arr: DoubleArray, shape : IntArray)

    init{
        System.loadLibrary("jni_xtensor")
    }
}