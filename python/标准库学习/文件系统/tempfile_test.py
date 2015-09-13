#/usr/bin/env python3
#encoding:utf-8

import tempfile
import os

#the file returned by TemporaryFile() has no name
print("TemporaryFile: ")
temp = tempfile.TemporaryFile();
try:
    print("temp: ")
    print('    ', temp)
    print('temp.name:')
    print('   ', temp.name)
finally:
#Automatically clean up the file
    temp.close()

with tempfile.TemporaryFile() as temp:
    temp.write('Some data')
    temp.seek(0)

    print(temp.read())

#open file in text mode
with tempfile.TemporaryFile(mode='w+t') as f:
    f.writelines(['first\n', 'sencond\n'])
    f.seek(0)

    for line in f:
        print(line.rstrip())

with tempfile.NamedTemporaryFile() as temp:
    print('temp:')
    print('    ' , temp)
    print('temp.name: '  + temp.name)

#temporay direcotry
directory_name = tempfile.mkdtemp()
print(directory_name)
os.removedirs(directory_name)

#predict the name
# dir + prefix + random + suffix
with tempfile.NamedTemporaryFile(suffix='_suffix', prefix='prefix_',
        dir='/tmp',) as temp:
    print('temp: ', temp)
    print('temp.name: ' + temp.name)

#temp file location
print('gettempdir(): ' + tempfile.gettempdir())
print('gettempprefix():' + tempfile.gettempprefix())





