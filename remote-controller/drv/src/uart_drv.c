#include "uart_drv.h"

void uart_init(uart_t * uart, int baudrate)
{
	/****** Enable Clocks ******/
	RCC_AHBPeriphClockCmd(uart->uart_tx_bus | uart->uart_rx_bus, ENABLE);
	if (uart->uart_port == USART1) {
		RCC_APB2PeriphClockCmd(uart->uart_bus, ENABLE);
	} else {
		RCC_APB1PeriphClockCmd(uart->uart_bus, ENABLE);
	}
	
	/* Init IO Pin */
	GPIO_Init(uart->uart_rx_io_port, &(uart->uart_rx_pin));
	GPIO_Init(uart->uart_tx_io_port, &(uart->uart_tx_pin));
	
	/* Init IO Source */
	GPIO_PinAFConfig(uart->uart_rx_io_port, uart->uart_rx_source, uart->uart_rx_af_no);
	GPIO_PinAFConfig(uart->uart_tx_io_port, uart->uart_tx_source, uart->uart_tx_af_no);

	/******* Init UART parameter ******/
	uart->uart_mode.USART_BaudRate = baudrate;
	USART_Init(uart->uart_port, &(uart->uart_mode));

	/******* Init UART Receive IRQ *******/
	NVIC_Init(&(uart->nvic_mode));
	USART_ITConfig(uart->uart_port, USART_IT_RXNE, ENABLE);
	
	/* Start UART */
	USART_Cmd(uart->uart_port, ENABLE);
}

static int _send_char_to_uart(uart_t * uart, unsigned char ch)
{
	volatile unsigned int time_out = 0xffffff;
	
	USART_SendData(uart->uart_port, ch);
	while (USART_GetFlagStatus(uart->uart_port, USART_FLAG_TC) != SET) {
		if (!(time_out--)) {
			return -1;
		}
	}
	
	return 0;
}

int uart_puts(uart_t * uart, const unsigned char *dat, unsigned int len)
{
	int ret;
	unsigned int i;
	
	for (i = 0; i < len; i++) {
		ret = _send_char_to_uart(uart, dat[i]);
		if (ret == -1) {
			return i;
		}
	}
	
	return len;
}

unsigned int uart_getch(uart_t * uart)
{
	if (USART_GetITStatus(uart->uart_port, USART_IT_RXNE)) {
		USART_ClearITPendingBit(uart->uart_port, USART_IT_RXNE);
		
		return USART_ReceiveData(uart->uart_port);
	} else {
		USART_ReceiveData(uart->uart_port);
		return 0xffffffff;
	}
}

