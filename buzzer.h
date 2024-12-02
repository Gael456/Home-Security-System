


#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"


extern const uint8_t BUZZER_OFF;
extern const uint8_t BUZZER_ON;

void Buzzer_Init(void);

void Play_Note(void);

void Buzzer_Output(uint8_t buzzer_value);

void buzzer_controller(void);