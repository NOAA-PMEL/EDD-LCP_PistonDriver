#include "encoder.h"
#include "logging.h"
#include "bsp/bsp_timer_a.h"
#include <stdio.h>

STATIC PERSISTENT volatile int32_t g_encoder_counter;
STATIC PERSISTENT volatile int32_t *p_encoder_counter;
STATIC PERSISTENT volatile int32_t g_encoder_direction;

STATIC PERSISTENT sEncoderSettings_t encSettings = {
    .min_count = ENCODER_MIN_COUNT_DEFAULT,
    .max_count = ENCODER_MAX_COUNT_DEFAULT,
    .distance = ENCODER_MAX_COUNT_DEFAULT - ENCODER_MIN_COUNT_DEFAULT,
    .length = ENCODER_LENGTH_DEFAULT,
 };

STATIC PERSISTENT sEncoderSettings_t *pEncSettings = &encSettings;

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


void ENC_Increment(void)
{
  
}

void ENC_Set_count(int32_t val)
{
  char temp[40];
  memset(temp,0,40);
  sprintf(temp, "Setting encoder to %li", val);
  Log.Debug(temp);
  *p_encoder_counter = val;
  sprintf(temp, "Encoder set to %li", *p_encoder_counter);
  Log.Debug(temp);
}

void ENC_Set_max_count(int32_t val)
{
  char temp[40];
  memset(temp,0,40);
  sprintf(temp, "Setting encoder max to %li", val);
  Log.Debug(temp);
  pEncSettings->max_count = val;
  sprintf(temp, "Encoder max set to %li", pEncSettings->max_count);
  Log.Debug(temp);
}

int32_t ENC_Get_count(void)
{
  return *p_encoder_counter;
}

int32_t ENC_Get_min_count(void)
{
  return pEncSettings->min_count;
}

int32_t ENC_Get_max_count(void)
{
  return pEncSettings->max_count;
}
void ENC_Init(void) {
  /** Configure the toggle pins no matter what */
  BSP_GPIO_Init(&g_BSP_GPIO_ENCODER_A);
  BSP_GPIO_Init(&g_BSP_GPIO_ENCODER_B);
  /** Use for GPIO based encoder interrupts (works, but not the best)*/

//      
      BSP_GPIOCallback(1, &ENC_Increment);
      BSP_GPIOCallback(2, &ENC_Increment);
//
      BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_A);
      BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_B);
      
      p_encoder_counter = BSP_GPIO_Init_Counter(0);
  
  /** Use for Timer B based counting (testing now) */
//  P1DIR &= ~(BIT3|BIT4);
//  P1SEL1 |= (BIT3|BIT4);
//  P1SEL0 |= (BIT3|BIT4);
  
//  Timer_A_Init();
//  Timer_A_Start();
  
  /** Use for ESI based (does not work) */
//    esiConfig();
//    ESI_disable();
  
}

void ENC_SetDir(int8_t dir)
{
  assert( (dir == -1) || (dir == 1) );
  g_encoder_direction = dir;
  if(dir == 1)
  {
    BSP_GPIO_ClearInterrupt(&g_BSP_GPIO_ENCODER_B);
    BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_A);
  } else {
    BSP_GPIO_ClearInterrupt(&g_BSP_GPIO_ENCODER_A);
    BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_B);
  }
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

