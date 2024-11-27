/**
 * @file Sr_Sensor_Interrupt.c
 *
 * @brief 
 *
 *
 *
 */
 
 #include "SR_Sensor_Interrupt.h"

void Sensor_Interrupt_Init(void)
 {
	 // Enable port B
	 SYSCTL->RCGCGPIO |= 0x02;
	 
	 // Initialize PB0 as an output
	 GPIOB->DIR &= ~0x01;
	 
	 // Enables digital function for PB0
	 GPIOB->DEN |= 0x01;
	 
	 // Enables pull-up resistor for PB0
	 GPIOB->PUR |= 0x01;
	 
	 // Edge-Sensitive
	 GPIOB->IS &= ~0x01;
	 
	 // Single-Edge detection
	 GPIOB->IBE &= ~0x01;
	 
	 // Rising edge trigger
	 GPIOB-> IEV |= 0x01;
	 
	 // CLear interrupts
	 GPIOB->ICR |= 0x01;
	 
	 // Enable interrupt for PB0
	 GPIOB->IM |= 0x01;
	 
	 NVIC->ISER[0] |= (1 << 1);
 }
 
 void GPIOB_Handler(void)
 {
	 if (GPIOB->RIS & 0x01)
	 {
		 // Clear interrupt
		 GPIOB->ICR |= 0x01;
		 GPIOB->DATA |= 0x02;
	 }
 }
 
 