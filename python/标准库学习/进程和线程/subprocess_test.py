#/usr/bin/env python3
#encoding:utf-8

import subprocess
import os
import signal
import time
import sys

#The same as os.system('ls -l')
subprocess.call(['ls', '-l'])

#Command with shell expansion
subprocess.call('echo $HOME', shell=True)

#Error Handling
try:
    subprocess.check_call(['false'])
except subprocess.CalledProcessError as err:
    print('Error: {0}'.format(err))

#capture output
output = subprocess.check_output(['ls', '-l'])
print('Have %d bytes in output' % len(output))
print(output)

#working with Popen directly
print('read: ')
proc = subprocess.Popen(['echo', '"two stdout"'], stdout=subprocess.PIPE,)
stdout_value = proc.communicate()[0]
print('\tstdout: {0}'.format(stdout_value))

print('write:')
proc = subprocess.Popen(['cat', '-'], stdin=subprocess.PIPE)
proc.communicate('\tstdin: to stdin\n')

proc = subprocess.Popen(['cat', '-'], 
                         stdin=subprocess.PIPE,
                         stdout=subprocess.PIPE)
print('popen2: ')
msg = 'throught stdin to stdout'
stdout_value = proc.communicate(msg)[0]
print('\tpass through: ' + stdout_value)

print('popen3: ')
proc = subprocess.Popen('cat -; echo "to stderr" 1>&2',
                        shell=True,
                        stdin=subprocess.PIPE,
                        stdout=subprocess.PIPE,
                        stderr=subprocess.PIPE,
                        )
msg = 'through stdin to stdout'
stdout_value, stderr_value = proc.communicate(msg)
print('\tpass through: {0}'.format(stdout_value))
print('\tstderr: {0}'.format(stderr_value))


proc = subprocess.Popen(['python3', 'signal_child.py'])
print("PARENT   : Pausing before sending signanl...")
sys.stdout.flush()
time.sleep(1)
print("PARENT : Signaling child")

sys.stdout.flush()
os.kill(proc.pid, signal.SIGUSR1)

