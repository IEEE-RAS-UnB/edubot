#include<sparki.h>
int sensor = 0;
void setup () 
{
}

void loop () 
{
  sensor = sparki.ping();
  sparki.moveFoward();
  sparki.println(sensor);
  delay(1500);
  if (sensor <= 15)
  {
    sparki.moveStop();
  }
    
}




