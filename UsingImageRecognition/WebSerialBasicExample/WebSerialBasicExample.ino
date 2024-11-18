#include <Adafruit_CircuitPlayground.h>
String recvString;
void colorAll(int c){
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i,CircuitPlayground.colorWheel(c));
  }
}
void setup() {
  CircuitPlayground.begin();
}
void loop() {
  if (Serial.available()) {
    recvString = Serial.readString();
    if (recvString == "0") {
      CircuitPlayground.clearPixels();
    } else {
      colorAll(recvString.toInt());
    }
    delay(100);
  }
  if(CircuitPlayground.leftButton() && CircuitPlayground.rightButton()){
    Serial.println("yellow");
    delay(1000);
  }else if(CircuitPlayground.leftButton()){
    Serial.println("cyan");
    delay(1000);
  }else if(CircuitPlayground.rightButton()){
    Serial.println("magenta");
    delay(1000);
  }
}
