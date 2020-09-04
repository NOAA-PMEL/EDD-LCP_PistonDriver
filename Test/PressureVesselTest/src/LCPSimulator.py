import sys
from threading import Event, Thread
import time
# import threading
import datetime as dt
from R85Pro import R85PRO as Relay
from HallEffect import HallEffect as HE

POWER_RELAY_1 = 0
POWER_RELAY_2 = 1
DRIVE_RELAY_1 = 3
DRIVE_RELAY_2 = 2


PISTON_LENGTH_INCHES = 8
ACTUAL_PISTON_DISPLACEMENT_INCHES = 7.75
COUNTS_PER_INCH = 188900 / ACTUAL_PISTON_DISPLACEMENT_INCHES

class LCP:
    def __init__(self, relay_port, he_port):
        """
        __init__ LCP Init

        LCP Class Init

        :param relay_port: Relay Com Port
        :type relay_port: Com Port
        :param he_port: Hall Encoder Port
        :type he_port: Com Port
        """
        self._relay = Relay(relay_port)
        self._he = HE(he_port, COUNTS_PER_INCH)

        self._power = False

    def close(self):
        """
        close Close the Serial Ports

        Close the Relay and Hall Effect Serial Ports
        """
        self._relay.close()
        self._he.close()

    @property
    def power(self):
        """
        power Get Power State

        Get the state of the power relays

        :return: Power state
        :rtype: bool
        """
        return self._power

    @power.setter
    def power(self, value):
        """
        power Set Power State

        Set the state of the power relays

        :param value: Power state (On/Off)
        :type value: bool
        :raises TypeError: Invalid value type
        """
        if(type(value) != bool):
            raise TypeError('value must be a boolean')
        else:
            self._power = value

    def power_on(self):
        """
        power_on Power Relays ON

        Turn the power relays ON
        """
        self._relay.set_relay(POWER_RELAY_1)
        self._relay.set_relay(POWER_RELAY_2)
        self.power = True

    def power_off(self):
        """
        power_on Power Relays ON

        Turn power to piston OFF
        Additionally, brake the piston
        """
        self._piston_brake()
        self._relay.clear_relay(POWER_RELAY_2)
        self._relay.clear_relay(POWER_RELAY_1)
        self.power = False

    def run_full_cycles(self, 
                        num_cycles):
        """
        run_full_cycles Run between full range

        Runs the piston between full range of piston 
        for specified number of times.

        :param num_cycles: Number of cycles to run
        :type num_cycles: int
        """
        print("Run full cycle {num_cycles} times")
        while num_cycles > 0:
            self.run_to_full()
            self.run_to_home()
            num_cycles -= 1

    def run_partial_cycles(self, 
                        start_pos, 
                        end_pos, 
                        num_cycles,
                        dwell_time):
        """
        run_partial_cycles Run between range

        Runs the pistons between specified range

        :param start_pos: Start of Range
        :type start_pos: float
        :param end_pos: End of Range
        :type end_pos: float
        :param num_cycles: Number of cycles to run
        :type num_cycles: int
        :param dwell_time: Time (seconds) to dwell after reaching position
        :type dwell_time: float
        """

        print(f"Run from {start_pos} inches to {end_pos} inches {num_cycles} times")
        self.run_to_XX(start_pos)

        for i in range(num_cycles):
            print(f"Cycles: {i+1} of {num_cycles}, Current Position: {self._he.position:.2f}")
            time.sleep(dwell_time)
            self.run_to_XX(end_pos)
            print(f"Cycles: {i+1} of {num_cycles}, Current Position: {self._he.position:.2f}")
            time.sleep(dwell_time)
            self.run_to_XX(start_pos)

            

    def run_to_home(self):
        """
        run_to_home Run the piston home

        Retracts the piston completely

        :raises ValueError: Power is Off
        :raises TimeoutError: Piston runs > 10 minutes
        """
        if self.power != True:
            raise ValueError('Power is not on')

        self._piston_retract()
        time.sleep(0.5)
        start_time = dt.datetime.now()
        while (abs(self._he.rate) > 0):
            elapsed_time = dt.datetime.now() - start_time
            if (elapsed_time.total_seconds() / 60) > 10.0:
                raise TimeoutError('Piston extending for > 10 minutes')
            print(f"Retracting, Time Passed: {elapsed_time.total_seconds():.2f} seconds, Rate: {self._he.rate}, Count: {self._he.count}, Pos: {self._he.position:.2f}")
            time.sleep(0.25)

    def run_to_full(self):
        """
        run_to_full Run the piston to full extent

        Run the piston completely out

        :raises ValueError: Power is not on
        :raises TimeoutError: If piston extends for > 10 minutes
        """
        if self.power != True:
            raise ValueError('Power is not on')

        self._piston_extend()
        time.sleep(0.5)

        start_time = dt.datetime.now()
        while (self._he.rate != 0):
            elapsed_time = dt.datetime.now() - start_time
            if (elapsed_time.total_seconds() / 60) > 10.0:
                raise TimeoutError('Piston extending for > 10 minutes')
            print(f"Extending, Time Passed: {elapsed_time.total_seconds():.2f} seconds, Rate: {self._he.rate}, Count: {self._he.count}, Pos: {self._he.position:.2f}")
            time.sleep(0.25)

    def run_to_XX(self, 
                value):
        """
        run_to_XX Run the piston to XX inches

        Runs the piston to XX inches

        :param value: Inches to move to]
        :type value: float
        :raises ValueError: If power is not on.
        """
        print(f"Run to {value} inches")
        if self.power != True:
            raise ValueError('Power is not on')
        
        pos_diff = 0
        # Get the current position
        dir = 0
        if(self._he.position > value):
            pos_diff = self._he.position - value
            self._piston_retract()
            dir = -1
        else:
            pos_diff = value  - self._he.position
            self._piston_extend()
            dir = 1

        # If position is greater than 0.01", set piston state
        if abs(pos_diff) > 0.01:
            while pos_diff > 0.01:
                if(dir == -1):
                    pos_diff = self._he.position - value
                else:
                    pos_diff = value  - self._he.position
                
        self._piston_brake()

    def zero(self):
        """
        zero Perform homing zero

        Run the piston to home and zero the count.
        """
        print("Zero commanded")
        self.run_to_home()
        self._he.zero_count()
            
    def run_count_range(self):
        """
        run_count_range Get Counts in Piston Throw

        Runs the Zero function followed by full range.  At top
        of the range it grabs the number of encoder counts.
        Returns the piston to home.

        """
        print("Run count range commanded")
        self.zero()
        self._piston_brake()
        self.run_to_full()
        self._piston_brake()

        self._he.counts_per_inch = self._he.count / ACTUAL_PISTON_DISPLACEMENT_INCHES
        print(f"Counts/in = {self._he.counts_per_inch}")
        self.run_to_home()

    def _piston_extend(self):
        """
        Extend the piston relay positions
        """
        self._piston_brake()
        self._he.set_extension()
        self._relay.clear_relay(DRIVE_RELAY_2)
        self._relay.set_relay(DRIVE_RELAY_1)

    def _piston_retract(self):
        """
        Retract the piston relay positions
        """
        # print("_piston_retract called")
        self._piston_brake()
        self._he.set_retraction()
        self._relay.clear_relay(DRIVE_RELAY_1)
        self._relay.set_relay(DRIVE_RELAY_2)

    def _piston_brake(self):
        """
        Brake the piston relay positions 
        """
        self._relay.clear_relay(DRIVE_RELAY_1)
        self._relay.clear_relay(DRIVE_RELAY_2)

class ReadThread(Thread):
    def __init__(self, event):
        """
        __init__ Initialize the Read Thread

        Initialize the thread timer which reads 
        the Hall Effect sensor at specified rate

        :param event: Event
        :type event: Event
        """
        Thread.__init__(self)
        self.stopped = event
    def run(self):
        while not self.stopped.wait(0.125):
            dev._he._get_message()


if __name__ == "__main__":
    dev = LCP("COM13", "COM16")
    dev.power_on()

    stopFlag = Event()
    thread = ReadThread(stopFlag)
    thread.start()

    try:
        # time.sleep(2)

        # print("Extend...")
        # dev._piston_extend()
        # for i in range(10):  
        #     time.sleep(.5)
        #     # dev._he._get_message()
        #     print(f"rate={dev._he.rate}, pos={dev._he.count}")
            

        # print("Brake...")
        # dev._piston_brake()
        # time.sleep(1)

        # print("Retract...")
        # dev._piston_retract()
        # for i in range(5):  
        #     time.sleep(.5)
        #     # dev._he._get_message()
        #     print(f"rate={dev._he.rate}, pos={dev._he.count}")
        
        # print("Brake...")
        # dev._piston_brake()
        # time.sleep(1)
        
        # print("Homing...")
        # dev.run_to_home()

        # print("Fully Extended...")
        # dev.run_to_full()
        # time.sleep(20)

        # print("Homing...")
        # dev.run_to_home()
        # time.sleep(20)
        
        # print("Fully Extended...")
        # dev.run_to_full()
        # time.sleep(20)
        
        # print("Find Full Range Counts")
        # dev.run_count_range()

        # time.sleep(5)

        # dev.run_to_home()
        # time.sleep(10)

        # print("Move to 3in...")
        # dev.run_to_XX(3.0)

        # print("Move to 2.5 inches")
        # dev.run_to_XX(2.5)

        print("Zero")
        dev.zero()

        print("Run 3 Cycles between 2 inches and 3.5 inches")
        dev.run_partial_cycles(2, 3, 3, 2)
        

        print(f"Final position is: {dev._he.position:.2f}")
    except Exception as e:
        print(e)
    finally:
        stopFlag.set()
        dev.power_off()
        sys.exit()
        dev.close()
        
    



