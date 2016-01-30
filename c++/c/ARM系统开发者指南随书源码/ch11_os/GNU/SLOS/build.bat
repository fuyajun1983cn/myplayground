
cd build\obj & del *.o
cd ..\..\build\image & del *.elf
cd ..\..\build\image & del *.bin

cd ..\..\build\obj

arm-elf-as  -o start.o ..\src\start.s
arm-elf-as  -o init.o ..\src\e7t\init.s
arm-elf-as  -o pcb.o ..\src\e7t\pcb.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o swiapi.o ..\src\core\swiapi.c
arm-elf-as  -o undef.o ..\src\undef.s
arm-elf-as  -o swi.o ..\src\swi.s
arm-elf-as  -o prefetch.o ..\src\prefetch.s
arm-elf-as  -o data.o ..\src\data.s
arm-elf-as  -o reserved.o ..\src\reserved.s
arm-elf-as  -o irq.o ..\src\irq.s
arm-elf-as  -o fiq.o ..\src\fiq.s
arm-elf-as  -o scheduler.o ..\src\scheduler.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -O1 -c -o swi_handler.o ..\src\e7t\events\swi_handler.c
arm-elf-as  -o irq_handler.o ..\src\e7t\events\irq_handler.s
arm-elf-as  -o bringup.o ..\src\events\bringup.s
arm-elf-as  -o cpsr.o ..\src\events\cpsr.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o event_init.o ..\src\e7t\events\event_init.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o button_service.o ..\src\e7t\events\button_service.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o tick_service.o ..\src\e7t\events\tick_service.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o ddf_io.o ..\src\devices\ddf_io.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o led_driver.o ..\src\e7t\devices\led_driver.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o serial_driver.o ..\src\e7t\devices\serial_driver.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o segment_driver.o ..\src\e7t\devices\segment_driver.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o mutex.o ..\src\core\mutex.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o cinit.o ..\src\core\cinit.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o cli_com.o ..\src\core\cli_com.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o cli_readline.o ..\src\core\cli_readline.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o cli_shell.o ..\src\core\cli_shell.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o cli_serial.o ..\src\core\cli_serial.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o uid.o ..\src\core\uid.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o task1_start.o ..\src\apps\task1_start.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o task2_start.o ..\src\apps\task2_start.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o task3_start.o ..\src\apps\task3_start.c
arm-elf-ld -Map ..\image\map.dat  -o ..\image\slos.elf linker.dat
arm-elf-strip -O binary -o ..\image\slos.bin -s ..\image\slos.elf

cd ..\..
dir build\image