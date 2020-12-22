#ifndef _BSP_PINS_H_
#define _BSP_PINS_H_

#include <stdbool.h>
#ifndef TEST
#include <driverlib/driverlib.h>
#endif
#include "config.h"
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
 * LED Pins
 **********************************************/
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
 * Debug UART Pins
 **********************************************/
/***********************************************
 * Debug UART Rx Pin
 **********************************************/
#define BSP_UART_DEBUG_RX_PORT             ( GPIO_PORT_P3 )
#define BSP_UART_DEBUG_RX_PIN              ( GPIO_PIN5 )
extern const driverlib_gpio_cfg_t BSP_UART_DEBUG_RX;

/***********************************************
 * Debug UART Tx Pin
 **********************************************/
#define BSP_UART_DEBUG_TX_PORT             ( GPIO_PORT_P3 )
#define BSP_UART_DEBUG_TX_PIN              ( GPIO_PIN4 )
extern const driverlib_gpio_cfg_t BSP_UART_DEBUG_TX;


/***********************************************
 * Console UART Pins
 **********************************************/
/***********************************************
 * Console UART Rx Pin
 **********************************************/
#define BSP_UART_CONSOLE_RX_PORT             ( GPIO_PORT_P2 )
#define BSP_UART_CONSOLE_RX_PIN              ( GPIO_PIN1 )
extern const driverlib_gpio_cfg_t BSP_UART_CONSOLE_RX;

/***********************************************
 * Console UART Tx Pin
 **********************************************/
#define BSP_UART_CONSOLE_TX_PORT             ( GPIO_PORT_P2 )
#define BSP_UART_CONSOLE_TX_PIN              ( GPIO_PIN0 )
extern const driverlib_gpio_cfg_t BSP_UART_CONSOLE_TX;



/***********************************************
 * 12V Enable Pin
 **********************************************/
#define BSP_GPIO_12V_ENABLE_PORT        ( GPIO_PORT_P2 )
#define BSP_GPIO_12V_ENABLE_PIN         ( GPIO_PIN5 )
extern const driverlib_gpio_cfg_t g_BSP_GPIO_12V_ENABLE;


/***********************************************
 * Battery Management Pins
 **********************************************/
/***********************************************
 * Battery Management IRQ Pin
 **********************************************/
#define BSP_GPIO_BM_IRQ_PORT            ( GPIO_PORT_P1)
#define BSP_GPIO_BM_IRQ_PIN             ( GPIO_PIN5)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_BM_IRQ;

/***********************************************
 * Battery Management I2C SDA Pin
 **********************************************/
#define BSP_I2C_BM_SDA_PORT             ( GPIO_PORT_P1 )
#define BSP_I2C_BM_SDA_PIN              ( GPIO_PORT_P6 )
extern const driverlib_gpio_cfg_t g_BSP_I2C_BM_SDA;

/***********************************************
 * Battery Management I2C SCL Pin
 **********************************************/
#define BSP_I2C_BM_SCL_PORT             ( GPIO_PORT_P1 )
#define BSP_I2C_BM_SCL_PIN              ( GPIO_PORT_P7 )
extern const driverlib_gpio_cfg_t g_BSP_I2C_BM_SCL;


/***********************************************
 * Control Communications Pins
 **********************************************/
/***********************************************
 * Control Enable Pin
 **********************************************/
#define BSP_GPIO_CONTROL_IRQ_PORT            ( GPIO_PORT_P3)
#define BSP_GPIO_CONTROL_IRQ_PIN             ( GPIO_PIN0)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_CONTROL_IRQ;

/***********************************************
 * Control I2C SDA Pin
 **********************************************/
#define BSP_I2C_CONTROL_SDA_PORT             ( GPIO_PORT_P3 )
#define BSP_I2C_CONTROL_SDA_PIN              ( GPIO_PIN1 )
extern const driverlib_gpio_cfg_t g_BSP_I2C_CONTROL_SDA;

/***********************************************
 * Control I2C SCL Pin
 **********************************************/
#define BSP_I2C_CONTROL_SCL_PORT             ( GPIO_PORT_P3 )
#define BSP_I2C_CONTROL_SCL_PIN              ( GPIO_PIN2 )
extern const driverlib_gpio_cfg_t g_BSP_I2C_CONTROL_SCL;

/***********************************************
 * H-Bridge (Motor Driver) Pins
 **********************************************/

//#if MD_CONFIG_MODE == 0
/***********************************************
 * H-Bridge Enable Pin
 **********************************************/
#define BSP_GPIO_MD_ENABLE_PORT            ( GPIO_PORT_P2)
#define BSP_GPIO_MD_ENABLE_PIN             ( GPIO_PIN4)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_MD_ENABLE;
//#elif MD_CONFIG_MODE == 1
/***********************************************
 * H-Bridge PWM Pin
 **********************************************/
//#define BSP_GPIO_MD_PWM_PORT            ( GPIO_PORT_P2)
//#define BSP_GPIO_MD_PWM_PIN             ( GPIO_PIN4)
//extern const driverlib_gpio_cfg_t g_BSP_GPIO_MD_IN1;
//#endif

/***********************************************
 * H-Bridge Phase Pin
 **********************************************/
#define BSP_GPIO_MD_PH_PORT            ( GPIO_PORT_P4)
#define BSP_GPIO_MD_PH_PIN             ( GPIO_PIN3)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_MD_PH;

/***********************************************
 * H-Bridge Sleep Pin
 **********************************************/
#define BSP_GPIO_MD_SLEEP_PORT            ( GPIO_PORT_P4)
#define BSP_GPIO_MD_SLEEP_PIN             ( GPIO_PIN2)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_MD_SLEEP;

/***********************************************
 * H-Bridge Fault Pin
 **********************************************/
#define BSP_GPIO_MD_FAULT_PORT            ( GPIO_PORT_P5)
#define BSP_GPIO_MD_FAULT_PIN             ( GPIO_PIN0)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_MD_FAULT;

/***********************************************
 * H-Bridge Mode Pin
 **********************************************/
#define BSP_GPIO_MD_PMODE_PORT            ( GPIO_PORT_P5)
#define BSP_GPIO_MD_PMODE_PIN             ( GPIO_PIN1)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_MD_PMODE;

/***********************************************
 * H-Bridge ADC IPROPI Pin
 **********************************************/
#define BSP_GPIO_MD_IPROPI_PORT            ( GPIO_PORT_P1)
#define BSP_GPIO_MD_IPROPI_PIN             ( GPIO_PIN2)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_MD_IPROPI;

/***********************************************
 * Encoder Pins
 **********************************************/
/***********************************************
 * Encoder Pin A
 **********************************************/
#define BSP_GPIO_ENCODER_A_PORT           ( GPIO_PORT_P9)
#define BSP_GPIO_ENCODER_A_PIN            ( GPIO_PIN0)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_ENCODER_A;

/***********************************************
 * Encoder Pin B
 **********************************************/
#define BSP_GPIO_ENCODER_B_PORT           ( GPIO_PORT_P9)
#define BSP_GPIO_ENCODER_B_PIN            ( GPIO_PIN1)
extern const driverlib_gpio_cfg_t g_BSP_GPIO_ENCODER_B;

#endif