#!/usr/bin/python
# -*- coding:utf8 -*-

import socket
from lxml import etree
import time

class XMLProtocol():
    def __init__(self, server_ip, server_port):
        self.server_ip = server_ip
        self.server_port = server_port
        self.msgXML = b'<msg id="vt.avkar.kiosk">'
        self.end_msgXML = b'</msg>\n\n'
        self.id = b"test_kiosk"
        self.slkey = None



    def big_header_xml(self, qtype, cmd, hall, secbegin, secend, sellnum):
        return b'<header><type>%s</type></device>%s</device><cmd>%</cmd><hall>%s</hall>' \
               b'<sec_index_begin>%s</sec_index_begin><sec_index_end>%s</sec_index_end>' \
               b'<cell_num>%s</cells_num></header>' % (qtype, self.id, cmd, hall, secbegin, secend, sellnum)

    def header_xml(self, qtype, cmd):
        return b"<header><type>%s</type><device>%s</device><cmd>%s</cmd></header>" % (qtype, self.id, cmd)

    def ping_xml(self):
        data = self.header_xml(b'query', b'ping')
        return b"%s%s%s" % (self.msgXML, data, self.end_msgXML)

    def infocard_xml(self, card):
        """

        :param card: уникальный номер считаной карты
        :return: запрос к MXL серверу получить информацию по карте
        """
        data = self.header_xml(b'query', b'get_card')
        return b'%s%s<data><card>%s</card></data>%s' % (self.msgXML, data, card, self.end_msgXML)

    def userstartses_xml(self, card):
        data = self.header_xml(b'query', b'auth')
        return b'%s%s<data><password>%s</password></data>%s' % (self.msgXML, data, card, self.end_msgXML)

    def userendses_xml(self, sessid):
        """

        :type sessid: id запущенной сессии
        """
        data = self.header_xml(u'query', u'quit')
        return b'%s%s<data><skey>%s</skey></data>%s' % (self.msgXML, data, sessid, self.end_msgXML)

    def sendCMD(self, cmd, *args):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.settimeout(1)
        self.sock.setblocking(1)
        try:
            self.sock.connect((self.server_ip, self.server_port))
        except socket.error as error:
            print u'error', error
            return error
        self.sock.send(cmd(*args))
        ret = self.sock.recv(1024**2)
        self.sock.close()
        tree = etree.XML(ret)
        cmd = tree.xpath('/msg/header/cmd')[0].text
        if cmd == 'auth':
            for node in tree.iterfind('.//skey'):
                self.skey = node.text
            if self.skey == None:
                return u'Error', None
            else:
                fio = tree.xpath('/msg/data/fio')[0].text
                return self.skey, fio
            return ret
        elif cmd == 'ping':
            return tree.xpath('/msg/header/free_cells/text()')[0], tree.xpath('/msg/header/free_cards')[0].text
        else:
            return ret


if __name__ == '__main__':
    serv_domodedovo = XMLProtocol('10.8.0.14', 7102)
    skey, fio = serv_domodedovo.sendCMD(serv_domodedovo.userstartses_xml, '99999')
    print '%s\n%s' % (skey, fio)
    print u'Свободных ячеек: %s\nСвободных карт: %s' % serv_domodedovo.sendCMD(serv_domodedovo.ping_xml)
    print serv_domodedovo.sendCMD(serv_domodedovo.userendses_xml, 9)
    #serv_domodedovo.sock.close()
