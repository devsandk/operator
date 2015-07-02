package autolugstor.operator.tcp;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.tcp.SSAction;
import autolugstor.operator.tcp.SSActionData;
import autolugstor.operator.tcp.TCPClient;
import autolugstor.protocol.ProtocolPing;
import autolugstor.protocol.XMLProtocol;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.List;

public class Ping implements Runnable {

   private Configuration cfg;
   private Boolean work = Boolean.valueOf(true);
   private List<SSAction> actions;
   private Logger log;


   public Ping(Configuration config, List<SSAction> a, Logger log) {
      this.cfg = config;
      this.actions = a;
      this.log = log;
   }

   public void run() {
      this.sendPing();

      while(this.work.booleanValue()) {
         try {
            Thread.sleep((long)(this.cfg.getPingPeriod() * 1000));
            this.sendPing();
         } catch (InterruptedException var2) {
            this.log.log(new Throwable(), (Exception)var2);
         }
      }

   }

   private void sendPing() {
      try {
         Date e = new Date();
         System.out.println("ping send " + e.toString());
         TCPClient t = new TCPClient(this.cfg, this.log);
         XMLProtocol p = new XMLProtocol();
         String s = t.Send(p.getXMLPing(this.cfg.getKioskId()));
         ProtocolPing pr = new ProtocolPing();
         String er = pr.Parse(s);
         System.out.println("actions=" + this.actions.size());

         for(int i = 0; i < this.actions.size(); ++i) {
            if(this.actions.get(i) != null) {
               GregorianCalendar g = new GregorianCalendar();
               if(pr.time != null) {
                  g.setTime(pr.time);
               }

               SSActionData ssd = new SSActionData(g, er, pr.isAntiterror, pr.free_cells, pr.free_cards);
               ((SSAction)this.actions.get(i)).SystemStateCompleted(ssd);
            }
         }
      } catch (Exception var10) {
         this.log.log(new Throwable(), var10);
      }

   }
}
