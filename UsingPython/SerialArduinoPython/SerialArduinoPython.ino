#include <Adafruit_CircuitPlayground.h>
int c, t = 0;
void colorAll(int c){
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i,CircuitPlayground.colorWheel(c));
  }
}
void setup() {
  CircuitPlayground.begin();
}
void loop() {
  while (!Serial.available());
  CircuitPlayground.clearPixels();
  c = Serial.readString().toInt();
  colorAll(c);
  t++;
  Serial.print(t);
  
}
