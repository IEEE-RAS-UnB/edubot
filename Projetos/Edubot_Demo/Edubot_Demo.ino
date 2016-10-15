/**
 * Edubot Demo
 *  Combination of multiple functions
 *  0 - Do nothing
 *  1 - Controled by Remote
 *  2 - Light Follower
 *  3 - Light Avoid
 *  
 *  @author Rafael Lima
 *  @version 0.3
 */

#include <Sparki.h>  // include the robot library

// State Codes
#define DO_NOTHING_MODE 0
#define HUMAN_CONTROL_MODE 1
#define LIGHT_FOLLOWER_MODE 2
#define LIGHT_FOLLOWER_AVOID 3

// State Variables
int status;

void setup() {
  // put your setup code here, to run once:
  sparki.servo(SERVO_CENTER); // center the servo

  // Set Init State
  status = HUMAN_CONTROL_MODE;
}

void loop() {
  //Scan for IR Receiver
  int code = sparki.readIR();

  switch(status){
    case HUMAN_CONTROL_MODE:
        modeHumanControl(code);
        break;
    case LIGHT_FOLLOWER_MODE:
        light_follower();
        break;
    case LIGHT_FOLLOWER_AVOID:
        light_avoid();
        break;
    case DO_NOTHING_MODE:
    default:
        sparki.moveStop(); // stop the motor
        sparki.RGB(RGB_OFF); // clear the RGB
        break;
  }

  changeMode(code);
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
    case 22:
       status = LIGHT_FOLLOWER_AVOID;
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
void light_follower(){
  int leftLight = sparki.lightLeft();
  int rightLight = sparki.lightRight();

   // Avoid Light
   sparki.RGB(50,100,70);
   sparki.motorRotate(MOTOR_LEFT, DIR_CCW, leftLight/11);
   sparki.motorRotate(MOTOR_RIGHT, DIR_CW, rightLight/11);
   sparki.servo((rightLight-leftLight)/15);
}

/**
 * Move "head" against the light and run out
 */
void light_avoid(){
  int leftLight = sparki.lightLeft();
  int rightLight = sparki.lightRight();

   // Follow Light
   sparki.RGB(0,0,100);
   sparki.motorRotate(MOTOR_LEFT, DIR_CW, leftLight/11);
   sparki.motorRotate(MOTOR_RIGHT, DIR_CCW, rightLight/11);
   sparki.servo((leftLight-rightLight)/12);
}
