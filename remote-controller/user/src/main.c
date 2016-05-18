#include "stm32f0xx.h"

#include "delay.h"
#include "leds.h"
#include "uarts.h"

int main(void)
{
	delay_init(48);
	gpio_init(&led_c13);
	uart_init(&uart_1, 115200);   
	
	while (1) {
		uart_puts(&uart_1, (const unsigned char *)"Hello", 5);
		LED_C13_OFF();
		delay_s(1);
		LED_C13_ON();
		delay_ms(10);
	}
	
	return 0;
}
