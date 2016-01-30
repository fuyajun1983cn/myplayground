OBJS = nih9_9.o \
rih9_10.o \
psih9_11.o \
pstd9_12.o \
pdih9_13.o \
pgrp9_14.o \
tbench.o \
vic.o


all : $(OBJS)
	armlink -o ../image/tbench.axf $(OBJS)

tbench.o : ../src/tbench.s
	armasm -g -o $@ $<

rih9_10.o : ../src/rih9_10.s
	armasm -g -o $@ $<

nih9_9.o : ../src/nih9_9.s
	armasm -g -o $@ $<
 
pdih9_13.o : ../src/pdih9_13.s
	armasm -g -o $@ $<
 
pgrp9_14.o : ../src/pgrp9_14.s
	armasm -g -o $@ $<
 
psih9_11.o : ../src/psih9_11.s
	armasm -g -o $@ $<
 
pstd9_12.o : ../src/pstd9_12.s
	armasm -g -o $@ $<
 
vic.o : ../src/vic.s
	armasm -g -o $@ $<
 
