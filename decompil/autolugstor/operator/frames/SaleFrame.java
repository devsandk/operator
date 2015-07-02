package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.frames.SalePanel;
import autolugstor.operator.tcp.SSAction;
import autolugstor.operator.tcp.Session;
import autolugstor.protocol.ProtocolRateTable;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.util.List;
import javax.swing.JFrame;

public class SaleFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   private Configuration cfg;
   private Session session;


   public SaleFrame(ManagerFrames mf, Configuration config, Session sess, ProtocolRateTable pRate, int freecells, List<SSAction> act, Logger log) {
      log.log(new Throwable(), "creating...");

      try {
         this.cfg = config;
         Dimension e = new Dimension(this.cfg.getScreenWidth(), this.cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.setLayout(new BorderLayout());
         SalePanel buttonPanel = new SalePanel(mf, e.width, e.height, this.cfg, this, this.session, pRate, freecells, act, log);
         Container container = this.getContentPane();
         container.add(buttonPanel, "Center");
         act.add(buttonPanel);
      } catch (Exception var11) {
         log.log(new Throwable(), var11);
      }

      log.log(new Throwable(), "created");
   }
}
