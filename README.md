Projeto de Semáforo com Raspberry Pi Pico

Descrição
Este projeto simula o funcionamento de um semáforo utilizando o Raspberry Pi Pico com 3 LEDs (vermelho, amarelo e verde), controlados por um temporizador. A cada 3 segundos, o semáforo alterna entre os LEDs, representando a sequência de "PARE" (vermelho), "ATENÇÃO" (amarelo) e "SIGA" (verde). O estado do semáforo é controlado por um temporizador repetido, e a cada segundo, uma mensagem correspondente é impressa no terminal serial.


Este código foi desenvolvido para simulação no ambiente Wokwi, utilizando o Raspberry Pi Pico, com LEDs conectados aos pinos GPIO 11, 12 e 13.

Requisitos
Hardware:\
Raspberry Pi Pico (ou similar)

3 LEDs (vermelho, amarelo e verde)

3 resistores de 330 Ω

Fios de conexão

Software:

Wokwi para simulação do Raspberry Pi Pico e LEDs

VSCode com a extensão de C/C++ para desenvolvimento e compilação do código

Funcionalidades

Mudança de Estado do Semáforo: A cada 3 segundos, o semáforo alterna entre as cores:

Vermelho: "PARE"

Amarelo: "ATENÇÃO"

Verde: "SIGA"


Impressão no Terminal Serial: A cada segundo, o código imprime no terminal serial a mensagem correspondente ao estado atual do semáforo.

Diagrama de Conexões

O código utiliza 3 LEDs conectados aos pinos GPIO 11 (vermelho), GPIO 12 (amarelo) e GPIO 13 (verde).

A comunicação serial é realizada utilizando a UART padrão do Raspberry Pi Pico, que é configurada automaticamente com a função stdio_init_all().

