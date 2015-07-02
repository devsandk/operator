package autolugstor.operator.tcp;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.tcp.TCPClient;
import autolugstor.operator.tcp.TCPClientAction;
import autolugstor.protocol.XMLProtocol;

public class TCPClientLoadData implements Runnable {

   private Configuration cfg;
   private TCPClientAction action;
   private String command = "";
   private String cardId = "";
   private Logger log;
   private int sec_index_begin = 0;
   private int sec_index_end = 0;


   public TCPClientLoadData(Configuration config, TCPClientAction act, String cmd, String cardid, Logger log) {
      this.cfg = config;
      this.action = act;
      this.command = cmd;
      this.cardId = cardid;
      this.log = log;
   }

   public TCPClientLoadData(Configuration config, TCPClientAction act, String cmd, Logger log, int hall, int secbegin, int secend) {
      this.cfg = config;
      this.action = act;
      this.command = cmd;
      this.log = log;
      this.sec_index_begin = secbegin;
      this.sec_index_end = secend;
   }

   public void run() {
      String answer = "";
      TCPClient tcp = new TCPClient(this.cfg, this.log);
      XMLProtocol xml = new XMLProtocol();

      try {
         String e = this.command;
         switch(this.command.hashCode()) {
         case 1131494696:
            if(e.equals("get_cells")) {
               answer = tcp.Send(xml.getXMLStateCells(this.cfg.getKioskId(), this.cfg.Hall, this.sec_index_begin, this.sec_index_end));
            }
            break;
         case 1976158809:
            if(e.equals("get_card")) {
               answer = tcp.Send(xml.getXMLInfoCard(this.cfg.getKioskId(), this.cardId));
            }
         }
      } catch (Exception var5) {
         answer = "";
         this.log.log(new Throwable(), var5);
      }

      this.action.ConnectionCompleted(answer, tcp.getError());
   }
}
