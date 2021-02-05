#include "msp430fr5989.h"
#include <system/System.h>
#include <bsp/bsp.h>
#include <stdio.h>
#include "shell.h"
#include "DRV8874.h"
#include "memory.h"
int main( void )
{
  // Initialize the system  
  BSP_Init();
  __bis_SR_register(GIE);
  
  BSP_LED_Set(LED_GREEN); 
  
  DRV8874_init();
  
  DRV8874_enable();
  
//  MEM_Init();
//  uint8_t value[256];
//  memset(value, 0xA0, 256);
//  MEM_Write_RAM_Struct(MEM_RAM_2, 0x00, value, 256);
  
  uint16_t i = 0;
  float temp = 0.0f;
  char voltage[24];

  BSP_DBG_puts("DEBUG UART");
  
  sShellImpl shell_impl = {
    .send_char = BSP_CNSL_putc,
  };
  shell_boot(&shell_impl);
  
  char c;
  
  while(1){

      c = BSP_CNSL_getc();
      shell_receive_char(c);
      
    
  }

  return 0;
}
