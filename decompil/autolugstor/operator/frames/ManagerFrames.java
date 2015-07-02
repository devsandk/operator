package autolugstor.operator.frames;

import autolugstor.log.Logger;
import autolugstor.manager.control.ManagerControlAddpaycell;
import autolugstor.manager.control.ManagerControlAdmin;
import autolugstor.manager.control.ManagerControlAnti;
import autolugstor.manager.control.ManagerControlFree;
import autolugstor.manager.control.ManagerControlFreeCell;
import autolugstor.manager.control.ManagerControlKassa;
import autolugstor.manager.control.ManagerControlOCardInfo;
import autolugstor.manager.control.ManagerControlOMain;
import autolugstor.manager.control.ManagerControlOOper;
import autolugstor.manager.control.ManagerControlOReturn;
import autolugstor.manager.control.ManagerControlOSale;
import autolugstor.manager.control.ManagerControlOSaleAction;
import autolugstor.manager.control.ManagerControlOWC;
import autolugstor.manager.image.ManagerImage;

public class ManagerFrames {

   public ManagerImage miMain;
   public ManagerControlOMain mcMain;
   public ManagerImage miAdmin;
   public ManagerControlAdmin mcAdmin;
   public ManagerImage miOper;
   public ManagerControlOOper mcOper;
   public ManagerImage miAnti;
   public ManagerControlAnti mcAnti;
   public ManagerImage miLogin;
   public ManagerImage miKassa;
   public ManagerControlKassa mcKassa;
   public ManagerImage miFree;
   public ManagerControlFree mcFree;
   public ManagerImage miFreeCell;
   public ManagerControlFreeCell mcFreeCell;
   public ManagerImage miCardInfo;
   public ManagerControlOCardInfo mcCardInfo;
   public ManagerImage miReturn;
   public ManagerControlOReturn mcReturn;
   public ManagerImage miSaleAction;
   public ManagerControlOSaleAction mcSaleAction;
   public ManagerImage miSale;
   public ManagerControlOSale mcSale;
   public ManagerImage miAddpaycell;
   public ManagerControlAddpaycell mcAddpaycell;
   public ManagerImage miWC;
   public ManagerControlOWC mcWC;


   public ManagerFrames(int w, int h, Logger log) {
      this.miMain = new ManagerImage("config/mi_main.xml", w, h);
      this.mcMain = new ManagerControlOMain("config/mc_main.xml", w, h);
      this.miAdmin = new ManagerImage("config/mi_admin.xml", w, h);
      this.mcAdmin = new ManagerControlAdmin("config/mc_admin.xml", w, h);
      this.miOper = new ManagerImage("config/mi_oper.xml", w, h);
      this.mcOper = new ManagerControlOOper("config/mc_oper.xml", w, h);
      this.miAnti = new ManagerImage("config/mi_anti.xml", w, h);
      this.mcAnti = new ManagerControlAnti("config/mc_anti.xml", w, h);
      this.miLogin = new ManagerImage("config/mi_login.xml", w, h);
      this.miKassa = new ManagerImage("config/mi_kassa.xml", w, h);
      this.mcKassa = new ManagerControlKassa("config/mc_kassa.xml", w, h);
      this.miFree = new ManagerImage("config/mi_free.xml", w, h);
      this.mcFree = new ManagerControlFree("config/mc_free.xml", w, h);
      this.miFreeCell = new ManagerImage("config/mi_freecells.xml", w, h);
      this.mcFreeCell = new ManagerControlFreeCell("config/mc_freecells.xml", w, h);
      this.miCardInfo = new ManagerImage("config/mi_cardinfo.xml", w, h);
      this.mcCardInfo = new ManagerControlOCardInfo("config/mc_cardinfo.xml", w, h);
      this.miReturn = new ManagerImage("config/mi_return.xml", w, h);
      this.mcReturn = new ManagerControlOReturn("config/mc_return.xml", w, h);
      this.miSaleAction = new ManagerImage("config/mi_saleaction.xml", w, h);
      this.mcSaleAction = new ManagerControlOSaleAction("config/mc_saleaction.xml", w, h);
      this.miSale = new ManagerImage("config/mi_sale.xml", w, h);
      this.mcSale = new ManagerControlOSale("config/mc_sale.xml", w, h);
      this.miAddpaycell = new ManagerImage("config/mi_addpaycell.xml", w, h);
      this.mcAddpaycell = new ManagerControlAddpaycell("config/mc_addpaycell.xml", w, h);
      this.miWC = new ManagerImage("config/mi_wc.xml", w, h);
      this.mcWC = new ManagerControlOWC("config/mc_wc.xml", w, h);

      try {
         this.miMain.Load();
         this.mcMain.Load();
         this.miAdmin.Load();
         this.mcAdmin.Load();
         this.miOper.Load();
         this.mcOper.Load();
         this.miAnti.Load();
         this.mcAnti.Load();
         this.miLogin.Load();
         this.miKassa.Load();
         this.mcKassa.Load();
         this.miFree.Load();
         this.mcFree.Load();
         this.miFreeCell.Load();
         this.mcFreeCell.Load();
         this.miCardInfo.Load();
         this.mcCardInfo.Load();
         this.miReturn.Load();
         this.mcReturn.Load();
         this.miSaleAction.Load();
         this.mcSaleAction.Load();
         this.miSale.Load();
         this.mcSale.Load();
         this.miAddpaycell.Load();
         this.mcAddpaycell.Load();
         this.miWC.Load();
         this.mcWC.Load();
      } catch (Exception var5) {
         log.log(new Throwable(), var5);
      }

   }
}
