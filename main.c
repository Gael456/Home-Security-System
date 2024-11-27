/*
 * @file main.c
 *
 * @brief Main source code for the Home Security System program.
 *
 * This file contains the main entry point and function definitions for the LCD Menu Design program.
 * It interfaces with the following:
 *	- EduBase Board LEDs (LED0 - LED3)
 *	- EduBase Board 16x2 Liquid Crystal Display (LCD)
 *  - PMOD ENC Module (Rotary Encoder)
 *
 * 
 *
 * @author Gael Esparza Lobatos
 */

#include "TM4C123GH6PM.h"
#include "SR_Sensor_Interrupt.h"
#include "buzzer.h"



int main(void)
{
	Sensor_Interrupt_Init();
	
	
	while(1)
	{
		buzzer_controller();
	}
}