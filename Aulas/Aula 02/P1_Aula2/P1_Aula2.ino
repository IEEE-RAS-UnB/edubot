 
 #include<sparki.h>  

 void setup () 
 { 
   sparki.clearLCD();
   sparki.println("eu apareço apenas uma vez na tela"); 
   sparki.updateLCD();
   delay(1000);
 }

 void loop () 
 {
   sparki.println("oi, eu fico repetindo");
   sparki.updateLCD();
   delay(2000);
 }




