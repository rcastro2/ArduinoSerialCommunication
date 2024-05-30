import serial
import time
import turtle
import asyncio

arduino = serial.Serial(port='COM7',  baudrate=9600, timeout=.1)
bob = turtle.Turtle()
bob.speed(10)

queue = asyncio.Queue()

async def process_commands():
    while True:
        if arduino.inWaiting() > 0:
            data = arduino.readline()
            print(data)
        
            if b'F' in data:
                new_status = "F"
            elif b"L" in data:
                new_status = "L"
            elif b"R" in data:
                new_status = "R"
            else:
                new_status = "S"
            
            await queue.put(new_status)
        else:
            await asyncio.sleep(0.01)
    
async def update_turtle():
    while True:
        status = await queue.get()
        if status == "F":
            bob.forward(5)
        elif status == "L":
            bob.left(5)
        elif status == "R":
            bob.right(5)
        await asyncio.sleep(0.01)
        

async def main():
    await asyncio.gather(process_commands(),update_turtle())

if __name__ == "__main__":
    asyncio.run(main())
