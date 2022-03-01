//
// Created by Jiwon_Hae on 2022/03/02.
//


#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>
#include <jni.h>
#include <cmath>
#include <array>
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xnpy.hpp"
#include <sstream>
#include <strstream>
#include <string>

using namespace xt;

auto load_npy(AAssetManager* mgr, const char* filename){
    AAsset* open = AAssetManager_open(mgr, filename, AASSET_MODE_UNKNOWN);
    long size = AAsset_getLength(open);
    char* buffer = (char*) malloc (sizeof(char)*size);
    AAsset_read (open,buffer,size);
    std::istrstream stream(reinterpret_cast<const char*>(buffer), size);
    AAsset_close(open);

    return load_npy<float>(stream);
}


