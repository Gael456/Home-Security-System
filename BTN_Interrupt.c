/**
 * @file BTN_Interrupt.c
 *
 * @brief 
 *
 * @author Gael Esparza Lobatos
 *
 */

#include "BTN_Interrupt.h"

void (*BTN_Task)(uint8_t btn_state);

void BTN_Interrupt_Init(void(*task)(uint8_t))
{
	BTN_Task = task;
	
	// Enable the clock to port E
	SYSCTL->RCGCGPIO |= 0x10;
	
	// Configure pins 1 and 2 as input
	GPIOE->DIR &= ~0x06;
	
	// Configure pins PE1 to function as GPIO pins
	GPIOE->AFSEL &= ~0x06;
	
	// Enable the digital functionality for pins PE1
	GPIOE->DEN |= 0x06;
	
	// Enable the pull-down resistor
	GPIOE->PDR |= 0x06;
	
	// Detect edges
	GPIOE->IS &= ~0x06;
	
	// Single edge detection
	GPIOE->IBE &= ~0x06;
	
	// Detect rising edges
	GPIOE->IEV |= 0x06;
	
	// Clear existing interrupts
	GPIOE->ICR |= 0x06;
	
	// sends interrupts to interrupt controller
	GPIOE->IM |= 0x06;
	
	// Enable Port E interrupt in NVIC
  NVIC->ISER[0] |= (1 << 4); // Interrupt number for Port E = 4
	
}

uint8_t BTN_READ(void)
{
	uint8_t btn_state = GPIOE->DATA & 0x06;
	
	return btn_state;
}

void GPIOE_Handler(void) 
{	
  if (GPIOE->MIS & 0x06)
	{
  	// Check if PE1 triggered the interrupt
		(*BTN_Task)(BTN_READ());
		
		GPIOE->ICR |= 0x06;
	}
}
