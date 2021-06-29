import struct
import mmap
import pprint

from collections import namedtuple

memory = {
    'VOL_SETPOINT_IN3': [0x00, 'float'],
    'VAR_WRITE': [0x07, 'uint8_t'],
    'VOL_TOTAL_IN3': [0x08, 'float'],
    'HOUSING_IN3': [0x0C, 'float'],
    'VOL_SMALL_PISTON_IN3': [0x18, 'float'],
    'VOL_LARGE_PISTON_IN3': [0x1C,'float'],
    'LEN_SETPOINT_IN': [0x20, 'float'],
    'LEN_TOTAL_IN': [0x28, 'float'],
    'LEN_SMALL_PISTON_IN': [0x38, 'float'],
    'LEN_LARGE_PISTON_IN': [0x3C, 'float'],
    'AREA_SMALL_PISTON': [0x48, 'float'],
    'AREA_LARGE_PISTON': [0x4C, 'float'],
    'PST_POSTION_MIN': [0x40, 'float'],
    'PST_POSITION_MAX': [0x44, 'float'],
    'PST_RATE': [0x48, 'float'],
    'PST_POSITION_IN' : [0x4C, 'float'],
    'PST_ENC_COUNTS': [0x50, 'float'],
    'TRV_DIR': [0x60, 'int8_t'],
    'TRV_ENG': [0x61, 'bool'],
    'USER_OVERRIDE': [0x63, 'bool'],
    'TRV_ZERO': [0x68, 'bool'],
    'TRV_FULL': [0x69, 'bool'],
    'TRV_MIN': [0x6A, 'bool'],
    'TRV_MAX': [0x6B, 'bool'],
    'PID_COEFF_P': [0x80, 'float'],
    'PID_COEFF_I': [0x84, 'float'],
    'BAT_RETCAP': [0x88, 'double'],
    'PID_COEFF_D': [0x90, 'float'],
    'PID_USED': [0x94, 'float'],
    'BAT_REPSOC': [0x98, 'double'],
    'BAT_VCELL': [0xA8, 'double'],
    'BAT_CURRENT': [0xB8, 'double'],
    'BAT_TTE': [0xC8, 'double'],
    'BAT_STATUS': [0xD8, 'double'],
    'YEAR_BUILT': [0xEF, 'uint16_t'],
    'SER_NUM': [0xF0, 'str8'],
    'SYS_ID': [0xE8,'str8'],
    'FIRM_MAJ': [0xFA, 'uint16_t'],
    'FIRM_MIN': [0xFC,'uint16_t'],
    'FIRM_BUILD': [0xFE,'uint16_t'],
}

memory = dict(sorted(memory.items(), key=lambda item: item[1], reverse=True))


def convert_memory_values(location:str, data:bytes) -> dict:
    """ Convert byte string from device to parsed dict

    Args:
        location (str): address read value
        data (bytes): byte string from device

    Returns:
        dict: memory values converted
    """
    mem = dict.fromkeys(memory.keys())

    while (location ) < 0xFF and len(data) > 0:
        for key in memory:
            if (location) == memory[key][0]:
                
                if memory[key][1] == 'bool':
                    offset = 1
                    value = struct.unpack('>?', data[:1])[0]
                elif memory[key][1] == 'uint8_t':
                    offset = 1
                    value = struct.unpack('>B', data[:1])[0]
                    # value = data[0]
                elif memory[key][1] == 'int8_t':
                    offset = 1
                    value = struct.unpack('>b', data[:1])[0]
                    # value = data[0]
                elif memory[key][1] == 'uint16_t':
                    offset = 2
                    value = struct.unpack('>H', data[:offset])[0]
                elif memory[key][1] == 'float':
                    offset = 4
                    value = struct.unpack('>f', data[:offset])[0]
                elif memory[key][1] == 'double':
                    offset = 8
                    value = struct.unpack('>d', data[:offset])[0]
                elif "str" in memory[key][1]:
                    offset = int(memory[key][1].replace('str',''))
                    value = data[:offset].decode('utf8')
                else:
                    offset = 1
                    value = None
                    
                location += offset
                data = data[offset:]
                if value:
                    mem[key] = value
                    break
        else:
            location += 1
            data = data[1:]
    return mem


def create_msg(key:str, value)->dict:
    """ Create message to send to microcontroller for write

    Creates the write message to send to the micro memory block

    Args:
        key (str): Memory value to access
        value (variable): Data to write to address(es)

    Returns:
        dict: address and byte string to send
    """
    if key in memory.keys():
        msg = b''
        if memory[key][1] == 'bool':
            msg = struct.pack('>?', value)
        elif memory[key][1] == 'int8_t':
            msg = struct.pack('>b', value)
        elif memory[key][1] == 'uint8_t':
            msg = struct.pack('>B', value)
        elif memory[key][1] == 'uint16_t':
            msg = struct.pack('>H', value)
        elif memory[key][1] == 'float':
            msg = struct.pack('>f', value)
        elif memory[key][1] == 'double':
            msg = struct.pack('>d', value)
        elif 'str' in memory[key][1]:
            msg = value.encode()
    return {'address': memory[key][0], 'data':msg}

def create_read_dict(key:str)->dict:
    """ Create message to send to microcontroller for read

    Creates the read message to send to access the micro memory block

    Args:
        key (str): Memory value to access

    Returns:
        dict: address and length of memory address
    """
    if key in memory.keys():
        msg = b''
        if memory[key][1] == 'bool':
            length = 1
        elif memory[key][1] == 'int8_t':
            length = 1
        elif memory[key][1] == 'uint8_t':
            length = 1
        elif memory[key][1] == 'uint16_t':
            length = 2
        elif memory[key][1] == 'float':
            length = 4
        elif memory[key][1] == 'double':
            length = 8
        elif 'str' in memory[key][1]:
            length = 8
    return {'address': memory[key][0], 'length':length}


if __name__ == "__main__":
    # data = b"\x00\x01\x00\x08\0x00\0x17"
    # location = 0xFA
    # mem = convert_memory_values(location, data)
    # print(mem)
    # data = [b'\xA5']
    # location = 0x07
    # mem = convert_memory_values(location, data)
    # pprint.pprint(mem)

    # data = b'\x42\x05\x33\x33'
    # location = 0x08
    # mem = convert_memory_values(location, data)
    # pprint.pprint(mem)


    # data = b"\x00\x01\x00\x08\x00\x17"
    # location = 0xFA

    # # When: convert_memory_values is called
    # mem = convert_memory_values(location, data)

    # data =  b'\x42\x05\x33\x33\x00\x00\x00\x77\x42\x05\x33\x33\x43\x00\xca\x3d'
    # data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x41\xe6\x51\xec\x42\xc8\x00\x00'
    # data += b'\x41\x0e\x38\xda\x00\x00\x00\x00\x40\xb0\x00\x00\x40\x20\x00\x00'
    # data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x3f\xb3\x33\x33\x41\x53\x33\x33'
    # data += b'\x3e\x19\x99\x9a\x41\x3b\x33\x33\x00\x00\x00\x00\x41\x00\x00\x00'
    # data += b'\x00\x01\xeb\x24\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    # data += b'\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    # data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    # data += b'\x3d\xfc\xb9\x24\x04\x01\x49\xbc\x3f\xbe\xb8\x51\xeb\x85\x1e\xb8'
    # data += b'\x43\x00\xc9\xad\x00\x00\x00\x00\x3f\xf0\x00\x00\x00\x00\x00\x00'
    # data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x40\x2a\x93\xfa\x78\xac\x8f\x15'
    # data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x3f\xbc\x71\xc7\x1c\x65\x8f\x9d'
    # data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    # data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x41\x2e\xd3\x6a\x00\x00\x00\x00'
    # data += b'\x00\x00\x00\x00\x00\x00\x00\x00\x4c\x43\x50\x2d\x50\x49\x53\x00'
    # data += b'\x4c\x43\x50\x30\x30\x30\x31\x30\x07\xe5\x00\x01\x00\x08\x00\x17'

    # location = 0x00

    # # When: convert_memory_values is called
    # mem = convert_memory_values(location, data)

    # Given: a command of True
    val = True

    # When: Call to create_msg with value
    msg = create_msg("TRV_ENG", val)