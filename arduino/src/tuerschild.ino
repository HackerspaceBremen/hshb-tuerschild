
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

unsigned int i = 0;
static unsigned long msLast = 0;

#define LEDPROBOX 20
#define BOX1START 0
#define BOX2START LEDPROBOX
#define BOX3START LEDPROBOX*2

#define BOX1SCHALTER 4
#define BOX2SCHALTER 5
#define BOX3SCHALTER 6
#define BOX1LED 7
#define BOX2LED 8
#define BOX3LED 9

typedef uint32_t Color;
Color cBlack = 0;
Color cWhite = 0x7F7F7F;
/* Color cWhite = 0x555555; */
Color cRed = 0x7F0000;
Color cGreen = 0x7F00;
Color cBlue = 0x7F;

float Brightness_1_1 = 0.0;
float Brightness_1_2 = 0.0;
float Brightness_2_1 = 0.0;
float Brightness_2_2 = 0.0;
float Brightness_3_1 = 0.0;
float Brightness_3_2 = 0.0;

unsigned long Interval = 20; //Interval für Lauflicht in ms

void setup ()
{
    /* Timer1.initialize(10000);       // Initialize timer to 10ms */
    /* Timer1.attachInterrupt(fade);  // Attach funciton checktime to timer interupt */
    Serial.begin(9600);

    pinMode(BOX1SCHALTER, INPUT_PULLUP);
    pinMode(BOX2SCHALTER, INPUT_PULLUP);
    pinMode(BOX3SCHALTER, INPUT_PULLUP);
    pinMode(BOX1LED, OUTPUT);
    pinMode(BOX2LED, OUTPUT);
    pinMode(BOX3LED, OUTPUT);

    strip.begin();                  // Initialize NeoPixel object
    strip.show();                   // Initialize all pixels to '}ff'

    msLast = millis();

}

void loop ()
{
    unsigned long ms = millis();
    if( (ms - msLast) >= Interval)
    {
        if(digitalRead(BOX1SCHALTER))
        {
            digitalWrite(BOX1LED, HIGH);
            LightBox(BOX1START, cWhite);
        }
        else
        {
            digitalWrite(BOX1LED, LOW);
            LightBox(BOX1START, cBlack);
        }
        if(digitalRead(BOX2SCHALTER))
        {
            digitalWrite(BOX2LED, HIGH);
            LightBox(BOX2START, cWhite);
        }
        else
        {
            digitalWrite(BOX2LED, LOW);
            LightBox(BOX2START, cBlack);
        }
        if(digitalRead(BOX3SCHALTER))
        {
            digitalWrite(BOX3LED, HIGH);
            LightBox(BOX3START, cWhite);
        }
        else
        {
            digitalWrite(BOX3LED, LOW);
            LightBox(BOX3START, cBlack);
        }
    }
    strip.show();
    msLast = millis();
}

void LightBox(int start, uint32_t col)
{
    for(int i = start; i < LEDPROBOX; i++)
    {
        strip.setPixelColor(i, col);
    }
}





