#include <Sparki.h>

// Variáveis
int sensorEsquerda;
int sensorCentral;
int sensorDireita;

// Função para imprimir os valores na tela
void imprimir();

void setup ()
{
  sparki.servo(0);
}

void loop()
{
  sensorEsquerda = sparki.lineLeft();
  sensorCentral = sparki.lineCenter();
  sensorDireita = sparki.lineRight();
  
  imprimir();
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
