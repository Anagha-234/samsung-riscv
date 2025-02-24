#include "ch32v00x.h"
#include "debug.h"   // For UART communication

#define BTN_PIN  GPIO_Pin_2  // Button connected to GPIOA Pin 2

void Delay_ms(uint32_t ms) {
    for(uint32_t i = 0; i < ms * 800; i++);  // Approximate delay
}

int main() {
    SystemInit();    // Initialize system
    USART_Printf_Init(115200);  // Initialize UART with baud rate 115200

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // Enable GPIOA clock

    // Configure Button Pin as Input Pull-Up (active low)
    GPIO_InitStructure.GPIO_Pin = BTN_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  // Internal pull-up
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    printf("System Initialized. Waiting for button presses...\n");

    uint32_t button_count = 0;
    uint8_t prev_state = 1;  // Assume button is not pressed initially

    while (1) {
        uint8_t curr_state = GPIO_ReadInputDataBit(GPIOA, BTN_PIN);

        if (curr_state == 0 && prev_state == 1) {  // Detect button press (Active Low)
            button_count++;
            printf("Button pressed %lu times!\n", button_count);
            Delay_ms(200);  // Debounce delay
        }

        prev_state = curr_state;
    }
}
