#include "bsp_uart.h"


__interrupt void USCI_A0_ISR(void);
__interrupt void USCI_A1_ISR(void);

static sCircularBufferC_t g_uartA0;
static sCircularBufferC_t g_uartA1;

void BSP_UART_Init(uint16_t baseAddr)
{
  assert( (baseAddr == EUSCI_A0_BASE) || (baseAddr == EUSCI_A1_BASE) );
  
  if(baseAddr == EUSCI_A0_BASE) 
  {
    EUSCI_A0_Init();
  } else {
    EUSCI_A1_Init();
  }
}

int BSP_UART_puts(uint16_t baseAddr, const char *str)
{
  
  assert( (baseAddr == EUSCI_A0_BASE) || (baseAddr == EUSCI_A1_BASE) );
  int cnt = 0;
  do{
    EUSCI_A_UART_transmitData(baseAddr, *str++);  
    cnt++;
  }while(*str != 0);
  
//  EUSCI_A_UART_transmitData(baseAddr,'\n');
  
  return cnt;
}


int BSP_UART_putc(uint16_t baseAddr, const char c)
{
  EUSCI_A_UART_transmitData(baseAddr, c);  
  return 1;
}

void BSP_UART_getc(uint16_t baseAddr, char *c)
{
  assert( (baseAddr == EUSCI_A0_BASE) || (baseAddr == EUSCI_A1_BASE) );
  
  *c = '\0';
  if(baseAddr == EUSCI_A0_BASE) 
  {
    BufferC_getc(&g_uartA0, c);
  } else {
    BufferC_getc(&g_uartA1, c);
  }
}




/*
 *  ======== eUSCI_A0 Interrupt Service Routine ========
 */
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
  switch(__even_in_range(UCA0IV,USCI_UART_UCTXCPTIFG))
  {
    case USCI_NONE: break;
    case USCI_UART_UCRXIFG:     
      BufferC_putc(&g_uartA0, UCA0RXBUF);
      break;
    case USCI_UART_UCTXIFG: 
      /** Clear the Tx Flag */
      UCA0IFG &= ~(UCTXIFG);
      break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
}

/*
 *  ======== eUSCI_A1 Interrupt Service Routine ========
 */
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
  switch(__even_in_range(UCA1IV,USCI_UART_UCTXCPTIFG))
  {
    case USCI_NONE: break;
    case USCI_UART_UCRXIFG:
      BufferC_putc(&g_uartA1, UCA1RXBUF);
      break;
    case USCI_UART_UCTXIFG: 
      UCA1IFG &= ~(UCTXIFG);
      break;
    case USCI_UART_UCSTTIFG: break;
    case USCI_UART_UCTXCPTIFG: break;
  }
}