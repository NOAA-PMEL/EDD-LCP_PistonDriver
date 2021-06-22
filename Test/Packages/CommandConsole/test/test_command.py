from _pytest.fixtures import fixture
from _pytest.monkeypatch import monkeypatch
import pytest
import serial
from LCPPistonConsole import PistonConsole

def mockack(self):
        return b'\x06'
def mocknack(self):
        return b'\x15'

@fixture
def MockConsole(monkeypatch):
    def mockopen(value):
        print(value)
        
    monkeypatch.setattr(serial.Serial, "open", mockopen)
    pc = PistonConsole('COM1')
    return pc

def test_readline_should_read_line_from_serial(MockConsole, monkeypatch):
    # Given: A mocked serial readline
    pc = MockConsole
    def mockreturn(value):
        return b'this is a sample return\r'

    
    monkeypatch.setattr(serial.Serial, "readline", mockreturn)
    
    # When: the readline function is called
    # Then: The correct line is returned
    assert pc.readline() == "this is a sample return\r"



def test_set_function_should_accept_valid_key_and_value(MockConsole, monkeypatch):
    # Given: A valid key and value
    pc = MockConsole
    key = "vset"
    value = 8.443

    def mockwrite(self, setstr):
        assert b"set vset 8.443\r" == setstr
    monkeypatch.setattr(serial.Serial, "write", mockwrite)
    
    # When: The set function is called
    # Then: The function should work
    pc.set(key, value)


def test_set_function_should_fail_on_list_for_value(MockConsole, monkeypatch):
    # Given: A bad value (list)
    pc = MockConsole
    key = "vset"
    value = [3.3, 4.2]

    # When: The function is called
    # Then: A TypeError is thrown
    with pytest.raises(TypeError):
        pc.set(key, value)

def test_set_function_should_raise_error_for_key_outside_of_list(MockConsole):
    # Given: a bad key
    pc = MockConsole
    key = "vrbo"
    value = "Test"

    # When: The function is called
    # Then: A ValueError should be thrown
    with pytest.raises(ValueError):
        pc.set(key, value)

def test_get_function_should_raise_error_for_key_outside_of_list(MockConsole):
     # Given: a bad key
    pc = MockConsole
    key = "vrbo"

    # When: The function is called
    # Then: A ValueError should be thrown
    with pytest.raises(ValueError):
        pc.get(key)

def test_get_function_should_return_valid_string_for_valid_key(MockConsole, monkeypatch):
    # Given: A valid key and mocked serial call
    pc = MockConsole
    key = "vtotal"

    def mockwrite(self, value):
        assert "get vtotal\r" == value

    def mockread(self):
        return "12.312"

    monkeypatch.setattr(serial.Serial, "write", mockwrite)
    monkeypatch.setattr(serial.Serial, "readline", mockread)

    # When: The function is called
    retval = pc.get(key)

    # Then:  A valid response was returned
    assert "12.312" == retval
    

def test_ram_write_should_fail_for_invalid_addr(MockConsole):
    # Given: A bad address value
    pc=MockConsole
    addr= 0x0400
    value = [1, 2, 3]

    # When: the function is called
    # Then: an assert error should be thrown
    with pytest.raises(AssertionError):
        pc.ram_write(addr, value)

def test_ram_write_should_fail_for_valid_addr_and_values_and_NACK(MockConsole, monkeypatch):
    # Given: A valid address and data, mocked serial write
    pc=MockConsole
    addr=0x0100
    value=[0,255,44]

    def mockwrite(self, value):
        assert "set -r 0x0100 00ff2c\r"

    monkeypatch.setattr(serial.Serial, "write", mockwrite)
    monkeypatch.setattr(serial.Serial, "read", mocknack)

    # When: The function is called
    # Then: A system error should be thrown
    with pytest.raises(SystemError):
        pc.ram_write(addr, value)


def test_ram_write_should_pass_for_valid_addr_and_values_and_ACK(MockConsole, monkeypatch):
    # Given: A valid address and data, mocked serial write
    pc=MockConsole
    addr=0x0100
    value=[0,255,44]

    def mockwrite(self, value):
        assert "set -r 0x0100 00ff2c\r"

    monkeypatch.setattr(serial.Serial, "write", mockwrite)
    monkeypatch.setattr(serial.Serial, "read", mockack)

    # When: The function is called
    # Then: The function should work
    assert pc.ram_write(addr, value)


def test_ram_read_should_fail_for_invalid_addr(MockConsole):
    # Given: A bad address value
    pc=MockConsole
    addr = 0x3121
    length = 10

    # When: The function is called
    # Then: An asser error should be thrown
    with pytest.raises(AssertionError):
        pc.ram_read(addr, 10)

def test__is_ack_should_fail_for_not_ack(MockConsole):
    # Given: A non-ack character
    pc=MockConsole
    value = 'a'

    # When: The function is called
    retval = pc._is_ack(value)
    
    # Then: The return is False
    assert False == retval


def test__is_ack_should_pass_for_ack(MockConsole):
    # Given: An ack character
    pc=MockConsole
    value = 0x06

    # When: the function is called
    retval = pc._is_ack(value)

    # Then: The return is True
    assert True == retval

def test_ram_read_should_fail_for_NACK(MockConsole, monkeypatch):
    # Given: A NACK response
    pc=MockConsole
    addr = 0x02AC
    length = 1
    
    
    def mockwrite(self, value):
        assert "get -r 0x02AC 1\r"

    monkeypatch.setattr(serial.Serial, "write", mockwrite)
    monkeypatch.setattr(serial.Serial, "read", mocknack)

    # When: The function is called
    # Then: A System error should be thrown
    with pytest.raises(SystemError):
        pc.ram_read(addr, length)

def test_ram_read_should_fail_for_invalid_response_length(MockConsole, monkeypatch):
    # Given: An ACK response, but string too long
    pc=MockConsole
    addr = 0x02AC
    length = 3

    def mocklong(self):
        return b'F400FF1C\r'

    def mockwrite(self, value):
        assert "get -r 0x02AC 3\r"

    monkeypatch.setattr(serial.Serial, "write", mockwrite)
    monkeypatch.setattr(serial.Serial, "read", mockack)
    monkeypatch.setattr(serial.Serial, "readline", mocklong)

    # When: The function is called
    # Then: A Value Error is thrown
    with pytest.raises(ValueError):
        pc.ram_read(addr, length)


def test_ram_read_should_pass_for_all_valid(MockConsole, monkeypatch):
    # Given: A valid addr, length and ACK response
    pc=MockConsole
    addr = 0x02AC
    length = 3
    expected_list = [0Xf4, 0X00, 0Xff]

    def mockread(self):
        return b'F400FF\r'
    def mockwrite(self, value):
        assert "get -r 0x02AC 3\r"
    
    monkeypatch.setattr(serial.Serial, "write", mockwrite)
    monkeypatch.setattr(serial.Serial, "read", mockack)
    monkeypatch.setattr(serial.Serial, "readline", mockread)

    # When: the function is called
    retval = pc.ram_read(addr, length)

    # Then: the returned value should be a valid list
    assert expected_list == retval

def test_led_on_should_fail_on_invalid_color(MockConsole):
    # Given: A wrong color
    pc=MockConsole
    led="RED"

    # When: the function is called
    # Then: An assert error is thrown
    with pytest.raises(ValueError):
        pc.led_on(led)

def test_led_on_should_pass_for_valid_color(MockConsole, monkeypatch):
    # Given: A valid color
    pc=MockConsole
    led="GREEN"

    def mockwrite(self, value):
        assert "led green on\r" == value
    monkeypatch.setattr(serial.Serial, 'write', mockwrite)

    # When: the function is called
    # Then: the function works
    pc.led_on(led)

def test_led_off_should_fail_on_invalid_color(MockConsole):
    # Given: A wrong color
    pc=MockConsole
    led="AMBER"

    # When: the function is called
    # Then: An assert error is thrown
    with pytest.raises(ValueError):
        pc.led_off(led)

def test_led_off_should_pass_for_valid_color(MockConsole, monkeypatch):
    # Given: A valid color
    pc=MockConsole
    led="BLUE"

    def mockwrite(self, value):
        assert "led blue off\r" == value
    monkeypatch.setattr(serial.Serial, 'write', mockwrite)

    # When: the function is called
    # Then: the function works
    pc.led_off(led)

def test_led_blink_should_fail_on_invalid_color(MockConsole):
    # Given: A wrong color
    pc=MockConsole
    led="RED"

    # When: the function is called
    # Then: An assert error is thrown
    with pytest.raises(ValueError):
        pc.led_blink(led)

def test_led_blink_should_pass_for_valid_color(MockConsole, monkeypatch):
    # Given: A valid color
    pc=MockConsole
    led="GREEN"

    def mockwrite(self, value):
        assert "led green blink\r" == value
    monkeypatch.setattr(serial.Serial, 'write', mockwrite)

    # When: the function is called
    # Then: the function works
    pc.led_blink(led)

def test_restart_should_write_valid_command(MockConsole, monkeypatch):
    # Given: Mocked writes
    pc=MockConsole

    def mockset(self, key, value):
        assert "restart" == key
        assert None == value
    monkeypatch.setattr(PistonConsole, "set", mockset)

    # When: The function is called
    # Then: The function processes correctly
    pc.restart()

def test_factory_reset_should_write_valid_command(MockConsole, monkeypatch):
    # Given: mocked writes
    pc=MockConsole

    def mockset(self, key, value):
        assert "factory" == key
        assert None == value
    monkeypatch.setattr(PistonConsole, "admin_mode", "admin")
    monkeypatch.setattr(PistonConsole, "set", mockset)

    # When: the function is called
    # Then: the function processes correctly
    pc.factory_reset()