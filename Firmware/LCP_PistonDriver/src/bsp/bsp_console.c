#include "bsp_console.h"

#if INCLUDE_CONSOLE

void BSP_CNSL_UART_Init(void)
{
  EUSCI_A1_Init();
}

void BSP_CNSL_puts(char *str){
  do{
    EUSCI_A_UART_transmitData(EUSCI_A0_BASE, *str++);  
  }while(*str != 0);
  EUSCI_A_UART_transmitData(EUSCI_A0_BASE,'\n');
}


#endif