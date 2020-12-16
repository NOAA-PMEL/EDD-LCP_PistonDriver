#include "bsp_debug.h"

#if DEBUG && DEBUG_UART



void BSP_DBG_UART_Init(void)
{
  EUSCI_A1_Init();
}

void BSP_DBG_puts(const char *str){
        do{
            EUSCI_A_UART_transmitData(EUSCI_A1_BASE, *str++);  
        }while(*str != 0);

    EUSCI_A_UART_transmitData(EUSCI_A1_BASE,'\n');
}
#endif