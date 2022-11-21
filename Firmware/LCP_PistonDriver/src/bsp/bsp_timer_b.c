#include "bsp_timer_b.h"


static Timer_B_initCaptureModeParam param = {
  .captureRegister = TIMER_B_CAPTURECOMPARE_REGISTER_0,
  .captureMode = TIMER_B_CAPTUREMODE_RISING_EDGE,
  .captureInputSelect = TIMER_B_CAPTURE_INPUTSELECT_CCIxA,
  .synchronizeCaptureSource = TIMER_B_CAPTURE_SYNCHRONOUS,
  .captureInterruptEnable = TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE,
  .captureOutputMode = 
  
};




void Timer_B_Init(void)
{
  Timer_B_initCaptureMode(