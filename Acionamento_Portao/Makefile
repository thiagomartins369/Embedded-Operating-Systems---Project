all: Ex2.out control_activation.out
Ex2.out: Ex2.o gpio_sysfs.o
	gcc Ex2.o gpio_sysfs.o -o Ex2.out
Ex3.out: control_activation.o gpio_dev_mem.o
	gcc control_activation.o gpio_dev_mem.o -o control_activation.out
Ex2.o: Ex2.c
	gcc -c Ex2.c
control_activation.o: control_activation.c
	gcc -c control_activation.c
gpio_sysfs.o: gpio_sysfs.c
	gcc -c gpio_sysfs.c
gpio_dev_mem.o: gpio_dev_mem.c
	gcc -c gpio_dev_mem.c
clean:
	rm -f *.out *.o *.bin *.txt *.html	
