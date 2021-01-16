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

/**********************************************************************************
* Configuration Constants
*********************************************************************************/
#define MAP_VER     (0x01)

// RAM0
#define RAM0_VOL_TOTAL_IN3      (0x00)
#define RAM0_VOL_SETPOINT_IN3   (0x04)
#define RAM0_PST_POSITION_IN    (0x10)
#define RAM0_PST_ENC_COUNTS     (0x14)
#define RAM0_PST_RATE           (0x18)
#define RAM0_TRV_DIR            (0x1C)
#define RAM0_TRV_ENG            (0x1D)
#define RAM0_TRV_ZERO           (0x1E)
#define RAM0_TRV_MAX            (0x1F)
#define RAM0_BAT_RETCAP         (0x20)
#define RAM0_BAT_REPSOC         (0x28)
#define RAM0_BAT_VCELL          (0x30)
#define RAM0_BAT_CURRENT        (0x38)
#define RAM0_BAT_TTE            (0x40)
#define RAM0_BAT_STATUS         (0x48)
#define RAM0_SYS_ID             (0x80)
#define RAM0_SER_NUM            (0x82)
#define RAM0_FIRM_MAJ           (0x84)
#define RAM0_FIRM_MIN           (0x85)
#define RAM0_FIRM_BUILD         (0x86)

// RAM1
#define RAM1_VOL_TOTAL_IN3      (0x00)
#define RAM1_VOL_SETPOINT_IN3   (0x04)
#define RAM1_VOL_SMALL_PISTON_IN3   (0x08)
#define RAM1_VOL_LARGE_PISTON_IN3   (0x0C)
#define RAM1_HOUSING_IN3        (0x10)
#define RAM1_AREA_SMALL_PISTON_IN2  (0x14)
#define RAM1_AREA_LARGE_PISTON_IN2  (0x18)
#define RAM1_LEN_PISTON_IN          (0x20)
#define RAM1_LEN_SMALL_PISTON_IN    (0x24)
#define RAM1_LEN_LARGE_PISTON_IN    (0x2C)
#define RAM1_PST_POSITION_MIN       (0x30)
#define RAM1_PST_POSITION_MAX       (0x34)
#define RAM1_PST_RATE           (0x80)
#define RAM1_TRV_DIR            (0x84)
#define RAM1_TRV_ENG            (0x85)
#define RAM1_TRV_ZERO           (0x86)
#define RAM1_TRV_MAX            (0x87)
#define RAM1_PID_COEFF_P        (0xC0)
#define RAM1_PID_COEFF_I        (0xC4)
#define RAM1_PID_COEFF_D        (0xC8)
#define RAM1_PID_USED           (0xCC)

// RAM2
#define RAM2_BAT_RETCAP         (0x00)
#define RAM2_BAT_REPSOC         (0x08)
#define RAM2_BAT_VCELL          (0x10)
#define RAM2_BAT_CURRENT        (0x18)
#define RAM2_BAT_TTE            (0x20)
#define RAM2_BAT_STATUS         (0x28)
 
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

/**********************************************************************************
* Typdefs
*********************************************************************************/
typedef enum eRamTypes {
    MEM_RAM_0,
    MEM_RAM_1,
    MEM_RAM_2
}eRamTypes_t;

typedef struct sRAM0 {
    float *VOL_total_in3;
    float *VOL_setpoint_in3;
    float *PST_Position_in;
    float *PST_Enc_Counts;
    float *PST_Rate;
    uint8_t *TRV_Dir;
    uint8_t *TRV_Eng;
    uint8_t *TRV_Zero;
    uint8_t *TRV_Max;
    double *BAT_RetCAP;
    double *BAT_RepSOC;
    double *BAT_VCell;
    double *BAT_Current;
    double *BAT_TTE;
    uint16_t *BAT_Status;
    uint16_t *SYS_ID;
    uint16_t *SER_NUM;
    uint8_t *FIRM_Maj;
    uint8_t *FIRM_Min;
    char *FIRM_Build[6];
}sRAM0_t;

typedef struct sRAM1 {
    float *VOL_Total_in3;
    float *VOL_Setpoint_in3;
    float *VOL_Small_Piston_in3;
    float *VOL_Large_Piston_in3;
    float *VOL_Housing_in3;
    float *AREA_Small_Piston_in2;
    float *AREA_Large_Piston_in2;
    float *LEN_Piston_in;
    float *LEN_Small_Piston_in;
    float *LEN_Large_Piston_in;
    float *PST_Position_Min;
    float *PST_Position_Max;
    float *PST_Rate;
    uint8_t *TRV_Dir;
    uint8_t *TRV_Eng;
    uint8_t *TRV_Zero;
    uint8_t *TRV_Max;
    float *PID_Coeff_P;
    float *PID_Coeff_I;
    float *PID_Coeff_D;
    uint8_t *PID_Used;
}sRAM1_t;

typedef struct sRAM2 {
    double *BAT_RetCAP;
    double *BAT_RepSOC;
    double *BAT_VCell;
    double *BAT_Current;
    double *BAT_TTE;
    uint16_t *BAT_Status;
}sRAM2_t;

typedef struct sMemory {
    sRAM0_t *RAM0;
    sRAM1_t *RAM1;
    sRAM2_t *RAM2;
}sMemory_t;
/**********************************************************************************
* Variables
*********************************************************************************/

/**********************************************************************************
* Function Prototypes
*********************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void MEM_Write_RAM_Struct(
                        eRamTypes_t select,
                        uint8_t location,
                        uint8_t value[], 
                        uint16_t len
                        );

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
