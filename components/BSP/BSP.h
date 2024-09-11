#ifndef BSP_H
#define BSP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "esp_log.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_adc/adc_oneshot.h"


//Declaracion de macros
#define GPIO_Write(gpio_num, value) gpio_set_level(gpio_num, value)
#define GPIO_Read(gpio_num) gpio_get_level(gpio_num)
#define GPIO_Set(gpio_num, mode) gpio_set_direction(gpio_num, mode)

//Definiciones generales
#define TRUE    1
#define FALSE   0
#define LOW FALSE
#define HIGH TRUE

// Definiciones de pines y canales
#define LED_PIN     GPIO_NUM_2
#define BUTTON_PIN  GPIO_NUM_0
#define ADC_CHANNEL ADC_CHANNEL_1
#define UART_PORT   UART_NUM_0

/*-----------------------------------------------------------*/
// Declaraciones de funciones

// ADC (Conversor Analógico-Digital)
void ADC_Init(adc_channel_t channel);                    // Inicializar ADC
int ADC_Read(adc_channel_t channel);    // Leer valor ADC

// GPIO
void GPIO_Set_Interrupt(gpio_num_t puerto, gpio_isr_t function);                               // Inicializar GPIO

// LED
void LED_State(bool state);  // Encender/Apagar LED

// UART / Consola
void UART_Init(void);               // Inicializar UART
void UART_Write(const char* data);   // Enviar datos a la consola

#endif