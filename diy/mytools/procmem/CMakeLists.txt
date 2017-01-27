cmake_minimum_required(VERSION 2.8)
project(procmem)

include_directories(${CURRENT_PROJECT_DIR})

set(procmem_SRC
    "pm_kernel.c"
    "pm_map.c"
    "pm_memusage.c"
    "pm_process.c"
    "procmem.c")

add_executable(procmem ${procmem_SRC})
