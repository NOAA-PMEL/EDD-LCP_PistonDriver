#ifndef _DRV8874_H
#define _DRV8874_H
#include "bsp/bsp.h"
//#include "bsp/bsp_pins.h"

void DRV8874_init( void );
void DRV8874_enable( void );
void DRV8874_disable( void );
void DRV8874_forward( void );
void DRV8874_reverse( void );
void DRV8874_stop( void );
float DRV8847_read_current( void );

#endif // _DRV8874_H
