package autolugstor.manager;

import autolugstor.manager.ManagerEvents;
import autolugstor.manager.control.ManagerControlItem;
import autolugstor.manager.control.ManagerControlLabelItem;
import java.awt.Container;
import java.awt.Cursor;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JLabel;
import javax.swing.JTextField;
import ra.RLabel;

public class ManagerObject {

   private ManagerControlItem mCI = null;
   private ManagerEvents managerEvent = null;
   private String managerAction = null;
   private Object object = null;
   private Boolean isChecked = Boolean.valueOf(false);
   private Boolean isExited = Boolean.valueOf(false);


   public JLabel addManagerControlButton(ManagerControlItem mci, Container container, ManagerEvents i, String action) {
      this.mCI = mci;
      this.managerEvent = i;
      this.managerAction = action;
      JLabel lbl = new JLabel(this.mCI.getIcon1());
      lbl.setBounds(this.mCI.calc_x, this.mCI.calc_y, this.mCI.calc_width, this.mCI.calc_height);
      container.add(lbl);
      lbl.setCursor(Cursor.getPredefinedCursor(12));
      lbl.addMouseListener(new MouseListener() {
         public void mouseReleased(MouseEvent arg0) {
            JLabel l = (JLabel)arg0.getSource();
            l.setIcon(ManagerObject.this.mCI.getIcon1());
            if(!ManagerObject.this.isExited.booleanValue() && l.isEnabled()) {
               ManagerObject.this.managerEvent.activateManagerItem(ManagerObject.this.managerAction);
            }

         }
         public void mousePressed(MouseEvent arg0) {
            JLabel l = (JLabel)arg0.getSource();
            if(l.isEnabled()) {
               l.setIcon(ManagerObject.this.mCI.getIcon3());
            }

         }
         public void mouseExited(MouseEvent arg0) {
            ManagerObject.this.isExited = Boolean.valueOf(true);
            JLabel l = (JLabel)arg0.getSource();
            if(l.isEnabled()) {
               l.setIcon(ManagerObject.this.mCI.getIcon1());
            }

         }
         public void mouseEntered(MouseEvent arg0) {
            ManagerObject.this.isExited = Boolean.valueOf(false);
            JLabel l = (JLabel)arg0.getSource();
            if(l.isEnabled()) {
               l.setIcon(ManagerObject.this.mCI.getIcon2());
            }

         }
         public void mouseClicked(MouseEvent arg0) {}
      });
      return lbl;
   }

   public JLabel addManagerControlLabel(ManagerControlLabelItem mci, Container container, String text) {
      JLabel lbl = new JLabel(text);
      lbl.setFont(mci.font);
      lbl.setForeground(mci.color);
      lbl.setBounds(mci.calc_x, mci.calc_y, mci.calc_width, mci.calc_height);
      container.add(lbl);
      return lbl;
   }

   public JTextField addManagerControlTextField(ManagerControlLabelItem mci, Container container, String text) {
      JTextField lbl = new JTextField(text);
      lbl.setFont(mci.font);
      lbl.setForeground(mci.color);
      lbl.setBounds(mci.calc_x, mci.calc_y, mci.calc_width, mci.calc_height);
      container.add(lbl);
      return lbl;
   }

   public RLabel addManagerControlRButton(ManagerControlItem mci, Container container, ManagerEvents i, String text, String action) {
      this.mCI = mci;
      this.managerEvent = i;
      this.managerAction = action;
      RLabel lbl = new RLabel(this.mCI.getIcon1());
      this.object = lbl;
      lbl.setBounds(this.mCI.calc_x, this.mCI.calc_y, this.mCI.calc_width, this.mCI.calc_height);
      lbl.setText(text);
      container.add(lbl);
      lbl.setCursor(Cursor.getPredefinedCursor(12));
      lbl.addMouseListener(new MouseListener() {
         public void mouseReleased(MouseEvent arg0) {
            RLabel l = (RLabel)arg0.getSource();
            if(!ManagerObject.this.isChecked.booleanValue() && l.isEnabled()) {
               l.setIcon(ManagerObject.this.mCI.getIcon1());
            }

            if(!ManagerObject.this.isExited.booleanValue() && l.isEnabled()) {
               ManagerObject.this.managerEvent.activateManagerItem(ManagerObject.this.managerAction);
            }

         }
         public void mousePressed(MouseEvent arg0) {
            RLabel l = (RLabel)arg0.getSource();
            if(!ManagerObject.this.isChecked.booleanValue() && l.isEnabled()) {
               l.setIcon(ManagerObject.this.mCI.getIcon3());
            }

         }
         public void mouseExited(MouseEvent arg0) {
            ManagerObject.this.isExited = Boolean.valueOf(true);
            RLabel l = (RLabel)arg0.getSource();
            if(!ManagerObject.this.isChecked.booleanValue() && l.isEnabled()) {
               l.setIcon(ManagerObject.this.mCI.getIcon1());
            }

         }
         public void mouseEntered(MouseEvent arg0) {
            ManagerObject.this.isExited = Boolean.valueOf(false);
            RLabel l = (RLabel)arg0.getSource();
            if(!ManagerObject.this.isChecked.booleanValue() && l.isEnabled()) {
               l.setIcon(ManagerObject.this.mCI.getIcon2());
            }

         }
         public void mouseClicked(MouseEvent arg0) {}
      });
      return lbl;
   }

   public void setRLabelChecked(Boolean b) {
      this.isChecked = b;
      RLabel l = (RLabel)this.object;
      if(this.isChecked.booleanValue()) {
         l.setIcon(this.mCI.getIcon4());
      } else {
         l.setIcon(this.mCI.getIcon1());
      }

   }

   public Boolean getChecked() {
      return this.isChecked;
   }
}
