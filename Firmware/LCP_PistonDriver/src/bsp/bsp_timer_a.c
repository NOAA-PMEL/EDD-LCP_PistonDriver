#include "bsp_timer_a.h"
#include "bsp_led.h"

void TIMER1_A0_ISR (void);
void TIMER1_A1_ISR (void);

#define COMPARE_VALUE ( 400 )
//
static Timer_A_initCaptureModeParam param = {
  .captureRegister = TIMER_A_CAPTURECOMPARE_REGISTER_0,
  .captureMode = TIMER_A_CAPTUREMODE_RISING_EDGE,
  .captureInputSelect = TIMER_A_CAPTURE_INPUTSELECT_Vcc,
  .synchronizeCaptureSource = TIMER_A_CAPTURE_SYNCHRONOUS,
  .captureInterruptEnable = TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE,
  .captureOutputMode = TIMER_A_OUTPUTMODE_OUTBITVALUE  
};

//static Timer_A_initCompareModeParam initCompParam = {
//  .compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_0,
//  .compareInterruptEnable = TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE,
//  .compareOutputMode = TIMER_A_OUTPUTMODE_OUTBITVALUE,
//  .compareValue = COMPARE_VALUE,
//  
//};

//Start timer in continuous mode sourced by SMCLK
Timer_A_initContinuousModeParam initContParam = {
    .clockSource = TIMER_A_CLOCKSOURCE_EXTERNAL_TXCLK,
    .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
    .timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_ENABLE,
    .timerClear = TIMER_A_SKIP_CLEAR,
    .startTimer = false,
    
};

Timer_A_initUpModeParam initUpParam = {
  .clockSource = TIMER_A_CLOCKSOURCE_EXTERNAL_TXCLK,
  .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
  .timerPeriod = COMPARE_VALUE,
  .timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_ENABLE,
  .captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,
  .timerClear = TIMER_A_SKIP_CLEAR  
};

void Timer_A_Init(void)
{
  
//  Timer_A_initContinuousMode(TIMER_A1_BASE, &initContParam);
  Timer_A_initUpMode(TIMER_A1_BASE, &initUpParam);
 

//  Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE,
//		TIMER_A_CAPTURECOMPARE_REGISTER_0
//		);
  Timer_A_initCaptureMode(TIMER_A1_BASE, &param);
//        
//  Timer_A_initCompareMode(TIMER_A1_BASE, &initCompParam);
  
  Timer_A_startCounter( TIMER_A1_BASE,
    		TIMER_A_UP_MODE
                );
}

void Timer_A_Start(void) {
  
  Timer_A_startCounter( TIMER_A1_BASE,
    		TIMER_A_CONTINUOUS_MODE
                );
  //__bis_SR_register(GIE);
}

//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
//#pragma vector=TIMER1_A0_VECTOR
//__interrupt
//#elif defined(__GNUC__)
//__attribute__((interrupt(TIMER1_A0_VECTOR)))
//#endif
//void TIMER1_A0_ISR (void)
//{
////  uint16_t compVal = Timer_A_getCaptureCompareCount(TIMER_A1_BASE,
////    		TIMER_A_CAPTURECOMPARE_REGISTER_0)
////    		+ COMPARE_VALUE;
////  BSP_LED_Toggle(LED_BLUE);
////  Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE,
////		TIMER_A_CAPTURECOMPARE_REGISTER_0
////		);
////  
////  Timer_A_setCompareValue(TIMER_A1_BASE,
////        TIMER_A_CAPTURECOMPARE_REGISTER_0,
////        compVal
////        );
//  
//}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER1_A0_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(TIMER1_A0_VECTOR)))
#endif
void TIMER1_A0_ISR(void)
{
    /* USER CODE START (section: TIMER1_A1_ISR_HOOK) */
    BSP_LED_Toggle(LED_BLUE);
    /* USER CODE END (section: TIMER1_A1_ISR_HOOK) */
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER1_A1_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(TIMER1_A1_VECTOR)))
#endif
void TIMER1_A1_ISR(void)
{
    /* USER CODE START (section: TIMER1_A1_ISR_HOOK) */
    BSP_LED_Toggle(LED_BLUE);
    /* USER CODE END (section: TIMER1_A1_ISR_HOOK) */
}

