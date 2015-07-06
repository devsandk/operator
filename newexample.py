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
import xml.etree.ElementTree as ET
from XMLProtocol import XMLProtocol


class Reader():
    def __init__(self):
        self.serial = serial.Serial('/dev/ttyUSB0', 9600)

pyDir = os.path.abspath(os.path.dirname(__file__))
baseUrl = QUrl.fromLocalFile(os.path.join(pyDir, "img/"))


class Foo(QObject):
    #@pyqtSlot(int, result=int)
    @pyqtSlot(result=str)
    def ping(self):
        proto = XMLProtocol.XMLProtocol('10.8.0.14', 7102)
        data = u'<msg><header><type>answer</type><free_cells>%s</free_cells>' \
               u'<free_card>%s</free_card></header></msg>' % proto.sendCMD('ping_xml')
        print data
        return data
    @pyqtSlot(result=str)
    def getcard(self):
       return reader.getcarnum()

    @pyqtSlot(str, str, str, result=str)
    def get_cells(self, hall, secbegin, secend):
        proto = XMLProtocol.XMLProtocol('10.8.0.14', 7102)
        result = proto.sendCMD('get_cells_xml', hall, secbegin, secend)
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

        html = u"""
             <html>
    <head>

        <link rel="stylesheet" type="text/css" href="style/style.css">

      <script src="jquery-2.1.3.min.js"></script>
            <script>
            var content = '';
            var card='';
            var read=1;
            function jgetcard(){
                    if (window.read==1){
                        var data = foo.getcard().toUpperCase();
                        data=data.replace(/^0+/, '')
                        $("#scontent").children('h2').remove();
                        $('#scontent').append("<h2>"+data+"</h2>")
                        window.card=data
                        if(data!="NONE_DATA"){
                            window.read=0;
                        }
                    }
            }
            var sale_cell = new Object()
                sale_cell.card = '';
                sale_cell.sec_num = '';
                sale_cell.cell_index = '';
                sale_cell.btime = '';
                sale_cell.sum = '';
                sale_cell.kkmses = '';
                sale_cell.kkmcheck = '';
                sale_cell.buy_card = function(){
                    alert('buy_card: card, btime, sum, kkmses, kkmcheck, sec_num, cell_index')
                }


            function setdatetime(){
                var data = foo.setdatetime()
                var month_names=['января', "февраля", "марта", "апреля", "майя", "июня", "июля", "августа", "сентября",
                                "октября", "ноября", "декабря"]
                $('#date').text($(data).find('day').text()+' '+month_names[parseInt($(data).find('month').text())]+' '+
                                $(data).find('year').text());
                $('#time').text($(data).find('time').text());
            }
            $(document).ready(function(){
                sale_cell.buy_card()
                sale_cell.card='99999'
                alert(sale_cell.card)
                $('.numbutton').mousedown(function(){
                    $(this).css({"background-image":$(this).css('background-image').substring(0,$(this).css('background-image').length-6)+'2.png)'})
                });
                $('.numbutton').mouseup(function(){
                    $(this).css({"background-image":$(this).css('background-image').substring(0,$(this).css('background-image').length-6)+'1.png)'})
                    /* Вызывать функцию выбора ячеек */
                    if($(this).attr('cmd')=='get_cell'){
                        begin = $(this).attr('begin')
                        end = $(this).attr('end')
                        data = foo.get_cells('1', begin, end);
                        $('.block').css({"display":"none"});
                        $('.viewcells').css({"display":"block"});
                        $('.chour').text('0')
                        free_cells=0;
                        $('.holl').children('.row').remove();
                        for(i=0; i<=10; i++){
                            $('.holl').append('<div class="row" id="'+i+'" sec_index="'+i+'"></div>')
                        }
                        $(data).find('item').each(function(){
                            if ($(this).attr('state')=='free'){
                                free_cells+=1
                            }
                            if ($(this).attr('cell_num')!='99999'){
                                class_name='need_pay'
                                size = $(this).attr('cell_size')
                                if($(this).attr('need_pay')=='yes'){
                                    class_name='need_pay'
                                }
                                else {
                                    class_name=$(this).attr('state')
                                }
                                $('#'+$(this).attr('sec_index')).append("<div class='cell size"+size+"_"+class_name+"'>"+
                                $(this).attr('cell_num')+"</div>")
                            }
                        })
                        $('.free_cells').text(free_cells)


                    }
                    else if($(this).attr('cmd')=='clear'){
                        $('.chour').text('0')
                    }
                    else if($('.chour').text()=='0'){
                        $('.chour').text($(this).text())
                    }
                    else {
                        $('.chour').text($('.chour').text()+$(this).text())
                    }

                });
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
                        window.read=1;
                    }
                    else if (cmd == "back_menu_oper"){
                        $('.block').css({"display":"none"});
                        $('.chour').text('0')
                        $('.oper').css({"display":"block"})
                    }
                    else if (cmd == "back_menu_kassa"){
                        $('.block').css({"display":"none"});
                        $('.kassa').css({"display":"block"})
                    }
                    else if (cmd=='back'){
                        $('.block').css({"display":"none"});
                        $('.menu').css({"display":"block"});
                        $("#hcontent").children('h2').remove()
                    }
                    else if (cmd=='oper'){
                        var data = foo.ping();
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
                                free_cells=$(this).find('free_cells').text()
                                $("#free_cells").text(free_cells)
                                $("#hcontent").append("<h2>Ответ сервера:</h2>")
                            }
                        });
                    }
                });


                setInterval('setdatetime();', 1000);
                setInterval('jgetcard();',3000);
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
                        <p>Свободных ячеек - <span id=free_cells></span></p>
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
                    <table>
                        <tr>
                            <td>ВРЕМЯ ХРАНЕНИЯ</td><td class='hour_guard two'><span class='chour'>0</span>ч</td>
                        </tr>
                        <tr>
                            <td>НОМЕР ЯЧЕЙКИ</td><td class='cell_num two'></td>
                        </tr>
                        <tr>
                            <td>ИТОГО</td><td class='summ two'></td>
                        </tr>
                    </table>
                        </div>
                        <div class='numpad'>
                            <div class='numbutton'>1</div>
                            <div class='numbutton'>2</div>
                            <div class='numbutton'>3</div>
                            <div class='numbutton'>4</div>
                            <div class='numbutton'>5</div>
                            <div class='numbutton'>6</div>
                            <div class='numbutton'>7</div>
                            <div class='numbutton'>8</div>
                            <div class='numbutton'>9</div>
                            <div class='numbutton'>0</div>
                            <div class='numbutton'>.</div>
                            <div class='numbutton'>00</div>
                        </div>
                        <div class='snumpad'>
                            <div class='numbutton' cmd='get_cell' begin='1', end='10'>Я</div>
                            <div class="numbutton b_clear" cmd='clear'></div>
                        </div>
                </div>
            </div>
            <div class="block card" style='display:none;min-height:600px;'>
                <div style="width:100%;margin-left:100px;float:left">
                    <img src='card.png' style="float:left;">
                </div>
                <div style="min-width:100%;text-align:center;float:left;">
                    <img src="text_saleaction1.png">
                </div>
                    <div class='button' style='margin:auto; width:100%; height:150px;float:left;border-radius:10px;padding-left:30px;'>
                        <img src='bt_cancel1.png' cmd='back_menu_oper' style="border-radius:51px;">
                    </div>
            </div>
            <div class="block viewcells" style='display:none; min-height:600px;'>
                <div class="view_head" style='background-color:white; width:100%;float:left;'>
                    <div class='text' style="float:left; width:50%; padding-left:20px; text-align:left;">
                        <p>Свободных ячеек - <span class='free_cells'></span></p>
                    </div>
                </div>
                <div class='holl'>
                    <!--<div class='row' sec_index='1'>
                        <div class='cell size2_free'>1</div>
                        <div class='cell size2_free'>2</div>
                        <div class='cell size2_free'>3</div>
                    </div>-->
                </div>
                <div class='button' style='margin:auto; width:50%; height:150px;float:left;'>
                    <img src='bt_backw1.png' cmd='back_menu_kassa'>
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
