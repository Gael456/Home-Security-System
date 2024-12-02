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
	
	// Configure pins 1 as input
	GPIOE->DIR &= ~0x02;
	
	// Configure pins PE1 to function as GPIO pins
	GPIOE->AFSEL &= ~0x02;
	
	// Enable the digital functionality for pins PE1
	GPIOE->DEN |= 0x02;
	
	// Enable the pull-down resistor
	GPIOE->PDR |= 0x02;
	
	// Detect edges
	GPIOE->IS &= ~0x02;
	
	// Single edge detection
	GPIOE->IBE &= ~0x02;
	
	// Detect rising edges
	GPIOE->IEV |= 0x02;
	
	// Clear existing interrupts
	GPIOE->ICR |= 0x02;
	
	// sends interrupts to interrupt controller
	GPIOE->IM |= 0x02;
	
	// Enable Port E interrupt in NVIC
  NVIC->ISER[0] |= (1 << 4); // Interrupt number for Port E = 4
	
}

void GPIOE_Handler(void) {
    if (GPIOE->RIS & 0x02) { // Check if PE1 triggered the interrupt
        BTN_Task(1);         // Pass button state to the task
        GPIOE->ICR |= 0x02;  // Clear interrupt flag for PE1
    }
}
