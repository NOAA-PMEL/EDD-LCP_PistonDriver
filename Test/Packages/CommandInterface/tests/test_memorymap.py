
from _pytest.python_api import approx
import pytest
from LCPMemoryMap import convert_memory_values


def test_memory_map_convert_value_should_return_valid_dict_for_firmware_version():
    # Given: data @ 0xFA - 0xFF
    data = b"\x00\x01\x00\x08\x00\x17"
    location = 0xFA

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: 
    assert (1, 8, 23) == (mem['FIRM_MAJ'], mem['FIRM_MIN'], mem['FIRM_BUILD'])


def test_memory_map_convert_value_should_return_valid_serial_num():
    # Given: sn = PMEL0010
    data = b'\x4c\x43\x50\x30\x30\x30\x31\x30'
    location = 0xF0

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: 
    assert "LCP00010" == mem['SER_NUM']

def test_memory_map_convert_value_should_return_valid_sys_id():
    # Given: sn = PMEL0010
    data = b'\x4c\x43\x50\x2d\x50\x49\x53'
    location = 0xE8

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: 
    assert "LCP-PIS" == mem['SYS_ID']

def test_memory_map_convert_value_should_return_valid_trv_dir_int():
    # Given: trv_dir = -1
    data = [b'\xFF']
    location = 0x60

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_dir should be -1
    assert -1 == mem['TRV_DIR']

def test_memory_map_convert_value_should_return_valid_trv_eng_bool():
    # Given: trv_eng = True
    data = [b'\x01']
    location = 0x61

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_eng should be True
    assert True == mem['TRV_ENG']


def test_memory_map_convert_values_should_return_valid_var_write_uint8():
    # Given: var_write = 0xA5
    data = [b'\xA5']
    location = 0x07

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_eng should be True
    assert 0xA5 == mem['VAR_WRITE']

def test_memory_map_convert_values_should_return_valid_vol_total_float():
    # Given: vol_total_in3 = 33.3
    data = b'\x42\x05\x33\x33'
    location = 0x08

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_eng should be True
    
    assert 33.3 == approx(mem['VOL_TOTAL_IN3'], abs=0.1)