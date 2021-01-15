#include "piston.h"


STATIC PERSISTENT sPistonVolume_t smallPiston = {
    ._volume = 0,
    ._length = 0,
    ._diameter = SMALL_PISTON_DIAMETER,
    ._max_length = SMALL_PISTON_MAX_LENGTH,
    ._max_volume = SMALL_PISTON_DIAMETER * PI *SMALL_PISTON_MAX_LENGTH
};

STATIC PERSISTENT sPistonVolume_t largePiston = {
    ._volume = 0,
    ._length = 0,
    ._diameter = LARGE_PISTON_DIAMETER,
    ._max_length = LARGE_PISTON_MAX_LENGTH,
    ._max_volume = LARGE_PISTON_DIAMETER * PI * LARGE_PISTON_MAX_LENGTH
};

STATIC const sPistonVolume_t housing = {
    ._volume = HOUSING_LENGTH * HOUSING_DIAMETER * PI,
    ._length = HOUSING_LENGTH,
    ._diameter = HOUSING_DIAMETER,
    ._max_length = HOUSING_LENGTH,
    ._max_volume = HOUSING_DIAMETER * PI * HOUSING_LENGTH
};

// STATIC sPiston_t piston = {
//     .length = 0.0f,
//     .setpoint = 0.0f,
// };

STATIC sActuator_t actuator = {
    // .settings = &encSettings,
    .current_length = 0.0f,
    .setpoint = 0.0f,
    .enc_min = 0.0f,
    .enc_max = 0.0f
};

STATIC sPistonSystem_t profiler = {
    .volume = 0,
    .actuator = &actuator,
    .smallPiston = &smallPiston,
    .largePiston = &largePiston,
    .housing = &housing
};

void PIS_Init(void) {

    DRV8874_init();
    ENC_Init();

}

void PIS_Enable(void) {
    DRV8874_enable();
}

void PIS_Disable(void) {
    DRV8874_disable();   
}

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

ePistonRunError_t PIS_Run_to_length(double length)
{
    #ifndef TEST
    assert(length <= SYSTEM_MAX_LENGTH);
    assert(length >= SYSTEM_MIN_LENGTH);
    #endif
    
    ePistonRunError_t error = PISErrorGeneric;

    actuator.setpoint_flag = false;
    if(length > actuator.current_length)
    {
        DRV8874_forward();
        actuator.move_dir = PISRunFwd;
    }

    float current = 0.0f;
    do{
        #ifdef TEST
        actuator.setpoint_flag = true;
        #endif
        //* @todo Add sleep function */
        current = DRV8847_read_current();

    }while((actuator.setpoint_flag != true) && (current >= 0.1f));

    // printf("%i, %f", actuator.setpoint_flag, current);
    if(current <= 0.1)
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
    } else {
        error = PISErrorNone;
    }
    return error;
}
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

void PIS_Write_length(double setpoint) {
    #ifndef TEST
    assert(setpoint >= 0.0f);
    assert(setpoint <= smallPiston._max_length + largePiston._max_length);
    #endif 

    actuator.setpoint = setpoint;
    _PIS_calc_encoder_range(
        setpoint, 
        actuator.range,
        actuator.conversion_factor,
        &actuator.enc_min,
        &actuator.enc_max
        );
}

void PIS_Write_volume(double volume)
{
   double length = _PIS_estimate_length_from_volume(
                                        volume,
                                        &smallPiston, 
                                        &largePiston,
                                        &housing
                                        );

    PIS_Write_length(length);
}

double PIS_Read_length(void) {
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

double PIS_Read_volume(void) { 
    PIS_Read_length();
    smallPiston._volume = smallPiston._length * smallPiston._diameter * PI;
    largePiston._volume = largePiston._length * largePiston._diameter * PI;
    return housing._volume + smallPiston._volume + largePiston._volume;
}

float PIS_Read_current(void) {
    return DRV8847_read_current();
}

// void PIS_set_length(double position)
// {

// }



/** @brief Calculate the min/max encoder count 
 * 
 * Determine what the min/max encoder count is in order
 * to preserve 
 * @param setpoint Setpoint (length) to send piston to
 * @param conversion_factor 
 * @param *settings Pointer to minimum
 */
STATIC void _PIS_calc_encoder_range(double setpoint, 
                        double range, 
                        double conversion_factor,
                        int32_t *min_cnt,
                        int32_t *max_cnt
                        ) 
{
    double min = (setpoint - range) * conversion_factor;
    double max = (setpoint + range) * conversion_factor;
    
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
    // printf("Volume=%f, max=%f ",volume, (housing->_max_volume + small->_max_volume + large->_max_volume + actuator.range));

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