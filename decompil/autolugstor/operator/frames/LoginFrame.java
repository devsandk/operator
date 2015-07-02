package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.LoginPanel;
import autolugstor.operator.frames.MainPanel;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.tcp.Session;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import javax.swing.JFrame;

public class LoginFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   private Configuration cfg;


   public LoginFrame(ManagerFrames mf, Configuration config, Session session, MainPanel mp, Logger log) {
      log.log(new Throwable(), "creating...");

      try {
         this.cfg = config;
         Dimension e = new Dimension(this.cfg.getScreenWidth(), this.cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.setLayout(new BorderLayout());
         LoginPanel buttonPanel = new LoginPanel(mf, e.width, e.height, this.cfg, this, session, mp, log);
         Container container = this.getContentPane();
         container.add(buttonPanel, "Center");
      } catch (Exception var9) {
         log.log(new Throwable(), var9);
      }

      log.log(new Throwable(), "created");
   }
}
