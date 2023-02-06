CC=gcc
CFLAGS=-Wall -O

all: Ex2.out control_activation.out 

gpio_dev_mem.o: gpio_dev_mem.c gpio_dev_mem.h
	$(CC) $(CFLAGS) -c $< -o $@
gpio_sysfs.o: gpio_sysfs.c gpio_sysfs.h
	$(CC) $(CFLAGS) -c $< -o $@
Ex2.o: Ex2.c 
	$(CC) $(CFLAGS) -c $< -o $@
control_activation.o: control_activation.c 
	$(CC) $(CFLAGS) -c $< -o $@

Ex2.out: Ex2.o gpio_sysfs.o
	$(CC) $(CFLAGS) -o Ex2.out Ex2.o gpio_sysfs.o
control_activation.out: control_activation.o gpio_dev_mem.o
	$(CC) $(CFLAGS) -o control_activation.out control_activation.o gpio_dev_mem.o


clean:
	rm -f *.out *.o *.bin *.txt *.html