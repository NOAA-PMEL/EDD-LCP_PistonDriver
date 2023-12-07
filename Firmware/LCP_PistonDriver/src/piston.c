/** @file "piston.c"
 * @brief Piston control
 */

/**********************************************************************************
 * Includes
 *********************************************************************************/
#include "piston.h"
#include "logging.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>

/**********************************************************************************
 * Preprocessor Constants
 *********************************************************************************/
/**********************************************************************************
 * Preprocessor Macros
 *********************************************************************************/
/**********************************************************************************
 * Module Typedefs
 *********************************************************************************/
/**********************************************************************************
 * Module Variable Definitions
 *********************************************************************************/
/**
 * Defines the struct for the Small Diameter Piston
 */
STATIC PERSISTENT sPistonVolume_t smallPiston = {
    ._volume = 0,
    ._length = 0,
    ._diameter = SMALL_PISTON_DIAMETER,
    ._max_length = SMALL_PISTON_MAX_LENGTH,
    //._max_volume = SMALL_PISTON_DIAMETER * PI *SMALL_PISTON_MAX_LENGTH
    ._max_volume = SMALL_PISTON_MAX_VOLUME
};

/**
 * Define the struct for the Large Diameter PIston
 */
STATIC PERSISTENT sPistonVolume_t largePiston = {
    ._volume = 0,
    ._length = 0,
    ._diameter = LARGE_PISTON_DIAMETER,
    ._max_length = LARGE_PISTON_MAX_LENGTH,
    //._max_volume = LARGE_PISTON_DIAMETER * PI * LARGE_PISTON_MAX_LENGTH
    ._max_volume = LARGE_PISTON_MAX_VOLUME
};

/**
 * Defines the struct for the Housing
 */
STATIC const sPistonVolume_t housing = {
    //._volume = HOUSING_LENGTH * HOUSING_DIAMETER * PI,
    ._volume = HOUSING_VOLUME,
    ._length = HOUSING_LENGTH,
    ._diameter = HOUSING_DIAMETER,
    ._max_length = HOUSING_LENGTH,
    //._max_volume = HOUSING_DIAMETER * PI * HOUSING_LENGTH
    ._max_volume = HOUSING_VOLUME
};

/**
 * Defines the struct for the Actuator settings
 */
STATIC sActuator_t actuator = {
    // .settings = &encSettings,
    .current_length = 0.0f,
    .setpoint = 0.0f,
    .enc_min = 0.0f,
    .enc_max = 0.0f
};

/** 
 * Defines the full profiler piston system struct
 */
//STATIC sPistonSystem_t profiler = {
//    .volume = 0,
//    .actuator = &actuator,
//    .smallPiston = &smallPiston,
//    .largePiston = &largePiston,
//    .housing = &housing
//};

STATIC PERSISTENT uint8_t _calibration = 0;

/**********************************************************************************
 * Function Prototypes
 *********************************************************************************/
STATIC void PIS_Write_length(double);
STATIC void PIS_Write_volume(double volume);
STATIC double PIS_Read_length(void);
STATIC double PIS_Read_volume(void);
STATIC float PIS_Read_current(void);
STATIC void _PIS_calc_encoder_range(double setpoint, 
                        double range, 
                        double conversion_factor,
                        int32_t *min_cnt,
                        int32_t *max_cnt
                        );

STATIC double _PIS_estimate_length_from_volume(
     double volume,
     const sPistonVolume_t *small,
     const sPistonVolume_t *large,
     const sPistonVolume_t *housing
     );

STATIC double _PIS_calculate_volume_from_length(
    double length,
    const sPistonVolume_t *small,
    const sPistonVolume_t *large,
    const sPistonVolume_t *housing
     );

STATIC bool _check_is_at_zero(void);
STATIC float _PIS_PID_Controller(float setpoint, float input);

/**********************************************************************************
 * Function Definitions
 *********************************************************************************/
/**********************************************************************************
 * Function: PIS_Init()
 *
 *//**
 * \b Description:
 * 
 * This function initializes the Piston System by initializing
 * the DRV8874 H-Bridge and the Encoder System
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
 * PIS_Init();
 * @endcode
 * 
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
void PIS_Init(void) {
    Log.Debug("Initializing Piston Functions");
    DRV8874_init();
    ENC_Init();
    PIS_Enable();

    /* check calibration */
    uint8_t cali = _calibration;
    MEM_Set_PST_Calibration((bool) cali);
}

/**********************************************************************************
 * Function: PIS_Enable()
 *
 *//**
 * \b Description:
 * 
 * This function enables the piston subsystem for movement
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * @endcode
 * 
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
void PIS_Enable(void) {
    Log.Debug("Enabling Piston Control");
    DRV8874_enable();
}

/**********************************************************************************
 * Function: PIS_Disable()
 *
 *//**
 * \b Description:
 * 
 * This function disables the piston subsystem, preventing
 * movement at unwanted times.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * PIS_Disable();
 * @endcode
 * 
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
void PIS_Disable(void) {
    Log.Debug("Disabling Piston Control");
    DRV8874_disable();   
}

/**********************************************************************************
 * Function: PIS_Read()
 *
 *//**
 * \b Description:
 * 
 * This function reads the selected variable.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param read is the variable to read
 * 
 * @return The selected variables value
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * double current = PIS_Read(PISReadCurrent);
 * printf("%lf\n", current);
 * @endcode
 * 
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
double PIS_Read(ePistonRead_t read)
{
    if(read == PISReadLength)
    {
        return PIS_Read_length();
    } else if( read == PISReadVolume) 
    {
        return PIS_Read_volume();
    } else if( read == PISReadCurrent) 
    {
        return (double) PIS_Read_current();
    } else {
        /** @todo Add Logging Error */
      return 0.0f;
    }
}

/**********************************************************************************
 * Function: PIS_Write()
 *
 *//**
 * \b Description:
 * 
 * This function writes the value to the selected
 * variable.
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Selected Variable must be valid
 * 
 * POST-CONDITION: None
 * 
 * @param write is the variable selected to be written to
 * @param value is the value to write to variable.
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Write(PISWriteVolume, 300.1);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
//void PIS_Write(ePistonWrite_t write, double value)
//{
//    switch(write)
//    {
//        case PISWriteLength:
//            
//            break;
//        case PISWriteVolume:
//
//            break;
//        default:
//        /** @todo Add Logging Error */
//            break;
//    }
//}

/**********************************************************************************
 * Function: PIS_Run_to_length()
 *
 *//**
 * \b Description:
 * 
 * This function runs the piston until it reaches the piston length
 * setpoint selected (within the range tolerance initially provided).
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Length Variable must be valid
 * 
 * POST-CONDITION: Piston will be moved to selected position.
 * POST-CONDITION: actuator.current_length will be updated.
 * 
 * @param length is the length to run to.
 * 
 * @return Error status
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * ePistonRunError_t error = PIS_Run_to_length(7.5);
 * if(error == PISErrorNone)
 * {
 *  printf("Piston successfully moved to %f inches", actuator.current_length);
 * }
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 * @see PIS_Run_to_length
 * @see PIS_Run_to_volume
 */
ePistonRunError_t PIS_Run_to_length(float length)
{
    #ifndef TEST
    assert(length <= SYSTEM_MAX_LENGTH);
    assert(length >= SYSTEM_MIN_LENGTH);
    #endif

    MEM_Set_f(LEN_setpoint, length);
    
    double volume = _PIS_calculate_volume_from_length( 
                    length,
                    &smallPiston,
                    &largePiston,
                    &housing);
    MEM_Set_f(VOL_setpoint, volume); 
    
    char temp[64];
    sprintf(temp, "PIS_Run_to_length called with length = %f", length);
    Log.Debug(temp);

    ePistonRunError_t error = PISErrorGeneric;
    /** Update the setpoint and encoder range */
    PIS_Write_length(length);

    actuator.setpoint_flag = false;
    float diff = length - ENC_Get_Length();
    uint8_t speed;
    if(fabs(diff) > PISTON_SLOW_SPEED_LENGTH)
    {
      speed = 100;
    } else {
      //speed = 80;
      speed = 60;
    }
    
    if(diff > 0)
    {
        actuator.move_dir = PISRunFwd;           
        PIS_Extend(true, speed);
        
    } else if(diff < 0) 
    {
        actuator.move_dir = PISRunRev;
        PIS_Retract(true, speed);
    } else {
        actuator.setpoint_flag = true;
    }

    float current = 0.0f;
    bool current_stop = false;
    bool slow_speed_flag = false;

    do
    {
        float current_length = PIS_Read_length();
        sprintf(temp, "Current length = %.4f", current_length);
        Log.Debug(temp);
        float diff = current_length - length;

        if(fabs(diff) < 0.01)
        {
            DRV8874_stop();
            actuator.setpoint_flag = true;
        } 

        if(!slow_speed_flag)
        {
            if(fabs(diff) <= PISTON_SLOW_SPEED_LENGTH)
            {
                slow_speed_flag = true;
                if(actuator.move_dir == PISRunFwd)
                {
                    PIS_Extend(false, PISTON_SLOW_SPEED);
                }
                else
                {
                    PIS_Retract(false, PISTON_SLOW_SPEED);
                }
            }
        }
        current = DRV8874_read_current();
        current_stop = (current >= 0.005f);

    } while(!actuator.setpoint_flag && current_stop);

    Log.Debug("Exited do/while loop");
    PIS_Stop();

    if(current_stop == false)
    {
      sprintf(temp, "Current at stop condition = %.4f", current);
      Log.Debug(temp);
    }
    
    if(actuator.setpoint_flag)
    {
      Log.Debug("Setpoint (supposedly) reached");
    }
    _delay_ms(1000);
    sprintf(temp, "Position at stop = %.4f", ENC_Get_Length());
    /* update the length in memory map*/
    PIS_Read_length();
    Log.Debug(temp);
    
    diff = ENC_Get_Length() - length;
    sprintf(temp, "Diff = %0.4f", diff);
    Log.Debug(temp);
    
    if((actuator.setpoint_flag == true) && (current <= 0.1))
    {
        error = PISErrorStalled;
        /** Log Error Stalled */
        Log.Error("Piston stalled");
        if(actuator.move_dir == PISRunFwd)
        {
            /** Log Stalled Fwd, near full extended hard stop? */
            Log.Error("Stall near full hard stop");
        }
        else if(actuator.move_dir == PISRunRev)
        {
            /** Log Stalled Rev, near zero hard stop? */
            Log.Error("Stall near zero hard stop");
        }
    } 
    else if((actuator.setpoint_flag == false))
    {
        /** Log overshoot */
        Log.Error("Overshoot");
        error = PISErrorOvershoot;
    } 
    else {
        error = PISErrorNone;
    }
    return error;
}

/**********************************************************************************
 * Function: PIS_Run_to_volume()
 *
 *//**
 * \b Description:
 * 
 * This function runs the piston until it reaches the volume setpoint 
 * selected (within the range tolerance initially provided).
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Volume Variable must be valid
 * 
 * POST-CONDITION: Piston will be moved to selected position
 * POST-CONDITION: actuator.current_length will be updated
 * 
 * @param write is the variable selected to be written to
 * @param value is the value to write to variable.
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * ePistonRunError_t error = PIS_Run_to_volume(600.75);
 * if(error == PISErrorNone)
 * {
 *  printf("Profiler volume is now %f (in^3)", actuator.current_length);
 * }
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 * @see PIS_Run_to_length
 * @see PIS_Run_to_volume
 */
ePistonRunError_t PIS_Run_to_volume(float volume)
{
    ePistonRunError_t error = PISErrorGeneric;
    char temp[64];
    
    #ifndef TEST
    assert(volume <= SYSTEM_MAX_VOLUME);
    assert(volume >= SYSTEM_MIN_VOLUME);
    #endif
    MEM_Set_f(VOL_setpoint, volume);
    
    double length = _PIS_estimate_length_from_volume(
                        volume, 
                        &smallPiston, 
                        &largePiston,
                        &housing
                    );
    
    
    error = PIS_Run_to_length(length);
    
    sprintf(temp, "Volume at stop = %.4f", PIS_Get_Volume());
    Log.Debug(temp);
    float diff = PIS_Get_Volume() - volume;
    sprintf(temp, "Diff = %0.4f", diff);
    Log.Debug(temp);
    
    return error;
}


void PIS_Extend(bool startup, uint8_t speed)
{
    MEM_Set_u8(TRV_zero, false);
    MEM_Set_u8(TRV_full, false);
    Log.Debug("PIS_Extend called");
    if(ENC_GetDir() == DIR_RETRACT)
    {
        Log.Debug("Stopping movement before Extending");
        PIS_Stop();
    }

    ENC_SetDir(DIR_EXTEND);
    DRV8874_reverse(speed);
    MEM_Set_Travel_Direction(1);
    MEM_Set_Travel_Engage(true);
    MEM_Set_u8(TRV_eng, true);
    actuator.speed = speed;
    actuator.move_dir = PISRunFwd;
}

void PIS_Retract(bool startup, uint8_t speed)
{
    MEM_Set_u8(TRV_zero, false);
    MEM_Set_u8(TRV_full, false);
    Log.Debug("PIS_Retract called");
    if(ENC_GetDir() == DIR_EXTEND)
    {
        Log.Debug("Stopping movement before Retracting");
        PIS_Stop();
    }

    ENC_SetDir(DIR_RETRACT);
    DRV8874_forward(speed);
    MEM_Set_Travel_Direction(-1);
    MEM_Set_Travel_Engage(true);
    MEM_Set_u8(TRV_eng, true);
    actuator.speed = speed;
    actuator.move_dir = PISRunRev;
    _check_is_at_zero();
}

void PIS_Stop(void)
{
    Log.Debug("PIS_Stop called");
    DRV8874_stop();
    MEM_Set_u8(TRV_eng, false);
    MEM_Set_i8(TRV_dir, PISRunStop);
    actuator.move_dir = PISRunStop;
    MEM_Set_Travel_Engage(false);
}

void PIS_Reset_to_Zero(void)
{
    //char temp[32];
    Log.Debug("PIS_Reset_to_Zero called");
    //int32_t count = ENC_Get_count();
    PIS_Retract(true, 100);
    _delay_ms(500);

    //while( (fabs(PIS_Read_current()) > 0.05f) &&
    //(count != ENC_Get_count()) )
    while(_check_is_at_zero() == false)
    {
        //sprintf(temp, "Resetting to zero: pos = %0.4f", ENC_Get_Length());
        //Log.Debug(temp);
        PIS_Read_length();
        _delay_ms(1000);
    }
    //Log.Debug("Move Complete");
    //Log.Debug("Resetting encoder");
    ENC_Set_count(0);
    MEM_Set_u8(TRV_zero, true);
    MEM_Set_i8(TRV_dir, PISRunStop);
    MEM_Set_u8(TRV_eng, false);
}

void PIS_Run_to_Full(void)
{
    char temp[64];
    //int32_t count = ENC_Get_count();
    int32_t count = ENC_Get_max_count();
    Log.Debug("PIS_Run_to_Full called");
    PIS_Extend(true, 100);
    _delay_ms(1000);

    //sprintf(temp, "Running to full: count = %li", count);
    //Log.Debug(temp);

    while(  (fabs(PIS_Read_current()) > 0.008f) &&
            (count != ENC_Get_count()) )
    //while(  (fabs(PIS_Read_current()) > 0.000001f) &&
    //        (count != ENC_Get_count()) )
    {
        sprintf(temp, "Running to full: pos = %0.4f, count=%li, current=%.8f",
                          ENC_Get_Length(), ENC_Get_count(), PIS_Read_current());
        Log.Debug(temp);
        PIS_Read_length();
        _delay_ms(1000);
    }
    _delay_ms(1000);
    Log.Debug("Move Complete");
    Log.Debug("Resetting encoder");

    MEM_Set_u8(TRV_full, true);
    MEM_Set_i8(TRV_dir, PISRunStop);
    MEM_Set_u8(TRV_eng, false);
}

void PIS_Calibrate(uint8_t cal)
{   
    if(cal == 1)
    {
        Log.Debug("PIS_Calibrate called");
        Log.Debug("System will Zero, than run to full");
        Log.Debug("This will take a few minutes");

        PIS_Reset_to_Zero();
        PIS_Run_to_Full();

        Log.Debug("Settng max encoder count");
        ENC_Set_max_count(ENC_Get_count());

        PIS_Reset_to_Zero();
        _calibration = 1;
        MEM_Set_PST_Calibration((bool) _calibration);
        Log.Debug("*** Calibration Complete ***");
    }
    else
    {
        Log.Debug("*** Calibration variable is false ***");
    }
}

void PIS_Calibration_check(void)
{
    if (_calibration == 1)
    {
        Log.Debug("Piston is already Calibrated");
    }
    else
    {
        /* calibrate the actuator */
        Log.Debug("\n\n<< Calibration is in progress >>\n\n");
        PIS_Calibrate(1);
    }
}

/**********************************************************************************
 * Function: PIS_is_at_zero()
 *
 *//**
 * \b Description:
 * 
 * This function returns true if the actuator is fully retracted, false otherwise.
 * 
 * @param float *small Pointer to small piston length
 * @param float *large Pointer to large piston length
 * 
 * @return bool
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Extend();
 * _delay_ms(5000);
 * float small, large, total;
 * length = PIS_Get_Length(&small, &large); 
 * 
 * @endcode
 *
 */
float PIS_Get_Length(float *small, float *large)
{
    float length;
    length = PIS_Read_length();
    *small = smallPiston._length;
    *large = largePiston._length;
    return length;
}

float PIS_Get_Volume(void)
{
    return PIS_Read_volume();
}

float PIS_Get_vset(void)
{
    return MEM_Get_VOL_Setpoint();
}

float PIS_Get_volume_small(void)
{
    PIS_Read_volume();
    return smallPiston._volume;
}

float PIS_Get_volume_large(void)
{
    PIS_Read_volume();
    return largePiston._volume;
}

float PIS_Get_area_small(void)
{
    return smallPiston._area;
}

float PIS_Get_area_large(void)
{
    return largePiston._area;
}

float PIS_Get_lset(void)
{
    return MEM_Get_LEN_Setpoint();
}

int8_t PIS_Get_direction(void)
{
    return actuator.move_dir;
}


/**********************************************************************************
 * Function: PIS_is_at_zero()
 *
 *//**
 * \b Description:
 * 
 * This function returns true if the actuator is fully retracted, false otherwise.
 * 
 * 
 * @return bool
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Retract();
 * _delay_ms(50000);
 * if( PIS_is_at_zero())
 * {
 *    printf("Fully Extended");
 * } 
 * 
 * @endcode
 *
 */
bool PIS_is_at_zero(void)
{
    return actuator.at_zero;
}

/**********************************************************************************
 * Function: PIS_is_at_full()
 *
 *//**
 * \b Description:
 * 
 * This function returns true if the actuator is fully extended, false otherwise.
 * 
 * 
 * @return bool
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Extend();
 * _delay_ms(50000);
 * if( PIS_is_at_full())
 * {
 *    printf("Fully Extended");
 * } 
 * 
 * @endcode
 *
 */
bool PIS_is_at_full(void)
{
    return actuator.at_full;
}


/**********************************************************************************
 * Function: PIS_Get_encoder_count()
 *
 *//**
 * \b Description:
 * 
 * This function returns the current encoder count.
 * 
 * 
 * @return int32_t Current
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Extend();
 * _delay_ms(500);
 * PIS_Stop();
 * int32_t count = PIS_Get_encoder_count();
 * 
 * @endcode
 *
 */
int32_t PIS_Get_encoder_count(void)
{
    return ENC_Get_count();
}


/**********************************************************************************
 * Function: PIS_Get_motor_current()
 *
 *//**
 * \b Description:
 * 
 * This function returns the motor current in amps (estimate, not calibrated).
 * 
 * 
 * @return float Current
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * float current = PIS_Get_motor_current();
 * 
 * @endcode
 *
 */
float PIS_Get_motor_current(void)
{
    return DRV8874_read_current();
}

bool PIS_is_moving(void)
{
    if( fabs(DRV8874_read_current() > 0.05) &&
        actuator.move_dir != PISRunStop)
    {
        MEM_Set_u8(TRV_zero, false);
        MEM_Set_u8(TRV_full, false);
        return true;
    }
    else
    {
        return false;
    }
}


/**********************************************************************************
 * Function: PIS_Write_length()
 *
 *//**
 * \b Description:
 * 
 * This function writes the value to length variable.
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Length must be valid
 * 
 * POST-CONDITION: actuator.enc_min is updated
 * POST-CONDITION: actuator.enc_max is updated
 * 
 * @param write is the variable selected to be written to
 * @param value is the value to write to variable.
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Write_length(10.2);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC void PIS_Write_length(double setpoint) {
    #ifndef TEST
    assert(setpoint >= 0.0f);
    assert(setpoint <= (smallPiston._max_length + largePiston._max_length) );
    #endif 

    actuator.setpoint = setpoint;
    _PIS_calc_encoder_range(
        setpoint, 
        actuator._range,
        actuator._conversion_factor,
        &actuator.enc_min,
        &actuator.enc_max
        );
}

/**********************************************************************************
 * Function: PIS_Write_volume()
 *
 *//**
 * \b Description:
 * 
 * This function writes the value to volume variable.
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Volume must be valid
 * 
 * POST-CONDITION: actuator.enc_min is updated
 * POST-CONDITION: actuator.enc_max is updated
 * 
 * @param value is the vvolume to set.
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Write_length(10.2);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
//STATIC void PIS_Write_volume(double volume)
//{
//   double length = _PIS_estimate_length_from_volume(
//                                        volume,
//                                        &smallPiston, 
//                                        &largePiston,
//                                        &housing
//                                        );
//
//    PIS_Write_length(length);
//}

/**********************************************************************************
 * Function: PIS_Read_length()
 *
 *//**
 * \b Description:
 * 
 * This function reads the current length value.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return Current piston length.
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * double length = PIS_Read_length();
 * printf("The piston length is %f", length);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC double PIS_Read_length(void) {  
    double length = ENC_Get_Length();
    if( (length > 0.0f) && (length <= smallPiston._max_length))
    {
        smallPiston._length = length;
        largePiston._length = 0.0f;
    } else if( (length > 0.0f) && (length < (smallPiston._max_length + largePiston._max_length)))
    {
        smallPiston._length = smallPiston._max_length;
        largePiston._length = length - smallPiston._max_length;
    } else if( (length > 0.0f) && (length <= (smallPiston._max_length + largePiston._max_length)))
    {
        smallPiston._length = smallPiston._max_length;
        largePiston._length = smallPiston._max_length;
    } else if( length == 0) {
        smallPiston._length = 0.0f;
        largePiston._length = 0.0f;
    }
    
    smallPiston._volume = smallPiston._length * SMALL_PISTON_RADIUS_SQR * PI;
    largePiston._volume = largePiston._length * LARGE_PISTON_RADIUS_SQR * PI;
    //smallPiston._volume = smallPiston._length * smallPiston._diameter * PI;
    //largePiston._volume = largePiston._length * largePiston._diameter * PI;
    float total = housing._volume + smallPiston._volume + largePiston._volume;
    
    MEM_Set_f(VOL_small_piston, smallPiston._volume);
    MEM_Set_f(VOL_large_piston, largePiston._volume);
    MEM_Set_f(VOL_total, total);
    
    MEM_Set_f(LEN_small_piston, smallPiston._length);
    MEM_Set_f(LEN_large_piston, largePiston._length);
    MEM_Set_f(LEN_total, length);
    
    return length;
}

/**********************************************************************************
 * Function: PIS_Read_volume()
 *
 *//**
 * \b Description:
 * 
 * This function reads the current volume value.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return Current piston length.
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * double length = PIS_Read_length();
 * printf("The piston length is % in.f\n", length);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC double PIS_Read_volume(void)
{
    PIS_Read_length();
    //smallPiston._volume = smallPiston._length * smallPiston._diameter * PI;
    //largePiston._volume = largePiston._length * largePiston._diameter * PI;
    //float total = housing._volume + smallPiston._volume + largePiston._volume;

    ////char temp[64] = {0};
    ////sprintf(temp, "H=%.4f, L=%.4f, S=%.4f, T=%.4f", housing._volume, largePiston._volume, smallPiston._volume, total);
    ////Log.Debug(temp);

    //MEM_Set_f(VOL_small_piston, smallPiston._volume);
    //MEM_Set_f(VOL_large_piston, largePiston._volume);
    //MEM_Set_f(VOL_housing, housing._volume);
    //MEM_Set_f(VOL_total, total);

    return MEM_Get_VOL_Total();
    //return total;
}

/**********************************************************************************
 * Function: PIS_Read_current()
 *
 *//**
 * \b Description:
 * 
 * This function reads the current current value.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return Current drive current.
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * double current = PIS_Read_current(); // Static function, only call from this module
 * printf("The piston drawing %f amps\n", current);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC float PIS_Read_current(void) {
    return DRV8874_read_current();
}

/** @brief Calculate the min/max encoder count 
 * 
 * Determine what the min/max encoder count is in order
 * to preserve 
 * @param setpoint Setpoint (length) to send piston to
 * @param _conversion_factor 
 * @param *settings Pointer to minimum
 */
STATIC void _PIS_calc_encoder_range(double setpoint, 
                        double range, 
                        double _conversion_factor,
                        int32_t *min_cnt,
                        int32_t *max_cnt
                        ) 
{
    double min = (setpoint - range) * _conversion_factor;
    double max = (setpoint + range) * _conversion_factor;
    
    *min_cnt = (int32_t) min;
    *max_cnt = (int32_t) max; 
    
}


/**@brief Calculate Length from Volume
 * 
 * Calculate the necessary length of the piston
 * by finding the volume of each component.
 * 
 * @param volume Volume required
 * @param sPistonVolume_t *small Pointer to small piston struct
 * @param sPistonVolume_t *large Pointer to large piston struct
 * @param sPistonVolume_t *housing Pointer to housing struct
 * 
 * @return length
 */
STATIC double _PIS_estimate_length_from_volume(
     double volume,
     const sPistonVolume_t *small,
     const sPistonVolume_t *large,
     const sPistonVolume_t *housing
     )
{
    double length = 0.0f;
    
    #ifndef TEST
    assert( volume >= housing->_max_volume);
    assert( volume <= (housing->_max_volume + small->_max_volume + large->_max_volume));
    #endif

    if((volume <= housing->_max_volume+0.001) && (volume >= housing->_max_volume-0.001))
    {
        length = 0.0f;
    }
    else if (volume <= (housing->_max_volume + small->_max_volume))
    {
        volume -= housing->_max_volume;
        //length = volume / (small->_diameter * PI);
        length = volume / (SMALL_PISTON_RADIUS_SQR * PI);
    }
    else if (volume <= (housing->_max_volume + small->_max_volume + large->_max_volume + 0.1))
    {
        volume -= (housing->_max_volume + small->_max_volume);
        //length = (volume / (large->_diameter*PI)) + small->_max_length;
        length = (volume / (LARGE_PISTON_RADIUS_SQR*PI)) + small->_max_length;
    } else {
        length =  -1.0f;
    }
    return length;
}


/** @brief Calculate Volume from Length
 * 
 * Calculate the system volume from the given length
 * 
 * @param length Length of piston
 * @param sPistonVolume_t *small Pointer to small piston struct
 * @param sPistonVolume_t *large Pointer to large piston struct
 * @param sPistonVolume_t *housing Pointer to housing struct
 * 
 * @return volume
 */
STATIC double _PIS_calculate_volume_from_length(
    double length,
    const sPistonVolume_t *small,
    const sPistonVolume_t *large,
    const sPistonVolume_t *housing
     )
{
    double volume = -1.0f;

    #ifndef TEST
    assert(length >= 0.0f);
    assert(length <= housing->_max_length + small->_max_length + large->_max_length);
    #endif
    
    if(length == 0.0f)
    {
        volume = housing->_max_volume;
    }
    else if((length <= small->_max_length) && (length > 0.0f))
    {
        //volume = housing->_max_volume + (small->_diameter * PI * length);
        volume = housing->_max_volume + (SMALL_PISTON_RADIUS_SQR * PI * length);
    }
    else if( (length <= (small->_max_length + large->_max_length)) && (length > 0))
    {
        length -= small->_max_length;
        //volume = housing->_max_volume + small->_max_volume + (large->_diameter * PI * length);
        volume = housing->_max_volume + small->_max_volume + (LARGE_PISTON_RADIUS_SQR * PI * length);
    } else {
        length = -1.0f;
    }

    return volume;
}

/**********************************************************************************
 * Function: _PIS_Run()
 *
 *//**
 * \b Description:
 * 
 * This function starts the piston running based on direction provided.
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Piston must be enabled
 * PRE-CONDITION: Direction must be valid
 * 
 * POST-CONDITION: Piston is in motion (unless stop is called)
 * 
 * @param dir is the Direction to move the piston
 * 
 * @return None
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * _PIS_Run(PISRunFwd); //Static Function, only call within this module 
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
//STATIC void _PIS_Run(ePistonRunDir_t dir)
//{
//    switch(dir)
//    {
//        case PISRunFwd:
//            DRV8874_forward(100);
//            break;
//        case PISRunRev:
//            DRV8874_reverse(100);
//            break;
//        case PISRunStop:
//            DRV8874_stop();
//            break;
//        default:
//            break;
//    }
//}

/**********************************************************************************
 * Function: _check_is_at_zero()
 *
 *//**
 * \b Description:
 * 
 * This function starts checks to see if the piston is at the zero .
 * 
 * PRE-CONDITION: Piston must be in a commanded movement state
 * PRE-CONDITION: Piston must be enabled
 * 
 * POST-CONDITION: No change
 *  
 * @return bool True=At Zero, False= Not at Zero
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * PIS_Retract();
 * while(_check_is_at_zero() == false);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC bool _check_is_at_zero(void)
{
    
  int32_t count = ENC_Get_count();
  _delay_ms(1);
  
  // MUST BE CALLED WHILE IN MOTION
  if( (PIS_Read_current()> 0.05) && (count != ENC_Get_count()) )
  {
    MEM_Set_u8(TRV_zero, false);
    return false;
  } else {
    MEM_Set_u8(TRV_zero, true);
    return true;
  }

}
