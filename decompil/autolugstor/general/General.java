package autolugstor.general;

import autolugstor.manager.image.ManagerImage;
import autolugstor.manager.image.ManagerImageAnimationItem;
import autolugstor.manager.image.ManagerImageItem;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.image.ImageObserver;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.GregorianCalendar;

public class General {

   public String NameOfMonth(int n) {
      switch(n) {
      case 0:
         return "Января";
      case 1:
         return "Февраля";
      case 2:
         return "Марта";
      case 3:
         return "Апреля";
      case 4:
         return "Мая";
      case 5:
         return "Июня";
      case 6:
         return "Июля";
      case 7:
         return "Августа";
      case 8:
         return "Сентября";
      case 9:
         return "Октября";
      case 10:
         return "Ноября";
      case 11:
         return "Декабря";
      default:
         return "Не знаю";
      }
   }

   public void drawManagers(ManagerImage mI, Graphics2D g2, ImageObserver obsrv) {
      try {
         int ex;
         for(ex = 0; ex < mI.items.length; ++ex) {
            ManagerImageItem m = mI.items[ex];
            if(m.getVisible().booleanValue()) {
               g2.drawImage(m.image, m.calc_x, m.calc_y, m.calc_width, m.calc_height, obsrv);
            }
         }

         for(ex = 0; ex < mI.animations.length; ++ex) {
            ManagerImageAnimationItem var7 = mI.animations[ex];
            if(var7.getVisible().booleanValue()) {
               g2.drawImage(var7.image, var7.calc_x, var7.calc_y, var7.calc_width, var7.calc_height, obsrv);
            }
         }
      } catch (Exception var6) {
         System.out.println("EX: General.drawManagers(): " + var6.getMessage());
      }

   }

   public void drawSystemState(ManagerImage mI, Graphics2D g2, String state, int w) {
      if(state != "") {
         Font f = new Font("Arial", 0, 24);
         g2.setFont(f);
         g2.setColor(Color.red);
         g2.fillRect(0, 0, w, 110);
         g2.setColor(Color.white);
         g2.drawString(state, 30, 60);
      }

   }

   public String getFormatCurrentTime() {
      SimpleDateFormat formatter = new SimpleDateFormat("HH:mm");
      return formatter.format(new Date());
   }

   public String getFormatCurrentTime(Date date) {
      SimpleDateFormat formatter = new SimpleDateFormat("HH:mm");
      return formatter.format(date);
   }

   public String getFormatCurrentDate() {
      GregorianCalendar g = new GregorianCalendar();
      return g.get(5) + " " + this.NameOfMonth(g.get(2)) + " " + g.get(1);
   }

   public String getFormatCurrentDate(GregorianCalendar g) {
      return g.get(5) + " " + this.NameOfMonth(g.get(2)) + " " + g.get(1);
   }

   public String getFormatConvertTime(long ms) {
      long s = ms / 1000L;
      long m = s / 60L;
      long h = m / 60L;
      long m_left = m - h * 60L;
      return h + " час. " + m_left + " мин.";
   }

   public String getFormatConvertTimeByMinute(int m) {
      long h = (long)(m / 60);
      long m_left = (long)m - h * 60L;
      return h + " час. " + m_left + " мин.";
   }

   public void drawAjaxLoader(int screenWidth, int screenHeight, Graphics2D g2, ImageObserver observer) {
      Image ajaxLoader = Toolkit.getDefaultToolkit().getImage("img/ajax-loader.gif");
      short w = 220;
      byte h = 19;
      int x = (screenWidth - w) / 2;
      int y = (screenHeight - h) / 2;
      g2.drawImage(ajaxLoader, x, y, w, h, observer);
   }

   public void drawAjaxLoader(int screenWidth, int screenHeight, Graphics2D g2, Image ajaxLoader, ImageObserver observer) {
      if(ajaxLoader != null) {
         short w = 220;
         byte h = 19;
         int x = (screenWidth - w) / 2;
         int y = (screenHeight - h) / 2;
         g2.drawImage(ajaxLoader, x, y, w, h, observer);
      }
   }

   public void drawError(int screenWidth, int screenHeight, Graphics2D g2, String error) {
      this.drawError(screenWidth, screenHeight, g2, error, 22);
   }

   public void drawError(int screenWidth, int screenHeight, Graphics2D g2, String error, int fontSize) {
      Font f = new Font("Dialog", 1, fontSize);
      FontMetrics fm = g2.getFontMetrics(f);
      int x = (screenWidth - fm.stringWidth(error)) / 2;
      int y = (screenHeight - fm.getHeight()) / 2;
      g2.setColor(Color.red);
      g2.setFont(f);
      g2.drawString(error, x, y);
   }

   public void drawVersion(int screenWidth, int screenHeight, Graphics2D g2, String version) {
      Font f = new Font("Dialog", 0, 12);
      FontMetrics fm = g2.getFontMetrics(f);
      byte x = 5;
      int y = screenHeight - fm.getHeight();
      g2.setColor(Color.BLACK);
      g2.setFont(f);
      g2.drawString(version, x, y);
   }
}
