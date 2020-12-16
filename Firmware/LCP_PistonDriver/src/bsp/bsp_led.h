#include <driverlib/driverlib.h>
#include "bsp_pins.h"
#include "bsp_gpio.h"

#if DEBUG && DEBUG_LED
typedef enum {
  LED_BLUE,
  LED_GREEN
}eLED_t;
#endif

#if DEBUG && DEBUG_LED
void BSP_LED_Init(eLED_t led) ;

void BSP_LED_Toggle(eLED_t led);

void BSP_LED_Set(eLED_t led);

void BSP_LED_Clear(eLED_t led);

#endif