#include "gpio_sysfs.h"
#include <unistd.h>

// int initializeGPIO(int pin) {
//     if (setGPIOdirection(pin, "out") < 0)
		
//         return -1;
//     if (GPIOwrite(pin, 1) < 0)
		
//         return -2;
//     return 0;
// }

// int main() {
//     int pin = 14;

//     if (initializeGPIO(pin) < 0)
// 		printf("Inicializando o pino %d...\n", pin);
//         return -1;
	
//     sleep(5);
//     if (unsetGPIO(pin) < 0)
// 		printf("Limpando o pino %d...\n", pin);
//         return -2;

//     return 0;

	int main()
{
	// int pin[4]={14,15,18,23};
	int pin = 14;			
			
		if(setGPIOdirection(pin, "out")<0)
			printf("Setando o pino %d como 'out'\n", pin);
		return -1;

		if(GPIOwrite(pin, 1)<0)
			printf("Escrevendo no pino %d...\n", pin);
		return -2;

		printf("Aguardando 5 segundos!\n");
		sleep(5);

		if(unsetGPIO(pin)<0)
			printf("Limpando o pino %d...\n", pin);
		return -3;
	
	return 0;
}
//}