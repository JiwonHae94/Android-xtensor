project(android_xtensor)

# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.
cmake_minimum_required(VERSION 3.10)
find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)

set(xtensor_DIR ${CMAKE_SOURCE_DIR}/include/xtensor)
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/include/opencv/4.5.5/sdk/native/jni)
find_package(OpenCV REQUIRED core imgproc)
