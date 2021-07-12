/** @file "memory.c"
* @brief Embedded C File Template
*/

/**********************************************************************************
* Includes
*********************************************************************************/
#include "memory.h"
#include "logging.h"
#include <assert.h>
#include <stdint.h>
#include "piston.h"

/**********************************************************************************
* Preprocessor Constants
*********************************************************************************/
#define HOUSING_VOLUME      ( 10.0f )
#define MINIMUM_TOTAL_VOLUME      ( HOUSING_VOLUME )
#define MAXIMUM_SMALL_VOLUME        ( 20f )
#define MAXIMUM_LARGE_VOLUME        ( 50f )
#define MAXIMUM_TOTAL_VOLUME        ( HOUSING_VOLUME + MAXIMUM_SMALL_VOLUME + MAXIMUM_LARGE_VOLUME)

#define MINIMUM_TOTAL_LENGTH        ( 0.0f )
#define MAXIMUM_TOTAL_LENGTH        (11.77f)

/**********************************************************************************
* Preprocessor Macros
*********************************************************************************/

/**********************************************************************************
* Module Variable Definitions
*********************************************************************************/
STATIC volatile uint8_t storage_ram[256];
STATIC volatile uint8_t temp_ram[512];  /** 512 to allow for 256 buffer overrun without failure */

/**********************************************************************************
* Module Typedefs
*********************************************************************************/
STATIC sRAM_t RAM = {
    .VOL_setpoint = (float*) &storage_ram[RAM_VOL_SETPOINT_IN3],
    .VOL_total = (float*) &storage_ram[RAM_VOL_TOTAL_IN3],
    .VAR_write = (uint8_t*) &storage_ram[RAM_VAR_WRITE],
    .VOL_housing = (float*) &storage_ram[RAM_VOL_HOUSING_IN3],
    .VOL_small_piston = (float*) &storage_ram[RAM_VOL_SMALL_PISTON_IN3],
    .VOL_large_piston = (float*) &storage_ram[RAM_VOL_LARGE_PISTON_IN3],
    .LEN_setpoint = (float*) &storage_ram[RAM_LEN_SETPOINT_IN],
    .LEN_total = (float*) &storage_ram[RAM_LEN_TOTAL_IN],
    .LEN_small_piston = (float*) &storage_ram[RAM_LEN_SMALL_PISTON_IN],
    .LEN_large_piston = (float*) &storage_ram[RAM_LEN_LARGE_PISTON_IN],
    .ARE_small_piston = (float*) &storage_ram[RAM_AREA_SMALL_PISTON],
    .ARE_large_piston = (float*) &storage_ram[RAM_AREA_LARGE_PISTON],
    .PST_position_min = (float*) &storage_ram[RAM_PST_POSTION_MIN],
    .PST_position_max = (float*) &storage_ram[RAM_PST_POSITION_MAX],
    .PST_rate = (float*) &storage_ram[RAM_PST_RATE],
    .PST_position = (float*) &storage_ram[RAM_PST_POSITION_IN],
    .PST_enc_counts = (uint32_t*) &storage_ram[RAM_PST_ENC_COUNTS],
    .TRV_dir = (int8_t *) &storage_ram[RAM_TRV_DIR],
    .TRV_eng = (uint8_t*) &storage_ram[RAM_TRV_ENG],
    .USR_override = (uint8_t*) &storage_ram[RAM_USER_OVERRIDE],
    .TRV_zero = (uint8_t*) &storage_ram[RAM_TRV_ZERO],
    .TRV_full = (uint8_t*) &storage_ram[RAM_TRV_FULL],
    .TRV_min = (uint8_t*) &storage_ram[RAM_TRV_MIN],
    .TRV_max = (uint8_t*) &storage_ram[RAM_TRV_MAX],
    .PID_coeff_p = (float*) &storage_ram[RAM_PID_COEFF_P],
    .PID_coeff_i = (float*) &storage_ram[RAM_PID_COEFF_I],
    .PID_coeff_d = (float*) &storage_ram[RAM_PID_COEFF_D],
    .PID_used = (uint8_t*) &storage_ram[RAM_PID_USED],
    .BAT_retcap = (double*) &storage_ram[RAM_BAT_RETCAP],
    .BAT_repsoc = (double*) &storage_ram[RAM_BAT_REPSOC],
    .BAT_vcell = (double*) &storage_ram[RAM_BAT_VCELL],
    .BAT_current = (double*) &storage_ram[RAM_BAT_CURRENT],
    .BAT_tte = (double*) &storage_ram[RAM_BAT_TTE],
    .BAT_status = (double*) &storage_ram[RAM_BAT_STATUS],
    .SYS_year_built = (uint16_t*) &storage_ram[RAM_YEAR_BUILT],
    .SYS_firm_maj = (uint8_t*) &storage_ram[RAM_FIRM_MAJ],
    .SYS_firm_min = (uint8_t*) &storage_ram[RAM_FIRM_MIN],
    .SYS_ser_num = (char*) &storage_ram[RAM_SER_NUM],
    .SYS_id = (char*) &storage_ram[RAM_SYS_ID],
    .SYS_firm_build = (char*) &storage_ram[RAM_FIRM_BUILD],
};

STATIC sRAM_t CMDRAM = {
    .VOL_setpoint = (float*) &temp_ram[RAM_VOL_SETPOINT_IN3],
    .VOL_total = (float*) &temp_ram[RAM_VOL_TOTAL_IN3],
    .VAR_write = (uint8_t*) &temp_ram[RAM_VAR_WRITE],
    .VOL_housing = (float*) &temp_ram[RAM_VOL_HOUSING_IN3],
    .VOL_small_piston = (float*) &temp_ram[RAM_VOL_SMALL_PISTON_IN3],
    .VOL_large_piston = (float*) &temp_ram[RAM_VOL_LARGE_PISTON_IN3],
    .LEN_setpoint = (float*) &temp_ram[RAM_LEN_SETPOINT_IN],
    .LEN_total = (float*) &temp_ram[RAM_LEN_TOTAL_IN],
    .LEN_small_piston = (float*) &temp_ram[RAM_LEN_SMALL_PISTON_IN],
    .LEN_large_piston = (float*) &temp_ram[RAM_LEN_LARGE_PISTON_IN],
    .ARE_small_piston = (float*) &temp_ram[RAM_AREA_SMALL_PISTON],
    .ARE_large_piston = (float*) &temp_ram[RAM_AREA_LARGE_PISTON],
    .PST_position_min = (float*) &temp_ram[RAM_PST_POSTION_MIN],
    .PST_position_max = (float*) &temp_ram[RAM_PST_POSITION_MAX],
    .PST_rate = (float*) &temp_ram[RAM_PST_RATE],
    .PST_position = (float*) &temp_ram[RAM_PST_POSITION_IN],
    .PST_enc_counts = (uint32_t*) &temp_ram[RAM_PST_ENC_COUNTS],
    .TRV_dir = (int8_t *) &temp_ram[RAM_TRV_DIR],
    .TRV_eng = (uint8_t*) &temp_ram[RAM_TRV_ENG],
    .USR_override = (uint8_t*) &temp_ram[RAM_USER_OVERRIDE],
    .TRV_zero = (uint8_t*) &temp_ram[RAM_TRV_ZERO],
    .TRV_full = (uint8_t*) &temp_ram[RAM_TRV_FULL],
    .TRV_min = (uint8_t*) &temp_ram[RAM_TRV_MIN],
    .TRV_max = (uint8_t*) &temp_ram[RAM_TRV_MAX],
    .PID_coeff_p = (float*) &temp_ram[RAM_PID_COEFF_P],
    .PID_coeff_i = (float*) &temp_ram[RAM_PID_COEFF_I],
    .PID_coeff_d = (float*) &temp_ram[RAM_PID_COEFF_D],
    .PID_used = (uint8_t*) &temp_ram[RAM_PID_USED],
    .BAT_retcap = (double*) &temp_ram[RAM_BAT_RETCAP],
    .BAT_repsoc = (double*) &temp_ram[RAM_BAT_REPSOC],
    .BAT_vcell = (double*) &temp_ram[RAM_BAT_VCELL],
    .BAT_current = (double*) &temp_ram[RAM_BAT_CURRENT],
    .BAT_tte = (double*) &temp_ram[RAM_BAT_TTE],
    .BAT_status = (double*) &temp_ram[RAM_BAT_STATUS],
    .SYS_year_built = (uint16_t*) &temp_ram[RAM_YEAR_BUILT],
    .SYS_firm_maj = (uint8_t*) &temp_ram[RAM_FIRM_MAJ],
    .SYS_firm_min = (uint8_t*) &temp_ram[RAM_FIRM_MIN],
    .SYS_ser_num = (char*) &temp_ram[RAM_SER_NUM],
    .SYS_id = (char*) &temp_ram[RAM_SYS_ID],
    .SYS_firm_build = (char*) &temp_ram[RAM_FIRM_BUILD],
};




const uint8_t* preadram = (uint8_t*) &storage_ram[0];
const uint8_t* pwriteram = (uint8_t*) &temp_ram[0];

/**********************************************************************************
*  Static Function Definitions
*********************************************************************************/
STATIC int16_t memcmp_volatile(volatile void *s, volatile void *t, size_t n)
{
  volatile uint8_t *ps = s;
  volatile uint8_t *pt = t;
  uint16_t cnt = 0;
  while(n-- > 0)
  {
    if(*ps++ == *pt++)
    {
      cnt++;
    }
  }
  return cnt;
}


STATIC void memset_volatile(volatile void *s, uint8_t c, size_t n)
{
  volatile uint8_t *p = s;
  while(n-- > 0)
  {
    *p++ = c;
  }
}


STATIC uint16_t strlen_volatile(volatile char* s)
{
  uint16_t cnt;
  for(uint16_t i=0; i<0xFFFF; i++)
  {
    if(s[i]==0x00u)
    {
      break;
    }
    
    cnt++;
  }
  return cnt;
}


STATIC void strncpy_volatile(volatile char *s, volatile char *t, size_t n)
{
  volatile char *ps = s;
  volatile char *pt = t;
  while(n-- > 0)
  {
    *ps++ = *pt++;
  }
    
}

/**********************************************************************************
* Function Definitions
*********************************************************************************/
void MEM_Init(void)
{
    memset_volatile((uint8_t*)temp_ram, 0u, 256);
    
    *RAM.PST_position_max = 12.0f;
    *RAM.PST_position_min = 0.0f;
}

void MEM_clear_temp(void)
{
    memset_volatile((uint8_t*)temp_ram, 0, 256);
}

void MEM_Write(void)
{
    uint8_t map[8];
    memset_volatile(map, 0u, 8);

    /** Compare the next two comparisons for time.  Use the first if close, since
     * it only checks the read only variables */
    /** #1 - Start Timing*/
    int16_t cmpval = 0;
//    uint8_t idx = 0u;
//    uint8_t len = 0u;
    for(uint8_t i=0x00; i<=0xF0; i+=0x10)
    {
        for(uint8_t j=0x00; i<0x08; i++)
        {
            
            cmpval += memcmp_volatile((uint8_t*)&temp_ram[i], &storage_ram[i], j);
        }
    }
    /** #1 - Stop Timing */
    /** #2 - Start Timing*/
    cmpval = memcmp_volatile(temp_ram, temp_ram, 256); 
    
    /** #2 - Stop Timing */
    if(cmpval != 0)
    {   
        /** Check that system is in write mode */
        if( (*RAM.VAR_write != VAR_WRITE_KEY) )
        {

            if(*CMDRAM.VAR_write == VAR_WRITE_KEY)
            {
                *RAM.VAR_write = VAR_WRITE_KEY;
            } else 
            {
                return;
            }
        }

        /** Compare the Piston Min Values */
        if(*RAM.PST_position_min != *CMDRAM.PST_position_min)
        {
            MEM_Set_PST_Position_Min(*CMDRAM.PST_position_min);
        } 

        /** Compare the Piston Max Values */
        if(*RAM.PST_position_max  != *CMDRAM.PST_position_max)
        {
            MEM_Set_PST_Position_Max(*CMDRAM.PST_position_max);
        }

        /** Compare the PID Coeff P */
        if(*RAM.PID_coeff_p != *CMDRAM.PID_coeff_p)
        {
            MEM_Set_PID_Coeff_P(*CMDRAM.PID_coeff_p);
        }

        /** Compare the PID Coeff i */
        if(*RAM.PID_coeff_i != *CMDRAM.PID_coeff_i)
        {
            MEM_Set_PID_Coeff_I(*CMDRAM.PID_coeff_i);    
        }

        /** Compare the PID Coeff D */
        if(*RAM.PID_coeff_d != *CMDRAM.PID_coeff_d)
        {
            MEM_Set_PID_Coeff_D(*CMDRAM.PID_coeff_d);
        }

        /** Compare the PID USED Value */
        if(*RAM.PID_used != *CMDRAM.PID_used)
        {

            MEM_Set_PID_Used(*CMDRAM.PID_used);
        }

        /** Compare the SERIAL Number */
        if(*RAM.SYS_ser_num != *CMDRAM.SYS_ser_num)
        {
            MEM_Set_Serial_Number((char*)&CMDRAM.SYS_ser_num[0]);
        }

       

        /** Compare the Volume Setpoints.  If that hasn't changed, comparet the Length Setpoint */
        if(*RAM.VOL_setpoint != *CMDRAM.VOL_setpoint)
        {
            /** Set the LENGTH to move to */
            MEM_Set_VOL_Setpoint(*CMDRAM.VOL_setpoint);
        } else if (*RAM.LEN_setpoint != *CMDRAM.LEN_setpoint)
        {
            MEM_Set_LEN_Setpoint(*CMDRAM.LEN_setpoint);
        }

        /** Are we in USER OVERRIDE mode? */
        if(*RAM.USR_override != true)
        {
            MEM_Set_User_Override(*CMDRAM.USR_override);
            return;
        }

        /** User Override Commands below */
        /** Compare the travel direction */
        if(*RAM.TRV_dir != *CMDRAM.TRV_dir)
        {
            MEM_Set_Travel_Direction(*CMDRAM.TRV_dir);
        }

        /** Compare the travel engaged command */
        if(*RAM.TRV_eng != *CMDRAM.TRV_eng)
        {
            MEM_Set_Travel_Engage(*CMDRAM.TRV_eng);
        }
    }

    /** Clear the temp ram for next call */
    memset_volatile(temp_ram, 0u, 256);
}

const uint8_t* MEM_Get_Write_Addr(volatile uint16_t offset)
{
    assert(offset<256);
    return preadram + offset;
}

const uint8_t* MEM_Get_Read_Addr(volatile uint16_t offset)
{
    assert(offset < 256);
    return pwriteram + offset;
}


void MEM_Set_VOL_Setpoint(volatile float value)
{
    if( (MINIMUM_TOTAL_VOLUME <= value) )
//    if((MINIMUM_TOTAL_VOLUME <= value) && (MAXIMUM_LARGE_VOLUME >= value))
    {
        /** @todo Call the volume setpoint routine */
        PIS_Run_to_volume(value);
        
        /** Update the RAM */
        *RAM.VOL_setpoint = value;
    } else {
        /** Raise value error */
    }
}

void MEM_Set_LEN_Setpoint(volatile float value)
{
    if((*RAM.PST_position_min <= value) && (*RAM.PST_position_max >= value))
    {
        /** @todo Call the length setpoint routine */
        if(PIS_Run_to_length((double) value) != PISErrorNone)
        {
            Log.Error("Failed to run to length");
        }
        /** Update the RAM */
        *RAM.LEN_setpoint = value;
    } else {
        /** Raise value error */
    }
}

void MEM_Set_PST_Position_Min(volatile float value)
{
    if((MINIMUM_TOTAL_LENGTH <= value) && (MAXIMUM_TOTAL_LENGTH >= value))
    {
        /** @todo Call the length setpoint routine */

        /** Update the RAM */
        *RAM.LEN_setpoint = value;
    } else {
        /** Raise value error */
    }
}

void MEM_Set_PST_Position_Max(volatile float value)
{
    if((MINIMUM_TOTAL_LENGTH <= value) && (MAXIMUM_TOTAL_LENGTH >= value))
    {
        /** @todo Call the maximum position function */

        /** Update the RAM */
        *RAM.LEN_setpoint = value;
    } else {
        /** Raise value error */
    }
}


void MEM_Set_PID_Coeff_P(volatile float value)
{
    /** @todo Call the PID P Function */

    /** Update the RAM */
    *RAM.PID_coeff_p = value;
}

void MEM_Set_PID_Coeff_I(volatile float value)
{
    /** @todo Call the PID I Function */

    /** Update the RAM */
    *RAM.PID_coeff_i = value;
}

void MEM_Set_PID_Coeff_D(volatile float value)
{
    /** @todo Call the PID D Function */

    /** Update the RAM */
    *RAM.PID_coeff_d = value;
}

void MEM_Set_PID_Used(volatile bool used)
{
    /** @todo Call the PID Used function */

    /** Update the RAM */
    *RAM.PID_used = (uint8_t) used;
}

void MEM_Set_Var_Write(volatile uint8_t value)
{
    /** Validate the Value */
    if(value == VAR_WRITE_KEY)
    {
        *RAM.VAR_write = value;
    } else {
        *RAM.VAR_write = 0u;
    }
}

void MEM_Set_User_Override(volatile bool value)
{
    *RAM.USR_override = value;
}

void MEM_Set_Travel_Direction(volatile int8_t dir)
{
    /** Set commanded direction */
    assert( (dir==1) || (dir==-1) );
    /** Update the RAM */
    *RAM.TRV_dir = dir;
    
    MEM_Set_Travel_Engage(*RAM.TRV_eng);
}

void MEM_Set_Travel_Engage(volatile bool state)
{    
    /** Set commanded state */
    if(state)
    {
        /** @todo Call the piston engage function */
      if(*RAM.TRV_dir != PISTON_DIR_RETRACT)
      {
        PIS_Extend(true, 100);
      } else {
        PIS_Retract(true, 100);
      }
      *RAM.TRV_eng = true;
    } else {
        /** @todo Call the piston stop function */
      PIS_Stop();
      *RAM.TRV_eng = false;
    }
    
}

void MEM_Set_Serial_Number(volatile char *value)
{
    /** Call the system serial number function */

    uint8_t len = strlen_volatile(value);
    if(len > 8) {
        len = 8;
    }
    strncpy_volatile(RAM.SYS_ser_num, value, len);
}


uint8_t MEM_Get_VAR_Write(void) { return *RAM.VAR_write; }
bool MEM_Get_USR_Override(void) { return (bool) *RAM.USR_override; }

float MEM_Get_VOL_Setpoint(void) { return PIS_Get_Volume(); }
//return *RAM.VOL_setpoint; }
float MEM_Get_VOL_Total(void) { return  *RAM.VOL_total; }
float MEM_Get_VOL_Housing(void) { return  *RAM.VOL_housing;} 
float MEM_Get_VOL_Small_Piston(void) { return  *RAM.VOL_small_piston;} 
float MEM_Get_VOL_Large_Piston(void) { return  *RAM.VOL_large_piston;} 

float MEM_Get_LEN_Setpoint(void) { return  *RAM.LEN_setpoint;} 
float MEM_Get_LEN_Total(void) { 
  
  return ENC_Get_Length();
}
//  return  *RAM.LEN_total;} 
float MEM_Get_LEN_Small_Piston(void) { return  *RAM.LEN_small_piston;} 
float MEM_Get_LEN_Large_Piston(void) { return  *RAM.LEN_large_piston;} 

float MEM_Get_AREA_Small_Piston(void) { return  *RAM.ARE_small_piston;} 
float MEM_Get_AREA_Large_Piston(void) { return  *RAM.ARE_large_piston;} 

float MEM_Get_PST_Position_Min(void) { return  *RAM.PST_position_min;} 
float MEM_Get_PST_Position_Max(void) { return  *RAM.PST_position_max;} 
uint32_t MEM_Get_PST_Encoder_Counts(void) { return  *RAM.PST_enc_counts;} 
float MEM_Get_PST_Rate(void) { return  *RAM.PST_rate;} 
float MEM_Get_PST_Position(void) { return  *RAM.PST_position;} 

int8_t MEM_Get_TRV_Direction(void) { return  *RAM.TRV_dir;} 
bool MEM_Get_TRV_Engaged(void) { return  *RAM.TRV_eng;} 
bool MEM_Get_TRV_Zero(void) { return  *RAM.TRV_zero;} 
bool MEM_Get_TRV_Full(void) { return  *RAM.TRV_full;} 
bool MEM_Get_TRV_Min(void) { return  *RAM.TRV_min;} 
bool MEM_Get_TRV_Max(void) { return  *RAM.TRV_max;} 

double MEM_Get_BAT_Retcap(void) { return  *RAM.BAT_retcap;} 
double MEM_Get_BAT_Repsoc(void) { return  *RAM.BAT_repsoc;} 
double MEM_Get_BAT_Vcell(void) { return  *RAM.BAT_vcell;} 
double MEM_Get_BAT_Current(void) { return  *RAM.BAT_current;} 
double MEM_Get_BAT_Status(void) { return  *RAM.BAT_status;} 
void MEM_Get_SYS_Id(char* value){ strncpy_volatile(value, RAM.SYS_id, 8);}
uint16_t MEM_Get_SYS_Year_Built(void) { return  *RAM.SYS_year_built;} 
uint8_t MEM_Get_SYS_Firmware_Major(void) { return  *RAM.SYS_firm_maj;} 
uint8_t MEM_Get_SYS_Firmware_Minor(void) { return  *RAM.SYS_firm_min;} 
uint32_t MEM_Get_SYS_Firmware_Build(void) { return  *RAM.SYS_firm_build;} 

float MEM_Get_PID_Coeff_P(void) { return  *RAM.PID_coeff_p;} 
float MEM_Get_PID_Coeff_I(void) { return  *RAM.PID_coeff_i;} 
float MEM_Get_PID_Coeff_D(void) { return  *RAM.PID_coeff_d;} 
float MEM_Get_PID_Used(void) { return  *RAM.PID_used;} 

void MEM_Get_SYS_Serial_Number(char* value) { strncpy_volatile(value, RAM.SYS_ser_num, 8);};