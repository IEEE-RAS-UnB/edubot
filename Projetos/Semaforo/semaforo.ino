#include "Sparki.h"
int a = 0;
void setup()
{
    sparki.RGB(RGB_GREEN);
    sparki.servo(0);
}

void loop()
{   
    int dist;
    dist = sparki.ping();
    if((dist < 10 && dist > -1)||(a>=10)){
        sparki.RGB(RGB_YELLOW);
        a=0;
        delay(2000);
        sparki.RGB(RGB_RED);
        delay(4000);
        sparki.RGB(RGB_GREEN);
        sparki.beep(100,1000);
        delay(10000);
    }
    else{
        if(a < 10){
            delay(500);
            a++;
        }
        sparki.beep(500);
    }

    sparki.RGB(RGB_GREEN);
}
