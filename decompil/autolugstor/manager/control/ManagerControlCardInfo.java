package autolugstor.manager.control;

import autolugstor.manager.control.ManagerControlCardInfoLabelItem;
import autolugstor.manager.control.ManagerControlItem;
import autolugstor.manager.control.ManagerControlLabelItem;
import java.awt.Color;
import java.awt.Font;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class ManagerControlCardInfo {

   private int screenWidth;
   private int screenHeight;
   private final String pathImg = "img/";
   private String fileConfig = "";
   public ManagerControlItem mciBack = null;
   public ManagerControlCardInfoLabelItem mciHead = null;
   public ManagerControlCardInfoLabelItem mciLFH = null;
   public ManagerControlCardInfoLabelItem mciLF = null;
   public ManagerControlLabelItem mciTime = null;
   public ManagerControlLabelItem mciDate = null;


   public ManagerControlCardInfo(String file, int screenwidth, int screenheight) {
      this.fileConfig = file;
      this.screenWidth = screenwidth;
      this.screenHeight = screenheight;
   }

   public void Load() throws ParserConfigurationException, SAXException, IOException {
      System.out.println("ManagerControlCard load...");
      DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
      f.setValidating(false);
      DocumentBuilder builder = f.newDocumentBuilder();
      Document doc = builder.parse(new File(this.fileConfig));
      NodeList node_images = doc.getChildNodes();
      NodeList children = node_images.item(0).getChildNodes();

      for(int i = 0; i < children.getLength(); ++i) {
         Node node = children.item(i);
         if(node.getNodeName() == "bt-back") {
            this.load_bt(node);
         }

         if(node.getNodeName() == "labels") {
            this.load_labels(node);
         }

         if(node.getNodeName() == "lb-time" || node.getNodeName() == "lb-date") {
            this.load_lb(node);
         }
      }

      System.out.println("ManagerControlCard loaded");
   }

   private void load_bt(Node node) throws IOException {
      NamedNodeMap attributes = node.getAttributes();
      Node attribImg1 = attributes.getNamedItem("img1");
      Node attribImg2 = attributes.getNamedItem("img2");
      Node attribImg3 = attributes.getNamedItem("img3");
      Node attribXA = attributes.getNamedItem("xalign");
      Node attribYA = attributes.getNamedItem("yalign");
      Node attribX = attributes.getNamedItem("x");
      Node attribY = attributes.getNamedItem("y");
      Node attribW = attributes.getNamedItem("width");
      Node attribH = attributes.getNamedItem("height");
      Node attribIL = attributes.getNamedItem("ident-left");
      Node attribIR = attributes.getNamedItem("ident-right");
      Node attribIT = attributes.getNamedItem("ident-top");
      Node attribIB = attributes.getNamedItem("ident-bottom");
      File input1 = new File("img/" + attribImg1.getNodeValue());
      BufferedImage bfimg1 = ImageIO.read(input1);
      File input2 = new File("img/" + attribImg2.getNodeValue());
      BufferedImage bfimg2 = ImageIO.read(input2);
      File input3 = new File("img/" + attribImg3.getNodeValue());
      BufferedImage bfimg3 = ImageIO.read(input3);
      if(node.getNodeName() == "bt-back") {
         this.mciBack = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

   }

   private void load_labels(Node node) throws IOException {
      NamedNodeMap attributes = node.getAttributes();
      Node attribH = attributes.getNamedItem("head-color");
      Node attribLFH = attributes.getNamedItem("lfh-color");
      Node attribLF = attributes.getNamedItem("lf-color");
      Color colorH = new Color(Integer.parseInt(attribH.getNodeValue()));
      Color colorLFH = new Color(Integer.parseInt(attribLFH.getNodeValue()));
      Color colorLF = new Color(Integer.parseInt(attribLF.getNodeValue()));
      this.mciHead = new ManagerControlCardInfoLabelItem(colorH);
      this.mciLFH = new ManagerControlCardInfoLabelItem(colorLFH);
      this.mciLF = new ManagerControlCardInfoLabelItem(colorLF);
   }

   private void load_lb(Node node) throws IOException {
      NamedNodeMap attributes = node.getAttributes();
      Node attribXA = attributes.getNamedItem("xalign");
      Node attribYA = attributes.getNamedItem("yalign");
      Node attribX = attributes.getNamedItem("x");
      Node attribY = attributes.getNamedItem("y");
      Node attribW = attributes.getNamedItem("width");
      Node attribH = attributes.getNamedItem("height");
      Node attribFName = attributes.getNamedItem("font-name");
      Node attribFColor = attributes.getNamedItem("font-color");
      Node attribFSize = attributes.getNamedItem("font-size");
      Node attribFType = attributes.getNamedItem("font-type");
      Node attribIL = attributes.getNamedItem("ident-left");
      Node attribIR = attributes.getNamedItem("ident-right");
      Node attribIT = attributes.getNamedItem("ident-top");
      Node attribIB = attributes.getNamedItem("ident-bottom");
      Font font = new Font(attribFName.getNodeValue(), Integer.parseInt(attribFType.getNodeValue()), Integer.parseInt(attribFSize.getNodeValue()));
      Color color = new Color(Integer.parseInt(attribFColor.getNodeValue()));
      if(node.getNodeName() == "lb-time") {
         this.mciTime = new ManagerControlLabelItem(this.screenWidth, this.screenHeight, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), font, color, Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "lb-date") {
         this.mciDate = new ManagerControlLabelItem(this.screenWidth, this.screenHeight, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), font, color, Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

   }
}
