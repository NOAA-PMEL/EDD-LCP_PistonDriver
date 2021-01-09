#include "bsp_gpio.h"


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