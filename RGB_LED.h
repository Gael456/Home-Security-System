#define RGB_LED_H
#define RGB_LED_H

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"

// RGB LED Colors
#define LED_OFF   0x00
#define LED_RED   0x01
#define LED_GREEN 0x02
#define LED_BLUE  0x04 

#define LED_YELLOW (LED_RED | LED_GREEN) // Red + Green = Yellow
#define LED_CYAN   (LED_GREEN | LED_BLUE) // Green + Blue = Cyan
#define LED_PURPLE (LED_RED | LED_BLUE) // Red + Blue = Magenta
#define LED_WHITE  (LED_RED | LED_GREEN | LED_BLUE) // Red + Green + Blue = White

/**
 * @brief Initializes LED pins
 *
 * @param None
 *
 * @return None
 */
void RGB_LED_Init(void);

/**
 * @brief Sets the color of the RGB LED
 *
 * @param color
 *
 * @return None
 */
void RGB_LED_Set(uint8_t color); // Set the RGB LED color

/**
 * @brief Sets the LED to blink in the desired color with a delay
 *
 * @param color, delay_ms
 *
 * @return None
 */
void RGB_LED_Blink(uint8_t color, uint32_t delay_ms); // Blink the LED with a color
