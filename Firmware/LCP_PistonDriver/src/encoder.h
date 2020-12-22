#ifndef _ENCODER_H
#define _ENCODER_H

#include <stdint.h>
#include <stdbool.h>
#include "bsp/bsp.h"
#include "bsp/bsp_esi.h"
#include "config.h"


/** Remove STATIC and PERSISTENT values if running TEST */
/** Add the actual values if running release */
#ifdef TEST
#ifndef STATIC
#define STATIC  
#endif
#ifndef PERSISTENT
#define PERSISTENT
#endif
#else
#ifndef STATIC
#define STATIC  static
#endif
#ifndef PERSISTENT
#define PERSISTENT __persistent 
#endif
#endif

#define ENCODER_MIN_COUNT_DEFAULT   SYS_ENCODER_MIN_COUNT_DEFAULT
#define ENCODER_MAX_COUNT_DEFAULT   SYS_ENCODER_MAX_COUNT_DEFAULT
#define ENCODER_LENGTH_DEFAULT      SYS_ENCODER_LENGTH_DEFAULT

/** 
 * @brief Encoder Settings Struct
 * @struct Encoder Settings
 */
typedef struct EncoderSettings {
    int32_t min_count;     /**< Minimum Counter setting (Default=0) */
    int32_t max_count;     /**< Maximum Counter setting (Default=type of piston) */
    int32_t distance;       /**< Difference between max and min counts */
    float length;           /**< Length to calculate conversion factor */
    float conversion_factor;    /**< Conversion factor to calculate "length" */
}sEncoderSettings_t;

void ENC_Init(void);
void ENC_FactoryReset(void);
void ENC_Set_Length(float val) ;


#ifdef TEST
extern volatile int32_t g_encoder_counter;
extern sEncoderSettings_t encSettings;
#endif

#ifdef TEST
void _clear_enc_counter(void);
void _set_max_enc_counter(void);
bool _set_min_count(int32_t val);
bool _set_max_count(int32_t val);
void _calculate_encoder_distance(void);
float _calculate_length(void);
#endif

#endif // _ENCODER_H
