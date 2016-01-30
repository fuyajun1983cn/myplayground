armcc -Otime -c ch06test.c
armasm -cpu 5TE bitstream.s
armasm -cpu 5TE matrix.s
armasm -cpu 5TE memset.s
armasm -cpu 5TE merge.s
armcc -Otime -c ref.c
armasm -cpu 5TE shift.s
armasm -cpu 5TE switch.s
armasm -cpu 5TE tolower.s
armasm -cpu 5TE unalign.s
armlink -o ch06test.axf ch06test.o bitstream.o matrix.o memset.o merge.o ref.o shift.o switch.o tolower.o unalign.o
armcc -Otime -c main1.c
armasm -cpu 5TE square.s
armlink -o main1.axf main1.o square.o
tcc -Otime -c main1.c
armasm -cpu 5TE -apcs /interwork square2.s
armlink -o main2.axf main1.o square2.o
armasm -cpu 5TE main3.s
armlink -o main3.axf main3.o
armcc -Otime -c main4.c
armasm -cpu 5TE sumof.s
armlink -o main4.axf main4.o sumof.o
