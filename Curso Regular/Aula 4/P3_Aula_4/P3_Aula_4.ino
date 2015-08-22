
#include <Sparki.h>

int sensor = 0;


void setup()
{  

}
void loop () 
{ 
  //vamos primeiramente ler o valor do sensor
  sensor = sparki.readIR();
 
  
  if(sensor == 70)
  {
    sparki.moveFoward();
  }
  
  else if((sensor == 64) || (sensor == 21))
  //ATENCAO: nao ia dar certo se fosse escrito (sensor == 64 || 21)
  {
    sparki.moveStop();
  }
  /* 
      Repare uma coisa muito importante nesse programa:
      quando o programa entra no primeiro if, nossa intuicao eh pensar
      que o robo vai andar pra frente e, ao sair do if, ele ira parar.
      Porem, nao eh assim! Quando escrevemos "sparki.moveFoward()", 
      os motores vao ser ligados ate outro comando os utilize para outra funcao,
      como parar, ir para esquerda, direita ou voltar.
  */ 
  
}

