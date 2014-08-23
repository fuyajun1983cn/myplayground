project(Lorenz)

add_executable(Lorenz lorenz.c)
target_link_libraries(Lorenz freeglut)
