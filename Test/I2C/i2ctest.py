import i2cdriver
import time
import struct
LCP_ADDR = 0x6C

def float_to_hex(f):
    return hex(struct.unpack('<I', struct.pack('<f', f))[0])

def float_to_bytearray(f):
    ba = bytearray(struct.pack("f", f))
    return [b for b in ba]
    

class LCP:
    def __init__(self, port):
        self._i2c = i2cdriver.I2CDriver(port, reset=True)
        self._i2c.reboot()
        self._i2c.setspeed(400)
        self._i2c.reset()

    def _write(self, offset, data):
        self._i2c.start(LCP_ADDR, 0)
        data.insert(0, offset)
        self._i2c.write(data)
        self._i2c.stop()
        self.wait_until_available()
        # self._i2c.stop()
        # self._i2c.reset()

    def _read(self, offset, length):
        self._i2c.start(LCP_ADDR, 0)
        self._i2c.write([offset])
        self._i2c.start(LCP_ADDR, 1)
        data = self._i2c.read(length)
        self._i2c.stop()
        return data

    def write_mode(self):
        print("Entering Write Mode")
        self._write(0x07, [0xA5])
        # self._i2c.start(0x6C, 0)
        # self._i2c.write([0x07, 0xA5])
        # self._i2c.stop()
    def reset(self):
        print("Resetting target")
        self._write(0x77, [0xCA])

    def read(self, startAddr=0, length=256):
        print(f"Read {length} bytes starting at 0x{startAddr}")
        
        # print(data)
        return self._read(startAddr, length)

    def extend(self, speed=100):
        print(f"Extend at {speed}")
        self._write(0x60, [ 0x01, 0x01, 0x00, 0x01])

    def retract(self, speed=100):
        print(f"Retract at {speed}")
        self._write(0x60, [0xFF, 0x01, 0x00, 0x01])

    def stop(self):
        print("Stop called")
        self._write(0x61, [0x00])

    def move_to_length(self, length):
        print(f"Move to {length} called")
        length = float_to_bytearray(length)
        self._write(0x20, length)


    def move_to_volume(self, volume):
        print(f"Move to {volume} called")
        volume = float_to_bytearray(volume)
        self._write(0x00, volume)

    def at_zero(self):
        data = lcp.read()
        if data[0x68] == 0:
            return False
        else:
            return True

    def is_available(self):
        scan = self._i2c.scan(silent=True)
        if scan:
            return True
        else:
            return False

    def wait_until_available(self):
        while not self.is_available():
            print(".",end="")
            time.sleep(1)
        print("")

def time_sleep(cnt):
    for i in range(cnt):
        print(cnt-i)
        time.sleep(1)

def read_data_array(lcp):
    data = lcp.read(0,256)
    print_data_array(data)

def print_data_array(data):
    d1 = [data[i:i+16] for i in range(0, len(data), 16)]
    idx = 0
    for d in d1:
        
        print(f"{idx.to_bytes(1,'big')}\t: {d}")

        idx += 1


def wait_for_i2c_available(lcp):
    while not lcp.is_available():
        # print("Not available")
        print(".",end="")
        time.sleep(1)
    print("")
    # lcp.reset()
    


if __name__ == "__main__":
    lcp = LCP("COM23")


# 
    lcp.write_mode()
    # wait_for_i2c_available(lcp)
    
    # lcp.move_to_volume(-1.0)
    # read_data_array(lcp)

    # lcp.move_to_volume(538.2)
    # read_data_array(lcp)

    # lcp.move_to_volume(540.8)

    # lcp.move_to_volume(538.0)
    # read_data_array(lcp)

    # lcp.move_to_volume(545.9)
    # lcp.move_to_volume(555.5)
    # lcp.move_to_volume(540.2)
    # lcp.move_to_volume(545.5)
    # lcp.move_to_volume(542.2)
    # lcp.move_to_volume(538.8)
    # # lcp.move_to_volume(600.0)
    # lcp.move_to_volume(-1.0)

    

    lcp.extend()
    # wait_for_i2c_available(lcp)

    time.sleep(5)
    lcp.stop()
    # wait_for_i2c_available(lcp)


    # lcp.retract()
    # wait_for_i2c_available(lcp)

    # lcp.stop()
    # wait_for_i2c_available(lcp)


    # lcp.move_to_volume(542.25)
    # wait_for_i2c_available(lcp)

    # lcp.extend()
    # wait_for_i2c_available(lcp)
    # time_sleep(2)

    # lcp.stop()
    # wait_for_i2c_available(lcp)
    
    # lcp.move_to_volume(-1.0)
    # wait_for_i2c_available(lcp)

    # lcp.reset()

    # time_sleep(3)
    # while not lcp.is_available():
    #     time_sleep(1)
    # # lcp.retract()
    
    # print_data_array(lcp.read())
 
    # i2c = i2cdriver.I2CDriver("COM23", reset=True)
    
    # try:
    #     i2c.setspeed(400)
    #     i2c.reset()

        # print(read_all(i2c))

        

        # print("Put in Write Mode")
        # i2c.start(0x6C, 0)
        # i2c.write([0x07, 0xA5])
        # i2c.stop()

        # print("Set serial number to PMEL0001")
        # i2c.start(0x6C, 0)
        # # i2c.write([0xF0, 0x23, 0x34, 0x45, 0x56])
        # i2c.write([0xF0, 0x50, 0x4d , 0x45, 0x4c, 0x30, 0x30, 0x30, 0x31,0x0A])
        # i2c.stop()
        # i2c.stop()

        # time_sleep(5)
        

        # print("Set PISTON FWD")
        # i2c.start(0x6C, 0)
        # i2c.write([0x60, 0x01, 0x01, 0x00, 0x01])
        # i2c.stop()
        # # i2c.stop()

        # time_sleep(3)

        # print("Stop PISTON")
        # # i2c.start(0x6C, 0)
        # # i2c.write([0x61, 0x00])
        # # i2c.stop()
        # # i2c.stop()

        # time_sleep(3)

        # print("Set PISTON REV")
        # i2c.start(0x6C, 0)
        # i2c.write([0x60, 0xFF, 0x01, 0x00, 0x01])
        # i2c.stop()

        # time_sleep(2)
        # print("Move to 1.0 inches")
        # i2c.start(0x6C, 0)
        # # i2c.write([0x20, 0x38, 0x80, 0x00, 0x00])
        # # i2c.write([0x20, 0x00, 0x00, 0x80, 0x38])
        # i2c.write([0x20, 0x00, 0x00, 0x80, 0x3f])
        # i2c.stop()

        # time.sleep(2)
        # print(read_all(i2c))
        # # 0000803f
        # # 0x3f800000

        # time.sleep(2)
        # print("Move to volume = 545.71234")
        # i2c.start(0x6C,0)
        # i2c.write([0x00, 0x97, 0x6d, 0x08, 0x44])
        # i2c.stop()


    # except Exception as e:
    #     print(e)
    # finally:
    #     i2c.stop()
    #     i2c.reset()
    #     del(i2c)
# print("Write Finished")
# time.sleep(2)
# print("Start Read")
# i2c.start(0x6C, 0)
# i2c.write([0x00])
# i2c.start(0x6C, 1)
# t = i2c.read(256)
# chunks = [t[i:i+8] for i in range(0, len(t), 8)]
# for chunk in chunks:
#     for c in chunk:
#         print(c, end=" ")
#         # print(f'{int.from_bytes(c, "little")}', endl=" ")
#     print("\n")
# print(f"Read Complete, data={t}")


