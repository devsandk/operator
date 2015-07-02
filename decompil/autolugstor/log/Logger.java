package autolugstor.log;

import java.io.FileWriter;
import java.io.IOException;
import java.text.Format;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Logger {

   private Format formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
   private FileWriter fw;
   private int count = 0;
   private final int countMax = 10000;
   private String file;


   public Logger(String file) {
      this.file = file;
      this.open();
   }

   private void open() {
      try {
         Date e = new Date();
         this.fw = new FileWriter("logs/" + this.file + "_" + e.getTime() + ".html", true);
      } catch (IOException var2) {
         var2.printStackTrace();
      }

   }

   public void log(String head, String msg, Throwable t, boolean msgRed) {
      try {
         String e = "[]";
         String calleeClassName = "[]";
         String callerMethodName = "[]";
         String callerClassName = "[]";
         StackTraceElement[] elements = t.getStackTrace();
         if(elements.length > 0) {
            e = elements[0].getMethodName();
            calleeClassName = elements[0].getClassName();
         }

         if(elements.length > 1) {
            callerMethodName = elements[1].getMethodName();
            callerClassName = elements[1].getClassName();
         }

         e = e.replace('<', '[');
         e = e.replace('>', ']');
         calleeClassName = calleeClassName.replace('<', '[');
         calleeClassName = calleeClassName.replace('>', ']');
         callerMethodName = callerMethodName.replace('<', '[');
         callerMethodName = callerMethodName.replace('>', ']');
         callerClassName = callerClassName.replace('<', '[');
         callerClassName = callerClassName.replace('>', ']');
         if(msgRed) {
            msg = "<font color=red><b>" + msg + "</b></font>";
         } else {
            msg = "<font color=\'0069b3\'><b>" + msg + "</b></font>";
         }

         String s = "<font color=\'#333333\'><i>" + this.formatter.format(new Date()) + "</i></font>: &nbsp&nbsp&nbsp" + calleeClassName + ".<b>" + e + "</b>(" + callerClassName + "." + callerMethodName + ") " + head + ": " + msg;
         System.out.println(s);
         this.fw.append(s + "<br>");
         this.fw.flush();
         ++this.count;
         if(this.count > 10000) {
            this.count = 0;
            this.close();
            this.open();
         }
      } catch (IOException var11) {
         var11.printStackTrace();
      }

   }

   public void log(Throwable t, String msg) {
      this.log("", msg, t, false);
   }

   public void log(Throwable t, String msg, boolean redMsg) {
      this.log("", msg, t, redMsg);
   }

   public void log(Throwable t, Exception e) {
      try {
         StackTraceElement[] e1 = e.getStackTrace();
         int len = 10;
         String end = "\t...";
         if(e1.length < len) {
            len = e1.length;
            end = "";
         }

         String s = "";
         s = s + "<font color=\'#8e0e0e\'>";
         s = s + e.getMessage() + "<br>";

         for(int i = 0; i < len; ++i) {
            s = s + "&nbsp&nbsp&nbsp--->&nbsp&nbsp&nbsp" + e1[i].toString() + "<br>";
         }

         s = s + end;
         s = s + "</font>";
         this.log("<font color=\'red\'><b>Exception</b></font>", s, t, false);
      } catch (Exception var8) {
         var8.printStackTrace();
      }

   }

   public void close() {
      try {
         this.fw.close();
      } catch (Exception var2) {
         var2.printStackTrace();
      }

   }
}
