/** @file bsp_pins.c
 *  @brief Board Support Package pin definitions for LCP Piston Driver
 *
 *  @author Matt Casari, matthew.casari@noaa.gov
 *  @date December 16, 2020
 *  @version 1.0.0
 *
 *  @copyright National Oceanic and Atmospheric Administration
 *  @copyright Pacific Marine Environmental Lab
 *  @copyright Environmental Development Division
 *
 *  @note  Board Support Package pin definitions for
 *  MSP430FR5989 Devices and LCP Piston Driver Board.
 *  @note Interfaces with lower level drivers to 
 *
 *  @bug  No known bugs
 */

#include "bsp_pins.h"


#if DEBUG && DEBUG_LED
const driverlib_gpio_cfg_t g_BSP_GPIO_GREEN_LED = {
  .port = BSP_GPIO_GREEN_LED_PORT,
  .pin = BSP_GPIO_GREEN_LED_PIN,
  .mode = GPIO_SET_AS_OUTPUT,
  .function = GPIO_NORMAL_MODULE_FUNCTION,
  .inverted = true
};
#endif

#if DEBUG && DEBUG_LED
const driverlib_gpio_cfg_t g_BSP_GPIO_BLUE_LED = {
  .port = BSP_GPIO_BLUE_LED_PORT,
  .pin = BSP_GPIO_BLUE_LED_PIN,
  .mode = GPIO_SET_AS_OUTPUT,
  .function = GPIO_NORMAL_MODULE_FUNCTION,
  .inverted = true
};
#endif


const driverlib_gpio_cfg_t g_BSP_GPIO_12V_ENABLE = {
  .port = BSP_GPIO_12V_ENABLE_PORT,
  .pin = BSP_GPIO_12V_ENABLE_PIN,
  .mode = GPIO_SET_AS_OUTPUT
  
};


//const driverlib_gpio_cfg_t g_BSP_GPIO_MDM_RX =
//{
//    .port = BSP_GPIO_MDM_RX_PORT,
//    .pin = BSP_GPIO_MDM_RX_PIN,
//    .configured = false,
//    .function = GPIO_SECONDARY_MODULE_FUNCTION,
//    .pullups = 1
//};