project(spaceball)

add_executable(spaceball spaceball.c vmath.c)
target_link_libraries(spaceball freeglut)
