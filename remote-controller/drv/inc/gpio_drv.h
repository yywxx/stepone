#ifndef __GPIO_DRV_H__
#define __GPIO_DRV_H__

#include "stm32f0xx_gpio.h"

enum gpio_status {
	HIGH,
	LOW,
};

typedef struct {
	unsigned int RCC_AHBPeriph;					// Such as RCC_AHBPeriph_GPIOC
	GPIO_TypeDef* port;									// Such as GPIOC
	GPIO_InitTypeDef attr;
	enum gpio_status default_status;		// HIGH or LOW
} gpio_t;

void gpio_init(gpio_t *dev);
void gpio_high(gpio_t *dev);
void gpio_low(gpio_t *dev);
enum gpio_status get_gpio_status(gpio_t *dev);

#endif /* __GPIO_DRV_H__ */
