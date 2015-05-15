set(TARGET_NAME  ${aggregation_LIBNAME})

set(src_FILES
    aggregate.cpp
)

if(NOT ${USE_PREBUILT_LIB})
add_library(${TARGET_NAME} SHARED ${src_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_libraries(${TARGET_NAME} Qt5::Core)
install(TARGETS ${aggregation_LIBNAME} DESTINATION "lib")
else()
find_library(LIB
    NAMES Aggregation
    PATHS  /usr/lib/i386-linux-gnu/qtcreator/
)
if (LIB)
   message(STATUS "found library Aggregation")
    set(aggregation_LIBNAME ${LIB})
else()
   message(FATAL_ERROR "not found Library Aggregation")
endif()
endif()

add_subdirectory(examples)
