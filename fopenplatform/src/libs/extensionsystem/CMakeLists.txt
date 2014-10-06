set(TARGET_NAME  ${extensionsystem_LIBNAME})

include_directories(${CMAKE_CURRENT_LIST_DIR}/../)

qt5_wrap_ui(ui_FILES plugindetailsview.ui pluginerroroverview.ui pluginerrorview.ui)
qt5_add_resources(qrc_FILES pluginview.qrc)

set(src_FILES
    iplugin.cpp
    invoker.cpp
    optionsparser.cpp
    plugincollection.cpp
    pluginmanager.cpp
    pluginspec.cpp
    plugindetailsview.cpp
    pluginerroroverview.cpp
    pluginerrorview.cpp
    pluginview.cpp
    ${ui_FILES}
    ${qrc_FILES}
)

if(NOT ${USE_PREBUILT_LIB})
add_library(${TARGET_NAME} SHARED ${src_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES VERSION 1.0.0 SOVERSION 1)
target_link_libraries(${TARGET_NAME} Qt5::Widgets ${aggregation_LIBNAME})
install(TARGETS ${extensionsystem_LIBNAME} DESTINATION "lib")
else()
find_library(LIB
    NAMES ExtensionSystem
    PATHS  /usr/lib/i386-linux-gnu/qtcreator/
)
if (LIB)
   message(STATUS "found library ExtensionSystem")
    set(extensionsystem_LIBNAME ${LIB})
else()
   message(FATAL_ERROR "not found Library ExtensionSystem")
endif()
endif()

add_subdirectory(test)
