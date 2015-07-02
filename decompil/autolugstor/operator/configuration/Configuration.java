package autolugstor.operator.configuration;

import java.awt.Dimension;
import java.awt.Toolkit;
import java.io.File;
import java.io.IOException;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class Configuration {

   private final String file = "config/configuration.xml";
   private String cardReaderAddress = "/dev/ttyUSB0";
   private int screenWidth = 1024;
   private int screenHeight = 768;
   public String ipAddress = "127.0.0.1";
   public int ipPort = 80;
   private int pingPeriod = 60;
   private String kioskId = "0";
   private String docRules = "";
   public int Hall = 1;
   public int Reader = 1;
   public String FrAddress = "/dev/ttyS0";
   public int FrType = 1;
   public int FrPassword = 30;


   public Configuration() {
      try {
         this.Load();
      } catch (IOException var2) {
         var2.printStackTrace();
      }

   }

   private void Load() throws ParserConfigurationException, SAXException, IOException {
      System.out.println("");
      System.out.println("load configuration...");
      DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
      f.setValidating(false);
      DocumentBuilder builder = f.newDocumentBuilder();
      Document doc = builder.parse(new File("config/configuration.xml"));
      NodeList node_images = doc.getChildNodes();
      NodeList children = node_images.item(0).getChildNodes();

      for(int i = 0; i < children.getLength(); ++i) {
         Node node = children.item(i);
         NamedNodeMap attributes = node.getAttributes();
         String var9;
         switch((var9 = node.getNodeName()).hashCode()) {
         case -934979389:
            if(var9.equals("reader")) {
               this.Reader = Integer.parseInt(attributes.getNamedItem("type").getNodeValue());
               System.out.println("<reader>: " + this.Reader);
            }
            break;
         case -907689876:
            if(var9.equals("screen")) {
               this.screenWidth = Integer.parseInt(attributes.getNamedItem("width").getNodeValue());
               this.screenHeight = Integer.parseInt(attributes.getNamedItem("height").getNodeValue());
               Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
               if(this.screenWidth <= 0) {
                  this.screenWidth = d.width;
               }

               if(this.screenHeight <= 0) {
                  this.screenHeight = d.height;
               }

               System.out.println("<dimension>: " + this.screenWidth + "x" + this.screenHeight);
            }
            break;
         case -905826493:
            if(var9.equals("server")) {
               this.ipAddress = attributes.getNamedItem("ip").getNodeValue();
               this.ipPort = Integer.parseInt(attributes.getNamedItem("port").getNodeValue());
               this.pingPeriod = Integer.parseInt(attributes.getNamedItem("ping").getNodeValue());
               if(this.pingPeriod < 10) {
                  this.pingPeriod = 10;
               }

               this.kioskId = attributes.getNamedItem("id").getNodeValue();
               System.out.println("<server>: " + this.ipAddress + ":" + this.ipPort + " ping=" + this.pingPeriod + " id=" + this.kioskId);
            }
            break;
         case 3276:
            if(var9.equals("fr")) {
               this.FrAddress = attributes.getNamedItem("address").getNodeValue();
               this.FrType = Integer.parseInt(attributes.getNamedItem("type").getNodeValue());
               this.FrPassword = Integer.parseInt(attributes.getNamedItem("password").getNodeValue());
               System.out.println("<fr>: address=" + this.FrAddress + " type=" + this.FrType + " password=" + this.FrPassword);
            }
            break;
         case 3088955:
            if(var9.equals("docs")) {
               this.docRules = attributes.getNamedItem("rules").getNodeValue();
               System.out.println("<docs>: rules=" + this.docRules);
            }
            break;
         case 3194937:
            if(var9.equals("hall")) {
               this.Hall = Integer.parseInt(attributes.getNamedItem("number").getNodeValue());
               System.out.println("<hall>: " + this.Hall);
            }
            break;
         case 1523533779:
            if(var9.equals("cardreader")) {
               this.cardReaderAddress = attributes.getNamedItem("address").getNodeValue();
               System.out.println("<cardreader>: " + this.cardReaderAddress);
            }
         }
      }

      System.out.println("configuration loaded");
      System.out.println("");
   }

   public String getCardReaderAddress() {
      return this.cardReaderAddress;
   }

   public int getScreenWidth() {
      return this.screenWidth;
   }

   public int getScreenHeight() {
      return this.screenHeight;
   }

   public String getIpAddress() {
      return this.ipAddress;
   }

   public int getIpPort() {
      return this.ipPort;
   }

   public int getPingPeriod() {
      return this.pingPeriod;
   }

   public String getKioskId() {
      return this.kioskId;
   }

   public String getDocRules() {
      return this.docRules;
   }
}
