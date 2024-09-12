#include "aplication.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    systemInit();
    while(1){
        systemStatus();
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
