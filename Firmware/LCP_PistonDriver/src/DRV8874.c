#include "DRV8874.h"

float _read_adc12_volts(void) ;

void DRV8874_init(void) {

 BSP_GPIO_Init(&g_BSP_GPIO_MD_SLEEP);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_ENABLE);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_PH);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_FAULT);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_PMODE);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_IPROPI);
 
 BSP_GPIO_Clear(&g_BSP_GPIO_MD_PMODE);
 
}



void DRV8874_enable( void ) {

  BSP_12V_On();
//  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
}


void DRV8874_forward( void ){
  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_PH);
}

void DRV8874_reverse( void ) {
  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PH);
}

void DRV8874_stop( void ) {
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_SLEEP);
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PH);
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_ENABLE);
}

float DRV8847_read_current( void )
{
  float a_ipropi = 444e-6;      /** @todo This needs to be somewhere else */
  
  /** Read voltage */
  float v_ipropi = _read_adc12_volts();
  v_ipropi *= a_ipropi;
  float i_propi = v_ipropi / 750.0f;
  
  float i = i_propi * 2197.8f;
  
  /** Convert to amps */
  return i / 2;
}


float _read_adc12_volts(void) { 
 float temp_f = (float) (BSP_ADC12_Read() / 4096); 
 return temp_f * 2.0f;
}