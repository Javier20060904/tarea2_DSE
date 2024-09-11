#include "aplication.h"

static const char *TAG = "example";

static void IRAM_ATTR systemInterrupt(){
    ESP_LOGI(TAG, "INTERRUPCION");
}

void systemInit(void){
    ADC_Init(ADC_CHANNEL);
    GPIO_Set(LED_PIN, GPIO_MODE_OUTPUT);
    GPIO_Write(LED_PIN, HIGH);
    GPIO_Set(BUTTON_PIN, GPIO_MODE_INPUT);
    GPIO_Set_Interrupt(BUTTON_PIN, systemInterrupt);
    ESP_LOGI(TAG, "INICIA SISTEMA");
}

void systemTerminate(void){
    GPIO_Write(LED_PIN, LOW);
    ESP_LOGI(TAG, "SISTEMA APAGADO");
}

void systemStatus(void){
    bool s = GPIO_Read(LED_PIN);
    ESP_LOGI(TAG, "ESTADO DEL SISTEMA: %d", s);
}