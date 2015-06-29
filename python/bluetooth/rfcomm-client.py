#!/usr/bin/env python
# -*- coding: utf-8 -*-

from bluetooth import *

server_address = "01:23:45:67:89:AB"
port = 1

sock = BluetoothSocket(RFCOMM)
sock.connect((server_address, port))
sock.send("Hello!")
sock.close()
