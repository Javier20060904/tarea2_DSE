#ifndef HAL_H
#define HAL_H

#include "BSP.h"

//Declaracion de macros
#define GPIO_Write(gpio_num, value) gpio_set_level(gpio_num, value)
#define GPIO_Read(gpio_num) gpio_get_level(gpio_num)
#define GPIO_Set(gpio_num, mode) gpio_set_direction(gpio_num, mode)
#define GPIO_PullMode(gpio_num, mode) gpio_set_pull_mode(gpio_num, mode)
#define GPIO_PullUpRes(gpio_num) gpio_pullup_en(gpio_num), gpio_pulldown_dis(gpio_num)
#define GPIO_PullDownRes(gpio_num) gpio_pulldown_en(gpio_num), gpio_pullup_dis(gpio_num)
#define GPIO_NoPullRes(gpio_num)  gpio_pulldown_dis(gpio_num), gpio_pullup_dis(gpio_num)
/*-----------------------------------------------------------*/
// Declaraciones de funciones

// ADC (Conversor Analógico-Digital)
void ADC_Init(adc_channel_t channel);                    // Inicializar ADC
int ADC_Read(adc_channel_t channel);    // Leer valor ADC
int Pot_Voltage(int ref_1,int ref_2);

// GPIO
void GPIO_Set_Interrupt(gpio_num_t puerto, gpio_isr_t function);                               // Inicializar GPIO

// UART / Consola
void UART_Init(void);               // Inicializar UART
void UART_Write(const char* data);   // Enviar datos a la consola

#endif