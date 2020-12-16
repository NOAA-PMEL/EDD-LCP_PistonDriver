#include <driverlib/driverlib.h>
#include "bsp_pins.h"
#include <system/System.h>
#include <stdint.h>
#include <assert.h>


void BSP_UART_Init(uint16_t baseAddr);
void BSP_UART_puts(uint16_t baseAddr, const char *str);