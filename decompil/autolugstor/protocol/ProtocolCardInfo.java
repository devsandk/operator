package autolugstor.protocol;

import java.io.IOException;
import java.io.StringReader;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

public class ProtocolCardInfo {

   public static final String stateActive = "active";
   public static final String stateInactive = "inactive";
   public static final String statePayYes = "yes";
   public static final String statePayNo = "no";
   public static final String stateKeepNo = "no";
   public static final String stateKeepYes = "yes";
   public static final String stateCompletedNo = "no";
   public static final String stateCompletedYes = "yes";
   public String type = "";
   public String device = "";
   public String cmd = "";
   public String card = "";
   public String status = "inactive";
   public Date act_time = new Date();
   public Date end_time = new Date();
   public String need_pay = "no";
   public String keep = "no";
   public int pay_time = 0;
   public int pay_sum = 0;
   public int sec_index = 0;
   public int cell_index = 0;
   public int cell_pos = 0;
   public int cell_num = 0;
   public Date time = new Date();
   public int btime = 0;
   public String completed = "no";


   public String Parse(String xml) throws ParserConfigurationException, SAXException, IOException {
      try {
         System.out.println("");
         System.out.println("Protocol CARD INFO:");
         DocumentBuilderFactory e = DocumentBuilderFactory.newInstance();
         e.setValidating(false);
         DocumentBuilder var18 = e.newDocumentBuilder();
         Document doc = var18.parse(new InputSource(new StringReader(xml)));
         SimpleDateFormat sdf = new SimpleDateFormat("yyyy.MM.dd-HH:mm:ss");
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
                  case 3560141:
                     if(n.equals("time")) {
                        try {
                           this.time = sdf.parse(node_items.item(k).getTextContent());
                        } catch (ParseException var14) {
                           var14.printStackTrace();
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
                        error1 = node_items.item(k).getTextContent();
                        System.out.println("error: " + error1);
                        return error1;
                     }
                  }
               }
            }

            if(node_body.item(i).getNodeName() == "data") {
               node_items = node_body.item(i).getChildNodes();

               for(k = 0; k < node_items.getLength(); ++k) {
                  Node var19 = node_items.item(k);
                  switch((error1 = var19.getNodeName()).hashCode()) {
                  case -1665261990:
                     if(error1.equals("act_time")) {
                        try {
                           this.act_time = sdf.parse(var19.getTextContent());
                        } catch (ParseException var16) {
                           var16.printStackTrace();
                        }
                     }
                     break;
                  case -1402931637:
                     if(error1.equals("completed")) {
                        this.completed = var19.getTextContent();
                     }
                     break;
                  case -1279981724:
                     if(error1.equals("sec_index")) {
                        this.sec_index = Integer.parseInt(var19.getTextContent());
                     }
                     break;
                  case -1013054539:
                     if(error1.equals("cell_index")) {
                        this.cell_index = Integer.parseInt(var19.getTextContent());
                     }
                     break;
                  case -917249239:
                     if(error1.equals("cell_num")) {
                        this.cell_num = Integer.parseInt(var19.getTextContent());
                     }
                     break;
                  case -917247497:
                     if(error1.equals("cell_pos")) {
                        this.cell_pos = Integer.parseInt(var19.getTextContent());
                     }
                     break;
                  case -892481550:
                     if(error1.equals("status")) {
                        this.status = var19.getTextContent();
                        if(!this.status.equals("active") && !this.status.equals("inactive")) {
                           this.status = "inactive";
                        }
                     }
                     break;
                  case -787084748:
                     if(error1.equals("pay_sum")) {
                        this.pay_sum = Integer.parseInt(var19.getTextContent());
                     }
                     break;
                  case 3046160:
                     if(error1.equals("card")) {
                        this.card = var19.getTextContent();
                     }
                     break;
                  case 3287941:
                     if(error1.equals("keep")) {
                        this.keep = var19.getTextContent();
                        if(!this.keep.equals("no") && !this.keep.equals("yes")) {
                           this.keep = "no";
                        }
                     }
                     break;
                  case 94065199:
                     if(error1.equals("btime")) {
                        this.btime = Integer.parseInt(var19.getTextContent());
                     }
                     break;
                  case 866004351:
                     if(error1.equals("need_pay")) {
                        this.need_pay = var19.getTextContent();
                        if(!this.need_pay.equals("no") && !this.need_pay.equals("yes")) {
                           this.need_pay = "no";
                        }
                     }
                     break;
                  case 1370194948:
                     if(error1.equals("pay_time")) {
                        this.pay_time = Integer.parseInt(var19.getTextContent());
                     }
                     break;
                  case 1725551537:
                     if(error1.equals("end_time")) {
                        try {
                           this.end_time = sdf.parse(var19.getTextContent());
                        } catch (ParseException var15) {
                           var15.printStackTrace();
                        }
                     }
                  }
               }
            }
         }

         System.out.println("<type>: " + this.type);
         System.out.println("<device>: " + this.device);
         System.out.println("<cmd>: " + this.cmd);
         System.out.println("<time>: " + this.time);
         System.out.println("<card>: " + this.card);
         System.out.println("<status>: " + this.status);
         System.out.println("<act_time>: " + this.act_time);
         System.out.println("<end_time>: " + this.end_time);
         System.out.println("<need_pay>: " + this.need_pay);
         System.out.println("<sec_index>: " + this.sec_index);
         System.out.println("<cell_index>: " + this.cell_index);
         System.out.println("<cell_pos>: " + this.cell_pos);
         System.out.println("");
         return "";
      } catch (Exception var17) {
         String error = "Сервер недоступен. Код ошибки 2.";
         System.out.println(error);
         return error;
      }
   }
}
