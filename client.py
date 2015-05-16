#! -*-coding:utf8 -*-
from twisted.internet import reactor, protocol
class EchoClient(protocol.Protocol):
   sdata=''
   def connectionMade(self):
       self.transport.write('<msg id="vt.avkar.kiosk"><header><type>query</type><device>test_kiosk</device><cmd>ping</cmd></header></msg>')
        


   def dataReceived(self, data):
       self.sdata=data
       print u"Ответ сервера:", self.sdata
       self.transport.loseConnection()

   def connectionLost(self, reason):
       print u"соединение разорвано"

class EchoFactory(protocol.ClientFactory):

   def buildProtocol(self, addr):
       return EchoClient()

   def clientConnectionFailed(self, connector, reason):
       print u"Не удалось осуществить соединение - всего доброго!"
       reactor.stop()

   def clientConnectionLost(self, connector, reason):
       print u"Соединение разорвано - всего доброго!"
       reactor.stop()
data_serv=None
reactor.connectTCP("192.168.0.81", 7102, EchoFactory())
reactor.run()

 

