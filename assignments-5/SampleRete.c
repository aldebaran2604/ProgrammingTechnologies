#include <jni.h>
#include <string.h>

int main()
{
	JavaVMOption options[1];
	JNIEnv *env;
	JavaVM *jvm;
	JavaVMInitArgs vm_args;

	jclass cls;

	jmethodID constructor;

	jobject simpleJNITestInstance;

	options[0].optionString = "-Djava.class.path=.:jess/Rete";

	memset(&vm_args, 0, sizeof(vm_args));
	vm_args.version = JNI_VERSION_1_6;
	vm_args.nOptions = 1;
	vm_args.options = options;

	long status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

	if (status == JNI_ERR) {
		printf("Error al crear la maquina virtual, bye bye!\n");
		return -1;
	} else {
		cls = (*env)->FindClass(env, "jess/Rete");
		if (cls==0) {
			(*jvm)->DestroyJavaVM(jvm);
	    	printf("Error no se encontro la clase Rete, bye bye!\n");
			return 0;
		}
                constructor = (*env)->GetMethodID(env, cls, "<init>", "()V");
                if (constructor==0) {
                        (*jvm)->DestroyJavaVM(jvm);
                printf("Error no se logro instanciar Rete, bye bye!\n");
                        return 0;
                }
                jobject simpleJNITestInstance = (*env)->NewObject(env, cls, constructor);
                if (simpleJNITestInstance==0) {
                        (*jvm)->DestroyJavaVM(jvm);
                printf("Error no se logro instanciar Rete, bye bye!\n");
                        return 0;
                }
                jstring jstr1 = (*env)->NewStringUTF(env, "diagnostico.clp");
                jmethodID batchRete = (*env)->GetMethodID(env, cls, "batch", "(Ljava/lang/String;)Ljess/Value;");
                if (batchRete==0) {
                        (*jvm)->DestroyJavaVM(jvm);
                printf("Error no se logro obtener el Metodo batch de Rete, bye bye!\n");
                        return 0;
                }
                (*env)->CallObjectMethod(env, simpleJNITestInstance , batchRete, jstr1);

                jmethodID batchFetch = (*env)->GetMethodID(env, cls, "fetch", "(Ljava/lang/String;)Ljess/Value;");
                if (batchFetch==0) {
                        (*jvm)->DestroyJavaVM(jvm);
                printf("Error no se logro obtener el Metodo fetch de Rete, bye bye!\n");
                        return 0;
                } else {
                        jmethodID contextID = (*env)->GetMethodID(env, cls, "getGlobalContext", "()Ljess/Context;");
                        jobject globalContext;
                        if (contextID==0) {
                                (*jvm)->DestroyJavaVM(jvm);
                        printf("Error no se logro obtener el Objeto Context de Rete, bye bye!\n");
                                return 0;
                        } else {
                                globalContext = (*env)->CallObjectMethod(env, simpleJNITestInstance , contextID);
                                if (globalContext==0) {
                                        (*jvm)->DestroyJavaVM(jvm);
                                printf("Error no se logro obtener el Objeto Context de Rete, bye bye!\n");
                                        return 0;
                                }
                        }
                        jstring jstr2 = (*env)->NewStringUTF(env, "square");
                        jobject valueSquare;

                        valueSquare = (*env)->CallObjectMethod(env, simpleJNITestInstance , batchFetch, jstr2);
                        if (valueSquare==0) {
                                (*jvm)->DestroyJavaVM(jvm);
                        printf("Error no se logro obtener el Objeto Value Rete, bye bye!\n");
                                return 0;
                        } else {
                                jclass clsValue;
                                clsValue = (*env)->FindClass(env, "jess/Value");
                                if (clsValue==0) {
                                        (*jvm)->DestroyJavaVM(jvm);
                                printf("Error no se encontro la clase Value, bye bye!\n");
                                        return 0;
                                }
                                jmethodID constructorValue;
                                constructorValue = (*env)->GetMethodID(env, clsValue, "<init>", "(Ljess/Value;)V");
                                if (constructorValue==0) {
                                        (*jvm)->DestroyJavaVM(jvm);
                                printf("Error no se encontro el contructor de Value, bye bye!\n");
                                        return 0;
                                }
                                jobject instanceValue = (*env)->NewObject(env, clsValue, constructorValue, valueSquare);
                                if (instanceValue==0) {
                                        (*jvm)->DestroyJavaVM(jvm);
                                printf("Error no se logro instanciar Value, bye bye!\n");
                                        return 0;
                                }
                                jmethodID contextID = (*env)->GetMethodID(env, instanceValue, "stringValue", "(Ljess/Context;)Ljava/lang/String;");
                                if (contextID==0) {
                                        (*jvm)->DestroyJavaVM(jvm);
                                printf("Error no se logro obtener el Metodo stringValue, bye bye!\n");
                                        return 0;
                                }

                                /*jint valueSquare;

                                valueSquare = (*env)->CallObjectMethod(env, instanceValue , contextID, globalContext);

                                if (valueSquare==0) {
                                        (*jvm)->DestroyJavaVM(jvm);
                                printf("Error no se logro obtener el valor de Value, bye bye!\n");
                                        return 0;
                                }*/
                        }
                }
	}
}