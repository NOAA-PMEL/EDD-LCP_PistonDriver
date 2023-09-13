/*
 */

#include "bsp.h"
#include "logging.h"

void BSP_WDT_A_Init(void)
{

    WDT_A_initWatchdogTimer(WDT_A_BASE,
                            WDT_A_CLOCKSOURCE_ACLK,
                            WDT_A_CLOCKDIVIDER_32K);


    WDT_A_start(WDT_A_BASE);

    //SFR_clearInterrupt(SFR_WATCHDOG_INTERVAL_TIMER_INTERRUPT);
    //SFR_enableInterrupt(SFR_WATCHDOG_INTERVAL_TIMER_INTERRUPT);
}


//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
//#pragma vector=WDT_VECTOR
//__interrupt 
//#elif defined(__GNUC__)
//__attribute__((interrupt(WDT_VECTOR)))
//#endif
//void WDT_A_ISR (void)
//{
//    //Log.Debug("Dog is watching\n");
//    //BSP_LED_Toggle(LED_GREEN);
//    //WDT_A_hold(WDT_A_BASE);
//
//    //SFR_disableInterrupt(SFR_WATCHDOG_INTERVAL_TIMER_INTERRUPT);
//    //PMM_trigBOR();
//    //WDTCTL = 0;
//}


