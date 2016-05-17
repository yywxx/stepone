#ifndef __LEDS_H__
#define __LEDS_H__

#include "gpio_drv.h"

#define LED_C13_ON()  gpio_low(&led_c13)
#define LED_C13_OFF() gpio_high(&led_c13)

extern gpio_t led_c13;

#endif /* __LEDS_H__ */
