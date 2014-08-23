include_directories(../../glm ../../glload/include ../../glutil/include ../../glfw/include ../../glmesh/include)
add_executable(font_test font_test.cpp)
target_link_libraries(font_test glload glutil glfw glmesh) 
