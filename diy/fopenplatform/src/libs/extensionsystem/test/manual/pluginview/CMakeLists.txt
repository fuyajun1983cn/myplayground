include_directories(${CMAKE_CURRENT_LIST_DIR}/../../../../)

add_executable(test plugindialog.cpp)
message(STATUS "library : ${extensionsystem_LIBNAME}")
target_link_libraries(test Qt5::Widgets ${extensionsystem_LIBNAME})
install(TARGETS test DESTINATION "lib")

add_subdirectory(plugins)
