# XTensor in Android
## <div align="left">Getting Started</div>
[`xtensor`](https://xtensor.readthedocs.io/en/latest/) is a C++ library meant for numerical analysis with multi-dimensional array expressions.

`xtensor` provides 
* an extensible expression system enabling __lazy broadcasting__.
* an API following the idioms of the __C++ standard library__.
* tools to manipulate array expressions and build upon _xtensor.

Containers of xtensor are inspired by NumPy, the Python array programming library. Adaptors for existing data structures to be plugged into the expression system can easily be written.

Credits : [to all xtensor developers](https://github.com/xtensor-stack/xtensor)

This project exemplifies the use of xtensor in Android.

## <div align="left">Why XTensor</div>
With increasing demand for on-device ML, need for multi-array/matrix operations grew significantly. However, support for such operation is not quite up to the expections.
Some of the similar works are :
- [multik](https://github.com/Kotlin/multik)
- [numpy-kotlin](https://github.com/Kotlin/kotlin-numpy) [_`android not supported`_](https://github.com/Kotlin/kotlin-numpy/issues/11#issuecomment-751669356))

## <div align="left">Usage</div>
### Prerequisites
* xtensor
* Android Studio
* C++14

[`Download xtensor package following the guideline`](https://github.com/xtensor-stack/xtensor)

### Setup
- **include xtensor package in the CMakeList.txt**
```txt
include_directories( ${xtensor_dir_path} )
```

### Basic Use
- **convert native arrays into xarray**
```c++
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
```

[**implement desired operations**](https://xtensor.readthedocs.io/en/latest/)

- **some of commonly used operations**
```c++
void xarray_arithmetic(
    xt::xarray<float> arr1, 
    xt::xarray<float> arr2
) {
    arr1 + arr2;
    arr1 - arr2;
    arr1 * arr2;
    arr1 / arr2;
}
```

```c++
#include <xtensor/xsort.hpp>

void sort(xt::xarray<float> xarray, int axis) {
    return xt::sort(xarray, axis);
}
```

```c++
void tranpose(
    xt::xarray<float> xarray, 
    xt::vector<size_t> permutation
) {
    xt::transpose(xarray, permutation);
}
```


```c++
void softmax(
    xt::xarray<float> xarray, 
    int axis
) {
    xt::xarray<float> max = amax(xarray, axis);
    
    // to keep dims
    max.reshape({shape[0]...shape[n})
    
    xt::xarray<float> expX = xt::exp(xarray - max);
    xt::xarray<float> sum = xt::sum(exp_x, axis);
  
    // to keep dims
    sum.reshape({shape[0]...shape[n})
    
    xt::xarray<float> fx = expX / sum;
    
}
```

```c++
void concatenate(
    xt::xarray<float> arr1, 
    xt::xarray<float> arr2,
    int axis
) {
    xt::concatenate(xtuple(arr1, arr2), axis);
}
```

