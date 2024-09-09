#include "BSP.h"

static const char *TAG = "example";

void app_main(void)
{
    #ifdef ESP32
        ESP_LOGI(TAG, "HOLA SOY UNA ESP32");
    #elif ESPC3
        ESP_LOGI(TAG, "HOLA SOY UNA ESPC3");
    #endif
        ESP_LOGI(TAG, "TERMINA PROGRAMA");
}
