#include "unity.h"
#include "piston.h"
#include "mock_encoder.h"
#include "mock_DRV8874.h"

void setUp(void)
{
}

void tearDown(void)
{
}


void test_piston_init_should_initialize_piston(void) {
    // Given:

    // When: Piston Initialization Called
    DRV8874_init_Expect();
    ENC_Init_Expect();

    PIS_init();
    
    // Then: Encoder & DRV8874 Init called
    TEST_PASS();
}
void test_piston_calc_range_should_calculate_min_max_for_piston_stop(void)
{
    // Given: A valid setpoint in the range of the piston
    double setpoint = 3.0f;
    double range = 0.001;
    double conversion_factor = 10000.0f;

    int32_t min;
    int32_t max;
    int32_t expected_min = 29990;
    int32_t expected_max = 30010;

    

    // When: the range function is called
    _calc_encoder_range(setpoint, range, conversion_factor, &min, &max);

    // Then: the correct range should be set
    TEST_ASSERT_EQUAL_INT32(expected_min, min);
    TEST_ASSERT_EQUAL_INT32(expected_max, max);
}


