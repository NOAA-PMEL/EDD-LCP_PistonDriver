/*
 *  This file is automatically generated and does not require a license
 *
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 */
#include <driverlib/inc/hw_memmap.h>      
#include <driverlib/pmm.h>
#include <driverlib/gpio.h>
#include <system/System.h>

/* USER CODE START (section: GPIO_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: GPIO_init_c_prologue) */

/*
 *  ======== GPIO_Init ========
 *  Initialize MSP430 General Purpose Input Output Ports
 *
 *  The GPIO registers should be set in a specific order:
 *     PxOUT
 *     PxSEL or PxSELx
 *     PxDIR
 *     PxREN
 *     PxIES
 *     PxIFG
 *     PxIE
 *
 *     This will ensure that:
 *         - IFG doesn't get set by manipulating the pin function, edge
 *           select, and pull-up/down resistor functionalities (see
 *           Section 8.2.6 of the MSP430 User's manual)
 *         - Glitch-free setup (configuring the OUT register _before_
 *           setting the pin direction)
 *         - Pull-up/pull-down resistor enable with the correct direction
 *           (.up. vs. .down.)
 */
void GPIO_Init(void)
{
    /* USER CODE START (section: GPIO_Init_prologue) */
    /* User initialization code */
    /* USER CODE END (section: GPIO_Init_prologue) */

    /* Port 1 Output Register */
    P1OUT = 0;

    /* Port 1 Port Select Register 1 */
    GPIO_setAsPeripheralModuleFunctionOutputPin(
              GPIO_PORT_P1, 
              (GPIO_PIN6 | GPIO_PIN7), 
              GPIO_PRIMARY_MODULE_FUNCTION
    );

    /* Port 1 Direction Register */
    P1DIR = 0;
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

    /* Port 1 Interrupt Edge Select Register */
    P1IES = 0;

    /* Port 1 Interrupt Flag Register */
    P1IFG = 0;

    /* Port 2 Output Register */
    P2OUT = 0;

    /* Port 2 Port Select Register 1 */
    GPIO_setAsPeripheralModuleFunctionOutputPin(
              GPIO_PORT_P2, 
              (GPIO_PIN0 | GPIO_PIN1), 
              GPIO_PRIMARY_MODULE_FUNCTION
    );
//    P2SEL1 = BIT0 | BIT1 | BIT5 | BIT6;

    /* Port 2 Direction Register */
    P2DIR = 0;
//    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN5);

    /* Port 2 Interrupt Edge Select Register */
    P2IES = 0;

    /* Port 2 Interrupt Flag Register */
    P2IFG = 0;

    
    /* Port 3 */
    GPIO_setAsPeripheralModuleFunctionOutputPin(
              GPIO_PORT_P3, 
              (GPIO_PIN1 | GPIO_PIN2 |GPIO_PIN4 | GPIO_PIN5), 
              GPIO_PRIMARY_MODULE_FUNCTION
    );
    
    /* Port 3 Output Register */
    P3OUT = 0;

    /* Port 3 Direction Register */
    P3DIR = BIT6 | BIT7;

    /* Port 3 Interrupt Edge Select Register */
    P3IES = 0;

    /* Port 3 Interrupt Flag Register */
    P3IFG = 0;

    /* Port 4 Output Register */
    P4OUT = 0;

    /* Port 4 Direction Register */
    P4DIR = 0;
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN2);
    GPIO_setAsInputPin(GPIO_PORT_P4, GPIO_PIN3);

    /* Port 4 Interrupt Edge Select Register */
    P4IES = 0;

    /* Port 4 Interrupt Flag Register */
    P4IFG = 0;
    
    /* Port 5 Output Register */
    P5OUT = 0;

    /* Port 5 Direction Register */
    P5DIR = 0;
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN1);
    GPIO_setAsInputPin(GPIO_PORT_P5, GPIO_PIN0);

    /* Port 5 Interrupt Edge Select Register */
//    P5IES = 0;

    /* Port 5 Interrupt Flag Register */
//    P5IFG = 0;
    
    

    /* Port J Output Register */
    PJOUT = 0;

    /* Port J Port Select Register 0 */
    PJSEL0 = BIT4 | BIT5;

    /* Port J Direction Register */
    PJDIR = 0;

    /* USER CODE START (section: GPIO_Init_epilogue) */
    /* User code */
    /* USER CODE END (section: GPIO_Init_epilogue) */


    /* Disable the GPIO power-on default high-impedance mode to activate previously configured port settings */
    PMM_unlockLPM5();
}
