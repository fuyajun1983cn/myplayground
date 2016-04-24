#!/usr/bin/env python3
#encoding:utf-8

'''
根据关键字，截取Log中的重要信息供分析问题
目前主要针对P2P连接的Log进行分析
'''

import re

##定义Log文件和输出文件
log_file_name="./test.log"
output_log_file_name = log_file_name + "_supplicant.log"


##Pattern Strings

include_strings_regx = [
    re.compile(r'wpa_supplicant')    ,
]
excluded_strings_regx = [
    re.compile(r'wlan0'),
    re.compile(r'hexdump'),
    re.compile(r'\ *WPS:\ *')
]

##
WPS_SUCCESS = re.compile(r'WPS-SUCCESS')
P2P_GROUP_FORMATION_SUCCESS = re.compile(r'P2P-GROUP-FORMATION-SUCCESS')
FOURC_WAY_HANDSHAKE_SUCCESS = re.compile(r'Key negotiation completed with')
GROUP_STARTED=re.compile(r'P2P-GROUP-STARTED')

def is_include_string(str, patterns):
    for reg in patterns:
        if reg.search(str) is not None:
            return True

    return False

def parse_info(str):
    if GROUP_STARTED.search(str) is not None:
        print("P2P Group Stared!\n")
        return

    if FOURC_WAY_HANDSHAKE_SUCCESS.search(str) is not None:
        print("4-Way handshke is OK\n")
        return

    if P2P_GROUP_FORMATION_SUCCESS.search(str) is not None:
        print("Group formation succeeded\n")
        return

    if WPS_SUCCESS.search(str) is not None:
        print("WPS succeeded\n")
        return

log_file = open(log_file_name)
output_log_file = open(output_log_file_name, 'w')

try:
    for line in log_file:
        ##filter out wpa_supplicant log
        if is_include_string(line, include_strings_regx) and not is_include_string(line, excluded_strings_regx):
            parse_info(line)
            output_log_file.write(line)
except UnicodeDecodeError:
    pass

#for line in log_file.readlines():
#    if supplicant_tag.search(line) is not None:
#        output_log_file.write(line)


## close files
log_file.close()
output_log_file.close()

