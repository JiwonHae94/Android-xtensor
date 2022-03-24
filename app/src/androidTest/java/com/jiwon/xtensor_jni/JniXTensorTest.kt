package com.jiwon.xtensor_jni

import org.junit.Test

class JniXTensorTest{
    @Test
    fun testXtensorArrCreation(){
        // multi-dimensional array with shape
        val shape = intArrayOf(1, 2, 3, 4)
        val arr = IntArray(shape[0] * shape[1] * shape[2] * shape[3]){ i -> i }

        xt.asarray(arr.toTypedArray(), shape)
    }
}