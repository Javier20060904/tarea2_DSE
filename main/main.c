#include "aplication.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    systemInit();
    #if !RTOS
    while(1){
        systemBehavior();
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
    #endif
}
