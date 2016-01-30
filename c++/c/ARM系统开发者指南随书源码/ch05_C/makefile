# Makefile for chapter 5

CC=armcc -Otime -c
AS=armasm -cpu 5TE
LD=armlink -o

FILES=ch05test.o test.o test_s.o

ch05test.axf: $(FILES)
	$(LD) ch05test.axf $(FILES)

ch05test.o: ch05test.c
	$(CC) ch05test.c

test.o: test.c
	$(CC) test.c

test_s.o: test_s.s
	$(AS) test_s.s

clean:
	rm *.o *.axf
