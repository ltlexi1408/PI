.default: all

all: blink5

clean:
	rm -rf blink5 *.o

blink5: led.o main.o
	g++ -Wall -Werror -g -O -o $@ $^

%.o: %cpp
	++ -Wall -Werror -lpigpio -lrt -lpthread -g -O -c $^