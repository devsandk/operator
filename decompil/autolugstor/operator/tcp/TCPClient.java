package autolugstor.operator.tcp;

import autolugstor.log.Logger;
import autolugstor.operator.configuration.Configuration;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.nio.charset.Charset;

public class TCPClient {

   public static final String errorConnectionFailed = "Сервер недоступен. Код ошибки 1.";
   private Configuration cfg;
   private String error = "";
   private Logger log;


   public TCPClient(Configuration config, Logger log) {
      this.cfg = config;
      this.log = log;
   }

   public String Send(String send) {
      System.out.println("");
      System.out.println("tcp_client > to server: " + send);
      String serverAnswer = "";

      try {
         Socket e = new Socket();
         e.setSoTimeout(5000);
         InetAddress AddrAsIAdr = InetAddress.getByName(this.cfg.getIpAddress());
         e.connect(new InetSocketAddress(AddrAsIAdr, this.cfg.getIpPort()), 5000);
         DataOutputStream outToServer = new DataOutputStream(e.getOutputStream());
         BufferedReader inFromServer = new BufferedReader(new InputStreamReader(e.getInputStream(), "UTF-8"));
         OutputStreamWriter out = new OutputStreamWriter(outToServer, Charset.forName("UTF-8"));
         out.write(send + "\n\n");
         out.flush();
         Boolean b = Boolean.valueOf(true);

         for(String s = null; b.booleanValue(); serverAnswer = serverAnswer + s) {
            s = inFromServer.readLine();
            if(s == null) {
               break;
            }
         }

         out.close();
         inFromServer.close();
         e.close();
         System.out.println("tcp_client < from server: " + serverAnswer);
         System.out.println("");
      } catch (Exception var10) {
         serverAnswer = "";
         this.error = "Сервер недоступен. Код ошибки 1.";
         System.out.println("tcp_client connection failed!");
         this.log.log(new Throwable(), "tcp_client connection failed!", true);
         this.log.log(new Throwable(), var10);
      }

      if(serverAnswer.length() > 0) {
         serverAnswer = serverAnswer.substring(0, serverAnswer.length() - 1);
      }

      return serverAnswer;
   }

   public String getError() {
      return this.error;
   }
}
