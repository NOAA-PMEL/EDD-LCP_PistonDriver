#include "msp430fr5989.h"
#include <system/System.h>
#include <bsp/bsp.h>
#include <stdio.h>
#include "logging.h"
#include "shell.h"
#include "piston.h"
#include "encoder.h"
#include "memory.h"
#include "control.h"

int main( void )
{
  // Initialize the system  
  BSP_Init();
  LOG_Init();
  MEM_Init();
  CTRL_Init();
  
  BSP_LED_Clear(LED_GREEN); 
  BSP_LED_Clear(LED_BLUE);

  PIS_Init();
  __bis_SR_register(GIE);

  Log.Set(LOG_DEBUG);
  PIS_Reset_to_Zero();
  //  Log.Set(LOG_NONE);
  
  sShellImpl shell_impl = {
    .send_char = BSP_CNSL_putc,
  };
  shell_boot(&shell_impl);
  
  char c;
  
  
  
  while(1){
      
      CTRL_Check_Write();
      c = BSP_CNSL_getc();
      shell_receive_char(c);
      
    
  }

//  return 0;
}
