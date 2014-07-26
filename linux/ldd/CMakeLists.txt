cmake_minimum_required(VERSION 2.8)
project(ldd)

set(KERNEL_DIR /usr/src/linux-headers-3.13.0-27-generic)
set(SCULL_DEBUG OFF)

##
#编译某个内核模块时,只需要在对应目录下新建一个CMakeLists.txt文件,
#内容可为如下:
#         compile_module(hello)
#如果该模块由多个模块构成,则可写成
#compile_module(hello  depend1 depend2 ...)
#

function(compile_module obj)
  set(TARGET_NAME ${obj})
  add_custom_target(${TARGET_NAME} ALL cp -f ${CMAKE_CURRENT_SOURCE_DIR}/*.* ${CMAKE_CURRENT_BINARY_DIR}/
  		    COMMAND echo "compiling module ${obj}.ko..."
  		    )
  list(LENGTH ARGN argn_len)
  set(i 0)
  set(depend_objlist "")
  while( i LESS ${argn_len})  
	list(GET ARGN ${i} argn_value)  
	set(depend_objlist "${depend_objlist} ${argn_value}.o") 
	math(EXPR i "${i} + 1")  
  endwhile() 
  
  add_custom_command(TARGET ${TARGET_NAME}
		     POST_BUILD
		     COMMAND echo "obj-m := ${obj}.o" > ${CMAKE_CURRENT_BINARY_DIR}/Makefile
		     COMMAND echo "${obj}-objs:=${depend_objlist}" >>${CMAKE_CURRENT_BINARY_DIR}/Makefile
		     COMMAND make -C ${KERNEL_DIR} M=${CMAKE_CURRENT_BINARY_DIR} modules
		     )
endfunction()

add_subdirectory(chapter02)
add_subdirectory(chapter03)
add_subdirectory(chapter04)
add_subdirectory(chapter05)
add_subdirectory(chapter06)
add_subdirectory(chapter07)
add_subdirectory(chapter08)



########## no ldd test program #############
add_subdirectory(sysfs)
add_subdirectory(input)
