package autolugstor.operator.tcp;

import java.util.GregorianCalendar;

public class SSActionData {

   public GregorianCalendar time;
   public String state;
   public boolean isAntiterror;
   public int free_cells;
   public int free_cards;


   public SSActionData(GregorianCalendar time, String state, boolean isAntiterror, int free_cells, int free_cards) {
      this.time = time;
      this.state = state;
      this.isAntiterror = isAntiterror;
      this.free_cells = free_cells;
      this.free_cards = free_cards;
   }
}
