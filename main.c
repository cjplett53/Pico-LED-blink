#include <stdint.h>
#include "hardware.h"
#include "morse.h"
#include "led.h"

int main() {

    // Wait for IO bank reset to finish
    while (!(RESETS_RESET_DONE & (1 << 5)));

    // Set GPIO18 function to SIO
    GPIO_CTRL(LED_PIN) = 5;

    // Enable output
    SIO_GPIO_OE_SET = 1 << LED_PIN;

    while (1) {
        // Send message
        send_morse_string("hello world");
    }
}