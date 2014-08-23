#include "platform.h"

#include "fyjstd.h"
#include "app.h"
#include "os.h"

using namespace FYJ;

static Application *app = NULL;

JavaVM* gJvm = 0;

struct JNIObjects {
	JNIEnv* env;
	JavaVM *jvm;
	bool shouldDetach;
};
JNIObjects* gJNIObject = 0;



#ifdef __cplusplus
extern "C" {
#endif

JNIObjects* getJNIEnv();

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
  
  	gJvm = vm;
  
//  	JNIObjects* jvm = getJNIEnv();
	
  
  return JNI_VERSION_1_2;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{  
  	gJvm = 0;
} 

JNIObjects* getJNIEnv()
{
	delete gJNIObject;
	
	gJNIObject = new JNIObjects;
	
	gJvm->GetEnv((void**)&gJNIObject->env, JNI_VERSION_1_2);
   	gJNIObject->jvm = gJvm;
	gJNIObject->shouldDetach = true;
	if (gJNIObject->env != NULL) 
	{
		gJNIObject->shouldDetach = false;
	} 
	else if (gJNIObject->jvm->AttachCurrentThread(&gJNIObject->env,NULL) != JNI_OK)
	{
        		//LOGE(LOG_TAG, "%s: AttachCurrentThread() failed", __FUNCTION__);
        		return NULL;
	} 
    return gJNIObject;
}


Image *loadImageFileFromJava(String filename)
{
	JNIObjects* jvm = getJNIEnv();
	jclass fyjclass = jvm->env->FindClass("com/fyj/test/common/Utilities");
	if (fyjclass == 0) {
		ERROR("com.fyj.common.Utilities not found!");
		return NULL;
	}

	jmethodID func = jvm->env->GetStaticMethodID(fyjclass, "loadImageFromDrawable", "(Ljava/lang/String;)Landroid/graphics/Bitmap;");
	if (func == 0) {
		ERROR("Could not find method id!");
		return NULL;
	}
	INFO("Loading image %s", filename.c_str());
	jstring image_name = jvm->env->NewStringUTF(filename.c_str());
	jobject bitmap_object = jvm->env->CallStaticObjectMethod(fyjclass, func, image_name);

	AndroidBitmapInfo  info;
	void*  pixels;
	int format;
	int ret;
	if ((ret = AndroidBitmap_getInfo(jvm->env, bitmap_object, &info)) < 0) {
	        ERROR("AndroidBitmap_getInfo() failed ! error=%d", ret);
	        return NULL;
	    }

	    if (info.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
	        INFO("Bitmap format is  RGBA_8888 !");
	        format = GL_RGBA;
	    } else if (info.format == ANDROID_BITMAP_FORMAT_RGB_565) {
	        INFO("Bitmap format is  RGB_565 !");
	        format = GL_RGB;
	    }

	    if ((ret = AndroidBitmap_lockPixels(jvm->env, bitmap_object, &pixels)) < 0) {
	        WARN("AndroidBitmap_lockPixels() failed ! error=%d", ret);
	    }
	    Image *img = fyj_new Image;
	    img->pixels = fyj_new uint8[info.height * info.stride];
	    fyj_memset(img->pixels, 0, info.height * info.stride);
	    fyj_memcpy(img->pixels, pixels, info.height * info.stride);
	   img->width = info.width;
	   img->height = info.height;
	   img->format = format;
#if 0
	   for (int i = 0; i < info.height * info.stride - 1; i++)
	   	INFO("0x%4x",  *(reinterpret_cast<unsigned char*>(img->pixels)+i));
#endif
	   AndroidBitmap_unlockPixels(jvm->env, bitmap_object);

	   jvm->env->DeleteLocalRef(fyjclass);

	   INFO("Finishling load image from Java!!");

	   return img;
}


JNIEXPORT jboolean JNICALL Java_com_fyj_test_common_NativeInterfaces_appInit(JNIEnv * env, jobject obj)
{
	return app->init();
}

JNIEXPORT jboolean JNICALL Java_com_fyj_test_common_NativeInterfaces_appRender(JNIEnv * env, jobject obj)
{
	return app->render();
}

JNIEXPORT void JNICALL Java_com_fyj_test_common_NativeInterfaces_main(JNIEnv * env, jobject obj, int width, int height)
{
	if (!app) {
		app = fyj_new Application();
	}
	app->setInputParameter("CurrentTest", "MyFirstTest");
	app->setInputParameter("width", width);
	app->setInputParameter("height", height);
}

 JNIEXPORT void JNICALL Java_com_fyj_test_common_NativeInterfaces_mainEnd(JNIEnv * env, jobject obj)
{
	if (app != NULL) {
		fyj_delete app;
		app = NULL;
	}
}

#ifdef __cplusplus
 }
#endif
 
