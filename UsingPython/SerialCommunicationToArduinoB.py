import serial
import keyboard
import time

arduino = serial.Serial(port='COM62',  baudrate=9600, timeout=.1)


def write_data(x):
    arduino.write(bytes(x,  'utf-8'))
    time.sleep(0.01)
    #print(arduino.readline())


while True:
    print("Key")
    print(keyboard.read_key())
    if keyboard.read_key() == "left":
        write_data("-1")
    elif keyboard.read_key() == "right":
        write_data("1")
    time.sleep(1)
