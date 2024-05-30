#include <Adafruit_CircuitPlayground.h>
int x = 0;
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  
  // put your main code here, to run repeatedly:
  while (!Serial.available());
  CircuitPlayground.clearPixels();
  x = Serial.readString().toInt();
  Serial.print(x);
  //CircuitPlayground.setPixelColor(0,255,0,0);
  CircuitPlayground.setPixelColor(x,255,0,0);
}
