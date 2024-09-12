#include "aplication.h"

static const char *TAG = "example";

bool systemState = true, adcState = true;

static void IRAM_ATTR systemInterrupt(){
    ESP_LOGI(TAG, "INTERRUPCION");
}

void systemInit(void){
    ADC_Init(ADC_CHANNEL);
    GPIO_Set(LED_PIN, GPIO_MODE_OUTPUT);
    GPIO_Write(LED_PIN, systemState);
    GPIO_Set(BUTTON_PIN, GPIO_MODE_INPUT);
    GPIO_Set_Interrupt(BUTTON_PIN, systemInterrupt);
    ESP_LOGI(TAG, "INICIA SISTEMA");
}

void systemTerminate(void){
    systemState = false;
    GPIO_Write(LED_PIN, false);
    ESP_LOGI(TAG, "SISTEMA APAGADO");
}

void systemStatus(void){
    ESP_LOGI(TAG, "ESTADO DEL SISTEMA: %d", systemState);
    if(adcState == false)
        ESP_LOGI(TAG, "NO DISPONIBLE");
    ESP_LOGI(TAG, "LECTURA DEL ADC: %d", ADC_Read(ADC_CHANNEL));
}