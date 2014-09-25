#include<Sparki.h>

void setup()
{
  // Faz o Sparki olhar para frente
  sparki.servo(0);
}

void loop()
{
  // A roda esquerda (MOTOR_LEFT) rotaciona no sentido anti-horário (DIR_CCW) com 50% de sua capacidade
  sparki.motorRotate(MOTOR_LEFT, DIR_CCW, 50);
  
  // A roda direita (MOTOR_RIGHT) rotaciona no sentido horário (DIR_CW) com 100% de sua capacidade
  sparki.motorRotate(MOTOR_RIGHT, DIR_CW, 100);
}
