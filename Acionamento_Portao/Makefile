CC=gcc
CFLAGS=-Wall -O
Parameters=-lwiringPi -lpthread

all: Driver_GPIO.out

Driver_GPIO.out: Driver_GPIO.c
	$(CC) $(CFLAGS) Driver_GPIO.c -o Driver_GPIO.out $(Parameters)

clean:
	rm -f *.out *.o *.bin *.txt *.html