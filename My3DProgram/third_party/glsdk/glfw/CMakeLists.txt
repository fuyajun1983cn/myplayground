project(glfw) 

if(UNIX)
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR} include lib)
include_directories(lib/x11)
add_definitions(-D_GLFW_USE_LINUX_JOYSTICKS -D_GLFW_HAS_XRANDR -D_GLFW_HAS_PTHREAD -D_GLFW_HAS_SYSCONF -D_GLFW_HAS_SYSCTL -D_GLFW_HAS_GLXGETPROCADDRESS -Wdeprecated-declarations)

AUX_SOURCE_DIRECTORY(lib glfw_SRC)
AUX_SOURCE_DIRECTORY(lib/x11 glfw_x11_SRC)

add_library(glfw SHARED ${glfw_SRC} ${glfw_x11_SRC})
target_link_libraries(glfw ${X11_LIBRARIES} pthread GL GLU Xrandr)

endif(UNIX)

add_subdirectory(examples)