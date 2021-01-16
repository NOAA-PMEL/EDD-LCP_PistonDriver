#include "unity.h"
#include <stdlib.h>
#include "memory.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_MEM_Write_RAM_struct_should_write_all_values(void)
{
    // Given: A 256-byte block of values
    uint8_t mem_to_cpy[256];
    for(uint16_t i=0;i<256;i++)
    {
        mem_to_cpy[i] = 0xFF;
    }
    eRamTypes_t selected = MEM_RAM_2;

    // When: MEM_Write_RAM_Struct
    MEM_Write_RAM_Struct(selected, 0x00, mem_to_cpy, 256);
    
    // Then:
    union num {uint32_t x; float y;};
    union num n;
    n.x = 0xFFFFFFFF;
    // printf("%lf, %lx\n", n.y, n.x);
    // n.y = *RAM2.BAT_RetCAP;
    // printf("%lf, %lx", n.y, n.x);
    TEST_ASSERT_EQUAL_FLOAT(n.y, *PistonProtocolRam.RAM2->BAT_RetCAP);

    
}

void test_MEM_Write_RAM_struct_should_write_all_values_not_ff(void)
{
    // Given: A 256-byte block of values
    uint8_t mem_to_cpy[256];
    for(uint16_t i=0;i<256;i++)
    {
        mem_to_cpy[i] = 0xA3;
    }
    eRamTypes_t selected = MEM_RAM_2;

    // When: MEM_Write_RAM_Struct
    MEM_Write_RAM_Struct(selected, 0x00, mem_to_cpy, 256);
    
    // Then:
    union num {uint32_t x; float y;};
    union num n;
    n.x = 0xA3A3A3A3;
    TEST_ASSERT_EQUAL_FLOAT(n.y, *PistonProtocolRam.RAM2->BAT_RetCAP);

    
}
