#include "stm32f0xx.h"

#include "delay.h"
#include "led_c13.h"

int main(void)
{
	delay_init(48);
	gpio_init(&led_c13);
	
	while (1) {
		LED_C13_OFF();
		delay_s(1);
		LED_C13_ON();
		delay_ms(10);
	}
	
	return 0;
}
