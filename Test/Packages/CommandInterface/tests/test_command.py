from LCPCommandInteface import LCPCommand, LCP_I2C_ADDR
import pytest
import i2cdriver




def mock_reset():
    pass

def mock_start(dev, rw):
    assert LCP_I2C_ADDR == dev
    assert EXPECTED_RW == rw

def mock_stop():
    pass

def mock_write(data):
    assert EXPECTED_DATA == data

def mock_read(length):
    assert EXPECTED_LENGTH ==length
    return EXPECTED_DATA


class mock_i2c:
    global EXPECTED_DEV
    global EXPECTED_READ_LENGTH
    global EXPECTED_READ_DATA
    def __init__(self, port, speed, pullups):
        pass
    def setspeed(self, s:int):
        pass
    def setpullups(self, s:int):
        pass
    def scan(self, silent=False):
        pass
    def reset(self):
        pass
    def start(self, dev, rw):
        assert EXPECTED_DEV == dev
        assert EXPECTED_RW == rw
    def read(self, l):
        assert EXPECTED_READ_LEN == l
        return EXPECTED_READ_DATA
    def write(self, bb):
        assert EXPECTED_WRITE_DATA == bb
    def stop(self):
        pass
    def regrd(self, dev, reg, fmt='B'):
        pass
    def regwr(dev, reg, vv):
        pass
    def monitor(s):
        pass
    def getstatus(s):
        pass

@pytest.fixture
def LCP(monkeypatch):
    monkeypatch.setattr(i2cdriver, "I2CDriver", mock_i2c)
    lcp = LCPCommand("COM1", LCP_I2C_ADDR)
    return lcp

def test_read_block_should_send_request_and_read_correctly(monkeypatch, LCP):
    # Given: A mocked I2C driver, data
    EXPECTED_ADDR = [1, 72]
    data = [2, 127]
    RETURN_DATA = data

    # When: read_block is successfully called
    # monkeypatch.setattr(i2cdriver.I2CDriver, "reset", mock_reset)
    EXPECTED_RW = 0
    # monkeypatch.setattr(i2cdriver.I2CDriver, "start", mock_start)
    # monkeypatch.setattr(i2cdriver.I2CDriver, "write", mock_write)
    # monkeypatch.setattr(i2cdriver.I2CDriver, "stop", mock_stop)
    # monkeypatch.setattr(i2cdriver.I2CDriver, "start", mock_read)
    # monkeypatch.setattr(i2cdriver.I2CDriver, "stop", mock_stop)
    retvals = LCP.read_block(EXPECTED_ADDR, 3)

    # Then
    assert retvals == EXPECTED_READ_DATA