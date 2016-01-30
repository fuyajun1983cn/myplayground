del *.o *.axf

set CORE=ARM920T
rem set CORE=ARM970T
armcc -c -O1 -g+ -cpu %CORE% mmuRoutines.c -o mmuRoutines.o
armcc -c -O1 -g+ -cpu %CORE% main.c -o main.o
armlink mmuRoutines.o main.o -ro-base 0x10000 -o mmu.axf
