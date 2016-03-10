cd Debug

make clean 

make

export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

./sone --dfb=system=x11,no-debug,no-vt-switch
