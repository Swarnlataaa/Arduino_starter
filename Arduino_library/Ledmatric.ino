#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

void setup()
{
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}

void loop()
{
    for (int row = 0; row < 8; row++)
    {
        lc.setRow(0, row, B11111111);
        delay(100);
        lc.setRow(0, row, 0);
    }
}
