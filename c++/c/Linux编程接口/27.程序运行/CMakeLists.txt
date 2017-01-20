cmake_minimum_required(VERSION 2.8)
project(test)

set(lib_SRC "../lib/error_functions.c"
            "../lib/get_num.c")

include_directories("../lib")

add_executable(envargs envargs.c ${lib_SRC})
add_executable(t_execve t_execve.c ${lib_SRC})
add_executable(t_execlp t_execlp.c ${lib_SRC})
add_executable(t_execle t_execle.c ${lib_SRC})
add_executable(t_execl t_execl.c ${lib_SRC})
add_executable(closeonexec closeonexec.c ${lib_SRC})
