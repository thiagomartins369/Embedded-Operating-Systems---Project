CC=gcc
CFLAGS=-Wall -O

all: Driver_GPIO.out

Driver_GPIO.out: Driver_GPIO.c
	$(CC) $(CFLAGS) Driver_GPIO.c -o Driver_GPIO.out -lwiringPi

clean:
	rm -f *.out *.o *.bin *.txt *.html