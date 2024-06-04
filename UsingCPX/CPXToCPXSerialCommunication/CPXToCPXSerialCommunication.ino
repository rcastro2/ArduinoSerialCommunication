#include <Adafruit_CircuitPlayground.h>
String recvString;

void colorAll(int c){
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i,CircuitPlayground.colorWheel(c));
  }
}
void setup() {
  CircuitPlayground.begin();
  Serial1.begin(9600);
}
void loop() {
  if (Serial1.available()) {
    recvString = Serial.readString();
    Serial.println(recvString.toInt());
    colorAll(recvString.toInt());
  }
  if(CircuitPlayground.leftButton()){
    x+=10;
    Serial1.println(x);
  }
  delay(200);
}

