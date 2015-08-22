
 #include <Sparki.h>

 void setup()
 {  

 }
 void loop () 
 { 
   sparki.clearLCD();
   if (300 >= 400 || 200 <=500)
   {
     sparki.print("Sou inteligente");
   }
   /* o bloco if acima eh executado porque 200 eh menor que 500
     e se trata de um OU, dessa forma, se uma das condicoes for verdadeira,
     o bloco eh executado  */
   
   if (300 >= 400 && 200 <= 500)
   {
     sparki.print("Nao sou inteligente");
   }
   /* o bloco if acima nao eh executado porque 300 nao eh maior que 400
     e se trata de um E, dessa forma, se uma das condicoes for falsa,
     o bloco ja nao eh executado  */
   sparki.updateLCD();
   
 }

