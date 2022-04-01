#include "LPD8806.h"
#include <SPI.h>
#include <Wire.h>

#define nLEDs  60

#define dataPin    11
#define clockPin   13
#define lukeButton 15

LPD8806 strip  = LPD8806(nLEDs, dataPin, clockPin);

int sabreBuffer[nLEDs+1];
int sabreOn = 0;
int mode = 0;
int state = 0;

void setup() {
  pinMode(lukeButton, INPUT);
  
  strip.begin();
  
  for(int i = 0; i < nLEDs; i++){
    strip.setPixelColor(i, 0,0,0); 
  }

  strip.show(); 
}


void loop() { 
  
  //fuck_it_im_using_jumps:
  
  if(digitalRead(lukeButton) == 1){
    delay(100);
    if(digitalRead(lukeButton) == 1){
      sabreOn = true;
      mode++;
      if(mode > 4) mode = 1;
    }
  }else{
    sabreOn = false;
  }
  
  strip.show();
  
  if(sabreOn == true){
    nyan();
  }
}



