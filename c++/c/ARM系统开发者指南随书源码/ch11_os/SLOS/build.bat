
cd build\obj

armasm -o start.o ..\src\start.s
armasm -o init.o ..\src\e7t\init.s
armasm -o pcb.o ..\src\e7t\pcb.s
armasm -o undef.o ..\src\undef.s
armasm -o swi.o ..\src\swi.s
armasm -o prefetch.o ..\src\prefetch.s
armasm -o data.o ..\src\data.s
armasm -o reserved.o ..\src\reserved.s
armasm -o irq.o ..\src\irq.s
armasm -o fiq.o ..\src\fiq.s
armasm -o scheduler.o ..\src\scheduler.s
armcc -c -o swi_handler.o ..\src\e7t\events\swi_handler.c
armasm -o irq_handler.o ..\src\e7t\events\irq_handler.s
armasm -o bringup.o ..\src\events\bringup.s
armasm -o cpsr.o ..\src\events\cpsr.s
armcc -c -o event_init.o ..\src\e7t\events\event_init.c
armcc -c -o button_service.o ..\src\e7t\events\button_service.c
armcc -c -o tick_service.o ..\src\e7t\events\tick_service.c
armcc -c -o ddf_io.o ..\src\devices\ddf_io.c
armcc -c -o led_driver.o ..\src\e7t\devices\led_driver.c
armcc -c -o serial_driver.o ..\src\e7t\devices\serial_driver.c
armcc -c -o segment_driver.o ..\src\e7t\devices\segment_driver.c
armcc -c -o mutex.o ..\src\core\mutex.c
armcc -c -o cinit.o ..\src\core\cinit.c
armcc -c -o cli_com.o ..\src\core\cli_com.c
armcc -c -o cli_readline.o ..\src\core\cli_readline.c
armcc -c -o cli_shell.o ..\src\core\cli_shell.c
armcc -c -o cli_serial.o ..\src\core\cli_serial.c
armcc -c -o uid.o ..\src\core\uid.c
armcc -c -o task1_start.o ..\src\apps\task1_start.c
armcc -c -o task2_start.o ..\src\apps\task2_start.c
armcc -c -o task3_start.o ..\src\apps\task3_start.c
armlink -first start.o -ro 0x0 -o ..\image\slos.elf start.o init.o pcb.o undef.o swi.o prefetch.o data.o reserved.o irq.o fiq.o scheduler.o swi_handler.o irq_handler.o bringup.o cpsr.o event_init.o button_service.o tick_service.o ddf_io.o led_driver.o serial_driver.o segment_driver.o mutex.o cinit.o cli_com.o cli_readline.o cli_shell.o cli_serial.o uid.o task1_start.o task2_start.o task3_start.o
fromelf -bin -o ..\image\slos.bin ..\image\slos.elf
cd ..\..
dir build\image
