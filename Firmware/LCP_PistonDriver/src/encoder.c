#include "encoder.h"
#include "logging.h"
#include "memory.h"
#include "bsp_timer_a.h"
#include <stdio.h>
#include "config.h"

STATIC PERSISTENT volatile int32_t g_encoder_counter;
STATIC PERSISTENT volatile int32_t *p_encoder_counter = &g_encoder_counter;
STATIC PERSISTENT volatile int32_t g_encoder_direction;

STATIC PERSISTENT sEncoderSettings_t encSettings =
{
    .min_count = ENCODER_MIN_COUNT_DEFAULT,
    .max_count = ENCODER_MAX_COUNT_DEFAULT,
    .distance = ENCODER_MAX_COUNT_DEFAULT - ENCODER_MIN_COUNT_DEFAULT,
    .length = ENCODER_LENGTH_DEFAULT,
};

STATIC PERSISTENT sEncoderSettings_t *pEncSettings = &encSettings;

//STATIC bool _set_min_count(int32_t val) {
//    if( val < 0 ) 
//    {
//        return false;
//    }
//    encSettings.min_count = val;
//    return true;
//}
//
//STATIC bool _set_max_count(int32_t val)
//{
//    if( (val < 0) || (val < encSettings.min_count) )
//    {
//        return false;
//    }
//
//    encSettings.max_count = val;
//    return true;
//}
//
//STATIC void _clear_enc_counter(void) {
//    g_encoder_counter = encSettings.min_count;
//}
//
//STATIC void _set_max_enc_counter(void) {
//    g_encoder_counter = encSettings.max_count;
//}

STATIC void _calculate_encoder_distance(void)
{
    encSettings.distance = encSettings.max_count - encSettings.min_count;
}

STATIC double _calculate_length(void) 
{
    int32_t temp_u = ENC_Get_count() - encSettings.min_count;
    double temp_f = (double) temp_u;
    temp_f /= encSettings.max_count;
    //temp_f *= encSettings.conversion_factor;
    return temp_f * encSettings.length;
}

void ENC_Increment(void)
{
    //*p_encoder_counter += g_encoder_direction;
    g_encoder_counter++;
}

void ENC_Decrement(void)
{
    g_encoder_counter--;
}
void ENC_Set_count(int32_t val)
{
    char temp[40] = {0};
    sprintf(temp, "Setting encoder to %li", val);
    Log.Debug(temp);
    *p_encoder_counter = val;

    /* set in the memory map too */
    MEM_Set_PST_Encoder_Counts(*p_encoder_counter);
    sprintf(temp, "Encoder set to %li", *p_encoder_counter);
    Log.Debug(temp);
}

void ENC_Set_max_count(int32_t val)
{
    char temp[40] = {0};
    sprintf(temp, "Setting encoder max to %li", val);
    Log.Debug(temp);
    pEncSettings->max_count = val;

    /* set in the memory map too */
    MEM_Set_PST_Encoder_Counts_Max(pEncSettings->max_count);
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

void ENC_Init(void)
{
    /** Configure the toggle pins no matter what */
    BSP_GPIO_Init(&g_BSP_GPIO_ENCODER_A);
    BSP_GPIO_Init(&g_BSP_GPIO_ENCODER_B);

    BSP_GPIO_Init(&g_BSP_GPIO_ENCODER_PULLUP);
    //BSP_GPIO_Set(&g_BSP_GPIO_ENCODER_PULLUP);
    //BSP_GPIO_Clear(&g_BSP_GPIO_ENCODER_PULLUP);

    /** Use for GPIO based encoder interrupts (works, but not the best) */
    BSP_GPIOCallback(1, &ENC_Increment);
    BSP_GPIOCallback(2, &ENC_Decrement);
    BSP_GPIOCallback_i(10, &ENC_GetDir);

    //BSP_GPIOCallback(2, &ENC_Increment);
    BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_A);
    BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_B);

    //p_encoder_counter = BSP_GPIO_Init_Counter(0);

    /** Use for Timer B based counting (testing now) */
    //P1DIR &= ~(BIT3|BIT4);
    //P1SEL1 |= (BIT3|BIT4);
    //P1SEL0 |= (BIT3|BIT4);
      
    //Timer_A_Init();
    //Timer_A_Start();
      
    /** Use for ESI based (does not work) */
    //esiConfig();
    //ESI_disable();

    __no_operation();
    __no_operation();
    __enable_interrupt();
    __no_operation();
    __no_operation();
}

void ENC_SetDir(ePistonDir_t dir)
{
    Log.Debug ("ENC_SetDir");

    assert( (dir == DIR_EXTEND) || (dir == DIR_RETRACT) );
    g_encoder_direction = (int32_t)dir;
    MEM_Set_i8(TRV_dir, dir);

    //if (dir == DIR_EXTEND)
    //{
    //    BSP_GPIO_ClearInterrupt(&g_BSP_GPIO_ENCODER_A);
    //    BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_B);
    //}
    //else
    //{
    //    BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_A);
    //    BSP_GPIO_ClearInterrupt(&g_BSP_GPIO_ENCODER_B);
    //}
    //__no_operation();
    //__enable_interrupt();
    //__no_operation();

    //if(dir == DIR_EXTEND)
    //{

    //Log.Debug ("__disable_interrupt()disabling interrupt");
    //__disable_interrupt();
    //Log.Debug ("__disable_interrupt()disabling interrupt DONE");
    //__no_operation();

    //Log.Debug ("BSP_GPIO clearing interrupts ENcoder A-B");
    BSP_GPIO_ClearInterrupt(&g_BSP_GPIO_ENCODER_A);
    BSP_GPIO_ClearInterrupt(&g_BSP_GPIO_ENCODER_B);
    //Log.Debug ("BSP_GPIO clearing interrupts ENcoder A-B DONE");

    //Log.Debug ("BSP_GPIO setting interrupts ENcoder A-B");
    BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_A);
    BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_B);
    //Log.Debug ("BSP_GPIO setting interrupts ENcoder A-B DONE");

    //}else {
    //BSP_GPIO_ClearInterrupt(&g_BSP_GPIO_ENCODER_A);
    //BSP_GPIO_SetInterrupt(&g_BSP_GPIO_ENCODER_B);
    //}
    __no_operation();
    __enable_interrupt();
    __no_operation();
}

int8_t ENC_GetDir(void)
{
    return g_encoder_direction;
}

double ENC_Get_Length(void)
{
    //float length = ENC_Get_count()
    //assert(encSettings.distance > 0);
    return _calculate_length();
}

void ENC_Set_MaxLength(double val)
{
    _calculate_encoder_distance();
    assert(encSettings.distance > 0);
    encSettings.length = val;
    encSettings.conversion_factor = encSettings.length / encSettings.distance;
}

void ENC_FactoryReset(void)
{
    encSettings.min_count = ENCODER_MIN_COUNT_DEFAULT;
    encSettings.max_count = ENCODER_MAX_COUNT_DEFAULT;
    ENC_Set_MaxLength(ENCODER_LENGTH_DEFAULT);
}
