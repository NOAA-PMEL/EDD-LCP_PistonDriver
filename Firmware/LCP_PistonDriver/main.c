#include "msp430fr5989.h"
#include <system/System.h>
#include <bsp/bsp.h>
#include <stdio.h>
#include "shell.h"
#include "DRV8874.h"
int main( void )
{
  // Initialize the system  
  BSP_Init();
  __bis_SR_register(GIE);
  
  BSP_LED_Set(LED_GREEN); 
  
  DRV8874_init();
  
  DRV8874_enable();
  
//  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PMODE);
//  BSP_12V_On();
  
//  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
//  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
//  BSP_GPIO_Set(&g_BSP_GPIO_MD_PH);
//  __bis_SR_register(LPM0_bits);
  uint16_t i = 0;
  float temp = 0.0f;
  char voltage[24];
//  BSP_CNSL_puts("CONSOLE UART");
  BSP_DBG_puts("DEBUG UART");
  
  sShellImpl shell_impl = {
    .send_char = BSP_CNSL_putc,
  };
  shell_boot(&shell_impl);
  
  char c;
//  DRV8874_forward();
  
  while(1){

      c = BSP_CNSL_getc();
//      BSP_CNSL_putc(c);
      shell_receive_char(c);
      
    
  }

  return 0;
}
