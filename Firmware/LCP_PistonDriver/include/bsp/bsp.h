#ifndef TEST
#include "driverlib.h"
#endif

#include "config.h"
#include "bsp_pins.h"
#include "bsp_gpio.h"
#include "bsp_led.h"
#include "bsp_uart.h"
#include "bsp_pwm.h"
#include "bsp_adc12.h"
#include "bsp_dma.h"
#include "bsp_esi.h"
#include "bsp_i2c.h"
#include "System.h"


/** !brief Initialize System
 * 
 * Initialize all Pins & Submodules
 * 
 */
void BSP_Init(void);

#if defined(DEBUG) && defined(DEBUG_UART)

/** !brief Init Debug UART
 * 
 * Initialize UART A1
 *
 */
void BSP_DBG_UART_Init(void);

/** !brief Debug Send String
 * 
 * Send string over Debug Port
 * 
 */
void BSP_DBG_puts(char *str);
void BSP_DBG_putc(char c);
#endif 

//#if INCLUDE_CONSOLE

/** !brief Init Console Port
 * 
 * Initialize A0
 * 
 */
void BSP_CNSL_UART_Init(void);

/** !brief Console Send String
 * 
 * Send string over console
 * 
 */
int BSP_CNSL_puts(const char *str);
int BSP_CNSL_putc(char c);

char BSP_CNSL_getc(void);

//#endif

/** !brief 12V Power ON
 * 
 * Enable 12V Subsystems
 * 
 */
void BSP_12V_On(void);

/** !brief 12V Power OFF
 * 
 * Disable 12V Subsystems
 * 
 */
void BSP_12V_Off(void);

/** !brief 12V Power Status
 *
 * get status On or OFF
 *
 */
bool BSP_12V_Status(void);

void _delay_ms(uint32_t seconds);

void BSP_MD_ADC_Init(void);

float BSP_MD_Read_ADC(void);
