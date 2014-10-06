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
  
  if (codigo != -1)
  {
    sparki.print("Codigo recebido: ");
    sparki.println(codigo);
    sparki.updateLCD();
  }
}
