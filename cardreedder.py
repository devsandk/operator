__author__ = 'asus'
import array
import serial

conn = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)

data = array.array('B', [0xfd, 0x00, 0x01, 0x0e, 0x6a, 0x36, 0xfe]).tostring()
conn.write(data)
c=conn.read(10)
card=''
for i in range(len(c)):
    card+=" "+str(hex(ord(c[i])))
print card
data = array.array('B', [0xfd, 0x00, 0x02, 0x10, 0xff, 0x02, 0xef, 0xfe]).tostring()
conn.write(data)
print conn.read(9)
data = array.array('B', [0xfd, 0x00, 0x03, 0x0e, 0xda, 0x05, 0xfe]).tostring()
conn.write(data)
print conn.read(10)
data = array.array('B', [0xfd, 0x00, 0x04, 0x43, 0x33, 0xd1, 0xfe]).tostring()
conn.write(data)
c=conn.read(19)
card=''
for i in range(len(c)):
    card+=" "+str(hex(ord(c[i])))

print card
conn.close()
