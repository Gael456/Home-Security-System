

#include "SysTick_Delay.h"

static uint32_t us_elapsed = 0;


void SysTick_Delay_Init(void)
{
	SysTick->LOAD = (4 - 1);
	
	SysTick->CTRL |= 0x03;
}

void Delay1us(uint32_t delay)
{
	us_elapsed = 0;
	
	while(delay > us_elapsed);
}