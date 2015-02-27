#include <Sparki.h>

void setup ()
{
  // Faz o Sparki olhar para frente
  sparki.servo(0);
}

void loop ()
{
  // Sparki anda para frente 10 centímetros
  sparki.moveForward(10);
  
  // Sparki rotaciona 90 graus para a direita
  sparki.moveRight(90);
  
  // Espera 1000 ms
  delay(1000);
}
