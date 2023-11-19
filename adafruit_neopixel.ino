#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_PIXELS 16

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
    colorWipe(strip.Color(255, 0, 0), 50); // Red
    delay(500);
    colorWipe(strip.Color(0, 255, 0), 50); // Green
    delay(500);
    colorWipe(strip.Color(0, 0, 255), 50); // Blue
    delay(500);
}

void colorWipe(uint32_t color, int wait)
{
    for (int i = 0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
    }
}
