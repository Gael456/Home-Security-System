/**
 * @file buzzer.c
 *
 * @brief Code for buzzer driver
 *
 * @author Gael Esparza Lobatos
 */
 
 #include "buzzer.h"
 
 const uint8_t BUZZER_OFF = 0x00;
 const uint8_t BUZZER_ON = 0x10;
 

 
 void Buzzer_Init(void)
 {
	 // Enable clock for GPIO port A
	 SYSCTL->RCGCGPIO |= 0x01;
	 
	 // Set GPIOA Pin 4 as output
	 GPIOA->DIR |= 0x10;
	 
	 // Disable alternate function for PA4
	 GPIOA->AFSEL &= ~0x10;
	 
	 // Enable digital functionality for PA4
	 GPIOA->DEN |= 0x10;
 }
 
 // Stes the buzzer state to ON/OFF
 void Buzzer_Output(uint8_t buzzer_value)
 {
	 // Clears PA4 and sets the state of the buzzer
	 GPIOA->DATA = (GPIOA->DATA & 0xEF) | buzzer_value;
 }
 
 void Play_Note(void)
{
	// Note frequency
	double note = 440.0;
	// Duration of note
	unsigned int duration = 100;
	
	//Calculates the period in microseconds
	int period_us = (int) (((double)1/note) * ((double)1000000));
	int half_period_us = period_us / 2;
	
	for(unsigned int i = 0; i < duration; i++) {
		
		Buzzer_Output(BUZZER_ON);
		Delay1us(half_period_us);
		Buzzer_Output(BUZZER_OFF);
		Delay1us(half_period_us);
		
	}
}

void buzzer_controller(void)
{
	Play_Note();
}