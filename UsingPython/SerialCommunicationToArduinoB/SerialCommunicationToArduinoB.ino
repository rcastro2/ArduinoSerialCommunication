#include <Adafruit_CircuitPlayground.h>
int pos = 0, amt = 0;
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  
  // put your main code here, to run repeatedly:
  while (!Serial.available());
  
  amt = Serial.readString().toInt();
  pos += amt;
  //Serial.print(amt);
  //CircuitPlayground.setPixelColor(0,255,0,0);
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(pos%10,255,0,0);
  delay(10);
}
