/**********************************************************************************
 * @Title       :   Piston Control
 * @Filename    :   piston.h
 * @Author      :   Matt Casari
 * @Origin Date :   1/12/2021
 * @Version     :   1.0.0
 * @Compiler    :   IAR, GCC
 * @Target      :   MSP430FR5989
 * @Notes       :   None
 * @Bugs        :   No known bugs
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights 
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *********************************************************************************/

#ifndef _PISTON_H
#define _PISTON_H

/**********************************************************************************
 * Includes
 *********************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "config.h"
#include "encoder.h"
#include "DRV8874.h"

/**********************************************************************************
 * Configuration Constants
 *********************************************************************************/
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
#define SYSTEM_MIN_LENGTH         (0.0f)
#define SYSTEM_MAX_LENGTH         (SMALL_PISTON_MAX_LENGTH + LARGE_PISTON_MAX_LENGTH)


/**********************************************************************************
 * MACROS
 *********************************************************************************/
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

/**********************************************************************************
 * Typdefs
 *********************************************************************************/
/**
 * Piston Read Options
 */
typedef enum ePistonRead {
    PISReadLength,  /**< Read Length (in) */
    PISReadVolume,  /**< Read Volume (in^3) */
    PISReadCurrent  /**< Read Current (A) */
}ePistonRead_t;

/**
 * Piston Write Optinos
 */
typedef enum ePistonWrite {
    PISWriteLength, /**< Write Length (in) */
    PISWriteVolume  /**< Write Volume (in^3) */
}ePistonWrite_t;

/**
 * Piston Run Direction
 */
typedef enum ePistonRunDir {
    PISRunFwd,  /**< Piston Forward */  
    PISRunRev,  /**< Piston Reverse */
    PISRunStop  /**< Piston Stop */
}ePistonRunDir_t;

/** 
 * Piston Run Errors
 */
typedef enum ePistonRunError {
    PISErrorNone,       /**< No iston Error */
    PISErrorStalled,    /**< Piston is stalled */
    PISErrorOvershoot,  /**< Piston overshot setpoint */
    PISErrorGeneric     /**< Generic piston error */
}ePistonRunError_t;

/**
 * Piston Volume Variables
 */
typedef struct sPistonVolume {
    double _volume;      /**< Piston volume (in^3) */
    double _length;      /**< Length of piston (in) */
    double _diameter;    /**< Diameter of piston (in) */
    double _max_length;  /**< Maximum length of piston (in) */
    double _max_volume;  /**< Maximum volume of piston (in) */
}sPistonVolume_t;

/**
 * Actuator settings and variables
 */
typedef struct sActuator {
    sEncoderSettings_t *settings;       /**< Current encoder settings */
    volatile double current_length;     /**< Length to calculate conversion factor */
    double setpoint;                    /**< Piston length setpoint (in) */
    double _conversion_factor;           /**< Conversion factor to calculate "length" cnt/in */
    double _range;                       /**< Offset range (in) */
    int32_t enc_min;                    /**< Encoder count min (Zero count) */
    int32_t enc_max;                    /**< Encoder count max (Full extend count) */
    ePistonRunDir_t move_dir;           /**< Piston movement direction */
    bool setpoint_flag;                 /**< Setpoint reached, True or False */
}sActuator_t;

/**
 * Piston System Struct
 */
typedef struct sPistonSystem {
    double volume;                      /**< Volume of the system */
    sActuator_t *actuator;              /**< Piston Length */
    sPistonVolume_t *smallPiston;       /**< Small Piston Volume */
    sPistonVolume_t *largePiston;       /**< Large Piston Volume */
    const sPistonVolume_t *housing;     /**< Housing Volume */
}sPistonSystem_t;

/**********************************************************************************
 * Function Prototypes
 *********************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void PIS_Init(void);
void PIS_Enable(void);
void PIS_Disable(void);
double PIS_Read(ePistonRead_t read);
void PIS_Write(ePistonWrite_t write, double value);
ePistonRunError_t PIS_Run_to_length(double length);
ePistonRunError_t PIS_Run_to_volume(double volume);
void PIS_Extend(void);
void PIS_Retract(void);
void PIS_Stop(void);
void PIS_Reset_to_Zero(void);

/**********************************************************************************
 * Unit Test Variables & Static Prototpyes
 *********************************************************************************/
#ifdef TEST
#ifdef DOXYGEN_IGNORE_THIS
extern sActuator_t actuator;
extern sPistonVolume_t smallPiston;
extern sPistonVolume_t largePiston;
extern const sPistonVolume_t housing;
void PIS_Write_length(double);
void PIS_Write_volume(double volume);
double PIS_Read_length(void);
double PIS_Read_volume(void);
float PIS_Read_current(void);
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
#endif // DOXYGEN_IGNORE_THIS
#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _PISTON_H
