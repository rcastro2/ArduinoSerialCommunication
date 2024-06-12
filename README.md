<h1>Arduino Serial Communication</h1>
<h2>Overview</h2>
<p>
Projects explore various ways to communicate between the CircuitPlayground Express and other technologies through serial communication.  Each project is further discussed below. In all projects appropriate libraries needed to be load in order to accomplish the serial communication.  CircuitPlayground Expressed used the Serial object which is part of Arduino, to communicate.  In each project the Arduino sketch must be loaded into the CircuitPlayground Express and the program for the corresponding technology must be executed.
</p>
<hr>
<h2>Using Python</h2>
<p>
This project explores how to communicate between the CircuitPlayground Express and a standard Python program. Project uses the pyserial library in order to communicate via serial.  There are three programs included in this project.  The "SerialArduinoPython" program demonstrates communicating back and forth between a Python program and the CircuitPlayground Express.  The "CPXTurle" program demonstrates using the CircuitPlayground Express to control the movement and color of a Python Turtle. The "Pygame" program demonstrates using the CircuitPlayground Express to control the sideway movement of a paddle in a video game using the accelerometer.  This program requires the pygame library in order to run.
</p>
<hr>
<h2>Using Web</h2>
<p>
This project explores how to communicate between the CircuitPlayground Express and a web page. Project uses the WebSerial API which is still under development, in order to communicate via serial.  The project also uses an additional library "tessel-web-serial" to decode the serial data from the CircuitPlayground Express. 
</p>
<p>
There are three programs included in this project.  The "basic" program allows you to specify an index on a color wheel to use for all the NeoPixels on the CircuitPlayground Express.  From the CircuitPlayground Express you can press the buttons to change the background color of the webpage.  The "advanced" program modifies the information communicated to the CircuitPlayground Express in the previous program to include the brightness of the NeoPixels and the amount of red, green and blue to use for the color of all the NeoPixels. The "Flappy Bird" program demonstrates using the CircuitPlayground Express to control the up and down movement of the bird as you collect coins and dodge pipes in the video game. The game component of the program is developed using a custom library included in the project.
</p>
<p> 
<b>Note:</b> <i>Only certain browsers support the WebSerial API.  Upon opening the webpage, a window opens allowing you to specify the port to use in order to communicate via serial with the CircuitPlayground Express.</i>
</p>
<hr>
<h2>Using Flask</h2>
<p>
This project explores how to incorporate the CircuitPlayground Express into an "Internet of Things" application.  Flask is a Python framework used to create web applications through a web server.  This project differs from the previous, "Using Web" in that the web page itself does not make a connection to the CircuitPlayground Express but rather the Python Flask application establishes the connection and makes communication to the CircuitPlayground Express available through its routes. The Python Flask application provides various ways to turn the NeoPixels on the CircuitPlayground Express on and off.  
</p>
<hr>
<h2>Using CPX</h2>
<p>
This project explores how to communicate between two CircuitPlayground Express boards via serial communication over wire connection. Two wires are required in order to connect the Tx and Rx of one CircuitPlayground Express to the other CircuitPlayground Express inversely. Unlike the other projects which used the Serial object to communicate to and from the CircuitPlayground Express, this project requires the use of the Serial1 object which is design for serial communication over the wire using the Tx and Rx connectors. 
</p>
<p>
There are two programs included in this project.  CPXtoCPXSerialCommunication program allows you to control the color of the NeoPixels on the other CircuitPlayground Express by transmitting an index to the color wheel.  CatchTheNeoPixel program is a game where you go head to head to see who can catch the yellow NeoPixel five times first. Use the left and right buttons to spin around the CircuitPlayground Express.
</p>