
cls

cd build\obj\apps\task1 & del *.o
cd ..\..\..\..\build\obj\apps\task2 & del *.o
cd ..\..\..\..\build\obj\apps\task3 & del *.o	
cd ..\..\..\..\build\obj & del *.o

cd ..\..\build\obj\apps\task1

arm-elf-as  -o start.o ..\..\..\src\apps\task1\start.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o led.o ..\..\..\src\apps\task1\led.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o startx.o ..\..\..\src\apps\task1\startx.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o swiapi.o ..\..\..\src\apps\task1\swiapi.c
arm-elf-ld -Map ..\..\..\image\map1.dat  -o ..\..\..\image\apps\task1.elf linker.dat
arm-elf-strip -O binary -o ..\..\..\image\apps\task1.bin -s ..\..\..\image\apps\task1.elf

cd ..\..\..\..\build\obj\apps\task2

arm-elf-as  -o start.o ..\..\..\src\apps\task2\start.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o led.o ..\..\..\src\apps\task2\led.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o startx.o ..\..\..\src\apps\task2\startx.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o swiapi.o ..\..\..\src\apps\task2\swiapi.c
arm-elf-ld -Map ..\..\..\image\map2.dat  -o ..\..\..\image\apps\task2.elf linker.dat
arm-elf-strip -O binary -o ..\..\..\image\apps\task2.bin -s ..\..\..\image\apps\task2.elf

cd ..\..\..\..\build\obj\apps\task3

arm-elf-as  -o start.o ..\..\..\src\apps\task3\start.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o serial.o ..\..\..\src\apps\task3\serial.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o com.o ..\..\..\src\apps\task3\com.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o shell.o ..\..\..\src\apps\task3\shell.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o readline.o ..\..\..\src\apps\task3\readline.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o swiapi.o ..\..\..\src\apps\task3\swiapi.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o startx.o ..\..\..\src\apps\task3\startx.c
arm-elf-ld -Map ..\..\..\image\map.dat  -o ..\..\..\image\apps\task3.elf linker.dat
arm-elf-strip -O binary -o ..\..\..\image\apps\task3.bin -s ..\..\..\image\apps\task3.elf

cd ..\..\..\..\build\obj

arm-elf-as  -o start.o ..\src\start.s
arm-elf-as  -o undef.o ..\src\undef.s
arm-elf-as  -o swi.o ..\src\swi.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o swiapi.o ..\src\core\swiapi.c
arm-elf-as  -o prefetch.o ..\src\prefetch.s
arm-elf-as  -o data.o ..\src\data.s
arm-elf-as  -o reserved.o ..\src\reserved.s
arm-elf-as  -o irq.o ..\src\irq.s
arm-elf-as  -o fiq.o ..\src\fiq.s
arm-elf-as  -o scheduler.o ..\src\scheduler.s
arm-elf-as  -o mmu.o ..\src\memory\mmu.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o util.o ..\src\memory\util.c
arm-elf-as  -o async.o ..\src\memory\async.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -O1 -c -o swi_handler.o ..\src\cm920iap\events\swi_handler.c
arm-elf-as  -o bringup.o ..\src\events\bringup.s
arm-elf-as  -o cpsr.o ..\src\events\cpsr.s
arm-elf-as  -o irq_handler.o ..\src\cm920iap\events\irq_handler.s
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o events_init.o ..\src\cm920iap\events\events_init.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o tick_service.o ..\src\cm920iap\events\tick_service.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o ddf_io.o ..\src\devices\ddf_io.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o led_driver.o ..\src\cm920iap\devices\led_driver.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o serial_driver.o ..\src\cm920iap\devices\serial_driver.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o cinit.o ..\src\core\cinit.c
arm-elf-gcc -mapcs -fomit-frame-pointer -O1 -c -o uid.o ..\src\core\uid.c
arm-elf-as  -o jump.o ..\src\core\jump.s
arm-elf-as  -o init.o ..\src\cm920iap\init.s
arm-elf-as  -o mmupcb.o ..\src\cm920iap\mmupcb.s
arm-elf-as  -o sal.o ..\src\sal.s
arm-elf-ld -Map ..\image\map.dat  -o ..\image\mmuslos.elf linker.dat
arm-elf-strip -O binary -o ..\image\mmuslos.bin -s ..\image\mmuslos.elf

cd ..\..
dir build\image
