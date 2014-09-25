#include <Sparki.h>

int numero = 0;

void setup()
{
  sparki.clearLCD();
  sparki.println("Eu apareco apenas uma vez na tela!");
  sparki.updateLCD();
}

void loop()
{
  // Vamos imprimir um numero na tela
  sparki.println(numero);
  sparki.updateLCD();
  
  // Fazemos o Sparki esperar por 200 milisegundos (2 segundos) antes de fazer qualquer outra coisa
  delay (2000);
  
  // Somamos 1 ao numero que vai aparecer na tela
  numero = numero + 1;
}




