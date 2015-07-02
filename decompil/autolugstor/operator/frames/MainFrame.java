package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.MainPanel;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.tcp.Ping;
import autolugstor.operator.tcp.SSAction;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JFrame;

public class MainFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   private Configuration cfg;
   private List<SSAction> actions = new ArrayList();
   private ManagerFrames mF;


   public MainFrame(Configuration config, Logger log) {
      log.log(new Throwable(), "creating...");

      try {
         this.cfg = config;
         Dimension e = new Dimension(this.cfg.getScreenWidth(), this.cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.mF = new ManagerFrames(e.width, e.height, log);
         this.setLayout(new BorderLayout());
         MainPanel buttonPanel = new MainPanel(this.mF, e.width, e.height, this.cfg, this.actions, log);
         Container container = this.getContentPane();
         container.add(buttonPanel, "Center");
         this.actions.add(buttonPanel);
         log.log(new Throwable(), "Ping starting...");
         Ping ping = new Ping(config, this.actions, log);
         Thread threadPing = new Thread(ping);
         threadPing.start();
         log.log(new Throwable(), "Ping started");
      } catch (Exception var8) {
         log.log(new Throwable(), var8);
      }

      log.log(new Throwable(), "created");
   }
}
