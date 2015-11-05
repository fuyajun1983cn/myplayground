#!/usr/bin/env python3

import logging


def smain():
    #configure the logging system
    # can only be run once
    logging.basicConfig(
        filename = 'app.log',
        level = logging.ERROR,
        format='%(levelname)s:%(asctime)s:%(message)s'
        )

    hostname = 'www.python.org'
    item = 'spam'
    filename = 'data.csv'
    mode = 'r'

    logging.critical('Host %s unkown', hostname)
    logging.error("Couldn't find %r", item)
    logging.warning('Feature is deprecated')
    logging.getLogger().level = logging.DEBUG
    logging.info('Opening file %r, mode = %r', filename, mode)
    logging.debug('Got here')

if __name__ == '__main__':
    smain()

