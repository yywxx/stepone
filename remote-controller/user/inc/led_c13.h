#ifndef __LED_C13_H__
#define __LED_C13_H__

#include "gpio_drv.h"

#define LED_C13_ON()  gpio_low(&led_c13)
#define LED_C13_OFF() gpio_high(&led_c13)

extern struct gpio_dev led_c13;

#endif /* __LED_C13_H__ */
