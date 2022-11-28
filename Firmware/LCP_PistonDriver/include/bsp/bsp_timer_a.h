#ifndef _TIMER_A_H
#define _TIMER_A_H

#ifndef TEST
#include "driverlib.h"
#endif


/** Remove STATIC and PERSISTENT values if running TEST */
/** Add the actual values if running release */
#ifdef TEST
#ifndef STATIC
#define STATIC  
#endif
#ifndef PERSISTENT
#define PERSISTENT
#endif
#else
#ifndef STATIC
#define STATIC  static
#endif
#ifndef PERSISTENT
//#define PERSISTENT __persistent 
#define PERSISTENT __attribute__((section (".persistent")))
#endif
#endif



void Timer_A_Init(void);
void Timer_A_Start(void);




#endif // _TIMER_A_H
