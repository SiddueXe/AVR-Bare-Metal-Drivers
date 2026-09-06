#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <stdint.h>


#define GPIO_PORT_B 0
#define GPIO_PORT_C 1
#define GPIO_PORT_D 2

#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_2 2
#define GPIO_PIN_3 3
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7



#define GPIO_HIGH 1
#define GPIO_LOW 0

#define GPIO_INPUT 0
#define GPIO_OUTPUT  1   

void GPIO_SetPin(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_WritePin(uint8_t port, uint8_t pin, uint8_t value);
void GPIO_TogglePin(uint8_t port, uint8_t pin);
void GPIO_ReadPin(uint8_t port, uint8_t pin);
#endif