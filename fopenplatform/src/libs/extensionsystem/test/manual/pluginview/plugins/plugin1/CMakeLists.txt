add_library(plugin1 SHARED plugin1.cpp)
target_link_libraries(plugin1 ${extensionsystem_LIBNAME})
install(TARGETS plugin1 DESTINATION "lib/plugins")
install(FILES plugin1.xml DESTINATION "lib/plugins")
