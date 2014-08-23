LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libcommon
LOCAL_SRC_FILES := \
../../../src/common/fyjstring.cpp \
../../../src/common/fyjprogram.cpp \
../../../src/common/fyjcamera.cpp \
../../../src/common/fyjgeometry_shape.cpp \
../../../src/common/fyjgeometry_sphere.cpp \
../../../src/common/fyjgeometry_torus.cpp

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/../../../src/platforms/android \
$(LOCAL_PATH)/../../../src/common \
$(LOCAL_PATH)/../../../src/testcases \
$(LOCAL_PATH)/../../../third_party/glsdk/glm

include $(BUILD_STATIC_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE := libmytest
LOCAL_SRC_FILES := \
../../../src/testcases/camera/cameratest.cpp \
../../../src/testcases/transform/transformtest.cpp \
../../../src/testcases/texture/texturetest.cpp \
../../../src/testcases/texture/earthtest.cpp \
../../../src/testcases/multitexture/multitexturetest.cpp \
../../../src/testcases/multitexture/earthtest.cpp \
../../../src/testcases/geometry/shapetest.cpp \
../../../src/testcases/geometry/geometrytest.cpp \
../../../src/testcases/fps/fpstest.cpp \
../../../src/testcases/test_interface.cpp

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/../../../src/platforms/android \
$(LOCAL_PATH)/../../../src/common \
$(LOCAL_PATH)/../../../src/testcases \
$(LOCAL_PATH)/../../../third_party/glsdk/glm

LOCAL_CFLAGS := -DOPENGL_ES2
LOCAL_LDLIBS := -ljnigraphics -lGLESv2 -ldl -llog
LOCAL_SHARED_LIBRARIES := libcommon
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libtestbase
LOCAL_SRC_FILES := \
../../../src/app/app.cpp \
../../../src/platforms/android/native_interface.cpp \
../../../src/platforms/android/os.cpp

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/../../../src/platforms/android \
$(LOCAL_PATH)/../../../src/common \
$(LOCAL_PATH)/../../../src/testcases \
$(LOCAL_PATH)/../../../src/app

LOCAL_LDLIBS := -ljnigraphics -lGLESv2 -ldl -llog
LOCAL_SHARED_LIBRARIES := libmytest libcommon
include $(BUILD_SHARED_LIBRARY)