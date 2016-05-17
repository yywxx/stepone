#ifndef __UART_DRV_H__
#define __UART_DRV_H__

#include "stm32f0xx.h"

typedef struct {
	GPIO_InitTypeDef uart_tx_pin;
	GPIO_TypeDef *uart_tx_io_port;
	unsigned int uart_tx_bus;
	unsigned char uart_tx_source;
	unsigned char uart_tx_af_no;
	GPIO_InitTypeDef uart_rx_pin;
	GPIO_TypeDef *uart_rx_io_port;
	unsigned int uart_rx_bus;
	unsigned char uart_rx_source;
	unsigned char uart_rx_af_no;
	
	unsigned int uart_bus;
	
	USART_InitTypeDef uart_mode;
	USART_TypeDef *uart_port;
	NVIC_InitTypeDef nvic_mode;
} uart_t;

extern void uart_init(uart_t * uart, int baudrate);
extern int uart_puts(uart_t * uart, const unsigned char *dat, unsigned int len);
extern unsigned int uart_getch(uart_t * uart);  // Not interrupt mode, it's poll.

#endif /* __UART_H__ */
