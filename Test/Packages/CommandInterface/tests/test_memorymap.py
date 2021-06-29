
import pytest
from LCPMemoryMap import convert_memory_values, create_msg, create_read_dict

@pytest.mark.decode
def test_memory_map_convert_value_should_return_valid_dict_for_firmware_version():
    # Given: data @ 0xFA - 0xFF
    data = b"\x00\x01\x00\x08\x00\x17"
    location = 0xFA

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: 
    assert (1, 8, 23) == (mem['FIRM_MAJ'], mem['FIRM_MIN'], mem['FIRM_BUILD'])

@pytest.mark.decode
def test_memory_map_convert_value_should_return_valid_serial_num():
    # Given: sn = PMEL0010
    data = b'\x4c\x43\x50\x30\x30\x30\x31\x30'
    location = 0xF0

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: 
    assert "LCP00010" == mem['SER_NUM']

@pytest.mark.decode
def test_memory_map_convert_value_should_return_valid_sys_id():
    # Given: sn = PMEL0010
    data = b'\x4c\x43\x50\x2d\x50\x49\x53'
    location = 0xE8

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: 
    assert "LCP-PIS" == mem['SYS_ID']

@pytest.mark.decode
def test_memory_map_convert_value_should_return_valid_trv_dir_int():
    # Given: trv_dir = -1
    data = b'\xFF'
    location = 0x60

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_dir should be -1
    assert -1 == mem['TRV_DIR']

@pytest.mark.decode
def test_memory_map_convert_value_should_return_valid_trv_eng_bool():
    # Given: trv_eng = True
    data = b'\x01'
    location = 0x61

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_eng should be True
    assert True == mem['TRV_ENG']

@pytest.mark.decode
def test_memory_map_convert_values_should_return_valid_var_write_uint8():
    # Given: var_write = 0xA5
    data = b'\xA5'
    location = 0x07

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_eng should be True
    assert 0xA5 == mem['VAR_WRITE']

@pytest.mark.decode
def test_memory_map_convert_values_should_return_valid_vol_total_float():
    # Given: vol_total_in3 = 33.3
    data = b'\x42\x05\x33\x33'
    location = 0x08

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_eng should be True
    
    assert 33.3 == pytest.approx(mem['VOL_TOTAL_IN3'], abs=0.1)

@pytest.mark.decode
def test_memory_map_convert_values_should_return_valid_bat_retcap_double():
    # Given: vol_total_in3 = 33.3
    data = b'\x3f\xbe\xb8\x51\xeb\x85\x1e\xb8'
    location = 0x88

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_eng should be True
    
    assert 0.12 == pytest.approx(mem['BAT_RETCAP'], abs=0.001)

@pytest.mark.decode
def test_memory_map_convert_values_should_convert_entire_memory_block():
    # Given: full memory block
    data =  b'\x42\x05\x33\x33\x00\x00\x00\x77\x42\x05\x33\x33\x43\x00\xca\x3d'
    data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x41\xe6\x51\xec\x42\xc8\x00\x00'
    data += b'\x41\x0e\x38\xda\x00\x00\x00\x00\x40\xb0\x00\x00\x40\x20\x00\x00'
    data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x3f\xb3\x33\x33\x41\x53\x33\x33'
    data += b'\x3e\x19\x99\x9a\x41\x3b\x33\x33\x00\x00\x00\x00\x41\x00\x00\x00'
    data += b'\x00\x01\xeb\x24\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    data += b'\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    data += b'\x3d\xfc\xb9\x24\x04\x01\x49\xbc\x3f\xbe\xb8\x51\xeb\x85\x1e\xb8'
    data += b'\x43\x00\xc9\xad\x00\x00\x00\x00\x3f\xf0\x00\x00\x00\x00\x00\x00'
    data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x40\x2a\x93\xfa\x78\xac\x8f\x15'
    data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x3f\xbc\x71\xc7\x1c\x65\x8f\x9d'
    data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x41\x2e\xd3\x6a\x00\x00\x00\x00'
    data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x4c\x43\x50\x2d\x50\x49\x53\x00'
    data += b'\x4c\x43\x50\x30\x30\x30\x31\x30\x07\xe5\x00\x01\x00\x08\x00\x17'
    
    location = 0x00

    # When: convert_memory_values is called
    mem = convert_memory_values(location, data)

    # Then: trv_eng should be True
    assert 0.12 == pytest.approx(mem['BAT_RETCAP'], abs=0.001)
    assert (1, 8, 23) == (mem['FIRM_MAJ'], mem['FIRM_MIN'], mem['FIRM_BUILD']) 


@pytest.mark.encode
def test_memory_map_create_msg_should_create_trv_eng_bool():
    # Given: a command of True
    val = True

    # When: Call to create_msg with value
    msg = create_msg("TRV_ENG", val)

    assert b'\x01' == msg['data']

@pytest.mark.encode
def test_memory_map_create_msg_should_create_trv_dir_int():
    # Given: a command of True
    val = -1

    # When: Call to create_msg with value
    msg = create_msg("TRV_DIR", val)

    assert b'\xFF' == msg['data']

@pytest.mark.encode
def test_memory_map_create_msg_should_create_var_write_uint8_t():
    # Given: a command of True
    val = 0x7F

    # When: Call to create_msg with value
    msg = create_msg("VAR_WRITE", val)

    assert b'\x7F' == msg['data']

@pytest.mark.encode
def test_memory_map_create_msg_should_create_year_built_uint16_t():
    # Given: a command of True
    val = 2027

    # When: Call to create_msg with value
    msg = create_msg("YEAR_BUILT", val)

    assert b'\x07\xEB' == msg['data']

@pytest.mark.encode
def test_memory_map_create_msg_should_create_pid_coeff_p_float():
    # Given: a command of True
    val = 3.1723

    # When: Call to create_msg with value
    msg = create_msg("PID_COEFF_P", val)

    assert b'\x40\x4b\x06\xf7' == msg['data']

@pytest.mark.encode
def test_memory_map_create_msg_should_create_bat_vcell_double():
    # Given: a command of True
    val = 13.723289342

    # When: Call to create_msg with value
    msg = create_msg("BAT_VCELL", val)

    assert b'\x40\x2b\x72\x52\xfb\x0a\xde\xe7' == msg['data']


@pytest.mark.encode
def test_memory_map_create_msg_should_create_ser_num_str8():
    # Given: a command of True
    val = 'PMEL1234'

    # When: Call to create_msg with value
    msg = create_msg("SER_NUM", val)

    assert b'\x50\x4d\x45\x4c\x31\x32\x33\x34' == msg['data']

@pytest.mark.encode
def test_memory_map_create_read_dict_should_create_pst_rate_float():
    # Given: a request for pst_rate
    expected_dict = {'address':0x48, 'length':4}

    # When: the create_read_dict is called
    msg = create_read_dict('PST_RATE')

    # Then: dict should be correct
    assert expected_dict == msg