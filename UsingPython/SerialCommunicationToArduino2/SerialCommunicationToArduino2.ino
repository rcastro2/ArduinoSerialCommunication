#include <Adafruit_CircuitPlayground.h>
char status = '\0', newStatus = '\0';
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}
void colorAll(int pos){
  for(int x = 0; x < 10; x++){
    CircuitPlayground.setPixelColor(x, CircuitPlayground.colorWheel(pos));
  }
}
bool readCap(int pos){
  return CircuitPlayground.readCap(pos) > 400;
}

void loop() {
  
  // put your main code here, to run repeatedly:
 if(CircuitPlayground.leftButton() && CircuitPlayground.rightButton()){
  newStatus = 'F';
 }else if(CircuitPlayground.rightButton()){
  newStatus = 'R';
 }else if(CircuitPlayground.leftButton()){
  newStatus = 'L';
 }else if(readCap(A3)){
  colorAll(0);
  newStatus = 'r';
 }else if(readCap(A1)){
  colorAll(64);
  newStatus = 'g';
 }else if(readCap(A7)){
  colorAll(160);
  newStatus = 'b';
 }else if(readCap(A5)){
  CircuitPlayground.clearPixels();
  newStatus = 'k';
 }else if(CircuitPlayground.slideSwitch() == 1){
  newStatus = 'O';
 }else if(CircuitPlayground.slideSwitch() == 0){
  newStatus = 'X';
 }else{
  newStatus = 0;
 }
 
 if(status != newStatus){
  status = newStatus;
  Serial.print(status);
 }
 delay(100);
}
