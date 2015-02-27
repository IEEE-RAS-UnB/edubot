#include<Sparki.h>

int limite = 300;

void setup()
{
  sparki.servo(0);
}

void loop()
{
  sparki.clearLCD();
  
  int cantoDireito  = sparki.edgeRight();
  int cantoEsquerdo = sparki.edgeLeft();
  int centro        = sparki.lineCenter();
  
  sparki.print ("Canto esquerdo: ");
  sparki.println(cantoEsquerdo);
  
  sparki.print ("Linha central: ");
  sparki.println(centro);
  
  sparki.print ("Canto direito: ");
  sparki.println(cantoDireito);
  
  sparki.updateLCD();
  
  if (centro <= limite)
  {
    sparki.moveStop();
    delay(500);

    sparki.moveBackward();
    delay(1000);
    
    // Dá meia-volta
    sparki.moveRight(180);
  }
  else if (cantoEsquerdo <= limite)
  {
    sparki.moveRight();
    delay(200);
  }
  else if (cantoDireito <= limite)
  {
    sparki.moveLeft();
    delay(200);
  }
  else
  {
    sparki.moveForward();
  }
}
