
#include "pico/stdlib.h"

// Motor izquierdo
#define IN1 2
#define IN2 3

// Motor derecho
#define IN3 6
#define IN4 7

int main(void) {

    // Inicializar los cuatro GPIO
    gpio_init(IN1);
    gpio_set_dir(IN1, GPIO_OUT);

    gpio_init(IN2);
    gpio_set_dir(IN2, GPIO_OUT);

    gpio_init(IN3);
    gpio_set_dir(IN3, GPIO_OUT);

    gpio_init(IN4);
    gpio_set_dir(IN4, GPIO_OUT);

    while (true) {

        // Ambos motores en un sentido
        gpio_put(IN1, 1);
        gpio_put(IN2, 0);

        gpio_put(IN3, 1);
        gpio_put(IN4, 0);

        sleep_ms(2000);

        // Detener ambos motores
        gpio_put(IN1, 0);
        gpio_put(IN2, 0);

        gpio_put(IN3, 0);
        gpio_put(IN4, 0);

        sleep_ms(1000);

        // Ambos motores en sentido contrario
        gpio_put(IN1, 0);
        gpio_put(IN2, 1);

        gpio_put(IN3, 0);
        gpio_put(IN4, 1);

        sleep_ms(2000);

        // Detener ambos motores
        gpio_put(IN1, 0);
        gpio_put(IN2, 0);

        gpio_put(IN3, 0);
        gpio_put(IN4, 0);

        sleep_ms(1000);
    }

    return 0;
}
