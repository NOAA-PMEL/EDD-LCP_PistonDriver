/** @file "piston.c"
 * @brief Piston control
 */

/**********************************************************************************
 * Includes
 *********************************************************************************/
#include "piston.h"

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
    ._max_volume = SMALL_PISTON_DIAMETER * PI *SMALL_PISTON_MAX_LENGTH
};

/**
 * Define the struct for the Large Diameter PIston
 */
STATIC PERSISTENT sPistonVolume_t largePiston = {
    ._volume = 0,
    ._length = 0,
    ._diameter = LARGE_PISTON_DIAMETER,
    ._max_length = LARGE_PISTON_MAX_LENGTH,
    ._max_volume = LARGE_PISTON_DIAMETER * PI * LARGE_PISTON_MAX_LENGTH
};

/**
 * Defines the struct for the Housing
 */
STATIC const sPistonVolume_t housing = {
    ._volume = HOUSING_LENGTH * HOUSING_DIAMETER * PI,
    ._length = HOUSING_LENGTH,
    ._diameter = HOUSING_DIAMETER,
    ._max_length = HOUSING_LENGTH,
    ._max_volume = HOUSING_DIAMETER * PI * HOUSING_LENGTH
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
STATIC sPistonSystem_t profiler = {
    .volume = 0,
    .actuator = &actuator,
    .smallPiston = &smallPiston,
    .largePiston = &largePiston,
    .housing = &housing
};


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
    DRV8874_init();
    ENC_Init();
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
void PIS_Write(ePistonWrite_t write, double value)
{
    switch(write)
    {
        case PISWriteLength:
            
            break;
        case PISWriteVolume:

            break;
        default:
        /** @todo Add Logging Error */
            break;
    }
}

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
ePistonRunError_t PIS_Run_to_length(double length)
{
    #ifndef TEST
    assert(length <= SYSTEM_MAX_LENGTH);
    assert(length >= SYSTEM_MIN_LENGTH);
    #endif

    ePistonRunError_t error = PISErrorGeneric;
    /** Update the setpoint and encoder range */
    PIS_Write_length(length);

    actuator.setpoint_flag = false;
    if(length > actuator.current_length)
    {
        DRV8874_forward();
        actuator.move_dir = PISRunFwd;
    } else if(length < actuator.current_length)
    {
        DRV8874_reverse();
    } else {
        actuator.setpoint_flag = true;
    }

    float current = 0.0f;
    do{
        #ifdef TEST
        actuator.setpoint_flag = true;
        #endif
        //* @todo Add sleep function */
        current = DRV8847_read_current();
        if( (actuator.move_dir == PISRunFwd) && \
            (length < actuator.current_length))
        {
            DRV8874_stop();
            break;
        }

    }while((actuator.setpoint_flag != true) && (current >= 0.1f));

    // printf("%i, %f", actuator.setpoint_flag, current);
    if((actuator.setpoint_flag == true) && (current <= 0.1))
    {
        // printf("In Error");
        error = PISErrorStalled;
        /** Log Error Stalled */
        if(actuator.move_dir == PISRunFwd)
        {
            /** Log Stalled Fwd, near full extended hard stop? */
        }
        else if(actuator.move_dir == PISRunRev)
        {
            /** Log Stalled Rev, near zero hard stop? */
        }
    } 
    else if((actuator.setpoint_flag == false))
    {
        /** Log overshoot */
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
ePistonRunError_t PIS_Run_to_volume(double volume)
{
    ePistonRunError_t error = PISErrorGeneric;

    #ifndef TEST
    assert(volume <= SYSTEM_MAX_VOLUME);
    assert(volume >= SYSTEM_MIN_VOLUME);
    #endif

    double length = _PIS_estimate_length_from_volume(
                        volume, 
                        &smallPiston, 
                        &largePiston,
                        &housing
                    );

    // printf("vol=%f, len=%f, cl=%f\n", volume, length, actuator.current_length);
    return PIS_Run_to_length(length);
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
STATIC void PIS_Write_volume(double volume)
{
   double length = _PIS_estimate_length_from_volume(
                                        volume,
                                        &smallPiston, 
                                        &largePiston,
                                        &housing
                                        );

    PIS_Write_length(length);
}

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
    } else if( (length > 0.0f) && (length <= (smallPiston._max_length + largePiston._max_length)))
    {
        smallPiston._length = smallPiston._max_length;
        largePiston._length = length - smallPiston._max_length;
    } else if( length == 0) {
        smallPiston._length = 0.0f;
        largePiston._length = 0.0f;
    }
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
STATIC double PIS_Read_volume(void) { 
    PIS_Read_length();
    smallPiston._volume = smallPiston._length * smallPiston._diameter * PI;
    largePiston._volume = largePiston._length * largePiston._diameter * PI;
    return housing._volume + smallPiston._volume + largePiston._volume;
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
    return DRV8847_read_current();
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
    // printf("Volume=%f, max=%f ",volume, (housing->_max_volume + small->_max_volume + large->_max_volume + actuator._range));

    if((volume <= housing->_max_volume+0.001) && (volume >= housing->_max_volume-0.001))
    {
        length = 0.0f;
        // printf("Housing Only: length=%f\n", length);
    }
    else if (volume <= (housing->_max_volume + small->_max_volume))
    {
        volume -= housing->_max_volume;
        length = volume / (small->_diameter * PI);
        
        // printf("Housing + Small: length=%f\n", length);
        // return length;
    }
    else if (volume <= (housing->_max_volume + small->_max_volume + large->_max_volume + 0.1))
    {
        volume -= (housing->_max_volume + small->_max_volume);
        length = (volume / (large->_diameter*PI)) + small->_max_length;
        // printf("Housing + Both: length=%f\n", length);
        // return length;
    } else {
        // printf("Nothin");
        length =  -1.0f;
    }
    // else if

    // printf("\nLength=%f", length);
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
        volume = housing->_max_volume + (small->_diameter * PI * length);
    }
    else if( (length <= (small->_max_length + large->_max_length)) && (length > 0))
    {
        length -= small->_max_length;
        volume = housing->_max_volume + small->_max_volume + (large->_diameter * PI * length);
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
STATIC void _PIS_Run(ePistonRunDir_t dir)
{
    switch(dir)
    {
        case PISRunFwd:
            DRV8874_forward();
            break;
        case PISRunRev:
            DRV8874_reverse();
            break;
        case PISRunStop:
            DRV8874_stop();
            break;
        default:
            break;
    }
}