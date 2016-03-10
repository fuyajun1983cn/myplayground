#!/usr/bin/env python3
#encoding:utf-8
import os
import sys
import sqlite3



BASE_WIFI                   = 0x00020000   #131072
BASE_WIFI_WATCHDOG          = 0x00021000   #135168
BASE_WIFI_P2P_MANAGER       = 0x00022000   #139264
BASE_WIFI_P2P_SERVICE       = 0x00023000   #143360
BASE_WIFI_MONITOR           = 0x00024000   #147456
BASE_WIFI_MANAGER           = 0x00025000   #151552
BASE_WIFI_CONTROLLER        = 0x00026000   #155648
BASE_WIFI_SCANNER           = 0x00027000   #159744
BASE_WIFI_SCANNER_SERVICE   = 0x00027100   #160000
BASE_WIFI_RTT_MANAGER       = 0x00027200   #160256
BASE_WIFI_RTT_SERVICE       = 0x00027300   #160512
BASE_WIFI_PASSPOINT_MANAGER = 0x00028000   #163840
BASE_WIFI_PASSPOINT_SERVICE = 0x00028100   #164096


BASE = BASE_WIFI_SCANNER_SERVICE
WifiScanner_Cmds = {
'CMD_SCAN_RESULTS_AVAILABLE'              : BASE + 0,
'CMD_FULL_SCAN_RESULTS'                   : BASE + 1,
'CMD_HOTLIST_AP_FOUND'                    : BASE + 2,
'CMD_HOTLIST_AP_LOST'                     : BASE + 3,
'CMD_WIFI_CHANGE_DETECTED'                : BASE + 4,
'CMD_WIFI_CHANGES_STABILIZED'             : BASE + 5,
'CMD_DRIVER_LOADED'                       : BASE + 6,
'CMD_DRIVER_UNLOADED'                     : BASE + 7,
'CMD_SCAN_PAUSED'                         : BASE + 8,
'CMD_SCAN_RESTARTED'                      : BASE + 9,
}

db_filename = 'test.db'
schema_sqlfile = 'test.sql'

db_is_new = not os.path.exists(db_filename)


def InitDB():
    with sqlite3.connect(db_filename) as conn:
        if db_is_new:
            print("Creating schema")
            with open(schema_sqlfile, 'rt') as f:
                schema = f.read()
            try:
                conn.executescript(schema)
            except sqlite2.OperationalError:
                import atexit
                atexit.register(os.unlink, db_filename)
        else:
            print('Datebase exists, no need to create.')


def InsertWifiCommand(id, name):
    #init db if not existent
    InitDB()
 
    with sqlite3.connect(db_filename) as conn:
        print("Inserting Wifi command")
        curs = conn.cursor()
        try:
            curs.execute('insert into wifi_info(command_id, command_name) values(?, ?)', (id, name))
        except sqlite2.OperationalError:
            pass
        else:
            print("{0} rows has been added.".format(curs.rowcount))
            conn.commit()

def QueryWifiCommand(id):

    with sqlite3.connect(db_filename) as conn:
        print("Querying wifi command " + id)
        curs = conn.cursor()
        try:
            curs.execute('select command_name from wifi_info where command_id = ?', (id,))
        except sqlite3.OperationalError:
            print("Command Error")
        else:
            command_name = curs.fetchone()
            if command_name is not None:
                return command_name[0]
            else:
                print("No such command")

def DeleteWifiCommand(command_name):

    with sqlite3.connect(db_filename) as conn:
        print("Deleting wifi command " + id)
        curs = conn.cursor()
        try:
            curs.execute('delete from wifi_info where command_name = ?', (command_name,))
        except sqlite3.OperationalError:
            print("Command Error")
        else:
            conn.commit()

def UpdateWifiCommand(id, name):

    with sqlite3.connect(db_filename) as conn:
        print("Updating wifi command " + id)
        curs = conn.cursor()
        try:
            curs.execute('update wifi_info set command_name = ? where command_id = ?', (name, id))
        except sqlite3.OperationalError:
            print("Command Error")
        else:
            conn.commit()


def Test():
    for command_name, command_id in WifiScanner_Cmds.items():
        print("Key: {0}, Value: {1}".format(command_id,command_name))
        InsertWifiCommand(command_id, command_name)



if __name__ == '__main__':

#    Test()

   if len(sys.argv) == 4:
       if sys.argv[1] == 'Insert':
          InsertWifiCommand(sys.argv[2], sys.argv[3])
       elif sys.argv[1] == 'Update':
          UpdateWifiCommand(sys.argv[2], sys.argv[3])
       else:
          print("Invalid Command!")
   elif len(sys.argv) == 3:
       if sys.argv[1] == 'Query':
           command_name = QueryWifiCommand(sys.argv[2])
           if command_name is not None:
               print("Command Name: " + command_name)
       elif sys.argv[1] == 'Delete':
           DeleteWifiCommand(sys.argv[2])
       else:
           print("Invalid Command!")
   else:
       print("Only support Insert, Update, Query, Dele:e Operations")



