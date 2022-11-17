from enum import auto
from SystemCalls import *
import pytest
import warnings
import re
from serial import SerialException, VERSION
import LCPPistonConsole as lcpc
import time


NUM_GETTER_REPEATS = 10
RESTART_TIMEOUT_MAX = 10
MOVEMENT_TIMEOUT_MAX = 200

@pytest.fixture
def port(pytestconfig):
    return pytestconfig.getoption("port")

@pytest.fixture(autouse=True)
def system(port):
    return lcpc.PistonConsole(port)
    

def test_system_id_get():
    # Given
    expected_id = "LCP-PPC"

    # When:
    sysid = system.id()

    # Then: SystemID should match
    assert expected_id == sysid


def test_firmware_get_should_return_valid_firmware_version():
    # Given: A valid firmware regular expression (example: vX.Y.Z-AAAAAA)
    regex_str = r"v\d*\.\d*\.\d*-\w*$"
    
    # When: The function is called
    version = system.ver()

    # Then: The regex should match
    m = re.match(regex_str, version)
    assert re.Match == type(m)
    assert 0 == m.start() 


def test_firmware_version_should_be_most_recent():
    # Given: A valid firmware version to test against
    expected_str = "v1.2.3-8da3fb"

    # When: The function is called
    version = system.ver()

    # Then: The strings should match
    assert expected_str == version

def test_report_should_return_valid_report():
    # @TODO: Complete this function!
    # Given: An expected report format
    
    # When: The report function is called
    report = system.report()

    # Then: The report should be valid (report is saved!)



@pytest.mark.getter
def test_volume_setpoint_is_within_expected_range():
    # Given: A valid range of setpoints (total volumes)
    # When: The get vset function is called multiple times
    # Then: The setpoint is valid
    for i in range(NUM_GETTER_REPEATS):
        assert TOTAL_VOLUME_MIN <= system.volume_setpoint <= TOTAL_VOLUME_MAX

@pytest.mark.getter
def test_volume_total_read_should_return_valid_total_volume():
    # Given: A valid range of volumes
    # When: The volume_total getter is called multiple times
    # Then: Actual volume is within expected volume
    for i in range(NUM_GETTER_REPEATS):
        assert TOTAL_VOLUME_MIN <= system.volume_total <= TOTAL_VOLUME_MAX

@pytest.mark.getter
def test_volume_small_should_return_valid_small_volume():
    # Given: A valid range of volumes
    # When: The volume_small getter is called multiple times
    # Then: Actual volume is within expected volume
    for i in range(NUM_GETTER_REPEATS):
        assert SMALL_VOLUME_MIN <= system.volume_small <= SMALL_VOLUME_MAX

@pytest.mark.getter
def test_volume_large_should_return_valid_large_volumes():
    # Given: A valid range of volumes
    # When: The volume_large getter is called multiple times
    # Then: Actual volume is within expected volume
    for i in range(NUM_GETTER_REPEATS):
        assert LARGE_VOLUME_MIN <= system.volume_small <= LARGE_VOLUME_MAX

@pytest.mark.getter
def test_volume_housing_should_return_valid_volume():
    # Given: The housing volume
    # When: The volume_housing getter is called multiple times
    # Then: Actual volume is within expected volume
    for i in range(NUM_GETTER_REPEATS):
        assert HOUSING_VOLUME*0.999 <= system.volume_housing <= HOUSING_VOLUME * 1.001

@pytest.mark.getter
def test_total_volume_should_equal_sum_of_all_volumes():
    # Given: The total volume
    # When: volume_small + volume_large + volume_housing are summed
    # Then: The result should equal the total volume (within 0.001)
    total_volume = system.volume_small + system.volume_large + system.volume_housing
    assert 0.001 >= abs(system.volume_total - total_volume)

@pytest.mark.getter
def test_area_small_should_return_valid_area():
    # Given: The small piston area
    # When: The area_small getter is called multiple times
    # Then: Actual area is within expected area
    for i in range(NUM_GETTER_REPEATS):
        assert SMALL_PISTON_AREA *0.999 <= system.area_small <= SMALL_PISTON_AREA * 1.001

@pytest.mark.getter
def test_area_large_should_return_valid_area():
    # Given: The large piston area
    # When: The area_large getter is called multiple times
    # Then: Actual area is within expected area
    for i in range(NUM_GETTER_REPEATS):
        assert LARGE_PISTON_AREA *0.999 <= system.area_large <= LARGE_PISTON_AREA * 1.001

@pytest.mark.getter
def test_total_length_should_return_valid_total_length():
    # Given: A valid range of lengths
    # When: The length_total getter is called multiple times
    # Then: Actual length is within expected length
    for i in range(NUM_GETTER_REPEATS):
        assert TOTAL_LENGTH_MIN <= system.length_total <= TOTAL_LENGTH_MAX

@pytest.mark.getter
def test_small_length_should_return_valid_small_length():
    # Given: A valid range of lengths
    # When: The length_small getter is called multiple times
    # Then: Actual length is within expected length
    for i in range(NUM_GETTER_REPEATS):
        assert SMALL_LENGTH_MIN <= system.length_total <= SMALL_LENGTH_MAX

@pytest.mark.getter
def test_large_length_should_return_valid_large_length():
    # Given: A valid range of lengths
    # When: The length_large getter is called multiple times
    # Then: Actual length is within expected length
    for i in range(NUM_GETTER_REPEATS):
        assert LARGE_LENGTH_MIN <= system.length_total <= LARGE_LENGTH_MAX

@pytest.mark.getter
def test_combination_of_lengths_should_be_equal_to_total():
    # Given: A total length
    # When: The length_large + length_small are added
    # Then: The sum is equal to length_total
    total_length = system.length_small + system.length_large
    assert 0.001 >= abs(system.length_total - total_length)

@pytest.mark.getter
def test_piston_minimum_should_return_value():
    # Given: The min/max of the full piston
    # When: pmin is called
    # Then: A valid response should be returned
    assert TOTAL_LENGTH_MIN <= system.piston_minimum <= TOTAL_LENGTH_MAX

@pytest.mark.getter
def test_piston_maximum_should_return_value():
    # Given: The min/max of the full piston
    # When: pmax is called
    # Then: A valid response should be returned
    assert TOTAL_LENGTH_MIN <= system.piston_maximum <= TOTAL_LENGTH_MAX

@pytest.mark.getter
def test_travel_engaged_is_not_set():
    # Given: An expectation that the system isn't moving
    # When: teng is called
    # Then: The response should be false
    assert False == system.travel_engaged

@pytest.mark.getter
def test_piston_rate_should_return_zero_when_not_moving():
    # Given: A non-moving system
    # When: prate is called
    # Then: Expect a rate of 0.0
    assert False == system.travel_engaged
    assert 0.0 == system.piston_rate

@pytest.mark.getter
def test_travel_direction_should_return_valid_response():
    # Given: An expectation of -1 or 1
    # When: tdir is called
    direction = system.piston_direction
    # Then: A valid response is returned
    
    assert direction[0] in [-1, 1]
    assert direction[1] in ["Extend", "Retract"]

@pytest.mark.getter
def test_travel_zero_should_return_valid_response():
    # Given: 
    # When: tzero is called
    # Then: A boolean should be returned
    assert bool == type(system.travel_zero)

@pytest.mark.getter
def test_travel_full_should_return_valid_response():
    # Given: 
    # When: tfull is called
    # Then: A boolean should be returned
    assert bool == type(system.travel_full)

@pytest.mark.getter
def test_pid_p_value_should_return_valid():
    # Given:
    # When: pidp is called
    # Then: Expect a float
    assert float == type(system.pid_p)

@pytest.mark.getter
def test_pid_i_value_should_return_valid():
    # Given:
    # When: pidi is called
    # Then: Expect a float
    assert float == type(system.pid_i)

@pytest.mark.getter
def test_pid_d_value_should_return_valid():
    # Given:
    # When: pidd is called
    # Then: Expect a float
    assert float == type(system.pid_d)

@pytest.mark.getter
def test_user_should_return_valid_username():
    # Given:
    # When: user is called
    # Then: Expect a string
    assert str == type(system.user)

@pytest.mark.getter
def test_logging_level_should_return_valid_level():
    # Given:
    # When: logging_level is called
    level = system.logging_level
    # Then: value is within range
    assert int == type(level)
    assert level in [0, 1, 2, 3]

@pytest.mark.admin
@pytest.mark.setter
def test_factory_reset_should_reset_to_expected_values():
    # Given
    
    # When: factory reset is called
    system.factory_reset()

    # Then: Values should reset
    assert TOTAL_LENGTH_MIN == system.piston_minimum
    assert TOTAL_LENGTH_MAX == system.piston_maximum

@pytest.mark.setter
@pytest.mark.parametrize("min", [0.0, 1.0, 2.0])
def test_piston_minimum_should_set_correctly_for_valid_values( min):
    # Given: Minimum values that are valid
    # When: The pmin set is used with values
    system.piston_minimum(min)

    # Then: pmin get should return same values
    assert min == system.piston_minimum

@pytest.mark.setter
@pytest.mark.parametrize("max", [11.0, 10.0, 9.0])
def test_piston_maximum_should_set_correctly_for_valid_values( max):
    # Given: maximum values that are valid
    # When: The pmax set is used with values
    system.piston_maximum = max

    # Then: pmax get should return same values
    assert max == system.piston_maximum
    
@pytest.mark.setter
@pytest.mark.parametrize("min", [7.0, 8.0, 9.0])
def test_piston_minimum_should_not_set_for_invalid_values( min):
    # Given: Values above pmax
    previous_min = system.piston_minimum

    # When: pmax is set to 6.99 and pmin is called with bad values
    system.piston_maximum = 6.99
    system.piston_minimum = min

    # Then: pmin should be previous value
    assert previous_min == system.piston_minimum

@pytest.mark.setter
@pytest.mark.parametrize("max", [5.99, 4.0, -1.0])
def test_piston_minimum_should_not_set_for_invalid_values( max):
    # Given: Values below pmin
    previous_max = system.piston_maximum

    # When: pmax is set to 6.99 and pmin is called with bad values
    system.piston_minimum = 6.00
    system.piston_maximum = max

    # Then: pmin should be previous value
    assert previous_max == system.piston_maximum


@pytest.mark.setter
@pytest.mark.parametrize("pidp", [0.0, -4.398, 127.8231])
def test_pid_p_should_set_correctly( pidp):
    # Given: pid_p values
    # When: pid_p is called with new value
    system.pid_p = pidp

    # Then: pid_p should be set correctly
    assert pidp == system.pid_p


@pytest.mark.setter
@pytest.mark.parametrize("pidi", [820.0, 0.3232, -7.7777])
def test_pid_p_should_set_correctly( pidi):
    # Given: pid_i values
    # When: pid_i is called with new value
    system.pid_i = pidi

    # Then: pid_i should be set correctly
    assert pidi == system.pid_i


@pytest.mark.setter
@pytest.mark.parametrize("pidd", [0.0, -0.00328, 4231.13])
def test_pid_p_should_set_correctly( pidd):
    # Given: pid_d values
    # When: pid_d is called with new value
    system.pid_d = pidd

    # Then: pid_d should be set correctly
    assert pidd == system.pid_d
    
@pytest.mark.setter
@pytest.mark.parametrize("level", [3, 2, 1, 0])
def test_logging_level_sets_correctly( level):
    # Given: logging levels
    # When: logging_level is called with new value
    system.logging_level= level

    # Then: Expected level should be set
    assert level == system.logging_level

@pytest.mark.setter
@pytest.mark.restart
@pytest.mark.timeout(RESTART_TIMEOUT_MAX)
def test_system_restart_should_restart_system():
    # Given:
    # When: A restart is commanded
    system.restart()

    # Then:
    assert "System Restart\r" in system.readline()
    buf = system.readline()
    while "System Start\r" not in buf:
        buf = system.readline()
    while ">" not in buf:
        buf = system.readline()
    assert True

@pytest.mark.setter
@pytest.mark.movement
@pytest.mark.timeout(MOVEMENT_TIMEOUT_MAX)
@pytest.mark.parametrize("volume", [TOTAL_VOLUME_MIN, TOTAL_VOLUME_MAX, (TOTAL_VOLUME_MAX - TOTAL_VOLUME_MIN)/2])
def test_volume_set_should_move_system_to_setpoint( volume):
    # Given: Volumes to set
    # When: Function is called and movement completes
    system.volume_setpoint(volume)

    while True == system.travel_engaged:
        time.sleep(1)

    # Then: Actual volume should be within XXX in^3
    assert VOLUME_TOLERANCE >= abs(volume - system.volume_total) 


def set_admin_mode(system):
    if "admin" != system.user_name:
        system.user_name= "admin"
        assert "admin" == system.user_name

@pytest.mark.admin
@pytest.mark.getter
def test_user_direction_get_returns_valid_response():
    # Given: System in admin mode
    set_admin_mode(system)

    # When: udir is called
    udir = system.user_direction

    # Then: udir should be -1, or 1
    assert int == type(udir[0])
    assert str == type(udir[1])
    assert udir[0] in [-1, 1]
    assert udir[1] in ["Retract", "Extend"]

@pytest.mark.admin
@pytest.mark.getter
def test_user_engage_is_not_set_before_being_set():
    # Given: System in admin mode
    set_admin_mode(system)

    # When: ueng is called
    ueng = system.user_engage
    # Then: ueng should be False
    assert bool == type(ueng)
    assert False == ueng 

@pytest.mark.admin
@pytest.mark.getter
def test_user_rate_should_be_a_valid_value():
    # Given: admin mode, Valid range of rate value
    set_admin_mode(system)

    # When: urate is read
    rate = system.user_rate
    
    # Then: rate should be valid
    assert float == type(rate)
    assert USER_PISTON_RATE_MIN <= rate <= USER_PISTON_RATE_MAX

@pytest.mark.admin
@pytest.mark.getter
def test_user_total_length_should_be_valid_number():
    # Given: admin mode, Range of valid lengths
    set_admin_mode(system)
    # When: ulset is read
    length = system.user_length_set
    
    # Then: length should be valid
    assert float == type(length)
    assert TOTAL_LENGTH_MIN <= length <= TOTAL_LENGTH_MAX

@pytest.mark.admin
@pytest.mark.getter
def test_serial_should_return_valid_serial():
    # Given: admin mode
    set_admin_mode(system)

    # When: serial is called
    sernum = system.serial_number

    # Then: serial should be a str
    assert str == type(sernum)

@pytest.mark.admin
@pytest.mark.setter
def test_serial_number_set_should_set_field():
    # Given: admin mode, a serial number
    set_admin_mode(system)
    sn = "LCP12345"

    # When: serial_number is called
    system.serial_number= sn

    assert sn == system.serial_number

@pytest.mark.admin
@pytest.mark.setter
def test_serial_number_set_should_keep_old_for_invalid():
    # Given: admin mode, serial number that is too long
    set_admin_mode(system)
    sn = "LCP10234523qp09asdal;kjdfa09124"
    prev_sn = system.serial_number

    # When: serial_number is set with invalid value
    system.serial_number = sn

    # Then: previous serial number will be kept
    assert prev_sn == system.serial_number

@pytest.mark.admin
@pytest.mark.setter
@pytest.mark.parametrize("length", [TOTAL_LENGTH_MIN, TOTAL_LENGTH_MAX/2, TOTAL_LENGTH_MAX])
def test_user_length_setpoint_should_accept_valid( length):
    # Given: admin mode, valid lengths
    set_admin_mode(system)

    # When: ulset is called
    system.user_length_max_setpoint = length

    # Then: ulset should be set
    assert length == system.user_length_max_setpoint


@pytest.mark.admin
@pytest.mark.setter
@pytest.mark.parametrize("length", [-TOTAL_LENGTH_MIN, TOTAL_LENGTH_MAX+0.001])
def test_user_length_setpoint_should_not_accept_invalid( length):
    # Given: admin mode, invalid lengths, previous setpoint
    set_admin_mode(system)
    prev_len = system.user_length_max_setpoint

    # When: ulset is called
    system.user_length_max_setpoint = length

    # Then: ulset should be set
    assert prev_len == system.user_length_max_setpoint

@pytest.mark.admin
@pytest.mark.setter
@pytest.mark.parametrize("rate", [USER_PISTON_RATE_MIN, (USER_PISTON_RATE_MAX + USER_PISTON_RATE_MIN)/2, USER_PISTON_RATE_MAX])
def test_user_rate_should_accept_valid_setpoint( rate):
    # Given: admin mode, valid lengths
    set_admin_mode(system)

    # When: urate is called
    system.user_rate = rate

    # Then: urate should be new value
    assert rate == system.user_rate


@pytest.mark.admin
@pytest.mark.setter
@pytest.mark.parametrize("rate", [-0.001, 0.0, USER_PISTON_RATE_MAX+0.001])
def test_user_rate_setpoint_should_not_accept_invalid( rate):
    # Given: admin mode, invalid rates, previous setpoint
    set_admin_mode(system)
    prev_rate = system.user_rate

    # When: urate is called
    system.user_rate = rate

    # Then: urate should be previous value
    assert prev_len == system.user_length_max_setpoint


@pytest.mark.admin
@pytest.mark.setter
@pytest.mark.parametrize("dir", [-1, 1])
def test_user_direction_should_accept_valid( dir):
    # Given: admin mode, valid dirs
    set_admin_mode(system)

    # When: udir is called
    system.user_direction = dir

    # Then: Direction should be set
    assert dir == system.user_direction

@pytest.mark.admin
@pytest.mark.setter
@pytest.mark.parametrize("dir", [-999,-2, -1.1, 0.1, 0.0, 1.001, 999])
def test_user_direction_should_not_accept_invalid( dir):
    # Given: admin mode, invalid dirs, previous dir
    set_admin_mode(system)
    prev_dir = system.user_direction

    # When: udir is called
    system.user_direction = dir

    # Then: previous direction should be kept
    assert prev_dir == system.user_direction

@pytest.mark.admin
@pytest.mark.setter
@pytest.mark.movement
@pytest.mark.timeout(MOVEMENT_TIMEOUT_MAX)
def test_user_eng_should_also_set_teng():
    # Given: admin mode, valid direction for travel
    set_admin_mode(system)

    if (system.total_length < 1.0):
        system.udir = 1
    elif (system.total_length > (system.user_total_max_length - 1.0)):
        system.udir = -1

    # When: ueng is called
    system.user_engaged = True

    # Then: ueng and teng should be true
    assert True == system.user_engaged
    assert True == system.travel_engaged
    
    # And then: Shut the system off and test its off
    system.user_engaged = False
    assert False == system.user_engaged
    assert False == system.travel_engaged




@pytest.mark.ram
@pytest.mark.getter
@pytest.mark.parametrize("addr", [0x0000, 0x0100, 0x0200])
def test_ram_read_should_read_requested_rull_ram_locations( addr):
    # Given: address and length
    length = 256

    # When: ram_read is called
    ram = system.ram_read(addr, length)

    # Then: length of list should be 256
    assert length == len(ram)

@pytest.mark.ram
@pytest.mark.getter
@pytest.mark.parametrize("addr,length", [
    (0x0010, 1),
    (0x020A, 10),
    (0x011C, 15)
])
def test_ram_read_should_read_smaller_lengths_too( addr, length):
    # Given: address and length
    # When: ram_read is called
    ram = system.ram_read(addr, length)

    # Then: length of list should be what is expected
    assert length == len(ram)


# @TODO Add Write tests - This requires better understanding of pytest load files
# @TODO Add Write tests - Need final version of memory map
# @pytest.mark.ram
# @pytest.mark.setter
# @pytest.mark.parametrize("values",
# def test_ram_write_should_write_to_ram_correctly( values):
    # pass