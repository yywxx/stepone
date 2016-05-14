#ifndef __DELAY_H__
#define __DELAY_H__

/* The Systick register only have 24bit, so, the max delay is 2.769 seconds */
void delay_init(unsigned int SYSCLK);
void delay_ms(unsigned int nms);
void delay_us(unsigned int nus);
void delay_s(unsigned int t);

#endif /* __DELAY_H__ */
