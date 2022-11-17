#ifndef _BSP_I2C_H_
#define _BSP_I2C_H_

#ifndef TEST
#include <driverlib/driverlib.h>
#endif

#include "bsp_pins.h"
#include "buffer_c.h"
#include <system/System.h>

// typedef eI2CStartCondition
// {
//     I2C_Idle = 0,

// }eI2CStartCondition_t;
typedef enum eI2CState
{
    I2C_Idle,           /**< Waiting for comms to start */
    I2C_Rx_Offset,      /**< Wait for data offset address */
    I2C_Write_Mode,     /**< Write data to slave address */
    I2C_Write_Pending,  /**< Ready for command to be completed */
    I2C_Read_Mode,      /**< Send data to master */

}eI2CState_t;


typedef enum eI2CIntCond
{
    I2C_Nack,               /**< I2C NACK Condition */
    I2C_Start,              /**< I2C Start sent */
    I2C_Stop,               /**< I2C Stop sent */
    I2C_Rx,                 /**< Receiving data */
    I2C_Tx,                 /**< Transmitting data */
    I2C_Byte_Count_Limit,   /**< I2C Byte count reached */
    I2C_Clock_Low_Timeout   /**< Clock stretching has timed out */
}eI2CIntCond_t;

/** @struct 
 * 
 */
typedef struct sI2CCommand
{
    uint8_t addr_offset;    /**< Commanded address offset */
    uint8_t idx;            /**< Current data index */
    sCircularBufferC_t rxBuf;   /**< Receive Data array */
    sCircularBufferC_t txBuf;   /**< Transmit Data array */
    
}sI2Command_t;

void BSP_I2C_Init(uint16_t baseAddr);
void BSP_I2CCallback(uint16_t int_num, void function(volatile sI2Command_t *p));
void BSP_I2C_Disable(uint16_t baseAddr);
void BSP_I2C_Enable(uint16_t baseAddr);
bool BSP_I2C_WriteReady( void);
sI2Command_t *BSP_I2C_GetI2C_struct(void);
#endif // _BSP_I2C_H