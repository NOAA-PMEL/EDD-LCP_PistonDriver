#include "DRV8874.h"


void DRV8874_init(void) {

 BSP_GPIO_Init(&g_BSP_GPIO_MD_SLEEP);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_ENABLE);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_PH);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_FAULT);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_PMODE);
 BSP_GPIO_Init(&g_BSP_GPIO_MD_IPROPI);
 
 BSP_GPIO_Clear(&g_BSP_GPIO_MD_PMODE);
 
}



void DRV8874_enable( void ) {

  BSP_12V_On();
  BSP_GPIO_Set(&g_BSP_GPIO_MD_SLEEP);
}


void DRV8874_forward( void ){
  BSP_GPIO_Set(&g_BSP_GPIO_MD_PH);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
}

void DRV8874_reverse( void ) {
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PH);
  BSP_GPIO_Set(&g_BSP_GPIO_MD_ENABLE);
  
}

void DRV8874_stop( void ) {
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_PH);
  BSP_GPIO_Clear(&g_BSP_GPIO_MD_ENABLE);
}