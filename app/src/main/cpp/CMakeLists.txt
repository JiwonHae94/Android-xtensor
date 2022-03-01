project(android_x_tensor)

# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.
cmake_minimum_required(VERSION 3.10)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

add_library(
        xtensor-lib
        SHARED
        xtensor/xtensor_practice.cpp
)


add_library(
        xtensor-utility
        SHARED
        xtensor/utility.cpp
)

find_library(
        log-lib
        log
)


target_link_libraries(
        xtensor-lib
        ${log-lib}
        ${android-lib}
)


target_link_libraries(
        xtensor-utility
        ${log-lib}
        ${android-lib}
)