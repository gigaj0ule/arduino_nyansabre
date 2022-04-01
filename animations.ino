void fadeOut(){
  for(int i = nLEDs / 2; i > 0; i--){
    strip.setPixelColor(i, Wheel(sabreBuffer[i], 0));
    strip.setPixelColor(60 - i, Wheel(sabreBuffer[60 - i], 0));
    delay(5);
    
    strip.show(); 
  }
  
  for(int i = 0; i < nLEDs; i++){
    strip.setPixelColor(i, 0,0,0); 
  }
  
  strip.show();
}


void fadeIn(){
  
  for(int i = 0; i < nLEDs; i++){
    strip.setPixelColor(i, 0,0,0); 
  }
  
  strip.show(); 
  
  for(int i = 0; i < nLEDs / 2; i++){
    strip.setPixelColor(i, Wheel(sabreBuffer[i], 1));
    strip.setPixelColor(60 - i, Wheel(sabreBuffer[60 - i], 1));
    delay(5);
    strip.show(); 
  }
}

void flashit(){
  for(int i = 0; i < nLEDs; i++){
    strip.setPixelColor(i, 255, 255, 255);
  }
  strip.show();
  
  delay(25);
  
    for(int i = 0; i < nLEDs; i++){
    strip.setPixelColor(i, 0, 0, 0);
  }
}

