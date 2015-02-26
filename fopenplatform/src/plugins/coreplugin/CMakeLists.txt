
qt5_wrap_ui(ui_FILES mainwindow.ui)

set(src_FILES
      mainwindow.cpp
     coreplugin.cpp
     plugindialog.cpp
     ${ui_FILES}
)

add_library(Core SHARED ${src_FILES})
target_link_libraries(Core Qt5::Widgets ${extensionsystem_LIBNAME})
install(TARGETS Core DESTINATION "lib/plugins")
install(FILES Core.xml DESTINATION "lib/plugins")
