#include "encoder.h"

STATIC PERSISTENT volatile int32_t g_encoder_counter;
STATIC PERSISTENT sEncoderSettings_t encSettings = {
    .min_count = ENCODER_MIN_COUNT_DEFAULT,
    .max_count = ENCODER_MAX_COUNT_DEFAULT,
    .distance = ENCODER_MAX_COUNT_DEFAULT - ENCODER_MIN_COUNT_DEFAULT,
    .length = ENCODER_LENGTH_DEFAULT,
    .conversion_factor = (ENCODER_LENGTH_DEFAULT / ENCODER_MAX_COUNT_DEFAULT)
};


void ENC_Init(void) {
    esiConfig();
}

float ENC_Get_Length(void)
{
    assert(encSettings.distance > 0);
    return _calculate_length();
}

void ENC_Set_MaxLength(float val) {
     _calculate_encoder_distance();
    assert(encSettings.distance > 0);
    encSettings.length = val;
    encSettings.conversion_factor = val / encSettings.distance;
}

void ENC_FactoryReset(void) {
    encSettings.min_count = ENCODER_MIN_COUNT_DEFAULT;
    encSettings.max_count = ENCODER_MAX_COUNT_DEFAULT;
    // encSettings.distance = ENCODER_MAX_COUNT_DEFAULT - ENCODER_MIN_COUNT_DEFAULT;
    // encSettings.length = ENCODER_LENGTH_DEFAULT;
    // encSettings.conversion_factor = (ENCODER_LENGTH_DEFAULT / ENCODER_MAX_COUNT_DEFAULT);
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

STATIC float _calculate_length(void) {
    
   
    // float temp = (float) (g_encoder_counter - encSettings.min_count); // / encSettings.distance;
    // printf("%f, %f", encSettings.length, encSettings.conversion_factor); 
    // temp *= encSettings.conversion_factor;

    int32_t temp_u = g_encoder_counter - encSettings.min_count;

    printf("%ld, %ld", temp_u, encSettings.distance);
    float temp_f = (float) temp_u;
    temp_f *= encSettings.conversion_factor;
    return temp_f;
}