#include "msp430fr5989.h"
#include <system/System.h>
#include <bsp/bsp.h>


int main( void )
{
  // Initialize the system  
  BSP_Init();
  
  BSP_LED_Set(LED_GREEN); 
  
  BSP_12V_Off();
  
  while(1){
    BSP_LED_Toggle(LED_BLUE);
    
    __delay_cycles(1000000);
    BSP_DBG_puts("DEBUG UART");
    BSP_CNSL_puts("CONSOLE UART");

  }

  return 0;
}
