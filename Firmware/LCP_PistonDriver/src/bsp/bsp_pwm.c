#include "bsp_pwm.h"
#include "logging.h"

static bool pwm_running = false;

//Timer_B_outputPWMParam param = {
//  .clockSource = TIMER_B_CLOCKSOURCE_SMCLK,             /** 2MHz */
//  .clockSourceDivider = TIMER_B_CLOCKSOURCE_DIVIDER_1, 
//  .timerPeriod = 50000,
//  .compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_3,
//  .compareOutputMode = TIMER_B_OUTPUTMODE_RESET_SET,
//  .dutyCycle = 0
//};

//static Timer_B_outputPWMParam param0 = {
//  .clockSource = TIMER_B_CLOCKSOURCE_SMCLK,
//  .clockSourceDivider = TIMER_B_CLOCKSOURCE_DIVIDER_1,
//  .timerPeriod = 1023,
//  .compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_3,
//  .compareOutputMode = TIMER_B_OUTPUTMODE_RESET_SET,
//  .dutyCycle = 0
//};
//
//static Timer_B_outputPWMParam param1 = {
//  .clockSource = TIMER_B_CLOCKSOURCE_SMCLK,
//  .clockSourceDivider = TIMER_B_CLOCKSOURCE_DIVIDER_1,
//  .timerPeriod = 1023,
//  .compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_5,
//  .compareOutputMode = TIMER_B_OUTPUTMODE_RESET_SET,
//  .dutyCycle = 0
//};
//

static Timer_B_initUpModeParam param = {
    .clockSource = TIMER_B_CLOCKSOURCE_SMCLK,
    .clockSourceDivider = TIMER_B_CLOCKSOURCE_DIVIDER_1,
    .timerPeriod = 1023,
    .timerInterruptEnable_TBIE = TIMER_B_TBIE_INTERRUPT_DISABLE,
    .captureCompareInterruptEnable_CCR0_CCIE = TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE,
    .timerClear = TIMER_B_DO_CLEAR,
    .startTimer = false
};

static Timer_B_initCompareModeParam param0 = {
    .compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_3,
    .compareInterruptEnable = TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE,
    .compareOutputMode = TIMER_B_OUTPUTMODE_RESET_SET,
    .compareValue = 0
};

static Timer_B_initCompareModeParam param1 = {
    .compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_5,
    .compareInterruptEnable = TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE,
    .compareOutputMode = TIMER_B_OUTPUTMODE_RESET_SET,
    .compareValue = 0
};

void BSP_PWM_Init(void)
{
    //Timer_B_outputPWM(TIMER_B0_BASE, &param0);
    //Timer_B_outputPWM(TIMER_B0_BASE, &param1);

    /* clear the interrupt */
    //Timer_B_clearTimerInterrupt(TIMER_B0_BASE);
    Timer_B_initUpMode(TIMER_B0_BASE, &param);
    //Timer_B_startCounter(TIMER_B0_BASE, TIMER_B_UP_MODE);
    Timer_B_initCompareMode(TIMER_B0_BASE, &param0);
    Timer_B_initCompareMode(TIMER_B0_BASE, &param1);
    //Timer_B_outputPWM(TIMER_B0_BASE, &param0);
    //Timer_B_outputPWM(TIMER_B0_BASE, &param1);
    //Timer_B_startCounter(TIMER_B0_BASE, TIMER_B_UP_MODE);
}

void BPS_PWM_SetPWM(uint8_t chan, uint16_t pwm)
{
    if(pwm > 1024)
    {
        pwm = 1024;
    }

    //Timer_B_clearTimerInterrupt(TIMER_B0_BASE);

    if (pwm_running)
    {
        /* do nothing */
    }
    else
    {
        Timer_B_startCounter(TIMER_B0_BASE, TIMER_B_UP_MODE);
        pwm_running = true;
    }

    if(chan == 0)
    {
        //param0.dutyCycle = pwm;
        //Timer_B_outputPWM(TIMER_B0_BASE, &param0);
        param0.compareValue = pwm;
        Timer_B_initCompareMode(TIMER_B0_BASE, &param0);
    }
    else if(chan == 1)
    {
        //param1.dutyCycle = pwm;
        //Timer_B_outputPWM(TIMER_B0_BASE, &param1);
        param1.compareValue = pwm;
        Timer_B_initCompareMode(TIMER_B0_BASE, &param1);
    }

    //if(pwm > 1024) {
    //  pwm = 1024;
    //}
    //
    //if(chan == 0) {
    //  param0.dutyCycle = pwm;
    //  Timer_B_outputPWM(TIMER_B0_BASE, &param0);
    //}else if(chan == 1) {
    //  param1.dutyCycle = pwm;
    //  Timer_B_outputPWM(TIMER_B0_BASE, &param1);
    //}
    //__bis_SR_register(GIE);
}

void BPS_PWM_StopPWM(void)
{
    Timer_B_stop(TIMER_B0_BASE);
    Timer_B_clearTimerInterrupt(TIMER_B0_BASE);
    pwm_running = false;
}
