import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import autolugstor.operator.frames.MainFrame;

public class AKHOperator {

   public static void main(String[] args) {
      Logger log = new Logger("operator");
      log.log(new Throwable(), "start");
      Configuration config = new Configuration();
      MainFrame f = new MainFrame(config, log);
      f.setDefaultCloseOperation(3);
      f.setVisible(true);
      f.toFront();
      System.out.println("exit");
   }
}
