cmake_minimum_required(VERSION 2.8)
project(libnl-test)

include(CheckIncludeFile)
include(CheckIncludeFiles)
check_include_file(/usr/local/include/libnl3/netlink/netlink.h CONFIG_LIBNL30)
check_include_file(/usr/local/include/libnl2/netlink/netlink.h CONFIG_LIBNL20)
set(DEBUG 1)
configure_file(
"${PROJECT_SOURCE_DIR}/config.h.in"
"${PROJECT_BINARY_DIR}/config.h"
)

include_directories(${PROJECT_BINARY_DIR})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
find_package(LibNL)
if (NOT NL_FOUND)
    message(FATAL "no netlink library found!!!")
    return()
endif()

include_directories(${NL_INCLUDE_DIRS})

message(INFO "includes: ${NL_INCLUDE_DIRS}")
message(INFO "libs: ${NL_LIBRARIES}")

add_executable(test1 test1.c)
target_link_libraries(test1 ${NL_LIBRARIES})


add_executable(test2 test2.c)
target_link_libraries(test2 ${NL_LIBRARIES})

add_executable(get_family_id get_family_id.c)
target_link_libraries(get_family_id ${NL_LIBRARIES})

add_executable(get_device_index get_device_index.c)
target_link_libraries(get_device_index ${NL_LIBRARIES})

add_executable(scan_test nl80211_common.c scan_test.c)
target_link_libraries(scan_test ${NL_LIBRARIES})

add_executable(scantesthandler scantesthandler.c)
target_link_libraries(scantesthandler ${NL_LIBRARIES})

