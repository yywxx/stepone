#ifndef __GPIO_DRV_H__
#define __GPIO_DRV_H__

#include "stm32f0xx_gpio.h"

enum gpio_status {
	HIGH,
	LOW,
};

struct gpio_dev {
	unsigned int RCC_AHBPeriph;					// Such as RCC_AHBPeriph_GPIOC
	GPIO_TypeDef* port;									// Such as GPIOC
	GPIO_InitTypeDef attr;
	enum gpio_status default_status;		// HIGH or LOW
};

void gpio_init(struct gpio_dev *dev);
void gpio_high(struct gpio_dev *dev);
void gpio_low(struct gpio_dev *dev);
enum gpio_status get_gpio_status(struct gpio_dev *dev);

#endif /* __GPIO_DRV_H__ */
