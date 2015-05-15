if (USE_PREBUILT_LIB)
    message(STATUS "using prebuilt library")
else()
    message(STATUS "using library built from source")
endif()

add_subdirectory(aggregation)
add_subdirectory(extensionsystem)
