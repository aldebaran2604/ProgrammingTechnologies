#include <jni.h>
#include <string.h>
//#include <stdio.h>
#include <stdlib.h>

jobject initContrcutor(char *nombreClase, JavaVM *jvm, JNIEnv *env);
jobject initContrcutorArchivo(char *nombreClase, char *archivo, JavaVM *jvm, JNIEnv *env);
void addAssert(char* nameAssert, jclass cls, jobject instanceObject, JavaVM *jvm, JNIEnv *env);
int runJess(jclass cls, jobject instanceObject, JavaVM *jvm, JNIEnv *env);
jstring getFetch(char *nameFetch, jclass cls, jobject instanceObject, JavaVM *jvm, JNIEnv *env);

int main(int argc, char **argv) {
	const char *fetchEnfermedad[4];
	fetchEnfermedad[0] = "enfermedad1";
	fetchEnfermedad[1] = "enfermedad2";
	fetchEnfermedad[2] = "enfermedad3";
	fetchEnfermedad[3] = "enfermedad4";
	JavaVMOption options[1];
	JNIEnv *env;
	JavaVM *jvm;
	JavaVMInitArgs vm_args;

	options[0].optionString = "-Djava.class.path=.:jess.jar";

	memset(&vm_args, 0, sizeof(vm_args));
	vm_args.version = JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	vm_args.options = options;

	long status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

	if (status == JNI_ERR) {
		printf("Error al crear la maquina virtual, bye bye!\n");
		return -1;
	}
	if (argc>1) {
		jobject instanceMainClass;
		instanceMainClass = initContrcutorArchivo("MainClass", "diagnostico.clp", jvm, env);
		jclass cls = (*env)->GetObjectClass(env, instanceMainClass);
		for (int i=1; i<argc; i++) {
			addAssert(argv[i], cls, instanceMainClass, jvm, env);
		}
		//addAssert("diarrea", cls, instanceMainClass, jvm, env);
		//addAssert("vomito", cls, instanceMainClass, jvm, env);
		//addAssert("deshidratacion", cls, instanceMainClass, jvm, env);
		int valor = runJess(cls, instanceMainClass, jvm, env);
		printf("Tiene: %d enfermedad(es) \n", valor);
		for(int i2=0; i2<4; i2++){
			jstring auxValor;
			auxValor = getFetch(fetchEnfermedad[i2], cls, instanceMainClass, jvm, env);
			const char *str = (*env)->GetStringUTFChars(env, auxValor, NULL);
			if (strcmp (str, "") != 0) {
				printf("%s \n", str);
			}
		}
		//printf("argc: %d \n", argc);
	} else {
		(*jvm)->DestroyJavaVM(jvm);
	    printf("No se pasaron sintomas, bye bye!\n");
	}
}

jobject initContrcutor(char *nombreClase, JavaVM *jvm, JNIEnv *env){
	jclass cls;
	cls = (*env)->FindClass(env, nombreClase);
	if (cls==0) {
		(*jvm)->DestroyJavaVM(jvm);
	    printf("Error no se encontro la clase %s, bye bye!\n", nombreClase);
		exit(0);
	}
	jmethodID constructor;
	constructor = (*env)->GetMethodID(env, cls, "<init>", "()V");
    if (constructor==0) {
        (*jvm)->DestroyJavaVM(jvm);
        printf("Error no se logro instanciar %s, bye bye!\n", nombreClase);
        exit(0);
    }
    jobject simpleJNITestInstance = (*env)->NewObject(env, cls, constructor);
    if (simpleJNITestInstance == 0) {
        (*jvm)->DestroyJavaVM(jvm);
        printf("Error no se logro crear %s, bye bye!\n", nombreClase);
        exit(0);
    }
	return simpleJNITestInstance;
}

jobject initContrcutorArchivo(char *nombreClase, char *archivo, JavaVM *jvm, JNIEnv *env){
	jclass cls;
	cls = (*env)->FindClass(env, nombreClase);
	if (cls==0) {
		(*jvm)->DestroyJavaVM(jvm);
	    printf("Error no se encontro la clase %s, bye bye!\n", nombreClase);
		exit(0);
	}
	jmethodID constructor;
	constructor = (*env)->GetMethodID(env, cls, "<init>", "(Ljava/lang/String;)V");
    if (constructor==0) {
        (*jvm)->DestroyJavaVM(jvm);
        printf("Error no se logro instanciar %s, bye bye!\n", nombreClase);
        exit(0);
    }
    jstring jstr1 = (*env)->NewStringUTF(env, archivo);
    jobject simpleJNITestInstance = (*env)->NewObject(env, cls, constructor, jstr1);
    if (simpleJNITestInstance == 0) {
        (*jvm)->DestroyJavaVM(jvm);
        printf("Error no se logro crear %s, bye bye!\n", nombreClase);
        exit(0);
    }
	return simpleJNITestInstance;
}

void addAssert(char* nameAssert, jclass cls, jobject instanceObject, JavaVM *jvm, JNIEnv *env) {
	if (cls==NULL) {
		(*jvm)->DestroyJavaVM(jvm);
		printf("Error cls, bye bye!\n");
		exit(0);
	}
	jmethodID assert = (*env)->GetMethodID(env, cls, "addAssert", "(Ljava/lang/String;)V");
	jstring jstr1 = (*env)->NewStringUTF(env, nameAssert);
    if (assert==0) {
        (*jvm)->DestroyJavaVM(jvm);
        printf("Error no se logro obtener el Metodo addAssert, bye bye!\n");
        exit(0);
    }
    (*env)->CallObjectMethod(env, instanceObject , assert, jstr1);
}

int runJess(jclass cls, jobject instanceObject, JavaVM *jvm, JNIEnv *env) {
	if (cls==NULL) {
		(*jvm)->DestroyJavaVM(jvm);
		printf("Error cls, bye bye!\n");
		exit(0);
	}
	jmethodID runJessM = (*env)->GetMethodID(env, cls, "runJess", "()I");
    if (runJessM==0) {
        (*jvm)->DestroyJavaVM(jvm);
        printf("Error no se logro obtener el Metodo runJess, bye bye!\n");
        exit(0);
    }
    jint valor;
    valor = (*env)->CallObjectMethod(env, instanceObject , runJessM);
    return valor;
}

jstring getFetch(char *nameFetch, jclass cls, jobject instanceObject, JavaVM *jvm, JNIEnv *env) {
	if (cls==NULL) {
		(*jvm)->DestroyJavaVM(jvm);
		printf("Error cls, bye bye!\n");
		exit(0);
	}
	jstring jstr1 = (*env)->NewStringUTF(env, nameFetch);
	jmethodID runJessM = (*env)->GetMethodID(env, cls, "getFetch", "(Ljava/lang/String;)Ljava/lang/String;");
    if (runJessM==0) {
        (*jvm)->DestroyJavaVM(jvm);
        printf("Error no se logro obtener el Metodo getFetch, bye bye!\n");
        exit(0);
    }
    jstring valor;
    valor = (*env)->CallObjectMethod(env, instanceObject , runJessM, jstr1);
    return valor;
}