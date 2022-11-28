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
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#define PERSISTENT __persistent 
#elif defined(__GNUC__)
#define PERSISTENT __attribute__((section (".persistent")))
#endif
#endif
#endif

#define ENCODER_MIN_COUNT_DEFAULT   SYS_ENCODER_MIN_COUNT_DEFAULT
#define ENCODER_MAX_COUNT_DEFAULT   SYS_ENCODER_MAX_COUNT_DEFAULT
#define ENCODER_LENGTH_DEFAULT      SYS_ENCODER_LENGTH_DEFAULT


/** @brief Piston Type
 * @enum Piston Type
 */
typedef enum ePistonType {
    SMALL_PISTON,
    LARGE_PISTON,
    NO_PISTON
}ePistionType_t;

typedef enum ePistonDir {
  DIR_EXTEND = 1,
  DIR_RETRACT = -1
}ePistonDir_t;

/** 
 * @brief Encoder Settings Struct
 * @struct Encoder Settings
 */
typedef struct EncoderSettings {
    int32_t min_count;     /**< Minimum Counter setting (Default=0) */
    int32_t max_count;     /**< Maximum Counter setting (Default=type of piston) */
    int32_t distance;       /**< Difference between max and min counts */
    volatile int32_t *current_count;  /**< Current encoder count */
    double length;           /**< Length to calculate conversion factor */
     double conversion_factor;    /**< Conversion factor to calculate "length" */
    // (void*) (function)(void);
}sEncoderSettings_t;


extern sEncoderSettings_t encSettings;
extern sEncoderSettings_t *pEncSettings;

void ENC_Init(void);
void ENC_FactoryReset(void);
double ENC_Get_Length(void);
void ENC_Set_MaxLength(double val) ;
void ENC_Increment(void);
void ENC_Decrement(void);
void ENC_Set_count(int32_t val);
void ENC_Set_max_count(int32_t val);
int32_t ENC_Get_count(void);
int32_t ENC_Get_min_count(void);
int32_t ENC_Get_max_count(void);
void ENC_SetDir(ePistonDir_t dir);
int8_t ENC_GetDir(void);

extern volatile int32_t g_encoder_direction;

#ifdef TEST
extern volatile int32_t g_encoder_counter;


#endif

#ifdef TEST
void _clear_enc_counter(void);
void _set_max_enc_counter(void);
bool _set_min_count(int32_t val);
bool _set_max_count(int32_t val);
void _calculate_encoder_distance(void);
double _calculate_length(void);
#endif

#endif // _ENCODER_H
