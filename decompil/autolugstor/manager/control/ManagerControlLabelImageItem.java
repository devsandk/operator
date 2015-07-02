package autolugstor.manager.control;

import java.awt.Color;
import java.awt.Font;
import java.awt.image.BufferedImage;
import javax.swing.ImageIcon;

public class ManagerControlLabelImageItem {

   public BufferedImage image_on1 = null;
   public BufferedImage image_off1 = null;
   public BufferedImage image_on2 = null;
   public BufferedImage image_off2 = null;
   public BufferedImage image_on3 = null;
   public BufferedImage image_off3 = null;
   public BufferedImage image_on4 = null;
   public BufferedImage image_off4 = null;
   private int y = 0;
   private int between = 0;
   public int calc_y = 0;
   public int calc_between = 0;
   public int calc_width1 = 0;
   public int calc_height1 = 0;
   public int calc_width2 = 0;
   public int calc_height2 = 0;
   public int calc_width3 = 0;
   public int calc_height3 = 0;
   public int calc_width4 = 0;
   public int calc_height4 = 0;
   public Font font = new Font("Dialog", 0, 12);
   public Color color;


   public ManagerControlLabelImageItem(BufferedImage imgon1, BufferedImage imgoff1, BufferedImage imgon2, BufferedImage imgoff2, BufferedImage imgon3, BufferedImage imgoff3, BufferedImage imgon4, BufferedImage imgoff4, int Y, int B, Font f, Color c) {
      this.color = Color.black;
      this.image_on1 = imgon1;
      this.image_off1 = imgoff1;
      this.image_on2 = imgon2;
      this.image_off2 = imgoff2;
      this.image_on3 = imgon3;
      this.image_off3 = imgoff3;
      this.image_on4 = imgon4;
      this.image_off4 = imgoff4;
      this.y = Y;
      this.between = B;
      this.font = f;
      this.color = c;
      this.CalcSizes();
   }

   private void CalcSizes() {
      this.calc_y = this.y;
      this.calc_between = this.between;
      this.calc_width1 = this.image_on1.getWidth();
      this.calc_height1 = this.image_on1.getHeight();
      this.calc_width2 = this.image_on2.getWidth();
      this.calc_height2 = this.image_on2.getHeight();
      this.calc_width3 = this.image_on3.getWidth();
      this.calc_height3 = this.image_on3.getHeight();
      this.calc_width4 = this.image_on4.getWidth();
      this.calc_height4 = this.image_on4.getHeight();
   }

   public ImageIcon getIconOn1() {
      return new ImageIcon(this.image_on1);
   }

   public ImageIcon getIconOff1() {
      return new ImageIcon(this.image_off1);
   }

   public ImageIcon getIconOn2() {
      return new ImageIcon(this.image_on2);
   }

   public ImageIcon getIconOff2() {
      return new ImageIcon(this.image_off2);
   }

   public ImageIcon getIconOn3() {
      return new ImageIcon(this.image_on3);
   }

   public ImageIcon getIconOff3() {
      return new ImageIcon(this.image_off3);
   }

   public ImageIcon getIconOn4() {
      return new ImageIcon(this.image_on4);
   }

   public ImageIcon getIconOff4() {
      return new ImageIcon(this.image_off4);
   }
}
