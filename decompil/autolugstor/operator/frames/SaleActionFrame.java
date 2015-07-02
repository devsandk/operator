package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.frames.SaleActionPanel;
import autolugstor.operator.frames.SurchageClass;
import autolugstor.operator.tcp.Session;
import autolugstor.protocol.ProtocolFreeCellItem;
import autolugstor.protocol.ProtocolRateTable;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import javax.swing.JFrame;

public class SaleActionFrame extends JFrame {

   private static final long serialVersionUID = 1L;
   private Configuration cfg;


   public SaleActionFrame(ManagerFrames mf, Configuration config, Session session, int btime, int cash, int intotal, int kkmses, int kkmcheck, ProtocolRateTable pRate, SurchageClass sclass, ProtocolFreeCellItem pCellForSale, Logger log) {
      log.log(new Throwable(), "creating...");

      try {
         this.cfg = config;
         Dimension e = new Dimension(this.cfg.getScreenWidth(), this.cfg.getScreenHeight());
         this.setBounds(0, 0, e.width, e.height);
         this.setUndecorated(true);
         this.setLayout(new BorderLayout());
         SaleActionPanel buttonPanel = new SaleActionPanel(mf, e.width, e.height, this.cfg, this, session, btime, cash, intotal, kkmses, kkmcheck, pRate, sclass, pCellForSale, log);
         Container container = this.getContentPane();
         container.add(buttonPanel, "Center");
      } catch (Exception var16) {
         log.log(new Throwable(), var16);
      }

      log.log(new Throwable(), "created");
   }
}
