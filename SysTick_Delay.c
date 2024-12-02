/**
 * @file SysTick_Delay.c
 *
 * @brief 
 *
 * @author Gael Esparza Lobatos
 *
 */

#include "SysTick_Delay.h"

static uint32_t us_elapsed = 0;

// Global flag used to indicate if milliseconds delay is active
static uint8_t ms_active = 0;

static uint32_t ms_elapsed = 0;

void SysTick_Delay_Init(void)
{
	// Set SysTick for 1us delay with a 4MHz clock
	SysTick->LOAD = (4 - 1);
	
	// Enable SysTick with system clock
	SysTick->CTRL |= 0x03;
}

void Delay1us(uint32_t delay)
{
	us_elapsed = 0;
	
	while(delay > us_elapsed);
}

void Delay1ms(uint32_t delay)
{
	// Reset the global variables, us_elapsed and ms_elapsed
	us_elapsed = 0;
	ms_elapsed = 0;
	
	// Set the ms_active global flag
	ms_active = 0x01;
	
	// Wait until ms_elapsed reaches the specified delay_in_ms
	while (delay > ms_elapsed);
	
	// Reset the ms_active global flag
	ms_active = 0x00;
}

void SysTick_Handler(void) {
  // Increment the global variable for microseconds
  us_elapsed++;

  // Check if 1 millisecond has elapsed
  if (us_elapsed == 1000 && (ms_active == 0x01))
	{
		// Reset us_elapsed
		us_elapsed = 0;
		
		// Increment ms_elapsed to indicate that 1 millisecond has passed
		ms_elapsed++;
	}
}
