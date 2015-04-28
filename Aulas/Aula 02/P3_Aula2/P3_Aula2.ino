 
 #include<sparki.h>

 int contador=0;  

 void setup () 
 { 
   sparki.clearLCD();
   sparki.println(contador); 
   sparki.updateLCD();
   delay(5000);
 }

 void loop () 
 {
   sparki.clearLCD();
   contador = contador + 1 ;
   sparki.print(contador);
   sparki.updateLCD();
   delay(2000);
 }




