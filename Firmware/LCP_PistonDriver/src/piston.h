#ifndef _PISTON_H
#define _PISTON_H


#include <stdint.h>
#include <stdbool.h>
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

#define PI                      ( 3.14159265359)

#define SMALL_PISTON_DIAMETER     (SYS_SMALL_PISTON_DIAMETER)
#define SMALL_PISTON_MAX_LENGTH   (SYS_SMALL_PISTON_MAX_LENGTH)
#define SMALL_PISTON_MAX_VOLUME   (SMALL_PISTON_DIAMETER * PI * SMALL_PISTON_MAX_LENGTH)
#define LARGE_PISTON_DIAMETER     (SYS_LARGE_PISTON_DIAMETER)
#define LARGE_PISTON_MAX_LENGTH   (SYS_LARGE_PISTON_MAX_LENGTH)
#define LARGE_PISTON_MAX_VOLUME   (LARGE_PISTON_DIAMETER * PI * LARGE_PISTON_MAX_LENGTH)
#define HOUSING_DIAMETER          (SYS_HOUSING_DIAMETER)
#define HOUSING_LENGTH            (SYS_HOUSING_LENGTH)
#define HOUSING_VOLUME            (HOUSING_DIAMETER * PI * HOUSING_LENGTH)
#define SYSTEM_MAX_VOLUME         (HOUSING_VOLUME + SMALL_PISTON_MAX_VOLUME + LARGE_PISTON_MAX_VOLUME + 0.01)
#define SYSTEM_MIN_VOLUME         (HOUSING_VOLUME - 0.01)
typedef enum ePistonRead {
    PISReadLength,
    PISReadVolume,
    PISReadCurrent
}ePistonRead_t;

typedef enum ePistonWrite {
    PISWriteLength,
    PISWriteVolume
}ePistonWrite_t;

typedef enum ePistonRunDir {
    PISRunFwd,
    PISRunRev,
    PISRunStop
}ePistonRunDir_t;

typedef enum ePistonRunError {
    PISErrorNone,
    PISErrorStalled,
    PISErrorGeneric
}ePistonRunError_t;

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
    double range;
    int32_t enc_min;
    int32_t enc_max;
    ePistonRunDir_t move_dir;
    bool setpoint_flag;
}sActuator_t;

typedef struct sPistonSystem {
    double volume;                   /**< Volume of the system */
    sActuator_t *actuator;         /**< Piston Length */
    sPistonVolume_t *smallPiston;    /**< Small Piston Volume */
    sPistonVolume_t *largePiston;    /**< Large Piston Volume */
    const sPistonVolume_t *housing;        /**< Housing Volume */
}sPistonSystem_t;


void PIS_Init(void);
void PIS_Enable(void);
void PIS_Disable(void);
double PIS_Read(ePistonRead_t read);
void PIS_Write(ePistonWrite_t write, double value);
ePistonRunError_t PIS_Run_to_volume(double volume);

void PIS_Write_length(double);
void PIS_Write_volume(double volume);
double PIS_Read_length(void);
double PIS_Read_volume(void);
float PIS_Read_current(void);

#ifdef TEST
extern sActuator_t actuator;
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

void _PIS_Run(ePistonRunDir_t dir);
#endif

#endif // _PISTON_H
