#!/usr/bin/env python
#encoding:utf-8

'''
  工具：从androidxref.com网站上批量下载代码
'''

import xml.dom.minidom
from HTMLParser import HTMLParser
import os
import sys
from urllib import urlopen
import threading
import re

default = xml.dom.minidom.parse("default.xml")
prefix = "http://androidxref.com/4.4.4_r1/"
xref_prefix = os.path.join(prefix, 'xref/')
raw_prefix = os.path.join(prefix, 'raw/')
local_prefix = "4.4.4"
error_paths = []

'''
获取Repository路径
'''
def parse_projects():
   paths = []
   for node in default.getElementsByTagName("project"):
        paths.append(node.getAttribute("path"))
   return paths

def fetch_remote_xref_file(path):
    try:
        remotefile = urlopen(os.path.join(xref_prefix, path))
    except IOError:
        error_paths.append(path)
        print "Error"
        return
    else:
        print "Sucess"
        filecontent = remotefile.read()
        remotefile.close()
        return filecontent

def fetch_remote_raw_file(path):
    try:
        remotefile = urlopen(os.path.join(raw_prefix, path))
    except IOError:
        error_paths.append(path)
        print "Error"
        return
    else:
        print "Sucess"
        filecontent = remotefile.readlines()
        remotefile.close()
        localfile_path = os.path.join(local_prefix, path)
        local_dir = os.path.dirname(localfile_path)
        if not os.path.exists(local_dir):
            os.makedirs(local_dir)
        localfile = open(localfile_path, 'w') 
        for line in filecontent:
            localfile.write(line+'\n')
        localfile.close()


def is_file(path):
    return path[-1] != '/'

def get_android_source(path):
    _path = path
    if is_file(path):
        fetch_remote_raw_file(_path)
    else:
        pass


exclude_paths= ['/4.4.4_r1/', '/4.4.4_r1/xref/',
                'http://www.opensolaris.org/os/project/opengrok/',
                'http://www.apache.org/licenses/LICENSE-2.0',
                'http://www.bootchart.org',
                '..']
class AndroidXrefHTMLParser(HTMLParser):
    def __init__(self,prefix):
        self.prefix = prefix 
        self.paths = []
        HTMLParser.__init__(self)
    def handle_starttag(self, tag, attrs):
        if tag == 'a':
            for name, value in attrs:
                if name == 'href' and value not in exclude_paths :
                    if is_file(value):
                        reg = re.compile(r'#\d+')
                        if re.match(reg, value) != None:
                            continue
                        print "downloading path: {0}".format(os.path.join(raw_prefix, self.prefix, value))
                        fetch_remote_raw_file(os.path.join(self.prefix, value))
                        print "finished"
                    else:
                        values = value.split('/')
                        if "4.4.4_r1" in values or "docs" in values or "http:" in values: 
                            continue
                        self.paths.append(os.path.join(self.prefix, value)) 
                        
    def set_prefix(self, prefix):
        self.prefix = prefix

def download_code(path):
    parser = AndroidXrefHTMLParser(path)
    parser.feed(fetch_remote_xref_file(parser.prefix))

    while len(parser.paths) != 0:
        parser.set_prefix(parser.paths[0])
        parser.paths = parser.paths[1:]
        parser.feed(fetch_remote_xref_file(parser.prefix)) 

class FetchAndroidSourceCode(threading.Thread):
    def __init__(self, path):
        threading.Thread.__init__(self)
        self.path = path

    def run(self):
        download_code(self.path)

if __name__ == "__main__":
    print "getting sourcecode from androidxref.com"
   # paths = parse_projects()
    paths = ['frameworks/base', 'frameworks/native', 'frameworks/av', 'system/core', 'system/extras', 'system/media', 'system/netd', 'system/security', 'system/vold', 'hardware/libhardware', 'hardware/libhardware_legacy' ]
    for path in paths:
        print path
        t = FetchAndroidSourceCode(path)
        t.start()
        t.join()
  #  fetch_remote_raw_file('frameworks/native/NOTICE')
    
    
