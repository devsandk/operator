package autolugstor.manager.control;

import java.awt.Color;
import java.awt.Font;
import java.awt.image.BufferedImage;
import javax.swing.ImageIcon;

public class ManagerControlLabelImageAdminItem {

   public BufferedImage[] blues = new BufferedImage[8];
   public BufferedImage[] greens = new BufferedImage[8];
   public BufferedImage[] limes = new BufferedImage[8];
   public BufferedImage[] reds = new BufferedImage[8];
   public BufferedImage[] yels = new BufferedImage[8];
   public BufferedImage[] grays = new BufferedImage[8];
   public BufferedImage[] blacks = new BufferedImage[8];
   public BufferedImage cellNull = null;
   private int y = 0;
   private int between = 0;
   public int calc_y = 0;
   public int calc_between = 0;
   public Font font = new Font("Dialog", 0, 12);
   public Color color;


   public ManagerControlLabelImageAdminItem(int Y, int B, Font f, Color c, BufferedImage cell_null, BufferedImage blue1, BufferedImage blue1_, BufferedImage blue2, BufferedImage blue2_, BufferedImage blue3, BufferedImage blue3_, BufferedImage blue4, BufferedImage blue4_, BufferedImage green1, BufferedImage green1_, BufferedImage green2, BufferedImage green2_, BufferedImage green3, BufferedImage green3_, BufferedImage green4, BufferedImage green4_, BufferedImage lime1, BufferedImage lime1_, BufferedImage lime2, BufferedImage lime2_, BufferedImage lime3, BufferedImage lime3_, BufferedImage lime4, BufferedImage lime4_, BufferedImage red1, BufferedImage red1_, BufferedImage red2, BufferedImage red2_, BufferedImage red3, BufferedImage red3_, BufferedImage red4, BufferedImage red4_, BufferedImage yel1, BufferedImage yel1_, BufferedImage yel2, BufferedImage yel2_, BufferedImage yel3, BufferedImage yel3_, BufferedImage yel4, BufferedImage yel4_, BufferedImage gray1, BufferedImage gray1_, BufferedImage gray2, BufferedImage gray2_, BufferedImage gray3, BufferedImage gray3_, BufferedImage gray4, BufferedImage gray4_, BufferedImage black1, BufferedImage black1_, BufferedImage black2, BufferedImage black2_, BufferedImage black3, BufferedImage black3_, BufferedImage black4, BufferedImage black4_) {
      this.color = Color.black;
      this.y = Y;
      this.between = B;
      this.font = f;
      this.color = c;
      this.cellNull = cell_null;
      this.blues[0] = blue1;
      this.blues[1] = blue1_;
      this.blues[2] = blue2;
      this.blues[3] = blue2_;
      this.blues[4] = blue3;
      this.blues[5] = blue3_;
      this.blues[6] = blue4;
      this.blues[7] = blue4_;
      this.greens[0] = green1;
      this.greens[1] = green1_;
      this.greens[2] = green2;
      this.greens[3] = green2_;
      this.greens[4] = green3;
      this.greens[5] = green3_;
      this.greens[6] = green4;
      this.greens[7] = green4_;
      this.limes[0] = lime1;
      this.limes[1] = lime1_;
      this.limes[2] = lime2;
      this.limes[3] = lime2_;
      this.limes[4] = lime3;
      this.limes[5] = lime3_;
      this.limes[6] = lime4;
      this.limes[7] = lime4_;
      this.reds[0] = red1;
      this.reds[1] = red1_;
      this.reds[2] = red2;
      this.reds[3] = red2_;
      this.reds[4] = red3;
      this.reds[5] = red3_;
      this.reds[6] = red4;
      this.reds[7] = red4_;
      this.yels[0] = yel1;
      this.yels[1] = yel1_;
      this.yels[2] = yel2;
      this.yels[3] = yel2_;
      this.yels[4] = yel3;
      this.yels[5] = yel3_;
      this.yels[6] = yel4;
      this.yels[7] = yel4_;
      this.grays[0] = gray1;
      this.grays[1] = gray1_;
      this.grays[2] = gray2;
      this.grays[3] = gray2_;
      this.grays[4] = gray3;
      this.grays[5] = gray3_;
      this.grays[6] = gray4;
      this.grays[7] = gray4_;
      this.blacks[0] = black1;
      this.blacks[1] = black1_;
      this.blacks[2] = black2;
      this.blacks[3] = black2_;
      this.blacks[4] = black3;
      this.blacks[5] = black3_;
      this.blacks[6] = black4;
      this.blacks[7] = black4_;
      this.CalcSizes();
   }

   private void CalcSizes() {
      this.calc_y = this.y;
      this.calc_between = this.between;
   }

   public ImageIcon getCellNull() {
      return new ImageIcon(this.cellNull);
   }

   public ImageIcon getBlue(int size) {
      return new ImageIcon(this.blues[2 * size - 2]);
   }

   public ImageIcon getBlue_(int size) {
      return new ImageIcon(this.blues[2 * size - 1]);
   }

   public ImageIcon getGreen(int size) {
      return new ImageIcon(this.greens[2 * size - 2]);
   }

   public ImageIcon getGreen_(int size) {
      return new ImageIcon(this.greens[2 * size - 1]);
   }

   public ImageIcon getLime(int size) {
      return new ImageIcon(this.limes[2 * size - 2]);
   }

   public ImageIcon getLime_(int size) {
      return new ImageIcon(this.limes[2 * size - 1]);
   }

   public ImageIcon getRed(int size) {
      return new ImageIcon(this.reds[2 * size - 2]);
   }

   public ImageIcon getRed_(int size) {
      return new ImageIcon(this.reds[2 * size - 1]);
   }

   public ImageIcon getYel(int size) {
      return new ImageIcon(this.yels[2 * size - 2]);
   }

   public ImageIcon getYel_(int size) {
      return new ImageIcon(this.yels[2 * size - 1]);
   }

   public ImageIcon getGray(int size) {
      return new ImageIcon(this.grays[2 * size - 2]);
   }

   public ImageIcon getGray_(int size) {
      return new ImageIcon(this.grays[2 * size - 1]);
   }

   public ImageIcon getBlack(int size) {
      return new ImageIcon(this.blacks[2 * size - 2]);
   }

   public ImageIcon getBlack_(int size) {
      return new ImageIcon(this.blacks[2 * size - 1]);
   }
}
