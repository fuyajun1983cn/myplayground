#/usr/bin/env python3
#encoding:utf-8

import linecache
import os

#looking for the linecache module , using 
#the built in sys.path search
module_line = linecache.getline('linecache.py', 3)
print('MODULE: ')
print(repr(module_line))

#look at the linecache module source directory
file_src = linecache.__file__
if file_src.endswith('.pyc'):
    file_src = file_src[:-1]

print('\nFILE:')
with open(file_src, 'r') as f:
    file_line = f.readlines()[2]

print(repr(file_line))


