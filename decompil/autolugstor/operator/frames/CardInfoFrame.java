package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.CardInfoPanel;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.frames.SurchageClass;
import autolugstor.operator.tcp.SSAction;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.util.List;
import javax.swing.JFrame;

public class CardInfoFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   private Configuration cfg;
   CardInfoPanel panel;
   private Logger log;


   public CardInfoFrame(ManagerFrames mf, String cardId, Configuration config, SurchageClass sClass, List<SSAction> act, Logger log) {
      this.log = log;
      log.log(new Throwable(), "creating...");

      try {
         this.cfg = config;
         Dimension e = new Dimension(this.cfg.getScreenWidth(), this.cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.setLayout(new BorderLayout());
         new Container();
         Container container = this.getContentPane();
         this.panel = new CardInfoPanel(mf, cardId, this, this.cfg, sClass, act, log);
         container.add(this.panel, "Center");
         act.add(this.panel);
      } catch (Exception var9) {
         log.log(new Throwable(), var9);
      }

      log.log(new Throwable(), "created");
   }

   public void loadDataCard(String cardId) {
      try {
         this.panel.loadDataCard(cardId);
      } catch (Exception var3) {
         this.log.log(new Throwable(), var3);
      }

   }
}
