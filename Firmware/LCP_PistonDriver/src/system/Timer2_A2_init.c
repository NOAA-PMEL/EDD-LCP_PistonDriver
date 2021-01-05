/*
 *  This file is automatically generated and does not require a license
 *
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 */
#include <driverlib/inc/hw_memmap.h>
#include <driverlib/timer_a.h>
#include <system/System.h>

/* USER CODE START (section: Timer2_A2_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: Timer2_A2_init_c_prologue) */

/*
 *  ======== Timer2_A2_Init ========
 *  Initialize Config for the MSP430 A2 Timer 2
 */
void Timer2_A2_Init(void)
{
    /* USER CODE START (section: Timer2_A2_Init_prologue) */
    /* User initialization code */
    /* USER CODE END (section: Timer2_A2_Init_prologue) */
    Timer_A_initUpModeParam param = {
      .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
      .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
      .timerPeriod = 1999,
      .timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_ENABLE,
      .captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,
      .timerClear = TIMER_A_SKIP_CLEAR
    };
    
    /* Configure TimerA in up mode */
    Timer_A_initUpMode(TIMER_A2_BASE, &param);

    /* Start TimerA counter */
    Timer_A_startCounter(TIMER_A2_BASE, TIMER_A_UP_MODE);

    /* USER CODE START (section: Timer2_A2_Init_epilogue) */
    /* User code */
    /* USER CODE END (section: Timer2_A2_Init_epilogue) */
}