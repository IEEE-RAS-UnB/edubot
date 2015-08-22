#include<Sparki.h>

void setup()
{
  // Faz o Sparki olhar para frente
  sparki.servo(0);
}

void loop()
{
  // Sparki anda para frente 10 centímetros
  sparki.moveForward(10);
  
  // Sparki rotaciona 45 graus para a direita
  sparki.moveRight(45);
  
  // Sparki anda para frente mais 10 centímetros
  sparki.moveForward(10);
  
  // Sparki rotaciona 45 graus para a esquerda
  sparki.moveLeft(45);
}
