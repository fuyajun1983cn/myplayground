rem set CORE=XScale
set CORE=ARM920T

armcc -c -O1 -g+ -cpu %CORE% cacheTest.c -o cacheTest.o
armasm -g -cpu %CORE% enableCache.s -o enableCache.o
armasm -g -cpu %CORE% flushcache.s -o flushcache.o
armasm -g -cpu %CORE% cleancachebyway.s -o cleancachebyway.o
armasm -g -cpu %CORE% cleancachebytest.s -o cleancachebytest.o
armasm -g -cpu %CORE% cleancachexscale.s -o cleancachexscale.o
armasm -g -cpu %CORE% cleanflushcacheregion.s -o cleanflushcacheregion.o
armasm -g -cpu %CORE% lockcachebyway.s -o lockcachebyway.o
armasm -g -cpu %CORE% lockcachebyLbit.s -o lockcachebyLbit.o
armasm -g -cpu %CORE% lockcachebyregion.s -o lockcachebyregion.o
armcc -c -O1 -g+ -cpu %CORE% main.c -o main.o
armlink -entry main.o -o cache.axf cacheTest.o enableCache.o flushcache.o cleancachebyway.o cleancachebytest.o cleancachexscale.o cleanflushcacheregion.o lockcachebyway.o lockcachebyLbit.o lockcachebyregion.o main.o
