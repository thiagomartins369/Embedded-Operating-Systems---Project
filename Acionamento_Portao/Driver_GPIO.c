#include "Driver_GPIO.h"

int SimulationPlateRecognized(){
    int plate = 12345;
    return plate;
}

void* VehicleRecognitionLED(void){
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[1], HIGH);
    sleep(3);
    digitalWrite(pin[1], LOW);
    return NULL;
}

void* LEDThread(void* dummy_ptr){
    VehicleRecognitionLED();
    return NULL;
}

void* GateThread(void* dummy_ptr){
    printf("thread gate chamada\n");
    GateDrive();

    return NULL;
}

int main()
{   
	init_GPIO();

    int placa = SimulationPlateRecognized();

    pthread_t LED_thread;
    pthread_t Gate_thread;

    for (int i = 0; i < 4; i++)
    {   
        if (placa == 12345){
        sleep(0.5);
        printf("Placa Encontrada: %d\n", placa);
        pthread_create(&LED_thread, NULL, &LEDThread, NULL);
        pthread_create(&Gate_thread, NULL, &GateThread, NULL);
        } else NoVehicleRecognitionLED();
    }
    
    ButtonRead();

	return 0;
}