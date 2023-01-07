#include "led.h"

Led::Led(){
}

Led::Led(int gpio){
    this->gpio = gpio;
    gpioInitialise();
    gpioSetMode(this->gpio, PI_OUTPUT);
    off();
}

Led::~Led(){
    off();
}

void Led::setGpio(int pin){
    gpio = pin;
    gpioSetMode(gpio, PI_OUTPUT);
    off();
}

void Led::on(){
    gpioWrite(gpio, 1);
}

void Led::off(){
    gpioWrite(gpio, 0);
}