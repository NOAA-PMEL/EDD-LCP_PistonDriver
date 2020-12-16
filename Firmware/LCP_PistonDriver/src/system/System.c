/*
 *  ======== _init.c ========
 *  DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN
 */

/* external peripheral initialization functions */
extern void Timer0_A3_Init(void);
extern void Timer2_A2_Init(void);
extern void Timer3_A2_Init(void);
extern void FRCTL_Init(void);
extern void GPIO_Init(void);
extern void CS_A_Init(void);
extern void PMM_Init(void);
extern void EUSCI_A0_Init(void);
extern void EUSCI_A1_Init(void);
extern void EUSCI_B0_Init(void);
extern void InterruptVectors_Init(void);
extern void System_Init(void);
extern void DMA_Init(void);
extern void RTC_B_Init(void);
extern void WDT_A_Init(void);

#include <msp430.h>
#include <system/System.h>

/* verify that the MSP430 headers included support the code that's generated */
#if defined(__TI_COMPILER_VERSION__)
  /* pragma required to suppress TI warning that #warning is unrecognized */
  #pragma diag_suppress 11
#endif
#if __MSP430_HEADER_VERSION__ < 1093
  #if defined(__TI_COMPILER_VERSION__)
    #warn The MSP430 headers included may be incompatible with the generated source files.  If the value of __MSP430_HEADER_VERSION__, declared by msp430.h, is less than 1093, please update your version of the msp430 headers.
  #elif defined(__GNUC__) || defined(__IAR_SYSTEMS_ICC__)
    #warning The MSP430 headers included may be incompatible with the generated source files.  If the value of __MSP430_HEADER_VERSION__, declared by msp430.h, is less than 1093, please update your version of the msp430 headers.
  #else
    /* if we can't just warn, resort to ANSI C's #error */
    #error The MSP430 headers included may be incompatible with the generated source files.  If the value of __MSP430_HEADER_VERSION__, declared by msp430.h, is less than 1093, please update your version of the msp430 headers.
  #endif
#endif
#if defined(__TI_COMPILER_VERSION__)
  /* pragma required to restore TI warnings about unrecognized directives */
  #pragma diag_default 11
#endif

/*
 *  ======== _init =========
 *  Initialize all configured  peripherals
 */
void SYS_init(void)
{
    /* Stop watchdog timer from timing out during initial start-up. */
    WDTCTL = WDTPW + WDTHOLD;
    
    /* initialize Config for the MSP430 A3 Timer 0 */
    Timer0_A3_Init();

    /* initialize Config for the MSP430 A2 Timer 2 */
//    Timer2_A2_Init();

    /* initialize Config for the MSP430 A2 Timer 3 */
    Timer3_A2_Init();

    /* initialize Config for the MSP430 FRCTL */
    FRCTL_Init();

    /* initialize Config for the MSP430 GPIO */
//    GPIO_Init();

    /* initialize Config for the MSP430 FR57xx family clock systems (CS_A) */
    CS_A_Init();

    /* initialize Config for the MSP430 PMM (Power Management Module) */
    PMM_Init();

    /* initialize Config for the MSP430 eUSCI_A0 */
    EUSCI_A0_Init();
    
    /* initialize Config for the MSP430 eUSCI_A1 */
    EUSCI_A1_Init();

    /* initialize Config for the MSP430 EUSCI_B0 */
    EUSCI_B0_Init();
    
    /* initialize Config for the MSP430 EUSCI_B1 */
    EUSCI_B1_Init();
    /* initialize Interrupt vector support */
    InterruptVectors_Init();

    /* initialize Config for the MSP430 System Registers */
    __bis_SR_register(GIE);

    /* initialize Config for the MSP430 Direct Memory Access (DMA) */
    DMA_Init();

    /* initialize Config for the MSP430 RTC_B */
    RTC_C_Init();

    /* initialize Config for the MSP430 WDT_A */
//    WDT_A_Init();
    
}
