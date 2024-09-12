#include "aplication.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



void app_main(void)
{   
    periphInit();
    systemInit();
    #if !RTOS
        while(1){
            systemBehavior();
            vTaskDelay(2000 / portTICK_PERIOD_MS);
        }
    #elif RTOS
        xTaskCreate(vADC, "vADC", 4096, NULL, 10, &adcHandle);
        xTaskCreate(vSystem, "vADC", 2048, NULL, 10, &systemHandle);
    #endif
}
