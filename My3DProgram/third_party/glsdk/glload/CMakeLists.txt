project(glload) 

if(UNIX)

add_definitions(-DLOAD_X11)
include_directories(include source)

set(glload_SRC
    source/gll_c.c
    source/gll_cpp.cpp
    source/gll_gl_ext.c
    source/glxl_ext.c
    )

add_library(glload SHARED ${glload_SRC})
target_link_libraries(glload GL GLU)

endif(UNIX)  
