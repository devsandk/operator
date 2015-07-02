package autolugstor.operator.frames;

import autolugstor.general.General;
import autolugstor.kasbi.Fr;
import autolugstor.log.Logger;
import autolugstor.manager.ManagerEvents;
import autolugstor.manager.ManagerObject;
import autolugstor.manager.control.ManagerControlOWC;
import autolugstor.manager.image.ManagerImage;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.ManagerFrames;
import autolugstor.operator.tcp.SSAction;
import autolugstor.operator.tcp.SSActionData;
import autolugstor.operator.tcp.Session;
import autolugstor.operator.tcp.TCPClient;
import autolugstor.protocol.ProtocolTariffWC;
import autolugstor.protocol.ProtocolWCSale;
import autolugstor.protocol.XMLProtocol;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.LayoutManager;
import java.awt.RenderingHints;
import java.awt.Toolkit;
import java.io.IOException;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class WCPanel extends JPanel implements ManagerEvents, SSAction {

   private static final long serialVersionUID = 1L;
   private ManagerImage mI = null;
   private ManagerControlOWC mC = null;
   private General gen = new General();
   private int screenWidth = 0;
   private int screenHeight = 0;
   private Configuration cfg;
   private JFrame parentFrame;
   private Image ajaxLoader = null;
   private String error = "";
   private Boolean succeed = Boolean.valueOf(false);
   private JLabel btCancel;
   private JLabel btOk;
   private JLabel btReturn;
   private JLabel btCancel2;
   private Fr kasbiFR;
   private boolean pressedOk = false;
   private boolean pressedReturn = false;
   private List<SSAction> actions;
   private String sS = "";
   private ManagerFrames mF;
   private boolean lockInterface = false;
   private boolean showInfo = true;
   private float sumPay = -1.0F;
   private int mode = 0;
   private Logger log;


   public WCPanel(ManagerFrames mf, int screenwidth, int screenheight, Configuration config, JFrame frame, Session ses, int btime, int sum, int kkmses, int kkmcheck, List<SSAction> act, int mode, Logger log) {
      this.log = log;
      log.log(new Throwable(), "creating...");

      try {
         this.mF = mf;
         this.mI = this.mF.miWC;
         this.mC = this.mF.mcWC;
         this.screenWidth = screenwidth;
         this.screenHeight = screenheight;
         this.cfg = config;
         this.parentFrame = frame;
         this.mode = mode;
         this.actions = act;
         TCPClient e = new TCPClient(this.cfg, log);
         XMLProtocol xml = new XMLProtocol();

         try {
            String mo_cancel = "wc";
            if(mode == 1) {
               mo_cancel = "dhc";
            }

            if(mode == 2) {
               mo_cancel = "bat";
            }

            String mo_ok = e.Send(xml.getXMLTariffWC(this.cfg.getKioskId(), mo_cancel));
            ProtocolTariffWC mo_c2 = new ProtocolTariffWC();
            String mo_ret = mo_c2.Parse(mo_ok);
            if(mo_ret == "") {
               this.sumPay = (float)mo_c2.rate_sum / 100.0F;
            }

            if(mo_ret != "") {
               log.log(new Throwable(), mo_ret, true);
            }
         } catch (Exception var20) {
            log.log(new Throwable(), var20);
         }

         this.setLayout((LayoutManager)null);
         ManagerObject mo_cancel1 = new ManagerObject();
         this.btCancel = mo_cancel1.addManagerControlButton(this.mC.mciCancel, this, this, "close");
         this.btCancel.setVisible(false);
         ManagerObject mo_ok1 = new ManagerObject();
         this.btOk = mo_ok1.addManagerControlButton(this.mC.mciOk, this, this, "ok");
         this.btOk.setVisible(false);
         ManagerObject mo_c21 = new ManagerObject();
         this.btCancel2 = mo_c21.addManagerControlButton(this.mC.mciCancel2, this, this, "cancel2");
         ManagerObject mo_ret1 = new ManagerObject();
         this.btReturn = mo_ret1.addManagerControlButton(this.mC.mciReturn, this, this, "return");
      } catch (Exception var21) {
         log.log(new Throwable(), var21);
      }

      log.log(new Throwable(), "created");
   }

   public void paintComponent(Graphics g) {
      try {
         Graphics2D e = (Graphics2D)g;
         e.clearRect(0, 0, this.screenWidth, this.screenHeight);
         e.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
         this.gen.drawManagers(this.mI, e, this);
         this.gen.drawAjaxLoader(this.screenWidth, this.screenHeight, e, this.ajaxLoader, this);
         Font service;
         FontMetrics f;
         if(this.error != "") {
            service = new Font("Arial", 0, 24);
            f = e.getFontMetrics(service);
            e.setFont(service);
            e.setColor(Color.red);
            byte fm = 0;
            if(this.showInfo) {
               fm = 100;
            }

            e.drawString(this.error, (this.screenWidth - f.stringWidth(this.error)) / 2, this.screenHeight / 2 + fm);
         }

         if(this.succeed.booleanValue()) {
            service = new Font("Dialog", 0, 24);
            f = e.getFontMetrics(service);
            String fm1 = "Карта возвращена";
            e.setFont(service);
            float[] ret1 = new float[3];
            Color.RGBtoHSB(29, 87, 29, ret1);
            e.setColor(Color.getHSBColor(ret1[0], ret1[1], ret1[2]));
            e.drawString(fm1, (this.screenWidth - f.stringWidth(fm1)) / 2, this.screenHeight / 2);
         }

         if(this.showInfo) {
            String service1 = "Пользование санузлом";
            if(this.mode == 1) {
               service1 = "Утеря БСК";
            }

            if(this.mode == 2) {
               service1 = "Зарядка телефона";
            }

            Font f1 = new Font("Dialog", 1, 28);
            FontMetrics fm2 = e.getFontMetrics(f1);
            String ret11 = "Оплаченная сумма: " + this.sumPay + " руб.";
            e.setFont(f1);
            float[] hsb = new float[3];
            Color.RGBtoHSB(0, 71, 114, hsb);
            e.setColor(Color.getHSBColor(hsb[0], hsb[1], hsb[2]));
            e.drawString(ret11, (this.screenWidth - fm2.stringWidth(ret11)) / 2, this.screenHeight / 2);
            e.drawString(service1, (this.screenWidth - fm2.stringWidth(service1)) / 2, this.screenHeight / 2 - 50);
         }

         this.gen.drawSystemState(this.mI, e, this.sS, this.screenWidth);
         e.finalize();
      } catch (Exception var8) {
         this.log.log(new Throwable(), var8);
      }

   }

   public void activateManagerItem(String param) {
      try {
         switch(param.hashCode()) {
         case -934396624:
            if(param.equals("return") && !this.pressedReturn) {
               this.pressedReturn = true;
               this.ajaxLoader = Toolkit.getDefaultToolkit().getImage("img/ajax-loader.gif");
               this.error = "";
               this.showInfo = false;
               this.btReturn.setVisible(false);
               this.btCancel2.setVisible(false);
               this.updateUI();
               boolean frerror = true;
               this.kasbiFR = new Fr(this.cfg.FrAddress, this.cfg.FrType, this.cfg.FrPassword);
               ArrayList slipList = new ArrayList();

               try {
                  byte e1 = 2;
                  switch(this.mode) {
                  case 0:
                     e1 = 2;
                     break;
                  case 1:
                     e1 = 3;
                     break;
                  case 2:
                     e1 = 4;
                  }

                  int frerror1 = this.kasbiFR.printDoc(slipList, "Оплата услуг ", (int)(this.sumPay * 100.0F), 1000, (int)(this.sumPay * 100.0F), false, e1);
                  System.out.println("FR ERROR: " + frerror1);
                  this.log.log(new Throwable(), "FR ERROR: " + frerror1);
                  if(frerror1 == this.kasbiFR.ERR_OK() && frerror1 != this.kasbiFR.ERR_NEED_COUNTINUEPRINT()) {
                     this.sendWCSale(Boolean.valueOf(true));
                  } else if(frerror1 == this.kasbiFR.ERR_NEED_COUNTINUEPRINT()) {
                     this.sendWCSale(Boolean.valueOf(false));
                     this.actionCountinuePrint();
                  } else {
                     this.error = "Ошибка оборудования " + frerror1;
                     this.log.log(new Throwable(), this.error, true);
                     this.ajaxLoader = null;
                     this.updateUI();
                     this.btOk.setVisible(false);
                     this.btReturn.setVisible(false);
                     this.btCancel2.setVisible(false);
                     this.btCancel.setVisible(true);
                  }
               } catch (Exception var7) {
                  this.log.log(new Throwable(), var7);
               }

               this.pressedReturn = false;
            }
            break;
         case 3548:
            if(param.equals("ok") && !this.pressedOk) {
               this.pressedOk = true;
               this.btOk.setVisible(false);
               this.ajaxLoader = Toolkit.getDefaultToolkit().getImage("img/ajax-loader.gif");
               this.error = "";
               this.updateUI();

               try {
                  Boolean e = Boolean.valueOf(this.kasbiFR.ContinuePrint());
                  System.out.println("FR COUNTINUE PRINT: " + e);
                  if(!e.booleanValue()) {
                     this.actionCountinuePrint();
                  } else {
                     this.close();
                  }
               } catch (InterruptedException var6) {
                  this.log.log(new Throwable(), (Exception)var6);
               }

               this.pressedOk = false;
            }
            break;
         case 94756344:
            if(param.equals("close") && !this.lockInterface) {
               this.lockInterface = true;
               this.close();
               this.lockInterface = false;
            }
            break;
         case 550215928:
            if(param.equals("cancel2") && !this.lockInterface) {
               this.lockInterface = true;
               this.close();
               this.lockInterface = false;
            }
         }
      } catch (Exception var8) {
         this.lockInterface = false;
         this.pressedReturn = false;
         this.pressedOk = false;
         this.log.log(new Throwable(), var8);
      }

   }

   private void actionCountinuePrint() {
      try {
         this.btOk.setVisible(true);
         this.btReturn.setVisible(false);
         this.btCancel2.setVisible(false);
         this.error = "Заправьте бумагу";
         this.ajaxLoader = null;
         this.updateUI();
      } catch (Exception var2) {
         this.log.log(new Throwable(), var2);
      }

   }

   private void sendWCSale(Boolean close) throws UnknownHostException, IOException {
      try {
         XMLProtocol e = new XMLProtocol();
         TCPClient tcp = new TCPClient(this.cfg, this.log);
         String service = "wc";
         if(this.mode == 1) {
            service = "dhc";
         }

         if(this.mode == 2) {
            service = "bat";
         }

         String answer = tcp.Send(e.getXMLWCSale(this.cfg.getKioskId(), (int)(this.sumPay * 100.0F), this.kasbiFR.Session(), this.kasbiFR.CheckNumber(), service));
         ProtocolWCSale p = new ProtocolWCSale();
         this.error = p.Parse(answer);
         this.error = "";
         if(this.error != "") {
            if(this.error == "error") {
               this.error = "Операция завершилась неудачно";
               this.log.log(new Throwable(), this.error, true);
            }

            this.ajaxLoader = null;
            this.updateUI();
            this.btCancel.setVisible(true);
         } else if(close.booleanValue()) {
            this.succeed = Boolean.valueOf(true);
            this.showInfo = false;
            this.ajaxLoader = null;
            this.updateUI();
            this.btCancel.setVisible(false);

            try {
               Thread.sleep(1000L);
            } catch (InterruptedException var8) {
               this.log.log(new Throwable(), (Exception)var8);
            }

            this.close();
         }
      } catch (Exception var9) {
         this.log.log(new Throwable(), var9);
      }

   }

   public void SystemStateCompleted(SSActionData data) {
      try {
         this.sS = data.state;
         this.updateUI();
      } catch (Exception var3) {
         this.log.log(new Throwable(), var3);
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
