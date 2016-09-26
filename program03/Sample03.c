#include <jni.h>
#include <stdio.h>
#include <string.h>

int main()
{
    JavaVMOption options[1];
    JNIEnv *env;
    JavaVM *jvm;
    JavaVMInitArgs vm_args;
    long status;
    jclass cls;
    jobject clsObject;
    jmethodID mid;
    jstring name;
    
    options[0].optionString = "-Djava.class.path=.";
    memset(&vm_args, 0, sizeof(vm_args));
    vm_args.version = JNI_VERSION_1_2;
    vm_args.options = options;

    status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

    if (status!=JNI_ERR) {
        cls = (*env)->FindClass(env, "Sample03");
        //clsObject = (*env)->GetObjectClass(cls);
        if (cls!=0) {
            clsObject = (*env)->GetObjectClass(env, cls);
            if (clsObject!=0) {
               mid = (*env)->GetMethodID(env, clsObject, "getName", "()L");
               name = (*env)->CallObjectMethod(env, clsObject, mid);
               //const char *auxName = (*env)->GetStringUTFChars(env, name, 0);
               //printf("Name: %s", auxName);
            }
            //mid = (*env)->GetMethodID(clsObject, "getName");
            //name = (*env)->CallObjectMethod(cls, clsObject);
            //printf("Name: %s", name);
        }
        (*jvm)->DestroyJavaVM(jvm);
        return 0;
    } else {
        return -1;
    }
}
