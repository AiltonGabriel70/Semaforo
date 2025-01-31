#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <stdio.h>  // Necessário para printf

// Definição dos pinos para os LEDs
#define LED_VERMELHO_PIN 11
#define LED_AMARELO_PIN 12
#define LED_VERDE_PIN 13

// Definição de estados do semáforo
typedef enum {
    VERMELHO,
    AMARELO,
    VERDE
} estado_semaforo_t;

estado_semaforo_t estado_atual = VERMELHO; // Começamos com o semáforo vermelho

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Troca o estado do semáforo a cada 3 segundos
    switch (estado_atual) {
        case VERMELHO:
            estado_atual = AMARELO;
            gpio_put(LED_VERMELHO_PIN, 0);  // Desliga o vermelho
            gpio_put(LED_AMARELO_PIN, 1);   // Liga o amarelo
            break;
        case AMARELO:
            estado_atual = VERDE;
            gpio_put(LED_AMARELO_PIN, 0);   // Desliga o amarelo
            gpio_put(LED_VERDE_PIN, 1);     // Liga o verde
            break;
        case VERDE:
            estado_atual = VERMELHO;
            gpio_put(LED_VERDE_PIN, 0);     // Desliga o verde
            gpio_put(LED_VERMELHO_PIN, 1);  // Liga o vermelho
            break;
    }

    return true;  // Retorna true para que o temporizador continue repetindo
}

int main() {
    // Inicialização dos pinos dos LEDs
    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);
    gpio_init(LED_AMARELO_PIN);
    gpio_set_dir(LED_AMARELO_PIN, GPIO_OUT);
    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);

    // Inicializa a comunicação serial
    stdio_init_all();  // Inicializa a UART para a comunicação serial

    // Aguarda 2 segundos para estabilizar a comunicação serial
    sleep_ms(2000);

    // Inicia com o semáforo no vermelho, então acende o LED vermelho e apaga os outros
    gpio_put(LED_VERMELHO_PIN, 1);  // Liga o LED vermelho
    gpio_put(LED_AMARELO_PIN, 0);   // Desliga o LED amarelo
    gpio_put(LED_VERDE_PIN, 0);     // Desliga o LED verde

    // Inicializa o temporizador com um atraso de 3 segundos (3000 ms)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        // Aguarda 1 segundo e imprime a mensagem correspondente ao estado
        sleep_ms(1000);

        // Imprime a mensagem de acordo com o estado do semáforo
        switch (estado_atual) {
            case VERMELHO:
                printf("PARE\n");  // Mensagem para o semáforo vermelho
                break;
            case AMARELO:
                printf("ATENÇÃO\n");  // Mensagem para o semáforo amarelo
                break;
            case VERDE:
                printf("SIGA\n");  // Mensagem para o semáforo verde
                break;
        }
    }

    return 0;
}
