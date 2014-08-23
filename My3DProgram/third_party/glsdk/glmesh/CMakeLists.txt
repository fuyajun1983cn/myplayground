project(glmesh) 

if(UNIX)

include_directories(include source ../glload/include ../glm)
AUX_SOURCE_DIRECTORY(source glmesh_SRC)

add_library(glmesh STATIC ${glmesh_SRC})

endif(UNIX)  
 
