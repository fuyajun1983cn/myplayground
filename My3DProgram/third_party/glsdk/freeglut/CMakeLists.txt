project(freeglut)

set(VERSION 2.6.0)
set(PACKAGE freeglut)
set(PACKAGE_NAME "freeglut library")
set(PACKAGE_BUGREPORT "freeglut-bugs@lists.sourceforge.net")
set(PACKAGE_STRING "freeglut-${VERSION}")
set(PACKAGE_TARNAME "freeglut-${VERSION}.tar.gz")
set(PACKAGE_VERSION "${VERSION}")
set(X_DISPLAY_MISSING 0)
set(DEBUG 0)

include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckFunctionExists)
include(CheckCCompilerFlag)
check_include_file(dlfcn.h HAVE_DLFCN_H)
if (NOT HAVE_DLFCN_H)
message(WARNING "failed to find dlfn.h ")
endif()

check_include_file(fcntl.h HAVE_FCNTL_H)
check_function_exists(gettimeofday HAVE_GETTIMEOFDAY)
check_include_file(GL/glu.h HAVE_GL_GLU_H)
check_include_file(GL/glx.h HAVE_GL_GLX_H)
check_include_file(GL/gl.h HAVE_GL_GL_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)
check_include_file(limits.h HAVE_LIMITS_H)
check_include_file(memory.h HAVE_MEMORY_H)
check_include_file(stdint.h HAVE_STDINT_H)
check_include_file(stdlib.h HAVE_STDLIB_H)
check_include_file(strings.h HAVE_STRINGS_H)
check_include_file(string.h HAVE_STRING_H)
check_include_file(sys/ioctl.h HAVE_SYS_IOCTL_H)
check_include_file(sys/param.h HAVE_SYS_PARAM_H)
check_include_file(sys/stat.h HAVE_SYS_STAT_H)
check_include_file(sys/time.h HAVE_SYS_TIME_H)
check_include_file(sys/types.h HAVE_SYS_TYPES_H)
check_include_file(unistd.h HAVE_UNISTD_H)
check_function_exists(vprintf HAVE_VPRINTF)
if (NOT HAVE_VPRINTF)
check_function_exists(_doprnt HAVE_DOPRNT)
endif()
check_include_file(X11/extensions/xf86vmode.h HAVE_X11_EXTENSIONS_XF86VMODE_H)
check_include_file(X11/extensions/XInput.h HAVE_X11_EXTENSIONS_XINPUT_H)
check_include_file(X11/extensions/XI.h HAVE_X11_EXTENSIONS_XI_H)
check_c_compiler_flag("-g -o" MINUS_C_MINUS_O)
if (NOT MINUS_C_MINUS_O)
set(NO_MINUS_C_MINUS_O 1)
else()
set(NO_MINUS_C_MINUS_O 0)
endif()
check_include_file(stdlib.h STDLIB_H)
if (STDLIB_H)
check_include_file(stddef.h STDC_HEADERS)
endif()

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/dummy.c "#include <sys/time.h> 
   #include <time.h> 
   void main() 
   { 
    return; 
   }")
try_compile(
  TIME_WITH_SYS_TIME
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/dummy.c
   )

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

include_directories(${PROJECT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H=1)
  
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR} include)
include("freeglut_src.cmake")

add_library(freeglut SHARED ${freeglut_SRC})
target_link_libraries(freeglut ${OPENGL_LIBRARIES} m)

add_subdirectory(progs)