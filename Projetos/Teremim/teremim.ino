#include <Sparki.h>

int distancia;
int tom;
int luz;

void setup() {
  sparki.clearLCD();
  sparki.servo(0);
  sparki.RGB(100,0,0);
}

void loop() {
  distancia = sparki.ping();
  tom = 200 + pow(1.2, distancia);
  luz = tom % 101;

  if((distancia != -1) && (distancia < 50)){
    sparki.print(tom);
    sparki.beep(tom);
    sparki.RGB(100-luz, luz, (((100-luz)*luz)/100));
  }
  else{
    sparki.noBeep();
    sparki.RGB(0,0,0);
  }
  
  sparki.updateLCD();
  delay(10);
  sparki.clearLCD();

}
