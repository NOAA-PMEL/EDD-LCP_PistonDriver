#ifndef _BSP_ADC12_H_
#define _BSP_ADC12_H_

#ifndef TEST
#include <driverlib/driverlib.h>
#endif

void BSP_ADC12_Init(uint32_t);
float BSP_ADC12_Read(void);
uint32_t BSP_ADC12_Address_for_DMA(void);

#endif