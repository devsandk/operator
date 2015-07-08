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



pyDir = os.path.abspath(os.path.dirname(__file__))
baseUrl = QUrl.fromLocalFile(os.path.join(pyDir, "img/"))
proto = XMLProtocol.XMLProtocol('10.8.0.14', 7102)

class Foo(QObject):
    #@pyqtSlot(int, result=int)
    @pyqtSlot(result=str)
    def ping(self):
        data = u'<msg><header><type>answer</type><free_cells>%s</free_cells>' \
               u'<free_card>%s</free_card></header></msg>' % proto.sendCMD('ping_xml')
        print data
        return data
    @pyqtSlot(result=str)
    def getcard(self):
        reader = Reader()
        return '%s'%reader.get_card_num()

    @pyqtSlot(str, str, str, result=str)
    def get_cells(self, hall, secbegin, secend):
        result = proto.sendCMD('get_cells_xml', hall, secbegin, secend)
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