cmake_minimum_required(VERSION 2.8)
project(Lib)

include_directories("/home/fuyajun/MyPlayground/java/jdk1.7.0_51/include"
                    "/home/fuyajun/MyPlayground/java/jdk1.7.0_51/include/linux"
)

include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckFunctionExists)
include(CheckCCompilerFlag)
check_include_file(sys/inotify.h HAVE_INOTIFY_H)
if (NOT HAVE_INOTIFY_H)
    message(WARNING "failed to find inotify.h")
endif()

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories(${PROJECT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H=1)


add_library(javalib SHARED com_fyj_test_FileObserver.cpp)
