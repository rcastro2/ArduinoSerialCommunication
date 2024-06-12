#include <Adafruit_CircuitPlayground.h>
char status = '\0', newStatus = '\0';

void colorAll(int r, int g, int b){
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i,r,g,b);
  }
}
void setup() {
  CircuitPlayground.begin();
}
void loop() {
  CircuitPlayground.clearPixels();  
  if(CircuitPlayground.leftButton() || CircuitPlayground.rightButton()){
    newStatus = 'e';
  }else if(CircuitPlayground.motionY() < -4){
    newStatus = 'u';
  }else {
    newStatus = 'd';
  }
  if (Serial.available()) {
    int data = Serial.read();
    if(data == 'h'){
      colorAll(0,250,250);
      CircuitPlayground.playTone(261,50);
    }
  }else{
    delay(100);
  }
  if(status != newStatus){
    status = newStatus;
    Serial.print(status);
  }
}
