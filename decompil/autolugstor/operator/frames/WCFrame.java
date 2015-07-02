package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.frames.WCPanel;
import autolugstor.operator.tcp.SSAction;
import autolugstor.operator.tcp.Session;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.util.List;
import javax.swing.JFrame;

public class WCFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   private Configuration cfg;
   public WCPanel panel;


   public WCFrame(ManagerFrames mf, Configuration config, Session session, int btime, int sum, int kkmses, int kkmcheck, List<SSAction> act, int mode, Logger log) {
      log.log(new Throwable(), "creating...");

      try {
         this.cfg = config;
         Dimension e = new Dimension(this.cfg.getScreenWidth(), this.cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.setLayout(new BorderLayout());
         this.panel = new WCPanel(mf, e.width, e.height, this.cfg, this, session, btime, sum, kkmses, kkmcheck, act, mode, log);
         Container container = this.getContentPane();
         container.add(this.panel, "Center");
         act.add(this.panel);
      } catch (Exception var13) {
         log.log(new Throwable(), var13);
      }

      log.log(new Throwable(), "created");
   }
}
