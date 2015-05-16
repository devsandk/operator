#!/usr/bin/python
# -*- coding: utf8 -*-

PASSWORD = 0x00
ID = 0x00
PORT = '/dev/ttyUSB0'
import serial
import time
import array
from struct import pack, unpack


def CalcKs_id(id=ID):
    ks_id = ~id
    ks_id &= 0xff
    return ks_id

KS_ID = CalcKs_id()
FR_CP = 'cp866'


def bcd(password=PASSWORD, lon=4):
    pas_list = []
    for i in range(1, lon, 2):
        pas_list.insert(0, ((((password/10**i) % 10) << 4)+((password/10**(i-1)) % 10)))
    return pas_list


class Kasbi:
    def __init__(self, conn, password=PASSWORD, frid=ID):
        """

        :param conn:
        :param password:
        :param frid:
        """
        self.conn = conn
        self.password = bcd(password)
        self.frid = frid
        self.ks_id = CalcKs_id(frid)
        self.conn.open()
    
    def addComand(self, code, long_data, data=[], c_password=0):
        #if len(data)==0:
        #    for i in range(long_data):
        #        data.append(0)
        #print data
        self.data_array=[self.frid, self.ks_id]+self.password+[code, long_data]+bcd(c_password, 6)+data
        self.CRC=0x00
        #print self.data_array
        for i in self.data_array:
            self.CRC += i
        self.data_array.append(~self.CRC & 0xff)
        if not self.conn.isOpen():
            return False
        ret = []
        #rrint self.data_array
        self.conn.write(array.array('B', self.data_array).tostring())
        ret.append(self.conn.readline())
        return ret[0]

    def ShortState(self):
        return self.addComand(0x01, 3)

    def XReport(self):
        return self.addComand(26, 3)
    
    def ZReport(self):
        return self.addComand(27, 3)

    def CurenTime(self, hors, minutes):
        data=[]
        data.append(bcd(hors, 2)[0])
        data.append(bcd(minutes, 2)[0])
        return self.addComand(0x26, 5, data)

    def Print_string(self, href=0, string=''):
       # string =string.encode('cp866') 
        if string > 40:
            string = string[:40]
        result = []
        result.append(href)
        for x in string:
           result.append(ord(x.encode('cp866')))
        if len(result) < 41:
            for i in range(41-len(result)):
                result.append(ord(' '.encode('cp866')))
        return self.addComand(0x11, 44, result)

    def Print_service_doc(self):
        return self.addComand(0x15, 3)
    
    def float2int(self, f, digits=2):
        mask = '%.'+str(digits)+'f'
        st = mask % f
        return int(st.replace('.', ''))
    
    def openChek(self, corr=0, ctype=0):
        return self.addComand(0x0b, 5, [corr, ctype])

    def Sale(self, price, count, tgroup=1, sec=1, discount=0, rate_discount=0, summ_rate_disc=0, tax0=0, tax1=0, tax2=0, tax3=0, string='', corr=0):
        #string = string.encode('cp866')
        if string > 37:
            string = string[:37]
        price = pack('l', self.float2int(price, 2))
        count = pack('l', self.float2int(count, 3))
        rate_discount = pack('h', self.float2int(rate_discount, 2))
        summ_rate_disc = pack('l', self.float2int(summ_rate_disc, 2))
        data = [corr]
        print array.array('B', count)
        for x in array.array('B', count).tostring():
            data.append(ord(x))
        for x in array.array('B', price).tostring():
            data.append(ord(x))
        data.extend([tgroup, sec, discount])
        for x in array.array('B', rate_discount).tostring():
            data.append(ord(x))
        for x in array.array('B', summ_rate_disc).tostring():
            data.append(ord(x))
        data.extend([tax0, tax1, tax2, tax3])
        for x in string:
            data.append(ord(x))
        if len(string) < 37:
            for i in range(37-len(string)):
                data.append(ord(' '.encode('cp866')))
        print len(data), data[1], data
        return self.addComand(0x06, 62, data)

    def closeChek(self,summ0=0,summ1=0,summ2=0,summ3=0,discount=0,rate_discount=0,summ_rate_disc=0,corr=0):
        data=[corr]
        summ0=pack('l', self.float2int(summ0, 2))
        summ1=pack('l', self.float2int(summ1, 2))
        summ2=pack('l', self.float2int(summ2, 2))
        summ3=pack('l', self.float2int(summ3, 2))
        summ=summ0+summ1+summ2+summ3
        rate_discount=pack('h', self.float2int(rate_discount, 2))
        summ_rate_disc=pack('l', self.float2int(summ_rate_disc, 2))
        for x in array.array('B', summ).tostring():
            data.append(ord(x))
        data.append(discount)
        for x in array.array('B', rate_discount).tostring():
            data.append(ord(x))
        for x in array.array('B', summ_rate_disc).tostring():
            data.append(ord(x))
        return self.addComand(0x0c, 27, data)

    def openCashDrawer(self):
        return self.addComand(0x04, 3)




if __name__=="__main__":
    ERROR_FR={'0x1a':u'Команда не поддерживается в данном режиме',\
            '0x0':u'Ошибок нет',\
            '0x1':u'Нет номера ККМ',\
            '0xa':u'Отъебись я занят',\
            '0x22':u'Переполнение диапазона количества',\
            '0x3d':u'Нет ни одной покупки'}

    ser = serial.Serial('/dev/ttyUSB0',115200, timeout=0.5)
    kassa = Kasbi(ser, 0x00,0)
    #kassa.CurenTime(17,02)
    #kassa.Print_string(0, u'You Мыло ')
    #kassa.Print_service_doc()
    #kassa.ZReport()
    #kassa.XReport()
    print ERROR_FR[hex(ord(kassa.openChek()[2]))]
    print ERROR_FR[hex(ord(kassa.Sale(9, 1)[2]))]
    #kassa.openCashDrawer()
    print ERROR_FR[hex(ord(kassa.closeChek(99)[2]))]
    kassa.conn.close()
       
