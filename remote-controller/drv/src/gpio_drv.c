#include "gpio_drv.h"

void gpio_init(struct gpio_dev *dev)
{
	/* GPIOC Periph clock enable */
  RCC_AHBPeriphClockCmd(dev->RCC_AHBPeriph, ENABLE);
	
	/* Configure PC10 and PC11 in output pushpull mode */
  GPIO_Init(dev->port, &dev->attr);
	
	/* Set GPIO default status */
	GPIO_WriteBit(dev->port, dev->attr.GPIO_Pin, (BitAction)dev->default_status);
}

void gpio_high(struct gpio_dev *dev)
{
	GPIO_SetBits(dev->port, dev->attr.GPIO_Pin);
}

void gpio_low(struct gpio_dev *dev)
{
	GPIO_ResetBits(dev->port, dev->attr.GPIO_Pin);
}

enum gpio_status get_gpio_status(struct gpio_dev *dev)
{
	if (dev->attr.GPIO_Mode == GPIO_Mode_IN) 
		return (enum gpio_status)GPIO_ReadInputDataBit(dev->port, dev->attr.GPIO_Pin);
	else
		return (enum gpio_status)GPIO_ReadOutputDataBit(dev->port, dev->attr.GPIO_Pin);
}
