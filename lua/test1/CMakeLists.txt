cmake_minimum_required(VERSION 2.8)
project(test1)

find_package(Lua51)

if (NOT LUA51_FOUND)
    message(ERR "failed to find lua51 library")
    return()
endif()

include_directories(${LUA_INCLUDE_DIR})

add_executable(test test.c)
target_link_libraries(test ${LUA_LIBRARIES})





