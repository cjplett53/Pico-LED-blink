#include <stdint.h>

#define RESETS_BASE     0x4000c000
#define IO_BANK0_BASE   0x40014000
#define SIO_BASE        0xd0000000

#define RESETS_RESET_DONE (*(volatile uint32_t *)(RESETS_BASE + 0x8))

#define GPIO_CTRL(n) (*(volatile uint32_t *)(IO_BANK0_BASE + 0x4 + (n)*8))

#define SIO_GPIO_OUT_SET (*(volatile uint32_t *)(SIO_BASE + 0x14))
#define SIO_GPIO_OUT_CLR (*(volatile uint32_t *)(SIO_BASE + 0x18))
#define SIO_GPIO_OE_SET  (*(volatile uint32_t *)(SIO_BASE + 0x24))

#define LED_PIN 18

void dot() {
    for (volatile int i = 0; i < 1850000; i++);
}

int main() {

    // Wait for IO bank reset to finish
    while (!(RESETS_RESET_DONE & (1 << 5)));

    // Set GPIO18 function to SIO
    GPIO_CTRL(LED_PIN) = 5;

    // Enable output
    SIO_GPIO_OE_SET = 1 << LED_PIN;

    while (1) {
        SIO_GPIO_OUT_SET = 1 << LED_PIN;
        dot();

        SIO_GPIO_OUT_CLR = 1 << LED_PIN;
        dot();
    }
}