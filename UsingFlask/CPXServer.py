from flask import Flask
from flask import render_template
import serial

app = Flask(__name__)

cpx_port = input("Enter the COM port to the CPX:")
arduino = serial.Serial(port=f'COM{cpx_port}',  baudrate=9600, timeout=.1)

@app.route("/")
def index():
    return "Welcome to CPX interface."

@app.route("/on")
def led_on():
    arduino.write(bytes('1',  'utf-8'))
    return "LED On!"
    #return render_template("lightSwitch.html",info='1')

@app.route("/off")
def led_off():
    arduino.write(bytes('0',  'utf-8'))
    return "LED Off!"
    #return render_template("lightSwitch.html",info='0')

@app.route("/pixel/<status>")
def led_switch(status=None):
    arduino.write(bytes(f'{status}',  'utf-8'))
    return "LED On!" if status == '1' else "LED Off!"

@app.route("/LED/")
@app.route("/LED/<led_state>")
def rendered_switch(led_state=None):
    if led_state == 'on':
        arduino.write(bytes('1',  'utf-8'))
    elif led_state == 'off':
        arduino.write(bytes('0',  'utf-8'))
        
    return render_template("lightSwitch.html",info=led_state)
#>python -m flask --app CPX run --host=0.0.0.0
