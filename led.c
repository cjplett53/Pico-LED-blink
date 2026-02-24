#include "hardware.h"
#include "led.h"

// Timing functions
static void delay_units(int units) {
    for(volatile int i = 0; i<units*1850000; i++);
}

// LED functions
void led_dot() {
    SIO_GPIO_OUT_SET = 1 << LED_PIN;
    delay_units(DOT_UNITS);
    SIO_GPIO_OUT_CLR = 1 << LED_PIN;
    delay_units(SYMBOL_GAP_UNITS);
}
void led_dash() {
    SIO_GPIO_OUT_SET = 1 << LED_PIN;
    delay_units(DASH_UNITS);
    SIO_GPIO_OUT_CLR = 1 << LED_PIN;
    delay_units(SYMBOL_GAP_UNITS);
}
void led_letter_gap() {
    delay_units(LETTER_GAP_UNITS - SYMBOL_GAP_UNITS);
}
void led_word_gap() {
    delay_units(WORD_GAP_UNITS - SYMBOL_GAP_UNITS);
}