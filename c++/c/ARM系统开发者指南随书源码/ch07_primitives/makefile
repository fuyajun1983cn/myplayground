# Makefile for chapter 7

TCC=tcc -Otime -c
CC=armcc -Otime -c
AS=armasm -cpu 5TE
LD=armlink -o


FILES=ch07test.o bits.o div_a7m.o div_a9e.o gen.o mul.o norm.o \
rand.o ref_bits.o ref_div.o ref_mul.o ref_norm.o ref_root.o \
ref_sat.o ref_tran.o root.o sat.o tran.o

ch07test.axf: $(FILES)
	$(LD) ch07test.axf $(FILES)

ch07test.o: ch07test.c
	$(CC) ch07test.c

gen.o: gen.c
	$(CC) gen.c

ref_bits.o: ref_bits.c
	$(CC) ref_bits.c

ref_div.o: ref_div.c
	$(CC) ref_div.c

ref_mul.o: ref_mul.c
	$(CC) ref_mul.c

ref_norm.o: ref_norm.c
	$(CC) ref_norm.c

ref_root.o: ref_root.c
	$(CC) ref_root.c

ref_sat.o: ref_sat.c
	$(CC) ref_sat.c

ref_tran.o: ref_tran.c
	$(CC) ref_tran.c

bits.o: bits.s
	$(AS) bits.s

div_a7m.o: div_a7m.s
	$(AS) div_a7m.s

div_a9e.o: div_a9e.s
	$(AS) div_a9e.s

mul.o: mul.s
	$(AS) mul.s

norm.o: norm.s
	$(AS) norm.s

rand.o: rand.s
	$(AS) rand.s

root.o: root.s
	$(AS) root.s

sat.o: sat.s
	$(AS) sat.s

tran.o: tran.s
	$(AS) tran.s

clean:
	rm *.o *.axf

