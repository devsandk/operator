package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.FreePanel;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.tcp.SSAction;
import autolugstor.protocol.ProtocolFreeCellItem;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.util.List;
import javax.swing.JFrame;

public class FreeFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   private Configuration cfg;


   public FreeFrame(ManagerFrames mf, Configuration config, List<SSAction> act, ProtocolFreeCellItem p, Logger log) {
      log.log(new Throwable(), "creating...");

      try {
         this.cfg = config;
         Dimension e = new Dimension(this.cfg.getScreenWidth(), this.cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.setLayout(new BorderLayout());
         FreePanel buttonPanel = new FreePanel(mf, e.width, e.height, this.cfg, act, this, p, log);
         Container container = this.getContentPane();
         container.add(buttonPanel, "Center");
         act.add(buttonPanel);
      } catch (Exception var9) {
         log.log(new Throwable(), var9);
      }

      log.log(new Throwable(), "created");
   }
}