#include <Adafruit_CircuitPlayground.h>
char status = '\0', newStatus = '\0';
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}
void colorAll(int r, int g, int b){
  for(int i = 0; i <= 9; i++){
    CircuitPlayground.setPixelColor(i, r,g,b);
  }
}

void loop() {
  CircuitPlayground.clearPixels();
  if(CircuitPlayground.motionX() > 4){
    newStatus = 'L';
  }else if(CircuitPlayground.motionX() < -4){
    newStatus = 'R';
  }else{
    newStatus = 'S';
  }
  if (Serial.available()) {
    int data = Serial.read();
    if(data == 'h'){
      colorAll(255,0,0);
      if(CircuitPlayground.slideSwitch()){
        CircuitPlayground.playTone(261,50);
      }else{
        delay(50);
      }
    }else if(data == 'b'){
      colorAll(255,255,255);
      if(CircuitPlayground.slideSwitch()){
        CircuitPlayground.playTone(523,50);
      }else{
        delay(50);
      }
    }else{
      delay(50);
    }
  }else{
    delay(50);
  }
 if(status != newStatus){
  status = newStatus;
  Serial.print(status);
 }
}
