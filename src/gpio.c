#include "gpio.h"


void GPIO_SetPin(uint8_t port, uint8_t pin, uint8_t mode)
{

switch(port){

    case GPIO_PORT_B:
    if(mode == GPIO_OUTPUT){
        DDRB |= (1 << pin);
    } else {
        DDRB &= ~(1 <<pin);

    }
    break;
    case GPIO_PORT_C:
    if(mode == GPIO_OUTPUT){
        DDRC |= (1 << pin);
    } else {
        DDRC &= ~(1 <<pin);

    }
    break;

    case GPIO_PORT_D:
    if(mode == GPIO_OUTPUT){
        DDRD |= (1 << pin);
    } else {
        DDRD &= ~(1 <<pin);

    }
    break;
}

}
void GPIO_WritePin(uint8_t port, uint8_t pin, uint8_t value)
{
    switch(port){
  case GPIO_PORT_B:
    if(value == GPIO_HIGH){
        PORTB |= (1 << pin);
    } else {
        PORTB &= ~(1 <<pin);

    }
    break;
    case GPIO_PORT_C:
    if(value == GPIO_HIGH){
        PORTC |= (1 << pin);
    } else {
        PORTC &= ~(1 <<pin);

    }
    break;

    case GPIO_PORT_D:
    if(value == GPIO_HIGH){
        PORTD |= (1 << pin);
    } else {
        PORTD &= ~(1 <<pin);

    }
    break;

    default:
    break;
}
}
void GPIO_TogglePin(uint8_t port, uint8_t pin)
{
switch(port){
  case GPIO_PORT_B:
    PORTB ^= (1 << pin);
    break;

    case GPIO_PORT_C:
    PORTC ^= (1 << pin);
    break;

    case GPIO_PORT_D:
    PORTD ^= (1 << pin);
    break;

    default:
    break;



}

}
void GPIO_ReadPin(uint8_t port, uint8_t pin)
{
   



}