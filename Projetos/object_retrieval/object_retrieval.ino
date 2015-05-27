#include <Sparki.h>

// Variáveis
int sensorEsquerda;
int sensorCentral;
int sensorDireita;
int distancia = 3;
int tempoGarra = 3000; // ms
boolean tenhoObjeto = false;

int limite = 700;

// Função para imprimir os valores na tela
void imprimir();
// Função para que o usuário possa posicionar as garras na posição inicial desejada
void prepararGarras();
// Função para seguir linha
void segueLinha();
void pegaObjeto ();
void largaObjeto ();

void setup() 
{
  sparki.servo(0);
  prepararGarras();
}

void loop()
{
  segueLinha ();
  devolveObjeto ();
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

void prepararGarras ()
{
  int botao;
  
  sparki.clearLCD();
  sparki.print ("Por favor, use o meu controle remoto para posicionar minhas garras de forma que elas estejam totalmente abertas e, depois, aperte STOP!");
  sparki.updateLCD();
  
  // Espera até que o usuário aperte o botão 7 (para começar a abrir as garras)
  do{
    botao = sparki.readIR();
  }while(botao != 7);
  // Começa a abrir a garra
  sparki.gripperOpen();
  
  // Espera até que o usuário aperte o botão 64 (para parar as garras)
  do{
    botao = sparki.readIR();
  }while(botao != 64);
  // Para a garra
  sparki.gripperStop();
}

void segueLinha ()
{
  int dist = sparki.ping();
  sensorCentral = sparki.lineCenter();

  while(sensorCentral <= limite && (dist == -1 || dist > distancia))
  {
    dist = sparki.ping();
    sparki.moveForward();
    sensorCentral = sparki.lineCenter();
    imprimir();
  }
  
  if(sensorCentral > limite)
  {
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
  else
  {
    pegaObjeto();
    return;
  }
}

void devolveObjeto ()
{
  boolean largar = false;
  sensorCentral = sparki.lineCenter();

  while(sensorCentral <= limite && !largar)
  {
    largar = (sparki.edgeLeft() <= limite) && (sparki.edgeRight() <= limite);
    
    sparki.moveForward();
    sensorCentral = sparki.lineCenter();
    imprimir();
  }
  
  if(sensorCentral > limite)
  {
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
  else if (largar)
  {
    largar = false;
    largaObjeto();
    return;
  }
}

void pegaObjeto ()
{
  tenhoObjeto = true;
  sparki.moveStop();
    
  sparki.gripperClose();
  delay(tempoGarra);
  sparki.gripperStop();
    
  sparki.moveRight(180);
}

void largaObjeto ()
{
  tenhoObjeto = false;
  sparki.moveStop();
    
  sparki.gripperOpen();
  delay(tempoGarra);
  sparki.gripperStop();
    
  sparki.moveRight(180);
}
