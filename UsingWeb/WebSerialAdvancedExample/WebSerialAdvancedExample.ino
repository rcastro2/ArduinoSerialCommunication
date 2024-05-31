#include <Adafruit_CircuitPlayground.h>
String recvString;
void colorAll(int r, int g, int b){
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i,r,g,b);
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
      Serial.println("255,255,255");
    } else {
      int i1 = recvString.indexOf(',');
      int i2 = recvString.indexOf(',', i1+1);
      int i3 = recvString.indexOf(',', i2+1);

      String r = recvString.substring(0, i1);
      String g = recvString.substring(i1 + 1, i2);
      String b = recvString.substring(i2 + 1, i3);
      String brightness = recvString.substring(i3 + 1);
      CircuitPlayground.setBrightness(brightness.toInt());
      colorAll(r.toInt(),g.toInt(),b.toInt());
      Serial.println(g + "," + b + "," + r);
    }
    
  }
  if(CircuitPlayground.leftButton() && CircuitPlayground.rightButton()){
    Serial.println("255,255,0");
    delay(1000);
  }else if(CircuitPlayground.leftButton()){
    Serial.println("0,255,255");
    delay(1000);
  }else if(CircuitPlayground.rightButton()){
    Serial.println("255,0,255");
    delay(1000);
  }
}
