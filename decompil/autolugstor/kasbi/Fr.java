package autolugstor.kasbi;

import autolugstor.kasbi.Kasbifr;
import autolugstor.kasbi.ShtrihMfr;
import java.util.ArrayList;

public class Fr {

   final int tKasbi = 1;
   final int tShtrih = 2;
   private Kasbifr _kasbi = null;
   private ShtrihMfr _shtrihm = null;
   private String Address;
   private int Type;
   private int Password;


   public Fr(String address, int type, int password) {
      this.Address = address;
      this.Type = type;
      this.Password = password;
      if(this.Type == 1) {
         this._kasbi = new Kasbifr();
         this._kasbi.PortName = this.Address;
         this._kasbi.Password = this.Password;
      }

      if(this.Type == 2) {
         this._shtrihm = new ShtrihMfr();
         this._shtrihm.PortName = this.Address;
         this._shtrihm.Password = this.Password;
      }

   }

   public boolean ContinuePrint() throws InterruptedException {
      switch(this.Type) {
      case 1:
         return this._kasbi.ContinuePrint();
      case 2:
         return this._shtrihm.ContinuePrint();
      default:
         return false;
      }
   }

   public int XReport() throws InterruptedException {
      switch(this.Type) {
      case 1:
         return this._kasbi.XReport();
      case 2:
         return this._shtrihm.XReport();
      default:
         return -1;
      }
   }

   public int ZReport() throws InterruptedException {
      switch(this.Type) {
      case 1:
         return this._kasbi.ZReport();
      case 2:
         return this._shtrihm.ZReport();
      default:
         return -1;
      }
   }

   public int printDoc(ArrayList<String> slipText, String text, int price, int mul, int cash, boolean saleReturn, int section) throws Exception {
      switch(this.Type) {
      case 1:
         return this._kasbi.printDoc(slipText, text, price, mul, cash, saleReturn, section);
      case 2:
         return this._shtrihm.printDoc(slipText, text, price, mul, cash, saleReturn, section);
      default:
         return -1;
      }
   }

   public int Session() {
      switch(this.Type) {
      case 1:
         return this._kasbi.Session;
      case 2:
         return this._shtrihm.Session;
      default:
         return -1;
      }
   }

   public int CheckNumber() {
      switch(this.Type) {
      case 1:
         return this._kasbi.CheckNumber;
      case 2:
         return this._shtrihm.CheckNumber;
      default:
         return -1;
      }
   }

   public int ERR_OK() {
      switch(this.Type) {
      case 1:
         return 0;
      case 2:
         return 0;
      default:
         return -1;
      }
   }

   public int ERR_NEED_COUNTINUEPRINT() {
      switch(this.Type) {
      case 1:
         return 215;
      case 2:
         return 215;
      default:
         return -1;
      }
   }
}
