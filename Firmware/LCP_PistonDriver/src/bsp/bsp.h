#include <driverlib/driverlib.h>
#include "bsp_pins.h"
#include "bsp_gpio.h"
#include "bsp_led.h"
#include "bsp_uart.h"

/** !brief Initialize System
 * 
 * Initialize all Pins & Submodules
 * 
 */
void BSP_Init(void);

#if DEBUG && DEBUG_UART

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
#endif 

#if INCLUDE_CONSOLE

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
void BSP_CNSL_puts(char *str);
#endif

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