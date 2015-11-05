cmake_minimum_required(VERSION 2.8)
project(test2)

find_package(Lua52)

if (NOT LUA51_FOUND)
    message(ERR "failed to find lua52 library")
    return()
endif()

include_directories(${LUA_INCLUDE_DIR})

add_executable(test test.c)
target_link_libraries(test ${LUA_LIBRARIES})





