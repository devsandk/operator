package autolugstor.protocol;

import java.io.StringReader;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;

public class ProtocolTariffWC {

   public String type = "";
   public String device = "";
   public String cmd = "";
   public int rate_sum = 1;
   public int rate_div = 1;


   public String Parse(String xml) {
      try {
         System.out.println("");
         System.out.println("Protocol AUTH:");
         DocumentBuilderFactory e = DocumentBuilderFactory.newInstance();
         e.setValidating(false);
         DocumentBuilder var13 = e.newDocumentBuilder();
         Document doc = var13.parse(new InputSource(new StringReader(xml)));
         NodeList node_list = doc.getChildNodes();
         NodeList node_body = node_list.item(0).getChildNodes();

         for(int i = 0; i < node_body.getLength(); ++i) {
            NodeList node_items;
            int k;
            String error1;
            if(node_body.item(i).getNodeName() == "header") {
               node_items = node_body.item(i).getChildNodes();

               for(k = 0; k < node_items.getLength(); ++k) {
                  String n;
                  switch((n = node_items.item(k).getNodeName()).hashCode()) {
                  case -1335157162:
                     if(n.equals("device")) {
                        this.device = node_items.item(k).getTextContent();
                     }
                     break;
                  case 98618:
                     if(n.equals("cmd")) {
                        this.cmd = node_items.item(k).getTextContent();
                     }
                     break;
                  case 3575610:
                     if(n.equals("type")) {
                        this.type = node_items.item(k).getTextContent();
                     }
                     break;
                  case 96784904:
                     if(n.equals("error")) {
                        error1 = node_items.item(k).getTextContent();
                        if(error1 == "") {
                           error1 = "error";
                        }

                        System.out.println("error: " + error1);
                        return error1;
                     }
                  }
               }
            }

            if(node_body.item(i).getNodeName() == "data") {
               node_items = node_body.item(i).getChildNodes();

               for(k = 0; k < node_items.getLength(); ++k) {
                  Node var14 = node_items.item(k);
                  switch((error1 = var14.getNodeName()).hashCode()) {
                  case 422613170:
                     if(error1.equals("rate_div")) {
                        this.rate_div = Integer.parseInt(var14.getTextContent());
                     }
                     break;
                  case 422627948:
                     if(error1.equals("rate_sum")) {
                        this.rate_sum = Integer.parseInt(var14.getTextContent());
                     }
                  }
               }
            }
         }

         System.out.println("<type>: " + this.type);
         System.out.println("<device>: " + this.device);
         System.out.println("<cmd>: " + this.cmd);
         System.out.println("<rate_sum>: " + this.rate_sum);
         System.out.println("<rate_div>: " + this.rate_div);
         System.out.println("");
         return "";
      } catch (Exception var12) {
         String error = "Сервер недоступен. Код ошибки 2.";
         System.out.println(error);
         return error;
      }
   }
}
