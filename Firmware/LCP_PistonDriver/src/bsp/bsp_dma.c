#include "bsp_dma.h"

static DMA_initParam param = {
    .channelSelect = DMA_CHANNEL_0,
    .transferModeSelect = DMA_TRANSFER_SINGLE,
    .transferSize = 1,
    .triggerSourceSelect = DMA_TRIGGERSOURCE_0,
    .transferUnitSelect = DMA_SIZE_SRCWORD_DSTWORD,
    .triggerTypeSelect = DMA_TRIGGER_RISINGEDGE,
    
};

void BSP_DMA_Init(uint32_t addr)
{
  DMA_init(&param);
  
  DMA_setSrcAddress(DMA_CHANNEL_0,
        0x0860,
        DMA_DIRECTION_UNCHANGED);
  
  DMA_setDstAddress(DMA_CHANNEL_0,
        addr,
        DMA_DIRECTION_UNCHANGED);
  
  DMA_enableTransfers(DMA_CHANNEL_0);
  
  DMA_startTransfer(DMA_CHANNEL_0);
}