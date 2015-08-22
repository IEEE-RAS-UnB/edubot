
#include <Sparki.h>

int sensor = 0;


void setup()
{  

}
void loop () 
{ 
  //vamos primeiramente ler o valor do sensor
  sensor = sparki.readIR();
 
  if(sensor == 70)
  {
    sparki.moveFoward(5);
  }
  
  /* no proximo loop, caso voce nao esteja apertando nenhum botao
  o valor que o sparki.readIR retorna eh igual a -1 */

}

