/**
 * @file SR_Sensor_Interrupt.h
 */
 
 #include "TM4C123GH6PM.h"
 
 extern volatile int motion_detected;
 
 void Sensor_Interrupt_Init(void);
 
 void GPIOB_Handler();