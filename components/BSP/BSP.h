#ifndef BSP_H
#define BSP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "driver/uart.h"

//Definiciones generales
#define TRUE    1
#define FALSE   0

// Definiciones de pines y canales
#define LED_PIN     GPIO_NUM_8
#define BUTTON_PIN  GPIO_NUM_0
#define ADC_CHANNEL ADC1_CHANNEL_1
#define UART_PORT   UART_NUM_0

/*-----------------------------------------------------------*/
// Declaraciones de funciones

// Inicialización de periféricos
void Periph_Init(void);

// ADC (Conversor Analógico-Digital)
void ADC_Init(void);                    // Inicializar ADC
//int ADC_Read(adc_channel_t channel);    // Leer valor ADC

// GPIO
void GPIO_Init(void);                               // Inicializar GPIO
//void GPIO_Write(gpio_num_t gpio_num, int level);    // Escribir en GPIO
//int GPIO_Read(gpio_num_t gpio_num);                 // Leer GPIO

// LED
void LED_Init(void);            // Inicializar LED
void Set_LED_State(bool state);  // Encender/Apagar LED

// Botón
void Button_Init(void);         // Inicializar botón
bool Button_IsPressed(void);    // Verificar si el botón está presionado

// UART / Consola
void UART_Init(void);               // Inicializar UART
void UART_Write(const char* data);   // Enviar datos a la consola

#endif