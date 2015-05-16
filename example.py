__author__ = 'tatyana'
import os
from PyQt4.QtCore import *
from PyQt4.QtGui import *
import sys
from PyQt4.QtGui import QApplication
from PyQt4.QtCore import QUrl
from PyQt4.QtWebKit import QWebView

class Foo(QObject):
    @pyqtSlot(int, result=int)
    def compute(self, value):
        return value * 2

    @pyqtSlot()
    def quit(self):
        QApplication.quit()









app = QApplication([])


pyDir = os.path.abspath(os.path.dirname(__file__))
baseUrl = QUrl.fromLocalFile(os.path.join(pyDir, "img/"))
# And a window
win = QWidget()
#win.setWindowTitle('QWebView Interactive Demo')
win.setFixedSize(1024, 768)
win.setGeometry(0, 0, 0, 0)
#win.setStyleSheet("{ border:0px solid black;}")
win.setWindowFlags(Qt.FramelessWindowHint)
# And give it a layout
layout = QVBoxLayout()
win.setLayout(layout)

# Create and fill a QWebView
view = QWebView()
view.setHtml('''
  <html>
    <head>


      <script language="javascript">
        // Completes the full-name control and
        // shows the submit button
        function completeAndReturnName() {
          var fname = document.getElementById('fname').value;
          var lname = document.getElementById('lname').value;
          var full = fname + ' ' + lname;

          document.getElementById('fullname').value = full;
          document.getElementById('submit-btn').style.display = 'block';

          return full;
        }
        function operClick(e,state) {
            if (state==1){
                e.target.src="bt_oper2.png";
            }
            else {
                e.target.src="bt_oper1.png";
            }
        }
      </script>
      <script src="jquery-2.1.3.min.js"></script>
            <script>
            $(document).ready(function(){
                $('img').mousedown(function(){
                    $(this).attr('src', $(this).attr('src').substring(0,$(this).attr('src').length-5)+'2.png')
                });
                $('img').mouseup(function(){
                    $(this).attr('src', $(this).attr('src').substring(0,$(this).attr('src').length-5)+'1.png')
                    alert($(this).attr('cmd'))
                });


            });
        </script>
    </head>

    <body style="margin:0px;padding:0px;">
        <div id='header' style="min-height:100px; background-color:#a0a0a0;margin-bottom:20px;">
        </div>
        <div id='content' style="width:100%; margin:auto;position:relative;text-align:center; ">
        <div style='margin:auto; width:100%; height:150px;'>
            <img src="bt_oper1.png" cmd='oper'>
        </div>
        <div style='margin:auto; width:100%; height:150px;'>
            <img src="bt_admin1.png" cmd='admin'>
        </div>
        <div style='margin:auto; width:100%; height:150px;'>
            <img src="bt_tech1.png" cmd='tech'>
        </div>
        <div style='margin:auto; width:100%; height:150px;'>
            <img src="bt_map1.png" cmd='map'>
   <!--     </div>
        </div>
      <form>

        <label for="fname">First name:</label>
        <input type="text" name="fname" id="fname"></input>
        <br />
        <label for="lname">Last name:</label>
        <input type="text" name="lname" id="lname"></input>
        <br />
        <label for="fullname">Full name:</label>
        <input disabled type="text" name="fullname" id="fullname"></input>
        <br />
        <input style="display: none;" type="submit" id="submit-btn"></input>
      </form> -->
    </body>
  </html>
''', baseUrl)

# A button to call our JavaScript
#button = QPushButton('Set Full Name')

# Interact with the HTML page by calling the completeAndReturnName
# function; print its return value to the console
def complete_name():
    frame = view.page().mainFrame()
    print frame.evaluateJavaScript('completeAndReturnName();')

# Connect 'complete_name' to the button's 'clicked' signal
#button.clicked.connect(complete_name)

# Add the QWebView and button to the layout
layout.addWidget(view)
#layout.addWidget(button)

# Show the window and run the app
win.show()
app.exec_()