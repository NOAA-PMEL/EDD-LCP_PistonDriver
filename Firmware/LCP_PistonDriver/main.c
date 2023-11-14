#include <msp430.h>
#include <stdio.h>
#include "bsp.h"
#include "logging.h"
#include "shell.h"
#include "piston.h"
#include "encoder.h"
#include "memory.h"
#include "control.h"

static void __attribute__((naked, used, section(".crt_0042")))
disable_watchdog (void)
{
	WDTCTL = WDTPW | WDTHOLD;
}

int main( void )
{
    // Initialize the system
    BSP_Init();
    LOG_Init();
    MEM_Init();
    CTRL_Init();

    BSP_LED_Clear(LED_GREEN);
    BSP_LED_Clear(LED_BLUE);
    //Log.Set(LOG_NONE);
    Log.Set(LOG_DEBUG);

    PIS_Init();
    //PIS_Reset_to_Zero();
    //PIS_Disable();

    /* Shell activation and user interactive mode*/
    sShellImpl shell_impl = {
        .send_char = BSP_CNSL_putc
    };
    shell_boot(&shell_impl);
    __bis_SR_register(GIE);
    //__bis_SR_register(LPM0_bits + GIE);

    /* for low power consumption, uncomment these two lines */
    //__bis_SR_register(LPM4_bits + GIE);
    //__no_operation();

    //char c;
    //while(1)
    //{
    //    //CTRL_Check_Write();
    //    c = BSP_CNSL_getc();
    //    shell_receive_char(c);
    //}
}

