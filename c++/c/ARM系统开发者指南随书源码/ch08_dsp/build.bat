armcc -Otime -c ch08test.c
armasm -cpu 5TE dot.s
armasm -cpu 5TE fft.s
armasm -cpu 5TE fir.s
armcc -Otime -c gen.c
armasm -cpu 5TE iir.s
armcc -Otime -c ref_dsp.c
armlink -o ch08test.axf ch08test.o dot.o fft.o fir.o gen.o iir.o ref_dsp.o
