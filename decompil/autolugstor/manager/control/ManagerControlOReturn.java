package autolugstor.manager.control;

import autolugstor.manager.control.ManagerControlItem;
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

public class ManagerControlOReturn {

   private int screenWidth;
   private int screenHeight;
   private final String pathImg = "img/";
   private String fileConfig = "";
   public ManagerControlItem mciCancel = null;
   public ManagerControlItem mciCancel2 = null;
   public ManagerControlItem mciOk = null;
   public ManagerControlItem mciReturn = null;


   public ManagerControlOReturn(String file, int screenwidth, int screenheight) {
      this.fileConfig = file;
      this.screenWidth = screenwidth;
      this.screenHeight = screenheight;
   }

   public void Load() throws ParserConfigurationException, SAXException, IOException {
      System.out.println("ManagerControl load...");
      DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
      f.setValidating(false);
      DocumentBuilder builder = f.newDocumentBuilder();
      Document doc = builder.parse(new File(this.fileConfig));
      NodeList node_images = doc.getChildNodes();
      NodeList children = node_images.item(0).getChildNodes();
      System.out.println("mc count=" + children.getLength());

      for(int i = 0; i < children.getLength(); ++i) {
         Node node = children.item(i);
         if(node.getNodeName() == "bt-cancel" || node.getNodeName() == "bt-ok" || node.getNodeName() == "bt-return" || node.getNodeName() == "bt-cancel2") {
            this.load_bt(node);
         }
      }

      System.out.println("ManagerControl loaded");
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
      if(node.getNodeName() == "bt-cancel") {
         this.mciCancel = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-ok") {
         this.mciOk = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-return") {
         this.mciReturn = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-cancel2") {
         this.mciCancel2 = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

   }
}
