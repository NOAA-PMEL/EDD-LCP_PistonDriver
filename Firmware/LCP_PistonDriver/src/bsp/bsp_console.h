#include <driverlib/driverlib.h>
#include "bsp_pins.h"
#include <system/System.h>

#if INCLUDE_CONSOLE
void BSP_CNSL_UART_Init(void);
void BSP_CNSL_puts(char *str);

#endif