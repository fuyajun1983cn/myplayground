#/usr/bin/env python3
#encoding:utf-8
import threading
import time
import logging

logging.basicConfig(level=logging.DEBUG,
                    format='(%(threadName)-10s) %(message)s',)
#Timer Thread
def delayed():
    logging.debug('workeer running')
    return

t1 = threading.Timer(3, delayed)
t1.setName('t1')
t2 = threading.Timer(3, delayed)
t2.setName('t2')

logging.debug('starting timers')
t1.start()
t2.start()

logging.debug('waiting before canceling %s', t2.getName())
time.sleep(2)
logging.debug('canceling %s', t2.getName())
t2.cancel()
logging.debug('done')

#signaling between Threads
def wait_for_event(e):
    logging.debug('wait_for_event starting')
    event_is_set = e.wait()
    logging.debug('event set: %s', event_is_set)

def wait_for_event_timeout(e, t):
    while not e.isSet():
        logging.debug('wait_for_event_timeout starting')
        event_is_set = e.wait(t)
        logging.debug('event set: %s', event_is_set)
        if event_is_set:
            logging.debug('processing event')
        else:
            logging.debug('doing other work')

e = threading.Event()
t1 = threading.Thread(name = 'block', target = wait_for_event, args=(e,))
t1.start()

t2 = threading.Thread(name = "nonblock", target = wait_for_event_timeout,
        args=(e, 2))
t2.start()


logging.debug('Waiting before calling Event.set()')
time.sleep(3)
e.set()
logging.debug('Event is set')


#threading.Lock
#Re-entrant Lock: threading.RLock
lock = threading.Lock()
logging.debug('First try :', lock.acquire())
logging.debug('Second try:', lock.acquire(0))

def worker_with(lock):
    with lock:
        logging.debug("Lock acquired via with")

def woker_no_with(lock):
    lock.acquire()
    logging.debug("Lock acquired directly")
    lock.release()

lock = threading.Lock()
w = threading.Thread(target=worker_with, args=(lock,))
nw = threading.Thread(target=woker_no_with, args=(lock,))

w.start()
nw.start()

#threading.Condition
def consumer(cond):
    logging.debug('comsumer threading is starting')
    thread = threading.currentThread()
    with cond:
        cond.wait()
        logging.debug('resource is available to consumer')

def producer(cond):
    logging.debug('producer threading is starting')
    thread = threading.currentThread()
    with cond:
        logging.debug("making resource available")
        con.notifyAll()

condition = threading.Condition()
c1 = threading.Thread(name = 'c1', target = comsumer, args=(condition,))
c2 = threading.Thread(name = 'c2', target=comsumer, args=(condition,))
p1 = threading.Thread(name = 'p1', target = producer, args=(condition,))
c1.start()
time.sleep(2)
c2.start()
time.sleep(2)
p1.start()

#threading.Semaphore



#thread local: threading.local



