#include<Sparki.h>

int limite = 300;
int distMin = 10; // cm

void tratarIR();
void tratarSonar();

void setup()
{
  sparki.servo(0);

  //pinMode(A0, INPUT);
  randomSeed(analogRead(A0));
}

void loop()
{
  tratarIR();
  
  tratarSonar();
}

void tratarIR()
{
  sparki.clearLCD();
  
  int cantoDireito = sparki.edgeRight();
  int cantoEsquerdo = sparki.edgeLeft();
  int linhaCentro = sparki.lineCenter();
  int linhaDireita = sparki.lineRight();
  int linhaEsquerda = sparki.lineLeft();
  
  sparki.print ("Canto esquerdo: ");
  sparki.println(cantoEsquerdo);
  
  sparki.print ("Linha esquerda: ");
  sparki.println(linhaEsquerda);
  
  sparki.print ("Linha central: ");
  sparki.println(linhaCentro);
  
  sparki.print ("Linha direita: ");
  sparki.println(linhaDireita);
  
  sparki.print ("Canto direito: ");
  sparki.println(cantoDireito);
  
  sparki.updateLCD();
  
  if (linhaCentro <= limite || linhaEsquerda <= limite || linhaDireita <= limite)
  {
    sparki.moveStop();
    delay(500);
    sparki.moveBackward();
    delay(1000);
    
    // Vamos decidir, aleatoriamente, se devemos continuar a andar para a esquerda (0) ou para a direita (1)
    int aleatorio = (int) (random(50)%2);
    
    if (aleatorio == 0) // esquerda
    {
      sparki.moveLeft(30);
    }
    else // direita
    {
      sparki.moveRight(30);
    }
  }
  else if (cantoEsquerdo <= limite)
  {
    //sparki.moveRight();
    sparki.motorRotate(MOTOR_RIGHT, DIR_CCW, 80);
    sparki.motorRotate(MOTOR_LEFT, DIR_CCW, 80);
    delay(200);
  }
  else if (cantoDireito <= limite)
  {
    //sparki.moveLeft();
    sparki.motorRotate(MOTOR_RIGHT, DIR_CW, 80);
    sparki.motorRotate(MOTOR_LEFT, DIR_CW, 80);
    delay(200);
  }
  else
  {
    sparki.moveForward();
  }
}

void tratarSonar()
{
  int frente = sparki.ping();
  int esquerda;
  int direita;
  
  if (frente <= distMin && frente != -1)
  {
    sparki.moveStop();
    
    sparki.servo(-75); // esquerda
    delay(1000);
    
    do
    {
      esquerda = sparki.ping();
    }while(esquerda == -1);
    
    sparki.servo(75); // direita
    delay(1000);
    
    do
    {
      direita = sparki.ping();
    }while(direita == -1);
    
    sparki.clearLCD();
    sparki.print("Esquerda: ");
    sparki.print(esquerda);
    sparki.println(" cm");
    sparki.print("Direita: ");
    sparki.print(direita);
    sparki.println(" cm");
    sparki.updateLCD();
    
    sparki.servo(0);
    
    delay(2000);
    
    if (esquerda <= direita)
    {
      sparki.moveRight(75);
    }
    else
    {
      sparki.moveLeft(75);
    }
  }
}
