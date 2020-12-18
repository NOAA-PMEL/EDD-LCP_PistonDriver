#ifndef _BSP_ADC12_H_
#define _BSP_ADC12_H_

#include <driverlib/driverlib.h>

void BSP_ADC12_Init(uint32_t);
float BSP_ADC12_Read(void);

#endif