#!/usr/bin/python
# -*- coding: utf8 -*-

import sys

from PyQt4.QtCore import *
from PyQt4.QtGui import *
from PyQt4.QtWebKit import *
import sys
import os
import socket
import time
import subprocess
import ksbfrdrv
import serial
import datetime
import locale
import array
from reader import Reader
import xml.etree.ElementTree as ET
from XMLProtocol import XMLProtocol
from lxml import etree



pyDir = os.path.abspath(os.path.dirname(__file__))
baseUrl = QUrl.fromLocalFile(os.path.join(pyDir, "img/"))
proto = XMLProtocol.XMLProtocol('10.8.0.14', 7102)

class Config:
    def __init__(self, config='config/config.xml'):
        self.xml = etree.parse(config)
        self.multiserver = self.xml.xpath('/config/servers')[0].attrib['multiserver']
        self.multipay = self.xml.xpath('/config/servers')[0].attrib['multipay']
        count = int(self.xml.xpath('/config/servers')[0].attrib['count'])
        self.node = []
        for i in range(count):
            self.node.append(XMLProtocol.XMLProtocol(
                self.xml.xpath('/config/servers/node')[i].attrib['net_address'],
                int(self.xml.xpath('/config/servers/node')[i].attrib['port'])
            ))

    def getserver(self, id):
        return self.node[id]

    def getbeetrow(self, id):
        min_row, max_row = self.xml.xpath('/config/servers/node')[id].attrib['begin_row'], \
        self.xml.xpath('/config/servers/node')[id].attrib['end_row']
        return (int(min_row), int(max_row))




proto = Config()
print proto.getserver(0).sendCMD('ping_xml')

class Foo(QObject):
    #@pyqtSlot(int, result=int)
    @pyqtSlot(int, result=str)
    def ping(self, serverid):
        data = u'<msg><header><type>answer</type><free_cells>%s</free_cells>' \
               u'<free_card>%s</free_card></header></msg>' % proto.getserver(serverid).sendCMD('ping_xml')
        print data
        return data
    @pyqtSlot(result=str)
    def getcard(self):
        reader = Reader()
        return '%s'%reader.get_card_num()

    @pyqtSlot(str, str, str,int, result=str)
    def get_cells(self, hall, secbegin, secend, serverid):
        smin, smax = proto.getbeetrow(serverid)
        begin = secbegin
        end = secend
        if int(begin) < smin:
            begin = str(smin)
            end = str(smin+9)
            print begin, end
        if int(end) > smax:
            end = str(smax)
            begin = str(smax-9)
            print begin, end
        result = proto.getserver(serverid).sendCMD('get_cells_xml', hall, begin, end)
        print result
        return result

    @pyqtSlot()
    def quit(self):
        QApplication.quit()

    @pyqtSlot(result=str)
    def setdatetime(self):
       # locale.setlocale(locale.LC_ALL, 'ru_RU.UTF-8')
        date = datetime.datetime.now()
        date = datetime.datetime.strftime(date, u'<msg><date><day>%d</day><month>%m</month>\
                                                <year>%Y</year></date><time>%H:%M</time></msg>')
        return date

class Window(QWidget):
    def __init__(self):
        super(Window, self).__init__()
        view = QWebView(self)
        layout = QVBoxLayout(self)
        layout.addWidget(view)
        layout.setMargin(0)
        self.setStyleSheet("border:10px solid rgb(0, 255, 0);")
        self.setFixedSize(1024, 768)
        self.setGeometry(0, 0, 0, 0)
        self.setWindowFlags(Qt.FramelessWindowHint)
        self.proto = XMLProtocol.XMLProtocol('10.8.0.14', 7102)
        self.foo = Foo(self)
        view.page().mainFrame().addToJavaScriptWindowObject("foo", self.foo)
        html = open('template.html', 'r')
        html = html.read().decode('utf-8')

        view.setHtml(html, baseUrl)

def main():
    app = QApplication(sys.argv)
    window = Window()
    window.show()
    app.exec_()

if __name__ == "__main__":
    main()