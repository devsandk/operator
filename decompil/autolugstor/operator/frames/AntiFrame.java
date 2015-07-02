package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.AntiPanel;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.tcp.SSAction;
import autolugstor.operator.tcp.Session;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.util.List;
import javax.swing.JFrame;

public class AntiFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   private Configuration cfg;


   public AntiFrame(ManagerFrames mf, Configuration config, Session sess, List<SSAction> act, Logger log) {
      log.log(new Throwable(), "creating...");

      try {
         this.cfg = config;
         Dimension e = new Dimension(this.cfg.getScreenWidth(), this.cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.setLayout(new BorderLayout());
         AntiPanel buttonPanel = new AntiPanel(mf, e.width, e.height, this.cfg, act, this, log);
         Container container = this.getContentPane();
         container.add(buttonPanel, "Center");
         act.add(buttonPanel);
      } catch (Exception var9) {
         log.log(new Throwable(), var9);
      }

      log.log(new Throwable(), "created");
   }
}
