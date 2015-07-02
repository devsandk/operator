package autolugstor.manager.control;

import java.awt.image.BufferedImage;
import javax.swing.ImageIcon;

public class ManagerControlItem {

   public final String xalign_no = "no";
   public final String xalign_left = "left";
   public final String xalign_center = "center";
   public final String xalign_right = "right";
   public final String yalign_no = "no";
   public final String yalign_top = "top";
   public final String yalign_center = "center";
   public final String yalign_bottom = "bottom";
   private int screenWidth;
   private int screenHeight;
   public BufferedImage image1 = null;
   public BufferedImage image2 = null;
   public BufferedImage image3 = null;
   public BufferedImage image4 = null;
   private String xAlign = "no";
   private String yAlign = "no";
   private int x = 0;
   private int y = 0;
   private int width = 0;
   private int height = 0;
   private int ident_left = 0;
   private int ident_right = 0;
   private int ident_top = 0;
   private int ident_bottom = 0;
   public int calc_x = 0;
   public int calc_y = 0;
   public int calc_width = 0;
   public int calc_height = 0;


   public ManagerControlItem(int screenwidth, int screenheight, BufferedImage img1, BufferedImage img2, BufferedImage img3, String xalign, String yalign, int X, int Y, int W, int H, int il, int ir, int it, int ib) {
      this.Init(screenwidth, screenheight, img1, img2, img3, xalign, yalign, X, Y, W, H, il, ir, it, ib);
   }

   public ManagerControlItem(int screenwidth, int screenheight, BufferedImage img1, BufferedImage img2, BufferedImage img3, BufferedImage img4, String xalign, String yalign, int X, int Y, int W, int H, int il, int ir, int it, int ib) {
      this.image4 = img4;
      this.Init(screenwidth, screenheight, img1, img2, img3, xalign, yalign, X, Y, W, H, il, ir, it, ib);
   }

   public void Init(int screenwidth, int screenheight, BufferedImage img1, BufferedImage img2, BufferedImage img3, String xalign, String yalign, int X, int Y, int W, int H, int il, int ir, int it, int ib) {
      this.screenWidth = screenwidth;
      this.screenHeight = screenheight;
      this.image1 = img1;
      this.image2 = img2;
      this.image3 = img3;
      this.xAlign = xalign;
      this.yAlign = yalign;
      this.x = X;
      this.y = Y;
      this.width = W;
      this.height = H;
      this.ident_left = il;
      this.ident_right = ir;
      this.ident_top = it;
      this.ident_bottom = ib;
      this.CalcSizes();
   }

   private void CalcSizes() {
      if(this.width <= 0) {
         this.calc_width = this.image1.getWidth();
      } else {
         this.calc_width = this.width;
      }

      if(this.height <= 0) {
         this.calc_height = this.image1.getHeight();
      } else {
         this.calc_height = this.height;
      }

      this.calc_x = this.x;
      this.calc_y = this.y;
      String var1 = this.xAlign;
      switch(this.xAlign.hashCode()) {
      case -1364013995:
         if(var1.equals("center")) {
            this.calc_x = (this.screenWidth - this.calc_width) / 2 + this.ident_left - this.ident_right;
         }
         break;
      case 3521:
         if(!var1.equals("no")) {
            ;
         }
         break;
      case 3317767:
         if(var1.equals("left")) {
            this.calc_x = 0 + this.ident_left;
         }
         break;
      case 108511772:
         if(var1.equals("right")) {
            this.calc_x = this.screenWidth - this.calc_width - this.ident_right;
         }
      }

      String var2 = this.yAlign;
      switch(this.yAlign.hashCode()) {
      case -1383228885:
         if(var2.equals("bottom")) {
            this.calc_y = this.screenHeight - this.calc_height - this.ident_bottom;
         }
         break;
      case -1364013995:
         if(var2.equals("center")) {
            this.calc_y = (this.screenHeight - this.calc_height) / 2 + this.ident_top - this.ident_bottom;
         }
         break;
      case 3521:
         if(!var2.equals("no")) {
            ;
         }
         break;
      case 115029:
         if(var2.equals("top")) {
            this.calc_y = 0 + this.ident_top;
         }
      }

   }

   public ImageIcon getIcon1() {
      return new ImageIcon(this.image1);
   }

   public ImageIcon getIcon2() {
      return new ImageIcon(this.image2);
   }

   public ImageIcon getIcon3() {
      return new ImageIcon(this.image3);
   }

   public ImageIcon getIcon4() {
      return new ImageIcon(this.image4);
   }
}
