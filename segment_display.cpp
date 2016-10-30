#include "Arduino.h"
#include "segment_display.h"
#include <Adafruit_NeoPixel.h>

// public:

segment_display::segment_display(int digits, int pin){
  strip = Adafruit_NeoPixel(3*7*digits, pin, NEO_GRB + NEO_KHZ800);
  size = digits;
  black = strip.Color(0,0,0);
  red = strip.Color(50,0,0);
  green = strip.Color(0,25,0);
  blue = strip.Color(0,0,35);
  yellow = strip.Color(25,15,0);
}

void segment_display::begin(){
  Serial.begin(9600);
  strip.begin();
}

void segment_display::write(String message, uint32_t color){
  if(message.length() > size){
    Serial.print("message is too long\n");
  }
  else{
    for(int i=1; i <= size; i++){
      if(i <= message.length()){
        digit(size - i, message.charAt(message.length()-i), color);
      }else{
        digit(size - i, '8', black);
      }
    }
    update();
  }
}

uint32_t segment_display::color(byte r, byte g, byte b){
  return strip.Color(r,g,b);
}

//private:

//The first digit is 0, the first seg is 0
void segment_display::segment(int digit, int seg, uint32_t color){
  int startpixel = digit*21 + seg*3;
  strip.setPixelColor(startpixel, color);
  strip.setPixelColor(startpixel + 1, color);
  strip.setPixelColor(startpixel + 2, color);
}

//The first digit is 0
void segment_display::digit(int digit, char i, uint32_t color){
  switch (i) {
    case '1': segment(digit, 0, black);  segment(digit, 1, color);  segment(digit, 2, color);  segment(digit, 3, black);  segment(digit, 4, black);  segment(digit, 5, black);  segment(digit, 6, black);
      break;
    case '2': segment(digit, 0, color);  segment(digit, 1, color);  segment(digit, 2, black);  segment(digit, 3, color);  segment(digit, 4, color);  segment(digit, 5, black);  segment(digit, 6, color);
      break;
    case '3': segment(digit, 0, color);  segment(digit, 1, color);  segment(digit, 2, color);  segment(digit, 3, color);  segment(digit, 4, black);  segment(digit, 5, black);  segment(digit, 6, color);
      break;
    case '4': segment(digit, 0, black);  segment(digit, 1, color);  segment(digit, 2, color);  segment(digit, 3, black);  segment(digit, 4, black);  segment(digit, 5, color);  segment(digit, 6, color);
      break;
    case '5': segment(digit, 0, color);  segment(digit, 1, black);  segment(digit, 2, color);  segment(digit, 3, color);  segment(digit, 4, black);  segment(digit, 5, color);  segment(digit, 6, color);
      break;
    case '6': segment(digit, 0, color);  segment(digit, 1, black);  segment(digit, 2, color);  segment(digit, 3, color);  segment(digit, 4, color);  segment(digit, 5, color);  segment(digit, 6, color);
      break;
    case '7': segment(digit, 0, color);  segment(digit, 1, color);  segment(digit, 2, color);  segment(digit, 3, black);  segment(digit, 4, black);  segment(digit, 5, black);  segment(digit, 6, black);
      break;
    case '8': segment(digit, 0, color);  segment(digit, 1, color);  segment(digit, 2, color);  segment(digit, 3, color);  segment(digit, 4, color);  segment(digit, 5, color);  segment(digit, 6, color);
      break;
    case '9': segment(digit, 0, color);  segment(digit, 1, color);  segment(digit, 2, color);  segment(digit, 3, color);  segment(digit, 4, black);  segment(digit, 5, color);  segment(digit, 6, color);
      break;
    case '0': segment(digit, 0, color);  segment(digit, 1, color);  segment(digit, 2, color);  segment(digit, 3, color);  segment(digit, 4, color);  segment(digit, 5, color);  segment(digit, 6, black);
      break;
  }
}

void segment_display::update(){
  strip.show();
}
