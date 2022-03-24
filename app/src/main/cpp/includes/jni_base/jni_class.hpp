//
// Created by Jiwon_Hae on 2022/03/24.
//


#include <iostream>
#include <string>
#include <cctype>

namespace JClass {

    /**
     * JNI/C++: Get Class Name
     * @param env [in] JNI context
     * @param myCls [in] Class object, which the name is asked of
     * @param fullpath [in] true for full class path, else name without package context
     * @return Name of class myCls, encoding UTF-8
     */
    std::string getClassName(JNIEnv* env, jclass myCls, bool fullpath = false)
    {
        jclass ccls = env->FindClass("java/lang/Class");
        jmethodID mid_getName = env->GetMethodID(ccls, "getName", "()Ljava/lang/String;");
        jstring strObj = (jstring)env->CallObjectMethod(myCls, mid_getName);
        const char* localName = env->GetStringUTFChars(strObj, 0);
        std::string res = localName;
        env->ReleaseStringUTFChars(strObj, localName);
        if (!fullpath)
        {
            std::size_t pos = res.find_last_of('.');
            if (pos!=std::string::npos)
            {
                res = res.substr(pos+1);
            }
        }
        return std::string(1, tolower(res[0]));
    }
}
