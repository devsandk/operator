package autolugstor.protocol;


public class ProtocolRateItem implements Comparable<Object> {

   public int hour = 0;
   public int sum = 0;
   public int size = 1;


   public ProtocolRateItem(int hour, int sum, int size) {
      this.hour = hour;
      this.sum = sum;
      this.size = size;
   }

   public String toString() {
      return "hour=" + this.hour + ", sum=" + this.sum + ", size=" + this.size;
   }

   public int compareTo(Object obj) {
      ProtocolRateItem tmp = (ProtocolRateItem)obj;
      return this.hour < tmp.hour?-1:(this.hour > tmp.hour?1:0);
   }
}
