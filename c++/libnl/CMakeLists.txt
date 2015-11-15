cmake_minimum_required(VERSION 2.8)
project(libnl-test)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package(LibNL3)

if (NOT NL3_FOUND)
  message(WARNING "libnl3 not found !")
  return()
endif()

include_directories(${NL3_INCLUDE_DIRS})


add_executable(test1 test1.c)
target_link_libraries(test1 ${NL3_LIBRARIES})
