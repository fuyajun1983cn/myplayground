set CORE=ARM940T

armcc -c -O1 -g+ -cpu %CORE%  main.c -o main.o
armcc -c -O1 -g+ -cpu %CORE%  mpu.c -o mpu.o
armlink main.o mpu.o  -o mpu.axf
