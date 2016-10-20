/**
 * Edubot Demo
 *  Combination of multiple functions
 *  0 - Do nothing
 *  1 - Controled by Remote
 *  2 - Light Follower
 *  3 - Light Avoid
 *  4 - Line Follower
 *  
 *  @author Rafael Lima
 *  @version 0.3
 */

#include <Sparki.h>  // include the robot library

// Control Codes
// /------^-----\
// |            |
// | 69  70  71 |
// | 68  64  67 |
// |  7  21   9 |
// | 22  25  13 |
// | 12  24  94 |
// |  8  28  90 |
// | 66  82  74 |
// \____________/

// State Codes
#define DO_NOTHING_MODE 0
#define HUMAN_CONTROL_MODE 1
#define LIGHT_FOLLOWER_MODE 2
#define LIGHT_FOLLOWER_AVOID 3
#define LINE_FOLLOWER_MODE 4

// Calibration Constants
#define MIN_LIGHT 995
#define LINE_THRESHOLD 700
#define SERVO_LEFT 80
#define SERVO_RIGHT -80

// State Variables
int status;

void setup() {
  // put your setup code here, to run once:
  sparki.servo(SERVO_CENTER); // center the servo

  // Set Init State
  status = HUMAN_CONTROL_MODE;
}

void loop() {
  // Read Sensors
  int code = sparki.readIR();   //Scan for IR Receiver
  int centerLight = sparki.lightCenter();
  int leftLight = (sparki.lightLeft() - MIN_LIGHT)*100;
  int rightLight = (sparki.lightRight() - MIN_LIGHT)*100;
  
  int lineLeft   = sparki.lineLeft();   // measure the left IR sensor
  int lineCenter = sparki.lineCenter(); // measure the center IR sensor
  int lineRight  = sparki.lineRight();  // measure the right IR sensor

  // Set mode
  changeMode(code);

  switch(status){
    case HUMAN_CONTROL_MODE:
        modeHumanControl(code);
        break;
    case LIGHT_FOLLOWER_MODE:
        light_follower(leftLight,rightLight);
        break;
    case LIGHT_FOLLOWER_AVOID:
        light_avoid(leftLight,rightLight);
        break;
    case LINE_FOLLOWER_MODE:
        line_follower(lineLeft,lineCenter,lineRight, LINE_THRESHOLD);
        break;
    case DO_NOTHING_MODE:
    default:
        sparki.moveStop(); // stop the motor
        sparki.RGB(RGB_OFF); // clear the RGB
        break;
  }
}

/**
 * Set Sparki mode based on remote control number buttons
 */
void changeMode(int code){
  switch(code){
    case 25:
       status = DO_NOTHING_MODE;
       break;
    case 64:
       status = HUMAN_CONTROL_MODE;
       break;
    case 24:
       status = LIGHT_FOLLOWER_MODE;
       break;
    case 94:
       status = LINE_FOLLOWER_MODE;
       break;
    default:
       status = status;
  }
}

/**
 * Control robot moviment using remote control arrows
 */
void modeHumanControl(int code){
  sparki.RGB(100,0,0); // RED light to make it look dangerous ..
  switch(code){
    case 70: sparki.moveForward(); break;
    case 21: sparki.moveBackward(); break;
    case 67: 
    case 71: sparki.moveRight(); break;
    case 68: 
    case 69: sparki.moveLeft(); break;
    case 64: sparki.moveStop();
             sparki.gripperStop(); 
             break;      

    // Gripper Buttons
    case 9:  sparki.gripperOpen(); break;
    case 7:  sparki.gripperClose(); break;

    // buzzer
    case 74: sparki.beep(); break;

    // Servo
    case 90: sparki.servo(SERVO_LEFT); break;
    case 28: sparki.servo(SERVO_CENTER); break;
    case 8: sparki.servo(SERVO_RIGHT); break;
  }
}

/**
 * Move "head" to the light and follow
 */
void light_follower(int leftLight, int rightLight){
   // Avoid Light
   sparki.RGB(50,100,70);
   sparki.motorRotate(MOTOR_LEFT, DIR_CCW, leftLight/11); // Mapping: leftLight/round(1024/100)
   sparki.motorRotate(MOTOR_RIGHT, DIR_CW, rightLight/11); // Mapping: rightLight/round(1024/100)
   sparki.servo((rightLight-leftLight)/15); // Mapping adjusted to make it 'look' to the light
}

/**
 * Move "head" against the light and run out
 */
void light_avoid(int leftLight, int rightLight){
   // Follow Light
   sparki.RGB(0,0,100);
   sparki.motorRotate(MOTOR_LEFT, DIR_CW, leftLight/11); // Mapping: leftLight/round(1024/100)
   sparki.motorRotate(MOTOR_RIGHT, DIR_CCW, rightLight/11); // Mapping: rightLight/round(1024/100)
   sparki.servo((leftLight-rightLight)/12); // Mapping: (leftLight-rightLight)/round(1024/90)
}

/**
 * Basic line Follower
 */
void line_follower(int lineLeft, int lineCenter, int lineRight, int threshold){
  sparki.RGB(0,100,0);
  if ( lineCenter < threshold ) // if line is below left line sensor
  {  
    sparki.moveForward(); // move forward
  }
  else{
    if ( lineLeft < threshold ) // if line is below left line sensor
    {  
      sparki.moveLeft(); // turn left
    }
  
    if ( lineRight < threshold ) // if line is below right line sensor
    {  
      sparki.moveRight(); // turn right
    }
  }
}
