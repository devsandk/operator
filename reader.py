__author__ = 'asus'
import serial
import array
import time 


class Reader:

    def __init__(self, port='/dev/ttyUSB0'):
        self.port = port
        self.data = None
        self.conn = serial.Serial(self.port, 9600, timeout=1)

    def get_card(self):
        self.conn.write(array.array('B', [0xfd, 0x00, 0x01, 0x0e, 0x6a, 0x36, 0xfe]).tostring())
        self.conn.read(10)
        self.conn.write(array.array('B', [0xfd, 0x00, 0x02, 0x07, 0x00, 0x00, 0x02, 0x34, 0x95, 0xfe]).tostring())
        self.conn.read(8)
        self.conn.write(array.array('B', [0xfd,0x00,0x03,0x43,0x3b,0x9c,0xfe]).tostring())
        self.data = self.conn.read(19)
       # self.conn.read(8)
        self.conn.write(array.array('B', [0xfd,0x00,0x04,0x07,0x02,0x01,0x00, 0xde, 0x21, 0xfe]).tostring())
       # self.conn.read(8)
       # self.conn.write(array.array('B', [0xfd,0x00,0x05,0x0e,0x0a,0x51,0xfe]).tostring())
       # self.conn.read(10)
       # self.conn.write(array.array('B', [0xfd,0x00,0x06,0x0e,0x62,0x7b,0xfe]).tostring())
       # self.conn.read(10)
       # self.conn.write(array.array('B', [0xfd,0x00,0x07,0x43,0x5b,0xfb,0xfe]).tostring())
       # self.data = self.conn.read(19)
       # self.conn.write(array.array('B', [0xfd,0x00,0x08,0x05,0x01,0x2d,0x55, 0xfe]).tostring())
       # self.conn.read(9)
       # self.conn.write(array.array('B', [0xfd,0x00,0x09,0x07,0x02,0x01,0x00,0xaa,0x5d, 0xfe]).tostring())
        self.conn.read()
        self.conn.close()
        return self.data

    def get_card_num(self):
        a = ''
        data = ''
        a = self.get_card()
        if len(a)<19:
            return u'None_data'
        for i in range(len(a[9:-3])):
            ch = str(hex(ord(a[i+9])))[2:]
            if len(ch) < 2:
                ch = '0' + ch
            data += ch
        return data
if __name__=="__main__":
    cardread = Reader()
    print cardread.get_card_num()







