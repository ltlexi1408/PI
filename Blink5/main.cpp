#include "led.h"

#define LEDS 5

Led leds[LEDS];


int main(){
    //Gpio Led pins
    int pins[LEDS] = {4, 17, 27, 22, 18};

    if(gpioInitialise() < 0){
        return 1;
    } else{
        //Button power
        gpioSetMode(10, PI_OUTPUT);
        //Button input to pi 
        gpioSetPullUpDown(9, PI_PUD_UP);

        for(int i = 0; i < LEDS; i++){
            leds[i].setGpio(pins[i]);
        }

        while(true){
            for(int i = 0; i < LEDS; i++){
                leds[i].on();
                time_sleep(0.5);
                leds[i].off();
                if(gpioRead(9) == 0){
                    break;
                }
            }
        }
    }

    gpioTerminate();

    return 0;
}