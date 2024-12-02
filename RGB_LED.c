/**
 * @file RGB_LED.c
 *
 * @brief 
 *
 * @author Gael Esparza Lobatos
 *
 */

#include "RGB_LED.h"

void RGB_LED_Init(void) {
	
	// Enable clock for Port D
  SYSCTL->RCGCGPIO |= 0x08; 

  // Configure PD0, PD1, PD2 as output
  GPIOD->DIR |= 0x07;  
	
	// Enable digital function for PD0, PD1, PD2
  GPIOD->DEN |= 0x07;  
}

void RGB_LED_Set(uint8_t color) {
  // Set the RGB LED color
  GPIOD->DATA = (GPIOD->DATA & ~0x07) | (color & 0x07);
}

void RGB_LED_Blink(uint8_t color, uint32_t delay_ms) {
  
	// Blink 3 times
	for (int i = 0; i < 3; i++) 
	{  
		// Turn on the LED with the specified color
		RGB_LED_Set(color);  
    Delay1ms(delay_ms);  
		
		// Turn off the LED
    RGB_LED_Set(LED_OFF); 
    Delay1ms(delay_ms);
  }
}
