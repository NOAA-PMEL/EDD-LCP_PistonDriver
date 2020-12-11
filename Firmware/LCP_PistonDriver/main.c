#include "msp430fr5989.h"
#include <system/System.h>
#include <driverlib/eusci_a_uart.h>
#include <driverlib/eusci_b_i2c.h>

int main( void )
{
  // Initialize the system
  SYS_init();
  
  

  while(1){
    P3OUT ^= BIT6;
    __delay_cycles(1000000);
    EUSCI_A_UART_transmitData(EUSCI_A0_BASE, 'c');
    EUSCI_A_UART_transmitData(EUSCI_A1_BASE, 'a');
//    EUSCI_B_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, 'c', 500);
  }

  return 0;
}
