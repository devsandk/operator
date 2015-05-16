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
import reader


class Reader():
    def __init__(self):
        self.serial = serial.Serial('/dev/ttyUSB0', 9600)




from twisted.internet import reactor
from twisted.internet.protocol import Protocol, ClientCreator

pyDir = os.path.abspath(os.path.dirname(__file__))
baseUrl = QUrl.fromLocalFile(os.path.join(pyDir, "img/"))

class XMLClient(Protocol):
   def sendMessage(self, msg):
       self.transport.write("%s\n" % msg)
   def dataReceived(self, data):
       print data

def gotProtocol(p):
    p.sendMessage(1, p.sendMessage, )	


class Foo(QObject):
    #@pyqtSlot(int, result=int)
    @pyqtSlot(result=str)
    def compute(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(1)
        sock.setblocking(1)
        data = b''
        try: sock.connect(("localhost", 7102))
        except socket.error as error:
            print u'error',error
            return '<?xml version="1.0" encoding="urf-8"?>\
                    <msg id="vt.avkar.server">\
                        <header>\
                            <type>%s</type>\
                        </header>\
                    </msg>'%('server_not_found')

        cmd =b'<msg  id="vt.avkar.kiosk"><header><type>query</type><device>test_kiosk</device><cmd>ping</cmd></header></msg>\n\n'
        sock.send(cmd)
        tmp = sock.recv(1024**2)
        print tmp
        #while tmp:
        #    data += tmp
        #    tmp = sock.recv(1024)
        data = tmp
        sock.close()

        return data
    @pyqtSlot(result=str)
    def getcard(self):
       return reader.getcarnum()

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

        self.foo = Foo(self)
        view.page().mainFrame().addToJavaScriptWindowObject("foo", self.foo)

        html = u"""
             <html>
    <head>

        <link rel="stylesheet" type="text/css" href="style/style.css">

      <script src="jquery-2.1.3.min.js"></script>
            <script>
            var content = '';

            function setdatetime(){
                var data = foo.setdatetime()
                var month_names=['января', "февраля", "марта", "апреля", "майя", "июня", "июля", "августа", "сентября",
                                "октября", "ноября", "декабря"]
                $('#date').text($(data).find('day').text()+' '+month_names[parseInt($(data).find('month').text())]+' '+
                                $(data).find('year').text());
                $('#time').text($(data).find('time').text());
            }
            $(document).ready(function(){
                $('img').mousedown(function(){
                    $(this).attr('src', $(this).attr('src').substring(0,$(this).attr('src').length-5)+'2.png')
                });
                $('img').mouseup(function(){
                    if ($(this).attr('class')=='none'){
                        $(this).attr('src', $(this).attr('src').substring(0,$(this).attr('src').length-5)+'1.png')
                        return None;
                    }
                    $('#content').css({"background-color":"white"})
                    $('#footer').css({"display":"block"});
                    $(this).attr('src', $(this).attr('src').substring(0,$(this).attr('src').length-5)+'1.png')
                    var cmd = $(this).attr('cmd')
                    if (cmd=='tech') {
                        foo.quit();
                    }
                    else if (cmd== "getcard"){
                        var data = foo.getcard().toUpperCase();
                        $("#scontent").children('h2').remove();
                        $('#scontent').append("<h2>"+data+"</h2>")
                    }
                    else if (cmd == "sale"){
                        $('.block').css({"display":"none"});
                        $('.kassa').css({"display":"block"});
                        $('#footer').css({"display":"none"});
                        $('#content').css({"background-color":"#C9D6E0"})
                    }
                    else if (cmd == "back_menu_oper"){
                        $('.block').css({"display":"none"});
                        $('.oper').css({"display":"block"})
                    }
                    else if (cmd=='back'){
                        $('.block').css({"display":"none"});
                        $('.menu').css({"display":"block"});
                        $("#hcontent").children('h2').remove()
                    }
                    else if (cmd=='oper'){
                        var data = foo.compute();
                        $('.menu').css({"display":"none"})
                        $('.oper').css({"display":"block"})



                        $(data).find('header').each(function() {
                            data=$(this).find('type').text()
                            if (data=="server_not_foun"){
                                $("#hcontent").children("h2").remove()
                                $("#hcontent").css({"color":"#ffffff"})
                                $("#header").css({"background-color":"red","background-image":"none"})
                                $("#hcontent").append("<h2>Код ошибки 2. Сервер не найден</h2>")
                            }
                            else {
                                $("#hcontent").children("h2").remove()
                                alert(data)
                                $("#hcontent").append("<h2>Ответ сервера:</h2>")
                            }
                        });
                    }
                });

                setInterval('setdatetime();', 1000);
                $('#settings').click(function (){
                    if ($("#scontent").css('display')=='none') {
                        $('#scontent').slideDown('slow')
                    }
                    else {
                        $('#scontent').hide('slow')
                    }
                });


            });
        </script>
        <title>Оператор АКХ</title>
        <meta charset="utf-8">
    </head>

    <body style="margin:0px;padding:0px;">
        <div id='scontent'>
            <div class='sheader'>
            </div>
            <img src="exit1.png" cmd="getcard">
        </div>
        <div id='header'>
            <div id='settings'>
            </div>
            <div id='hcontent'>
            </div>
            <div id='datetime'>
                <div id='date'>
                </div>
                <div id='time'>
                </div>
            </div>
        </div>
        <div id='content' style="width:100%; margin:auto;position:relative;text-align:center; ">
            <div class='block menu' style='display:block;padding-top:20px;'>
                <div  class='button' style='margin:auto; width:100%; height:150px;'>
                    <img src="bt_oper1.png" cmd='oper'>
                </div>
                <div class='button' style='margin:auto; width:100%; height:150px;'>
                    <img src="bt_admin1.png" cmd='admin'>
                </div>
                <div class='button' style='margin:auto; width:100%; height:150px;'>
                    <img src="bt_tech1.png" cmd='tech'>
                </div>
                <div class='button' style=''>
                    <img src="bt_map1.png" cmd='map'>
                </div>
            </div>

            <div class='block oper' style='display:none;padding-top:20px;'>
                <div class='button' style='margin:auto; width:50%; height:149px;float:left;'>
                    <img src='bt_sale1.png' cmd='sale'>
                </div>
                <div class='button' style='margin:auto; width:50%; height:149px;float:left;'>
                    <img src='bt_wc1.png' cmd='tech'>
                </div>
                <div class='button' style='margin:auto; width:50%; height:150px;float:left;'>
                    <img src='bt_return1.png' cmd='tech'>
                </div>
                <div class='button' style='margin:auto; width:50%; height:150px;float:left;'>
                    <img src='bt_bsk1.png' cmd='tech'>
                </div>
                <div class='button' style='margin:auto; width:50%; height:150px;float:left;'>
                    <img src='bt_kassa1.png' cmd='tech'>
                </div>
                <div class='button' style='margin:auto; width:50%; height:150px;float:left;'>
                    <img src='bt_mobile1.png' cmd='tech'>
                </div>
                <div class='button' style='margin:auto; width:50%; height:150px;float:left;'>
                    <img src='bt_map1.png' cmd='tech'>
                </div>
                <div class='button' style='margin:auto; width:50%; height:150px;float:left;'>
                    <img src='bt_backw1.png' cmd='back'>
                </div>
            </div>
            <div class="block kassa" style="display:none; background-color:#C9D6E0;float:left;padding-top:20px;">
                <div class="kassa-left">
                    <div class='text'>
                        <p>Свободных ячеек - 101</p>
                        <p>Продвно, но не активировано - 0 </p>
                    </div>
                    <div class='button' style='margin:auto; width:50%; height:150px;float:left;border-radius:10px;padding-left:30px;'>
                        <img src='bt_mo1.png' cmd='back_menu_oper' style="border-radius:51px;">
                    </div>
                    <div class="info">
                        <img src="leg_clock.png">
                        <img src="leg_nl.png">
                        <img src="leg_clear.png">
                        <img src="leg_num.png">
                    </div>
                    <div class="kl_bottom">
                            <img src='bt_num1.png' cmd='back_menu_oper' style="border-radius:51px;
                                                                               float:left">
                            <img src='bt_slips1.png' cmd='back_menu_oper' class='none' style="border-radius:51px;
                                                                                 float:right;
                                                                                 -webkit-filter:grayscale(1)">
                    </div>
                </div>
                <div class="kassa-right">
                        <div class="sale_card">
                        </div>
                </div>
            </div>
        </div>
        <div id='footer' style="background-color:#cfcfcf;
                                min-height:31px;
                                max-height:31px;
                                text-align:left;
                                font-size:10pt;
                                padding:12px 0 0 10px;
                                float:left;
                                width:99%">
        v1.5.4
        </div>
    </body>
  </html>
            """
        view.setHtml(html, baseUrl)

def main():
    app = QApplication(sys.argv)
    window = Window()
    window.show()
    app.exec_()

if __name__ == "__main__":
    main()
