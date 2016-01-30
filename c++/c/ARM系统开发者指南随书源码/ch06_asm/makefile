# Makefile for chapter 7

TCC=tcc -Otime -c
CC=armcc -Otime -c
AS=armasm -cpu 5TE
LD=armlink -o

ALL: ch06test.axf main1.axf main2.axf main3.axf main4.axf

# Example 6.1 is built as main1.axf

main1.axf: main1.c square.s
	$(CC) main1.c
	$(AS) square.s
	$(LD) main1.axf main1.o square.o

# Example 6.2 is built as main2.axf

main2.axf: main1.c square2.s
	$(TCC) main1.c
	$(AS) -apcs /interwork square2.s
	$(LD) main2.axf main1.o square2.o

# Example 6.3 is built as main3.axf

main3.axf: main3.s
	$(AS) main3.s
	$(LD) main3.axf main3.o

# Example 6.4 is built as main4.axf

main4.axf: main4.c sumof.s
	$(CC) main4.c
	$(AS) sumof.s
	$(LD) main4.axf main4.o sumof.o

# Other chapter 6 examples are built in ch06test.axf

FILES=ch06test.o bitstream.o matrix.o memset.o merge.o ref.o shift.o \
switch.o tolower.o unalign.o

ch06test.axf: $(FILES)
	$(LD) ch06test.axf $(FILES)

ch06test.o: ch06test.c
	$(CC) ch06test.c

ref.o: ref.c
	$(CC) ref.c

bitstream.o: bitstream.s
	$(AS) bitstream.s

matrix.o: matrix.s
	$(AS) matrix.s

memset.o: memset.s
	$(AS) memset.s

merge.o: merge.s
	$(AS) merge.s

shift.o: shift.s
	$(AS) shift.s

switch.o: switch.s
	$(AS) switch.s

tolower.o: tolower.s
	$(AS) tolower.s

unalign.o: unalign.s
	$(AS) unalign.s

clean:
	rm *.o *.axf

