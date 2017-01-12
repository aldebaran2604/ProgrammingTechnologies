#include <jni.h>
#include <string.h>
//#include <stdio.h>
#include <stdlib.h>

jobject initContrcutor(char *nombreClase, jclass cls, JavaVM *jvm, JNIEnv *env);
void addEval(char* evalCadena, jclass cls, jobject instanceObject, JavaVM *jvm, JNIEnv *env);

int main()
{
	JavaVMOption options[1];
	JNIEnv *env;
	JavaVM *jvm;
	JavaVMInitArgs vm_args;

	options[0].optionString = "-Djava.class.path=.:jess/Rete";

	memset(&vm_args, 0, sizeof(vm_args));
	vm_args.version = JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	vm_args.options = options;

	long status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

	if (status == JNI_ERR) {
		printf("Error al crear la maquina virtual, bye bye!\n");
		return -1;
	}
	jobject instanceRete;
	jclass clsRete;
	instanceRete = initContrcutor("jess/Rete", clsRete, jvm, env);
	jclass cls = (*env)->GetObjectClass(env, instanceRete);
	addEval("(reset)", cls, instanceRete, jvm, env);
	addEval("(defrule botulismo (colicos) (problema-respiratorio) (problema-habla) (vision-doble) (nauseas) (vomito) (debilidad) (paralisis) =>(printout t \"Usted tiene botulismo\" crlf))", cls, instanceRete, jvm, env);
	addEval("(assert (colicos))", cls, instanceRete, jvm, env);
	addEval("(assert (problema-respiratorio))", cls, instanceRete, jvm, env);
	addEval("(assert (problema-habla))", cls, instanceRete, jvm, env);
	addEval("(assert (vision-doble))", cls, instanceRete, jvm, env);
	addEval("(assert (nauseas))", cls, instanceRete, jvm, env);
	addEval("(assert (vomito))", cls, instanceRete, jvm, env);
	addEval("(assert (debilidad))", cls, instanceRete, jvm, env);
	addEval("(assert (paralisis))", cls, instanceRete, jvm, env);
	addEval("(run)", cls, instanceRete, jvm, env);
}

jobject initContrcutor(char *nombreClase, jclass cls, JavaVM *jvm, JNIEnv *env){
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
        printf("Error no se logro instanciar %s, bye bye!\n", nombreClase);
        exit(0);
    }
	return simpleJNITestInstance;
}

void addEval(char* evalCadena, jclass cls, jobject instanceObject, JavaVM *jvm, JNIEnv *env) {
	if (cls==NULL) {
		(*jvm)->DestroyJavaVM(jvm);
		printf("Error cls, bye bye!\n");
		exit(0);
	}
	jmethodID evalRete = (*env)->GetMethodID(env, cls, "eval", "(Ljava/lang/String;)Ljess/Value;");
	jstring jstr1 = (*env)->NewStringUTF(env, evalCadena);
    if (evalRete==0) {
        (*jvm)->DestroyJavaVM(jvm);
        printf("Error no se logro obtener el Metodo eval de Rete, bye bye!\n");
        exit(0);
    }
    (*env)->CallObjectMethod(env, instanceObject , evalRete, jstr1);
}