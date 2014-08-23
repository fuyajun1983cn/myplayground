project(glimg) 

if(UNIX)

find_package(OpenGL REQUIRED)
include_directories(include source ../glload/include)
AUX_SOURCE_DIRECTORY(source glimg_SRC)

add_library(glimg SHARED ${glimg_SRC})
target_link_libraries(glimg ${OPENGL_LIBRARIES} glload)

endif(UNIX) 
