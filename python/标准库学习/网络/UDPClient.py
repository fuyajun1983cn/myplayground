#!/usr/bin/env python3
#coding:utf-8

from socket import *

serverName ='localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input('请输入小写字母语句：')
#sockets by themselves always
#deal in binary byte strings, not text.
#need use the two methods to convert between them
#str.encode  from text to byte strings
#bytes.decode from byte strings to text
clientSocket.sendto(message.encode(), (serverName, serverPort))
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print(modifiedMessage.decode())
clientSocket.close()
