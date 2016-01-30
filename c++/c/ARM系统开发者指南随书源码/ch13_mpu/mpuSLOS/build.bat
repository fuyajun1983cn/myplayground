cd build\obj\apps\task1

armcc -c -o led.o ..\..\..\src\apps\task1\led.c
armcc -c -o start.o ..\..\..\src\apps\task1\start.c
armlink -first start.o -entry entry -ro 0x20000 -o ..\..\..\image\apps\task1.elf led.o start.o 
fromelf -bin -o ..\..\..\image\apps\task1.bin ..\..\..\image\apps\task1.elf

cd ..\task2
armcc -c -o led.o ..\..\..\src\apps\task2\led.c
armcc -c -o start.o ..\..\..\src\apps\task2\start.c
armlink -first start.o -entry entry -ro 0x28000 -o ..\..\..\image\apps\task2.elf led.o start.o 
fromelf -bin -o ..\..\..\image\apps\task2.bin ..\..\..\image\apps\task2.elf

cd ..\task3
armcc -c -o start.o    ..\..\..\src\apps\task3\start.c
armcc -c -o serial.o   ..\..\..\src\apps\task3\serial.c
armcc -c -o com.o      ..\..\..\src\apps\task3\com.c
armcc -c -o shell.o    ..\..\..\src\apps\task3\shell.c
armcc -c -o readline.o ..\..\..\src\apps\task3\readline.c
armlink -first start.o -entry entry -ro 0x30000 -o ..\..\..\image\apps\task3.elf start.o serial.o com.o shell.o readline.o
fromelf -bin -o ..\..\..\image\apps\task3.bin ..\..\..\image\apps\task3.elf

cd ..\..
armasm -o start.o ..\src\start.s
armasm -o undef.o ..\src\undef.s
armasm -o swi.o ..\src\swi.s
armasm -o prefetch.o ..\src\prefetch.s
armasm -o data.o ..\src\data.s
armasm -o reserved.o ..\src\reserved.s
armasm -o irq.o ..\src\irq.s
armasm -o fiq.o ..\src\fiq.s
armasm -o scheduler.o ..\src\scheduler.s
armasm -o mpu.o ..\src\memory\mpu.s
armcc -c -o mem_init.o ..\src\memory\mem_init.c
armasm -o async.o ..\src\memory\async.s
armcc -c -o swi_handler.o ..\src\cm940iap\events\swi_handler.c
armasm -o bringup.o ..\src\events\bringup.s
armasm -o cpsr.o ..\src\events\cpsr.s
armasm -o irq_handler.o ..\src\cm940iap\events\irq_handler.s
armcc -c -o events_init.o ..\src\cm940iap\events\events_init.c
armcc -c -o tick_service.o ..\src\cm940iap\events\tick_service.c
armcc -c -o ddf_io.o ..\src\devices\ddf_io.c
armcc -c -o led_driver.o ..\src\cm940iap\devices\led_driver.c
armcc -c -o serial_driver.o ..\src\cm940iap\devices\serial_driver.c
armcc -c -o cinit.o ..\src\core\cinit.c
armcc -c -o uid.o ..\src\core\uid.c
armasm -o jump.o ..\src\core\jump.s
armasm -o init.o ..\src\cm940iap\init.s
armasm -o mpupcb.o ..\src\cm940iap\mpupcb.s
armasm -o sal.o ..\src\sal.s
armlink -first start.o -ro 0x0 -o ..\image\slos.elf start.o undef.o swi.o prefetch.o data.o reserved.o irq.o fiq.o scheduler.o mpu.o mem_init.o async.o swi_handler.o bringup.o cpsr.o irq_handler.o events_init.o tick_service.o ddf_io.o led_driver.o serial_driver.o cinit.o uid.o jump.o init.o mpupcb.o sal.o
fromelf -bin -o ..\image\slos.bin ..\image\slos.elf

cd ..\..
dir build\image
