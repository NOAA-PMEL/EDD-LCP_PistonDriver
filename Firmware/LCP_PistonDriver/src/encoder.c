#include "encoder.h"

STATIC PERSISTENT volatile int32_t g_encoder_counter;
STATIC PERSISTENT sEncoderSettings_t encSettings = {
    .min_count = ENCODER_MIN_COUNT_DEFAULT,
    .max_count = ENCODER_MAX_COUNT_DEFAULT,
    .distance = ENCODER_MAX_COUNT_DEFAULT - ENCODER_MIN_COUNT_DEFAULT,
    .length = ENCODER_LENGTH_DEFAULT,
 };

STATIC PERSISTENT sEncoderSettings_t *pEncSettings = &encSettings;

void ENC_Init(void) {
    esiConfig();
}

double ENC_Get_Length(void)
{
    assert(encSettings.distance > 0);
    return _calculate_length();
}

void ENC_Set_MaxLength(double val) {
     _calculate_encoder_distance();
    assert(encSettings.distance > 0);
    encSettings.length = val;
    encSettings.conversion_factor = encSettings.length / encSettings.distance;
}

void ENC_FactoryReset(void) {
    encSettings.min_count = ENCODER_MIN_COUNT_DEFAULT;
    encSettings.max_count = ENCODER_MAX_COUNT_DEFAULT;
    ENC_Set_MaxLength(ENCODER_LENGTH_DEFAULT);
}

STATIC bool _set_min_count(int32_t val) {
    if( val < 0 ) 
    {
        return false;
    }
    encSettings.min_count = val;
    return true;
}

STATIC bool _set_max_count(int32_t val)
{
    if( (val < 0) || (val < encSettings.min_count) )
    {
        return false;
    }

    encSettings.max_count = val;
    return true;
}

STATIC void _clear_enc_counter(void) {
    g_encoder_counter = encSettings.min_count;
}

STATIC void _set_max_enc_counter(void) {
    g_encoder_counter = encSettings.max_count;
}

STATIC void _calculate_encoder_distance(void) {
    
    encSettings.distance = encSettings.max_count - encSettings.min_count;
}

STATIC double _calculate_length(void) 
{
    int32_t temp_u = g_encoder_counter - encSettings.min_count;
    double temp_f = (double) temp_u;
    temp_f *= encSettings.conversion_factor;
    return temp_f;
}