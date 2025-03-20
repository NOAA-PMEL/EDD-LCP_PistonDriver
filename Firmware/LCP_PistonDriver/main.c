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
    //Log.Set(LOG_DEBUG);

    //PIS_Init();
    //PIS_Reset_to_Zero();
    //PIS_Disable();
    //PIS_Calibration_check();

    // Disable COM interfaces
    EUSCI_A_UART_disable(EUSCI_A0_BASE);
    EUSCI_A_UART_disable(EUSCI_A1_BASE);
    
    // Disable I2C interfaces
    EUSCI_B_I2C_disable(EUSCI_B0_BASE);
    EUSCI_B_I2C_disable(EUSCI_B1_BASE);
    
    // Disable ADC
    ADC12CTL0 &= ~ADC12ON;

    // 5. Disable DMA controller
    DMA0CTL &= ~DMAEN;
    DMA1CTL &= ~DMAEN;
    DMA2CTL &= ~DMAEN;

    // 6. Disable any enabled PWM timers
    TA0CTL = 0;  // Timer A0 (likely used for PWM)
    TA1CTL = 0;  // Timer A1
    TA2CTL = 0;  // Timer A2
    TA3CTL = 0;  // Timer A3

    // 7. Disable motor driver IC
    // Your motor driver appears to have sleep/enable lines
    // Assuming g_BSP_GPIO_MD_SLEEP is active low
    BSP_GPIO_Clear(&g_BSP_GPIO_MD_SLEEP);  // Put motor driver to sleep
    BSP_GPIO_Clear(&g_BSP_GPIO_MD_ENABLE); // Disable motor driver
    
    // 8. Configure GPIO pins 
    // Put unused GPIO pins in a defined state
    P1OUT = 0;
    P2OUT = 0;
    P3OUT = 0;
    P4OUT = 0;
    P5OUT = 0;
    P6OUT = 0;
    P7OUT = 0;
    P8OUT = 0;
    
    P1DIR = 0xFF;
    P2DIR = 0xFF;
    P3DIR = 0xFF;
    P4DIR = 0xFF;
    P5DIR = 0xFF;
    P6DIR = 0xFF;
    P7DIR = 0xFF;
    P8DIR = 0xFF;
    
    // Visual indicator before sleep
    BSP_LED_Set(LED_GREEN);
    __delay_cycles(500000);
    BSP_LED_Clear(LED_GREEN);

    /* for low power consumption, uncomment lines below */
    __enable_interrupt();
    __bis_SR_register(LPM3_bits + GIE);
    //__no_operation();

    /* Shell activation and user interactive mode*/
    //sShellImpl shell_impl = {
    //    .send_char = BSP_CNSL_putc
    //};
    //shell_boot(&shell_impl);

    //char c;
    //while(1)
    //{
    //    //CTRL_Check_Write();
    //    c = BSP_CNSL_getc();
    //    shell_receive_char(c);
    //}
}

