#include <stdio.h>
#include <stdint.h>

const uint8_t ledPin = 25;    // LED pin
const uint8_t buttonPin = 14; // Button pin
const int maxIterations = 100;

void setup()
{
    // Set LED pin as an output
    gpio_set_function(ledPin, GPIO_FUNC_SIO);
    gpio_init(ledPin);
    gpio_set_dir(ledPin, GPIO_OUT);

    // Set button pin as an input
    gpio_set_function(buttonPin, GPIO_FUNC_SIO);
    gpio_pull_up(buttonPin);
}

void loop()
{
    for (int i = 0; i < maxIterations; i++)
    {
        if (isButtonPressed(buttonPin))
        {
            toggleLED(ledPin);
        }
    }
}

bool isButtonPressed(uint8_t buttonPin)
{
    return !gpio_get(buttonPin);
}

inline void toggleLED(uint8_t ledPin)
{
    gpio_xor_mask(1 << ledPin);
}
