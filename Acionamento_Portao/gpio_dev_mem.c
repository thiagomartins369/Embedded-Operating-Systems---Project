#include "gpio_dev_mem.h"

//
// Set up a memory regions to access GPIO
//

int  mem_fd;
void *gpio_map;
// I/O access


void setup_io()
{
	/* open /dev/mem */
	if((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0)
	{
		printf("can't open /dev/mem \n");
		exit(-1);
	}

	/* mmap GPIO */
	gpio_map = mmap(
				NULL,             //Any adddress in our space will do
				BLOCK_SIZE,       //Map length
				PROT_READ|PROT_WRITE,// Enable reading & writting to mapped memory
				MAP_SHARED,       //Shared with other processes
				mem_fd,           //File to map
				GPIO_BASE         //Offset to GPIO peripheral
			);
	close(mem_fd); //No need to keep mem_fd open after mmap
	if(gpio_map == MAP_FAILED)
	{
		printf("mmap error %p\n", gpio_map);//error also set!
		exit(-1);
	}
	gpio = (volatile unsigned *)gpio_map;
}
