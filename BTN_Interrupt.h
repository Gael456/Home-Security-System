

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"


extern void (*BTN_Task)(uint8_t btn_state);

void BTN_Interrupt_Init(void(*task)(uint8_t));

uint8_t BTN_READ(void);

void GPIOE_Handler(void);