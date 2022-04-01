void nyan(){
  
  // Set up color buffer
  for (int i = 0; i < nLEDs/2; i++) {
    int color = (((i * 384 / (nLEDs/2)) + 384) % 384);
    sabreBuffer[i + 1 ] = color;
    sabreBuffer[60 - i] = color;
  }
  
  // Fade in color buffer
  flashit();

  // Cycle colors
  while(true){
    for (int j = 384; j > 0; j--) {    
      
      for (int i = 0; i < nLEDs/2; i++) {
        
        int color = (((i * 384 / (nLEDs/2)) + j) % 384);
        
        sabreBuffer[i + 1 ] = color;
        sabreBuffer[60 - i] = color;
        
        strip.setPixelColor(i, Wheel(color, 1));
        strip.setPixelColor(60 - i, Wheel(color, 1));
      }
      
      strip.show();    
    
      // If luke button is pressed then exit
      if (digitalReadFast(lukeButton) == state){
        delay(50);
        if (digitalReadFast(lukeButton) == state){
          flashit();
          goto fuck_it_im_using_jumps;
        }
      } 
    }   
  }
  
  fuck_it_im_using_jumps:;
}
