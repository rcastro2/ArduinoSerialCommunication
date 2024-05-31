import serial
import time
import turtle

cpx_port = input("Enter the COM port to the CPX:")
arduino = serial.Serial(port=f'COM{cpx_port}',  baudrate=9600, timeout=.1)

bob = turtle.Turtle()
bob.width(5)
bob.speed(10)
status = "S"
driver = False

while True:
    if arduino.inWaiting() > 0:
        data = arduino.readline()
        print(data)

        if b'F' in data:
            status = "F"
        elif b"L" in data:
            status = "L"
        elif b"R" in data:
            status = "R"
        else:
            status = "S"
        
        if b"r" in data:
            bob.color("red")
        elif b"g" in data:
            bob.color("green")
        elif b"b" in data:
            bob.color("blue")
        elif b"k" in data:
            bob.color("black")

        if b"O" in data:
            driver = True
        elif b"X" in data:
            driver = False    
        
            
    if status == "F" or driver:
        bob.forward(2)
    if status == "L":
        bob.left(10)
    elif status == "R":
        bob.right(10)
    time.sleep(0.02)
