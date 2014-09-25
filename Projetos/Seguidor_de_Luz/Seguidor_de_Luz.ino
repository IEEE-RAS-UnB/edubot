#include <Sparki.h> // include the sparki library

void setup() 
{
}

void loop() {
  //pode mudar o offset dependendo da "área" da luz que está sendo emitida e deseja que o sparki siga
  int offset = 30;
  int left   = sparki.lightLeft();   // measure the left light sensor
  int center = sparki.lightCenter(); // measure the center light sensor
  int right  = sparki.lightRight();  // measure the right light sensor
  
  sparki.clearLCD();
  sparki.print("Left: "); 
  sparki.println(left); // tells the distance to the computer
  sparki.print("Center: "); 
  sparki.println(center); // tells the distance to the computer
  sparki.print("Right: "); 
  sparki.println(right); // tells the distance to the computer
  sparki.updateLCD();

  if ( (right > (center+offset)) && (right > (left+offset)) )  // if the right light is the strongest
  {  
    sparki.moveRight(); // turn right
  }else if( (left > (center+offset)) && (left > (right+offset)) )  // if the left light is the strongest
  {   
    sparki.moveLeft(); // turn left
  }else{
    sparki.moveForward(); // move forward
  }
  
  delay(100); // wait 0.1 seconds
}
