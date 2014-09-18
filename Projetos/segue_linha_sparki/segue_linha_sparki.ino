#include <Sparki.h> //inclui a biblioteca do Sparki

/*esse programa eh um segue linha, ou seja, ele deve utilizar os seus sensores de LDR para perceber se esta
na linha, ou seja, se esta no "escuro" ou esta fora dela, ou seja, no "claro" e se movimentar de acordo com isso para seguir a linha PRETA*/

void setup()
{
  
}

void loop(){
   int sensor=200;
   // o sensor LDR percebe que para valores proximos de 200 a iluminacao esta baixa, portanto percebe que esta "escuro"
   // para valores acima de 200 o ldr percebe que esta "claro". A leitura do LDR vai de 0 a 1000, sendo 1000 o dado que indica maior iluminacao e 0 o dado que indica menor iluminacao possivel.
   int botao = sparki.readIR(); // o "botao" eh a variavel que le o valor do botao pressionado no controle remoto do sparki. 
   int sensor_esquerdo; //sensor LDR do lado esquerdo que le as variaveis de iluminacao do ambiente.
   int sensor_centro; // sensor LDR do meio que le as variaveis de iluminacao do ambiente.
   int sensor_direito; // sensor LDR do lado direito que le as variaveis de iluminacao do ambiente.
   //obs: eles so precisam ser lidos no loop while, quando for dado o comando para o Sparki comecar sua movimentacao para seguir a linha.
   int a=1; //variavel de inicializacao do programa.
   
   //esse programa so inicializa quando pressionado o botao equivalente ao valor 70, e so para se pressionado o botao de valor 13.
   if (botao==70){ 
     a=70;
   }
   while(a==70){
         sensor_esquerdo = sparki.lineLeft(); //em cada loop vai ler a variavel do sensor LDR esquerdo.
         sensor_centro = sparki.lineCenter();//em cada loop vai ler a variavel do sensor LDR central.
         sensor_direito = sparki.lineRight();//em cada loop vai ler a variavel do sensor LDR direito.
         if (sensor_centro < sensor){ //se o sensor do centro receber menos que 250 entao estara no preto e portanto, o Sparki deve continuar andando reto.
           sparki.moveForward();//mover para frente
         }
         else { //caso o sensor do meio percebe um nivel "banco, ou "fora da linha", entao temos dois casos: ou ele saiu pela direita ou pela esquerda da linha.
           if (sensor_esquerdo > (sensor+100)) //caso ele saia pela esquerda entao o valor do sensor LDR esquerdo tbm estara lendo um valor maior que 200, nessa situacao, o Sparki deve corrigir a tragetoria virando para direita.
           {
             sparki.moveRight();//mover para direita
           }
     
           if(sensor_direito > (sensor+100))//caso ele saia pela direita entao o valor do sensor LDR direito tbm estara lendo um valor maior que 200, nessa situacao, o Sparki deve corrigir a tragetoria virando para esquerda.
           {
             sparki.moveLeft();//mover para a esqueda
           }
         }
         
         //obs: entre 200 e 300 o robo continua a fazer o que estava fazendo antes, essa seria numa margem de "ruido" para o programa
         botao = sparki.readIR(); //leitura novamente do botao para saber se alguma tecla foi pressionada.
         if(botao==13){ //caso o 13 tenha sido pressionado entao o robo ira parar e loop while ira acabar.
           a=13; //note com a=13 o loop nao ira parar
           sparki.moveStop(); //comando para o Sparki parar de se mover
         }
     //os comandos abaixos sao os comandos de controles mostrados no painel do arduino sobre as leituras dos sensores.
     sparki.clearLCD(); //primeiramente limpamos a tela,
   
     sparki.print("Sensor esquerda: "); //logo apos coletamos os dados lidos pelos sensores e os printamos no LCD,
     sparki.println(sensor_esquerdo);
   
     sparki.print("Sensor centro: ");
     sparki.println(sensor_centro);
   
     sparki.print("Sensor direita: ");
     sparki.println(sensor_direito);
   
     sparki.updateLCD(); // e finalmente fazemos a atualizacao do LCD.
     delay (100);//espera 0.1 segundo para a visualizacao no LCD nao ficar tao confusa (e se o tempo fosse maior, tipo 1 segundo, iria atrapalhar o desenvolvimento do programa).
   }
   
}
