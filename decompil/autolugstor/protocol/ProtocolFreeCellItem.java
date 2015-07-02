package autolugstor.protocol;

import java.util.Date;

public class ProtocolFreeCellItem {

   public static final int CELL_SIZE_TYPE1 = 1;
   public static final int CELL_SIZE_TYPE2 = 2;
   public static final int CELL_SIZE_TYPE3 = 3;
   public static final int CELL_SIZE_TYPE4 = 4;
   public static final String CELL_STATE_YES = "yes";
   public static final String CELL_STATE_NO = "no";
   public static final String CELL_STATE_FREE = "free";
   public static final String CELL_STATE_FREE2 = "free2";
   public static final String CELL_STATE_ACTIVISATION = "activisation";
   public static final String CELL_STATE_GUARD = "guard";
   public static final String CELL_STATE_REPAY = "repay";
   public static final String CELL_STATE_OPEN = "open";
   public static final String CELL_STATE_OPENED = "opened";
   public static final String CELL_STATE_OPENKEY = "open key";
   public static final String CELL_STATE_ALARM = "alarm";
   public static final String CELL_STATE_ERRORCOM = "error_com";
   public Date time;
   public int hall = 0;
   public int sec_index = 0;
   public int sec_num = 0;
   public int cell_index = 0;
   public int cell_size = 0;
   public int cell_num = 0;
   public String active = "no";
   public String isfree = "no";
   public String net_address = "";
   public String state = "";
   public String root_access = "no";
   public int cell_pos = 0;
   public String card = "";
   public Date act_time = null;
   public Date end_time = null;
   public String need_pay = "";
   public int pay_time = 0;
   public int pay_sum = 0;
   public String adm_cell = "no";


   public ProtocolFreeCellItem(Date time, int h, int si, int sn, int ci, int cs, int cn, String a, String i, String net, String state, String root_access, int cell_pos) {
      this.time = time;
      this.hall = h;
      this.sec_index = si;
      this.sec_num = sn;
      this.cell_index = ci;
      this.cell_size = cs;
      this.cell_num = cn;
      this.active = a;
      this.isfree = i;
      this.net_address = net;
      this.state = state;
      this.root_access = root_access;
      this.cell_pos = cell_pos;
   }

   public String toString() {
      String s = "adm_cell=" + this.adm_cell + ", hall=" + this.hall + ", sec_index=" + this.sec_index + ", sec_num=" + this.sec_num + ", cell_index=" + this.cell_index + ", cell_size=" + this.cell_size + ", cell_num=" + this.cell_num + ", active=" + this.active + ", isfree=" + this.isfree + ", net_address=" + this.net_address + ", state=" + this.state + ", root_access=" + this.root_access + ", cell_pos=" + this.cell_pos + ", card=" + this.card + ", need_pay=" + this.need_pay + ", pay_time=" + this.pay_time + ", pay_sum=" + this.pay_sum;
      if(this.act_time != null) {
         s = s + ", act_time=" + this.act_time;
      }

      if(this.end_time != null) {
         s = s + ", end_time=" + this.end_time;
      }

      return s;
   }

   public String getString() {
      String ruState = "?";
      String var2 = this.state;
      switch(this.state.hashCode()) {
      case -1010579351:
         if(var2.equals("opened")) {
            ruState = "ЗАГРУЗКА";
         }
         break;
      case -506193015:
         if(var2.equals("open key")) {
            ruState = "АВАРИЯ";
         }
         break;
      case 3151468:
         if(var2.equals("free")) {
            ruState = "СВОБОДНО";
         }
         break;
      case 3417674:
         if(var2.equals("open")) {
            ruState = "ЗАГРУЗКА";
         }
         break;
      case 92895825:
         if(var2.equals("alarm")) {
            ruState = "АВАРИЯ";
         }
         break;
      case 97695558:
         if(var2.equals("free2")) {
            ruState = "СВОБОДНО";
         }
         break;
      case 98705061:
         if(var2.equals("guard")) {
            ruState = "ОХРАНА";
         }
         break;
      case 108401045:
         if(var2.equals("repay")) {
            ruState = "ДОПЛАТА";
         }
         break;
      case 329858762:
         if(var2.equals("error_com")) {
            ruState = "АВАРИЯ";
         }
         break;
      case 1578965484:
         if(var2.equals("activisation")) {
            ruState = "ЗАГРУЗКА";
         }
      }

      String ruAccess = "ЗАПРЕЩЕН";
      if(this.root_access.equals("yes")) {
         ruAccess = "РАЗРЕШЕН";
      }

      String res = "Статус: " + ruState + "; Админ.: " + ruAccess;
      if(this.isfree.equals("no") && this.need_pay.equals("no")) {
         long ruEnable = this.act_time.getTime();
         long ms_end = this.end_time.getTime();
         long ms_now = this.time.getTime();
         long ms_total = ms_end - ruEnable;
         long ms_elapsed = ms_now - ruEnable;
         long ms_left = ms_total - ms_elapsed;
         long s = ms_left / 1000L;
         long m1 = s / 60L;
         long h = m1 / 60L;
         long min = m1 - h * 60L;
         res = res + "; Осталось: " + h + "ч. " + min + "мин.";
      }

      if(this.need_pay.equals("yes")) {
         int ruEnable1 = this.pay_time / 60;
         int m = this.pay_time - ruEnable1 * 60;
         res = res + "; ДОПЛАТА: " + ruEnable1 + "ч " + m + "мин/" + (float)this.pay_sum / 100.0F + "руб";
      }

      String ruEnable2 = "НЕТ";
      if(this.active.equals("no")) {
         ruEnable2 = "ДА";
      }

      res = res + "; Блокировка: " + ruEnable2;
      return res;
   }
}
