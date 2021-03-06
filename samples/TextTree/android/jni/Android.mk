LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

CINDER_PATH = ../../../../../../

LOCAL_SRC_FILES := main.cpp

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../src
FILE_LIST := $(wildcard $(LOCAL_PATH)/../../src/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

include $(LOCAL_PATH)/$(CINDER_PATH)/blocks/new-chronotext-toolkit/android/Android.mk

LOCAL_CFLAGS := -DCHR_COMPLEX
LOCAL_CFLAGS += -ffast-math -O3
#LOCAL_CFLAGS += -g -DDEBUG

LOCAL_LDLIBS := -llog -landroid
LOCAL_STATIC_LIBRARIES := cinder boost_system boost_filesystem boost_thread freeimage ft2 android_native_app_glue

LOCAL_MODULE := TextTree
include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
$(call import-module,cinder)
$(call import-module,boost)
