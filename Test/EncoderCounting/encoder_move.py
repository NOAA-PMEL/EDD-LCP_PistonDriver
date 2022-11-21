import serial as ser
import time
import re






speeds = list(range(75,105,5))#[100, 90, 80] #[40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]
speeds.reverse()
delay = [int( (80/(x/100)+1)*1.1) for x in speeds]

speed_return = 100
delay_return = (80 / (speed_return/100))

time_length = (sum(delay) + delay_return*len(delay)) * 1.1
print(f'Total time expected = {time_length/60} minutes')


delay_times = []

CONSOLE_OK = b'> OK\r\n'
ZERO_STR = b'set zero 0\r\n'
CLEAR_ENC_STR = b'set encode 0\r\n'
GET_ENC_STR = b'get encode\r\n'

ENCODE_PATTERN = "encode= (.+?)\r\n"

encoder_zero = [None]*len(delay)
encoder_full = [None]*len(delay)

def get_encoder(dev):
    dev.write(GET_ENC_STR)
    time.sleep(1)
    readstr = dev.read_all().decode()
    count = re.search(ENCODE_PATTERN, readstr).group(1)
    print(f'Encoder count = {count}, {speed=}')
    return int(count)

if __name__ == "__main__":
    dev = ser.Serial('COM5', 115200, timeout=1.0)
    dev.write(b'debug\r\n')
    time.sleep(3)
    dev.flushInput()

    try:

        for idx, speed  in enumerate(speeds):
            print(f'\n*** STARTING RUN @ SPEED = {speed}')
            dev.write(ZERO_STR)

            # Zero the system
            read_flg = False;
            while not read_flg:
                readline = dev.readline()
                # print(readline)
                if(readline == CONSOLE_OK):
                    read_flg = True
                else:
                    time.sleep(0.1)
            print("System zeroed")

            # Clear the encoder (just to make sure)
            time.sleep(2)
            dev.write(CLEAR_ENC_STR)
            get_encoder(dev)
            # print(dev.read_all())

            # Extend the piston
            print(f'Extending - Delaying for {delay[idx]} seconds')
            sendstr = f'set fwd {speed}\r\n'
            dev.write(sendstr.encode())
            time.sleep(2)
            readstr = dev.read_all()
            if CONSOLE_OK not in readstr:
                raise SystemError('Did not accept fwd request')
            time.sleep(int(delay[idx]))

            # Get the encoder count
            encoder_full[idx] = get_encoder(dev)
            # dev.write(GET_ENC_STR)
            # time.sleep(1)
            # readstr = dev.read_all().decode()
            # count = re.search(ENCODE_PATTERN, readstr).group(1)
            # print(f'Encoder count @ Zero = {count}, {speed=}')
            # encoder_full[idx] = int(count)

            # Retract the piston
            print(f'Retracting - Delaying for {delay[idx]} seconds')
            # sendstr = f'set rev {speed_return}\r\n'
            sendstr = f'set rev {speed}\r\n'
            dev.write(sendstr.encode())
            time.sleep(2)
            readstr = dev.read_all()
            if CONSOLE_OK not in readstr:
                raise SystemError('Did not accept fwd request')

            
            time.sleep(int(delay[idx]))

            # Get the encoder count
            encoder_zero[idx] = get_encoder(dev)
            # dev.write(GET_ENC_STR)
            # time.sleep(1)
            # readstr = dev.read_all().decode()
            # count = re.search(ENCODE_PATTERN, readstr).group(1)
            # print(f'Encoder count @ Zero = {count}, {speed=}')
            # encoder_zero[idx] = int(count)
 

            print(f'speed={speed}, ret_speed={speed}, full_cnt={encoder_full[idx]}, zero_cnt={encoder_zero[idx]}, diff={encoder_full[idx]-encoder_zero[idx]}')
            print("Test complete")
    except Exception as  e:
        print("Test Failure")
        print(e)
    finally:

        dev.write(b'stop\r\n')
        dev.close()
        
        print("Exiting")