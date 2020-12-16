#include <driverlib/driverlib.h>
#include "bsp_pins.h"
#include <system/System.h>

#if DEBUG && DEBUG_UART
void BSP_DBG_UART_Init(void);
void BSP_DBG_puts(const char *str);

#endif