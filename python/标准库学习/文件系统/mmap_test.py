#/usr/bin/env python3
#encoding:utf-8

import mmap
import contextlib

with open('lorem.txt', 'r') as f:
    with contextlib.closing(mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)) as m:
            print('First 10 bytes via read : {0}'.format(m.read(10)))
            print('First 10 bytes via slice: {0}'.format(m[:10]))
            print('2nd 10 bytes via read: {0}'.format(m.read(10)))


