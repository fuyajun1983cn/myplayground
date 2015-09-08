#!/usr/bin/env python3
#encoding:utf-8

import os
import os.path
import time

print("os.sep: " + os.sep)
print("os.extsep: " + os.extsep)
print("os.pardir: " + os.pardir)
print("os.curdir: " + os.curdir)

for path in ['/one/two/three', 
             '/one/two/three/', 
             '/path/to/filename.txt',
             '/',
             '.',
             '']:
    print("%15s : %s" %(path, os.path.split(path)))
    print("%15s : %s" %(path, os.path.dirname(path)))
    print("%21s : %s" %(path, os.path.splitext(path)))

paths = ['/one/two/three/four', 
'/one/two/threefold',
'/one/two/three/'
]
for path in paths:
    print('PATH:', path)

print()
print('PREFIX: ', os.path.commonprefix(paths))


#expandvars, expandusers
os.environ['NAME']='fuyajun'
print(os.path.expandvars('/path/to/$NAME'))
print(os.path.expanduser("~/fuyajun"))


#normal path
print(os.path.normpath('.././'))

#abs path
print(os.path.abspath('.'))

#file time
print("Current File: " + __file__)
print("Access Time: " + time.ctime(os.path.getatime(__file__)))
print("Modified Time: " + time.ctime(os.path.getmtime(__file__)))
print("Changed Time: " + time.ctime(os.path.getctime(__file__)))
print("Size : " , os.path.getsize(__file__))

print("Absolute: ", os.path.isabs(__file__))
print("Is File? ", os.path.isfile(__file__))
print("Is Dir? ", os.path.isdir(__file__))
print("Is Link? ", os.path.islink(__file__))
print("MountPoint? ", os.path.ismount(__file__))
print("Exists? ", os.path.exists(__file__))




