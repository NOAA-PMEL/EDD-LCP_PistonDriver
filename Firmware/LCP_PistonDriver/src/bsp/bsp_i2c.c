#include "bsp_i2c.h"
#include "buffer_c.h"
#include <assert.h>

volatile static eI2CState_t I2C_STATE;
volatile static sI2Command_t i2c1;

void (*I2C_int_0_callback)(volatile sI2Command_t *p);   /** Should flag transfer complete */
void (*I2C_int_1_callback)(volatile sI2Command_t *p);
void (*I2C_int_2_callback)(volatile sI2Command_t *p);


void (*I2C_int_0_callback)(volatile sI2Command_t *p) = NULL;
void (*I2C_int_1_callback)(volatile sI2Command_t *p) = NULL;
void (*I2C_int_2_callback)(volatile sI2Command_t *p) = NULL;

__interrupt void USCI_B1_ISR(void);
static void _BSP_I2C_State_Machine(eI2CIntCond_t cond);
static void _BSP_clear_struct(volatile sI2Command_t *p);



void BSP_I2C_Init(uint16_t baseAddr)
{
  assert( (baseAddr == EUSCI_B0_BASE) || (baseAddr == EUSCI_B1_BASE));
  
  if(baseAddr == EUSCI_B0_BASE)
  {
    EUSCI_B0_Init();
  } else {
    EUSCI_B1_Init();
  }
  
  _BSP_clear_struct(&i2c1);
}


// void BSP_I2C_puts(uint16_t baseAddr, const char *str, uint8_t length)
// {
//   assert( (baseAddr == EUSCI_B0_BASE) || (baseAddr == EUSCI_B1_BASE));
//   BufferC_puts(&i2c_tx1, str, len);

//   EUSCI_B_I2C_enable(EUSCI_B1_BASE);

//   EUSCI_B_I2C_clearInterrupt(EUSCI_B1_BASE,
//           EUSCI_B_I2C_TRANSMIT_INTERRUPT0 +
//           EUSCI_B_I2C_STOP_INTERRUPT
//               );

//   EUSCI_B_I2C_enableInterrupt(EUSCI_B1_BASE,
//           EUSCI_B_I2C_TRANSMIT_INTERRUPT0 +
//           EUSCI_B_I2C_STOP_INTERRUPT
//           );
  
// }


void BSP_I2CCallback(uint16_t int_num, void function(volatile sI2Command_t *p))
{
  switch(int_num) {
    case 0: I2C_int_0_callback = function; break;
    case 1: I2C_int_1_callback = function; break;
    case 2: I2C_int_2_callback = function; break;
    default: assert(False); break;
  }

}


static void _BSP_I2C_State_Machine(eI2CIntCond_t cond)
{
  uint8_t data=0;

  switch(I2C_STATE)
  {
    case I2C_Idle:
      if(cond == I2C_Start)
      {
        I2C_STATE = I2C_Rx_Offset;
      }
      break;
    case I2C_Rx_Offset:
      BufferC_getc((sCircularBufferC_t*)&i2c1.rxBuf, (uint8_t*)&data);
      i2c1.addr_offset = data;
//      if(EUSCI_B_I2C_getMode(EUSCI_B1_BASE))
//      {
        /** Get Data */
//        I2C_int_0_callback(&i2c1);

        for(uint8_t i=0; i< 25; i++)
        {
          BufferC_putc((sCircularBufferC_t*) &i2c1.txBuf, i+'a');
        }
//        I2C_STATE = I2C_Read_Mode;
//      } else {
        I2C_STATE = I2C_Write_Mode;
//        BufferC_putc((sCircularBufferC_t*)&i2c1.rxBuf, EUSCI_B_I2C_slaveGetData(EUSCI_B1_BASE));
//      } 
      break;
    
    case I2C_Write_Mode:
      if(cond == I2C_Start)
      {
        I2C_STATE = I2C_Read_Mode;
        BufferC_getc((sCircularBufferC_t*)&i2c1.txBuf, (char*)&data);
        EUSCI_B_I2C_slavePutData( EUSCI_B1_BASE, data);
      } else if(cond == I2C_Stop)
      {
        /** Write data */
        I2C_int_1_callback(&i2c1);
        I2C_STATE = I2C_Idle;
      } else if( (cond == I2C_Nack) || (cond == I2C_Start) || (cond == I2C_Clock_Low_Timeout))
      {
        I2C_STATE = I2C_Idle;
      }
      break;

    case I2C_Read_Mode:
      if(cond == I2C_Start)
      {
        /** Start Data Transfer */
        BufferC_getc((sCircularBufferC_t*)&i2c1.txBuf, (char*)&data);
        EUSCI_B_I2C_slavePutData( EUSCI_B1_BASE, data);
      } 
      I2C_STATE = I2C_Idle;
      break;
    default:
      I2C_STATE = I2C_Idle;
      break;
  }

  if(I2C_STATE == I2C_Idle)
  {
    _BSP_clear_struct(&i2c1);
  }

}

static void _BSP_clear_struct(volatile sI2Command_t *p)
{
  p->addr_offset = 0u;
  p->idx = 0u;
  BufferC_Clear((sCircularBufferC_t*)&p->rxBuf);
  BufferC_Clear((sCircularBufferC_t*)&p->txBuf);
}



#pragma vector=USCI_B1_VECTOR
__interrupt void USCI_B1_ISR(void)
{
  volatile char data;
  switch(__even_in_range(UCB1IV, USCI_I2C_UCBIT9IFG))
    {
        case USCI_NONE:             // No interrupts break;
            break;
        case USCI_I2C_UCALIFG:      // Arbitration lost
            break;
        case USCI_I2C_UCNACKIFG:    // NAK received (master only)
            _BSP_I2C_State_Machine(I2C_Nack);
            break;
        case USCI_I2C_UCSTTIFG:     // START condition detected with own address (slave mode only)
            _BSP_I2C_State_Machine(I2C_Start);
            break;
        case USCI_I2C_UCSTPIFG:     // STOP condition detected (master & slave mode)
            _BSP_I2C_State_Machine(I2C_Stop);
            break;
        case USCI_I2C_UCRXIFG3:     // RXIFG3
            break;
        case USCI_I2C_UCTXIFG3:     // TXIFG3
            break;
        case USCI_I2C_UCRXIFG2:     // RXIFG2
            break;
        case USCI_I2C_UCTXIFG2:     // TXIFG2
            break;
        case USCI_I2C_UCRXIFG1:     // RXIFG1
            break;
        case USCI_I2C_UCTXIFG1:     // TXIFG1
            break;
        case USCI_I2C_UCRXIFG0:     // RXIFG0
          BufferC_putc((sCircularBufferC_t*)&i2c1.rxBuf, (char)EUSCI_B_I2C_slaveGetData(EUSCI_B1_BASE));
          _BSP_I2C_State_Machine(I2C_Rx);
            break;
        case USCI_I2C_UCTXIFG0:     // TXIFG0
          BufferC_getc((sCircularBufferC_t*)&i2c1.txBuf, (char*)&data);
          EUSCI_B_I2C_slavePutData(EUSCI_B1_BASE, data);
          break;
        case USCI_I2C_UCBCNTIFG:    // Byte count limit reached (UCBxTBCNT)
            break;
        case USCI_I2C_UCCLTOIFG:    // Clock low timeout - clock held low too long
            _BSP_I2C_State_Machine(I2C_Clock_Low_Timeout);
            break;
        case USCI_I2C_UCBIT9IFG:    // Generated on 9th bit of a transmit (for debugging)
            break;
        default:
            break;
    }
}