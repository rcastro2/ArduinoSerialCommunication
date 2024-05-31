import serial
import time

cpx_port = input("Enter the COM port to the CPX:")
arduino = serial.Serial(port=f'COM{cpx_port}',  baudrate=9600, timeout=.1)


def write_read(x):
    arduino.write(bytes(x,'utf-8'))
    time.sleep(1)
    data = arduino.readline()
    return  data


while True:
    num = input("Enter an index (0-255) to the color wheel: ")
    value  = write_read(num)
    print(value)
