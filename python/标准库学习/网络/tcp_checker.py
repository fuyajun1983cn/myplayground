#!/usr/bin/env python2

from __future__ import print_function
import socket
import re
import sys

def check_server(addr, port):
    #Create a TCP Socket
    s = socket.socket()
    print("Attemping to connect to %s on port %d" % (addr, port))
    try:
        s.connect((addr, port))
        print("Connecting to %s on port %d" %(addr, port))
        return True
    except socket.error, e:
        print("Connecting to %s on port %d failed" %(addr, port))
        return False

if __name__ == "__main__":
    from optparse import OptionParser
    parser = OptionParser()
    parser.add_option("-a", "--address", dest="address", default="localhost",
                      help="ADDRESS for server", metavar="ADDRESS")
    parser.add_option("-p", "--port", dest="port", default=80,
                      help="PORT for server", metavar="PORT")

    (options, args) = parser.parse_args()
    print("Optins: %s, Args: %s" %(options, args) )
    check = check_server(options.address, options.port)
    print("Check Server Returned: %s" %check)
    sys.exit(0)
