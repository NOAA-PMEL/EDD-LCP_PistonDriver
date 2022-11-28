#ifndef _BSP_PWM_H_
#define _BSP_PWM_H_

#ifndef TEST
#include "driverlib.h"
#endif

void BSP_PWM_Init(void);
void BPS_PWM_SetPWM(uint8_t chan, uint16_t pwm);


#endif
