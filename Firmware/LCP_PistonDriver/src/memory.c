/** @file "memory.c"
* @brief Embedded C File Template
*/

/**********************************************************************************
* Includes
*********************************************************************************/
#include "memory.h"
/**********************************************************************************
* Preprocessor Constants
*********************************************************************************/

/**********************************************************************************
* Preprocessor Macros
*********************************************************************************/

/**********************************************************************************
* Module Variable Definitions
*********************************************************************************/
STATIC uint8_t ram0_array[256];
STATIC uint8_t ram1_array[256];
STATIC uint8_t ram2_array[256];

/**********************************************************************************
* Module Typedefs
*********************************************************************************/
STATIC sRAM0_t RAM0 = {
    .VOL_total_in3 = (float*) &ram0_array[RAM0_VOL_TOTAL_IN3],
    .VOL_setpoint_in3 = (float*) &ram0_array[RAM0_VOL_SETPOINT_IN3],
    .PST_Position_in = (float*) &ram0_array[RAM0_PST_POSITION_IN],
    .PST_Enc_Counts = (float*) &ram0_array[RAM0_PST_ENC_COUNTS],
    .PST_Rate = (float*) &ram0_array[RAM0_PST_RATE],
    .TRV_Dir = (uint8_t*) &ram0_array[RAM0_TRV_DIR],
    .TRV_Eng = (uint8_t*) &ram0_array[RAM0_TRV_ENG],
    .TRV_Zero = (uint8_t*) &ram0_array[RAM0_TRV_ZERO],
    .TRV_Max = (uint8_t*) &ram0_array[RAM0_TRV_MAX],
    .BAT_RetCAP = (double*) &ram0_array[RAM0_BAT_RETCAP],
    .BAT_RepSOC = (double*) &ram0_array[RAM0_BAT_REPSOC],
    .BAT_VCell = (double*) &ram0_array[RAM0_BAT_VCELL],
    .BAT_Current = (double*) &ram0_array[RAM0_BAT_CURRENT],
    .BAT_TTE = (double*) &ram0_array[RAM0_BAT_TTE],
    .BAT_Status = (uint16_t*) &ram0_array[RAM0_BAT_STATUS],
    .SYS_ID = (uint16_t*) &ram0_array[RAM0_SYS_ID],
    .SER_NUM = (uint16_t*) &ram0_array[RAM0_SER_NUM],
    .FIRM_Maj = (uint8_t*) &ram0_array[RAM0_FIRM_MAJ],
    .FIRM_Min = (uint8_t*) &ram0_array[RAM0_FIRM_MIN],
    .FIRM_Build = (char*) &ram0_array[RAM0_FIRM_BUILD],
};

STATIC sRAM1_t RAM1 = {

};

STATIC sRAM2_t RAM2 = {

};

STATIC sMemory_t txProtocolRam = {
    .RAM0 = &RAM0,
    .RAM1 = &RAM1,
    .RAM2 = &RAM2
};

/**********************************************************************************
* Function Prototypes
*********************************************************************************/

/**********************************************************************************
* Function Definitions
*********************************************************************************/

/**********************************************************************************
* Function: MOD_Init()
*
*//**
* \b Description:
* 
* This function does XXX, YYY & ZZZ
* 
* PRE-CONDITION: None
* 
* POST-CONDITION: None
* 
* @param None
* 
* @return void
* 
* \b Example:
* @code
* MOD_Init();
* printf("Module is initialized!\n");
* @endcode
* 
* @see MOD_Init
*/
void MOD_Init(void)
{

}
