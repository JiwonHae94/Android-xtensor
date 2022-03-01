package com.jiwon.androidxtensor

typealias xt  = XTensor

object XTensor {
    external fun <T> asarray(arr: Array<T>, shape : IntArray) : Any

    external fun arrayCreation(floatArray: FloatArray, shape : IntArray)

    external fun runPractice()

    external fun createArr(arr : FloatArray, shape : IntArray)

    init{
        System.loadLibrary("xtensor-lib")
    }
}