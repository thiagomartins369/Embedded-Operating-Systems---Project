 // Access from ARM Running Linux
#include "gpio_dev_mem.h"

volatile unsigned *gpio;

//Compile junto com o arquivo gpio_dev_mem.c
int main(int argc, char **argv)
{
	// Set up gpi pointer for direct register access
	setup_io();
	INP_GPIO(15);
	OUT_GPIO(15);
	GPIO_SET = 1<<4;
	sleep(5);
	GPIO_CLR = 1<<4;
	return 0;
}