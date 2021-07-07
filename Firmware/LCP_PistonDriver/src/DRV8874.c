#include "DRV8874.h"

float _read_adc12_volts(void) ;
uint16_t _calculate_pwm(uint8_t percent);


static uint16_t speed_fwd = 0;
static uint16_t speed_rev =0;

void DRV8874_init(void) {

 BSP_GPIO_Init(&g_BSP_GPIO_MD_SLEEP);
 
 BSP_GPIO_Init(&g_BSP_GPIO_MD_FAULT);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_PMODE);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_IPROPI);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_ENABLE);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_PH);
 
#ifdef DRV8874_NO_PWM
 BSP_GPIO_Clear(&g_BSP_GPIO_MD_PMODE);
 
#else 
 BSP_GPIO_Set(&g_BSP_GPIO_MD_PMODE);
#endif
 
 
 DRV8874_enable();
 // PWM Settings 
 // EN = TB0.3
 // PH = TB0.5
}



void DRV8874_enable( void ) {
  BSP_12V_On();
}


void DRV8874_disable( void ) {
  BSP_12V_Off();
}

void DRV8874_forward( uint8_t percent ){
  speed_rev = 0;
  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
#ifdef DRV8874_NO_PWM
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PH);
#else
  BPS_PWM_SetPWM(0,0);
  uint16_t target = _calculate_pwm(percent);
  int16_t inc = 0;
  
  if( target == speed_fwd)
  {
    return;
  }
  else if(target > speed_fwd)
  {
    inc = 1;
  }else {
    inc = -1;
  }
  
  do {
    BPS_PWM_SetPWM(1, speed_fwd);  
    __delay_cycles(1000);
    speed_fwd += inc;
  } while (target != speed_fwd);
  
  
//  // EN/IN1 is Low
//  BPS_PWM_SetPWM(0,0);
//  speed_rev = 0;
//  DRV8874_forward_change_speed(100);
//for(uint16_t i=0; i<1024; i++)
//  {
//    // PH/IN2 is PWMed
//    BPS_PWM_SetPWM(1, i);
//    __delay_cycles(1000);
//  }
#endif
//  speed_fwd = 1024;

}

//void DRV8874_forward_change_speed(uint8_t percent)
//{
//  BPS_PWM_SetPWM(0,0);
//  uint16_t target = _calculate_pwm(percent);
//  int16_t inc = 0;
//  
//  if( target == speed_fwd)
//  {
//    return;
//  }
//  else if(target > speed_fwd)
//  {
//    inc = 1;
//  }else {
//    inc = -1;
//  }
//  
//  do {
//    BPS_PWM_SetPWM(0, speed_fwd);  
//    __delay_cycles(1000);
//    speed_fwd += inc;
//  } while (target != speed_fwd);
//}

void DRV8874_reverse( uint8_t percent ) {

  speed_fwd = 0;
  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
#ifdef DRV8874_NO_PWM
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_PH);
#else
   BPS_PWM_SetPWM(1,0);
  uint16_t target = _calculate_pwm(percent);
  int16_t inc = 0;
 
  if( target == speed_rev)
  {
    return;
  }
  else if(target > speed_rev)
  {
    inc = 1;
  }else {
    inc = -1;
  }
  do {
    BPS_PWM_SetPWM(0, speed_rev);  
    __delay_cycles(1000);
    speed_rev += inc;
  } while (target != speed_rev);
//  // PH/IN2 is Low
//  BPS_PWM_SetPWM(1,0);
//  speed_fwd = 0;
//
//  BPS_PWM_SetPWM(0, 0);
//  DRV8874_reverse_change_speed(100);
//  for(uint16_t i=0; i<1024; i++)
//  {
////     EN/IN1 is PWMed
//    BPS_PWM_SetPWM(0, i);
//    __delay_cycles(1000);
//  }
#endif

//  speed_rev = 1024;
  

}

//void DRV8874_reverse_change_speed(uint8_t percent)
//{
//  BPS_PWM_SetPWM(1,0);
//  uint16_t target = _calculate_pwm(percent);
//  int16_t inc = 0;
// 
//  if( target == speed_fwd)
// {
//  return;
//}
//  else if(target > speed_fwd)
//  {
//    inc = 1;
//}else {
//  inc = -1;
//}
// do {
//    BPS_PWM_SetPWM(1, _calculate_pwm(percent));  
//  __delay_cycles(1000);
//  speed_fwd += inc;
//} while (target != speed_fwd);
//}


void DRV8874_stop( void ) {
#ifdef DRV8874_NO_PWM
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PH);
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_ENABLE);
#else
  BPS_PWM_SetPWM(0,0);
  BPS_PWM_SetPWM(1,0);
#endif  
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_SLEEP);
  
  speed_fwd = 0;
  speed_rev = 0;
}

float DRV8847_read_current( void )
{
//  float a_ipropi = 444e-6;      /** @todo This needs to be somewhere else */
//  
//  /** Read voltage */
//  float v_ipropi = _read_adc12_volts();
//  v_ipropi *= a_ipropi;
//  float i_propi = v_ipropi / 750.0f;
//  
//  float i = i_propi * 2197.8f;
//  
//  /** Convert to amps */
//  return i / 2;
  float v_ipropi = 0.0f;
  float i_propi = 0.0f;
  
  for(uint8_t i=0; i<10; i++)
  {
    v_ipropi += _read_adc12_volts();
  }
  v_ipropi = v_ipropi / 10.0f;
  i_propi = v_ipropi / 750.0f;
  i_propi = i_propi / 444e-6;
  
  
//  float v_ipropi = _read_adc12_volts();
//  float i_propi = v_ipropi / 750.0f;
  return i_propi;
}


float _read_adc12_volts(void) { 
// float temp_f = (float) (BSP_ADC12_Read() / 4096); 
// return temp_f * 2.0f;
  return BSP_ADC12_Read_voltage();
}

uint16_t _calculate_pwm(uint8_t percent)
{
  uint16_t pwm;
  if(percent >= 100)
  {
    pwm = 1024;
  } else if (percent >= 75)
  {
    pwm = 768;
  } else if (percent >= 50)
  {
    pwm = 512;
  } else if (percent >= 25)
  {
    pwm = 256;
  } else
  {
    pwm = 0;
  }
  
  return pwm;
}