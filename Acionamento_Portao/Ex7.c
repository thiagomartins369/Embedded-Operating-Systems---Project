#include <wiringPi.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int pin[6] = {15,16,1,4,28,29}; // Pino GPIO4 é o 7 na WiringPi
    int i=0;

	wiringPiSetup();
    while (i<6)
    {
        if (i<4)
        {
            pinMode(pin[i], OUTPUT);
        } else 
        {
            pinMode(pin[i], INPUT);
            pullUpDnControl(pin[i], PUD_UP);
        } 
        i++;
    }
    

    for (i=0; i<4; i++){
        printf("Acionando o pino %d...\n", pin[i]);
        digitalWrite(pin[i], HIGH);
        printf("Escrevendo no pino %d...\n", pin[i]);
        sleep(1);
        printf("Apagando o pino %d...\n", pin[i]);
        digitalWrite(pin[i], LOW);
    }
	
    for (i=4; i<6; i++)
    {   
        printf("Rotina do Botão (%d)\n", pin[i]);
        int n=0;
        while(n<3)
        {
            printf("n = %d\n", n);
            puts("Pressione o botao\n");
            while(digitalRead(pin[i]));
            printf("Botao %d pressionado\n", pin[i]);
            while(digitalRead(pin[i])==0);
            puts("Botao solto\n");
            n++;
        }
    }
    
        

	return 0;
}