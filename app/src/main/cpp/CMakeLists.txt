project(android_x_tensor)

# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/includes)


find_library( # Sets the name of the path variable.
        android-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        android )

find_library(
        log-lib
        log
)

add_library(
        jni_xtensor
        SHARED
        xtensor/jni_xtensor.cpp
)

target_link_libraries(
        jni_xtensor
        ${log-lib}
        ${android-lib}
        ${jni_array}
)



add_library(
        xtensor-utility
        SHARED
        xtensor/utility.cpp
)



target_link_libraries(
        xtensor-utility
        ${log-lib}
        ${android-lib}
)