package autolugstor.protocol;

import java.io.StringReader;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;

public class ProtocolWCSale {

   public String type = "";
   public String device = "";
   public String cmd = "";
   public String skey = "";
   public String fio = "";


   public String Parse(String xml) {
      try {
         System.out.println("");
         System.out.println("Protocol WCSale:");
         DocumentBuilderFactory e = DocumentBuilderFactory.newInstance();
         e.setValidating(false);
         DocumentBuilder var13 = e.newDocumentBuilder();
         Document doc = var13.parse(new InputSource(new StringReader(xml)));
         NodeList node_list = doc.getChildNodes();
         NodeList node_body = node_list.item(0).getChildNodes();

         for(int i = 0; i < node_body.getLength(); ++i) {
            if(node_body.item(i).getNodeName() == "header") {
               NodeList node_header = node_body.item(i).getChildNodes();

               for(int k = 0; k < node_header.getLength(); ++k) {
                  String var10;
                  switch((var10 = node_header.item(k).getNodeName()).hashCode()) {
                  case -1335157162:
                     if(var10.equals("device")) {
                        this.device = node_header.item(k).getTextContent();
                     }
                     break;
                  case 98618:
                     if(var10.equals("cmd")) {
                        this.cmd = node_header.item(k).getTextContent();
                     }
                     break;
                  case 3575610:
                     if(var10.equals("type")) {
                        this.type = node_header.item(k).getTextContent();
                     }
                     break;
                  case 96784904:
                     if(var10.equals("error")) {
                        String error1 = node_header.item(k).getTextContent();
                        if(error1 == "") {
                           error1 = "error";
                        }

                        System.out.println("error: " + error1);
                        return error1;
                     }
                  }
               }
            }
         }

         System.out.println("<type>: " + this.type);
         System.out.println("<device>: " + this.device);
         System.out.println("<cmd>: " + this.cmd);
         System.out.println("<skey>: " + this.skey);
         System.out.println("<fio>: " + this.fio);
         System.out.println("");
         return "";
      } catch (Exception var12) {
         String error = "Сервер недоступен. Код ошибки 2.";
         System.out.println(error);
         return error;
      }
   }
}
