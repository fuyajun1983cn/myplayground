cmake_minimum_required(VERSION 2.8)
project(sone)

set(CMAKE_C_FLAGS "-std=c99")

find_package(DirectFB)
if (DFB_FOUND)
include_directories(${DFB_INCLUDE_DIRS})
endif()

set(sone_SRCS
   src/dfb.c
   src/dialog.c
   src/guisubsystem.c
   src/textarea.c
   src/timer.c
   src/utils.c
   src/main.c
   )
   
add_executable(sone ${sone_SRCS})
target_link_libraries(sone ${DFB_LIBRARIES} pthread)