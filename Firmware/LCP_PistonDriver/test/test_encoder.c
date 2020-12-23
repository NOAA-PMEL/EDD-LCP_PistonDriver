#include "unity.h"
#include "encoder.h"
#include "config.h"
#include "mock_bsp.h"
#include "mock_bsp_esi.h"

void setUp(void)
{
}

void tearDown(void)
{
    // encSettings.min_count = 0;
    // encSettings.max_count = ENCODER_MAX_COUNT_DEFAULT;
    ENC_FactoryReset();
}

void test_encoder_init_should_call_bsp_init(void) {
    // Given 

    // When 
    // esiConfig_Expect();
    esiConfig_Expect();
    ENC_Init();

    // Then
    TEST_PASS();
}

void test_encoder__clear_enc_counter_should_set_global_to_zero(void) {
    // Given
    g_encoder_counter = 9876543;
    
    // When
    _clear_enc_counter();

    // Then
    TEST_ASSERT_EQUAL_UINT32(0, g_encoder_counter);
}

void test_encoder__set_max_enc_counter_should_set_to_max_of_struct(void) {
    // Given
    g_encoder_counter = 12345;

    // When 
    _set_max_enc_counter();

    // Then
    TEST_ASSERT_EQUAL_INT32(SYS_ENCODER_MAX_COUNT_DEFAULT, g_encoder_counter);
}

void test_encoder__clear_enc_counter_should_set_global_to_num_if_num_is_not_zero(void) {
    // Given: Modify encSettings to have min_count = 10
    encSettings.min_count = 10;

    // When: _clear_enc_counter() is called 
    _clear_enc_counter();

    // Then: g_encoder_counter should == 10
    TEST_ASSERT_EQUAL_INT32(10, g_encoder_counter);
    

}

void test_encoder_reset_should_take_back_to_factory_reset(void) {
    // Given: encSettings are not "original"
    encSettings.min_count = 321u;
    encSettings.max_count = 456u;
    encSettings.distance = 32u;
    encSettings.length = 40.0f;

    // When: ENC_Reset() is called
    ENC_FactoryReset();

    // Then: encSettings are returned to "original"
    TEST_ASSERT_EQUAL_INT32(ENCODER_MIN_COUNT_DEFAULT, encSettings.min_count);
    TEST_ASSERT_EQUAL_INT32(ENCODER_MAX_COUNT_DEFAULT, encSettings.max_count);
    TEST_ASSERT_EQUAL_INT32(ENCODER_MAX_COUNT_DEFAULT - ENCODER_MIN_COUNT_DEFAULT, encSettings.distance);
    TEST_ASSERT_EQUAL_FLOAT(ENCODER_LENGTH_DEFAULT, encSettings.length);
}

void test_encoder__set_max_count_should_fill_struct_with_val(void) {
    // Given: a value not equal to ENCODER_MAX_COUNT_DEFAULT
    int32_t test_val = 400000;
    bool test_response = false;
    
    // When: _set_max_count() is called
    test_response = _set_max_count(test_val);

    // Then: test should pass and encSettings.max_count == 400000
    TEST_ASSERT_TRUE(test_response);
    TEST_ASSERT_EQUAL_INT32(test_val, encSettings.max_count);
}

void test_encoder__set_max_count_should_not_accept_negative_numbers(void) {
    // Given: a negative value
    int32_t test_val = -4000;
    bool test_response = false;

    // when: _set_max_count() is called
    test_response = _set_max_count(test_val);

    // then: function fails, no change to encSettings
    TEST_ASSERT_FALSE(test_response);
    TEST_ASSERT_EQUAL_INT32(ENCODER_MAX_COUNT_DEFAULT, encSettings.max_count);

}

void test_encoder__set_max_count_should_not_accept_value_less_than_max_val(void) {
    // Given: a value less than encSttings.min_count
    int32_t test_val = 10;
    encSettings.min_count = 50;
    bool test_response = false;

    // when: _set_max_count() is called
    test_response = _set_max_count(test_val);

    // then: function fails, no change to encSettings
    TEST_ASSERT_FALSE(test_response);
    TEST_ASSERT_EQUAL_INT32(ENCODER_MAX_COUNT_DEFAULT, encSettings.max_count);

}

void test_encoder__set_min_count_should_fill_struct_with_val(void) {
    // Given: a value not equal to ENCODER_MIN_COUNT_DEFAULT
    int32_t test_val = 212;
    bool test_response = false;

    // when: _set_min_count() is called
    test_response = _set_min_count(test_val);

    // then: function should pass, min_count changes
    TEST_ASSERT_TRUE(test_response);
    TEST_ASSERT_EQUAL_INT32(encSettings.min_count, test_val);
}

void test_encoder__set_min_count_should_not_accept_negative_numbers(void) {
    // Given: a negative value
    int32_t test_val = -4000;
    bool test_response = false;

    // when: _set_max_count() is called
    test_response = _set_min_count(test_val);

    // then: function fails, no change to encSettings
    TEST_ASSERT_FALSE(test_response);
    TEST_ASSERT_EQUAL_INT32(ENCODER_MAX_COUNT_DEFAULT, encSettings.max_count);

}


void test_encoder__calculate_encoder_distance_should_calculate_dist_in_struct(void)
{
    // Given: Initial conditions suffice
    int32_t diff = ENCODER_MAX_COUNT_DEFAULT - ENCODER_MIN_COUNT_DEFAULT;

    // When: function _calculate_encoder_distance() is called
    _calculate_encoder_distance();

    // Then: Correct value is populated in struct
    TEST_ASSERT_EQUAL_INT32(diff, encSettings.distance);

}


void test_encoder__calculate_length_should_return_zero_for_0_position(void) {
    // Given: Initial condition of zero counts
    g_encoder_counter = 0;
    float response = 999.9f;
    encSettings.conversion_factor = 11.0f;

    // When: _calculate_length is called
    response = _calculate_length();

    // Then: length should be 0
    TEST_ASSERT_EQUAL_FLOAT(0.0f, response);
}

void test_encoder__calculate_length_should_return_max_for_max_position(void) {
    // Given: Initial condition of zero counts
    g_encoder_counter = encSettings.max_count;
    encSettings.distance = 0;
    float response = 999.9f;
    encSettings.conversion_factor = 11.0f / (ENCODER_MAX_COUNT_DEFAULT - ENCODER_MIN_COUNT_DEFAULT);

    // When: _calculate_length is called
    response = _calculate_length();

    // Then: length should be 0
    TEST_ASSERT_EQUAL_FLOAT(11.0f, response);
}

void test_encoder_Set_MaxLength_should_set_value(void) {
    // Given: Value of 12.0f
    float length = 12.0f;
    float c_factor = 12.0f / ENCODER_MAX_COUNT_DEFAULT;

    // When: ENC_Set_ConversionFactor is called
    ENC_Set_MaxLength(length);

    // Then: The struct is updated
    TEST_ASSERT_EQUAL_FLOAT(length, encSettings.length);
    TEST_ASSERT_EQUAL_FLOAT(c_factor, encSettings.conversion_factor);
}


void test_encoder_Get_Length_should_calculate_zero_defaults(void) {
    // Given: Encoder count of zero
    g_encoder_counter = 0u;

    // When: ENC_Get_Length() is called
    float length = ENC_Get_Length();

    // Then: Length == 0
    TEST_ASSERT_EQUAL_FLOAT(0.0f, length);
}

void test_encoder_Get_Length_should_calculate_max_defaults(void) {
    // Given: Encoder count of zero
    g_encoder_counter = ENCODER_MAX_COUNT_DEFAULT;

    // When: ENC_Get_Length() is called
    float length = ENC_Get_Length();

    // Then: Length == default max
    TEST_ASSERT_EQUAL_FLOAT(ENCODER_LENGTH_DEFAULT, length);
}

void test_encoder_Get_Length_should_calcaulte_mid_point(void) {
    // Given: Encoder at midpoint
    g_encoder_counter = ENCODER_MAX_COUNT_DEFAULT/2;

    // When: ENC_Get_Length() is called
    float length = ENC_Get_Length();

    // Then: length == default/2
    TEST_ASSERT_EQUAL_FLOAT(ENCODER_LENGTH_DEFAULT/2, length);
}

void test_encoder_Get_Length_should_calculate_zero_for_min_greater_zero(void) {
    // Given: min_counts = 10
    encSettings.min_count = 10;
    _calculate_encoder_distance();
    g_encoder_counter = 10;

    // When: ENC_Get_Length() is called
    float length = ENC_Get_Length();

    // Then: length == 0
    TEST_ASSERT_EQUAL_FLOAT(0, length);
}

void test_encoder_Get_Length_should_calculate_max_for_min_greater_zero(void) {
    // Given: min_counts = 50
    encSettings.min_count = 50;
    _calculate_encoder_distance();
    g_encoder_counter = ENCODER_MAX_COUNT_DEFAULT;

    // When: ENC_Get_Length() is called
    float length = ENC_Get_Length();

    // Then: length = max
    TEST_ASSERT_EQUAL_FLOAT(ENCODER_LENGTH_DEFAULT, length);

}
