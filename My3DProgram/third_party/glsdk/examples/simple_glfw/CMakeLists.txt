
include_directories(../../glfw/include ../../glload/include)
add_executable(simple_glfw simple_glfw.cpp)
#link_directories(${CMAKE_CURRENT_BINARY_DIR}/glsdk/freeglut  ${CMAKE_CURRENT_BINARY_DIR}/glsdk/glload)
target_link_libraries(simple_glfw glload glfw) 
