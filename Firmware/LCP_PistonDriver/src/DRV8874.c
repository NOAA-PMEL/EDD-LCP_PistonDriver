#include "DRV8874.h"
#include "logging.h"
#include <stdio.h>

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



void DRV8874_enable( void ) 
{
  Log.Debug("Enabling DRV8874");
  BSP_12V_On();
}


void DRV8874_disable( void ) 
{
  Log.Debug("Disabling DRV8874");
  BSP_12V_Off();
}

void DRV8874_forward( uint8_t percent )
{
  Log.Debug("DRV8874_forward entered");
  char temp[80];
  speed_rev = 0;
  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
  __delay_cycles(16000);
  Log.Debug("DRV8874_forward After sleep 1ms cycles");

#ifdef DRV8874_NO_PWM
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PH);
#else
  BPS_PWM_SetPWM(0,0);
  uint16_t target = _calculate_pwm(percent);
  int16_t inc = 0;
  
  if( target == speed_fwd)
  {
    Log.Debug("Already at target speed");
    return;
  }
  else if(target > speed_fwd)
  {
    inc = 1;
  }else {
    inc = -1;
  }
  
  sprintf(temp, "Setting DRV8874 FORWARD at %u%%, pwm = %u", percent, target);
  Log.Debug(temp);
  do {
    BPS_PWM_SetPWM(1, speed_fwd);  
    __delay_cycles(1000);
    speed_fwd += inc;
  } while (target != speed_fwd);
  
  
#endif

}



void DRV8874_reverse( uint8_t percent ) 
 {
  Log.Debug("DRV8874_reverse entered");
  char temp[80];
  speed_fwd = 0;
  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
  __delay_cycles(16000);
  Log.Debug("DRV8874_reverse After sleep 1ms");
#ifdef DRV8874_NO_PWM
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_PH);
#else
   BPS_PWM_SetPWM(1,0);
  uint16_t target = _calculate_pwm(percent);
  int16_t inc = 0;
 
  if( target == speed_rev)
  {
    Log.Debug("Already at target speed");
    return;
  }
  else if(target > speed_rev)
  {
    inc = 1;
  }else {
    inc = -1;
  }
 sprintf(temp, "Setting DRV8874 FORWARD at %u%%, pwm = %u", percent, target);
 Log.Debug(temp);
  do {
    BPS_PWM_SetPWM(0, speed_rev);  
    __delay_cycles(1000);
    speed_rev += inc;
  } while (target != speed_rev);

#endif 

}




void DRV8874_stop( void ) {
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_SLEEP);
  __delay_cycles(16000);
  Log.Debug("DRV8874_stop After sleep 1ms cycles");

#ifdef DRV8874_NO_PWM
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PH);
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_ENABLE);
#else
  BPS_PWM_SetPWM(0,0);
  BPS_PWM_SetPWM(1,0);
#endif  
  
  speed_fwd = 0;
  speed_rev = 0;
  Log.Debug("DRV8874 Stopped");
}

float DRV8874_read_current( void )
{

//  /** Convert to amps */
  float v_ipropi = 0.0f;
  float i_propi = 0.0f;
  
  for(uint8_t i=0; i<25; i++)
  {
    v_ipropi += _read_adc12_volts();
  }
  v_ipropi = v_ipropi / 10.0f;
  i_propi = v_ipropi / 750.0f;
  i_propi = i_propi / 444e-6;
  
  return i_propi;
}


float _read_adc12_volts(void) { 

  return BSP_ADC12_Read_voltage();
}

uint16_t _calculate_pwm(uint8_t percent)
{
  float pwm;
//  if(percent >= 100)
//  {
//    pwm = 1024;
//  } else if (percent >= 75)
//  {
//    pwm = 768;
//  } else if (percent >= 50)
//  {
//    pwm = 512;
//  } else if (percent >= 25)
//  {
//    pwm = 256;
//  } else
//  {
//    pwm = 0;
//  }
  pwm = ((float)percent * 1024)/100;
  
  return (uint16_t)pwm;
}
