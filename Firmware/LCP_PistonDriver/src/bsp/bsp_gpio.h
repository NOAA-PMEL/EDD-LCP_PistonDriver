#ifndef TEST
#include <driverlib/driverlib.h>
#endif
#include "bsp_pins.h"

void BSP_GPIO_Init(const driverlib_gpio_cfg_t *p);
volatile int32_t * BSP_GPIO_Init_Counter( uint8_t counter);
void BSP_GPIO_Toggle(const driverlib_gpio_cfg_t *p);
void BSP_GPIO_Set(const driverlib_gpio_cfg_t *p);
void BSP_GPIO_Clear(const driverlib_gpio_cfg_t *p);
bool BSP_GPIO_Read(const driverlib_gpio_cfg_t *p);
void BSP_GPIO_SetInterrupt(const driverlib_gpio_cfg_t *p);
void BSP_GPIO_ClearInterrupt(const driverlib_gpio_cfg_t *p);
void BSP_GPIOCallback(uint16_t int_num, void function(void));