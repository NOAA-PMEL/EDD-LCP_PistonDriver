#ifndef TEST
#include "driverlib.h"
#endif
#include "bsp_pins.h"
#include <system/System.h>
#include <stdint.h>
#include <assert.h>
#include "buffer_c.h"

void BSP_UART_Init(uint16_t baseAddr);
int BSP_UART_puts(uint16_t baseAddr, const char *str);
int BSP_UART_putc(uint16_t baseAddr, const char c);
void BSP_UART_getc(uint16_t baseAddr, char *str);
