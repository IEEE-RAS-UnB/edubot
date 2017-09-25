#include <Sparki.h>

int sensor_c;
int sensor_r;
int sensor_l;

void setup() {
  // put your setup code here, to run once:
  sensor_c=0;
  sensor_r=0;
  sensor_l=0;
  sparki.RGB(0,0,100);
}

void loop() {
  // put your main code here, to run repeatedly:

sensor_c=sparki.lineCenter();
sensor_r=sparki.lineRight();
sensor_l=sparki.lineLeft();


if(sensor_c<400){ // Preto
  sparki.moveForward();
  sparki.RGB(0,100,0);
 
}
else if(sensor_l<400){ // Branco 
  sparki.moveLeft();
  sparki.RGB(100,0,0);


}
else if(sensor_r<400){ // Branco
  sparki.moveRight();
  sparki.RGB(0,0,100);

}
  delay(150);

}
