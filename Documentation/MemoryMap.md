|---|---|---|
| | | |
| a | B | c

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
STATIC sRAM1_t *pRAM1_addr = &RAM1;

STATIC sRAM2_t RAM2 = {
    .BAT_RetCAP = (double*)&ram2_array[RAM2_BAT_RETCAP],
    .BAT_RepSOC = (double*)&ram2_array[RAM2_BAT_REPSOC],
    .BAT_VCell = (double*)&ram2_array[RAM2_BAT_VCELL],
    .BAT_Current = (double*)&ram2_array[RAM2_BAT_CURRENT],
    .BAT_TTE = (double*)&ram2_array[RAM2_BAT_TTE],
    .BAT_Status = (uint16_t*)&ram2_array[RAM2_BAT_STATUS],
};
STATIC sRAM2_t *pRAM2_addr = &RAM2;