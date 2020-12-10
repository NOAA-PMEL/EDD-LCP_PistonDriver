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
#include <driverlib/dma.h>
#include <system/System.h>
#include <stdint.h>

/* USER CODE START (section: DMA_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: DMA_init_c_prologue) */

/*
 *  ======== DMA_Init ========
 *  Initialize Config for the MSP430 Direct Memory Access (DMA)
 */



void DMA_Init(void)
{
  
    DMA_initParam param = {
    .channelSelect = DMA_CHANNEL_0,
    .transferModeSelect = DMA_TRANSFER_BLOCK,
    .transferSize = 1,
    .triggerSourceSelect = DMA_TRIGGERSOURCE_14,
    .transferUnitSelect = DMA_SIZE_SRCBYTE_DSTBYTE,
    .triggerTypeSelect = DMA_TRIGGER_RISINGEDGE
    };

    /* Initialize DMA channel 0 */
    DMA_init(&param);

    /* Enable transfers to be triggered for channel 0 */
    DMA_enableTransfers(param.channelSelect);

    /* Enable the DMA interrupt for channel 0 */
    DMA_enableInterrupt (param.channelSelect);

    /* USER CODE START (section: DMA_Init_epilogue) */
    /* User code */
    /* USER CODE END (section: DMA_Init_epilogue) */
}

