#include <sparki.h>

void setup () 
{
  sparki.moveFoward(5);
}

void loop ()
{
  sparki.moveFoward(5);
  delay(2000); //eh necessario esse delay para que seja percebido que o Sparki para e entra novamente no loop
  
}
