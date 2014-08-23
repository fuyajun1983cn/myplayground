file(GLOB PROGS "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

foreach(prog ${PROGS})
  get_filename_component(EXE_NAME ${prog} NAME_WE)
  add_executable(${EXE_NAME} ${prog})
endforeach()

