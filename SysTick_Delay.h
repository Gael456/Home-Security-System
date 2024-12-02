

#include "TM4C123GH6PM.h"


/**
 * @brief Initializes the sysTick timer
 *
 * @param None
 *
 * @return None
 */
void SysTick_Delay_Init(void);


/**
 * @brief Provides a blocking delay in microseconds using the SysTick timer
 *
 * @param delay 
 *
 * @return None
 */
void Delay1us(uint32_t delay);

/**
 * @brief Provides a blocking delay in milliseconds using the SysTick timer
 *
 * @param delay 
 *
 * @return None
 */
void Delay1ms(uint32_t delay);

void SysTick_Handler(void);