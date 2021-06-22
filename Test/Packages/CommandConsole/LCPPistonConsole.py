from typing import Type
import serial
from serial.serialutil import SerialException
from textwrap import wrap


KEY_LIST = [
    "vset",
    "vtotal",
    "vsmall",
    "vlarge",
    "vhouse",
    "asmall",
    "alarge",
    "ltotal",
    "lsmall",
    "llarge",
    "pmin",
    "pmax",
    "prate",
    "tdir",
    "teng",
    "tzero",
    "tfull",
    "pidp",
    "pidi",
    "pidd",
    "user",
    "level",
    "restart"
]

USER_KEY_LIST = ["utest", "udir", "ueng", "urate", "ulset", "factory"]


class PistonConsole:
    def __init__(self, port: int) -> None:
        self._ser = serial.Serial()
        try:
            self._ser.port=port
            self._ser.baudrate=115200
            self._ser.open()
        except SerialException as e:
            print("Failure to open serial port:")
            print(e)

        self._admin = False

    def readline(self):
        """ Read line from console

        Returns:
            [type]: [description]
        """
        return self._ser.readline().decode('utf8')

    def set(self, key: str, value=None):
        """ Set value to system key

        Args:
            key (str): Key to set (see KEY_LIST and USER_KEY_LIST)
            value ([bool, int, float, str]): Value to set

        Raises:
            ValueError: Key not in list of keys
            TypeError: Invalid value type
        """
        if not ( (key in USER_KEY_LIST) or (key in KEY_LIST)):
            raise ValueError(f"{key} not in list of keys")

        sendstr = f"set {key} "
        print(sendstr)
        # Convert value
        if type(value) == float:
            sendstr += f"{value}"
        elif type(value) == int:
            sendstr += f"{value}"
        elif type(value) == str:
            sendstr += value
        else:
            raise TypeError(f"Invalid Types {type(value)}")

        sendstr += "\r"
        self._ser.write(sendstr.encode())

    def get(self, key: str) -> str:
        """ Read value from system

        Args:
            key (str): Key to get (see KEY_LIST and USER_KEY_LIST)

        Raises:
            ValueError: Key not in list of keys

        Returns:
            str: Returned key value
        """
        if not ( (key in USER_KEY_LIST) or (key in KEY_LIST)):
            raise ValueError(f"{key} not in list of keys")

        sendstr = f"get {key}\r"
        self._ser.write(sendstr)

        return self._ser.readline()

    def ram_write(self, addr: int, value: list[int]) -> None:
        """[summary]

        Args:
            addr (int): RAM address to write to
            value (list[int]): Value to write to address

        Returns:
            bool: Pass=True, Fail=False
        """
        assert self._valid_addr(addr)
        value_str = [format(x, "02x") for x in value]
        length = len(value_str)
        sendstr = f"set -r 0x{addr:02x} {length} {value_str}\r"
        self._ser.write(sendstr)

        
        # Read ACK and continue or fail
        val = ord(self._ser.read().decode('utf8'))
        if not self._is_ack(val):
            raise SystemError(f'Request to read addr={addr} failed')
        return True

    def ram_read(self, addr: int, length: int) -> list[int]:
        """[summary]

        Args:
            addr (int): RAM address to read
            length (int): Number of bytes to read

        Raises:
            ValueError: Number of bytes requsted outside of 0 - 255 range
            ValueError: Returned length not same as requested

        Returns:
            list[int]: Returned values from registers requested
        """
        # Validate addr and create sendstr
        assert self._valid_addr(addr)
        if length > 0xFF:
            raise ValueError("Length={len} > 255, Invalid Length")
        sendstr = f"get -r 0x{addr:02x} {length}\r"

        self._ser.write(sendstr)

        # Read ACK and continue or fail
        val = ord(self._ser.read().decode('utf8'))
        print(type(val))
        if not self._is_ack(val):
            raise SystemError(f'Request to read addr={addr} failed')

        # Read return values and convert to list of ints
        values = self._ser.readline().decode("utf-8")
        values = wrap(values, 2)
        values = [int(x, 16) for x in values]

        if len(values) != length:
            raise ValueError(
                f"Return value length ({len(values)}) != length expected ({length})"
            )

        return values

    def led_on(self, led: str):
        """ Turn LED ON

        Args:
            led (str): [GREEN or BLUE LED selection]
        """
        assert self._valid_led(led)
        sendstr = f"led {led.lower()} on\r"
        self._ser.write(sendstr)

    def led_off(self, led: str):
        """ Turn LED OFF

        Args:
            led (str): GREEN or BLUE LED selection
        """
        assert self._valid_led(led)
        sendstr = f"led {led.lower()} off\r"
        self._ser.write(sendstr)

    def led_blink(self, led: str):
        """ Blink LED

        Args:
            led (str): GREEN or BLUE LED selection
        """
        assert self._valid_led(led)
        sendstr = f"led {led.lower()} blink\r"

    def set_admin_mode(self, state: bool, username: str = "guest") -> bool:
        """ Select Admin mode for controller

        Args:
            state (bool): True=Set Admin Mode, False=Cancel Admin Mode
            username (str, optional): User requested username. Defaults to "guest".

        Raises:
            ValueError: Admin Mode was unable to be set
            ValueError: Admin Mode was unable to be cleared

        Returns:
            bool: [description]
        """
        if state:
            if self.user != "admin":
                self.set("user", "admin")

            if self.user != "admin":
                raise ValueError(f"Issue setting admin mode.  User name is {self.user}")
        else:
            if self.user != username:
                self.set("user", username)

            if self.user != username:
                raise ValueError(f"Issue exiting admin mode. User name is {self.user}")
        return True

    def restart(self):
        """Restart the system
        """
        self.set("restart", None)

    def factory_reset(self):
        """ Reset all variable to factory settings

        Raises:
            AttributeError: Admin mode required
        """
        if not self.admin_mode:
            raise AttributeError(f"Must be in admin mode.  UN={self.user}")
        self.set("factory", None)

    @property
    def user(self):
        return self.get("user")

    @property
    def serial_number(self):
        """ System Serial Number

        Returns:
            str: System Serial Number
        """
        self._ser.write("ser\r")
        return self._ser.readline()

    @serial_number.setter
    def serial_number(self, value: str):
        if not self.admin_mode:
            raise AttributeError(f"Must be in admin mode.  UN={self.user}")

        if len(value) > 16:
            raise ValueError(f"Serial Number must not exceed 16 characters")

        sendstr = f"set serial {value}\r"
        self._ser.write(sendstr.encode())
        # Check for ACK

    @property
    def user_test(self):
        return self.get("utest")

    @user_test.setter
    def user_test(self, value: int):
        if not self.admin_mode:
            raise AttributeError(f"Must be in admin mode.  UN={self.user}")

        if type(value) != int:
            raise TypeError(
                f"utest value requires an int.  {type(value)} was provided."
            )

        if 0 <= value <= 10:
            self.set("utest", value)
        else:
            raise ValueError(
                f"utest value must be within range 0 - 10.  {value} was given."
            )

        utest = self.user_test
        if value != utest:
            raise ValueError(f"Failure to set utest.  Expected {value}, was {utest}.")

    @property
    def user_direction(self):
        udir = self.get("udir")

        if udir == 1:
            return [1, "Extension"]
        elif udir == -1:
            return [-1, "Retraction"]
        else:
            raise ValueError(f"Invalid udir value received, {udir}.")

    @user_direction.setter
    def user_direction(self, value: int):
        if not self.admin_mode:
            raise AttributeError(f"Must be in admin mode.  UN={self.user}")

        if type(value) != int:
            raise TypeError(
                f"utest value requires an int.  {type(value)} was provided."
            )

        if value in [-1, 1]:
            self.set("udir", value)
        else:
            raise ValueError(f"udir value must be -1 or 1.  {value} was given.")

        udir = self.user_direction
        if value != udir:
            raise ValueError(f"Failure to set udir.  Expected {value}, was {udir}")

    @property
    def user_engage(self):
        return self.get("ueng")

    @user_engage.setter
    def user_engage(self, value: bool):
        if not self.admin_mode:
            raise AttributeError(f"Must be in admin mode.  UN={self.user}")

        if type(value) != bool:
            raise TypeError(f"ueng value requires a bool.  {type(value)} was provided.")

        self.set("ueng", value)

        ueng = self.user_engage
        if value != ueng:
            raise ValueError(f"Failure to set ueng.  Expected {value}, was {ueng}")

    @property
    def user_rate(self):
        return self.get("urate")

    @user_rate.setter
    def user_rate(self, value):
        if not self.admin_mode:
            raise AttributeError(f"Must be in admin mode.  UN={self.user}")

        if type(value) != float:
            raise TypeError(
                f"urate value requires a float.  {type(value)} was provided."
            )

        self.set("urate", value)

        urate = self.user_rate
        if value != urate:
            raise ValueError(f"Failure to set urate.  Expected {value}, was {urate}")

    @property
    def user_length_max_setpoint(self):
        return self.get("ulset")

    @user_length_max_setpoint.setter
    def user_length_max_setpoint(self, value):
        if not self.admin_mode:
            raise AttributeError(f"Must be in admin mode.  UN={self.user}")

        if type(value) != float:
            raise TypeError(
                f"ulset value requires a float.  {type(value)} was provided."
            )

        self.set("ulset", value)

        ulset = self.user_length_max_setpoint
        if value != ulset:
            raise ValueError(f"Failure to set ulset.  Expected {value}, was {ulset}")

    @property
    def id(self):
        self._ser.write("id\r")
        return self._ser.readline()

    @property
    def ver(self):
        self._ser.write("ver\r")
        return self._ser.readline()

    @property
    def report(self):
        self._ser.write("report\r")
        return self._ser.readline()

    @property
    def admin_mode(self):
        if self.user == "admin":
            return True
        else:
            return False

    @property
    def volume_setpoint(self):
        return self.get("vset")

    @volume_setpoint.setter
    def volume_setponit(self, volume: float):
        if type(volume) != float:
            raise TypeError(
                f"Volume is a float value.  {type(volume)} passed to function"
            )

        self.set("vset", volume)

        vreturn = self.get("vset")
        if vreturn != volume:
            raise ValueError(
                f"Volume Setpoint not set correctly.  Expected {volume}, was {vreturn}"
            )

    @property
    def volume_total(self):
        return self.get("vtotal")

    @property
    def volume_small(self):
        return self.get("vsmall")

    @property
    def volume_large(self):
        return self.get("vlarge")

    @property
    def volume_housing(self):
        return self.get("vhouse")

    @property
    def area_small(self):
        return self.get("asmall")

    @property
    def area_large(self):
        return self.get("alarge")

    @property
    def length_total(self):
        return self.get("ltotal")

    @property
    def length_small_piston(self):
        return self.get("lsmall")

    @property
    def length_large_piston(self):
        return self.get("llarge")

    @property
    def piston_minimum(self):
        return self.get("pmin")

    @piston_minimum.setter
    def piston_minimum(self, minval):
        if type(minval) != float:
            raise TypeError(
                f"Piston minimum requires a float value.  {type(minval)} was used."
            )
        self.set("pmin", minval)

        pminret = self.get("pmin")
        if pminret != minval:
            raise ValueError("PMin not set correctly")

    @property
    def piston_maximum(self):
        return self.get("pmax")

    @piston_maximum.setter
    def piston_maximum(self, maxval):
        if type(maxval) != float:
            raise TypeError(
                f"Piston minimum requires a float value.  {type(maxval)} was used."
            )
        self.set("pmin", maxval)

        pminret = self.get("pmin")
        if pminret != maxval:
            raise ValueError("PMin not set correctly")

    @property
    def piston_rate(self):
        return self.get("prate")

    @property
    def travel_direction(self):
        dir = self.get("tdir")

        if dir == 1:
            return "Extension"
        elif dir == -1:
            return "Retraction"
        else:
            raise ValueError(f"Invalid direction returned, {dir}.")

    @property
    def travel_engaged(self):
        if self.get("teng"):
            return "Engaged"
        else:
            return "Halted"

    @property
    def travel_zero(self):
        tzero = self.get("tzero")
        if bool(tzero):
            return [True, "Fully Retracted"]
        else:
            return [False, "Not Fully Retracted"]

    @property
    def travel_full(self):
        tzero = self.get("tfull")
        if bool(tzero):
            return [True, "Fully Extended"]
        else:
            return [False, "Not Fully Extended"]

    @property
    def pid_p(self):
        return get("pidp")

    @pid_p.setter
    def pid_p(self, value: float):
        if type(value) != float:
            raise TypeError(f"pidp requires a float, not {type(value)}.")
        self.set("pidp", value)

        pidp = self.get("pidp")
        if pidp != value:
            raise ValueError(
                f"pidp not set correctly.  Expected {value}, received {pidp}"
            )

    @property
    def pid_i(self):
        return get("pidi")

    @pid_i.setter
    def pid_i(self, value: float):
        if type(value) != float:
            raise TypeError(f"pidi requires a float, not {type(value)}.")
        self.set("pidi", value)

        pidp = self.get("pidi")
        if pidp != value:
            raise ValueError(
                f"pidi not set correctly.  Expected {value}, received {pidi}"
            )

    @property
    def pid_d(self):
        return get("pidd")

    @pid_d.setter
    def pid_d(self, value: float):
        if type(value) != float:
            raise TypeError(f"pidd requires a float, not {type(value)}.")
        self.set("pidd", value)

        pidd = self.get("pidd")
        if pidd != value:
            raise ValueError(
                f"pidd not set correctly.  Expected {value}, received {pidd}"
            )

    @property
    def logging_level(self):
        lvl = self.get("level")

        if lvl == 0:
            return [0, "Off"]
        elif lvl == 1:
            return [1, "Debug+"]
        elif lvl == 2:
            return [2, "Warning+"]
        elif lvl == 3:
            return [3, "Errors Only"]
        else:
            raise ValueError(f"Level {lvl} not recognized")

    @logging_level.setter
    def logging_level(self, value):
        if 0 <= value <= 3:
            self.set("level", value)
        else:
            raise ValueError(f"Level {lvl} outside of acceptable values")

        lvl = self.logging_level
        if value != lvl:
            raise ValueError(
                "Logging level not set correctly.  Expected {value}, received {lvl}"
            )

    @staticmethod
    def _valid_addr(addr) -> bool:
        if addr > int("0x02FF", 16):
            return False
        return True

    @staticmethod
    def _valid_led(led: str) -> bool:
        if led not in ["GREEN", "BLUE"]:
            raise ValueError(f"Invalid LED {led}")
        return True

    @staticmethod
    def _is_ack(value:str)->bool:
        if value == 0x06:
            return True
        else:
            return False