#include <sparki.h>

void setup () 
{
  sparki.moveFoward();
  delay(5000);
  sparki.moveStop();
  
}

void loop ()
{
  sparki.moveFoward();
  delay(2000);
  sparki.moveStop();
  delay(2000); //eh necessario esse delay para que seja percebido a parada do Sparki.
  
}
