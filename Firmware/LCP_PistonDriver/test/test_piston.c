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
    _PIS_calc_encoder_range(setpoint, range, conversion_factor, &min, &max);

    // Then: the correct range should be set
    TEST_ASSERT_EQUAL_INT32(expected_min, min);
    TEST_ASSERT_EQUAL_INT32(expected_max, max);
}

void test__PIS_estimate_length_from_volume_should_return_valid_length_no_extension(void)
{
    // Given: Volume == housing volume
    
    double volume = housing._max_volume;
    double expected_length = 0.0f;
    double calc_length = 0.0f;

    // When: _PIS_estimate_length_from_volume is called
    calc_length = _PIS_estimate_length_from_volume(
        volume,
        &smallPiston,
        &largePiston,
        &housing);

    // Then: The return length is 0
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, calc_length);
}

void test__PIS_estimate_length_from_volume_should_return_negative_one_for_volume_less_than_housing(void)
{
    // Given: Volume == housing volume
    
    double volume = housing._max_volume;
    double expected_length = 0.0f;
    double calc_length = 0.0f;

    // When: _PIS_estimate_length_from_volume is called
    calc_length = _PIS_estimate_length_from_volume(
        volume,
        &smallPiston,
        &largePiston,
        &housing);

    // Then: The return length is 0
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, calc_length);
}

void test__PIS_estimate_length_from_volume_should_return_valid_length_short_piston_only(void)
{
    // Given: Valid volume called is == housing + 1/2 small piston
    
    double volume = housing._max_volume + smallPiston._max_volume/2;
    double expected_length = smallPiston._max_length/2;
    double calc_length = 0.0f;

    // When: _PIS_estimate_length_from_volume is called
    calc_length = _PIS_estimate_length_from_volume(
        volume,
        &smallPiston,
        &largePiston,
         &housing);

    // Then: The return length is valid
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, calc_length);
}

void test__PIS_estimate_length_from_volume_should_return_valid_length_both_piston(void)
{
    // Given: Valid volume called is == housing + 1/2 small piston
    
    double volume = housing._max_volume + smallPiston._max_volume + largePiston._max_volume/2;
    double expected_length = smallPiston._max_length + largePiston._max_length/2;
    double calc_length = 0.0f;

    // When: _PIS_estimate_length_from_volume is called
    calc_length = _PIS_estimate_length_from_volume(
        volume,
        &smallPiston,
        &largePiston,
         &housing);

    // Then: The return length is valid
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, calc_length);
}

void test__PIS_estimate_length_from_volume_should_return_invalid_for_volume_greater_than_system(void)
{
   // Given: Valid volume called is == housing + 1/2 small piston
    
    double volume = housing._max_volume + smallPiston._max_volume + largePiston._max_volume + 1.0f;
    double expected_length = -1.0f;
    double calc_length = 0.0f;

    // When: _PIS_estimate_length_from_volume is called
    calc_length = _PIS_estimate_length_from_volume(
        volume,
        &smallPiston,
        &largePiston,
         &housing);

    // Then: The return length is valid
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, calc_length);
 
}


void test__PIS_calculate_volume_from_length_should_return_housing_vol_for_zero_length(void)
{
    // Given: a length of zero
    double length = 0.0f;
    double expected_volume = housing._max_volume;
    double calc_volume = 0.0f;

    // When: _PIS_calculate_volume_from_length is called
    calc_volume = _PIS_calculate_volume_from_length(
        length, 
        &smallPiston,
        &largePiston,
        &housing);

    // Then: volume == housing volume
    TEST_ASSERT_EQUAL_DOUBLE(expected_volume, calc_volume);
}

void test__PIS_calculate_volume_from_length_should_return_housing_plus_half_small_for_half_small_length(void)
{
    // Given: a length of zero
    double length = smallPiston._max_length/2;
    double expected_volume = housing._max_volume + smallPiston._max_volume/2;
    double calc_volume = 0.0f;

    // When: _PIS_calculate_volume_from_length is called
    calc_volume = _PIS_calculate_volume_from_length(
        length, 
        &smallPiston,
        &largePiston,
        &housing);

    // Then: volume == housing volume
    TEST_ASSERT_EQUAL_DOUBLE(expected_volume, calc_volume);
}

void test__PIS_calculate_volume_from_length_should_return_housing_plus_half_large_for_half_large_length(void)
{
    // Given: a length of zero
    double length = smallPiston._max_length + largePiston._max_length/2;
    double expected_volume = housing._max_volume + smallPiston._max_volume + largePiston._max_volume/2;
    double calc_volume = 0.0f;

    // When: _PIS_calculate_volume_from_length is called
    calc_volume = _PIS_calculate_volume_from_length(
        length, 
        &smallPiston,
        &largePiston,
        &housing);

    // Then: volume == housing volume
    TEST_ASSERT_EQUAL_DOUBLE(expected_volume, calc_volume);
}

void test_PIS_calculate_volume_from_length_should_return_invalid_for_negative_numbers(void)
{
    // Given: a length of zero
    double length = -0.32f;
    double expected_volume = -1.0f;
    double calc_volume = 0.0f;

    // When: _PIS_calculate_volume_from_length is called
    calc_volume = _PIS_calculate_volume_from_length(
        length, 
        &smallPiston,
        &largePiston,
        &housing);

    // Then: volume == housing volume
    TEST_ASSERT_EQUAL_DOUBLE(expected_volume, calc_volume);

}

void test_PIS_calculate_volume_from_length_should_return_invalid_for_length_greater_than_system(void)
{
    // Given: a length of zero
    double length = housing._max_length + smallPiston._max_length + largePiston._max_length + 0.01f;
    double expected_volume = -1.0f;
    double calc_volume = 0.0f;

    // When: _PIS_calculate_volume_from_length is called
    calc_volume = _PIS_calculate_volume_from_length(
        length, 
        &smallPiston,
        &largePiston,
        &housing);

    // Then: volume == housing volume
    TEST_ASSERT_EQUAL_DOUBLE(expected_volume, calc_volume);

}


void test_PIS_get_length_should_return_valid_length_full_length(void)
{
    // Given: Fully extended pistons
    double expected_length = smallPiston._max_length + largePiston._max_length;
    double actual_length = -1.0f;
    smallPiston._length = smallPiston._max_length;
    largePiston._length = largePiston._max_length;

    // When: PIS_get_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_get_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, actual_length);
    
}

void test_PIS_get_length_should_return_valid_length_for_zero_length_(void)
{
    // Given: Fully extended pistons
    double expected_length = 0.0f;
    double actual_length = 0.0f;
    smallPiston._length = smallPiston._max_length;
    largePiston._length = largePiston._max_length;

    // When: PIS_get_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_get_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, actual_length);
    
}

void test_PIS_get_length_should_return_valid_small_large_length_for_zero_length_(void)
{
    // Given: Fully extended pistons
    double expected_length = 0.0f;
    double actual_length = 0.0f;
    smallPiston._length = smallPiston._max_length;
    largePiston._length = largePiston._max_length;

    // When: PIS_get_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_get_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(smallPiston._max_length, smallPiston._length);
    TEST_ASSERT_EQUAL_DOUBLE(largePiston._max_length, largePiston._length);    
}

void test_PIS_get_length_should_return_valid_small_large_length_for_full_length_(void)
{
    // Given: Fully extended pistons
    double expected_length = smallPiston._max_length + largePiston._max_length;
    double actual_length = 0.0f;
    smallPiston._length = 0;
    largePiston._length = 0;

    // When: PIS_get_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_get_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(smallPiston._max_length, smallPiston._length);
    TEST_ASSERT_EQUAL_DOUBLE(largePiston._max_length, largePiston._length);
}