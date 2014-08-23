#ifndef PLATFORM_H
#define PLATFORM_H

#include "fyjstd.h"
#include <jni.h>
#include <android/log.h>
#include <android/bitmap.h>
#include "fyjstring.h"

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>


#define GL_WRITE_ONLY   GL_WRITE_ONLY_OES
#define glMapBuffer     glMapBufferOES
#define glUnmapBuffer   glUnmapBufferOES



struct Image
{
	int width;
	int height;
	int format;
	void *pixels;
};

extern "C" Image *loadImageFileFromJava(FYJ::String filename);


#endif
