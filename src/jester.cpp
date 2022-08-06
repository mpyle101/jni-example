#include <iostream>
#include <jni.h>

int main()
{
    JavaVMOption *opts = new JavaVMOption[1];
    opts[0].optionString = const_cast<char*>("-Djava.class.path=./hello-world");
    
    JavaVMInitArgs args;
    args.version  = JNI_VERSION_1_8;
    args.options  = opts;
    args.nOptions = 1;
    args.ignoreUnrecognized = JNI_FALSE;

    JavaVM *jvm {nullptr};
    JNIEnv *env {nullptr};
    jint rc = JNI_CreateJavaVM(&jvm, (void**) &env, &args);
    delete [] opts;

    if (rc != JNI_OK) {
        switch (rc) {
            case JNI_EVERSION:
                std::cerr << "JVM is outdated" << std::endl;
                break;
            case JNI_ENOMEM:
                std::cerr << "Not enough memory to load JVM" << std::endl;
                break;
            case JNI_EINVAL:
                std::cerr << "Invalid argument" << std::endl;
                break;
            case JNI_EEXIST:
                std::cerr << "JVM already running" << std::endl;
                break;
            default:
                std::cerr << "Error launching JVM: " << rc << std::endl;
        }

        exit(EXIT_FAILURE);
    }

    std::cout << "JVM loaded: ";
    jint vers {env->GetVersion()};
    std::cout << ((vers >> 16) & 0x0f) << "." << (vers & 0x0f) << std::endl;

    jclass cls = env->FindClass("HelloWorld/Main");
    if (cls == nullptr) {
        env->ExceptionDescribe();
    } else {
        jmethodID m_id = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
        if (m_id == nullptr) {
            std::cerr << "Method 'main' not found" << std::endl;
        } else {
            env->CallStaticVoidMethod(cls, m_id);
        }
    }

    jvm->DestroyJavaVM();

    return 0;
}