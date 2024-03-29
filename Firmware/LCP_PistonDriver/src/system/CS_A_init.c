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
 *
 */
#include <driverlib/inc/hw_memmap.h>
#include <driverlib/cs.h>
#include <system/System.h>

/* USER CODE START (section: CS_A_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: CS_A_init_c_prologue) */

/*
 *  ======== CS_A_Init ========
 *  Initialize MSP430 Clock System
 */
void CS_A_Init(void)
{

    /* USER CODE START (section: CS_A_Init_prologue) */
    /* User initialization code */
    /* USER CODE END (section: CS_A_Init_prologue) */

    /*
     * Sets the external clock source for XT1 and XT2. These variables can be used by
     * other API functions.
     *   XT1 Frequency -  32768 Hz
     *   XT2 Frequency -  0 Hz
     */
    CS_setExternalClockSource (32768, 0);

    /*
     * Start Low Frequency crystal in low frequency mode
     */
    CS_turnOnLFXTWithTimeout(LFXTDRIVE_3, 100000);

    /*
     * Setting MCLK source from CS_DCOCLK_SELECT with the divider of CS_CLOCK_DIVIDER_2.
     */
    CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_2);

    /*
     * Setting SMCLK source from CS_DCOCLK_SELECT with the divider of CS_CLOCK_DIVIDER_4.
     */
    CS_initClockSignal( CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_8);

    /*
     * Setting ACLK source from CS_VLOCLK_SELECT with the divider of CS_CLOCK_DIVIDER_1.
     */
    CS_initClockSignal(CS_ACLK, CS_VLOCLK_SELECT, CS_CLOCK_DIVIDER_1);

    /*
     * Set DCO frequency to 8000000 Hz
     */
//    CS_setDCOFreq (CS_DCORSEL_0, CS_DCOFSEL_6);
    CS_setDCOFreq (CS_DCORSEL_1, CS_DCOFSEL_4);

    /*
     * Clears all oscillator fault flags including global oscillator fault flag
     * before switching clock sources
     */
    CS_clearAllOscFlagsWithTimeout(100000);

    /*
     * MCLK clock request enable. Setting this enables conditional module requests for MCLK
     */
    CS_disableClockRequest (CS_MCLK);

    /*
     * SMCLK clock request enable. Setting this enables conditional module requests for SMCLK
     */
    CS_disableClockRequest (CS_SMCLK);

    /*
     * ACLK clock request enable. Setting this enables conditional module requests for ACLK
     */
    CS_disableClockRequest (CS_ACLK);

    /* USER CODE START (section: CS_A_Init_epilogue) */
    /* User code */
    /* USER CODE END (section: CS_A_Init_epilogue) */
}
