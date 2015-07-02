package autolugstor.protocol;

import autolugstor.protocol.ProtocolOperatorItem;
import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

public class ProtocolOperator {

   public String type = "";
   public String device = "";
   public String cmd = "";
   private List<ProtocolOperatorItem> items = new ArrayList();


   public String Parse(String xml) throws ParserConfigurationException, SAXException, IOException {
      try {
         System.out.println("");
         System.out.println("Protocol OPERATORS:");
         DocumentBuilderFactory e = DocumentBuilderFactory.newInstance();
         e.setValidating(false);
         DocumentBuilder var13 = e.newDocumentBuilder();
         Document doc = var13.parse(new InputSource(new StringReader(xml)));
         NodeList node_list = doc.getChildNodes();
         NodeList node_body = node_list.item(0).getChildNodes();

         int i;
         for(i = 0; i < node_body.getLength(); ++i) {
            NodeList node_items;
            int k;
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
                        String a = node_items.item(k).getTextContent();
                        System.out.println("error: " + a);
                        return a;
                     }
                  }
               }
            }

            if(node_body.item(i).getNodeName() == "data") {
               node_items = node_body.item(i).getChildNodes();

               for(k = 0; k < node_items.getLength(); ++k) {
                  Node var15 = node_items.item(k);
                  if(var15.getNodeName() == "item") {
                     NamedNodeMap var14 = var15.getAttributes();
                     this.items.add(new ProtocolOperatorItem(Integer.parseInt(var14.getNamedItem("id").getNodeValue()), var14.getNamedItem("password").getNodeValue(), var14.getNamedItem("name").getNodeValue(), Integer.parseInt(var14.getNamedItem("kkmpwd").getNodeValue()), Integer.parseInt(var14.getNamedItem("kkmadmpwd").getNodeValue())));
                  }
               }
            }
         }

         System.out.println("<type>: " + this.type);
         System.out.println("<device>: " + this.device);
         System.out.println("<cmd>: " + this.cmd);
         System.out.println("<operators_list> (" + this.items.size() + "):");

         for(i = 0; i < this.items.size(); ++i) {
            System.out.println("<item>: " + ((ProtocolOperatorItem)this.items.get(i)).toString());
         }

         System.out.println("");
         return "";
      } catch (Exception var12) {
         String error = "Сервер недоступен. Код ошибки 2.";
         System.out.println(error);
         return error;
      }
   }

   public List<ProtocolOperatorItem> getOperators() {
      return this.items;
   }
}
