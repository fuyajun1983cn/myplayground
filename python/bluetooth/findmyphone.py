#!/usr/bin/env python
# -*- coding: utf-8 -*-

from bluetooth import *

target_name = "HUAWEI U9508"
target_address = None

'''
@param duration: 控制扫描设备的超时时间。1.28s * duration(8, by default)
@param flush_cache: False 默认情况下，扫描到的蓝牙设备的地址会缓存几分钟，
　　　　　　　　　　　　可能返回的是缓存的设备地址
                    True 将实时扫描附近蓝牙设备的地址
'''
nearby_devices = discover_devices(duration=8 , flush_cache=True)

for address in nearby_devices:
	if target_name == lookup_name(address, timeout = 10):
		target_address = address;
		break;

if target_address is not None:
	print "找到目标蓝牙设备，地址为 : " + target_address
else:
	print "附近无法找到目标蓝牙设备。"

