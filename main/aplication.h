#ifndef APLICATION_H
#define APLICATION_H

#include "HAL.h"

#define RTOS 1

#if RTOS
    extern TaskHandle_t adcHandle;
    extern TaskHandle_t systemHandle;
#endif

void systemInit();
void systemTerminate();
void periphInit(void);

#if !RTOS
    void systemBehavior();
#elif RTOS
    void vADC(void *arg);
    void vSystem(void *arg);
#endif

#endif