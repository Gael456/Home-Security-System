#include "TM4C123GH6PM.h"
#include "SR_Sensor_Interrupt.h"
#include "buzzer.h"
#include "BTN_Interrupt.h"
#include "SysTick_Delay.h"
#include "RGB_LED.h"
#include "UART0.h"


volatile uint8_t system_state = 1;
volatile uint8_t prev_system_state = 0;

void BTN_Handler(uint8_t btn_status);

int main(void)
{
	// Initialize Sensor driver
	Sensor_Interrupt_Init();
	
	// Initialize Buzzer driver
	Buzzer_Init();
	
	// Initialize button interrupt
	BTN_Interrupt_Init(&BTN_Handler);
	
	// Initialize RGB LED
	RGB_LED_Init();
	
	// Initialize SysTick timer
	SysTick_Delay_Init();
	
	UART0_Init();
	
	
	
	UART0_Output_String("System Initialized.");
	UART0_Output_Newline();
	Delay1ms(1000);
	
	while(1)
	{	

		while(system_state)
		{
			
			
			if(!prev_system_state)
		  {
		  	RGB_LED_Set(LED_GREEN);
				UART0_Output_String("System Armed: No Motion Detect.");
				UART0_Output_Newline();
				prev_system_state = 1;
		  }
			
			while(motion_detected)
			{
				prev_system_state++;
				if(prev_system_state == 2)
				{
				
					UART0_Output_String("Motion Detected");
					UART0_Output_Newline();
				}

			  RGB_LED_Set(LED_RED);
			  buzzer_controller();
				
		  }
		}
	  
	}
}

void BTN_Handler(uint8_t btn_state) {
  switch(btn_state) 
	{
		case(0x04):
		{
			system_state = !system_state;
			motion_detected = 0;
			if(system_state)
			{
				prev_system_state = 0;
			}				
			else
			{
				RGB_LED_Set(LED_OFF);
				UART0_Output_String("System Disarmed");
				UART0_Output_Newline();
			}			
		}
  }
}

	