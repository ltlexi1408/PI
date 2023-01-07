#include "led.h"
#include <unistd.h>
#include <signal.h>

#define LEDS 5

Led leds[LEDS];
pid_t child = -1;

int main(){
    //Gpio Led pins
    int pins[LEDS] = {4, 17, 27, 22, 18};

    if(gpioInitialise() < 0){
        return 1;
    } else{
        for(int i = 0; i < LEDS; i++){
            leds[i].setGpio(pins[i]);
        }
        
        child = fork();

        if(child == 0){
            while(true){
                for(int i = 0; i < LEDS; i++){
                    leds[i].on();
                    time_sleep(0.5);
                    leds[i].off();
                }
            }
        } else{
            //Button power
            gpioSetMode(10, PI_OUTPUT);
            //Button input to pi 
            gpioSetPullUpDown(9, PI_PUD_UP);

            while(true){
                if(gpioRead(9) == 0){
                    kill(child, SIGKILL);
                    for(int i = 0; i < LEDS; i++){
                        leds[i].off();
                    }
                    break;
                }
            }
        }
    }

    gpioTerminate();

    return 0;
}