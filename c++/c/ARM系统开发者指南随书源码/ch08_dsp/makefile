# Makefile for chapter 8

TCC=tcc -Otime -c
CC=armcc -Otime -c
AS=armasm -cpu 5TE
LD=armlink -o


FILES=ch08test.o dot.o fft.o fir.o gen.o iir.o ref_dsp.o

ch08test.axf: $(FILES)
	$(LD) ch08test.axf $(FILES)

ch08test.o: ch08test.c
	$(CC) ch08test.c

gen.o: gen.c
	$(CC) gen.c

ref_dsp.o: ref_dsp.c
	$(CC) ref_dsp.c

dot.o: dot.s
	$(AS) dot.s

fft.o: fft.s
	$(AS) fft.s

fir.o: fir.s
	$(AS) fir.s

iir.o: iir.s
	$(AS) iir.s

clean:
	rm *.o *.axf

