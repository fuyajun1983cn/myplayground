project(glutil) 

if(UNIX)

include_directories(include source ../glload/include ../glm)
AUX_SOURCE_DIRECTORY(source glutil_SRC)

add_library(glutil SHARED ${glutil_SRC})
target_link_libraries(glutil GL GLU)

endif(UNIX)  
