 #include<sparki.h>

 //criando uma variavel de nome "contador" e colocando dentro dela o valor 0
 int contador=0;  

 void setup () 
 { 
   //limpando a tela
   sparki.clearLCD();
   
   //mandando o sparki pensar em escrever o que esta dentro do espaço de memoria
   //chamado contador (0)
   sparki.println(contador);
   
   //escrevendo os pensamentos do sparki na tela
   sparki.updateLCD();
   
   //agora, vamos apagar o numero 0 do contador e colocar o numero 2
   contador = 2;
   
   //mandando o sparki pensar em escrever o que esta dentro do espaço de memoria
   //chamado contador (2)
   sparki.println(contador);
   
   //escrevendo os pensamentos do sparki na tela
   sparki.updateLCD();
   
   //esperando 5 segundos
   delay(5000);
 }

 void loop () 
 {
   sparki.clearLCD();
 }




