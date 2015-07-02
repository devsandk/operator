package autolugstor.manager.control;

import autolugstor.manager.control.ManagerControlHallItem;
import autolugstor.manager.control.ManagerControlItem;
import autolugstor.manager.control.ManagerControlLabelImageAdminItem;
import autolugstor.manager.control.ManagerControlLabelImageItem;
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

public class ManagerControlFreeCell {

   private int screenWidth;
   private int screenHeight;
   private final String pathImg = "img/";
   private String fileConfig = "";
   public ManagerControlItem mciBack = null;
   public ManagerControlItem mciAdminPermit = null;
   public ManagerControlItem mciAdminDenied = null;
   public ManagerControlItem mciCellEnabled = null;
   public ManagerControlItem mciCellDisabled = null;
   public ManagerControlItem mciFree = null;
   public ManagerControlLabelItem mciTime = null;
   public ManagerControlLabelItem mciDate = null;
   public ManagerControlHallItem mciHall = null;
   public ManagerControlLabelImageItem mciCell = null;
   public ManagerControlLabelImageAdminItem mciCellAdmin = null;
   public ManagerControlLabelItem mciHallNumber = null;
   public ManagerControlLabelItem mciFreeCount = null;
   public ManagerControlItem mciSecLeft = null;
   public ManagerControlItem mciSecRight = null;
   public ManagerControlLabelItem mciCurSec = null;


   public ManagerControlFreeCell(String file, int screenwidth, int screenheight) {
      this.fileConfig = file;
      this.screenWidth = screenwidth;
      this.screenHeight = screenheight;
   }

   public void Load() throws ParserConfigurationException, SAXException, IOException {
      System.out.println("ManagerControlFreeCell load...");
      DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
      f.setValidating(false);
      DocumentBuilder builder = f.newDocumentBuilder();
      Document doc = builder.parse(new File(this.fileConfig));
      NodeList node_images = doc.getChildNodes();
      NodeList children = node_images.item(0).getChildNodes();

      for(int i = 0; i < children.getLength(); ++i) {
         Node node = children.item(i);
         if(node.getNodeName() == "bt-back" || node.getNodeName() == "bt-admin-permit" || node.getNodeName() == "bt-admin-denied" || node.getNodeName() == "bt-free" || node.getNodeName() == "bt-sec-left" || node.getNodeName() == "bt-sec-right" || node.getNodeName() == "bt-cell-enabled" || node.getNodeName() == "bt-cell-disabled") {
            this.load_bt(node);
         }

         if(node.getNodeName() == "btgroup-hall") {
            this.load_btgroup(node);
         }

         if(node.getNodeName() == "lb-time" || node.getNodeName() == "lb-date" || node.getNodeName() == "lb-hall" || node.getNodeName() == "lb-free" || node.getNodeName() == "lb-sec") {
            this.load_lb(node);
         }

         if(node.getNodeName() == "cells") {
            this.load_cells(node);
         }

         if(node.getNodeName() == "cells-admin") {
            this.load_cells_admin(node);
         }
      }

      System.out.println("ManagerControlFreeCell loaded");
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

      if(node.getNodeName() == "bt-cell-enabled") {
         this.mciCellEnabled = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-cell-disabled") {
         this.mciCellDisabled = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-admin-permit") {
         this.mciAdminPermit = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-admin-denied") {
         this.mciAdminDenied = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-free") {
         this.mciFree = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-sec-left") {
         this.mciSecLeft = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

      if(node.getNodeName() == "bt-sec-right") {
         this.mciSecRight = new ManagerControlItem(this.screenWidth, this.screenHeight, bfimg1, bfimg2, bfimg3, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      }

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
      ManagerControlLabelItem mcli = new ManagerControlLabelItem(this.screenWidth, this.screenHeight, attribXA.getNodeValue(), attribYA.getNodeValue(), Integer.parseInt(attribX.getNodeValue()), Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribW.getNodeValue()), Integer.parseInt(attribH.getNodeValue()), font, color, Integer.parseInt(attribIL.getNodeValue()), Integer.parseInt(attribIR.getNodeValue()), Integer.parseInt(attribIT.getNodeValue()), Integer.parseInt(attribIB.getNodeValue()));
      String var20;
      switch((var20 = node.getNodeName()).hashCode()) {
      case -1111059590:
         if(var20.equals("lb-sec")) {
            this.mciCurSec = mcli;
         }
         break;
      case -83559003:
         if(var20.equals("lb-date")) {
            this.mciDate = mcli;
         }
         break;
      case -83483549:
         if(var20.equals("lb-free")) {
            this.mciFreeCount = mcli;
         }
         break;
      case -83440080:
         if(var20.equals("lb-hall")) {
            this.mciHallNumber = mcli;
         }
         break;
      case -83074876:
         if(var20.equals("lb-time")) {
            this.mciTime = mcli;
         }
      }

   }

   private void load_btgroup(Node node) throws IOException {
      NamedNodeMap attributes = node.getAttributes();
      Node attribImg1 = attributes.getNamedItem("img1");
      Node attribImg2 = attributes.getNamedItem("img2");
      Node attribImg3 = attributes.getNamedItem("img3");
      Node attribY = attributes.getNamedItem("y");
      Node attribB = attributes.getNamedItem("between");
      File input1 = new File("img/" + attribImg1.getNodeValue());
      BufferedImage bfimg1 = ImageIO.read(input1);
      File input2 = new File("img/" + attribImg2.getNodeValue());
      BufferedImage bfimg2 = ImageIO.read(input2);
      File input3 = new File("img/" + attribImg3.getNodeValue());
      BufferedImage bfimg3 = ImageIO.read(input3);
      if(node.getNodeName() == "btgroup-hall") {
         this.mciHall = new ManagerControlHallItem(bfimg1, bfimg2, bfimg3, Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribB.getNodeValue()));
      }

   }

   private void load_cells_admin(Node node) throws IOException {
      NamedNodeMap attributes = node.getAttributes();
      Node attribY = attributes.getNamedItem("y");
      Node attribB = attributes.getNamedItem("between");
      Node attribFName = attributes.getNamedItem("font-name");
      Node attribFColor = attributes.getNamedItem("font-color");
      Node attribFSize = attributes.getNamedItem("font-size");
      Node attribFType = attributes.getNamedItem("font-type");
      Node aNull = attributes.getNamedItem("cell-null");
      Node ablue1 = attributes.getNamedItem("blue1");
      Node ablue1_ = attributes.getNamedItem("blue1_");
      Node ablue2 = attributes.getNamedItem("blue2");
      Node ablue2_ = attributes.getNamedItem("blue2_");
      Node ablue3 = attributes.getNamedItem("blue3");
      Node ablue3_ = attributes.getNamedItem("blue3_");
      Node ablue4 = attributes.getNamedItem("blue4");
      Node ablue4_ = attributes.getNamedItem("blue4_");
      Node agreen1 = attributes.getNamedItem("green1");
      Node agreen1_ = attributes.getNamedItem("green1_");
      Node agreen2 = attributes.getNamedItem("green2");
      Node agreen2_ = attributes.getNamedItem("green2_");
      Node agreen3 = attributes.getNamedItem("green3");
      Node agreen3_ = attributes.getNamedItem("green3_");
      Node agreen4 = attributes.getNamedItem("green4");
      Node agreen4_ = attributes.getNamedItem("green4_");
      Node alime1 = attributes.getNamedItem("lime1");
      Node alime1_ = attributes.getNamedItem("lime1_");
      Node alime2 = attributes.getNamedItem("lime2");
      Node alime2_ = attributes.getNamedItem("lime2_");
      Node alime3 = attributes.getNamedItem("lime3");
      Node alime3_ = attributes.getNamedItem("lime3_");
      Node alime4 = attributes.getNamedItem("lime4");
      Node alime4_ = attributes.getNamedItem("lime4_");
      Node ared1 = attributes.getNamedItem("red1");
      Node ared1_ = attributes.getNamedItem("red1_");
      Node ared2 = attributes.getNamedItem("red2");
      Node ared2_ = attributes.getNamedItem("red2_");
      Node ared3 = attributes.getNamedItem("red3");
      Node ared3_ = attributes.getNamedItem("red3_");
      Node ared4 = attributes.getNamedItem("red4");
      Node ared4_ = attributes.getNamedItem("red4_");
      Node ayel1 = attributes.getNamedItem("yel1");
      Node ayel1_ = attributes.getNamedItem("yel1_");
      Node ayel2 = attributes.getNamedItem("yel2");
      Node ayel2_ = attributes.getNamedItem("yel2_");
      Node ayel3 = attributes.getNamedItem("yel3");
      Node ayel3_ = attributes.getNamedItem("yel3_");
      Node ayel4 = attributes.getNamedItem("yel4");
      Node ayel4_ = attributes.getNamedItem("yel4_");
      Node agray1 = attributes.getNamedItem("gray1");
      Node agray1_ = attributes.getNamedItem("gray1_");
      Node agray2 = attributes.getNamedItem("gray2");
      Node agray2_ = attributes.getNamedItem("gray2_");
      Node agray3 = attributes.getNamedItem("gray3");
      Node agray3_ = attributes.getNamedItem("gray3_");
      Node agray4 = attributes.getNamedItem("gray4");
      Node agray4_ = attributes.getNamedItem("gray4_");
      Node ablack1 = attributes.getNamedItem("black1");
      Node ablack1_ = attributes.getNamedItem("black1_");
      Node ablack2 = attributes.getNamedItem("black2");
      Node ablack2_ = attributes.getNamedItem("black2_");
      Node ablack3 = attributes.getNamedItem("black3");
      Node ablack3_ = attributes.getNamedItem("black3_");
      Node ablack4 = attributes.getNamedItem("black4");
      Node ablack4_ = attributes.getNamedItem("black4_");
      Font font = new Font(attribFName.getNodeValue(), Integer.parseInt(attribFType.getNodeValue()), Integer.parseInt(attribFSize.getNodeValue()));
      Color color = new Color(Integer.parseInt(attribFColor.getNodeValue()));
      File i = new File("img/" + ablue1.getNodeValue());
      BufferedImage blue1 = ImageIO.read(i);
      i = new File("img/" + ablue1_.getNodeValue());
      BufferedImage blue1_ = ImageIO.read(i);
      i = new File("img/" + ablue2.getNodeValue());
      BufferedImage blue2 = ImageIO.read(i);
      i = new File("img/" + ablue2_.getNodeValue());
      BufferedImage blue2_ = ImageIO.read(i);
      i = new File("img/" + ablue3.getNodeValue());
      BufferedImage blue3 = ImageIO.read(i);
      i = new File("img/" + ablue3_.getNodeValue());
      BufferedImage blue3_ = ImageIO.read(i);
      i = new File("img/" + ablue4.getNodeValue());
      BufferedImage blue4 = ImageIO.read(i);
      i = new File("img/" + ablue4_.getNodeValue());
      BufferedImage blue4_ = ImageIO.read(i);
      i = new File("img/" + agreen1.getNodeValue());
      BufferedImage green1 = ImageIO.read(i);
      i = new File("img/" + agreen1_.getNodeValue());
      BufferedImage green1_ = ImageIO.read(i);
      i = new File("img/" + agreen2.getNodeValue());
      BufferedImage green2 = ImageIO.read(i);
      i = new File("img/" + agreen2_.getNodeValue());
      BufferedImage green2_ = ImageIO.read(i);
      i = new File("img/" + agreen3.getNodeValue());
      BufferedImage green3 = ImageIO.read(i);
      i = new File("img/" + agreen3_.getNodeValue());
      BufferedImage green3_ = ImageIO.read(i);
      i = new File("img/" + agreen4.getNodeValue());
      BufferedImage green4 = ImageIO.read(i);
      i = new File("img/" + agreen4_.getNodeValue());
      BufferedImage green4_ = ImageIO.read(i);
      i = new File("img/" + alime1.getNodeValue());
      BufferedImage lime1 = ImageIO.read(i);
      i = new File("img/" + alime1_.getNodeValue());
      BufferedImage lime1_ = ImageIO.read(i);
      i = new File("img/" + alime2.getNodeValue());
      BufferedImage lime2 = ImageIO.read(i);
      i = new File("img/" + alime2_.getNodeValue());
      BufferedImage lime2_ = ImageIO.read(i);
      i = new File("img/" + alime3.getNodeValue());
      BufferedImage lime3 = ImageIO.read(i);
      i = new File("img/" + alime3_.getNodeValue());
      BufferedImage lime3_ = ImageIO.read(i);
      i = new File("img/" + alime4.getNodeValue());
      BufferedImage lime4 = ImageIO.read(i);
      i = new File("img/" + alime4_.getNodeValue());
      BufferedImage lime4_ = ImageIO.read(i);
      i = new File("img/" + ared1.getNodeValue());
      BufferedImage red1 = ImageIO.read(i);
      i = new File("img/" + ared1_.getNodeValue());
      BufferedImage red1_ = ImageIO.read(i);
      i = new File("img/" + ared2.getNodeValue());
      BufferedImage red2 = ImageIO.read(i);
      i = new File("img/" + ared2_.getNodeValue());
      BufferedImage red2_ = ImageIO.read(i);
      i = new File("img/" + ared3.getNodeValue());
      BufferedImage red3 = ImageIO.read(i);
      i = new File("img/" + ared3_.getNodeValue());
      BufferedImage red3_ = ImageIO.read(i);
      i = new File("img/" + ared4.getNodeValue());
      BufferedImage red4 = ImageIO.read(i);
      i = new File("img/" + ared4_.getNodeValue());
      BufferedImage red4_ = ImageIO.read(i);
      i = new File("img/" + ayel1.getNodeValue());
      BufferedImage yel1 = ImageIO.read(i);
      i = new File("img/" + ayel1_.getNodeValue());
      BufferedImage yel1_ = ImageIO.read(i);
      i = new File("img/" + ayel2.getNodeValue());
      BufferedImage yel2 = ImageIO.read(i);
      i = new File("img/" + ayel2_.getNodeValue());
      BufferedImage yel2_ = ImageIO.read(i);
      i = new File("img/" + ayel3.getNodeValue());
      BufferedImage yel3 = ImageIO.read(i);
      i = new File("img/" + ayel3_.getNodeValue());
      BufferedImage yel3_ = ImageIO.read(i);
      i = new File("img/" + ayel4.getNodeValue());
      BufferedImage yel4 = ImageIO.read(i);
      i = new File("img/" + ayel4_.getNodeValue());
      BufferedImage yel4_ = ImageIO.read(i);
      i = new File("img/" + agray1.getNodeValue());
      BufferedImage gray1 = ImageIO.read(i);
      i = new File("img/" + agray1_.getNodeValue());
      BufferedImage gray1_ = ImageIO.read(i);
      i = new File("img/" + agray2.getNodeValue());
      BufferedImage gray2 = ImageIO.read(i);
      i = new File("img/" + agray2_.getNodeValue());
      BufferedImage gray2_ = ImageIO.read(i);
      i = new File("img/" + agray3.getNodeValue());
      BufferedImage gray3 = ImageIO.read(i);
      i = new File("img/" + agray3_.getNodeValue());
      BufferedImage gray3_ = ImageIO.read(i);
      i = new File("img/" + agray4.getNodeValue());
      BufferedImage gray4 = ImageIO.read(i);
      i = new File("img/" + agray4_.getNodeValue());
      BufferedImage gray4_ = ImageIO.read(i);
      i = new File("img/" + ablack1.getNodeValue());
      BufferedImage black1 = ImageIO.read(i);
      i = new File("img/" + ablack1_.getNodeValue());
      BufferedImage black1_ = ImageIO.read(i);
      i = new File("img/" + ablack2.getNodeValue());
      BufferedImage black2 = ImageIO.read(i);
      i = new File("img/" + ablack2_.getNodeValue());
      BufferedImage black2_ = ImageIO.read(i);
      i = new File("img/" + ablack3.getNodeValue());
      BufferedImage black3 = ImageIO.read(i);
      i = new File("img/" + ablack3_.getNodeValue());
      BufferedImage black3_ = ImageIO.read(i);
      i = new File("img/" + ablack4.getNodeValue());
      BufferedImage black4 = ImageIO.read(i);
      i = new File("img/" + ablack4_.getNodeValue());
      BufferedImage black4_ = ImageIO.read(i);
      i = new File("img/" + aNull.getNodeValue());
      BufferedImage cellNull = ImageIO.read(i);
      if(node.getNodeName() == "cells-admin") {
         this.mciCellAdmin = new ManagerControlLabelImageAdminItem(Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribB.getNodeValue()), font, color, cellNull, blue1, blue1_, blue2, blue2_, blue3, blue3_, blue4, blue4_, green1, green1_, green2, green2_, green3, green3_, green4, green4_, lime1, lime1_, lime2, lime2_, lime3, lime3_, lime4, lime4_, red1, red1_, red2, red2_, red3, red3_, red4, red4_, yel1, yel1_, yel2, yel2_, yel3, yel3_, yel4, yel4_, gray1, gray1_, gray2, gray2_, gray3, gray3_, gray4, gray4_, black1, black1_, black2, black2_, black3, black3_, black4, black4_);
      }

   }

   private void load_cells(Node node) throws IOException {
      NamedNodeMap attributes = node.getAttributes();
      Node imgOn1 = attributes.getNamedItem("imgon1");
      Node imgOff1 = attributes.getNamedItem("imgoff1");
      Node imgOn2 = attributes.getNamedItem("imgon2");
      Node imgOff2 = attributes.getNamedItem("imgoff2");
      Node imgOn3 = attributes.getNamedItem("imgon3");
      Node imgOff3 = attributes.getNamedItem("imgoff3");
      Node imgOn4 = attributes.getNamedItem("imgon4");
      Node imgOff4 = attributes.getNamedItem("imgoff4");
      Node attribY = attributes.getNamedItem("y");
      Node attribB = attributes.getNamedItem("between");
      Node attribFName = attributes.getNamedItem("font-name");
      Node attribFColor = attributes.getNamedItem("font-color");
      Node attribFSize = attributes.getNamedItem("font-size");
      Node attribFType = attributes.getNamedItem("font-type");
      Font font = new Font(attribFName.getNodeValue(), Integer.parseInt(attribFType.getNodeValue()), Integer.parseInt(attribFSize.getNodeValue()));
      Color color = new Color(Integer.parseInt(attribFColor.getNodeValue()));
      File i = new File("img/" + imgOn1.getNodeValue());
      BufferedImage bfimgon1 = ImageIO.read(i);
      i = new File("img/" + imgOff1.getNodeValue());
      BufferedImage bfimgoff1 = ImageIO.read(i);
      i = new File("img/" + imgOn2.getNodeValue());
      BufferedImage bfimgon2 = ImageIO.read(i);
      i = new File("img/" + imgOff2.getNodeValue());
      BufferedImage bfimgoff2 = ImageIO.read(i);
      i = new File("img/" + imgOn3.getNodeValue());
      BufferedImage bfimgon3 = ImageIO.read(i);
      i = new File("img/" + imgOff3.getNodeValue());
      BufferedImage bfimgoff3 = ImageIO.read(i);
      i = new File("img/" + imgOn4.getNodeValue());
      BufferedImage bfimgon4 = ImageIO.read(i);
      i = new File("img/" + imgOff4.getNodeValue());
      BufferedImage bfimgoff4 = ImageIO.read(i);
      if(node.getNodeName() == "cells") {
         this.mciCell = new ManagerControlLabelImageItem(bfimgon1, bfimgoff1, bfimgon2, bfimgoff2, bfimgon3, bfimgoff3, bfimgon4, bfimgoff4, Integer.parseInt(attribY.getNodeValue()), Integer.parseInt(attribB.getNodeValue()), font, color);
      }

   }
}
