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

    PIS_Init();
    
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


void test_PIS_Read_length_should_return_valid_length_full_length(void)
{
    // Given: Fully extended pistons
    double expected_length = smallPiston._max_length + largePiston._max_length;
    double actual_length = -1.0f;
    smallPiston._length = smallPiston._max_length;
    largePiston._length = largePiston._max_length;

    // When: PIS_Read_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_Read_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, actual_length);
    
}

void test_PIS_Read_length_should_return_valid_length_for_zero_length_(void)
{
    // Given: Fully extended pistons
    double expected_length = 0.0f;
    double actual_length = 0.0f;
    smallPiston._length = smallPiston._max_length;
    largePiston._length = largePiston._max_length;

    // When: PIS_Read_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_Read_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, actual_length);
    
}

void test_PIS_Read_length_should_return_valid_small_large_length_for_zero_length_(void)
{
    // Given: Fully extended pistons
    double expected_length = 0.0f;
    double actual_length = -1.0f;
    smallPiston._length = smallPiston._max_length;
    largePiston._length = largePiston._max_length;

    // When: PIS_Read_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_Read_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(0.0f, smallPiston._length);
    TEST_ASSERT_EQUAL_DOUBLE(0.0f, largePiston._length);    
}

void test_PIS_Read_length_should_return_valid_small_large_length_for_full_length_(void)
{
    // Given: Fully extended pistons
    double expected_length = smallPiston._max_length + largePiston._max_length;
    double actual_length = 0.0f;
    smallPiston._length = 0;
    largePiston._length = 0;

    // When: PIS_Read_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_Read_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(smallPiston._max_length, smallPiston._length);
    TEST_ASSERT_EQUAL_DOUBLE(largePiston._max_length, largePiston._length);
}

void test_PIS_Read_length_should_return_valid_small_large_length_for_partial_full_length_(void)
{
    // Given: Fully extended small piston, partial large
    double expected_length = smallPiston._max_length + largePiston._max_length/3;
    double actual_length = 0.0f;
    smallPiston._length = 0;
    largePiston._length = 0;

    // When: PIS_Read_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_Read_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(smallPiston._max_length, smallPiston._length);
    TEST_ASSERT_EQUAL_DOUBLE(largePiston._max_length/3, largePiston._length);
}

void test_PIS_Read_length_should_return_valid_small_large_length_for_partial_small_length_(void)
{
    // Given: Partial extended small piston, no large
    double expected_length = smallPiston._max_length/3;
    double actual_length = 0.0f;
    smallPiston._length = 0;
    largePiston._length = 0;

    // When: PIS_Read_length() called
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_Read_length();

    // Then: Valid full length returned
    TEST_ASSERT_EQUAL_DOUBLE(smallPiston._max_length/3, smallPiston._length);
    TEST_ASSERT_EQUAL_DOUBLE(0, largePiston._length);
}


void test_PIS_Read_volume_should_return_valid_volume_full_extension(void)
{
    // Given: Fully extended piston
    double expected_volume = SMALL_PISTON_MAX_LENGTH * SMALL_PISTON_DIAMETER * PI;
    expected_volume += LARGE_PISTON_MAX_LENGTH * LARGE_PISTON_DIAMETER * PI;
    expected_volume += HOUSING_DIAMETER * PI * HOUSING_LENGTH;
    double actual_volume = -1.0f;
    double extension_length =SMALL_PISTON_MAX_LENGTH + LARGE_PISTON_MAX_LENGTH;
   
   // When: PIS_Read_volume() is called
    ENC_Get_Length_ExpectAndReturn(extension_length);
    actual_volume = PIS_Read_volume();

    // Then: valid full length returned
    TEST_ASSERT_DOUBLE_WITHIN(0.1, expected_volume, actual_volume);
    
}

void test_PIS_Read_volume_should_return_valid_volume_zero_extension(void)
{
    // Given: Fully extended piston
    double expected_volume = HOUSING_DIAMETER * PI * HOUSING_LENGTH;
    double actual_volume = -1.0f;
    double extension_length = 0.0f;
    smallPiston._length = 0.0f;
    largePiston._length = 0.0f;

    // When: PIS_Read_volume() is called
    ENC_Get_Length_ExpectAndReturn(extension_length);
    actual_volume = PIS_Read_volume();

    // Then: valid full length returned
    TEST_ASSERT_DOUBLE_WITHIN(0.1, expected_volume, actual_volume);
    
}


void test_PIS_Enable_should_enable_hbridge(void)
{
    // Given: 

    // When: PIS_Enabel called
    DRV8874_enable_Expect();
    PIS_Enable();
    // Then: DRV8874_enable() called
    TEST_PASS();
}

void test_PIS_Disable_should_disable_hbridge(void)
{
    // Given:
    // WHen: PIS_Disable() called
    DRV8874_disable_Expect();
    PIS_Disable();

    // Then: DRV8874_disable() called
    TEST_PASS();
}

void test_PIS_Run_should_call_run_fwd_if_fwd_commanded(void)
{
    // Given:
    // When: PIS_Run(PisRunFwd) called
    DRV8874_forward_Expect();
    _PIS_Run(PISRunFwd);

    // Then: HBridge Forward called
    TEST_PASS();
}

void test_PIS_Run_should_call_run_rev_if_rev_commanded(void)
{
    // Given:
    // When: PIS_Run(PisRunRev) called
    DRV8874_reverse_Expect();
    _PIS_Run(PISRunRev);

    // Then: HBridge Reverse called
    TEST_PASS();
}

void test_PIS_Run_should_call_run_stop_if_stop_commanded(void)
{
    // Given:
    // When: PIS_Run(PisRunRev) called
    DRV8874_stop_Expect();
    _PIS_Run(PISRunStop);

    // Then: HBridge Reverse called
    TEST_PASS();
}


void test_PIS_Write_length_should_write_valid_zero_setpoint(void)
{
    // Given: A valid setpoint of 0
    double setpoint = 0.0f;
    actuator.setpoint = 4.3;
    actuator.range = 0.005f;
    actuator.conversion_factor = 10000;

    // When: PIS_Write_length is called
    PIS_Write_length(setpoint);

    // Then: the setpoint and encoder min/max are written
    TEST_ASSERT_EQUAL_DOUBLE(setpoint, actuator.setpoint);
    TEST_ASSERT_INT32_WITHIN(1,-50, actuator.enc_min);
    TEST_ASSERT_INT32_WITHIN(1, 50, actuator.enc_max);
}

void test_PIS_Write_length_should_write_valid_full_setpoint(void)
{
    // Given: A valid setpoint of full
    double setpoint = SMALL_PISTON_MAX_LENGTH + LARGE_PISTON_MAX_LENGTH;
    actuator.setpoint = 0.0f;
    actuator.range = 0.005f;
    actuator.conversion_factor = 10000;

    int32_t setpoint_cnts = setpoint * actuator.conversion_factor;
    int32_t min_cnts = setpoint_cnts - actuator.range*actuator.conversion_factor;
    int32_t max_cnts = setpoint_cnts + actuator.range*actuator.conversion_factor;
    
    // When: PIS_Write_length is called
    PIS_Write_length(setpoint);

    // Then: the setpoint and encoder min/max are written 
    TEST_ASSERT_EQUAL_DOUBLE(setpoint, actuator.setpoint);
    TEST_ASSERT_INT32_WITHIN(1, min_cnts, actuator.enc_min);
    TEST_ASSERT_INT32_WITHIN(1, max_cnts, actuator.enc_max);

}

void test_PIS_Write_volume_should_calculate_and_set_correct_length_zero(void)
{
    // Given: A valid volume of zero extension
    double volume = HOUSING_DIAMETER * PI * HOUSING_LENGTH;
    double expected_length = 0.0f;
    
    actuator.setpoint = 4.3;
    actuator.range = 0.005f;
    actuator.conversion_factor = 10000;
    int32_t expected_min = -actuator.range * actuator.conversion_factor;
    int32_t expected_max = actuator.range * actuator.conversion_factor;
    
    // When: PIS_Write_volume() is called
    PIS_Write_volume(volume);

    // Then: The setpoint and encoder min/max are written
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, actuator.setpoint);
    TEST_ASSERT_INT32_WITHIN(1, expected_min, actuator.enc_min);
    TEST_ASSERT_INT32_WITHIN(1, expected_max, actuator.enc_max);
}

void test_PIS_Write_volume_should_calculate_and_set_correct_length_full(void)
{
    // Given: A valid volume of zero extension
    double volume = housing._max_volume + smallPiston._max_volume + largePiston._max_volume;
    
    actuator.setpoint = 4.3;
    actuator.range = 0.005f;
    actuator.conversion_factor = 10000;
    double expected_length = SMALL_PISTON_MAX_LENGTH + LARGE_PISTON_MAX_LENGTH;
    int32_t expected_length_cnt = expected_length*actuator.conversion_factor;
    int32_t expected_min = expected_length_cnt - actuator.range * actuator.conversion_factor;
    int32_t expected_max = expected_length_cnt + actuator.range * actuator.conversion_factor;
    
    // When: PIS_Write_volume() is called
    PIS_Write_volume(volume);

    // Then: The setpoint and encoder min/max are written
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, actuator.setpoint);
    TEST_ASSERT_INT32_WITHIN(1, expected_min, actuator.enc_min);
    TEST_ASSERT_INT32_WITHIN(1, expected_max, actuator.enc_max);
}

void test_PIS_Read_current_should_return_valid_current(void)
{
    // Given:
    float expected_current = 2.7;
    float actual_current = 0.0f;

    // When: A call to the HBridge Current sensor is made
    DRV8847_read_current_ExpectAndReturn(expected_current);
    actual_current = PIS_Read_current();

    // Then: 
    TEST_ASSERT_EQUAL_DOUBLE(expected_current, actual_current);
}

void test_PIS_Read_should_call_length_and_return_value(void) 
{
    // Given: 
    double expected_length = 0.0f;
    double actual_length = 3.4f;

    // When:
    ENC_Get_Length_ExpectAndReturn(expected_length);
    actual_length = PIS_Read(PISReadLength);

    // Then: Valid zero length returned
    TEST_ASSERT_EQUAL_DOUBLE(expected_length, actual_length);
    
}

void test_PIS_Read_should_call_volume_and_return_value(void) 
{
    // Given: 
    double expected_volume = HOUSING_VOLUME;
    double length = 0.0f;
    double actual_volume = 3.4f;

    // When:
    ENC_Get_Length_ExpectAndReturn(length);
    actual_volume = PIS_Read(PISReadVolume);

    // Then: Valid zero length returned
    TEST_ASSERT_DOUBLE_WITHIN(0.001, expected_volume, actual_volume);
    
}


void test_PIS_Run_to_volume_should_send_command_and_run(void)
{
    // Given: A volume larger than the current volume
    double setpoint = SYSTEM_MAX_VOLUME;
    actuator.current_length = 0.2f;
    smallPiston._diameter = SMALL_PISTON_DIAMETER;
    largePiston._diameter = LARGE_PISTON_DIAMETER;
    ePistonRunError_t error;

    // When: The PIS_run_to_volume() is called
    DRV8874_forward_Expect();
    

    DRV8847_read_current_ExpectAndReturn(2.0f);
    // DRV8847_read_current_ExpectAndReturn(1.0f);
    // DRV8847_read_current_ExpectAndReturn(0.0f);
    // actuator.setpoint_flag = true;
    error = PIS_Run_to_volume(setpoint);

    // Then:
    TEST_ASSERT_EQUAL(PISErrorNone, error);


}