#include "bsp_uart.h"
void BSP_UART_Init(uint16_t baseAddr)
{
  assert( (baseAddr == EUSCI_A0_BASE) || (baseAddr == EUSCI_A1_BASE) );
  
  if(baseAddr == EUSCI_A0_BASE) 
  {
    EUSCI_A0_Init();
  } else {
    EUSCI_A1_Init();
  }
}

void BSP_UART_puts(uint16_t baseAddr, const char *str)
{
  
  assert( (baseAddr == EUSCI_A0_BASE) || (baseAddr == EUSCI_A1_BASE) );
  do{
    EUSCI_A_UART_transmitData(baseAddr, *str++);  
  }while(*str != 0);
  
  EUSCI_A_UART_transmitData(baseAddr,'\n');
}