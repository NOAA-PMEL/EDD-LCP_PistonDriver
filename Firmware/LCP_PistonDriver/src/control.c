#include "control.h"
#include "memory.h"
#include "bsp/bsp_gpio.h"
#include "bsp/bsp_i2c.h"
#include "buffer_c.h"



static void CTRL_Read(volatile sI2Command_t *p)
{
    uint8_t *readAddr = (uint8_t*)MEM_Get_Read_Addr(p->addr_offset);
    for(uint16_t i=p->addr_offset; i<256; i++)
    {
        BufferC_putc((sCircularBufferC_t*)&p->txBuf, *readAddr++);
    }
}

static void CTRL_Write(volatile sI2Command_t *p)
{
    uint8_t data;
    uint8_t *writeAddr = (uint8_t*) MEM_Get_Write_Addr(p->addr_offset);
    uint16_t offset = p->addr_offset;
    while( (p->rxBuf.size > 0) && (offset < 256))
    {
        BufferC_getc((sCircularBufferC_t*)&p->rxBuf, (char*)&data);
        *writeAddr++ = data;
        offset++;
    }

    /** Complete write command */
}

void CTRL_Init(void)
{
    /** Initialize pins and I2c */
    BSP_GPIO_Init(&g_BSP_I2C_CONTROL_SCL);
    BSP_GPIO_Init(&g_BSP_I2C_CONTROL_SDA);
    BSP_I2C_Init(EUSCI_B1_BASE);

    /** Attach Callbacks*/
    BSP_I2CCallback(0, &CTRL_Read);
    BSP_I2CCallback(1, &CTRL_Write);

}