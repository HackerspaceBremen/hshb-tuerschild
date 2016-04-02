
#include "Adafruit_NeoPixel.h"
#include "rgb.h"
/* #include "TimerOne.h" */
//define the data pin
#define LEDPIN 10
//define number of pixels
#define NUMPIXEL 45
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXEL, LEDPIN, NEO_GRB | NEO_KHZ800);

unsigned int i = 0;
unsigned int j = 0;
static unsigned long msLast = 0;

#define LEDPROBOX 15
#define BOX1START 0
#define BOX2START LEDPROBOX
#define BOX3START LEDPROBOX*2

#define BOX1SCHALTER 8
#define BOX2SCHALTER 7
#define BOX3SCHALTER 4
#define BOX1LED 5
#define BOX2LED 6
#define BOX3LED 9

typedef uint32_t Color;
Color cBlack = 0;
/* Color cWhite = 0x7F7F7F; */
/* Color cWhite = 0x555555; */
Color cWhite = 0x3C3C3C;
/* Color cRed = 0x7F0000; */
/* Color cGreen = 0x7F00; */
/* Color cBlue = 0x7F; */
/* Color cOrange = 0xEE7600; */
/* Color cYellow = 0x7F7F00; */

#define GreenR 0
#define GreenG 127
#define GreenB 0
#define YellowR 127
#define YellowG 127
#define YellowB 0
#define OrangeR 238
#define OrangeG 118
#define OrangeB 0

#define WhiteS 0
#define WhiteV 24

#define GreenH 120
#define GreenS 100
#define GreenV 100
hsv GreenHsv = {GreenH, GreenS/100.0, GreenV/100.0};
#define OrangeH 30
#define OrangeS 100
#define OrangeV 93
hsv OrangeHsv = {OrangeH, OrangeS/100.0, OrangeV/100.0};
#define YellowH 60
#define YellowS 100
#define YellowV 50
hsv YellowHsv = {YellowH, YellowS/100.0, YellowV/100.0};

#define BSTEPS 20

float Brightness[BSTEPS] = {
    0.05,
    0.1, 0.15,
    0.2, 0.25,
    0.3, 0.35,
    0.4, 0.45,
    0.5, 0.55,
    0.6, 0.65,
    0.7, 0.75,
    0.8, 0.85,
    0.9, 0.95,
    1.0
};
float Brightness2[BSTEPS] = {
    1.0, 0.95,
    0.9, 0.85,
    0.8, 0.75,
    0.7, 0.65,
    0.6, 0.55,
    0.5, 0.45,
    0.4, 0.35,
    0.3, 0.25,
    0.2, 0.15,
    0.1, 0.05
};



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

    /* msLast = millis(); */

}

void loop ()
{
    unsigned long ms = millis();
    /* Serial.print(BOX2START); */
    if((ms - msLast) >= Interval)
    {
        j++;
        if(j%BSTEPS == 0)
        {
            i++;
        }
        if(!digitalRead(BOX1SCHALTER))
        {
            /* digitalWrite(BOX1LED, HIGH); */
            analogWrite(BOX1LED, 64);
            LightBox(BOX1START, cWhite);
            hsv GreenHsv1 = GreenHsv;
            GreenHsv1.s = GreenHsv.s - Brightness2[j%BSTEPS]*(GreenS-WhiteS)/100.0;
            GreenHsv1.v = GreenHsv.v - Brightness2[j%BSTEPS]*(GreenV-WhiteV)/100.0;
            rgb GreenRgb1 = hsv2rgb(GreenHsv1);
            strip.setPixelColor(BOX1START+i%LEDPROBOX,GreenRgb1.r*255,GreenRgb1.g*255,GreenRgb1.b*255);
            hsv GreenHsv2 = GreenHsv;
            GreenHsv2.s = GreenHsv.s - Brightness[j%BSTEPS]*(GreenS-WhiteS)/100.0;
            GreenHsv2.v = GreenHsv.v - Brightness[j%BSTEPS]*(GreenV-WhiteV)/100.0;
            rgb GreenRgb2 = hsv2rgb(GreenHsv2);
            strip.setPixelColor(BOX1START+i%LEDPROBOX-1,GreenRgb2.r*255,GreenRgb2.g*255,GreenRgb2.b*255);

        }
        else
        {
            /* digitalWrite(BOX1LED, LOW); */
            analogWrite(BOX1LED, 0);
            LightBox(BOX1START, cBlack);
        }
        if(!digitalRead(BOX2SCHALTER))
        {
            /* digitalWrite(BOX2LED, HIGH); */
            analogWrite(BOX2LED, 64);
            LightBox(BOX2START, cWhite);
            hsv OrangeHsv1 = OrangeHsv;
            OrangeHsv1.s = OrangeHsv.s - Brightness2[j%BSTEPS]*(OrangeS-WhiteS)/100.0;
            OrangeHsv1.v = OrangeHsv.v - Brightness2[j%BSTEPS]*(OrangeV-WhiteV)/100.0;
            rgb OrangeRgb1 = hsv2rgb(OrangeHsv1);
            strip.setPixelColor(BOX2START+LEDPROBOX-1-i%LEDPROBOX,OrangeRgb1.r*255,OrangeRgb1.g*255,OrangeRgb1.b*255);
            hsv OrangeHsv2 = OrangeHsv;
            OrangeHsv2.s = OrangeHsv.s - Brightness[j%BSTEPS]*(OrangeS-WhiteS)/100.0;
            OrangeHsv2.v = OrangeHsv.v - Brightness[j%BSTEPS]*(OrangeV-WhiteV)/100.0;
            rgb OrangeRgb2 = hsv2rgb(OrangeHsv2);
            strip.setPixelColor(BOX2START+LEDPROBOX-1-i%LEDPROBOX+1,OrangeRgb2.r*255,OrangeRgb2.g*255,OrangeRgb2.b*255);
        }
        else
        {
            /* digitalWrite(BOX2LED, LOW); */
            analogWrite(BOX2LED, 0);
            LightBox(BOX2START, cBlack);
        }
        if(!digitalRead(BOX3SCHALTER))
        {
            /* digitalWrite(BOX3LED, HIGH); */
            analogWrite(BOX3LED, 64);
            LightBox(BOX3START, cWhite);
            /* strip.setPixelColor(BOX3START+i%LEDPROBOX,strip.Color(YellowR, YellowG, YellowB)); */
            hsv YellowHsv1 = YellowHsv;
            YellowHsv1.s = YellowHsv.s - Brightness2[j%BSTEPS]*(YellowS-WhiteS)/100.0;
            YellowHsv1.v = YellowHsv.v - Brightness2[j%BSTEPS]*(YellowV-WhiteV)/100.0;
            rgb YellowRgb1 = hsv2rgb(YellowHsv1);
            strip.setPixelColor(BOX3START+i%LEDPROBOX,YellowRgb1.r*255,YellowRgb1.g*255,YellowRgb1.b*255);
            hsv YellowHsv2 = YellowHsv;
            YellowHsv2.s = YellowHsv.s - Brightness[j%BSTEPS]*(YellowS-WhiteS)/100.0;
            YellowHsv2.v = YellowHsv.v - Brightness[j%BSTEPS]*(YellowV-WhiteV)/100.0;
            rgb YellowRgb2 = hsv2rgb(YellowHsv2);
            strip.setPixelColor(BOX3START+i%LEDPROBOX-1,YellowRgb2.r*255,YellowRgb2.g*255,YellowRgb2.b*255);
        }
        else
        {
            /* digitalWrite(BOX3LED, LOW); */
            analogWrite(BOX3LED, 0);
            LightBox(BOX3START, cBlack);
        }
        msLast = millis();
    }
    strip.show();
}

void LightBox(int start, uint32_t col)
{
    for(int i = start; i < start + LEDPROBOX; i++)
    {
        strip.setPixelColor(i, col);
    }
}





