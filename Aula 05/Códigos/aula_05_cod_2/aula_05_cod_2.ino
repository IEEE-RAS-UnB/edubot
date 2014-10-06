#include <Sparki.h>

// Variáveis
int sensorEsquerda;
int sensorCentral;
int sensorDireita;

int limite = 500;

// Função para imprimir os valores na tela
void imprimir();

void setup() 
{
  sparki.servo(0);
}

void loop()
{
  sensorEsquerda = sparki.lineLeft();
  sensorCentral = sparki.lineCenter();
  sensorDireita = sparki.lineRight();
  
  if ( sensorEsquerda < limite )
  {  
    sparki.moveLeft();
  }

  if ( sensorDireita < limite )
  {  
    sparki.moveRight();
  }

  if ( (sensorCentral < limite) && (sensorEsquerda > limite) && (sensorDireita > limite) )
  {
    sparki.moveForward();
  }
  
  imprimir();
  
  delay(100); // wait 0.1 seconds
}

void imprimir ()
{
  sparki.clearLCD ();

  sparki.print("Sensor na esquerda: ");
  sparki.println(sensorEsquerda);
  
  sparki.print("Sensor central: ");
  sparki.println(sensorCentral);
  
  sparki.print("Sensor na direita: ");
  sparki.println(sensorDireita);
  
  sparki.updateLCD();
}
