package autolugstor.operator.frames;

import autolugstor.general.General;
import autolugstor.log.Logger;
import autolugstor.manager.ManagerEvents;
import autolugstor.manager.ManagerObject;
import autolugstor.manager.control.ManagerControlFree;
import autolugstor.manager.image.ManagerImage;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.tcp.SSAction;
import autolugstor.operator.tcp.SSActionData;
import autolugstor.operator.tcp.TCPClient;
import autolugstor.protocol.ProtocolFreeCellItem;
import autolugstor.protocol.ProtocolSetFree;
import autolugstor.protocol.XMLProtocol;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.LayoutManager;
import java.awt.RenderingHints;
import java.util.List;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class FreePanel extends JPanel implements ManagerEvents, SSAction {

   private static final long serialVersionUID = 1L;
   private ManagerImage mI = null;
   private ManagerControlFree mC = null;
   private JLabel labelTime;
   private JLabel labelDate;
   private General gen = new General();
   private int screenWidth = 0;
   private int screenHeight = 0;
   private Configuration cfg;
   private boolean lockInterface = false;
   private String sS = "";
   private List<SSAction> actions;
   private JFrame parentFrame;
   private String error = "";
   private JLabel btFree;
   private JLabel btCancel;
   private ProtocolFreeCellItem pFree;
   private ManagerFrames mF;
   private Logger log;


   public FreePanel(ManagerFrames mf, int screenwidth, int screenheight, Configuration config, List<SSAction> act, JFrame parentFrame, ProtocolFreeCellItem pFree, Logger log) {
      this.log = log;
      log.log(new Throwable(), "creating...");

      try {
         this.mF = mf;
         this.mI = this.mF.miFree;
         this.mC = this.mF.mcFree;
         this.screenWidth = screenwidth;
         this.screenHeight = screenheight;
         this.cfg = config;
         this.actions = act;
         this.parentFrame = parentFrame;
         this.pFree = pFree;
         this.setLayout((LayoutManager)null);
         ManagerObject e = new ManagerObject();
         this.btFree = e.addManagerControlButton(this.mC.mciFree, this, this, "free");
         ManagerObject m2 = new ManagerObject();
         this.btCancel = m2.addManagerControlButton(this.mC.mciCancel, this, this, "cancel");
         ManagerObject mo_time = new ManagerObject();
         this.labelTime = mo_time.addManagerControlLabel(this.mC.mciTime, this, this.gen.getFormatCurrentTime());
         ManagerObject mo_date = new ManagerObject();
         this.labelDate = mo_date.addManagerControlLabel(this.mC.mciDate, this, this.gen.getFormatCurrentDate());
      } catch (Exception var13) {
         log.log(new Throwable(), var13);
      }

      log.log(new Throwable(), "created");
   }

   public void paintComponent(Graphics g) {
      try {
         Graphics2D e = (Graphics2D)g;
         e.clearRect(0, 0, this.screenWidth, this.screenHeight);
         e.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
         this.gen.drawManagers(this.mI, e, this);
         if(this.error != "") {
            Font f = new Font("Arial", 0, 24);
            FontMetrics fm = e.getFontMetrics(f);
            e.setFont(f);
            e.setColor(Color.red);
            e.drawString(this.error, (this.screenWidth - fm.stringWidth(this.error)) / 2, this.screenHeight / 2);
         }

         this.gen.drawSystemState(this.mI, e, this.sS, this.screenWidth);
         e.finalize();
      } catch (Exception var5) {
         this.log.log(new Throwable(), var5);
      }

   }

   public void activateManagerItem(String param) {
      try {
         switch(param.hashCode()) {
         case -1367724422:
            if(param.equals("cancel") && !this.lockInterface) {
               this.lockInterface = true;
               this.close();
               this.lockInterface = false;
            }
            break;
         case 3151468:
            if(param.equals("free") && !this.lockInterface) {
               this.lockInterface = true;
               this.sendFree();
               this.lockInterface = false;
            }
         }
      } catch (Exception var3) {
         this.lockInterface = false;
         this.log.log(new Throwable(), var3);
      }

   }

   public void panelVisible(boolean b) {
      try {
         this.setVisible(b);
      } catch (Exception var3) {
         this.log.log(new Throwable(), var3);
      }

   }

   public void SystemStateCompleted(SSActionData data) {
      try {
         this.sS = data.state;
         this.labelTime.setText(this.gen.getFormatCurrentTime(data.time.getTime()));
         this.labelDate.setText(this.gen.getFormatCurrentDate(data.time));
         this.updateUI();
      } catch (Exception var3) {
         this.log.log(new Throwable(), var3);
      }

   }

   private void sendFree() {
      try {
         this.btFree.setVisible(false);
         this.btCancel.setVisible(false);
         TCPClient e = new TCPClient(this.cfg, this.log);
         XMLProtocol xml = new XMLProtocol();
         String s = e.Send(xml.getXMLSetFree(this.cfg.getKioskId(), this.pFree.sec_num, this.pFree.cell_index));
         ProtocolSetFree p = new ProtocolSetFree();
         this.error = p.Parse(s);
         if(this.error == "") {
            this.close();
         } else {
            this.error = "Не удалось освободить ячейку";
            this.log.log(new Throwable(), this.error, true);
            this.btCancel.setVisible(true);
            this.updateUI();
         }
      } catch (Exception var5) {
         this.log.log(new Throwable(), var5);
      }

   }

   private void close() {
      try {
         this.actions.remove(this);
         this.parentFrame.dispose();
      } catch (Exception var2) {
         this.log.log(new Throwable(), var2);
      }

   }
}
