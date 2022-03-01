package com.jiwon.androidxtensor

import org.junit.Test

class XTensorPracticeTest{
    @Test
    fun runTest(){
        XTensor.runPractice()
    }

    @Test
    fun runArrayCreation(){
        XTensor.createArr(
            (0..1000).map{ it.toFloat() }.toFloatArray(),
            intArrayOf(1, 1000)
        )
    }
}