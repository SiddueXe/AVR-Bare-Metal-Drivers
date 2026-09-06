#include "gpio.h"
#include"uart.h"
#include<util/delay.h>
int main(void)
{
    GPIO_SetPin(GPIO_PORT_B, GPIO_PIN_5, GPIO_OUTPUT);

    // GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_5, GPIO_HIGH);  LED ON
    //GPIO_WritePin(GPIO_PORT_B, GPIO_PIN_5, GPIO_LOW);      // LED OFF

    UART_Init(9600);
    
while(1){
UART_SendString("SIDDU\n");
_delay_ms(1000);

}

}