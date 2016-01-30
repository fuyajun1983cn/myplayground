armcc -Otime -c ch05test.c
armcc -Otime -c test.c
armasm -cpu 5TE test_s.s
armlink -o ch05test.axf ch05test.o test.o test_s.o
