cmake_minimum_required(VERSION 2.8.12)
project(miniui)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

set(src_FILES
    main.cpp
    device.cpp
)

add_executable(miniui ${src_FILES})
target_link_libraries(miniui Qt5::Widgets)
