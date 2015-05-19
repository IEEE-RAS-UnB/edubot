
 #include <Sparki.h>

 int a=0 ;
 
 void setup()
 {  

 }
 void loop () 
 { 
   sparki.clearLCD();
   if (a>3)
   {
     sparki.print("Busco sabedoria");
   }
   
   else if (a<3)
   {
     sparki.print("Faco programas");
   }
   else()
   {
     sparki.print("E sou legal");
   }
  /* Perceba que esse ultimo else, inclui o caso ultimo casoque resta
     que eh de a ser IGUAL a 3.  */
   sparki.updateLCD();
   
 }

