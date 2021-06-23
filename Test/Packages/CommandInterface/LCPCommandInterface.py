import i2cdriver

LCP_I2C_ADDR = 0xCA
MAX_ADDR_LOC = 0x02FF

VOL_TOTAL_IN3 = 0x0000
VOL_SETPOINT_IN3 = 0x0004

PST_POSTIION_IN = 0x0010
PST_ENC_COUNTS = 0x0014
PST_RATE = 0x0018

TRV_DIR = 0x001C
TRV_ENG = 0x001D
TRV_ZERO = 0x001E
TRV_MAX = 0x001F

SYS_ID = 0x0080
SER_NUM = 0x0082
FIRM_MAJ = 0x0084
FIRM_MIN = 0x0086
FIRM_BUILD = 0x0088


class LCPCommand:
    def __init__(self, port:str, device=LCP_I2C_ADDR) -> None:
        self._i2c = i2cdriver.I2CDriver(port=port, speed=100, pullups=0)
        self._dev = device

    def read_block(self, addr:int, length:int):
        assert addr <= 0x02FF
        assert length <= (0x02FF - addr)

        if not self._i2c.start(self._dev, 0):
            self._i2c.stop()
            return None
        self._i2c.write(addr)
        self._i2c.stop()
        self._i2c.start(self._dev, 1)
        data = self._i2c.read(length)
        self._i2c.stop()

        return data

    def write_block(self, addr:int, data:[int], length:int):
        assert addr < MAX_ADDR_LOC
        assert len(data) <= (MAX_ADDR_LOC - addr)

        self._i2c.reset()
        self._i2c.start(self._dev, 0)
        self._i2c.write(addr)
        self._i2c.start(self._dev, 0)
        self._i2c.write(data)
        self._i2c.stop()