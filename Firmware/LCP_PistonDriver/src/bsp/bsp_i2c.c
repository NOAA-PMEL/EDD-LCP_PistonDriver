#include "bsp_i2c.h"
#include "buffer_c.h"
#include <assert.h>
#include "control.h"
#include "logging.h"

volatile static eI2CState_t I2C_STATE;
sI2Command_t i2c1;

void (*I2C_int_0_callback)(volatile sI2Command_t *p);   /** Should flag transfer complete */
void (*I2C_int_1_callback)(volatile sI2Command_t *p);
void (*I2C_int_2_callback)(volatile sI2Command_t *p);

void (*I2C_int_0_callback)(volatile sI2Command_t *p) = NULL;
void (*I2C_int_1_callback)(volatile sI2Command_t *p) = NULL;
void (*I2C_int_2_callback)(volatile sI2Command_t *p) = NULL;

void USCI_B1_ISR(void);
static void _BSP_I2C_State_Machine(eI2CIntCond_t cond);
static void _BSP_clear_struct(volatile sI2Command_t *p);


/**
 *
 *
 */
//struct CtrlNode {
//  sI2Command_t data;
//  struct CtrlNode* next;
//};


//__persistent static struct CtrlNode node[5] = {NULL, NULL};
//__persistent static struct CtrlNode n1 = {NULL, NULL};
//__persistent static struct CtrlNode n2 = {NULL, NULL};
//__persistent static struct CtrlNode n3 = {NULL, NULL};
//
//static void _add_call_to_list(struct CtrlNode* head, sI2Command_t *p)
//{
//  struct CtrlNode* temp = head;
//  uint8_t idx = 0;
//  while(temp)
//  {
//    temp = temp->next;
//    idx++;
//  }
//  
//  if(idx == 6)
//  {
//    node[5].next = &node[0];
//  } else {
//    node[idx-1].next = &node[idx+1];
//  }
//  
//}

void BSP_I2C_Init(uint16_t baseAddr)
{
    assert( (baseAddr == EUSCI_B0_BASE) || (baseAddr == EUSCI_B1_BASE));

    if(baseAddr == EUSCI_B0_BASE)
    {
        EUSCI_B0_Init();
    }
    else
    {
        EUSCI_B1_Init();
    }

    _BSP_clear_struct(&i2c1);
    I2C_STATE = I2C_Idle;
}

void BSP_I2C_Disable(uint16_t baseAddr)
{
    EUSCI_B_I2C_disable(baseAddr);
    //EUSCI_B_I2C_disableInterrupt(EUSCI_B1_BASE, 0xFFFF);
}

void BSP_I2C_Enable(uint16_t baseAddr)
{
    _BSP_clear_struct(&i2c1);
    I2C_STATE = I2C_Idle;
    //EUSCI_B_I2C_clearInterrupt(EUSCI_B1_BASE,
    //                            EUSCI_B_I2C_TRANSMIT_INTERRUPT0 +
    //                            EUSCI_B_I2C_STOP_INTERRUPT +
    //                            EUSCI_B_I2C_START_INTERRUPT +
    //                            EUSCI_B_I2C_NAK_INTERRUPT
    //                            );

    BSP_I2C_Init(EUSCI_B1_BASE);
    //EUSCI_B_I2C_enable(baseAddr);
    //uint16_t interrupts =   EUSCI_B_I2C_TRANSMIT_INTERRUPT0 |
    //                        EUSCI_B_I2C_RECEIVE_INTERRUPT0 |
    //                        EUSCI_B_I2C_START_INTERRUPT |
    //                        EUSCI_B_I2C_STOP_INTERRUPT |
    //                        EUSCI_B_I2C_NAK_INTERRUPT |
    //                        EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT;
    //
    //EUSCI_B_I2C_disableInterrupt(EUSCI_B1_BASE, ~interrupts);
    //EUSCI_B_I2C_enableInterrupt(EUSCI_B1_BASE, interrupts);
}

//void BSP_I2C_puts(uint16_t baseAddr, const char *str, uint8_t length)
//{
//  assert( (baseAddr == EUSCI_B0_BASE) || (baseAddr == EUSCI_B1_BASE));
//  BufferC_puts(&i2c_tx1, str, len);
//  EUSCI_B_I2C_enable(EUSCI_B1_BASE);
//  EUSCI_B_I2C_enableInterrupt(EUSCI_B1_BASE,
//          EUSCI_B_I2C_TRANSMIT_INTERRUPT0 +
//          EUSCI_B_I2C_STOP_INTERRUPT
//          );
//}

void BSP_I2CCallback(uint16_t int_num, void function(volatile sI2Command_t *p))
{
    switch(int_num)
    {
        case 0: I2C_int_0_callback = function; break;
        case 1: I2C_int_1_callback = function; break;
        case 2: I2C_int_2_callback = function; break;
        //default: assert(False); break;
        default: assert(false); break;
    }
}

bool BSP_I2C_WriteReady( void)
{
    bool ready = false;

    if(I2C_STATE == I2C_Write_Pending)
    {
        ready = true;
    }
    return ready;
}

sI2Command_t *BSP_I2C_GetI2C_struct(void)
{
    return &i2c1;
}

static void _BSP_I2C_State_Machine(eI2CIntCond_t cond)
{
    char data=0;

    switch(I2C_STATE)
    {
        case I2C_Idle:
            if(cond == I2C_Start)
            {
                I2C_STATE = I2C_Rx_Offset;
            }
            break;

        case I2C_Rx_Offset:
            if(BufferC_Get_Size(&i2c1.rxBuf) == 0)
            {
                /** This is a scan condition, reset to Idle */
                //I2C_STATE = I2C_Idle;
                I2C_STATE = I2C_Rx_Offset;
            }
            else
            {
                BufferC_getc((sCircularBufferC_t*)&i2c1.rxBuf, &data);
                i2c1.addr_offset = data;

                /** Preload data in case of Read mode */
                I2C_int_0_callback(&i2c1);
                I2C_STATE = I2C_Write_Mode;
            }
            break;

        case I2C_Write_Mode:
            if(cond == I2C_Start)
            {
                I2C_STATE = I2C_Read_Mode;
                BufferC_getc((sCircularBufferC_t*)&i2c1.txBuf, (char*)&data);
                EUSCI_B_I2C_slavePutData( EUSCI_B1_BASE, data);
            }
            else if(cond == I2C_Stop)
            {
                /** Write data */
                I2C_STATE = I2C_Write_Pending;
            }
            else if( (cond == I2C_Nack) || (cond == I2C_Clock_Low_Timeout))
            {
                I2C_STATE = I2C_Idle;
            }
            break;

        case I2C_Write_Pending:
            __delay_cycles(5);
            CTRL_Check_Write();
            break;

        case I2C_Read_Mode:
            if(cond == I2C_Start)
            {
                /** Start Data Transfer */
                BufferC_getc((sCircularBufferC_t*)&i2c1.txBuf, (char*)&data);
                EUSCI_B_I2C_slavePutData( EUSCI_B1_BASE, data);
                __delay_cycles(5000);
            }
            else
            {
                I2C_STATE = I2C_Idle;
            }
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

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_B1_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(USCI_B1_VECTOR)))
#endif
void USCI_B1_ISR(void)
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
            __delay_cycles(1000);
            _BSP_I2C_State_Machine(I2C_Start);
            break;
        case USCI_I2C_UCSTPIFG:     // STOP condition detected (master & slave mode)
            __delay_cycles(1000);
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
            __delay_cycles(1000);
            BufferC_putc((sCircularBufferC_t*)&i2c1.rxBuf, (char)EUSCI_B_I2C_slaveGetData(EUSCI_B1_BASE));
            _BSP_I2C_State_Machine(I2C_Rx);
            //__delay_cycles(5000);
            break;
        case USCI_I2C_UCTXIFG0:     // TXIFG0
            BufferC_getc((sCircularBufferC_t*)&i2c1.txBuf, (char*)&data);
            EUSCI_B_I2C_slavePutData(EUSCI_B1_BASE, data);
            __delay_cycles(1000);
            break;
        case USCI_I2C_UCBCNTIFG:    // Byte count limit reached (UCBxTBCNT)
            break;
        case USCI_I2C_UCCLTOIFG:    // Clock low timeout - clock held low too long
            _BSP_I2C_State_Machine(I2C_Clock_Low_Timeout);
            break;
        case USCI_I2C_UCBIT9IFG:    // Generated on 9th bit of a transmit (for debugging)
            break;
        default:
            __no_operation();
            break;
    }
}
