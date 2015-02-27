#include <Sparki.h>

// Variáveis
int sensorEsquerda;
int sensorCentral;
int sensorDireita;

int limite = 700;

// Função para imprimir os valores na tela
void imprimir();

void setup() 
{
  sparki.servo(0);
}

void loop()
{
  sensorCentral = sparki.lineCenter();

  while(sensorCentral <= limite)
  {
    sparki.moveForward();
    sensorCentral = sparki.lineCenter();
    imprimir();
  }
  
  sensorEsquerda = sparki.lineLeft();
  sensorDireita = sparki.lineRight();
  
  if(sensorEsquerda < sensorDireita)
  {
    sparki.moveLeft();
  }
  else
  {
    sparki.moveRight();
  }
  
  imprimir();
  
  //delay(100); // wait 0.1 seconds
}

void imprimir ()
{
  sparki.clearLCD ();

  sparki.print("Esquerda: ");
  sparki.println(sensorEsquerda);
  
  sparki.print("Centro:   ");
  sparki.println(sensorCentral);
  
  sparki.print("Direita:  ");
  sparki.println(sensorDireita);
  
  sparki.updateLCD();
}
