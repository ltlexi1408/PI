#ifndef LED
#define LED

#include <pigpio.h>

class Led{
    public:
    Led();
    Led(int gpio);
    ~Led();

    void setGpio(int pin);

    void on();
    void off();

    private:

    int gpio;
    int power;
};

#endif
