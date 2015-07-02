package autolugstor.protocol;


public class XMLProtocol {

   public static final String SEVICE_WC = "wc";
   public static final String SEVICE_MOBILE = "bat";
   public static final String SEVICE_DOUCHE = "dhc";


   private String getXMLStart() {
      return "<msg id=\"vt.avkar.kiosk\">";
   }

   private String getXMLEnd() {
      return "</msg>";
   }

   private String getXMLHeader(String type, String id, String cmd) {
      return "<header><type>" + type + "</type>" + "<device>" + id + "</device>" + "<cmd>" + cmd + "</cmd>" + "</header>";
   }

   private String getXMLHeader(String type, String id, String cmd, int hall, int secbegin, int secend, int cellnum) {
      return "<header><type>" + type + "</type>" + "<device>" + id + "</device>" + "<cmd>" + cmd + "</cmd>" + "<hall>" + hall + "</hall>" + "<sec_index_begin>" + secbegin + "</sec_index_begin>" + "<sec_index_end>" + secend + "</sec_index_end>" + "<cell_num>" + cellnum + "</cell_num>" + "</header>";
   }

   public String getXMLPing(String kioskId) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "ping") + this.getXMLEnd();
   }

   public String getXMLInfoCard(String kioskId, String cardId) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "get_card") + "<data>" + "<card>" + cardId + "</card>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLStateCells(String kioskId, int hall, int secbegin, int secend) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "get_cells", hall, secbegin, secend, 0) + this.getXMLEnd();
   }

   public String getXMLStateCells(String kioskId, int hall, int cellnum) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "get_cells", hall, 0, 0, cellnum) + this.getXMLEnd();
   }

   public String getXMLUserStartSession(String id, String cardId) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "auth") + " <data>" + "<password>" + cardId + "</password> " + "</data>" + this.getXMLEnd();
   }

   public String getXMLUserEndSession(String id, String sessId) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "quit") + "<data>" + "<skey>" + sessId + "</skey>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLBSKRegistration(String id, String cardId, int sec_num, int cell_index) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "try_card") + "<data>" + "<card>" + cardId + "</card>" + "<sec_num>" + sec_num + "</sec_num>" + "<cell_index>" + cell_index + "</cell_index>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLBSKSale(String id, String cardId, int btime, int sum, int kkmses, int kkmcheck, int sec_num, int cell_index) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "buy_card") + "<data>" + "<card>" + cardId + "</card>" + "<btime>" + btime + "</btime>" + "<sum>" + sum + "</sum>" + "<kkmses>" + kkmses + "</kkmses>" + "<kkmcheck>" + kkmcheck + "</kkmcheck>" + "<sec_num>" + sec_num + "</sec_num>" + "<cell_index>" + cell_index + "</cell_index>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLBSKSurcharge(String id, String cardId, int btime, int sum, int kkmses, int kkmcheck) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "add_pay") + "<data>" + "<card>" + cardId + "</card>" + "<btime>" + btime + "</btime>" + "<sum>" + sum + "</sum>" + "<kkmses>" + kkmses + "</kkmses>" + "<kkmcheck>" + kkmcheck + "</kkmcheck>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLBSKReturn(String id, String cardId, int btime, int sum, int kkmses, int kkmcheck) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "return_card") + "<data>" + "<card>" + cardId + "</card>" + "<btime>" + btime + "</btime>" + "<sum>" + sum + "</sum>" + "<kkmses>" + kkmses + "</kkmses>" + "<kkmcheck>" + kkmcheck + "</kkmcheck>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLTariff(String kioskId) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "get_rate") + this.getXMLEnd();
   }

   public String getXMLBSKTryReturn(String id, String cardId) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "try_return") + "<data>" + "<card>" + cardId + "</card>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLAdminStartSession(String id, String cardId) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "auth_adm") + " <data>" + "<password>" + cardId + "</password> " + "</data>" + this.getXMLEnd();
   }

   public String getTariffNew(String id, int sum, int rate) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "add_rate") + "<data>" + "<rate_sum>" + sum + "</rate_sum>" + "<rate_div>" + rate + "</rate_div>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLOperators(String kioskId) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "get_users") + this.getXMLEnd();
   }

   public String getXMLOperatorChangePwd(String devid, int id, String pwd, String name, int kkmpwd, int kkmadmpwd) {
      return this.getXMLStart() + this.getXMLHeader("query", devid, "edit_users") + "<data>" + "<item id=\"" + id + "\" password=\"" + pwd + "\" name=\"" + name + "\" kkmpwd=\"" + kkmpwd + "\" kkmadmpwd=\"" + kkmadmpwd + "\"/>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLAdminRootAccess(String id, int sec_num, int cell_index, String access) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "root_access") + "<data>" + "<item sec_num=\"" + sec_num + "\" cell_index=\"" + cell_index + "\" access=\"" + access + "\"/>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLAntiTerror(String kioskId) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "anti_terror") + this.getXMLEnd();
   }

   public String getXMLResetAntiTerror(String kioskId) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "reset_terror") + this.getXMLEnd();
   }

   public String getXMLSetFree(String id, int sec_num, int cell_index) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "set_free") + "<data>" + "<item sec_num=\"" + sec_num + "\" cell_index=\"" + cell_index + "\"/>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLRateTable(String kioskId) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "get_rate_table") + this.getXMLEnd();
   }

   public String getXMLTariffWC(String kioskId, String service) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "get_wc_rate") + "<data>" + "<service>" + service + "</service>" + "</data>" + this.getXMLEnd();
   }

   public String getTariffWCNew(String id, int sum, int rate, String service) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "add_wc_rate") + "<data>" + "<rate_sum>" + sum + "</rate_sum>" + "<rate_div>" + rate + "</rate_div>" + "<service>" + service + "</service>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLWCSale(String id, int sum, int kkmses, int kkmcheck, String service) {
      return this.getXMLStart() + this.getXMLHeader("query", id, "pay_wc") + "<data>" + "<sum>" + sum + "</sum>" + "<kkmses>" + kkmses + "</kkmses>" + "<kkmcheck>" + kkmcheck + "</kkmcheck>" + "<service>" + service + "</service>" + "</data>" + this.getXMLEnd();
   }

   public String getXMLCellEnable(String kioskId, int secnum, int cellindex, String active) {
      return this.getXMLStart() + this.getXMLHeader("query", kioskId, "set_enable") + "<data>" + "<item sec_num=" + secnum + " cell_index=" + cellindex + " active=" + active + "/>" + "</data>" + this.getXMLEnd();
   }
}
