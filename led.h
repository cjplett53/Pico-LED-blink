#ifndef LED_H
#define LED_H

#define LED_PIN 18

#define DOT_UNITS           1
#define DASH_UNITS          3
#define SYMBOL_GAP_UNITS    1
#define LETTER_GAP_UNITS    3
#define WORD_GAP_UNITS      7

void led_dot();
void led_dash();
void led_letter_gap();
void led_word_gap();

#endif