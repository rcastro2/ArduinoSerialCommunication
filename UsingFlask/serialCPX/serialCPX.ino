#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  if (Serial.available()) {
    char incomingByte = Serial.read();
    if (incomingByte == '1') {
      for(int i = 0; i < 10; i++){
        CircuitPlayground.setPixelColor(i,CircuitPlayground.colorWheel(i * 27));
      }    
    } else if (incomingByte == '0') {
      CircuitPlayground.clearPixels();
    }
  }
}
