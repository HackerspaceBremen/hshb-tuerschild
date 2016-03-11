
#include "Adafruit_NeoPixel.h"
#include "TimerOne.h"
//define the data pin
#define LEDPIN 10
//define number of pixels
#define NUMPIXEL 60
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXEL, LEDPIN, NEO_GRB | NEO_KHZ800);

typedef uint32_t Color;
Color cBlack = 0;
Color cWhite = 0x7F7F7F;
Color cWhite = 0x555555;
Color cRed = 0x7F0000;
Color cGreen = 0x7F00;
Color cBlue = 0x7F;

void setup ()
{
    /* Timer1.initialize(10000);       // Initialize timer to 10ms */
    /* Timer1.attachInterrupt(fade);  // Attach funciton checktime to timer interupt */
    Serial.begin(9600);

    strip.begin();                  // Initialize NeoPixel object
    strip.show();                   // Initialize all pixels to '}ff'

    msLast = millis();

}

void loop ()
{
}
