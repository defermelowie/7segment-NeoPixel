#include <segment_display.h>

#define NUMDIGITS 1 // How manny digits do you have
#define PIN 5 // Witch pin is used

// Make an segment_display object
segment_display D = segment_display(NUMDIGITS, PIN); // or segment_display D(NUMDIGITS, PIN);

// Make your own color(optional)
uint32_t myColor = D.color(0, 0, 100);

int delaytime = 1000;

void setup() {
  D.begin(); // This initializes the segment_display library.
}

void loop() {
  D.write("0", myColor);
  delay(delaytime);
  D.write("1", myColor);
  delay(delaytime);
  D.write("2", myColor);
  delay(delaytime);
  D.write("3", myColor);
  delay(delaytime);
  D.write("4", myColor);
  delay(delaytime);
  D.write("5", myColor);
  delay(delaytime);
  D.write("6", myColor);
  delay(delaytime);
  D.write("7", myColor);
  delay(delaytime);
  D.write("8", myColor);
  delay(delaytime);
  D.write("9", myColor);
  delay(delaytime);
}
