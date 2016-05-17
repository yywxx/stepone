#include "uarts.h"

uart_t uart_1 = {
	.uart_tx_pin.GPIO_Pin = GPIO_Pin_6,
	.uart_tx_pin.GPIO_Mode = GPIO_Mode_AF,
	.uart_tx_pin.GPIO_OType = GPIO_OType_PP,
	.uart_tx_pin.GPIO_Speed = GPIO_Speed_50MHz,
	.uart_tx_pin.GPIO_PuPd = GPIO_PuPd_UP,
	.uart_tx_io_port = GPIOB,
	.uart_tx_bus = RCC_AHBPeriph_GPIOB,
	.uart_tx_source = GPIO_PinSource6,
	.uart_tx_af_no = GPIO_AF_0,
	
	.uart_rx_pin.GPIO_Pin = GPIO_Pin_7,
	.uart_rx_pin.GPIO_Mode = GPIO_Mode_AF,
	.uart_rx_pin.GPIO_OType = GPIO_OType_OD,
	.uart_rx_pin.GPIO_Speed = GPIO_Speed_50MHz,
	.uart_rx_pin.GPIO_PuPd = GPIO_PuPd_NOPULL,
	.uart_rx_io_port = GPIOB,
	.uart_rx_bus = RCC_AHBPeriph_GPIOB,
	.uart_rx_source = GPIO_PinSource7,
	.uart_rx_af_no = GPIO_AF_0,
	
	.uart_bus = RCC_APB2Periph_USART1,
	
	.uart_mode.USART_HardwareFlowControl = USART_HardwareFlowControl_None,
	.uart_mode.USART_Mode = USART_Mode_Rx | USART_Mode_Tx,
	.uart_mode.USART_Parity = USART_Parity_No,
	.uart_mode.USART_StopBits = USART_StopBits_1,
	.uart_mode.USART_WordLength = USART_WordLength_8b,
	
	.uart_port = USART1,
	
	.nvic_mode.NVIC_IRQChannel = USART1_IRQn,
	.nvic_mode.NVIC_IRQChannelCmd = ENABLE,
	.nvic_mode.NVIC_IRQChannelPriority = 0,
};

uart_t uart_2 = {
	.uart_tx_pin.GPIO_Pin = GPIO_Pin_2,
	.uart_tx_pin.GPIO_Mode = GPIO_Mode_AF,
	.uart_tx_pin.GPIO_OType = GPIO_OType_PP,
	.uart_tx_pin.GPIO_Speed = GPIO_Speed_50MHz,
	.uart_tx_pin.GPIO_PuPd = GPIO_PuPd_UP,
	.uart_tx_io_port = GPIOA,
	.uart_tx_bus = RCC_AHBPeriph_GPIOA,
	
	.uart_rx_pin.GPIO_Pin = GPIO_Pin_3,
	.uart_rx_pin.GPIO_Mode = GPIO_Mode_AF,
	.uart_rx_pin.GPIO_OType = GPIO_OType_OD,
	.uart_rx_pin.GPIO_Speed = GPIO_Speed_50MHz,
	.uart_rx_pin.GPIO_PuPd = GPIO_PuPd_NOPULL,
	.uart_rx_io_port = GPIOA,
	.uart_rx_bus = RCC_AHBPeriph_GPIOA,
	
	.uart_bus = RCC_APB1Periph_USART2,
	
	.uart_mode.USART_HardwareFlowControl = USART_HardwareFlowControl_None,
	.uart_mode.USART_Mode = USART_Mode_Rx | USART_Mode_Tx,
	.uart_mode.USART_Parity = USART_Parity_No,
	.uart_mode.USART_StopBits = USART_StopBits_1,
	.uart_mode.USART_WordLength = USART_WordLength_8b,
	
	.uart_port = USART2,
	
	.nvic_mode.NVIC_IRQChannel = USART2_IRQn,
	.nvic_mode.NVIC_IRQChannelCmd = ENABLE,
	.nvic_mode.NVIC_IRQChannelPriority = 0,
};

void USART1_IRQHandler(void)
{
	USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	USART_ReceiveData(USART1);
}

