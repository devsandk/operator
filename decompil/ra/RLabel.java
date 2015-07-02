package ra;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class RLabel extends JLabel {

   private static final long serialVersionUID = 1L;
   private Font fontString = new Font("Dialog", 0, 12);
   private Color colorString;
   private int Id;
   public boolean checked;
   public Object obj;
   public int cell_index;
   public int sec_index;
   public int hall_index;
   public int cell_pos;
   public ImageIcon icon1;
   public ImageIcon icon2;
   public ImageIcon icon3;
   public ImageIcon icon4;


   public RLabel() {
      this.colorString = Color.BLACK;
      this.Id = 0;
      this.checked = false;
      this.obj = null;
      this.cell_index = -1;
      this.sec_index = -1;
      this.hall_index = -1;
      this.cell_pos = -1;
      this.icon1 = null;
      this.icon2 = null;
      this.icon3 = null;
      this.icon4 = null;
   }

   public RLabel(ImageIcon icon) {
      this.colorString = Color.BLACK;
      this.Id = 0;
      this.checked = false;
      this.obj = null;
      this.cell_index = -1;
      this.sec_index = -1;
      this.hall_index = -1;
      this.cell_pos = -1;
      this.icon1 = null;
      this.icon2 = null;
      this.icon3 = null;
      this.icon4 = null;
      this.setIcon(icon);
   }

   public void paintComponent(Graphics g) {
      super.paintComponent(g);
      Graphics2D g2 = (Graphics2D)g;
      g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
      FontMetrics fm = g2.getFontMetrics(this.fontString);
      int x = (this.getWidth() - fm.stringWidth(this.getText())) / 2;
      int y = (this.getHeight() - fm.getHeight()) / 2 + fm.getHeight() - 5;
      g2.setColor(this.colorString);
      g2.setFont(this.fontString);
      g2.drawString(this.getText(), x, y);
      g2.finalize();
   }

   public void setFontString(Font font) {
      this.fontString = font;
   }

   public void setColorString(Color color) {
      this.colorString = color;
   }

   public void setId(int id) {
      this.Id = id;
   }

   public int getId() {
      return this.Id;
   }
}
