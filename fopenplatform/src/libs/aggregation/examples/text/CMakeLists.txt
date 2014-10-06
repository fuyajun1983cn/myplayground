add_definitions(-DAGGREGATION_LIBRARY)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../..)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

qt5_wrap_ui(ui_FILES main.ui)
qt5_wrap_cpp(moc_FILES myinterfaces.h)

add_executable(text main.cpp ${ui_FILES} ${moc_FILES})
target_link_libraries(text Qt5::Core Qt5::Widgets ${aggregation_LIBNAME})

install(TARGETS text DESTINATION "lib")
