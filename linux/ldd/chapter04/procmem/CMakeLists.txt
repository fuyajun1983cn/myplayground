configure_file(${ldd_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
compile_module(procmem scull)
compile_module(procmem2 scull2)

