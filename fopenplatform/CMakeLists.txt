cmake_minimum_required(VERSION 2.8.11)
project(fopenplatform)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}")
#set(QT_QMAKE_EXECUTABLE "/usr/bin/qmake")
set(USE_PREBUILT_LIB OFF CACHE BOOL "using prebuilt library or not" FORCE)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

#set(IMG_DIR "${PROJECT_SOURCE_DIR}/res/images")
#set(FONT_DIR "${PROJECT_SOURCE_DIR}/res/fonts")

# Find the QtWidgets library
find_package(Qt5Widgets)

#configure_file(
 #   "${jade_SOURCE_DIR}/config.h.in"
  #  "${jade_BINARY_DIR}/config.h"
#)

add_subdirectory(src)
