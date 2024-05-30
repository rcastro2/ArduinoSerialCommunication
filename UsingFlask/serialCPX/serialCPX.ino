#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  if (Serial.available()) {
    char incomingByte = Serial.read();
    if (incomingByte == '1') {
      CircuitPlayground.setPixelColor(0,255,255,255);
    } else if (incomingByte == '0') {
      CircuitPlayground.clearPixels();
    }
  }
}
