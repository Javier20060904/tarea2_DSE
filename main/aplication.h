#ifndef APLICATION_H
#define APLICATION_H

#include "HAL.h"

#if RTOS
    extern TaskHandle_t adcHandle;
    extern TaskHandle_t systemHandle;
    extern TaskHandle_t buttonHandle;
#endif

#define VOLTAGE_READ(adc) (ADC_Read(adc) * 5 / 4095)
//#define VOLTAGE_POT(ref_1,ref_2) (5* ((ADC_Read(ref_1)-ADC_Read(ref_2))/(4095-ADC_Read(ref_2))) )

int voltagePot(int ref_1, int ref_2);

void systemInit();
void periphInit(void);

#if !RTOS
    void systemBehavior();
#elif RTOS
    void vADC(void *arg);
    void vSystem(void *arg);
    void vButton(void *arg);
#endif

#endif