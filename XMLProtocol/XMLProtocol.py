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
        return b'<header><type>%s</type><device>%s</device><cmd>%s</cmd><hall>%s</hall>' \
               b'<sec_index_begin>%s</sec_index_begin><sec_index_end>%s</sec_index_end>' \
               b'<cell_num>%s</cell_num></header>' % (qtype, self.id, cmd, hall, secbegin, secend, sellnum)

    def header_xml(self, qtype, cmd):
        """

        :rtype : object
        """
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

    def auth_xml(self, card):
        data = self.header_xml(b'query', b'auth')
        return b'%s%s<data><password>%s</password></data>%s' % (self.msgXML, data, card, self.end_msgXML)

    def auth_adm_xml(self, card):
        data = self.header_xml(b'query', b'auth_adm')
        return b'%s%s<data><password>%s</password></data>%s' % (self.msgXML, data, card, self.end_msgXML)

    def quit_xml(self, sessid):
        """

        :type sessid: id запущенной сессии
        """
        data = self.header_xml(u'query', u'quit')
        return b'%s%s<data><skey>%s</skey></data>%s' % (self.msgXML, data, sessid, self.end_msgXML)

    def get_card_xml(self, card):
        data = self.header_xml(b'query', b'get_card')
        return b'%s%s<data><card>%s</card></data>%s' % (self.msgXML, data, card, self.end_msgXML)

    def get_cells_xml(self, hall, secbegin, secend):
        data = self.big_header_xml(b'query', b'get_cells', hall, secbegin, secend, 0)
        return b'%s%s%s' % (self.msgXML, data, self.end_msgXML)

    def get_cells0_xml(self, hall, cellnum):
        data = self.big_header_xml(b'query', b'get_cells', hall, 0, 0, cellnum)
        return b'%s%s%s' % (self.msgXML, data, self.end_msgXML)

    def try_card_xml(self, card, sec_num, cell_index):
        data = self.header_xml(b'query', b'try_card')
        return b'%s%s<data><card>%s</card><sec_num>%s</sec_num><cell_index>%s</cell_index></data>%s' % \
               (self.msgXML, data, card, sec_num, cell_index, self.end_msgXML)

    def buy_card_xml(self, card, btime, sum, kkmses, kkmcheck, sec_num, cell_index):
        data = self.header_xml(b'query', b'buy_card')
        return b'%s%s<data><card>%s</card><btime>%s</btime><sum>%s</sum><kkmses>%s</kkmses><kkmcheck>%s' \
               b'</kkmcheck><sec_num>%s</sec_num><cell_index>%s</cell_index></data>%s' % \
               (self.msgXML, data, card, btime, sum, kkmses, kkmcheck, sec_num, cell_index, self.end_msgXML)

    def add_pay_xml(self, card, btime, sum, kkmses, kkmcheck,):
        data = self.header_xml(b'query', b'add_pay')
        return b'%s%s<data><card>%s</card><btime>%s</btime><sum>%s</sum><kkmses>%s</kkmses>' \
               b'<kkmcheck>%s</kkmcheck></data>%s' % \
               (self.msgXML, data, card, btime, sum, kkmses, kkmcheck, self.end_msgXML)

    def return_card_xml(self, card, btime, sum, kkmses, kkmcheck):
        data = self.header_xml(b'query', b'return_card')
        return b'%s%s<data><card>%s</card><btime>%s</btime><sum>%s</sum><kkmses>%s</kkmses>' \
               b'<kkmcheck>%s</kkmcheck></data>%s' % \
               (self.msgXML, data, card, btime, sum, kkmses, kkmcheck, self.end_msgXML)

    def get_rate_xml(self):
        print  b'%s%s%s' % (self.msgXML, self.header_xml(b'query', b'get_rate'), self.end_msgXML)
        return b'%s%s%s' % (self.msgXML, self.header_xml(b'query', b'get_rate'), self.end_msgXML)
        
    def try_return_xml(self, card):
        data = b'%s%s' % (b'query', b'try_return')
        return b'%s<data><card>%s</card></data>%s' % (self.msgXML, data, card, self.end_msgXML)

    def add_rate_xml(self, sum, rate):
        data = b'%s%s' % (b'query', b'add_rate')
        return b'%s<data><rate_sum>%s</rate_sum><rdate_div>%s</rate_div></data>%s' % (self.msgXML, sum, rate, self.end_msgXML)

    def get_user_xml(sekf):
        return b'%s%s%s%s' % (self.msgXML, u'query', b'get_user', self.end_msgXML)

    def sendCMD(self, cmd, *args):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.settimeout(1)
        self.sock.setblocking(1)
        try:
            self.sock.connect((self.server_ip, self.server_port))
        except socket.error as error:
            print u'error', error
            return error
        self.sock.send(getattr(self, cmd)(*args))
        total_data = []
        while True:
            data = self.sock.recv(1024)
            if not data:
                break
            total_data.append(data)
        ret = ''.join(total_data)
        self.sock.close()
        tree = etree.XML(ret)
        cmd = tree.xpath('/msg/header/cmd')[0].text
        if cmd == 'auth':
            for node in tree.iterfind('.//skey'):
                self.skey = node.text
            if self.skey is None:
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
    skey, fio = serv_domodedovo.sendCMD('auth_xml', '99999')
    #print '%s\n%s' % (skey, fio)
   # print u'Свободных ячеек: %s\nСвободных карт: %s' % serv_domodedovo.sendCMD('ping_xml')
    print serv_domodedovo.sendCMD('get_card_xml', '66992E81550034')
    print serv_domodedovo.sendCMD('get_cells_xml', 1, 11,20)
   # print serv_domodedovo.sendCMD('get_rate_xml')
   # print serv_domodedovo.sendCMD('quit_xml', skey)
  #  print serv_domodedovo.sendCMD('auth_adm_xml', '6638BD81360034')
  #  print serv_domodedovo.sendCMD('get_rate_xml')
    print serv_domodedovo.sendCMD('quit_xml', skey)
