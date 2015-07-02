package autolugstor.protocol;

import java.io.StringReader;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;

public class ProtocolPing {

   public String type = "";
   public String device = "";
   public String cmd = "";
   public Date time;
   public boolean isAntiterror = false;
   public int free_cells = 0;
   public int free_cards = 0;


   public String Parse(String xml) {
      String error = "";

      try {
         System.out.println("");
         System.out.println("Protocol SYSTEM STATE:");
         DocumentBuilderFactory e = DocumentBuilderFactory.newInstance();
         e.setValidating(false);
         DocumentBuilder builder = e.newDocumentBuilder();
         Document doc = builder.parse(new InputSource(new StringReader(xml)));
         SimpleDateFormat sdf = new SimpleDateFormat("yyyy.MM.dd-HH:mm:ss");
         NodeList node_list = doc.getChildNodes();
         NodeList node_body = node_list.item(0).getChildNodes();

         for(int i = 0; i < node_body.getLength(); ++i) {
            if(node_body.item(i).getNodeName() == "header") {
               NodeList node_header = node_body.item(i).getChildNodes();

               for(int k = 0; k < node_header.getLength(); ++k) {
                  String var12;
                  switch((var12 = node_header.item(k).getNodeName()).hashCode()) {
                  case -1715797615:
                     if(var12.equals("anti_terror")) {
                        this.isAntiterror = true;
                     }
                     break;
                  case -1335157162:
                     if(var12.equals("device")) {
                        this.device = node_header.item(k).getTextContent();
                     }
                     break;
                  case -567943216:
                     if(var12.equals("free_cards")) {
                        this.free_cards = Integer.parseInt(node_header.item(k).getTextContent());
                     }
                     break;
                  case -567829570:
                     if(var12.equals("free_cells")) {
                        this.free_cells = Integer.parseInt(node_header.item(k).getTextContent());
                     }
                     break;
                  case 98618:
                     if(var12.equals("cmd")) {
                        this.cmd = node_header.item(k).getTextContent();
                     }
                     break;
                  case 3560141:
                     if(var12.equals("time")) {
                        try {
                           this.time = sdf.parse(node_header.item(k).getTextContent());
                        } catch (ParseException var14) {
                           var14.printStackTrace();
                        }
                     }
                     break;
                  case 3575610:
                     if(var12.equals("type")) {
                        this.type = node_header.item(k).getTextContent();
                     }
                     break;
                  case 96784904:
                     if(var12.equals("error")) {
                        error = node_header.item(k).getTextContent();
                        if(error == "") {
                           error = "error";
                        }

                        System.out.println("error: " + error);
                     }
                  }
               }
            }
         }

         System.out.println("<type>: " + this.type);
         System.out.println("<device>: " + this.device);
         System.out.println("<cmd>: " + this.cmd);
         System.out.println("<free_cells>: " + this.free_cells);
         System.out.println("<free_cards>: " + this.free_cards);
         System.out.println("");
         return error;
      } catch (Exception var15) {
         error = "Сервер недоступен. Код ошибки 2.";
         System.out.println(error);
         return error;
      }
   }
}
