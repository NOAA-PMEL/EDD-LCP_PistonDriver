/**********************************************************************************
* @Title       :   Module Name
* @Filename    :   memory.h
* @Author      :   Matt Casari
* @Origin Date :   1/15/2021
* @Version     :   1.0.0
* @Compiler    :   IAR, GCC
* @Target      :   
* @Notes       :   None
* @Bugs        :   No known bugs
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights 
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*********************************************************************************/
/**********************************************************************************
* Build Log
* Data    | Initials |  Description
*--------------------------------
* 1/15/21 |    MJC   | Initial design, conforming to MAP Version 0x01
*********************************************************************************/
#ifndef _MEMORY_H
#define _MEMORY_H



/**********************************************************************************
* Includes
*********************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



/**********************************************************************************
* Configuration Constants
*********************************************************************************/
#define MAP_VER     (0x01)


#define RAM_VOL_SETPOINT_IN3 0x00
#define RAM_VAR_WRITE 0x07  
#define RAM_VOL_TOTAL_IN3 0x08  
#define RAM_VOL_HOUSING_IN3 0x0C  
#define RAM_VOL_SMALL_PISTON_IN3 0x18  
#define RAM_VOL_LARGE_PISTON_IN3 0x1C 
#define RAM_LEN_SETPOINT_IN 0x20  
#define RAM_LEN_TOTAL_IN 0x28  
#define RAM_LEN_SMALL_PISTON_IN 0x38  
#define RAM_LEN_LARGE_PISTON_IN 0x3C  
#define RAM_AREA_SMALL_PISTON 0x48  
#define RAM_AREA_LARGE_PISTON 0x4C  
#define RAM_PST_POSTION_MIN 0x40  
#define RAM_PST_POSITION_MAX 0x44  
#define RAM_PST_RATE 0x48  
#define RAM_PST_POSITION_IN 0x5C
#define RAM_PST_ENC_COUNTS 0x50  
#define RAM_TRV_DIR 0x60  
#define RAM_TRV_ENG 0x61  
#define RAM_TRV_SPD 0x62
#define RAM_USER_OVERRIDE 0x63  
#define RAM_TRV_ZERO 0x68  
#define RAM_TRV_FULL 0x69  
#define RAM_TRV_MIN 0x6A  
#define RAM_TRV_MAX 0x6B  
#define RAM_PID_COEFF_P 0x80  
#define RAM_PID_COEFF_I 0x84  
#define RAM_BAT_RETCAP 0x88  
#define RAM_PID_COEFF_D 0x90  
#define RAM_PID_USED 0x94  
#define RAM_BAT_REPSOC 0x98  
#define RAM_BAT_VCELL 0xA8  
#define RAM_BAT_CURRENT 0xB8  
#define RAM_BAT_TTE 0xC8  
#define RAM_BAT_STATUS 0xD8  
#define RAM_YEAR_BUILT 0xEF  
#define RAM_SER_NUM 0xF0  
#define RAM_SYS_ID 0xE8 
#define RAM_FIRM_MAJ 0xFA  
#define RAM_FIRM_MIN 0xFC 
#define RAM_FIRM_BUILD 0xFE 
#define RAM_SYS_RESET 0x77

 
/**********************************************************************************
* MACROS
*********************************************************************************/
/** Remove STATIC and PERSISTENT values if running TEST */
/** Add the actual values if running release */
#ifdef TEST
#ifndef STATIC
#define STATIC  
#endif
#ifndef PERSISTENT
#define PERSISTENT
#endif
#else
#ifndef STATIC
#define STATIC  static
#endif
#ifndef PERSISTENT
#define PERSISTENT __persistent 
#endif
#endif


#define VAR_WRITE_KEY   (0xA5)
#define SYS_RESET_KEY   (0xCA)
#define PISTON_DIR_EXTEND       ( 1 )
#define PISTON_DIR_RETRACT      ( -1 )

/**********************************************************************************
* Typdefs
*********************************************************************************/

typedef enum eRamVars_f {
  VOL_setpoint,
  VOL_total,
  VOL_housing,
  VOL_small_piston,
  VOL_large_piston,
  LEN_setpoint,
  LEN_total,
  LEN_small_piston,
  LEN_large_piston,
  ARE_small_piston,
  ARE_large_piston,
  PST_position_min,
  PST_position_max,
  PST_rate,
  PST_position,
  PID_coeff_p,
  PID_coeff_i,
  PID_coeff_d,
  
}eRamVars_f_t;

typedef enum eRamVars_i8 {
  TRV_dir,
}eRamVars_i8_t;

typedef enum eRamVars_u8 {
  VAR_write,
  USR_override,
  TRV_eng,
  TRV_zero,
  TRV_full,
  TRV_min,
  TRV_max,
}eRamVars_u8_t;

//typedef enum eRamVars_c {
//    SYS_ser_num,  
//}eRamVars_c_t;

typedef struct sRAM {
    
    volatile float *VOL_setpoint;
    volatile uint8_t *VAR_write;
    volatile float *VOL_total;
    volatile float *VOL_housing;
    volatile float *VOL_small_piston;
    volatile float *VOL_large_piston;
    volatile float *LEN_setpoint;
    volatile float *LEN_total;
    volatile float *LEN_small_piston;
    volatile float *LEN_large_piston;
    volatile float *ARE_small_piston;
    volatile float *ARE_large_piston;
    volatile float *PST_position_min;
    volatile float *PST_position_max;
    volatile float *PST_rate;
    volatile float *PST_position;
    volatile uint32_t *PST_enc_counts;
    volatile int8_t *TRV_dir;
    volatile uint8_t *TRV_speed;
    volatile uint8_t *TRV_eng;
    volatile uint8_t *USR_override;
    volatile uint8_t *TRV_zero;
    volatile uint8_t *TRV_full;
    volatile uint8_t *TRV_min;
    volatile uint8_t *TRV_max;
    volatile float *PID_coeff_p;
    volatile float *PID_coeff_i;
    volatile float *PID_coeff_d;
    volatile uint8_t *PID_used;
    volatile double *BAT_retcap;
    volatile double *BAT_repsoc;
    volatile double *BAT_vcell;
    volatile double *BAT_current;
    volatile double *BAT_tte;
    volatile double *BAT_status;
    volatile uint16_t *SYS_year_built;
    volatile uint8_t *SYS_firm_maj;
    volatile uint8_t *SYS_firm_min;
    volatile char *SYS_ser_num;
    volatile char *SYS_id;
    volatile char *SYS_firm_build;
    volatile char *RESET;
}sRAM_t;

/**********************************************************************************
* Variables
*********************************************************************************/

/**********************************************************************************
* Function Prototypes
*********************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif
void MEM_Init(void);
void MEM_clear_temp(void);
void MEM_Write(void);

const uint8_t* MEM_Get_Write_Addr(uint16_t offset);
const uint8_t* MEM_Get_Read_Addr(uint16_t offset);
const sRAM_t* MEM_Get_Write_Struct(void);
const sRAM_t* MEM_Get_RAM_Struct(void);


void MEM_Set_VOL_Setpoint(float value);
void MEM_Set_LEN_Setpoint(float value);
void MEM_Set_PST_Position_Min(float value);
void MEM_Set_PST_Position_Max(float value);
void MEM_Set_PID_Coeff_P(float value);
void MEM_Set_PID_Coeff_I(float value);
void MEM_Set_PID_Coeff_D(float value);
void MEM_Set_PID_Used(bool used);
void MEM_Set_Var_Write(uint8_t value);
void MEM_Set_User_Override(bool value);
void MEM_Set_Travel_Direction(int8_t dir);
void MEM_Set_Travel_Engage(bool state);
void MEM_Set_Serial_Number(volatile char *value);
void MEM_Set_f(eRamVars_f_t type, float value);
void MEM_Set_u8(eRamVars_u8_t type, uint8_t value);
void MEM_Set_i8(eRamVars_i8_t type, int8_t value);
void MEM_Set_YearBuilt(volatile uint16_t year);

uint8_t MEM_Get_VAR_Write(void);
bool MEM_Get_USR_Override(void);

float MEM_Get_VOL_Setpoint(void);
float MEM_Get_VOL_Total(void);
float MEM_Get_VOL_Housing(void);
float MEM_Get_VOL_Small_Piston(void);
float MEM_Get_VOL_Large_Piston(void);

float MEM_Get_LEN_Setpoint(void);
float MEM_Get_LEN_Total(void);
float MEM_Get_LEN_Small_Piston(void);
float MEM_Get_LEN_Large_Piston(void);

float MEM_Get_AREA_Small_Piston(void);
float MEM_Get_AREA_Large_Piston(void);

float MEM_Get_PST_Position_Min(void);
float MEM_Get_PST_Position_Max(void);
uint32_t MEM_Get_PST_Encoder_Counts(void);
float MEM_Get_PST_Rate(void);
float MEM_Get_PST_Position(void);

int8_t MEM_Get_TRV_Direction(void);
bool MEM_Get_TRV_Engaged(void);
bool MEM_Get_TRV_Zero(void);
bool MEM_Get_TRV_Full(void);
bool MEM_Get_TRV_Min(void);
bool MEM_Get_TRV_Max(void);

double MEM_Get_BAT_Retcap(void);
double MEM_Get_BAT_Repsoc(void);
double MEM_Get_BAT_Vcell(void);
double MEM_Get_BAT_Current(void);
double MEM_Get_BAT_Status(void);
void MEM_Get_SYS_Id(char* value);
uint16_t MEM_Get_SYS_Year_Built(void);
uint8_t MEM_Get_SYS_Firmware_Major(void);
uint8_t MEM_Get_SYS_Firmware_Minor(void);
uint32_t MEM_Get_SYS_Firmware_Build(void);

float MEM_Get_PID_Coeff_P(void);
float MEM_Get_PID_Coeff_I(void);
float MEM_Get_PID_Coeff_D(void);
float MEM_Get_PID_Used(void);

void MEM_Get_SYS_Serial_Number(char* value);


/**********************************************************************************
* Unit Test Variables & Static Prototpyes
*********************************************************************************/
#ifdef TEST
#ifndef DOXYGEN_IGNORE_THIS

extern sRAM2_t RAM2;
extern sMemory_t PistonProtocolRam;

#endif // DOXYGEN_IGNORE_THIS
#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _MEMORY_H
