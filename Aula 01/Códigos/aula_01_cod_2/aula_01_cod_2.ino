/*****************************************************
* Encontrando raizes reais de uma equação de segundo *
* grau, na forma: y = a*x² + b*x + c                 *
*****************************************************/
#include<Sparki.h>

// Executa apenas uma vez, ao iniciar o Sparki
void setup()
{
  // Declarando as variaveis
  int a;
  int b;
  int c;
  float delta;
  float raiz1;
  float raiz2;
  
  // Definindo os coeficientes
  a = 1;
  b = 2;
  c = 3;
  
  // Calculando o delta
  delta = sqrt(b*b - 4*a*c);
  
  // Calculando as duas raizes
  raiz1 = (-b + delta)/(2*a);
  raiz2 = (-b - delta)/(2*a);
  
  // Imprimindo as raizes encontradas
  sparki.print("Raiz 1: "); // Note que nao ha quebra de linha
  sparki.println(raiz1); // Agora, ha quebra de linha
  
  sparki.print("Raiz 2: ");
  sparki.println(raiz2);
  
  // Atualizando o LCD
  sparki.updateLCD();
}

// Executa sempre em loop
void loop()
{
  // Nao faz nada aqui
}
