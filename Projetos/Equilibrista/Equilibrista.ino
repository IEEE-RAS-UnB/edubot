#include <Sparki.h>

//Declarações de funções
void pegar_dados (void);
void imprimir (void);

//Declarações de variáveis globais
float x;
float y;

void setup()
{
  sparki.servo (SERVO_CENTER);
}

void loop()
{
  //Pegamos os dados do acelerômetro
  pegar_dados ();
  
  //Imprimimos os dados na tela de LCD
  imprimir ();
  
  // Checamos se a inclinação está no eixo y (frente) ou no eixo x (nas laterais)
  if ( (x < 1) && (x > -1) ) //Neste caso, a inclinação não está nas laterias
  {
    if (y > 0) //Aqui, o Sparki está em uma descida
    {
      sparki.moveBackward (); //Anda para trás
      sparki.servo (0);
    }
    else if (y < 0) //Aqui, o Sparki está em uma subida
    {
      sparki.moveForward (); //Anda para frente
      sparki.servo (0);
    }
    else //y = 0
    {
      sparki.moveStop (); //Fica parado
      sparki.servo (0);
    }
  }
  else //Neste caso, a inclinação está nas laterais do Sparki
  {
    if ( x > 1 ) //Inclinado para a direita
    {
      sparki.moveLeft();
      sparki.servo (-70);
    }
    if ( x < -1 ) //Inclinado para a esquerda
    {
      sparki.moveRight();
      sparki.servo (70);
    }   
  }
  delay(100);
}

void pegar_dados ()
{
  x = sparki.accelX ();
  y = sparki.accelY ();
}

void imprimir ()
{
  sparki.clearLCD ();
  sparki.print ("x = ");
  sparki.println (x);
  sparki.print ("y = ");
  sparki.println (y);
  
  if ( (x < 1) && (x > -1) ) //Neste caso, a inclinação não está nas laterias
  {
    if (y > 0)
    {
      sparki.print ("Descida!");
    }
    else if (y < 0)
    {
      sparki.print ("Subida!");
    }
    else //y = 0
    {
      sparki.print ("Neutro!");
    }
  }
  else
  {
    if ( x > 1 )
    {
      sparki.print ("Ir para a esquerda!");
    }
    if ( x < -1 )
    {
      sparki.print ("Ir para a direita!");
    }   
  }
  
  sparki.updateLCD ();
}
