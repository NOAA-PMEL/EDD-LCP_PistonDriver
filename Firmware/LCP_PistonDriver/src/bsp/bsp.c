#include "bsp.h"


void BSP_Init(void)
{
#if DEBUG && DEBUG_LED
  BSP_LED_Init(LED_BLUE);
  BSP_LED_Init(LED_GREEN);
#endif
  
  BSP_GPIO_Init(&g_BSP_GPIO_12V_ENABLE);
  
  SYS_init();
  
  PMM_unlockLPM5();
}

#if DEBUG && DEBUG_UART
void BSP_DBG_UART_Init(void)
{
  BSP_UART_Init(EUSCI_A1_BASE);
}

void BSP_DBG_puts(char *str)
{
 BSP_UART_puts(EUSCI_A1_BASE, str); 
}
#endif 

#if INCLUDE_CONSOLE
void BSP_CNSL_UART_Init(void)
{
  BSP_UART_Init(EUSCI_A0_BASE);
}

void BSP_CNSL_puts(char *str)
{
 BSP_UART_puts(EUSCI_A0_BASE, str); 
}
#endif 



void BSP_12V_On(void)
{
  BSP_GPIO_Set(&g_BSP_GPIO_12V_ENABLE);  
}

void BSP_12V_Off(void)
{
  BSP_GPIO_Clear(&g_BSP_GPIO_12V_ENABLE);  
}
