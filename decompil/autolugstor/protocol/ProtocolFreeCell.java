package autolugstor.protocol;

import autolugstor.protocol.Hall;
import autolugstor.protocol.ProtocolFreeCellItem;
import java.io.IOException;
import java.io.StringReader;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
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

public class ProtocolFreeCell {

   public String type = "";
   public String device = "";
   public String cmd = "";
   private List<Hall> listHall = new ArrayList();
   private List<ProtocolFreeCellItem> items = new ArrayList();


   public int getHallCount() {
      return this.listHall.size();
   }

   public List<Hall> getHalls() {
      return this.listHall;
   }

   public Hall get(int index) {
      return (Hall)this.listHall.get(index);
   }

   public Boolean isFree(int hall, int sec_index, int cell_index) {
      Boolean r = Boolean.valueOf(false);

      for(int i = 0; i < this.items.size(); ++i) {
         if(((ProtocolFreeCellItem)this.items.get(i)).hall == hall && ((ProtocolFreeCellItem)this.items.get(i)).cell_index == cell_index && ((ProtocolFreeCellItem)this.items.get(i)).sec_index == sec_index && ((ProtocolFreeCellItem)this.items.get(i)).isfree.equals("yes")) {
            return Boolean.valueOf(true);
         }
      }

      return r;
   }

   public int getNum(int hall, int sec_index, int cell_index) {
      for(int i = 0; i < this.items.size(); ++i) {
         if(((ProtocolFreeCellItem)this.items.get(i)).hall == hall && ((ProtocolFreeCellItem)this.items.get(i)).cell_index == cell_index && ((ProtocolFreeCellItem)this.items.get(i)).sec_index == sec_index && ((ProtocolFreeCellItem)this.items.get(i)).isfree.equals("yes")) {
            return ((ProtocolFreeCellItem)this.items.get(i)).cell_num;
         }
      }

      return -1;
   }

   public ProtocolFreeCellItem getItem(int hall, int sec_index, int cell_pos) {
      for(int i = 0; i < this.items.size(); ++i) {
         if(((ProtocolFreeCellItem)this.items.get(i)).hall == hall && ((ProtocolFreeCellItem)this.items.get(i)).cell_pos == cell_pos && ((ProtocolFreeCellItem)this.items.get(i)).sec_index == sec_index) {
            return (ProtocolFreeCellItem)this.items.get(i);
         }
      }

      return null;
   }

   public String getCurNumbers(int hall, int sec_begin, int sec_end) {
      ArrayList num = new ArrayList();

      int min;
      for(min = 0; min < this.items.size(); ++min) {
         if(((ProtocolFreeCellItem)this.items.get(min)).hall == hall && ((ProtocolFreeCellItem)this.items.get(min)).sec_index >= sec_begin && ((ProtocolFreeCellItem)this.items.get(min)).sec_index <= sec_end && ((ProtocolFreeCellItem)this.items.get(min)).cell_num != 99999) {
            num.add(Integer.valueOf(((ProtocolFreeCellItem)this.items.get(min)).cell_num));
         }
      }

      min = 0;
      int max = 0;
      if(num.size() > 0) {
         min = ((Integer)num.get(0)).intValue();
         max = ((Integer)num.get(0)).intValue();
      }

      for(int i = 0; i < num.size(); ++i) {
         if(((Integer)num.get(i)).intValue() < min) {
            min = ((Integer)num.get(i)).intValue();
         }

         if(((Integer)num.get(i)).intValue() > max) {
            max = ((Integer)num.get(i)).intValue();
         }
      }

      return min + " - " + max;
   }

   public int getCountSection() {
      ArrayList sec = new ArrayList();
      boolean f = false;
      int i = 0;

      while(i < this.items.size()) {
         f = false;
         int k = 0;

         while(true) {
            if(k < sec.size()) {
               if(((Integer)sec.get(k)).intValue() != ((ProtocolFreeCellItem)this.items.get(i)).sec_index) {
                  ++k;
                  continue;
               }

               f = true;
            }

            if(!f) {
               sec.add(Integer.valueOf(((ProtocolFreeCellItem)this.items.get(i)).sec_index));
            }

            ++i;
            break;
         }
      }

      return sec.size();
   }

   public int getFreeCellsCount(int hall) {
      int count = 0;

      for(int i = 0; i < this.items.size(); ++i) {
         if(((ProtocolFreeCellItem)this.items.get(i)).hall == hall && ((ProtocolFreeCellItem)this.items.get(i)).isfree.equals("yes")) {
            ++count;
         }
      }

      return count;
   }

   public int getFreeCellsCount() {
      int count = 0;

      for(int i = 0; i < this.items.size(); ++i) {
         if(((ProtocolFreeCellItem)this.items.get(i)).isfree.equals("yes")) {
            ++count;
         }
      }

      return count;
   }

   public ProtocolFreeCellItem getItemByNum(int cell_num) {
      for(int i = 0; i < this.items.size(); ++i) {
         if(((ProtocolFreeCellItem)this.items.get(i)).cell_num == cell_num) {
            return (ProtocolFreeCellItem)this.items.get(i);
         }
      }

      return null;
   }

   public String Parse(String xml) throws ParserConfigurationException, SAXException, IOException {
      try {
         System.out.println("");
         System.out.println("Protocol FREE CELLS:");
         DocumentBuilderFactory e = DocumentBuilderFactory.newInstance();
         e.setValidating(false);
         DocumentBuilder var22 = e.newDocumentBuilder();
         Document doc = var22.parse(new InputSource(new StringReader(xml)));
         SimpleDateFormat sdf = new SimpleDateFormat("yyyy.MM.dd-HH:mm:ss");
         Date time = new Date();
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
                  case 3560141:
                     if(n.equals("time")) {
                        try {
                           time = sdf.parse(node_items.item(k).getTextContent());
                        } catch (ParseException var20) {
                           var20.printStackTrace();
                        }
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
                  Node var23 = node_items.item(k);
                  if(var23.getNodeName() == "item") {
                     NamedNodeMap var24 = var23.getAttributes();
                     ProtocolFreeCellItem pfci = new ProtocolFreeCellItem(time, Integer.parseInt(var24.getNamedItem("hall").getNodeValue()), Integer.parseInt(var24.getNamedItem("sec_index").getNodeValue()), Integer.parseInt(var24.getNamedItem("sec_num").getNodeValue()), Integer.parseInt(var24.getNamedItem("cell_index").getNodeValue()), Integer.parseInt(var24.getNamedItem("cell_size").getNodeValue()), Integer.parseInt(var24.getNamedItem("cell_num").getNodeValue()), var24.getNamedItem("active").getNodeValue(), var24.getNamedItem("isfree").getNodeValue(), var24.getNamedItem("net_address").getNodeValue(), var24.getNamedItem("state").getNodeValue(), var24.getNamedItem("root_access").getNodeValue(), Integer.parseInt(var24.getNamedItem("cell_pos").getNodeValue()));

                     for(int x = 0; x < var24.getLength(); ++x) {
                        String var16;
                        switch((var16 = var24.item(x).getNodeName()).hashCode()) {
                        case -1665261990:
                           if(var16.equals("act_time")) {
                              try {
                                 pfci.act_time = sdf.parse(var24.item(x).getNodeValue());
                              } catch (ParseException var19) {
                                 var19.printStackTrace();
                              }
                           }
                           break;
                        case -978672681:
                           if(var16.equals("adm_cell")) {
                              pfci.adm_cell = var24.item(x).getNodeValue();
                           }
                           break;
                        case -787084748:
                           if(var16.equals("pay_sum")) {
                              pfci.pay_sum = Integer.parseInt(var24.item(x).getNodeValue());
                           }
                           break;
                        case 3046160:
                           if(var16.equals("card")) {
                              pfci.card = var24.item(x).getNodeValue();
                           }
                           break;
                        case 866004351:
                           if(var16.equals("need_pay")) {
                              pfci.need_pay = var24.item(x).getNodeValue();
                           }
                           break;
                        case 1370194948:
                           if(var16.equals("pay_time")) {
                              pfci.pay_time = Integer.parseInt(var24.item(x).getNodeValue());
                           }
                           break;
                        case 1725551537:
                           if(var16.equals("end_time")) {
                              try {
                                 pfci.end_time = sdf.parse(var24.item(x).getNodeValue());
                              } catch (ParseException var18) {
                                 var18.printStackTrace();
                              }
                           }
                        }
                     }

                     this.items.add(pfci);
                  }
               }
            }
         }

         System.out.println("<type>: " + this.type);
         System.out.println("<device>: " + this.device);
         System.out.println("<cmd>: " + this.cmd);
         System.out.println("<cell_list> (" + this.items.size() + "):");

         for(i = 0; i < this.items.size(); ++i) {
            System.out.println("<item>: " + ((ProtocolFreeCellItem)this.items.get(i)).toString());
         }

         System.out.println("");
         return "";
      } catch (Exception var21) {
         String error = "Сервер недоступен. Код ошибки 2.";
         System.out.println(error);
         return error;
      }
   }

   public void DataProcessing() {
      System.out.println("");
      System.out.println("Protocol FREE CELLS DataProcessing:");
      this.listHall.clear();
      Boolean find = Boolean.valueOf(false);
      int i = 0;

      while(i < this.items.size()) {
         find = Boolean.valueOf(false);
         int k = 0;

         while(true) {
            if(k < this.listHall.size()) {
               if(((Hall)this.listHall.get(k)).getNumber() != ((ProtocolFreeCellItem)this.items.get(i)).hall) {
                  ++k;
                  continue;
               }

               find = Boolean.valueOf(true);
            }

            if(!find.booleanValue()) {
               this.listHall.add(new Hall(((ProtocolFreeCellItem)this.items.get(i)).hall));
            }

            ++i;
            break;
         }
      }

      System.out.println("hall count=" + this.listHall.size());
      System.out.println("");
   }
}
