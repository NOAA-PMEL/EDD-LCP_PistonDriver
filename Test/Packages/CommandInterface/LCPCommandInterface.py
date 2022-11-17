
import i2cdriver
from functools import wraps
from LCPMemoryMap import create_msg, create_read_dict, convert_memory_values

USER_WRITE_KEY = 0xA5

MAX_VOLUME_1124 = 1124
MIN_VOLUME_1124 = 0
MAX_VOLUME_674 = 674
MIN_VOLUME_674 = 0

MIN_PISTON_LENGTH = 0
MAX_PISTON_LENGTH = 11.77

class LCPCommand:
    def __init__(self, port:str, device=LCP_I2C_ADDR, lcptype=674) -> None:
        self._i2c = i2cdriver.I2CDriver(port=port, speed=100, pullups=0)
        self._dev = device
        if not (lcptype == 674 or lcptype == 1124):
            raise ValueError('lcptype must be 674 or 1124')
        self._type = lcptype

    def read(self, address:int, length:int):
        """ I2C Comm Read Address

        I2C Communications to read the provided address for
        number of bytes specified.

        Args:
            address (int): Starting Address to read
            length (int): Number of bytes to read

        Returns:
            [bytes]: Data at address, length bytes long
        """
        assert address <= 0x02FF
        assert length <= (0x02FF - address)

        if not self._i2c.start(self._dev, 0):
            self._i2c.stop()
            return None
        self._i2c.write(address)
        self._i2c.stop()
        self._i2c.start(self._dev, 1)
        data = self._i2c.read(length)
        self._i2c.stop()

        return data

    def write(self, address:int, data:bytes):
        """ I2C Comm Write Address
        
        I2C Communications to write provided address (and beyond)
        with data provided.  Length auto-calculated.
        Args:
            address (int): Start of write address
            data (bytes): Data to write
        """
        assert address < MAX_ADDR_LOC
        assert len(data) <= (MAX_ADDR_LOC - address)

        self._i2c.reset()
        self._i2c.start(self._dev, 0)
        self._i2c.write(address)
        self._i2c.start(self._dev, 0)
        self._i2c.write(data)
        self._i2c.stop()

    def _set_state(state):
        """ Decorator to put LCP Power Board in State to accept write commands"""
        @wraps(state)
        def _decorator(self):
            msg = create_msg('VAR_WRITE', USER_WRITE_KEY)
            self.write(**msg)
            state(self)
            msg = create_msg('VAR_WRITE', 0x00)
            self.write(**msg)

    def _user_override(self, state=False):
        """ LCP Power User Override

        The LCP Piston Control board requires the user enter override mode in
        order to manually control the piston direction and power on/off.

        Args:
            state (bool, optional): Override Enabled (True) or Disabled (False). Defaults to False.
        """
        assert bool == type(state)
        msg = create_msg('USER_OVERRIDE', state)
        self.write(**msg)

    @_set_state
    def set_volume(self, volume:float):
        """ Set the volume setpoint

        Sets the system volume to user selection. Is
        coupled with LEN_SETPOINT_IN (will be autocalculated
        after VOL_SETPOINT_IN3 is set).

        Args:
            volume (float): Volume setpoint (in^3)
        """
        assert float == type(volume)
        if self._type == 674:
            assert 0 <= volume <= MAX_VOLUME_674
        else:
            assert 0 <= volume <= MAX_VOLUME_1124

        msg = create_msg('VOL_SETPOINT_IN3', volume)
        
        self.write(**msg)

    @_set_state
    def set_length(self, length:float):
        """ Set the piston length

        Alternatively to using volume, the system can be set
        to move the piston to a specified position.  Coupled
        with VOL_SETPOINT_IN3 (will be autocalculated after
        LEN_SETPOINT_IN is set).

        Args:
            length (float): User define piston length setpoint (in)
        """
        assert float == type(length)
        assert MIN_PISTON_LENGTH <= length <= MAX_PISTON_LENGTH

        msg = create_msg('LEN_PISTON_IN', length)
        self.write(**msg)

    @_set_state
    def set_piston_min(self, length):
        """ Set Piston Minimum position

        Sets the Piston Minimum position for situations where
        piston cannot be fully retracted.

        Args:
            length ([type]): Piston Minimum position (in)
        """
        assert float == type(length)
        assert MIN_PISTON_LENGTH <= length <= MAX_PISTON_LENGTH

        msg = create_msg('PISTON_POSITION_MIN', length)
        self.write(**msg)

    @_set_state
    def set_piston_max(self, length):
        """ Set Piston Maximum position

        Sets the Piston Maximum position for situations where
        piston cannot be fully extended.

        Args:
            length ([type]): Piston Minimum position (in)
        """
        assert float == type(length)
        assert MIN_PISTON_LENGTH <= length <= MAX_PISTON_LENGTH

        msg = create_msg('PISTON_POSITION_MAX', length)
        self.write(**msg)
        
    
    @_set_state
    def set_pid_coeff(self, p:float=None, i:float=None, d:float=None, used:bool=None):
        """ Set PID coefficients and state

        Args:
            p (float, optional): Proporitional Coefficient. Defaults to None.
            i (float, optional): Integral Coefficient. Defaults to None.
            d (float, optional): Derivatvie Coefficient. Defaults to None.
            used (bool, optional): Flag to indicate if PID control is used. Defaults to None.
        """
        assert (float == type(p)) or (p == None)
        assert (float == type(i)) or (i == None)
        assert (float == type(d)) or (d == None)
        assert (bool == type(used)) or (used == None)

        if p:
            msg = create_msg('PID_COEFF_P', p)
            self.write(**msg)
        if i:
            msg = create_msg('PID_COEFF_I', i)
            self.write(**msg)
        if d:
            msg = create_msg('PID_COEFF_D',d)
            self.write(**msg)
        
        if used:
            msg = create_msg('PID_USED', used)


    @_set_state
    def run_piston(self, dir:int):
        """ Run piston in specified direction

        Args:
            dir (int): Retract (-1) or Extend (1)
        """
        assert dir == -1 or dir == 1
        
        # Go into user override mode (direct control of piston)
        self._user_override(True)

        # Set the direction, then engage
        msg = create_msg('TRV_DIR', dir)
        self.write(**msg)
        msg = create_msg('TRV_ENG', True)
        self.write(**msg)

    @_set_state
    def stop_piston(self):
        """ Stop Piston Movement """
        # User override mode (control of piston)
        self._user_override(True)

        # Stop the piston
        msg =create_msg('TRV_ENG', False)
        self.write(**msg)

        # Clear override mode
        self._user_override(False)

    @_set_state
    def set_serial_number(self, ser_num:str):
        """ Set system serial number

        Args:
            ser_num (str): Serial Number (8 chars max)
        """
        assert str == type(ser_num)

        msg = create_msg('SER_NUM', ser_num)
        self.write(**msg)

    
        

    def get_battery_data(self) -> dict:
        """ Get a dict of battery datea

        Returns:
            dict: Battery data
        """
        msg = self._read()
        battery_tags = (
            'BAT_RETCAP',
            'BAT_REPSOC',
            'BAT_VCELL',
            'BAT_CURRENT',
            'BAT_TTE',
            'BAT_STATUS'
        )
        return {k: msg[k] for k in battery_tags}


    @property
    def pid(self) -> dict:
        """Get PID Coefficents and status

        Returns:
            dict: PID Coefficents and status
        """
        mem = self._read()
        pid = {
            'p':mem['PID_COEFF_P'],
            'i':mem['PID_COEFF_I'],
            'd':mem['PID_COEFF_D'],
            'used':mem['PID_USED']
        }
        return pid

    @property
    def rate(self) -> float:
        """ Get piston rate (in/sec)

        Returns:
            float: Piston rate (in/sec)
        """
        return self._read('PST_RATE')
    
    @property
    def position(self) -> float:
        """ Get current piston position

        Returns:
            float: Piston position (in)
        """
        return self._read('PST_POSITION_IN')

    @property
    def piston(self) -> dict:
        """ Get Piston information

        Returns:
            dict: Piston position, rate, min, max and encoder count
        """
        mem = self._read()
        piston = {
            'position':mem['PST_POSITION_IN'],
            'rate':mem['PST_RATE'],
            'min':mem['PST_POSITION_MIN'],
            'max':mem['PST_POSITION_MAX'],
            'encoder_cnt':mem['PST_ENC_COUNTS']
        }

    @property
    def volume(self)->dict:
        """ Get volume information

        Returns:
            dict: System volume setpoint, current volume, small piston volume, large piston volume, housing volume
        """
        mem = self._read()
        volume = {
            'setpoint':mem['VOL_SETPOINT_IN3'],
            'current':mem['VOL_TOTAL_IN3'],
            'small':mem['VOL_SMALL_PISTON_IN3'],
            'large':mem['VOL_LARGE_PISTON_IN3'],
            'housing':mem['HOUSING_IN3']
        }
        return 
    
    @property
    def length(self)->dict:
        """ Get length information

        Returns:
            dict: Piston setpoint, total length, small piston length, large piston length
        """
        mem = self._read()
        volume = {
            'setpoint':mem['LEN_SETPOINT_IN'],
            'current':mem['LEN_PISTON_IN'],
            'small':mem['LEN_SMALL_PISTON_IN'],
            'large':mem['LEN_LARGE_PISTON_IN']
        }
        
    @property
    def serial_number(self)->str:
        """ Get serial number

        Returns:
            str: Serial Number (8 char max)
        """
        return self._read('SER_NUM')
    
    @property 
    def year_built(self) ->int:
        """ Get System Build date

        Returns:
            int: year built
        """
        return self._read('YEAR_BUILT')

    @property
    def volume_setpoint(self)->float:
        """ Get volume setpoint

        Returns:
            float: Volume setpoint (in3)
        """
        return self._read('VOL_SETPOINT_IN3')

    @property
    def volume_total(self)->float:
        """ Get current total volume

        Returns:
            float: total volume (in3)
        """
        return self._read('VOL_TOTAL_IN3')

    @property
    def firmware_version(self)->str:
        """ Get firmware version

        Returns:
            str: firmware version
        """
        mem = self._read()
        firmware = f"v{mem['FIRM_MAJ']}.{mem['FIRM_MIN']}.{mem['FIRM_BUILD']}"
        return firmware

    @property
    def full(self) -> bool:
        """ Full Position Flag
        The current flag status for indicating fully extended.

        Returns:
            bool: Not Fully Extended (False), Fully Extended (True)
        """
        return self._read('TRV_FULL')

    @property
    def zero(self) -> bool:
        """ Zero Position Flag
        The current flag status for indicating fully retracted.

        Returns:
            bool: Not Fully Retracted (False), Fully Retracted (True)
        """
        return self._read('TRV_ZERO')

    @property
    def min(self) -> bool:
        """ Min Position Flag
        The current flag status for indicating positioned at MINIMUM.

        Returns:
            bool: Not at MIN position (False), At MIN position (True)
        """
        return self._read('TRV_MIN')
    
    @property
    def max(self) -> bool:
        """ Max Position Flag
        The current flag status for indicating positioned at MAXIMUM.

        Returns:
            bool: Not at MAX position (False), At MAX position (True)
        """
        return self._read('TRV_MAX')

    @property
    def system(self) -> dict:
        """ Return system information 

        Returns:
            dict: System id, serial number, firmware version, year built
        """
        mem = self._read()
        system = {
            'id': mem['SYS_ID'],
            'serial_number': mem['SER_NUM'],
            'firmware': f"v{mem['FIRM_MAJ']}.{mem['FIRM_MIN']}.{mem['FIRM_BUILD']}",
            'year_built': mem['YEAR_BUILT']
        }
        return system

    def _read(self, tag:str=None)->:
        """ Read memory by tag
        Reads the memory at the tag location, if provided.  Otherwise
        defaults to reading all memory location 

        Args:
            tag (str, optional): Memory tag. Defaults to None.

        Returns:
            dict: Memory requested
        """
        if tag:
            assert tag in memory.keys()
            msg = create_read_dict(tag)
            readval = self.read(**msg)
            mem = convert_memory_values(msg['address'], readval)
            return mem[tag]
        else:
            msg = {'address':0x00, 'length'=0xff}
            readval = self.read(**msg)
            return convert_memory_values(0x00, readval)

    

    
    