#include "bsp_gpio.h"
#include "msp430fr5989.h"

void (*GPIO_int_0_callback)(void);
void (*GPIO_int_1_callback)(void);
void (*GPIO_int_2_callback)(void);
void (*GPIO_int_3_callback)(void);
void (*GPIO_int_4_callback)(void);
void (*GPIO_int_5_callback)(void);
void (*GPIO_int_6_callback)(void);
void (*GPIO_int_7_callback)(void);

void (*GPIO_int_0_callback)(void) = 0;
void (*GPIO_int_1_callback)(void) = 0;
void (*GPIO_int_2_callback)(void) = 0;
void (*GPIO_int_3_callback)(void) = 0;
void (*GPIO_int_4_callback)(void) = 0;
void (*GPIO_int_5_callback)(void) = 0;
void (*GPIO_int_6_callback)(void) = 0;
void (*GPIO_int_7_callback)(void) = 0;

__interrupt void Port_1 (void);
__interrupt void Port_2 (void);
__interrupt void Port_3 (void);
__interrupt void Port_4 (void);
__interrupt void Port_9 (void);


void BSP_GPIO_Init(const driverlib_gpio_cfg_t *p)
{
  if(p->function == DEFAULT_MODULE_FUNCTION) {
    if(p->mode == 1) 
    {
      GPIO_setAsOutputPin(p->port, p->pin);
    } else {
      GPIO_setAsInputPin(p->port, p->pin);
    }
  } else {
    GPIO_setAsPeripheralModuleFunctionOutputPin(p->port, p->pin, p->function);
  }
  
}
void BSP_GPIO_Toggle(const driverlib_gpio_cfg_t *p)
{
  GPIO_toggleOutputOnPin(p->port, p->pin);
  
}
void BSP_GPIO_Set(const driverlib_gpio_cfg_t *p)
{
  
  if(p->inverted)
  {
    GPIO_setOutputLowOnPin(p->port, p->pin);
  } else {
    GPIO_setOutputHighOnPin(p->port, p->pin);
  }
  
}



void BSP_GPIO_Clear(const driverlib_gpio_cfg_t *p)
{
  
  if(!p->inverted)
  {
    GPIO_setOutputLowOnPin(p->port, p->pin);
  } else {
    GPIO_setOutputHighOnPin(p->port, p->pin);
  }
  
}


bool BSP_GPIO_Read(const driverlib_gpio_cfg_t *p)
{
  if( GPIO_getInputPinValue(p->port, p->pin))
  {
    return true;
  } else {
    return false;
  }
}


void BSP_GPIOCallback(uint16_t int_num, void function(void))
{
  switch(int_num){
    case 0: GPIO_int_0_callback = function; break;
    case 1: GPIO_int_1_callback = function; break;
    case 2: GPIO_int_2_callback = function; break;
    case 3: GPIO_int_3_callback = function; break;
    case 4: GPIO_int_4_callback = function; break;
    case 5: GPIO_int_5_callback = function; break;
    case 6: GPIO_int_6_callback = function; break;
    case 7: GPIO_int_7_callback = function; break;
  
  }

}



#pragma vector=PORT1_VECTOR
__interrupt void Port_1 (void)
{
  switch (__even_in_range(P1IV,P1IV_P1IFG7))
  {
    case P1IV_NONE:
      break;			/*Vector 0 - No Interrupt */
    case P1IV_P1IFG0:
      break;		/* Vector 2 - Interrupt on Pin 1, Pin 0*/
    default:
      break;
  }
}


#pragma vector=PORT2_VECTOR
__interrupt void Port_2 (void)
{
  switch (__even_in_range(P2IV,P2IV_P2IFG7))
  {
    case P2IV_NONE:
      break;			/*Vector 0 - No Interrupt */
    case P2IV_P2IFG0:
      break;		/* Vector 2 - Interrupt on Pin 1, Pin 0*/
    default:
      break;
  }
}



#pragma vector=PORT3_VECTOR
__interrupt void Port_3 (void)
{
  switch (__even_in_range(P3IV,P3IV_P3IFG7))
  {
    case P3IV_NONE:
    break;			/*Vector 0 - No Interrupt */
    case P3IV_P3IFG0:
    break;		/* Vector 2 - Interrupt on Port 3, Pin 0 */
  }

}



#pragma vector=PORT4_VECTOR
__interrupt void Port_4 (void)
{

  switch (__even_in_range(P4IV,P4IV_P4IFG7))
  {
    case P4IV_NONE:
    break;			/*Vector 0 - No Interrupt */
    case P4IV_P4IFG0:
    break;			/* Vector 2 - Interrupt on Port 4, Pin 0 */
    case P4IV_P4IFG1:
    break;			/* Vector 4 - Interrupt on Port 4, Pin 1 */
    default:
      break;
  }
}




//#pragma vector=PORT9_VECTOR
//__interrupt void Port_9 (void)
//{
//
//  switch (__even_in_range(P9IV,P9IV_P9IFG7))
//  {
//    case P9IV_NONE:
//    break;			/*Vector 0 - No Interrupt */
//    case P9IV_P9IFG0:
//    break;			/* Vector 2 - Interrupt on Port 4, Pin 0 */
//    case P9IV_P9IFG1:
//    break;			/* Vector 4 - Interrupt on Port 4, Pin 1 */
//    default:
//      break;
//  }
//}