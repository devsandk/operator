__author__ = 'anton'
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from PyQt4.QtWebKit import *
import sys
import os
from cardreedder import Reader
from XMLProtocol import XMLProtocol

pyDir = os.path.abspath(os.path.dirname(__file__))
baseUrl = QUrl.fromLocalFile(os.path.join(pyDir, "img/"))
proto = XMLProtocol.XMLProtocol('10.8.0.14', 7102)

class Foo(QObject):
    @pyqtSlot(result=str)
    def getcard(self):
        reader = Reader()
        return '%s'%reader.get_card_num()


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
        view.settings().setAttribute(QWebSettings.DeveloperExtrasEnabled, True)
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


