set(aggregation_LIBNAME "Aggregation")
set(extensionsystem_LIBNAME "ExtensionSystem")

include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/)

add_subdirectory(libs)
add_subdirectory(plugins)
add_subdirectory(app)
