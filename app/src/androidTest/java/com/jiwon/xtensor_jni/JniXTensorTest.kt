package com.jiwon.xtensor_jni

import org.junit.Test

class JniXTensorTest{
    @Test
    fun testXTensorIntArray(){
        // multi-dimensional array with shape
        val shape = intArrayOf(1, 2, 3, 4)
        val arr = IntArray(shape[0] * shape[1] * shape[2] * shape[3]){ i -> i }
        xt.asarray(arr, shape)
    }

    @Test
    fun testXTensorFloatArray(){
        // multi-dimensional array with shape
        val shape = intArrayOf(1, 2, 3, 4)
        val arr = FloatArray(shape[0] * shape[1] * shape[2] * shape[3]){ i -> i.toFloat() }
        xt.asarray(arr, shape)
    }

    @Test
    fun testXTensorDoubleArray(){
        // multi-dimensional array with shape
        val shape = intArrayOf(1, 2, 3, 4)
        val arr = DoubleArray(shape[0] * shape[1] * shape[2] * shape[3]){ i -> i.toDouble() }
        xt.asarray(arr, shape)
    }

    @Test
    fun testXTensorLongArray(){
        // multi-dimensional array with shape
        val shape = intArrayOf(1, 2, 3, 4)
        val arr = LongArray(shape[0] * shape[1] * shape[2] * shape[3]){ i -> i.toLong() }
        xt.asarray(arr, shape)
    }
}