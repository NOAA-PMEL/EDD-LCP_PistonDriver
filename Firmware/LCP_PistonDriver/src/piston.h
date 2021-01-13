#ifndef _PISTON_H
#define _PISTON_H


#include <stdint.h>
#include <assert.h>
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
    double _volume;
    double _length;      /**< Length of piston */
    double _diameter;    /**< Diameter of piston */
    double _max_length;  /**< Maximum length of piston */
    double _max_volume;  /**< Maximum volume of piston */
}sPistonVolume_t;

typedef struct sActuator {
    sEncoderSettings_t *settings;    /**< Current encoder settings */
    volatile double current_length;         /**< Length to calculate conversion factor */
    double conversion_factor;       /**< Conversion factor to calculate "length" cnt/in */
    double setpoint;
}sActuator_t;

// typedef struct sPiston {
//     sEncoderSettings_t *settings;   /**< Encoder Settings */
//     volatile double length;         /**< Current Length of piston */
//     double setpoint;                /**< Current setpoint for piston */ 
// }sPiston_t;

typedef struct sPistonSystem {
    double volume;                   /**< Volume of the system */
    sActuator_t *actuator;         /**< Piston Length */
    sPistonVolume_t *smallPiston;    /**< Small Piston Volume */
    sPistonVolume_t *largePiston;    /**< Large Piston Volume */
    const sPistonVolume_t *housing;        /**< Housing Volume */
}sPistonSystem_t;


void PIS_init(void);
double PIS_get_length(void);
double PIS_get_volume(void);

#ifdef TEST
extern sPistonVolume_t smallPiston;
extern sPistonVolume_t largePiston;
extern const sPistonVolume_t housing;
void _PIS_calc_encoder_range(double setpoint, 
                        double range, 
                        double conversion_factor,
                        int32_t *min_cnt,
                        int32_t *max_cnt
                        );

double _PIS_estimate_length_from_volume(
     double volume,
     const sPistonVolume_t *small,
     const sPistonVolume_t *large,
     const sPistonVolume_t *housing
     );

double _PIS_calculate_volume_from_length(
    double length,
    const sPistonVolume_t *small,
    const sPistonVolume_t *large,
    const sPistonVolume_t *housing
     );
#endif

#endif // _PISTON_H
