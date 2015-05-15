##inotify使用

运行命令：
java -cp dist/ThinkingInJava.jar -Djava.library.path=/home/fuyajun/MyPlayground/my-program-wharehouse/java/jni/inofity/src/com/fyj/test/lib/build/  com.fyj.test.VimFileObserver


```java
/**
  * 方法声明
  */

static JNINativeMethod sMethods[] = {

     /* name, signature, funcPtr */

    { "init", "()I", (void*)com_fyj_test_fileobserver_init },

    { "observe", "(I)V", (void*)com_fyj_test_fileobserver_observe },

    { "startWatching", "(ILjava/lang/String;I)I", (void*)com_fyj_test_fileobserver_startWatching },

    { "stopWatching", "(II)V", (void*)com_fyj_test_fileobserver_stopWatching }

    

};



int register_com_fyj_test_FileObserver(JNIEnv* env)

{

    jclass clazz;



    clazz = env->FindClass("com/fyj/test/FileObserver$ObserverThread");



    if (clazz == NULL)

	{

        ALOGE("Can't find com/fyj/test/FileObserver$ObserverThread");

        return -1;

    }



    method_onEvent = env->GetMethodID(clazz, "onEvent", "(IILjava/lang/String;)V");

    if (method_onEvent == NULL)

    {

        ALOGE("Can't find FileObserver.onEvent(int, int, String)");

        return -1;

    }


    //注册方法
    return env->RegisterNatives(clazz, sMethods, NELEM(sMethods));

}


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv* env;
    vm->GetEnv((void**)&env, JNI_VERSION_1_2);
    register_com_fyj_test_FileObserver(env);

    return JNI_VERSION_1_2;

}
```
