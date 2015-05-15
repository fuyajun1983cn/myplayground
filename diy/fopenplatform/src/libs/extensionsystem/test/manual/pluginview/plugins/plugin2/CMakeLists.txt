add_library(plugin2 SHARED plugin2.cpp)
target_link_libraries(plugin2 ${extensionsystem_LIBNAME})
install(TARGETS plugin2 DESTINATION "lib/plugins")
install(FILES plugin2.xml DESTINATION "lib/plugins")
