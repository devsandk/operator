package autolugstor.protocol;


public class ProtocolOperatorItem {

   public int id = 0;
   public String password = "";
   public String name = "";
   public int kkmpwd = 0;
   public int kkmadmpwd = 0;


   public ProtocolOperatorItem() {}

   public ProtocolOperatorItem(int id, String password, String name, int kkmpwd, int kkmadmpwd) {
      this.id = id;
      this.password = password;
      this.name = name;
      this.kkmpwd = kkmpwd;
      this.kkmadmpwd = kkmadmpwd;
   }
}
