#include "msp430fr5989.h"
#include <system/System.h>
#include <bsp/bsp.h>
#include <stdio.h>

int main( void )
{
  // Initialize the system  
  BSP_Init();
  __bis_SR_register(GIE);
  
  BSP_LED_Set(LED_GREEN); 
  
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PMODE);
  BSP_12V_On();
  
//  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
//  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
//  BSP_GPIO_Set(&g_BSP_GPIO_MD_PH);
//  __bis_SR_register(LPM0_bits);
  uint16_t i = 0;
  float temp = 0.0f;
  char voltage[24];
  BSP_CNSL_puts("CONSOLE UART");
  BSP_DBG_puts("DEBUG UART");
  while(1){
    BSP_LED_Toggle(LED_BLUE);
    
     __delay_cycles(10000);
   
    if(++i>1000){
      i=0;
      BSP_GPIO_Toggle(&g_BSP_GPIO_MD_PH);

      char c;
      do {
        BSP_CNSL_getc(&c);
        if(c != '\0')
        {
          BSP_CNSL_putc(c);
        }
//        BSP_DBG_putc(c);
      }while(c != '\0');
    }
    
    temp = BSP_ADC12_Read();
    
    temp /= 4096;
    temp *= 2.0;
    
//    sprintf(voltage, "%0.4f\r", temp);
//    BSP_CNSL_puts(voltage);
    
  }

  return 0;
}
