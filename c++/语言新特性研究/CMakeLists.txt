cmake_minimum_required(VERSION 2.8)
project(Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_executable(lambda_test lambda_test.cpp)
add_executable(type_test type_test.cpp)
add_executable(init_test init_test.cpp)
add_executable(enum_test enum_test.cpp)
