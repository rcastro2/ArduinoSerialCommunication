import serial
from gamelib import *


cpx_port = input("Enter the COM port to the CPX:")
arduino = serial.Serial(port=f'COM{cpx_port}',  baudrate=9600, timeout=.1)

game = Game(660,384,"Paddle Game")
bk = Animation("background17SpriteSheet.png",8,game,5120/5,768/2,4)
ball = Image("globe.png",game)
ball.resizeBy(-90)
ball.setSpeed(4,60)

paddle1 = Image("paddle.png",game,False)
paddle1.y = game.height - 40
paddle1.score = 0
paddle1.direction = "S"

font = Font(white,40,black,"Comic Sans MS")

def cpxInput():
  if arduino.inWaiting() > 0:
    data = arduino.readline()

    if b"L" in data:
        paddle1.direction = "L"
    elif b"R" in data:
        paddle1.direction = "R"
    else:
        paddle1.direction = "S"

while not game.over:
  game.processInput()
  cpxInput()

  bk.draw()
  ball.move(True)
  paddle1.draw()
  
  if paddle1.direction == "L":
    paddle1.x -= 6
  elif paddle1.direction == "R":
    paddle1.x += 6

  if ball.y < 15:
    paddle1.score += 1

  if ball.y > game.height - 20:
    arduino.write(bytes('h','utf-8'))
    paddle1.health -= 10
    ball.moveTo(game.width / 2, game.height / 2)

  if paddle1.health < 0:
    game.over = True

  if ball.collidedWith(paddle1,"rectangle"):
    arduino.write(bytes('b','utf-8'))
    ball.changeYSpeed()
    ball.y -= ball.speed
    ball.speed += 0.5

  game.drawText(f"Score: {paddle1.score}",10,10, font)
  game.drawText(f"Health: {paddle1.health}",400,10, font)
  
  game.update(60)
game.quit()
