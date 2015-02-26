add_executable(fopenplatform main.cpp)
target_link_libraries(fopenplatform Qt5::Widgets ${extensionsystem_LIBNAME})
install(TARGETS fopenplatform DESTINATION lib)
