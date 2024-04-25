#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "control.h"
#include "memory.h"
#include "bsp_gpio.h"
#include "bsp_i2c.h"
#include "buffer_c.h"
#include "logging.h"
#include "piston.h"
#include "encoder.h"
#include "driverlib.h"
#include "string.h"

uint8_t map[256];

void _CTRL_Run_Commands(uint8_t offset, const sRAM_t *pWrite, const sRAM_t *pLast);

static void CTRL_Read(volatile sI2Command_t *p)
{
    uint8_t *readAddr = (uint8_t*)MEM_Get_Read_Addr(p->addr_offset);
    for(uint16_t i=p->addr_offset; i<256; i++)
    {
        BufferC_putc((sCircularBufferC_t*)&p->txBuf, *readAddr++);
    }
}

static void CTRL_Write(void)
{
    sI2Command_t *p = BSP_I2C_GetI2C_struct();
    uint8_t data;
    uint8_t *writeAddr = (uint8_t*) MEM_Get_Write_Addr(p->addr_offset);
    uint8_t *readAddr = 0;
    uint16_t offset = p->addr_offset;
    char temp[32];

    sprintf(temp, "offset = 0x%02X", offset);
    Log.Debug(temp);

    while( (p->rxBuf.size > 0) && (offset < 256))
    {
        BufferC_getc((sCircularBufferC_t*)&p->rxBuf, (char*)&data);
        sprintf(temp, "data = 0x%02X", data);
        Log.Debug(temp);
        *writeAddr++ = data;
        offset++;
    }

    /** Complete write command */
    memset(map, 0, 256);
    writeAddr = (uint8_t*) MEM_Get_Write_Addr(p->addr_offset);
    readAddr = (uint8_t*) MEM_Get_Read_Addr(p->addr_offset);
    offset = p->addr_offset;
    while(offset < 256)
    {
        if( (*writeAddr++ - *readAddr++) != 0)
        {
            map[offset] = 1;
        }
        else
        {
            map[offset] = 0;
        }
        offset++;
    }

    /** Mask non-writeable */
    for(uint16_t i=0x00; i< 0x0100; i+=0x10)
    {
        for(uint16_t j=0x08; j<0x10; j++)
        {
            map[i|j] = 0x00;
        }
    }

    writeAddr = (uint8_t*) MEM_Get_Write_Addr(0);
    readAddr = (uint8_t*) MEM_Get_Read_Addr(0);
    for(uint16_t i=p->addr_offset; i<0x100; i++)
    {
        if(map[i]==0)
        {
            writeAddr[i] = readAddr[i];
        }
    }

    const sRAM_t *pWrite = MEM_Get_Write_Struct();
    const sRAM_t *pLast = MEM_Get_RAM_Struct();
    Log.Debug("*** I2C CTRL ***");
    _CTRL_Run_Commands(p->addr_offset, pWrite, pLast);
    Log.Debug("*** I2C CTRL Complete\n");

    /** Convert to Control Struct */
    //MEM_Write();
    /** Update from MEM */
    //BSP_
}

void CTRL_Init(void)
{
    /** Initialize pins and I2c */
    BSP_GPIO_Init(&g_BSP_I2C_CONTROL_SCL);
    BSP_GPIO_Init(&g_BSP_I2C_CONTROL_SDA);
    BSP_I2C_Init(EUSCI_B1_BASE);

    /** Attach Callbacks*/
    BSP_I2CCallback(0, &CTRL_Read);
    //BSP_I2CCallback(1, &CTRL_Write);
}

void _CTRL_Run_Commands(uint8_t offset, const sRAM_t *pWrite, const sRAM_t *pLast)
{
    char temp[64];

    if (offset != RAM_VAR_WRITE)
    {
        if( (*pLast->VAR_write != 0xA5) )
        {
            Log.Error("VAR_write needs to be 0xA5 to enter write mode");
            return;
        }
    }

    /* check everything else based on offset-address */
    /** Check for VAR Write legit */
    if (offset == RAM_VAR_WRITE)
    {
        if( (*pLast->VAR_write == 0xA5) )
        {
            Log.Debug("Already in write mode");
        }
        else if(*pWrite->VAR_write == 0xA5)
        {
            MEM_Set_Var_Write(*pWrite->VAR_write);
            Log.Debug("Entering write mode");
        }
    }
    else if (offset == RAM_SYS_RESET)
    {
        if( *pWrite->RESET == SYS_RESET_KEY)
        {
            Log.Debug("System Reset commanded");
            Log.Debug("\n\n\nDEBUG: *****************************");
            Log.Debug("<< System Reset commanded >>");
            Log.Debug("*****************************\n\n\n");

            PMM_trigPOR();
        }
    }
    else if (offset == RAM_VOL_SETPOINT_IN3)
    {
        /** Volume of Length Setpoints */
        if(*pWrite->VOL_setpoint != 0)
        {
            //if(*pWrite->VOL_setpoint != *pWrite->VOL_total)
            if(*pWrite->VOL_setpoint != *pLast->VOL_setpoint)
            {
                BSP_I2C_Enable(EUSCI_B1_BASE);
                sprintf(temp, "I2C - VOL_setpoint = %.3f", *pWrite->VOL_setpoint);
                Log.Debug(temp);
                if(*pWrite->VOL_setpoint <= 0.0f)
                {
                    PIS_Reset_to_Zero();
                }
                else
                {
                    float v_current = PIS_Get_Volume();
                    float diff = (*pWrite->VOL_setpoint-v_current);
                    if(fabs(diff) > CTRL_VOLUME_DIFF_MAX)
                    {
                        for(uint8_t i=0;i<10;i++)
                        {
                            v_current = PIS_Get_Volume();
                            diff = (*pWrite->VOL_setpoint-v_current);
                            if(fabs(diff) > CTRL_VOLUME_DIFF_MAX)
                            {
                                PIS_Run_to_volume(*pWrite->VOL_setpoint);
                            }
                        }
                    }
                    else
                    {
                        sprintf(temp, "Setpoint within %.3f of Current total",CTRL_VOLUME_DIFF_MAX);
                        Log.Debug(temp);
                        sprintf(temp,"Diff is %.3f", diff);
                        Log.Debug(temp);
                    }
                }
            }
        }
    }
    else if (offset == RAM_LEN_SETPOINT_IN)
    {
        if(*pWrite->LEN_setpoint != *pLast->LEN_setpoint)
        {
            BSP_I2C_Enable(EUSCI_B1_BASE);
            sprintf(temp, "I2C - LEN_setpoint = %.3f", *pWrite->LEN_setpoint);
            Log.Debug(temp);

            if(*pWrite->LEN_setpoint <= 0.0f)
            {
                PIS_Reset_to_Zero();
            }
            else
            {
                PIS_Run_to_length(*pWrite->LEN_setpoint);
            }
        }
    }
    else if (offset == RAM_PID_COEFF_P)
    {
        /** PID Functions */
        if(*pWrite->PID_coeff_p != *pLast->PID_coeff_p)
        {
            sprintf(temp, "Setting PID.P to %.3f", *pWrite->PID_coeff_p);
            Log.Debug(temp);
        }
    }
    else if (offset == RAM_PID_COEFF_I)
    {
        if(*pWrite->PID_coeff_i != *pLast->PID_coeff_i)
        {
            sprintf(temp, "Setting PID.I to %.3f", *pWrite->PID_coeff_i);
            Log.Debug(temp);
        }
    }
    else if (offset == RAM_PID_COEFF_D)
    {
        if(*pWrite->PID_coeff_d != *pLast->PID_coeff_d)
        {
            sprintf(temp, "Setting PID.D to %.3f", *pWrite->PID_coeff_d);
            Log.Debug(temp);
        }
    }
    else if (offset == RAM_PID_USED)
    {
        if(*pWrite->PID_used != *pLast->PID_used)
        {
            sprintf(temp, "Setting PID_used to %i", *pWrite->PID_used);
            Log.Debug(temp);
        }
    }
    else if (offset == RAM_PST_POSTION_MIN)
    {
        /** Position Min/Maxes */
        if(*pWrite->PST_position_min != 0.0f)
        {
            if(*pWrite->PST_position_min != *pLast->PST_position_min)
            {
                Log.Debug("Setting minimum position");
                Log.Error("Min Position wants to be set! Not currently implemented");
            }
        }
    }
    else if (offset == RAM_PST_POSITION_MAX)
    {
        if(*pWrite->PST_position_max != 0.0f)
        {
            if(*pWrite->PST_position_max!= *pLast->PST_position_max)
            {
                Log.Debug("Setting maximum position");
                Log.Error("Max Position wants to be set! Not currently implemented");
            }
        }
    }
    else if (offset == RAM_PST_ENC_COUNTS)
    {
        /** Position Encoder Counts */
        if(*pWrite->PST_enc_counts != *pLast->PST_enc_counts)
        {
            ENC_Set_count(*pWrite->PST_enc_counts);
        }
    }
    else if (offset == RAM_PST_CAL)
    {
        /** Piston Calibrate */
        if (*pWrite->PST_calibration != 0)
        {
            PIS_Calibrate( (uint8_t) *pWrite->PST_calibration);
            //MEM_Set_PST_Calibration(*pWrite->PST_calibration);
        }
    }
    else if (offset == RAM_MOV_FULL)
    {
        if (*pWrite->MOV_Full != 0)
        {
            /** piston move to full */
            MEM_Set_MOV_Full(*pWrite->MOV_Full);
            MEM_Set_MOV_Zero(!*pWrite->MOV_Full);
            PIS_Run_to_Full();
        }
    }
    else if (offset == RAM_MOV_ZERO)
    {
        if (*pWrite->MOV_Zero != 0)
        {
            /** piston move to zero */
            MEM_Set_MOV_Zero(*pWrite->MOV_Zero);
            MEM_Set_MOV_Full(!*pWrite->MOV_Zero);
            PIS_Reset_to_Zero();
        }
    }
    else if (offset == RAM_USER_OVERRIDE)
    {
        /** User Override */
        if(*pWrite->USR_override != *pLast->USR_override)
        {
            MEM_Set_User_Override(*pWrite->USR_override);
        }
    }
    else
    {
        Log.Debug("Offset does not match");
    }

    /* User override*/
    if(MEM_Get_USR_Override())
    {
        BSP_I2C_Enable(EUSCI_B1_BASE);
        /** Travel Direction and Engaged */
        if(*pWrite->TRV_dir != *pLast->TRV_dir)
        {
            MEM_Set_Travel_Direction(*pWrite->TRV_dir);
        }

        MEM_Set_Travel_Engage(*pWrite->TRV_eng);
        if(MEM_Get_TRV_Engaged())
        {
            Log.Debug("I2C - User TRV is engaged");
            if(MEM_Get_TRV_Direction() == -1)
            {
                Log.Debug("Retract Called");
                PIS_Retract(true, 100);
            }
            else if(MEM_Get_TRV_Direction() == 1)
            {
                Log.Debug("I2C - Extend Called");
                PIS_Extend(true, 100);
            }
            else
            {
                Log.Debug("I2C - Stop Called (dir=0)");
                PIS_Stop();
            }
        }
        else
        {
            Log.Debug("I2C - Stop Called");
            PIS_Stop();
        }
    }
    return;
}

void CTRL_Check_Write(void)
{
    //sI2Command_t* p;
    if(BSP_I2C_WriteReady()==true)
    {
        Log.Debug("Entering CTRL Commanded");
        BSP_I2C_Disable(EUSCI_B1_BASE);
        CTRL_Write();
        //BSP_I2C_Init(EUSCI_B1_BASE);
        BSP_I2C_Enable(EUSCI_B1_BASE);
        Log.Debug("Exiting CTRL Commanded\n\n");
    }
}
