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
    .setpoint = 0.0f
};

STATIC sPistonSystem_t profiler = {
    .volume = 0,
    .actuator = &actuator,
    .smallPiston = &smallPiston,
    .largePiston = &largePiston,
    .housing = &housing
};

void PIS_init(void) {

    DRV8874_init();
    ENC_Init();

}


double PIS_get_length(void) {
    double length = ENC_Get_Length();
    if( (length > 0.0f) && (length <= smallPiston._max_length))
    {
        smallPiston._length = length;
    } else if( (length > 0.0f) && (length <= (smallPiston._max_length + largePiston._max_length)))
    {
        smallPiston._length = smallPiston._max_length;
        largePiston._length = length - smallPiston._max_length;
    }
    return length;
}
double PIS_get_volume(void) {

    return -1.0f;

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

    if(volume == housing->_max_volume)
    {
        length = 0.0f;
    }
    else if (volume <= (housing->_max_volume + small->_max_volume))
    {
        volume -= housing->_max_volume;
        length = volume / (small->_diameter * PI);
        return length;
    }
    else if (volume <= (housing->_max_volume + small->_max_volume + large->_max_volume))
    {
        volume -= (housing->_max_volume + small->_max_volume);
        length = (volume / (large->_diameter*PI)) + small->_max_length;
        return length;
    } else {
        length =  -1.0f;
    }
    // else if
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