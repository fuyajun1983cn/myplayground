
include_directories(../../freeglut/include ../../glload/include)
add_executable(simple_glut simple_glut.cpp)
#link_directories(${CMAKE_CURRENT_BINARY_DIR}/glsdk/freeglut  ${CMAKE_CURRENT_BINARY_DIR}/glsdk/glload)
target_link_libraries(simple_glut glload freeglut)