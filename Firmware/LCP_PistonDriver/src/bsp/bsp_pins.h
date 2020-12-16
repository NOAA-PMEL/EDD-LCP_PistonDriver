#ifndef _BSP_PINS_H_
#define _BSP_PINS_H_

#include <stdbool.h>
#include <driverlib/driverlib.h>

typedef struct {
    uint8_t port;
    uint16_t pin;
    bool mode;        /*<< Pin Mode 1=Output, 0=Input */
    bool configured;  /**< Is the port configured 0=NO, 1=YES */
    uint8_t function;   /**< 0=Normal, 1=Primary, 2=Secondary, 3=Ternary */
    bool inverted;       /**< Invert the output */

    /** Input Options */
    uint8_t pullups;     /**< Needs resistors 0=No, 1=Pull-ups, 2=Pull-Downs */
    bool interrupt;      /**< Is there an interrupt attached? 0=No, 1=Yes */
    bool interruptEdge;  /**< Interrupt Edge 0=Low To High, 1=High to Low */

    /** Input Value */
    volatile bool inputValue;  /**< Value of Input */
}driverlib_gpio_cfg_t;

#define GPIO_NORMAL_MODULE_FUNCTION ( 0 )

#define GPIO_SET_AS_INPUT   ( 0 )
#define GPIO_SET_AS_OUTPUT  ( 1 )




/***********************************************
 * LED0 pin: Green LED
 **********************************************/
#if DEBUG && DEBUG_LED
#define BSP_GPIO_GREEN_LED_PORT     ( GPIO_PORT_P3 )
#define BSP_GPIO_GREEN_LED_PIN      ( GPIO_PIN6 )  
extern const driverlib_gpio_cfg_t g_BSP_GPIO_GREEN_LED;
#endif

/***********************************************
 * LED1 pin: RED LED
 **********************************************/
#if DEBUG && DEBUG_LED
#define BSP_GPIO_BLUE_LED_PORT     ( GPIO_PORT_P3 )
#define BSP_GPIO_BLUE_LED_PIN      ( GPIO_PIN7 )  
extern const driverlib_gpio_cfg_t g_BSP_GPIO_BLUE_LED;
#endif

/***********************************************
 * 12V Enable Pin
 **********************************************/
#define BSP_GPIO_12V_ENABLE_PORT        ( GPIO_PORT_P2 )
#define BSP_GPIO_12V_ENABLE_PIN         ( GPIO_PIN5 )
extern const driverlib_gpio_cfg_t g_BSP_GPIO_12V_ENABLE;

#endif