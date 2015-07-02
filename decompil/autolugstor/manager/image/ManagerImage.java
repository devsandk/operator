package autolugstor.manager.image;

import autolugstor.manager.image.ManagerImageAnimationItem;
import autolugstor.manager.image.ManagerImageItem;
import java.awt.Toolkit;
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

public class ManagerImage {

   private int screenWidth;
   private int screenHeight;
   private final String pathImg = "img/";
   private String fileConfig = "";
   public ManagerImageItem[] items = null;
   public ManagerImageAnimationItem[] animations = null;


   public ManagerImage(String file, int screenwidth, int screenheight) {
      this.fileConfig = file;
      this.screenWidth = screenwidth;
      this.screenHeight = screenheight;
   }

   public void Load() throws ParserConfigurationException, SAXException, IOException {
      System.out.println("ManagerImage load...");
      DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
      f.setValidating(false);
      DocumentBuilder builder = f.newDocumentBuilder();
      Document doc = builder.parse(new File(this.fileConfig));
      NodeList node_images = doc.getChildNodes();
      NodeList children = node_images.item(0).getChildNodes();
      int count_image = 0;
      int count_animation = 0;

      int index_image;
      for(index_image = 0; index_image < children.getLength(); ++index_image) {
         if(children.item(index_image).getNodeName() == "img") {
            ++count_image;
         }

         if(children.item(index_image).getNodeName() == "animation") {
            ++count_animation;
         }
      }

      System.out.println("mi count=" + count_image);
      this.items = new ManagerImageItem[count_image];
      this.animations = new ManagerImageAnimationItem[count_animation];
      index_image = 0;
      int index_animation = 0;

      for(int i = 0; i < children.getLength(); ++i) {
         Node node = children.item(i);
         if(node.getNodeName() == "img") {
            this.load_image(index_image, node);
            ++index_image;
         }

         if(node.getNodeName() == "animation") {
            this.load_animation(index_animation, node);
            ++index_animation;
         }
      }

      System.out.println("ManagerImage loaded");
   }

   private void load_animation(int index_animation, Node node) {
      NamedNodeMap attributes = node.getAttributes();
      Node attribSrc = attributes.getNamedItem("src");
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
      this.animations[index_animation] = new ManagerImageAnimationItem(this.screenWidth, this.screenHeight, Toolkit.getDefaultToolkit().getImage("img/" + attribSrc.getNodeValue()), attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
   }

   private void load_image(int index_image, Node node) throws IOException {
      NamedNodeMap attributes = node.getAttributes();
      Node attribSrc = attributes.getNamedItem("src");
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
      Node attribId = attributes.getNamedItem("id");
      File input = new File("img/" + attribSrc.getNodeValue());
      BufferedImage bfimg = ImageIO.read(input);
      this.items[index_image] = new ManagerImageItem(this.screenWidth, this.screenHeight, bfimg, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      if(attribId != null) {
         this.items[index_image].setId(attribId.getNodeValue());
      }

   }

   public void setVisible(String id, Boolean b) {
      for(int i = 0; i < this.items.length; ++i) {
         if(id.equals(this.items[i].getId())) {
            this.items[i].setVisible(b);
            break;
         }
      }

   }

   public ManagerImageItem getImageItem(String id) {
      for(int i = 0; i < this.items.length; ++i) {
         if(id.equals(this.items[i].getId())) {
            return this.items[i];
         }
      }

      return null;
   }
}
