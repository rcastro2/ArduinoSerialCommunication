#include <Adafruit_CircuitPlayground.h>
int us = 0, them = 0;
int target = -1;
int score = 0;
char jumpLocs[] = {'A','B','C','D','E','F','G','H','I','J'};
bool gameover = false;

void colorAll(int r, int g, int b){
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i,r,g,b);
  }
}
void setup() {
  CircuitPlayground.begin();
  Serial1.begin(9600);
  while(target == -1){
    if(CircuitPlayground.slideSwitch()){
      target = jump();
      Serial1.println(target);
    }else if (Serial1.available()) {
      String data = Serial1.readString();
      Serial.println(data);
      target = data.toInt();   
      Serial.println(target); 
    }
    delay(100);
  }
  colorAll(255,255,255);
  delay(2000);
}
void loop() {
  CircuitPlayground.clearPixels();
  if(gameover) return;

  if (Serial1.available()) {
    int data = Serial1.read();
    Serial.println(data);
    if(data < 60){
      them = data - 48;
    }else if(data == 90){
      gameover = true;
    }else{
      target = data - 65;
    }
  }
  if(CircuitPlayground.leftButton()){
    us++;
    checkBoundaries();
    Serial1.print(us);
  }
  if(CircuitPlayground.rightButton()){
    us--;
    checkBoundaries();
    Serial1.print(us);
  }
  CircuitPlayground.setPixelColor(target,255,255,0);
  CircuitPlayground.setPixelColor(them,255,0,0);
  CircuitPlayground.setPixelColor(us,0,0,255);
  if(target == us){
    score++;
    target = jump();
    Serial1.print(jumpLocs[target]);
  }
  if(score >= 5){
    colorAll(0,255,0);
    Serial1.print('Z');
  }
  
  delay(100);
}
void checkBoundaries(){
  if(us > 9) us = 0;
  if(us < 0) us = 9;
}
int jump(){
  int locs[9];
  int pos = 0;
  for(int i = 0; i < 10;i++){
    if(i != us && i != them){
      locs[pos] = i;
      pos++;
    }
  }
  int r = random(0,pos);
  return locs[r];

}
