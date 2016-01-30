cd build\obj

armasm -o sand.o ..\src\sand.s
armlink  -o ..\image\sand.elf sand.o
fromelf -bin -o ..\image\rom.bin ..\image\sand.elf

cd ..\..
dir build\image
