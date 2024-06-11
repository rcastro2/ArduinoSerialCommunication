#include <Adafruit_CircuitPlayground.h>
char status = '\0', newStatus = '\0';
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}
void colorAll(int c, int s, int e){
  for(int i = s; i <= e; i++){
    CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(c));
  }
}

void loop() {
  CircuitPlayground.clearPixels();
 if(CircuitPlayground.motionX() > 4){
  colorAll(120,0,4);
  newStatus = 'L';
 }else if(CircuitPlayground.motionX() < -4){
  colorAll(120,5,9);
  newStatus = 'R';
 }else{
  newStatus = 'S';
 }
 
 if(status != newStatus){
  status = newStatus;
  Serial.print(status);
 }
 delay(50);
}
