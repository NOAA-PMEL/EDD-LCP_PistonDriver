import serial
import time

class R85PRO:
    def __init__(self, port):
        self._ser = serial.Serial(port, 9600, timeout=1)
        

    def set_relay(self, relay):
        self._ser.flushOutput()
        if relay > 7:
            raise ValueError(f'Relay values are 1 - 8, {relay} not valid')

        relay += 8
        sendcmd = bytes.fromhex("FE") + relay.to_bytes(1,byteorder='big')

        # print(f"{sendcmd=}")
        self._ser.write(sendcmd)

    def clear_relay(self, relay):
        self._ser.flushOutput()
        if relay > 7:
            raise ValueError(f'Relay values are 1 - 8, {relay} not valid')
        sendcmd = bytes.fromhex("FE") + relay.to_bytes(1,byteorder='big')
        # print(f"{sendcmd=}")
        self._ser.write(sendcmd)


    def get_relay_status(self):
        self._ser.flush()
        self._ser.write(bytes.fromhex("FE18"))
        
        relays = self._ser.read(1)

    def close(self):
        self._ser.close()


if __name__ == "__main__":
    dev = R85PRO('COM13')

    dev.set_relay(0)
    dev.set_relay(1)

    dev.set_relay(3)
    time.sleep(10)
    dev.set_relay(4)
    time.sleep(1)
    dev.clear_relay(3)
    time.sleep(10)
    dev.clear_relay(4)
    dev.close()