#include <driverlib/driverlib.h>
#include "bsp_pins.h"
#include "bsp_gpio.h"
#include "bsp_led.h"
#include "bsp_uart.h"

void BSP_Init(void);

#if DEBUG && DEBUG_UART
void BSP_DBG_UART_Init(void);
void BSP_DBG_puts(char *str);
#endif 

#if INCLUDE_CONSOLE
void BSP_CNSL_UART_Init(void);
void BSP_CNSL_puts(char *str);
#endif


void BSP_12V_On(void);
void BSP_12V_Off(void);