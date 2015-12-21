#!/usr/bin/env python3

"""
Created on Sun Aug 24 22:02:49 2014

@author: fuyajun

"""

import os
import inspect

#获取当前脚本所处的目录
scriptDir = os.path.dirname(inspect.getfile(inspect.currentframe()))

#获取当前脚本的完整路径
currentScriptfile =__file__

#获取当前脚本的文件名
currentScriptFileName =os.path.basename( currentScriptfile)

print(scriptDir)
print(currentScriptfile)
print(currentScriptFileName)
print(os.path.abspath(currentScriptfile))
