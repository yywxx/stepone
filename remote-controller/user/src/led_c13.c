#include "led_c13.h"

struct gpio_dev led_c13 = {
	.RCC_AHBPeriph = RCC_AHBPeriph_GPIOC,
	
	.port = GPIOC,
	
	.attr.GPIO_Pin = GPIO_Pin_13,
	.attr.GPIO_Mode = GPIO_Mode_OUT,
	.attr.GPIO_OType = GPIO_OType_PP,
	.attr.GPIO_Speed = GPIO_Speed_50MHz,
	.attr.GPIO_PuPd = GPIO_PuPd_NOPULL,
	
	.default_status = HIGH,
};

