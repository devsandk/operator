package autolugstor.protocol;

import autolugstor.protocol.ProtocolRateItem;
import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
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

public class ProtocolRateTable {

   public String type = "";
   public String device = "";
   public String cmd = "";
   private List<ProtocolRateItem> items = new ArrayList();
   private ProtocolRateItem[] rateTable = null;
   private int countSizes = 4;


   public List<ProtocolRateItem> get() {
      return this.items;
   }

   public String Parse(String xml) throws ParserConfigurationException, SAXException, IOException {
      try {
         System.out.println("");
         System.out.println("Protocol RATE TABLE:");
         DocumentBuilderFactory e = DocumentBuilderFactory.newInstance();
         e.setValidating(false);
         DocumentBuilder var14 = e.newDocumentBuilder();
         Document doc = var14.parse(new InputSource(new StringReader(xml)));
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
                  Node var16 = node_items.item(k);
                  if(var16.getNodeName() == "item") {
                     NamedNodeMap var15 = var16.getAttributes();
                     ProtocolRateItem pfci = new ProtocolRateItem(Integer.parseInt(var15.getNamedItem("hour").getNodeValue()), Integer.parseInt(var15.getNamedItem("sum").getNodeValue()), Integer.parseInt(var15.getNamedItem("size").getNodeValue()));
                     this.items.add(pfci);
                  }
               }
            }
         }

         this.rateTable = new ProtocolRateItem[this.items.size()];

         for(i = 0; i < this.rateTable.length; ++i) {
            this.rateTable[i] = (ProtocolRateItem)this.items.get(i);
         }

         Arrays.sort(this.rateTable);
         System.out.println("<type>: " + this.type);
         System.out.println("<device>: " + this.device);
         System.out.println("<cmd>: " + this.cmd);

         for(i = 0; i < this.rateTable.length; ++i) {
            System.out.println("<rate item>: " + this.rateTable[i].toString());
         }

         System.out.println("");
         return "";
      } catch (Exception var13) {
         String error = "Сервер недоступен. Код ошибки 2.";
         System.out.println(error);
         return error;
      }
   }

   public int getSum(int hour, int size) {
      int sum = 0;
      if(this.rateTable == null) {
         return sum;
      } else if(hour > this.rateTable.length / this.countSizes) {
         return sum;
      } else {
         for(int i = 0; i < hour * this.countSizes; ++i) {
            if(this.rateTable[i].size == size) {
               sum += this.rateTable[i].sum;
            }
         }

         return sum;
      }
   }

   public int getSumIndex(int index) {
      return this.rateTable == null?0:(index > this.rateTable.length?0:this.rateTable[index].sum);
   }
}
