#include <Adafruit_CircuitPlayground.h>
String recvString;
int x = 0;

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
    recvString = Serial1.readString();
    int c = recvString.toInt();
    Serial.println(c); //Demonstrate the ability to communicate on two serial ports
    colorAll(c);
  }
  if(CircuitPlayground.leftButton()){
    x+=10;
    Serial1.println(x);
    delay(100);
  }
  delay(100);
}

