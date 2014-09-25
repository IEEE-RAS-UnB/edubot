/********************************************
* Possível resolução para o projeto final   *
* do curso.                                 *
* Note que há o conceito de funções polimór-*
* ficas, o que não é esperado que os alunos *
* saibam.                                   *
*********************************************/

#include <Sparki.h>

#define distancia_minima 20 //Se houver um obstáculo a uma distância menor do que essa, o robô irá tentar desviar

//Funções
void imprimir (int); //Imprime distância na frente
void imprimir (int, int); //Imprime distâncias nos lados
void imprimir (char *); //Imprime uma string

//Variáveis
int distancia_frente;
int distancia_direita;
int distancia_esquerda;
 
void setup()
{
  sparki.servo(0); //Faz o robô olhar para frente
}

void loop()
{
    sparki.moveForward (); //O robô começa a andar para frente
    
    distancia_frente = sparki.ping(); //Mede a distância, usando o Sonar
    
    while (distancia_frente > distancia_minima || distancia_frente == -1) //A medição "-1" occore quando há algum erro. Neste caso, devemos simplesmente ignorar e fazer uma nova leitura
    {
      distancia_frente = sparki.ping ();
      
      //Vamos imprimir no monitor LCD do Sparki os valores que estão sendo lidos:
      imprimir (distancia_frente);
    }
    
    sparki.moveStop (); //O robô para, pois há um obstáculo a frente e ele precisa desviar!
    imprimir ("Estou muito perto de um obstáculo! Preciso desviar!");
    
    //Agora, o robô deve decidir para onde ir. Lembre-se, ângulos positivos fazem o robô olhar para a direita; negativos, para a esquerda!
    sparki.servo (70); //Olha para a direita
    delay (1000); //Esperamos um pouco para que o Sonar esteja na posição desejada
    do
    {
      distancia_direita = sparki.ping (); //Faz a medição
    } while (distancia_direita == -1); //Checa se houve erro na medição
    
    sparki.servo (-70); //Olha para a esquerda
    delay (1000); //Esperamos um pouco para que o Sonar esteja na posição desejada
    do
    {
      distancia_esquerda = sparki.ping (); //Faz a medição
    } while (distancia_esquerda == -1); //Checa se houve erro na medição
    
    sparki.servo (0);
    
    //Vamos imprimir no monitor LCD do Sparki os valores que estão sendo lidos:
    imprimir (distancia_direita, distancia_esquerda);
    
    if ( distancia_direita <= 20 && distancia_esquerda <= 20 ) //Neste caso, o robô está muito perto de obstáculos em todas as direções, então ele tenta voltar
    {
      sparki.moveRight (180); //Dá meia-volta
    }
    else
    {
      if ( distancia_direita > distancia_esquerda ) //Neste caso, há mais espaço para o robô ir na direita
      {
        sparki.moveRight (90); //Vira 90º para a direita
      }
      else //Neste caso, há mais espaço para o robô ir na esquerda
      {
        sparki.moveLeft (90); //Vira 90º para a esquerda
      }
    }
    
    delay (1000);
}

void imprimir (int dist_f)
{
  sparki.clearLCD (); //Limpa a tela
  sparki.print ("Distancia na frente = ");
  sparki.println (dist_f);
  sparki.updateLCD (); //Imprime na tela
}

void imprimir (int dist_d, int dist_e)
{
  sparki.clearLCD (); //Limpa a tela
  sparki.print ("Distancia na direita = ");
  sparki.println (dist_d);
  sparki.print ("Distancia na esquerda = ");
  sparki.println (dist_e);
  sparki.updateLCD (); //Imprime na tela
}

void imprimir (char *mensagem)
{
  sparki.clearLCD (); //Limpa a tela
  sparki.print (mensagem);
  sparki.updateLCD (); //Imprime na tela
}
