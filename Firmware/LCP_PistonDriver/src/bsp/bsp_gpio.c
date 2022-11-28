#include "bsp_gpio.h"
#include "driverlib.h"

volatile int32_t g_gpio_count_0 = 0lu;

void (*GPIO_int_0_callback)(void);
void (*GPIO_int_1_callback)(void);
void (*GPIO_int_2_callback)(void);
void (*GPIO_int_3_callback)(void);
void (*GPIO_int_4_callback)(void);
void (*GPIO_int_5_callback)(void);
void (*GPIO_int_6_callback)(void);
void (*GPIO_int_7_callback)(void);
int8_t (*GPIO_int_10_callback)(void);

void (*GPIO_int_0_callback)(void) = 0;
void (*GPIO_int_1_callback)(void) = 0;
void (*GPIO_int_2_callback)(void) = 0;
void (*GPIO_int_3_callback)(void) = 0;
void (*GPIO_int_4_callback)(void) = 0;
void (*GPIO_int_5_callback)(void) = 0;
void (*GPIO_int_6_callback)(void) = 0;
void (*GPIO_int_7_callback)(void) = 0;
int8_t (*GPIO_int_10_callback)(void) = 0;

void Port_1 (void);
void Port_2 (void);
void Port_3 (void);
void Port_4 (void);
void Port_9 (void);


volatile int32_t * BSP_GPIO_Init_Counter( uint8_t counter)
{
  volatile int32_t *p;
  
  switch(counter)
  {
  case 0:
    p = &g_gpio_count_0;
    break;
  default:
    break;
    
  }
  
  return p;
}


void BSP_GPIO_Init(const driverlib_gpio_cfg_t *p)
{
  

//  if(p->function == DEFAULT_MODULE_FUNCTION) {
    if(p->mode == 1) 
    {
      GPIO_setAsOutputPin(p->port, p->pin);
    } else {
      if(p->pullups == 0)
      {
        GPIO_setAsInputPin(p->port, p->pin);
      }
      else if(p->pullups == 1)
      {
        GPIO_setAsInputPinWithPullUpResistor(p->port, p->pin);
      }
      else if(p->pullups == 2)
      {
        GPIO_setAsInputPinWithPullDownResistor(p->port, p->pin);
      }
      
    }
//  } else {
  if(p->function != DEFAULT_MODULE_FUNCTION) {
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


void BSP_GPIO_SetInterrupt(const driverlib_gpio_cfg_t *p)
{
    GPIO_enableInterrupt(p->port, p->pin); 
    __bis_SR_register(GIE);
  
}
void BSP_GPIO_ClearInterrupt(const driverlib_gpio_cfg_t *p)
{
    GPIO_disableInterrupt(p->port, p->pin);
    __bis_SR_register(GIE);
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

void BSP_GPIOCallback_i(uint16_t int_num, int8_t function(void))
{
  switch(int_num) {
    case 10: GPIO_int_10_callback = function; break;
  }
}


#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(PORT1_VECTOR)))
#endif
void Port_1 (void)
{
  volatile static uint8_t fwd_state = 0;
  volatile static uint8_t rev_state = 0;
  volatile uint8_t value;
  volatile int8_t dir; 
  
  switch (__even_in_range(P1IV,P1IV_P1IFG7))
  {
    case P1IV_NONE:
      break;			/*Vector 0 - No Interrupt */
    case P1IV_P1IFG0:
      break;		/* Vector 2 - Interrupt on Pin 1, Pin 0*/
    case P1IV_P1IFG3:
      
    value = GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4);
    dir = GPIO_int_10_callback();
    if(dir == -1)
    {
      if( (fwd_state == 0) && (value == 0) ) 
      {
        fwd_state = 1;
      }
    } else if( dir == 1)
    {
      if( (rev_state == 0 ) && (value == 1) )
      {
        rev_state = 1;
      }
    }
//      if(GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4))
//      {
//        if(fwd_state == 0)
//        {
//          GPIO_int_1_callback(); // Increment
//          fwd_state = 1;
//        } 
//      } else {
//        if(rev_state == 0)
//        {
//          GPIO_int_2_callback();
//          rev_state = 1;
//        }
//      }
//      GPIO_disableInterrupt(GPIO_PORT_P1, GPIO_PIN3);
//      GPIO_int_1_callback();
//      GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN3);
//      GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN3);
      
//      g_gpio_count_0++;
      break;
    case P1IV_P1IFG4:
    value = GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN3);
 
/** Rising Edge States */
//    if( (fwd_state == 1) && (value == 1) ) 
//    {
//      GPIO_int_2_callback();
//      fwd_state = 0;
//    }
//    
//    if( (rev_state == 1 ) && (value == 0) )
//    {
//      GPIO_int_1_callback();
//      rev_state = 0;
//    }
    
    /** Falling Edge States */
    dir = GPIO_int_10_callback();
    if(dir == -1)
    {
      if( (fwd_state == 1) && (value == 1))
      {
        GPIO_int_2_callback();
        fwd_state = 0;
      }
    } else if( dir == 1)
    {
      if( (rev_state == 1) && (value == 0) )
      {
        GPIO_int_1_callback();
        rev_state = 0;
      }
    }      

      //      g_gpio_count_0--;
//      if(GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN3))
//      {
//        if(fwd_state == 1)
//        {
//          fwd_state = 0;
//        }
//      } else {
//        if(rev_state == 1)
//        {
//          rev_state = 0;
//        }
//      }
      break;
    default:
      break;
  }
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT2_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(PORT2_VECTOR)))
#endif
void Port_2 (void)
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


#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT3_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(PORT3_VECTOR)))
#endif
void Port_3 (void)
{
  switch (__even_in_range(P3IV,P3IV_P3IFG7))
  {
    case P3IV_NONE:
    break;			/*Vector 0 - No Interrupt */
    case P3IV_P3IFG0:
    break;		/* Vector 2 - Interrupt on Port 3, Pin 0 */
  }

}


#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT4_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(PORT4_VECTOR)))
#endif
void Port_4 (void)
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



//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
//#pragma vector=PORT9_VECTOR
//__interrupt
//#elif defined(__GNUC__)
//__attribute__((interrupt(PORT9_VECTOR)))
//#endif
//interrupt void Port_9 (void)
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
