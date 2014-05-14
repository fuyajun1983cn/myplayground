include_directories(../../freeglut/include ../../glload/include )
add_executable(caustics dino.c underwater.c texload.c)
target_link_libraries(caustics freeglut glload)
