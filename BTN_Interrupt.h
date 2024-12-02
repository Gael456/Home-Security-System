

#include "TM4C123GH6PM.h"


extern void (*BTN_Task)(uint8_t btn_state);

void BTN_Interrupt_Init(void(*task)(uint8_t));

void GPIOE_Handler(void);