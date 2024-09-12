#include "aplication.h"

#if RTOS
    TaskHandle_t adcHandle = NULL;
    TaskHandle_t systemHandle = NULL;

#endif

static const char *TAG = "example";

bool systemState = true, adcState = true;

static void IRAM_ATTR systemInterrupt(){
    ESP_LOGI(TAG, "INTERRUPCION");
    systemTerminate();
}

void periphInit(void){
    ADC_Init(ADC_CHANNEL);
    GPIO_Set(LED_PIN, GPIO_MODE_OUTPUT);
    GPIO_Set(BUTTON_PIN, GPIO_MODE_INPUT);
    GPIO_Set_Interrupt(BUTTON_PIN, systemInterrupt);
}

void systemInit(void){
    systemState = true;
    adcState = true;
    GPIO_Write(LED_PIN, systemState);
    #if RTOS
        if(adcHandle != NULL)
            vTaskResume(adcHandle);
    #endif
    ESP_LOGI(TAG, "INICIA SISTEMA");
}

void systemTerminate(void){
    systemState = false;
    adcState = false;
    GPIO_Write(LED_PIN, systemState);
    #if RTOS
        vTaskSuspend(adcHandle);
    #endif
    ESP_LOGI(TAG, "SISTEMA APAGADO");
}

#if !RTOS
    void systemBehavior(void){
        ESP_LOGI(TAG, "ESTADO DEL SISTEMA: %s", systemState ? "ENCENDIDO" : "APAGADO");
        if(!adcState){
            ESP_LOGI(TAG, "NO DISPONIBLE");
            return;
        }
        ESP_LOGI(TAG, "LECTURA DEL ADC: %d", ADC_Read(ADC_CHANNEL));
    }

#elif RTOS
    void vADC(void *arg){
        while(1){
            ESP_LOGI(TAG, "LECTURA DEL ADC: %d", ADC_Read(ADC_CHANNEL));
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }

    void vSystem(void *arg){
        while (1)
        {
            ESP_LOGI(TAG, "ESTADO DEL SISTEMA: %s", systemState ? "ENCENDIDO" : "APAGADO");
            if(!adcState){
                ESP_LOGI(TAG, "NO DISPONIBLE");
            }
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }    
    }
#endif