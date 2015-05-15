/* //device/libs/android_runtime/android_util_FileObserver.cpp

**

** Copyright 2006, The Android Open Source Project

**

** Licensed under the Apache License, Version 2.0 (the "License"); 

** you may not use this file except in compliance with the License. 

** You may obtain a copy of the License at 

**

**     http://www.apache.org/licenses/LICENSE-2.0 

**

** Unless required by applicable law or agreed to in writing, software 

** distributed under the License is distributed on an "AS IS" BASIS, 

** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 

** See the License for the specific language governing permissions and 

** limitations under the License.

*/




#include <jni.h>

#include <unistd.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdint.h>

#include <fcntl.h>

#include <sys/ioctl.h>

#include <errno.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_INOTIFY_H

#include <sys/inotify.h>

#endif

#define LOG_TAG "com.fyj.test.FileObserver"

#ifndef NeLEM
#define NELEM(x) (int)(sizeof(x)/sizeof((x)[0]))
#endif

void log_print(const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[1024];

    va_start(ap, fmt);
    vsnprintf(buf, 1024, fmt, ap);
    va_end(ap);
}

#define ALOGE(...) log_print(LOG_TAG, __VA_ARGS__)

static jmethodID method_onEvent;



static jint com_fyj_test_fileobserver_init(JNIEnv* env, jobject object)

{

#ifdef HAVE_INOTIFY_H



    return (jint)inotify_init();    



#else // HAVE_INOTIFY



    return -1;



#endif // HAVE_INOTIFY

}



static void com_fyj_test_fileobserver_observe(JNIEnv* env, jobject object, jint fd)

{

#ifdef HAVE_INOTIFY_H

 

    char event_buf[512];

    struct inotify_event* event;

         

    while (1)

    {

        int event_pos = 0;

        int num_bytes = read(fd, event_buf, sizeof(event_buf));

        

        if (num_bytes < (int)sizeof(*event))

        {

            if (errno == EINTR)

                continue;



            ALOGE("***** ERROR! android_os_fileobserver_observe() got a short event!");

            return;

        }

        

        while (num_bytes >= (int)sizeof(*event))

        {

            int event_size;

            event = (struct inotify_event *)(event_buf + event_pos);



            jstring path = NULL;

            

            if (event->len > 0)

            {

                path = env->NewStringUTF(event->name);

            }



            env->CallVoidMethod(object, method_onEvent, event->wd, event->mask, path);

            if (env->ExceptionCheck()) {

                env->ExceptionDescribe();

                env->ExceptionClear();

            }

            if (path != NULL)

            {

                env->DeleteLocalRef(path);

            }



            event_size = sizeof(*event) + event->len;

            num_bytes -= event_size;

            event_pos += event_size;

        }

    }

    

#endif // HAVE_INOTIFY

}



static jint com_fyj_test_fileobserver_startWatching(JNIEnv* env, jobject object, jint fd, jstring pathString, jint mask)

{

    int res = -1;

    

#ifdef HAVE_INOTIFY_H

   

    if (fd >= 0)

    {

        const char* path = env->GetStringUTFChars(pathString, NULL);

        

        res = inotify_add_watch(fd, path, mask);

        

        env->ReleaseStringUTFChars(pathString, path);

    }



#endif // HAVE_INOTIFY

    

    return res;

}



static void com_fyj_test_fileobserver_stopWatching(JNIEnv* env, jobject object, jint fd, jint wfd)

{

#ifdef HAVE_INOTIFY_H



    inotify_rm_watch((int)fd, (uint32_t)wfd);



#endif // HAVE_INOTIFY

}



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



    return env->RegisterNatives(clazz, sMethods, NELEM(sMethods));

}


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv* env;
    vm->GetEnv((void**)&env, JNI_VERSION_1_2);
    register_com_fyj_test_FileObserver(env);

    return JNI_VERSION_1_2;

}
