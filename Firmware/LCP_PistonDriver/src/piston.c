#include "piston.h"


STATIC PERSISTENT sPistonVolume_t smallPiston = {
    .volume = 0,
    ._length = 0,
    ._diameter = SMALL_PISTON_DIAMETER,
    ._max_length = SMALL_PISTON_MAX_LENGTH
};

STATIC PERSISTENT sPistonVolume_t largePiston = {
    .volume = 0,
    ._length = 0,
    ._diameter = LARGE_PISTON_DIAMETER,
    ._max_length = LARGE_PISTON_MAX_LENGTH
    ._max_volume = 
};

STATIC const sPistonVolume_t housing = {
    .volume = HOUSING_LENGTH * HOUSING_DIAMETER * PI,
    ._length = HOUSING_LENGTH,
    ._diameter = HOUSING_DIAMETER,
    ._max_length = HOUSING_LENGTH
};

STATIC sPiston_t piston = {
    .length = 0.0f,
    .setpoint = 0.0f
};
    

STATIC sSystemVolume_t profiler = {
    .volume = 0,
    .pistonLength = 0,
    .smallPiston = &smallPiston,
    .largePiston = &largePiston,
    .housing = &housing
};

void PIS_init(void) {

    DRV8874_init();
    ENC_Init();

}

void PIS_set_length(double position)
{

}



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