#!/usr/bin/env python3

import logging
import logging.config

def smain():
    #configure the logging system
    logging.config.fileConfig('logconfig.ini')
    
    hostname = 'www.python.org'
    item = 'spam'
    filename = 'data.csv'
    mode = 'r'

    logging.critical('Host %s unkown', hostname)
    logging.error("Couldn't find %r", item)
    logging.warning('Feature is deprecated')
    logging.info('Opening file %r, mode = %r', filename, mode)
    logging.debug('Got here')

if __name__ == '__main__':
    smain()

