#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class segment_display
{
  public:
  
    Adafruit_NeoPixel strip;
    uint32_t black;
    uint32_t red;
    uint32_t green;
    uint32_t blue;
    uint32_t yellow;
    
    segment_display(int digits, int pin);

    void begin();
  
    void write(String message, uint32_t color);
    
    uint32_t color(byte r, byte g, byte b);
  
  private:
  
    int size;
    //The first digit is 0, the first seg is 0, (.setPixelColor(0, color) lets the first led shine)
    void segment(int digit, int seg, uint32_t color);

    //The first digit is 0
    void digit(int digit, char i, uint32_t color);
    
    void update();
};
