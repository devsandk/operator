package autolugstor.manager.control;

import java.awt.image.BufferedImage;
import javax.swing.ImageIcon;

public class ManagerControlHallItem {

   public BufferedImage image1 = null;
   public BufferedImage image2 = null;
   public BufferedImage image3 = null;
   private int y = 0;
   private int between = 0;
   public int calc_y = 0;
   public int calc_between = 0;
   public int calc_width = 0;
   public int calc_height = 0;


   public ManagerControlHallItem(BufferedImage img1, BufferedImage img2, BufferedImage img3, int Y, int B) {
      this.image1 = img1;
      this.image2 = img2;
      this.image3 = img3;
      this.y = Y;
      this.between = B;
      this.CalcSizes();
   }

   private void CalcSizes() {
      this.calc_y = this.y;
      this.calc_between = this.between;
      this.calc_width = this.image1.getWidth();
      this.calc_height = this.image1.getHeight();
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
}
