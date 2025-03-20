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

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog
    
    // Disable SVS
    PMMCTL0_H = PMMPW_H;       // Open PMM registers for write
    PMMCTL0_L &= ~SVSHE;       // Disable high-side SVS
    PMMCTL0_H = 0;             // Lock PMM registers
    
    // Set all pins to outputs driving low
    P1OUT = 0; P1DIR = 0xFF;
    P2OUT = 0; P2DIR = 0xFF;
    P3OUT = 0; P3DIR = 0xFF;
    P4OUT = 0; P4DIR = 0xFF;
    P5OUT = 0; P5DIR = 0xFF;
    P6OUT = 0; P6DIR = 0xFF;
    P7OUT = 0; P7DIR = 0xFF;
    P8OUT = 0; P8DIR = 0xFF;
    
    // Simplify clock system configuration
    CSCTL0_H = CSKEY_H;        // Unlock CS registers
    CSCTL1 = DCOFSEL_0;        // Set DCO to lowest frequency
    CSCTL2 = SELA__VLOCLK + SELS__VLOCLK + SELM__VLOCLK;
    CSCTL3 = DIVA__1 + DIVS__1 + DIVM__1;
    CSCTL0_H = 0;              // Lock CS registers
    
    // Configure FRAM
    FRCTL0 = FRCTLPW | NWAITS_0;
    
    // Enter LPM3 (don't enable interrupts - we want no wake-up sources)
    __bis_SR_register(LPM3_bits);
    
    // Code below will never execute unless hardware reset
    while(1);
}

