package autolugstor.manager.control;

import java.awt.Color;
import java.awt.Font;
import java.awt.image.BufferedImage;
import javax.swing.ImageIcon;

public class ManagerControlFiguresItem {

   public BufferedImage image1 = null;
   public BufferedImage image2 = null;
   public BufferedImage image3 = null;
   public int xBegin = 0;
   public int yBegin = 0;
   public int Between = 0;
   public int calc_width = 0;
   public int calc_height = 0;
   public Font font = new Font("Dialog", 0, 12);
   public Color color;


   public ManagerControlFiguresItem(BufferedImage img1, BufferedImage img2, BufferedImage img3, int xbegin, int ybegin, int between, Font f, Color c) {
      this.color = Color.BLACK;
      this.image1 = img1;
      this.image2 = img2;
      this.image3 = img3;
      this.xBegin = xbegin;
      this.yBegin = ybegin;
      this.Between = between;
      this.font = f;
      this.color = c;
      this.CalcSizes();
   }

   private void CalcSizes() {
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
