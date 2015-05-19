
#include <Sparki.h>


int a = 3;
int b = 3;

void setup()
{  
  sparki.clearLCD();
  if(a==b)
  {
    sparki.print("a e b sao iguais!");
  }
  sparki.updateLCD();
}
void loop () 
{ 

}

//mude os valores de a e b tal que a nao seja mais igual a b e veja o que acontece.
