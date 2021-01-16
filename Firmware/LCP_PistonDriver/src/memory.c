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
    .FIRM_Build = (char*) &ram0_array[RAM0_FIRM_BUILD]
};

STATIC sRAM1_t RAM1 = {
    .VOL_Total_in3 = (float*) &ram1_array[RAM1_VOL_TOTAL_IN3],
    .VOL_Setpoint_in3 = (float*) &ram1_array[RAM1_VOL_SETPOINT_IN3],
    .VOL_Small_Piston_in3 = (float*) &ram1_array[RAM1_VOL_SMALL_PISTON_IN3],
    .VOL_Large_Piston_in3 = (float*) &ram1_array[RAM1_VOL_LARGE_PISTON_IN3],
    .VOL_Housing_in3 = (float*) &ram1_array[RAM1_HOUSING_IN3],
    .AREA_Small_Piston_in2 = (float*) &ram1_array[RAM1_AREA_SMALL_PISTON_IN2],
    .AREA_Large_Piston_in2 = (float*) &ram1_array[RAM1_AREA_LARGE_PISTON_IN2],
    .LEN_Piston_in = (float*) &ram1_array[RAM1_LEN_PISTON_IN],
    .LEN_Small_Piston_in = (float*) &ram1_array[RAM1_LEN_SMALL_PISTON_IN],
    .LEN_Large_Piston_in = (float*) &ram1_array[RAM1_LEN_LARGE_PISTON_IN],
    .PST_Position_Min = (float*) &ram1_array[RAM1_PST_POSITION_MIN],
    .PST_Position_Max = (float*) &ram1_array[RAM1_PST_POSITION_MAX],
    .PST_Rate = (float*) &ram1_array[RAM1_PST_RATE],
    .TRV_Dir= (uint8_t*) &ram1_array[RAM1_TRV_DIR],
    .TRV_Eng= (uint8_t*) &ram1_array[RAM1_TRV_ENG],
    .TRV_Zero = (uint8_t*) &ram1_array[RAM1_TRV_ZERO],
    .TRV_Max = (uint8_t*) &ram1_array[RAM1_TRV_MAX],
    .PID_Coeff_P = (float*) &ram1_array[RAM1_PID_COEFF_P],
    .PID_Coeff_I = (float*) &ram1_array[RAM1_PID_COEFF_I],
    .PID_Coeff_D = (float*) &ram1_array[RAM1_PID_COEFF_D],
    .PID_Used = (uint8_t*) &ram1_array[RAM1_PID_USED],
};

STATIC sRAM2_t RAM2 = {
    .BAT_RetCAP = (double*)&ram2_array[RAM2_BAT_RETCAP],
    .BAT_RepSOC = (double*)&ram2_array[RAM2_BAT_REPSOC],
    .BAT_VCell = (double*)&ram2_array[RAM2_BAT_VCELL],
    .BAT_Current = (double*)&ram2_array[RAM2_BAT_CURRENT],
    .BAT_TTE = (double*)&ram2_array[RAM2_BAT_TTE],
    .BAT_Status = (uint16_t*)&ram2_array[RAM2_BAT_STATUS],
};

STATIC sMemory_t PistonProtocolRam = {
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
void MEM_Write_RAM_Struct(
                        eRamTypes_t select,
                        uint8_t location,
                        uint8_t value[], 
                        uint16_t len
                        )
{
    switch(select)
    {
        case MEM_RAM_0:
            break;
        case MEM_RAM_1:
            break;
        case MEM_RAM_2:
            memcpy(&ram2_array[location], value, len);
            break;
        default:
            break;
    }
    
    for(uint16_t i=location; i<8; i++)
    {
        printf("loc[%d]: 0x%x\n",i, ram2_array[i]);
    }
    printf("RAM2.BAT_RetCAP = %f\n", PistonProtocolRam.RAM2->BAT_RetCAP);
    // uint32_t temp = 0;
    // for(uint8_t i=0; i<8; i++)
    // {
    //     temp |= (uint32_t) (ram2_array[i] << i);
    // }
    // printf("0x%ld\n", temp);
}
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
