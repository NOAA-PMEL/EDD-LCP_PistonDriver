#include "msp430fr5989.h"
#include <system/System.h>
#include <bsp/bsp.h>
#include <stdio.h>
#include "logging.h"
#include "shell.h"
//#include "DRV8874.h"
#include "piston.h"
#include "encoder.h"
#include "memory.h"
#include "control.h"
#include "func_buf.h"

int main( void )
{
  // Initialize the system  
  BSP_Init();
  LOG_Init();
  MEM_Init();
  CTRL_Init();
  
  BSP_LED_Clear(LED_GREEN); 
  BSP_LED_Clear(LED_BLUE);
//  ENC_Init();
//  DRV8874_init();
  PIS_Init();
  __bis_SR_register(GIE);
//  MEM_Init();
//  uint8_t value[256];
//  memset(value, 0xA0, 256);
//  MEM_Write_RAM_Struct(MEM_RAM_2, 0x00, value, 256);
  FBUF_buffer_empty(&f_buf);
  FBUF_buffer_put(&f_buf, &BSP_LED_Flash_Both);
  FBUF_buffer_put(&f_buf, &BSP_LED_Flash_Both);

  
  FBUF_buffer_run(&f_buf);
  Log.Set(LOG_DEBUG);
  PIS_Reset_to_Zero();
  FBUF_buffer_run(&f_buf);
  //  Log.Set(LOG_NONE);
  
  sShellImpl shell_impl = {
    .send_char = BSP_CNSL_putc,
  };
  shell_boot(&shell_impl);
  
  char c;
  
  
  
  while(1){

      c = BSP_CNSL_getc();
      shell_receive_char(c);
      
    
  }

//  return 0;
}
