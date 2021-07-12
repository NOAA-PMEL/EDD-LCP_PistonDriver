/** @file "piston.c"
 * @brief Piston control
 */

/**********************************************************************************
 * Includes
 *********************************************************************************/
#include "piston.h"
#include "logging.h"
#include <math.h>
#include <stdio.h>
/**********************************************************************************
 * Preprocessor Constants
 *********************************************************************************/
/**********************************************************************************
 * Preprocessor Macros
 *********************************************************************************/
/**********************************************************************************
 * Module Typedefs
 *********************************************************************************/
/**********************************************************************************
 * Module Variable Definitions
 *********************************************************************************/
/**
 * Defines the struct for the Small Diameter Piston
 */
STATIC PERSISTENT sPistonVolume_t smallPiston = {
    ._volume = 0,
    ._length = 0,
    ._diameter = SMALL_PISTON_DIAMETER,
    ._max_length = SMALL_PISTON_MAX_LENGTH,
    ._max_volume = SMALL_PISTON_DIAMETER * PI *SMALL_PISTON_MAX_LENGTH
};

/**
 * Define the struct for the Large Diameter PIston
 */
STATIC PERSISTENT sPistonVolume_t largePiston = {
    ._volume = 0,
    ._length = 0,
    ._diameter = LARGE_PISTON_DIAMETER,
    ._max_length = LARGE_PISTON_MAX_LENGTH,
    ._max_volume = LARGE_PISTON_DIAMETER * PI * LARGE_PISTON_MAX_LENGTH
};

/**
 * Defines the struct for the Housing
 */
STATIC const sPistonVolume_t housing = {
    ._volume = HOUSING_LENGTH * HOUSING_DIAMETER * PI,
    ._length = HOUSING_LENGTH,
    ._diameter = HOUSING_DIAMETER,
    ._max_length = HOUSING_LENGTH,
    ._max_volume = HOUSING_DIAMETER * PI * HOUSING_LENGTH
};

/**
 * Defines the struct for the Actuator settings
 */
STATIC sActuator_t actuator = {
    // .settings = &encSettings,
    .current_length = 0.0f,
    .setpoint = 0.0f,
    .enc_min = 0.0f,
    .enc_max = 0.0f
};

/** 
 * Defines the full profiler piston system struct
 */
STATIC sPistonSystem_t profiler = {
    .volume = 0,
    .actuator = &actuator,
    .smallPiston = &smallPiston,
    .largePiston = &largePiston,
    .housing = &housing
};


/**********************************************************************************
 * Function Prototypes
 *********************************************************************************/
STATIC void PIS_Write_length(double);
STATIC void PIS_Write_volume(double volume);
STATIC double PIS_Read_length(void);
STATIC double PIS_Read_volume(void);
STATIC float PIS_Read_current(void);
STATIC void _PIS_calc_encoder_range(double setpoint, 
                        double range, 
                        double conversion_factor,
                        int32_t *min_cnt,
                        int32_t *max_cnt
                        );

STATIC double _PIS_estimate_length_from_volume(
     double volume,
     const sPistonVolume_t *small,
     const sPistonVolume_t *large,
     const sPistonVolume_t *housing
     );

STATIC double _PIS_calculate_volume_from_length(
    double length,
    const sPistonVolume_t *small,
    const sPistonVolume_t *large,
    const sPistonVolume_t *housing
     );

/**********************************************************************************
 * Function Definitions
 *********************************************************************************/
/**********************************************************************************
 * Function: PIS_Init()
 *
 *//**
 * \b Description:
 * 
 * This function initializes the Piston System by initializing
 * the DRV8874 H-Bridge and the Encoder System
 * 
 * PRE-CONDITION: None
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * @endcode
 * 
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
void PIS_Init(void) {
    DRV8874_init();
    ENC_Init();
}

/**********************************************************************************
 * Function: PIS_Enable()
 *
 *//**
 * \b Description:
 * 
 * This function enables the piston subsystem for movement
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * @endcode
 * 
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
void PIS_Enable(void) {
    DRV8874_enable();
}

/**********************************************************************************
 * Function: PIS_Disable()
 *
 *//**
 * \b Description:
 * 
 * This function disables the piston subsystem, preventing
 * movement at unwanted times.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * PIS_Disable();
 * @endcode
 * 
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
void PIS_Disable(void) {
    DRV8874_disable();   
}

/**********************************************************************************
 * Function: PIS_Read()
 *
 *//**
 * \b Description:
 * 
 * This function reads the selected variable.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param read is the variable to read
 * 
 * @return The selected variables value
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * double current = PIS_Read(PISReadCurrent);
 * printf("%lf\n", current);
 * @endcode
 * 
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
double PIS_Read(ePistonRead_t read)
{
    if(read == PISReadLength)
    {
        return PIS_Read_length();
    } else if( read == PISReadVolume) 
    {
        return PIS_Read_volume();
    } else if( read == PISReadCurrent) 
    {
        return (double) PIS_Read_current();
    } else {
        /** @todo Add Logging Error */
    }
}

/**********************************************************************************
 * Function: PIS_Write()
 *
 *//**
 * \b Description:
 * 
 * This function writes the value to the selected
 * variable.
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Selected Variable must be valid
 * 
 * POST-CONDITION: None
 * 
 * @param write is the variable selected to be written to
 * @param value is the value to write to variable.
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Write(PISWriteVolume, 300.1);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
void PIS_Write(ePistonWrite_t write, double value)
{
    switch(write)
    {
        case PISWriteLength:
            
            break;
        case PISWriteVolume:

            break;
        default:
        /** @todo Add Logging Error */
            break;
    }
}

/**********************************************************************************
 * Function: PIS_Run_to_length()
 *
 *//**
 * \b Description:
 * 
 * This function runs the piston until it reaches the piston length
 * setpoint selected (within the range tolerance initially provided).
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Length Variable must be valid
 * 
 * POST-CONDITION: Piston will be moved to selected position.
 * POST-CONDITION: actuator.current_length will be updated.
 * 
 * @param length is the length to run to.
 * 
 * @return Error status
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * ePistonRunError_t error = PIS_Run_to_length(7.5);
 * if(error == PISErrorNone)
 * {
 *  printf("Piston successfully moved to %f inches", actuator.current_length);
 * }
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 * @see PIS_Run_to_length
 * @see PIS_Run_to_volume
 */
ePistonRunError_t PIS_Run_to_length(double length)
{
    #ifndef TEST
    assert(length <= SYSTEM_MAX_LENGTH);
    assert(length >= SYSTEM_MIN_LENGTH);
    #endif

    char temp[64];
    sprintf(temp, "PIS_Run_to_length called with length = %f", length);
    Log.Debug(temp);

    ePistonRunError_t error = PISErrorGeneric;
    /** Update the setpoint and encoder range */
    PIS_Write_length(length);

    actuator.setpoint_flag = false;
    float diff = length - ENC_Get_Length();
    uint8_t speed;
    if(diff > 0.5)
    {
      speed = 100;
    } else {
      speed = 50;
    }
    
    if(diff > 0)
    {
        actuator.move_dir = PISRunFwd;           
        PIS_Extend(true, speed);
        
    } else if(diff < 0) 
    {
        actuator.move_dir = PISRunRev;
        PIS_Retract(true, speed);
    } else {
        actuator.setpoint_flag = true;
    }

    float current = 0.0f;
    bool current_stop = false;
    bool setpoint_reached = false;
    bool slow_speed_flag = false;
    do{

        
        float current_length = PIS_Read_length();
        sprintf(temp, "Current length = %.4f", current_length);
        Log.Debug(temp);
        
        float diff = current_length - length;
        
        if(fabs(diff) < 0.005)
        {
          DRV8874_stop();
          actuator.setpoint_flag = true;
        } 

        
      if(!slow_speed_flag)
      {
        if(fabs(diff) <= 0.5)
        {
          slow_speed_flag = true;
          if(actuator.move_dir == PISRunFwd)
          {
            PIS_Extend(false, 50);
          } else {
            PIS_Retract(false, 50);
          }
        }
      }
      current = DRV8847_read_current();
      current_stop = (current >= 0.005f);
      setpoint_reached = (actuator.setpoint_flag);
    }while(!actuator.setpoint_flag && current_stop);
    
    Log.Debug("Exited do/while loop");
    PIS_Stop();
    
    if(current_stop == false)
    {
      sprintf(temp, "Current at stop condition = %.4f", current);
      Log.Debug(temp);
    }
    
    if(actuator.setpoint_flag)
    {
      Log.Debug("Setpoint (supposedly) reached");
    }
    sprintf(temp, "Position at stop = %.4f", ENC_Get_Length());
    Log.Debug(temp);
    
    diff = ENC_Get_Length() - length;
    sprintf(temp, "Diff = %0.4f", diff);
    Log.Debug(temp);
    
    

    if((actuator.setpoint_flag == true) && (current <= 0.1))
    {
        
        error = PISErrorStalled;
        /** Log Error Stalled */
        Log.Error("Piston stalled");
        if(actuator.move_dir == PISRunFwd)
        {
            /** Log Stalled Fwd, near full extended hard stop? */
            Log.Error("Stall near full hard stop");
        }
        else if(actuator.move_dir == PISRunRev)
        {
            /** Log Stalled Rev, near zero hard stop? */
            Log.Error("Stall near zero hard stop");
        }
    } 
    else if((actuator.setpoint_flag == false))
    {
        /** Log overshoot */
        Log.Error("Overshoot");
        error = PISErrorOvershoot;
    } 
    else {
        error = PISErrorNone;
    }
    return error;
}

/**********************************************************************************
 * Function: PIS_Run_to_volume()
 *
 *//**
 * \b Description:
 * 
 * This function runs the piston until it reaches the volume setpoint 
 * selected (within the range tolerance initially provided).
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Volume Variable must be valid
 * 
 * POST-CONDITION: Piston will be moved to selected position
 * POST-CONDITION: actuator.current_length will be updated
 * 
 * @param write is the variable selected to be written to
 * @param value is the value to write to variable.
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * ePistonRunError_t error = PIS_Run_to_volume(600.75);
 * if(error == PISErrorNone)
 * {
 *  printf("Profiler volume is now %f (in^3)", actuator.current_length);
 * }
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 * @see PIS_Run_to_length
 * @see PIS_Run_to_volume
 */
ePistonRunError_t PIS_Run_to_volume(double volume)
{
    ePistonRunError_t error = PISErrorGeneric;
    char temp[64];
    
    #ifndef TEST
    assert(volume <= SYSTEM_MAX_VOLUME);
    assert(volume >= SYSTEM_MIN_VOLUME);
    #endif

    double length = _PIS_estimate_length_from_volume(
                        volume, 
                        &smallPiston, 
                        &largePiston,
                        &housing
                    );
    
    error = PIS_Run_to_length(length);
    
    sprintf(temp, "Volume at stop = %.4f", PIS_Get_Volume());
    Log.Debug(temp);
    float diff = PIS_Get_Volume() - volume;
    sprintf(temp, "Diff = %0.4f", diff);
    Log.Debug(temp);
    
    return error;
}


void PIS_Extend(bool startup, uint8_t speed)
{
  Log.Debug("PIS_Extend called");
  if(ENC_GetDir() == DIR_RETRACT)
  {
    Log.Debug("Stopping movement before Extending");
    PIS_Stop();
  }
  ENC_SetDir(DIR_EXTEND);
  DRV8874_reverse(speed);
  actuator.speed = speed;
  actuator.move_dir = PISRunFwd;
}

void PIS_Retract(bool startup, uint8_t speed)
{
  Log.Debug("PIS_Retract called");
  if(ENC_GetDir() == DIR_EXTEND)
  {
    Log.Debug("Stopping movement before Retracting");
    PIS_Stop();
  }
  ENC_SetDir(DIR_RETRACT);
  DRV8874_forward(speed);
  actuator.speed = speed;
  actuator.move_dir = PISRunRev;
}

void PIS_Stop(void)
{
  Log.Debug("PIS_Stop called");
  DRV8874_stop();
  actuator.move_dir = PISRunStop;
}

void PIS_Reset_to_Zero(void)
{
  char temp[32];
  Log.Debug("PIS_Reset_to_Zero called");
  int32_t count = ENC_Get_count();
  PIS_Retract(true, 100);
  __delay_cycles(0xFFFFFFFF);
  
  while( (fabs(PIS_Read_current()) > 0.05f) && 
        (count != ENC_Get_count()) )
  {
    sprintf(temp, "Resetting to zero: pos = %0.4f", ENC_Get_Length());
    Log.Debug(temp);
    __delay_cycles(0x00FFFFFF);
  }
  Log.Debug("Move Complete");
  Log.Debug("Resetting encoder");
  ENC_Set_count(0);
}       

void PIS_Run_to_Full(void)
{
  char temp[32];
  int32_t count = ENC_Get_count();  
  Log.Debug("PIS_Run_to_Full called");
  PIS_Extend(true, 100);
   __delay_cycles(0xFFFFFFFF);
  
  while( (fabs(PIS_Read_current()) > 0.000001f) && 
          (count != ENC_Get_count()) )
  {
    sprintf(temp, "Running to full: pos = %0.4f", ENC_Get_Length());
      Log.Debug(temp);
      __delay_cycles(0x00FFFFFF);
  }
  Log.Debug("Move Complete");
  Log.Debug("Resetting encoder");
}

void PIS_Calibrate(void)
{   
    Log.Debug("PIS_Calibrate called");
    Log.Debug("System will Zero, than run to full");
    Log.Debug("This will take a few minutes");

    PIS_Reset_to_Zero();
    PIS_Run_to_Full();
    Log.Debug("Settng max encoder count");
    ENC_Set_max_count(ENC_Get_count());



}


float PIS_Get_Volume(void)
{
  return PIS_Read_volume();
  
}

/**********************************************************************************
 * Function: PIS_Write_length()
 *
 *//**
 * \b Description:
 * 
 * This function writes the value to length variable.
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Length must be valid
 * 
 * POST-CONDITION: actuator.enc_min is updated
 * POST-CONDITION: actuator.enc_max is updated
 * 
 * @param write is the variable selected to be written to
 * @param value is the value to write to variable.
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Write_length(10.2);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC void PIS_Write_length(double setpoint) {
    #ifndef TEST
    assert(setpoint >= 0.0f);
    assert(setpoint <= (smallPiston._max_length + largePiston._max_length) );
    #endif 

    actuator.setpoint = setpoint;
    _PIS_calc_encoder_range(
        setpoint, 
        actuator._range,
        actuator._conversion_factor,
        &actuator.enc_min,
        &actuator.enc_max
        );
}

/**********************************************************************************
 * Function: PIS_Write_volume()
 *
 *//**
 * \b Description:
 * 
 * This function writes the value to volume variable.
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Volume must be valid
 * 
 * POST-CONDITION: actuator.enc_min is updated
 * POST-CONDITION: actuator.enc_max is updated
 * 
 * @param value is the vvolume to set.
 * 
 * @return void
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Write_length(10.2);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC void PIS_Write_volume(double volume)
{
   double length = _PIS_estimate_length_from_volume(
                                        volume,
                                        &smallPiston, 
                                        &largePiston,
                                        &housing
                                        );

    PIS_Write_length(length);
}

/**********************************************************************************
 * Function: PIS_Read_length()
 *
 *//**
 * \b Description:
 * 
 * This function reads the current length value.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return Current piston length.
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * double length = PIS_Read_length();
 * printf("The piston length is %f", length);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC double PIS_Read_length(void) {
//  Log.Debug("PIS_Read_length called");
  
    double length = ENC_Get_Length();
    char temp[32];
//    sprintf(temp, "length = %.4f", length);
//    Log.Debug(temp);
    if( (length > 0.0f) && (length <= smallPiston._max_length))
    {
        smallPiston._length = length;
    } else if( (length > 0.0f) && (length <= (smallPiston._max_length + largePiston._max_length)))
    {
        smallPiston._length = smallPiston._max_length;
        largePiston._length = length - smallPiston._max_length;
    } else if( length == 0) {
        smallPiston._length = 0.0f;
        largePiston._length = 0.0f;
    }
    return length;
}

/**********************************************************************************
 * Function: PIS_Read_volume()
 *
 *//**
 * \b Description:
 * 
 * This function reads the current volume value.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return Current piston length.
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * double length = PIS_Read_length();
 * printf("The piston length is % in.f\n", length);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC double PIS_Read_volume(void) { 
    PIS_Read_length();
    smallPiston._volume = smallPiston._length * smallPiston._diameter * PI;
    largePiston._volume = largePiston._length * largePiston._diameter * PI;
    return housing._volume + smallPiston._volume + largePiston._volume;
}

/**********************************************************************************
 * Function: PIS_Read_current()
 *
 *//**
 * \b Description:
 * 
 * This function reads the current current value.
 * 
 * PRE-CONDITION: Piston must be initialized
 * 
 * POST-CONDITION: None
 * 
 * @param None
 * 
 * @return Current drive current.
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * double current = PIS_Read_current(); // Static function, only call from this module
 * printf("The piston drawing %f amps\n", current);
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC float PIS_Read_current(void) {
    return DRV8847_read_current();
}

/** @brief Calculate the min/max encoder count 
 * 
 * Determine what the min/max encoder count is in order
 * to preserve 
 * @param setpoint Setpoint (length) to send piston to
 * @param _conversion_factor 
 * @param *settings Pointer to minimum
 */
STATIC void _PIS_calc_encoder_range(double setpoint, 
                        double range, 
                        double _conversion_factor,
                        int32_t *min_cnt,
                        int32_t *max_cnt
                        ) 
{
    double min = (setpoint - range) * _conversion_factor;
    double max = (setpoint + range) * _conversion_factor;
    
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
    // printf("Volume=%f, max=%f ",volume, (housing->_max_volume + small->_max_volume + large->_max_volume + actuator._range));

    if((volume <= housing->_max_volume+0.001) && (volume >= housing->_max_volume-0.001))
    {
        length = 0.0f;
        // printf("Housing Only: length=%f\n", length);
    }
    else if (volume <= (housing->_max_volume + small->_max_volume))
    {
        volume -= housing->_max_volume;
        length = volume / (small->_diameter * PI);
        
        // printf("Housing + Small: length=%f\n", length);
        // return length;
    }
    else if (volume <= (housing->_max_volume + small->_max_volume + large->_max_volume + 0.1))
    {
        volume -= (housing->_max_volume + small->_max_volume);
        length = (volume / (large->_diameter*PI)) + small->_max_length;
        // printf("Housing + Both: length=%f\n", length);
        // return length;
    } else {
        // printf("Nothin");
        length =  -1.0f;
    }
    // else if

    // printf("\nLength=%f", length);
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

/**********************************************************************************
 * Function: _PIS_Run()
 *
 *//**
 * \b Description:
 * 
 * This function starts the piston running based on direction provided.
 * 
 * PRE-CONDITION: Piston must be initialized
 * PRE-CONDITION: Piston must be enabled
 * PRE-CONDITION: Direction must be valid
 * 
 * POST-CONDITION: Piston is in motion (unless stop is called)
 * 
 * @param dir is the Direction to move the piston
 * 
 * @return None
 * 
 * \b Example:
 * @code
 * PIS_Init();
 * PIS_Enable();
 * _PIS_Run(PISRunFwd); //Static Function, only call within this module 
 * 
 * @endcode
 *
 * @see PIS_Init
 * @see PIS_Enable
 * @see PIS_Disable
 * @see PIS_Read
 * @see PIS_Write
 */
STATIC void _PIS_Run(ePistonRunDir_t dir)
{
    switch(dir)
    {
        case PISRunFwd:
            DRV8874_forward(100);
            break;
        case PISRunRev:
            DRV8874_reverse(100);
            break;
        case PISRunStop:
            DRV8874_stop();
            break;
        default:
            break;
    }
}