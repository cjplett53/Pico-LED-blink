#include "led.h"
#include "morse.h"

// Lookup table indexed by ASCII code
static const char *morse_table[128] = {
    ['A'] = ".-",
    ['B'] = "-...",
    ['C'] = "-.-.",
    ['D'] = "-..",
    ['E'] = ".",
    ['F'] = "..-.",
    ['G'] = "--.",
    ['H'] = "....",
    ['I'] = "..",
    ['J'] = ".---",
    ['K'] = "-.-",
    ['L'] = ".-..",
    ['M'] = "--",
    ['N'] = "-.",
    ['O'] = "---",
    ['P'] = ".--.",
    ['Q'] = "--.-",
    ['R'] = ".-.",
    ['S'] = "...",
    ['T'] = "-",
    ['U'] = "..-",
    ['V'] = "...-",
    ['W'] = ".--",
    ['X'] = "-..-",
    ['Y'] = "-.--",
    ['Z'] = "--..",

    [' '] = " " 
};

// Send string and char functions
static void send_morse_char(char c) {
    const char *pattern = morse_table[(unsigned char)c];
    if(!pattern) return;
    if(c==' ') {
        led_word_gap();
        return;
    }
    for(int i=0; pattern[i] != '\0'; ++i) {
        if (pattern[i] == '.') led_dot();
        else if (pattern[i] == '-') led_dash();
    }
    led_letter_gap();
}
void send_morse_string(const char * str) {
    for(int i=0; str[i] != '\0'; i++) {
        char c = str[i];
        c = (c >= 'a' && c <= 'z') ? (c - 32) : c;
        send_morse_char(c);
    }
    for(int i=0; i<2; ++i) led_word_gap();
}