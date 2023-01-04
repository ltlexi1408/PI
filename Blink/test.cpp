#include <pigpio.h>
#include <cstdio>

int main(){
	bool temp;
	int i = 0;

	if(gpioInitialise() < 0){
		return 1;
	} else {
		gpioSetMode(4, PI_OUTPUT);
		while(i <= 30){
			gpioWrite(4, 0);
			time_sleep(0.5);
			gpioWrite(4, 1);
			time_sleep(0.5);
			i++;
		}
	}

	gpioTerminate();
	return 0;
}
