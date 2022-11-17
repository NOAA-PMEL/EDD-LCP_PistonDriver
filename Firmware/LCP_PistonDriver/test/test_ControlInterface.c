#include "unity.h"
#include "ControlInterface.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_CIF_FrameDecoder_should_decode_valid_msg(void)
{
    // Given: A valid Frame with 
    uint8_t frame[8] = {
                FRAME_START_CHAR,
                0x01,
                0x00,
                0x01,
                0x37,
                0x00,
                0x6A,
                0xBF,
                0x4A,
                0x82
            }

    // When: CIF_FrameDecoder is called
    
    // Then:
    
}