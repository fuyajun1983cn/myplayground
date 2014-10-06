add_library(plugin3 SHARED plugin3.cpp)
target_link_libraries(plugin3 ${extensionsystem_LIBNAME})
install(TARGETS plugin3 DESTINATION "lib/plugins")
install(FILES plugin3.xml DESTINATION "lib/plugins")
