#include "bsp_pwm.h"

//Timer_B_outputPWMParam param = {
//  .clockSource = TIMER_B_CLOCKSOURCE_SMCLK,             /** 2MHz */
//  .clockSourceDivider = TIMER_B_CLOCKSOURCE_DIVIDER_1, 
//  .timerPeriod = 50000,
//  .compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_3,
//  .compareOutputMode = TIMER_B_OUTPUTMODE_RESET_SET,
//  .dutyCycle = 0
//};

static Timer_B_outputPWMParam param0 = {
  .clockSource = TIMER_B_CLOCKSOURCE_SMCLK,
  .clockSourceDivider = TIMER_B_CLOCKSOURCE_DIVIDER_1,
  .timerPeriod = 1023,
  .compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_3,
  .compareOutputMode = TIMER_B_OUTPUTMODE_RESET_SET,
  .dutyCycle = 0
};

static Timer_B_outputPWMParam param1 = {
  .clockSource = TIMER_B_CLOCKSOURCE_SMCLK,
  .clockSourceDivider = TIMER_B_CLOCKSOURCE_DIVIDER_1,
  .timerPeriod = 1023,
  .compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_5,
  .compareOutputMode = TIMER_B_OUTPUTMODE_RESET_SET,
  .dutyCycle = 0
};
//

void BSP_PWM_Init(void)
{
  Timer_B_outputPWM(TIMER_B0_BASE, &param0);
  Timer_B_outputPWM(TIMER_B0_BASE, &param1);
}


void BPS_PWM_SetPWM(uint8_t chan, uint16_t pwm)
{
  if(pwm > 1024) {
    pwm = 1024;
  }
  if(chan == 0) {
    param0.dutyCycle = pwm;
    Timer_B_outputPWM(TIMER_B0_BASE, &param0);
  }else if(chan == 1) {
    param1.dutyCycle = pwm;
    Timer_B_outputPWM(TIMER_B0_BASE, &param1);
  }
  
  __bis_SR_register(GIE);
}