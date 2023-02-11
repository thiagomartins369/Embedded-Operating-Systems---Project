#include <wiringPi.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int pin[6] = {15,16,1,4,28,29}; // Pino 15 (verde), 16 (azul), 1 (vermelho), 4 (Controle), 28 (Botão_Paring), 29 (Botão_Reg) na WiringPi

// Protótipos de funções que serão utilizadas:
void init_GPIO(void);
int ButtonRead(void);
int ButtonRead(void);

void init_GPIO(){
    
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
    // Inicialização dos LEDs
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], HIGH);
    sleep(1);
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
}

int ButtonRead(void){
    for (int i=4; i<6; i++){   
        printf("Rotina do Botão (%d)\n", pin[i]);
        int n=0;
        while(n<3)
        {
            printf("n = %d\n", n);
            puts("Pressione o botao\n");
            while(digitalRead(pin[i]));
            delay(50);
            if (digitalRead(pin[i]) == 0) {
                printf("Botao %d pressionado\n", pin[i]);
                n++;
            }
            while(digitalRead(pin[i])==0);
            delay(50);
            if (digitalRead(pin[i]) == 1) {
                puts("Botao solto\n");
            }
        }
    }
    return 0;
}

void* GateDrive(void){
    printf("Portão Acionado!!\n");
    digitalWrite(pin[3], HIGH);
    sleep(2);
    digitalWrite(pin[3], LOW);
    printf("Portão Desligado!!\n");
    return NULL;
}

void NoVehicleRecognitionLED(void){
    digitalWrite(pin[2], HIGH);
}