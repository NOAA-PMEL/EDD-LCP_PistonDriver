import struct
import mmap
import pprint

from collections import namedtuple

memory = {
    'VOL_SETPOINT_IN3': [0x00, 4, 'float'],
    'VAR_WRITE': [0x07, 1, 'uint8_t'],
    'VOL_TOTAL_IN3': [0x08, 4, 'float'],
    'HOUSING_IN3': [0x0C, 4, 'float'],
    'VOL_SMALL_PISTON_IN3': [0x18,4,'float'],
    'VOL_LARGE_PISTON_IN3': [0x1C,4,'float'],
    'LEN_PISTON_IN': [0x20, 4, 'float'],
    'LEN_SMALL_PISTON_IN': [0x28, 4, 'float'],
    'LEN_LARGE_PISTON_IN': [0x2C, 4, 'float'],
    'AREA_SMALL_PISTON': [0x38, 4, 'float'],
    'AREA_LARGE_PISTON': [0x3C, 4, 'float'],
    'PST_POSTION_MIN': [0x40, 4, 'float'],
    'PST_POSITION_MAX': [0x44, 4, 'float'],
    'PST_RATE': [0x48, 4, 'float'],
    'PST_POSITION_IN' : [0x4C, 4, 'float'],
    'PST_ENC_COUNTS': [0x50, 4, 'float'],
    'TRV_DIR': [0x60, 1, 'int8_t'],
    'TRV_ENG': [0x61, 1, 'bool'],
    'USER_OVERRIDE': [0x63, 1, 'bool'],
    'TRV_ZERO': [0x68, 1, 'bool'],
    'TRV_MAX': [0x69, 1, 'bool'],
    'PID_COEFF_P': [0x80, 4, 'float'],
    'PID_COEFF_I': [0x84, 4, 'float'],
    'BAT_RETCAP': [0x88, 8, 'double'],
    'PID_COEFF_D': [0x90, 4, 'float'],
    'PID_USED': [0x94, 4, 'float'],
    'BATT_REPSOC': [0x98, 8, 'double'],
    'BATT_VCELL': [0xA8, 8, 'double'],
    'BATT_CURRENT': [0xB8, 8, 'double'],
    'BATT_TTE': [0xC8, 8, 'double'],
    'BATT_STATUS': [0xD8, 8, 'double'],
    'YEAR_BUILT': [0xEF, 2, 'uint16_t'],
    'SER_NUM': [0xF0, 8, 'str8'],
    'SYS_ID': [0xE8, 8, 'str8'],
    'FIRM_MAJ': [0xFA,2, 'uint16_t'],
    'FIRM_MIN': [0xFC, 2, 'uint16_t'],
    'FIRM_BUILD': [0xFE, 2, 'uint16_t'],
}

memory = dict(sorted(memory.items(), key=lambda item: item[1], reverse=True))


def convert_memory_values(location, data):
    mem = dict.fromkeys(memory.keys())

    while (location ) < 0xFF and len(data) > 0:
        for key in memory:
            if (location) == memory[key][0]:
                
                if memory[key][2] == 'bool':
                    value = struct.unpack('>?', data[0])[0]
                    mem[key] = value
                    location += 1
                    data[1:]
                    break
                elif memory[key][2] == 'uint8_t':
                    value = struct.unpack('>B', data[0])[0]
                    mem[key] = value
                    location += 1
                    data = data[1:]
                    break
                elif memory[key][2] == 'int8_t':
                    value = struct.unpack('>b', data[0])[0]
                    mem[key] = value
          
                    location += 1
                    data =data[1:]
                    break
                elif memory[key][2] == 'uint16_t':
                    t_data = data[:2]
                    value = struct.unpack('>H', t_data)
                    mem[key] = value[0]
                    location += 2
                    data = data[2:]
                    break
                elif memory[key][2] == 'float':
                    value = struct.unpack('>f', data[:4])
                    mem[key] = value[0]
                    location += 4
                    data = data[4:]
                    break
                elif "str" in memory[key][2]:
                    length = int(memory[key][2].replace('str',''))
                    t_data = data[:length].decode('utf8')
                    mem[key] = t_data
                    location += length
                    data = data[length:]
                else:
                    location += 1
                    data = data[1:]
                    break
        else:
            location += 1
            data = data[1:]
    
    # pprint.pprint(mem)
    return mem


if __name__ == "__main__":
    # data = b"\x00\x01\x00\x08\0x00\0x17"
    # location = 0xFA
    # mem = convert_memory_values(location, data)
    # print(mem)
    data = [b'\xA5']
    location = 0x07
    mem = convert_memory_values(location, data)
    pprint.pprint(mem)

    data = b'\x42\x05\x33\x33'
    location = 0x08
    mem = convert_memory_values(location, data)
    pprint.pprint(mem)