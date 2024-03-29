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
#include <system/System.h>

/* USER CODE START (section: PMM_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: PMM_init_c_prologue) */

/*
 *  ======== PMM_Init ========
 *  Initialize Config for the MSP430 PMM (Power Management Module)
 */
void PMM_Init(void)
{
    /* USER CODE START (section: PMM_Init_prologue) */
    /* User initialization code */
    /* USER CODE END (section: PMM_Init_prologue) */

    PMM_enableSVSH();

//    PMM_enableLowPowerReset(PMM_BASE);

    /* USER CODE START (section: PMM_Init_epilogue) */
    /* User code */
    /* USER CODE END (section: PMM_Init_epilogue) */
}
