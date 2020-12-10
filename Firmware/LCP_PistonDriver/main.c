#include "msp430fr5989.h"
#include <system/System.h>

int main( void )
{
  // Initialize the system
  SYS_init();

  while(1){
    P3OUT ^= BIT6;
    __delay_cycles(1000000);
  }

  return 0;
}
