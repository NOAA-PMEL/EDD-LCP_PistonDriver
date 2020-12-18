#include "msp430fr5989.h"
#include <system/System.h>
#include <bsp/bsp.h>


int main( void )
{
  // Initialize the system  
  BSP_Init();
  __bis_SR_register(GIE);
  
  BSP_LED_Set(LED_GREEN); 
  
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PMODE);
  BSP_12V_On();
  
  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_PH);
//  __bis_SR_register(LPM0_bits);
  uint16_t i = 0;
  while(1){
    BSP_LED_Toggle(LED_BLUE);
    
     __delay_cycles(10000);
    BSP_DBG_puts("DEBUG UART");
    BSP_CNSL_puts("CONSOLE UART");
//    BPS_PWM_SetPWM(i++);
    if(++i>100){
      i=0;
      BSP_GPIO_Toggle(&g_BSP_GPIO_MD_PH);
//      BSP_GPIO_Toggle(&g_BSP_GPIO_MD_ENABLE);
    }

  }

  return 0;
}
