#include "stm32f0xx.h"
#include "delay.h"

static unsigned int fac_us = 0;
static unsigned int fac_ms = 0;

/************* Initialize delay **************
 * SYSTICK is fix rate: HCLK/8
 *********************************************/
void delay_init(unsigned int SYSCLK)
{
	SysTick->CTRL &= 0xfffffffb;//Clear bit2, select the external clock = HCLK/8
	fac_us = SYSCLK / 8;		    
	fac_ms = (unsigned int)fac_us * 1000;
}	

void delay_ms(unsigned int nms)
{	 		  	  
	unsigned int temp;		   
	
	SysTick->LOAD = (unsigned int)nms * fac_ms;
	SysTick->VAL = 0x00;
	SysTick->CTRL = 0x01 ;
	
	do {
		temp = SysTick->CTRL;
	} while ((temp & 0x01) && !(temp & (1 << 16)));
	
	SysTick->CTRL = 0x00;
	SysTick->VAL = 0X00;
}

void delay_us(unsigned int nus)
{		
	unsigned int temp;	    	 
	
	SysTick->LOAD = nus * fac_us;	 
	SysTick->VAL = 0x00; 
	SysTick->CTRL = 0x01 ;
	
	do {
		temp = SysTick->CTRL;
	} while ((temp & 0x01) && !(temp & (1 << 16)));
	
	SysTick->CTRL = 0x00;
	SysTick->VAL = 0X00;
}

void delay_s(unsigned int t)
{
	unsigned int i;
	
	for (i = 0; i < t; i++) {
		delay_ms(1000);
	}
}
