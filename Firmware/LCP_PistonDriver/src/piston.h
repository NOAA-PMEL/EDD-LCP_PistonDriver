#ifndef _PISTON_H
#define _PISTON_H


#include <stdint.h>
#include "config.h"
#include "encoder.h"
#include "DRV8874.h"

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

#define SMALL_PISTON_DIAMETER     (SYS_SMALL_PISTON_DIAMETER)
#define SMALL_PISTON_MAX_LENGTH   (SYS_SMALL_PISTON_MAX_LENGTH)
#define LARGE_PISTON_DIAMETER     (SYS_LARGE_PISTON_DIAMETER)
#define LARGE_PISTON_MAX_LENGTH   (SYS_LARGE_PISTON_MAX_LENGTH)
#define HOUSING_DIAMETER          (SYS_HOUSING_DIAMETER)
#define HOUSING_LENGTH            (SYS_HOUSING_LENGTH)

#define PI                      ( 3.14159265359)

typedef struct sPistonVolume {
    double volume;
    double _length;      /**< Length of piston */
    double _diameter;    /**< Diameter of piston */
    double _max_length;  /**< Maximum length of piston */
}sPistonVolume_t;

typedef struct sLength {
    sEncoderSettings_t *encoder;    /**< Current encoder settings */
    volatile double length;         /**< Length to calculate conversion factor */
    double conversion_factor;       /**< Conversion factor to calculate "length" cnt/in */
}sLength_t;

typedef struct sPiston {
    sEncoderSettings_t *settings;   /**< Encoder Settings */
    volatile double length;         /**< Current Length of piston */
    double setpoint;                /**< Current setpoint for piston */ 
}sPiston_t;

typedef struct sSystemVolume {
    double volume;                   /**< Volume of the system */
    sLength_t *pistonLength;         /**< Piston Length */
    sPistonVolume_t *smallPiston;    /**< Small Piston Volume */
    sPistonVolume_t *largePiston;    /**< Large Piston Volume */
    const sPistonVolume_t *housing;        /**< Housing Volume */
}sSystemVolume_t;


void PIS_init(void);

#ifdef TEST
void _PIS_calc_encoder_range(double setpoint, 
                        double range, 
                        double conversion_factor,
                        int32_t *min_cnt,
                        int32_t *max_cnt
                        );
#endif

#endif // _PISTON_H
