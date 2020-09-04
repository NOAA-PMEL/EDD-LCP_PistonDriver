import serial
import threading

class HallEffect:
    def __init__(self, port, inches):
        self._ser = serial.Serial(port, 115200, timeout=1)
        self.count = 0
        self.rate = 0
        self.__counts_per_inch = 15000;
        self.__counts_per_inch = inches
        self._get_message()

    def close(self):
        # self.t.cancel()
        self._ser.close()

    @property
    def count(self):
        return self.__count

    @count.setter
    def count(self, value):
        self.__count = value

    @property
    def rate(self):
        return self._rate

    @rate.setter
    def rate(self, value):
        if(type(value) != int):
            raise TypeError('rate value must be int type')
        else:
            self._rate = value
    
    @property
    def counts_per_inch(self):
        return self.__counts_per_inch

    @counts_per_inch.setter
    def counts_per_inch(self, value):
        self.__counts_per_inch = value
        
    @property
    def position(self):
        return self.count/self.counts_per_inch

    def set_extension(self):
        self._ser.write(b'E')

    def set_retraction(self):
        self._ser.write(b'R')

    def set_brake(self):
        self._ser.write(b'B')

    def zero_count(self):
        self._ser.write(b'Z')


    def _get_message(self):
        self._ser.flushInput()
        line = self._ser.read_until().decode()
        # print(line)
        try:
            (count, rate) = line[1:].rstrip().split(',')
            self.count = int(count)
            self.rate = int(rate)
        except Exception as e:
            print(e)

        # self.t = threading.Timer(0.25, self._get_message).start()