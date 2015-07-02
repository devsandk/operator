package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.FreeCellPanel;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.tcp.SSAction;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.util.List;
import javax.swing.JFrame;

public class FreeCellFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   public FreeCellPanel panel = null;
   private Logger log;


   public FreeCellFrame(ManagerFrames mf, Configuration cfg, List<SSAction> act, Logger log) {
      this.log = log;
      log.log(new Throwable(), "creating...");

      try {
         Dimension e = new Dimension(cfg.getScreenWidth(), cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.setLayout(new BorderLayout());
         new Container();
         Container container = this.getContentPane();
         this.panel = new FreeCellPanel(mf, this, cfg, act, log);
         container.add(this.panel, "Center");
         act.add(this.panel);
      } catch (Exception var7) {
         log.log(new Throwable(), var7);
      }

      log.log(new Throwable(), "created");
   }

   public void loadData() {
      try {
         this.panel.loadData();
      } catch (Exception var2) {
         this.log.log(new Throwable(), var2);
      }

   }
}
