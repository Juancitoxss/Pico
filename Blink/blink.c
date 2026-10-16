
#include "pico/stdlib.h"

#define LED 16
#define BOTON 14

int main(void) {

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_init(BOTON);
    gpio_set_dir(BOTON, GPIO_IN);
    gpio_pull_down(BOTON);

    bool estado_led = false;
    gpio_put(LED, 0);

    while (true) {

        if (gpio_get(BOTON) == 1) {

            sleep_ms(20);

            if (gpio_get(BOTON) == 1) {

                estado_led = !estado_led;
                gpio_put(LED, estado_led);

                while (gpio_get(BOTON) == 1) {
                    sleep_ms(1);
                }

                sleep_ms(20);
            }
        }
    }

    return 0;
}
