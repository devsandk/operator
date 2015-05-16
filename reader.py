__author__ = 'asus'
import serial
import array
import time 

def getcard():
    data=None
    conn = serial.Serial('/dev/ttyUSB1', 9600, timeout=1)
    conn.write(array.array('B', [0xfd, 0x00, 0x01, 0x0e, 0x6a, 0x36, 0xfe]).tostring())
    conn.read(10)
    conn.write(array.array('B', [0xfd, 0x00, 0x02, 0x07, 0x00, 0x01, 0x02, 0xec, 0x8c, 0xfe]).tostring())
    conn.read(8)
    conn.write(array.array('B', [0xfd,0x00,0x03,0x05,0x01,0x8b,0x7c,0xfe]).tostring())
    conn.read(8)
    conn.write(array.array('B', [0xfd,0x00,0x04,0x10,0x2d,0xb1,0xfe]).tostring())
    conn.read(8)
    conn.write(array.array('B', [0xfd,0x00,0x05,0x0e,0x0a,0x51,0xfe]).tostring())
    conn.read(10)
    conn.write(array.array('B', [0xfd,0x00,0x06,0x0e,0x62,0x7b,0xfe]).tostring())
    conn.read(10)
    conn.write(array.array('B', [0xfd,0x00,0x07,0x43,0x5b,0xfb,0xfe]).tostring())
    data = conn.read(19)
    conn.write(array.array('B', [0xfd,0x00,0x08,0x05,0x01,0x2d,0x55, 0xfe]).tostring())
    conn.read(9)
    conn.write(array.array('B', [0xfd,0x00,0x09,0x07,0x02,0x01,0x00,0xaa,0x5d, 0xfe]).tostring())
    conn.read()
    conn.close()
    return data

def getcarnum():
    a=''
    while len(a)<19:
        a=getcard()
    data=''
    for i in range(len(a[9:-3])):
        ch=str(hex(ord(a[i+9])))[2:]
        if len(ch)<2:
            ch='0'+ch
        data+=ch
    return data
if __name__=="__main__":
    print getcarnum()







