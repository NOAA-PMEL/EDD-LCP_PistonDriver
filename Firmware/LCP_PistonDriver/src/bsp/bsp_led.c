#include "bsp.h"



#if DEBUG && DEBUG_LED


#endif

#if DEBUG && DEBUG_LED

void BSP_LED_Init(eLED_t led) {
  switch(led){
    case LED_BLUE:
      BSP_GPIO_Init(&g_BSP_GPIO_BLUE_LED);
      break;
    case LED_GREEN:
      BSP_GPIO_Init(&g_BSP_GPIO_GREEN_LED);
      break;
    default:
      assert(false);
      break;
  }
  
}
void BSP_LED_Toggle(eLED_t led)
{
  switch(led){
    case LED_BLUE:
      BSP_GPIO_Toggle(&g_BSP_GPIO_BLUE_LED);
      break;
    case LED_GREEN:
      BSP_GPIO_Toggle(&g_BSP_GPIO_GREEN_LED);
      break;
    default:
      assert(false);
      break;
  }
}

void BSP_LED_Set(eLED_t led)
{
  switch(led){
    case LED_BLUE:
      BSP_GPIO_Set(&g_BSP_GPIO_BLUE_LED);
      break;
    case LED_GREEN:
      BSP_GPIO_Set(&g_BSP_GPIO_GREEN_LED);
      break;
    default:
      assert(false);
      break;
  }
}

void BSP_LED_Clear(eLED_t led)
{
  switch(led){
    case LED_BLUE:
      BSP_GPIO_Clear(&g_BSP_GPIO_BLUE_LED);
      break;
    case LED_GREEN:
      BSP_GPIO_Clear(&g_BSP_GPIO_GREEN_LED);
      break;
    default:
      assert(false);
      break;
  }
  
}

void BSP_LED_Flash_Both(void)
{
  BSP_GPIO_Set(&g_BSP_GPIO_BLUE_LED);
  BSP_GPIO_Set(&g_BSP_GPIO_BLUE_LED); 
  _delay_ms(1000);
  BSP_GPIO_Clear(&g_BSP_GPIO_BLUE_LED);
  BSP_GPIO_Clear(&g_BSP_GPIO_BLUE_LED); 
  _delay_ms(1000);
}
#endif