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
  .function = DEFAULT_MODULE_FUNCTION,
  .inverted = true
};
#endif

#if DEBUG && DEBUG_LED
const driverlib_gpio_cfg_t g_BSP_GPIO_BLUE_LED = {
  .port = BSP_GPIO_BLUE_LED_PORT,
  .pin = BSP_GPIO_BLUE_LED_PIN,
  .mode = GPIO_SET_AS_OUTPUT,
  .function = DEFAULT_MODULE_FUNCTION,
  .inverted = true
};
#endif


const driverlib_gpio_cfg_t g_BSP_GPIO_12V_ENABLE = {
  .port = BSP_GPIO_12V_ENABLE_PORT,
  .pin = BSP_GPIO_12V_ENABLE_PIN,
  .mode = GPIO_SET_AS_OUTPUT
  
};

/***********************************************
 * Debug UART Pins
 **********************************************/
const driverlib_gpio_cfg_t BSP_UART_DEBUG_RX = {
  .port = BSP_UART_DEBUG_RX_PORT,
  .pin = BSP_UART_DEBUG_RX_PIN,
  .function = PRIMARY_MODULE_FUNCTION
};

const driverlib_gpio_cfg_t BSP_UART_DEBUG_TX = {
  .port = BSP_UART_DEBUG_TX_PORT,
  .pin = BSP_UART_DEBUG_TX_PIN,
  .function = PRIMARY_MODULE_FUNCTION
};

/***********************************************
 * Console UART Pins
 **********************************************/
const driverlib_gpio_cfg_t BSP_UART_CONSOLE_RX = {
  .port = BSP_UART_CONSOLE_RX_PORT,
  .pin = BSP_UART_CONSOLE_RX_PIN,
  .function = PRIMARY_MODULE_FUNCTION
};

const driverlib_gpio_cfg_t BSP_UART_CONSOLE_TX = {
  .port = BSP_UART_CONSOLE_TX_PORT,
  .pin = BSP_UART_CONSOLE_TX_PIN,
  .function = PRIMARY_MODULE_FUNCTION
};

/***********************************************
 * Battery Management Pins
 **********************************************/
const driverlib_gpio_cfg_t g_BSP_GPIO_BM_IRQ = {
  .port = BSP_GPIO_BM_IRQ_PORT,
  .pin = BSP_GPIO_BM_IRQ_PIN,
  .mode = GPIO_SET_AS_INPUT,
  .function = DEFAULT_MODULE_FUNCTION,
  .inverted = false,
  .pullups = 2,
  .interrupt = true,
  .interruptEdge = 0
};

const driverlib_gpio_cfg_t g_BSP_I2C_BM_SDA = {
  .port = BSP_I2C_BM_SDA_PORT,
  .pin = BSP_I2C_BM_SDA_PIN,
  .function = PRIMARY_MODULE_FUNCTION
};

const driverlib_gpio_cfg_t g_BSP_I2C_BM_SCL = {
  .port = BSP_I2C_BM_SCL_PORT,
  .pin = BSP_I2C_BM_SCL_PIN,
  .function = PRIMARY_MODULE_FUNCTION
};

  


/***********************************************
 * Control Communications Pins
 **********************************************/
const driverlib_gpio_cfg_t g_BSP_GPIO_CONTROL_IRQ = {
  .port = BSP_GPIO_CONTROL_IRQ_PORT,
  .pin = BSP_GPIO_CONTROL_IRQ_PIN,
  .mode = GPIO_SET_AS_INPUT,
  .function = DEFAULT_MODULE_FUNCTION,
  .inverted = false,
  .pullups = 2,
  .interrupt = true,
  .interruptEdge = 0
};

const driverlib_gpio_cfg_t g_BSP_I2C_CONTROL_SDA = {
  .port = BSP_I2C_CONTROL_SDA_PORT,
  .pin = BSP_I2C_CONTROL_SDA_PIN,
  .function = PRIMARY_MODULE_FUNCTION
};

const driverlib_gpio_cfg_t g_BSP_I2C_CONTROL_SCL = {
  .port = BSP_I2C_CONTROL_SCL_PORT,
  .pin = BSP_I2C_CONTROL_SCL_PIN,
  .function = PRIMARY_MODULE_FUNCTION
};


/***********************************************
 * H-Bridge (Motor Driver) Pins
 **********************************************/
#ifdef DRV8874_NO_PWM
const driverlib_gpio_cfg_t g_BSP_GPIO_MD_ENABLE = {
  .port = BSP_GPIO_MD_ENABLE_PORT,
  .pin = BSP_GPIO_MD_ENABLE_PIN,
  .mode = GPIO_SET_AS_OUTPUT,
  .function = DEFAULT_MODULE_FUNCTION
};
#else
const driverlib_gpio_cfg_t g_BSP_GPIO_MD_ENABLE = {
  .port = BSP_GPIO_MD_ENABLE_PORT,
  .pin = BSP_GPIO_MD_ENABLE_PIN,
  .mode = GPIO_SET_AS_OUTPUT,
  .function = PRIMARY_MODULE_FUNCTION
};
#endif

#ifdef DRV8874_NO_PWM
const driverlib_gpio_cfg_t g_BSP_GPIO_MD_PH = {
  .port = BSP_GPIO_MD_PH_PORT,
  .pin = BSP_GPIO_MD_PH_PIN,
  .mode = GPIO_SET_AS_OUTPUT
};
#else
const driverlib_gpio_cfg_t g_BSP_GPIO_MD_PH = {
  .port = BSP_GPIO_MD_PH_PORT,
  .pin = BSP_GPIO_MD_PH_PIN,
  .mode = GPIO_SET_AS_OUTPUT,
  .function = PRIMARY_MODULE_FUNCTION
};
#endif

const driverlib_gpio_cfg_t g_BSP_GPIO_MD_SLEEP = {
  .port = BSP_GPIO_MD_SLEEP_PORT,
  .pin = BSP_GPIO_MD_SLEEP_PIN,
  .mode = GPIO_SET_AS_OUTPUT
};

const driverlib_gpio_cfg_t g_BSP_GPIO_MD_FAULT = {
  .port = BSP_GPIO_MD_FAULT_PORT,
  .pin = BSP_GPIO_MD_FAULT_PIN,
  .mode = GPIO_SET_AS_INPUT
};

const driverlib_gpio_cfg_t g_BSP_GPIO_MD_PMODE = {
  .port = BSP_GPIO_MD_PMODE_PORT,
  .pin = BSP_GPIO_MD_PMODE_PIN,
  .mode = GPIO_SET_AS_OUTPUT
};

const driverlib_gpio_cfg_t g_BSP_GPIO_MD_IPROPI = {
  .port = BSP_GPIO_MD_IPROPI_PORT,
  .pin = BSP_GPIO_MD_IPROPI_PIN,
  .function = TERNARY_MODULE_FUNCTION,
};
/***********************************************
 * Encoder Pins
 **********************************************/
const driverlib_gpio_cfg_t g_BSP_GPIO_ENCODER_A = {
  .port = BSP_GPIO_ENCODER_A_PORT,
  .pin = BSP_GPIO_ENCODER_A_PIN,
  .mode = GPIO_SET_AS_INPUT,
  .function = PRIMARY_MODULE_FUNCTION
};

const driverlib_gpio_cfg_t g_BSP_GPIO_ENCODER_B = {
  .port = BSP_GPIO_ENCODER_B_PORT,
  .pin = BSP_GPIO_ENCODER_B_PIN,
  .mode = GPIO_SET_AS_INPUT,
  .function = PRIMARY_MODULE_FUNCTION
};