#!/usr/bin/python
# -*- coding:utf-8 -*-
import bcd
import serial
import datetime
import time
ERROR_FR={'0x1a':u'Команда не поддерживается в данном режиме',\
            '0x0':u'Ошибок нет',\
            '0x1':u'Нет номера ККМ',\
            '0xa':u'Отъебись я занят'}
hour=datetime.datetime.now().hour
minut=datetime.datetime.now().minute
#year=datetime.datetime.now().year

ser = serial.Serial('/dev/ttyUSB0',115200,writeTimeout=0.5, timeout=0.5,stopbits=serial.STOPBITS_ONE, parity=serial.PARITY_NONE)
kassa = bcd.Kasbi(ser, 0x00)
print ERROR_FR[hex(ord(kassa.ZReport()[2]))]
time.sleep(2)
print ERROR_FR[hex(ord(kassa.CurenTime(hour,minut)[2]))]
kassa.conn.close()

