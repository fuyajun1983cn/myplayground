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
GO_NEG_SUCCESS = re.compile(r'P2P-GO-NEG-SUCCESS')
EAP_STARTED = re.compile(r'CTRL-EVENT-EAP-STARTED')
SEND_M1 = re.compile(r'Building Message M1')
SEND_M2 = re.compile(r'Building Message M2')
SEND_M3 = re.compile(r'Building Message M3')
SEND_M4 = re.compile(r'Building Message M4')
SEND_M5 = re.compile(r'Building Message M5')
SEND_M6 = re.compile(r'Building Message M6')
SEND_M7 = re.compile(r'Building Message M7')
SEND_M8 = re.compile(r'Building Message M8')
SEND_Done = re.compile(r'Building Message WSC_Done')
RECV_M1 = re.compile(r'Received M1')
RECV_M2 = re.compile(r'Received M2')
RECV_M3 = re.compile(r'Received M3')
RECV_M4 = re.compile(r'Received M4')
RECV_M5 = re.compile(r'Received M5')
RECV_M6 = re.compile(r'Received M6')
RECV_M7 = re.compile(r'Received M7')
RECV_M8 = re.compile(r'Received M8')
RECV_Done = re.compile(r'Received WSC_Done')
WPS_SUCCESS = re.compile(r'WPS-SUCCESS')
P2P_GROUP_FORMATION_SUCCESS = re.compile(r'P2P-GROUP-FORMATION-SUCCESS')
SEND_EAPOL_KEY_1_of_4 = re.compile(r'Sending EAPOL-Key 1/4')
SEND_EAPOL_KEY_2_of_4 = re.compile(r'Sending EAPOL-Key 2/4')
SEND_EAPOL_KEY_3_of_4 = re.compile(r'Sending EAPOL-Key 3/4')
SEND_EAPOL_KEY_4_of_4 = re.compile(r'Sending EAPOL-Key 4/4')
RECV_EAPOL_KEY_1_of_4 = re.compile(r'RX message 1 of 4-Way Handshake')
RECV_EAPOL_KEY_2_of_4 = re.compile(r'RX message 2 of 4-Way Handshake')
RECV_EAPOL_KEY_3_of_4 = re.compile(r'RX message 3 of 4-Way Handshake')
RECV_EAPOL_KEY_4_of_4 = re.compile(r'RX message 4 of 4-Way Handshake')
FOURC_WAY_HANDSHAKE_SUCCESS = re.compile(r'Key negotiation completed with')
GROUP_STARTED=re.compile(r'P2P-GROUP-STARTED')

def is_include_string(str, patterns):
    for reg in patterns:
        if reg.search(str) is not None:
            return True

    return False

def parse_info(str):
    if GO_NEG_SUCCESS.search(str) is not None:
        print("P2P GO Negotiation Success!\n")
        return

    if EAP_STARTED.search(str) is not None:
        print("CTRL-EVENT-EAP-STARTED EAP authentication started\n")
        return

    if SEND_M1.search(str) is not None:
        print("Send M1\n")
        return

    if RECV_M1.search(str) is not None:
        print("Received M1\n")
        return

    if SEND_M2.search(str) is not None:
        print("Send M2\n")
        return

    if RECV_M2.search(str) is not None:
        print("Received M2\n")
        return

    if SEND_M3.search(str) is not None:
        print("Send M3\n")
        return

    if RECV_M3.search(str) is not None:
        print("Received M3\n")
        return

    if SEND_M4.search(str) is not None:
        print("Send M4\n")
        return

    if RECV_M4.search(str) is not None:
        print("Received M4\n")
        return

    if SEND_M5.search(str) is not None:
        print("Send M5\n")
        return

    if RECV_M5.search(str) is not None:
        print("Received M5\n")
        return

    if SEND_M6.search(str) is not None:
        print("Send M6\n")
        return

    if RECV_M6.search(str) is not None:
        print("Received M6\n")
        return

    if SEND_M7.search(str) is not None:
        print("Send M7\n")
        return

    if RECV_M7.search(str) is not None:
        print("Received M7\n")
        return

    if SEND_M8.search(str) is not None:
        print("Send M8\n")
        return

    if RECV_M8.search(str) is not None:
        print("Received M8\n")
        return

    if SEND_Done.search(str) is not None:
        print("Send WSC_Done\n")
        return

    if RECV_Done.search(str) is not None:
        print("Received WSC_Done\n")
        return
    
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

