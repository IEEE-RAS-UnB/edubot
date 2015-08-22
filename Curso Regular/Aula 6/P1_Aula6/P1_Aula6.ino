#include<sparki.h>
void setup () 
{
}

void loop () 
{
  sparki.moveFoward();
  sparki.println(sparki.ping());
  delay(1500);
  if (sparki.ping() <= 15)
  {
    sparki.moveStop();
  }
    
}


//  OBS: Nesse caso, o primeiro sparki.ping() sera diferente do segundo!
//  o primeiro indicara a distancia em t= x, enquanto o segundo indicara
//  a distancia em t= x + 1,5 segundos. Para resolver isso, usamos variaveis!
// P12_Aula6

