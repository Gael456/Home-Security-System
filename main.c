/*
 * @file main.c
 *
 * @brief Main source code for the Home Security System program.
 *
 * This file contains the main entry point and function definitions for the LCD Menu Design program.
 * It interfaces with the following:
 *	- 
 *	- 
 *  - 
 *
 * 
 *
 * @author Gael Esparza Lobatos
 */

#include "TM4C123GH6PM.h"
#include "SR_Sensor_Interrupt.h"
#include "buzzer.h"
#include "BTN_Interrupt.h"
#include "SysTick_Delay.h"
#include "RGB_LED.h"


void BTN_Handler(uint8_t btn_status);

int main(void)
{
	Sensor_Interrupt_Init();
	Buzzer_Init();
	BTN_Interrupt_Init(&BTN_Handler);
	RGB_LED_Init();
	
	while(1)
	{
		
		// Idle state: System armed and waiting for motion
		if(!motion_detected)
		{
			// Set green for idle state
			RGB_LED_Set(LED_GREEN);
		}
		
		// Motion Detected
		while(motion_detected){
			
			// Indicate motion with red LED and buzzer
			Buzzer_Output(BUZZER_ON);
			RGB_LED_Set(LED_RED);
			buzzer_controller();
		
		}
	}
}


// Resets the Security system
void BTN_Handler(uint8_t btn_state) {
  if (btn_state) {
		
    // Indicates reset with blue LED
		RGB_LED_Set(LED_BLUE);
		motion_detected = 0;
		Delay1ms(500);
		RGB_LED_Set(LED_OFF);
		RGB_LED_Set(LED_GREEN);
  }
}

	
