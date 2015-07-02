package autolugstor.protocol;

import java.io.StringReader;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;

public class ProtocolBSKTryReturn {

   public String type = "";
   public String device = "";
   public String cmd = "";
   public String card = "";
   public int btime = 0;
   public int sum = 0;


   public String Parse(String xml) {
      try {
         System.out.println("");
         System.out.println("Protocol BSKTryReturn:");
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
                  case 114251:
                     if(error1.equals("sum")) {
                        this.sum = Integer.parseInt(var14.getTextContent());
                     }
                     break;
                  case 3046160:
                     if(error1.equals("card")) {
                        this.card = var14.getTextContent();
                     }
                     break;
                  case 94065199:
                     if(error1.equals("btime")) {
                        this.btime = Integer.parseInt(var14.getTextContent());
                     }
                  }
               }
            }
         }

         System.out.println("<type>: " + this.type);
         System.out.println("<device>: " + this.device);
         System.out.println("<cmd>: " + this.cmd);
         System.out.println("<card>: " + this.card);
         System.out.println("<btime>: " + this.btime);
         System.out.println("<sum>: " + this.sum);
         System.out.println("");
         return "";
      } catch (Exception var12) {
         String error = "Сервер недоступен. Код ошибки 2.";
         System.out.println(error);
         return error;
      }
   }
}
