#include "config.h"
#include "bsp.h"

static uint16_t adc2 = 0;

void BSP_Init(void)
{
  /* Stop watchdog timer from timing out during initial start-up. */
  WDTCTL = WDTPW + WDTHOLD;
    
  /** Initialize Timers */
  Timer0_A3_Init();
  Timer3_A2_Init();
  
  /** Initialize FRAM Control */
  FRCTL_Init();
  
  /** Clear the GPIO */
  GPIO_Init();
  
  /** Initialize the Clock System */
  CS_A_Init();
  
  /** Initialize the Power Management Module */
  PMM_Init();
  
  /** Initialzie EUSCI Modules */
  EUSCI_A0_Init();
  EUSCI_A1_Init();
  EUSCI_B0_Init();
  EUSCI_B1_Init();
  
  /** Initialize the Interrupt Vectors */
  InterruptVectors_Init();
  
  /** Initialize the DMA */
  DMA_Init();
  

  
  /** Initialize RTC C */
  RTC_C_Init();
  __bis_SR_register(GIE);
  
  /** Initialize the LEDS (if preprocessor flags set) */
#if DEBUG && DEBUG_LED
  BSP_LED_Init(LED_BLUE);
  BSP_LED_Init(LED_GREEN);
#endif
  
  /** Initializethe Debug UART (if preprocessor flags set) */
#if DEBUG & DEBUG_UART
  BSP_GPIO_Init(&BSP_UART_DEBUG_RX);
  BSP_GPIO_Init(&BSP_UART_DEBUG_TX);
#endif
  
  /** Initialize the Console (if preprocesor flag set) */
  /** Console */
#if INCLUDE_CONSOLE
  BSP_GPIO_Init(&BSP_UART_CONSOLE_RX);
  BSP_GPIO_Init(&BSP_UART_CONSOLE_TX);
#endif
  
  /** 12V Power */
  BSP_GPIO_Init(&g_BSP_GPIO_12V_ENABLE);

  /** Battery Managment Pins */
  BSP_GPIO_Init(&g_BSP_GPIO_BM_IRQ);
  BSP_GPIO_Init(&g_BSP_I2C_BM_SDA);
  BSP_GPIO_Init(&g_BSP_I2C_BM_SCL);
  
  /** Control Comms */
  BSP_GPIO_Init(&g_BSP_GPIO_CONTROL_IRQ);
  BSP_GPIO_Init(&g_BSP_I2C_CONTROL_SDA);
  BSP_GPIO_Init(&g_BSP_I2C_CONTROL_SCL);
  
  /** Motor Driver */
//#if MD_CONFIG_MODE == 0
//  BSP_GPIO_Init(&g_BSP_GPIO_MD_IN1);
//#elif (MD_CONFIG_MODE == 1)
  BSP_GPIO_Init(&g_BSP_GPIO_MD_ENABLE);
//#endif
  
  BSP_GPIO_Init(&g_BSP_GPIO_MD_PH);
  BSP_GPIO_Init(&g_BSP_GPIO_MD_SLEEP);
  BSP_GPIO_Init(&g_BSP_GPIO_MD_FAULT);
  BSP_GPIO_Init(&g_BSP_GPIO_MD_PMODE);
  BSP_GPIO_Init(&g_BSP_GPIO_MD_IPROPI);
  
  /** Encoder (Hall Effect) */
  BSP_GPIO_Init(&g_BSP_GPIO_ENCODER_A);
  BSP_GPIO_Init(&g_BSP_GPIO_ENCODER_B);
    
  PMM_unlockLPM5();
  
    /** Initialize the PWM Channel */
//#if MD_CONFIG_MODE == 0
  BSP_PWM_Init();
//#endif
  
  /** Initialize the Debug UART */
  BSP_DBG_UART_Init();
  
  /** Initialize the Console UART */
  BSP_CNSL_UART_Init();
  
  /** Initialize the DMA for ADC12 */
  uint32_t adcAddr = BSP_ADC12_Address_for_DMA();
  BSP_DMA_Init( adcAddr, (uint32_t) &adc2);
  
  /** Initialize the ADC12 */
  BSP_ADC12_Init((uint32_t) &adc2);
  

  
  /** Initialze the Extended Scan Interface (encoder) */
//  esiConfig();
  
  __bis_SR_register(GIE);
}

#if DEBUG && DEBUG_UART
void BSP_DBG_UART_Init(void)
{

  BSP_UART_Init(EUSCI_A1_BASE);
}

void BSP_DBG_puts(char *str)
{

 BSP_UART_puts(EUSCI_A1_BASE, str); 
}

void BSP_DBG_putc(char c)
{
  BSP_UART_putc(EUSCI_A1_BASE, c); 
}
#endif 

#if INCLUDE_CONSOLE
void BSP_CNSL_UART_Init(void)
{

  BSP_UART_Init(EUSCI_A0_BASE);
}

int BSP_CNSL_puts(const char *str)
{

 return BSP_UART_puts(EUSCI_A0_BASE, str); 
}

int BSP_CNSL_putc(const char c)
{
  return BSP_UART_putc(EUSCI_A0_BASE, c); 
}

char BSP_CNSL_getc(void)
{
  char c;
  BSP_UART_getc(EUSCI_A0_BASE, &c);
  return c;
}
#endif 



void BSP_12V_On(void)
{
 BSP_GPIO_Set(&g_BSP_GPIO_12V_ENABLE);  
}

void BSP_12V_Off(void)
{
  
  BSP_GPIO_Clear(&g_BSP_GPIO_12V_ENABLE);  
}


