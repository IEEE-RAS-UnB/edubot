#include<Sparki.h>

int codigo;

void setup()
{
  sparki.servo(0);
  sparki.clearLCD();
}

void loop()
{
  codigo = sparki.readIR();
  
  if (codigo == 21)
  {
    sparki.moveBackward();
    delay(5000);
    sparki.moveStop();
  }
  else if (codigo == -1)
  {
    sparki.moveStop();
  }
}
