#!/usr/bin/env python3

import logging

#For libraries that want to perform logging, you should create a dedicated logger object
log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())


def func():
    log.Critical('A Critical Error!')
    log.debug('A debug message')
    
