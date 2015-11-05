#/usr/bin/env python3
#encoding:utf-8

from shutil import *
from glob import glob
import os
from commands import *

print('BEFORE: ', glob('shuti*'))
copyfile('shutil_test.py', 'shutil_test.py.copy')
print("AFTER: ", glob('shutil*'))


os.mkdir('example')
print('BEFORE: ' + str(os.listdir('example')))
copy('shutil_test.py', 'example')
print('AFTER: ' + str(os.listdir('example')))


print('before: ')
print(getoutput('ls -rlast /tmp/example'))
copytree('.', '/tmp/example')
print('\nafter:')
print(getoutput('ls -rlast /tmp/example'))


