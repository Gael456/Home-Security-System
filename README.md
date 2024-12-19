ECE 425
Microprocessor Systems
Final Project
Home Security System



Gael Esparza Lobatos
Instructor: Aaron Nanas
Fall 2024


Introduction
This project focuses on the development of a home security system using the Tiva TM4C123G microcontroller. The objective is to detect unauthorized motion and trigger alerts. The system uses various components such as motion detection sensors, RGB LEDs, a buzzer for alerts, and a button interface for arming and disarming. The implementation uses several drivers, including interrupt-driven mechanisms for motion detection, SysTick-based delays, and UART communication for data logging and interfacing.
Designed to detect unauthorized motion and trigger appropriate alerts, this system demonstrates the application of microprocessor concepts to address a practical problem. By utilizing the Tiva platforms GPIO and timer features, the project ensures efficient and real-time operation, emphasizing both reliability and user control. The project applies key embedded systems concepts, such as interrupt handling, GPIO control, timers, and SysTick delays, to achieve real-time operation.

Methodology
Embedded Systems concepts applied  
- Interrupt Handling
Used for motion detection and button inputs to respond to real-time event efficiently
Drivers using interrupts: SR_Sensor_Interrupt.c and BTN_Interrupt.c

- GPIO 
General purpose IO pins were used to interface with components like the buzzer, button, and LED.

- SysTick Delay
SysTick delays were used to ensure accurate time-based operations like a buzzer’-s note frequency and LED delay worked properly.
The outcome of the project is a function home security system that effectively detects motion, sounds an alert, and provides the user control for arming and disarming the system.

- General-Purpose Timer Module
Configured to generate periodic interrupts every 1ms for tasks like LED blinking and button debouncing
Block Diagram


Hardware 
Component
Description
Tiva TM4C123GH6PM
Main microcontroller for the project
Motion Sensor HC-SR105
Detects motion and triggers interrupts
Passive Buzzer
Generates an auditory alarm when motion is detected
RGB LED
Provides visual feedback for the systems state
Push Button
Allows the user to arm or disarm system


Software components
Component                 Description
SR_Sensor_Interrrupt.c    Manages motion sensor input
SysTick_Delay.c           Provides precise delays to timing operations
BTN_Interrupt.c           Handles button press interrupts for task
UART.c                    Handles UART Communication for logging
RGB_LED.c                 Controls the RGB LED for status indication
buzzer.c                  Controls the buzzer to provide audible alarm


Pin layout
Component    Pin   Direction
Buzzer       PA4   Output
Button       PE2   Input
LED Red      PD0   Output
LED Green    PD1   Output
LED Blue     PD2   Output
SR Sensor    PB0   Input


Analysis and Results
Results Obtained
The system successfully arms and disarms using the button.
RGB LED indicates the system status
- Green: Armed and no motion detected
- Red: Motion detected
- LED Off: System Deactivated
Buzzer activates upon motion detection

Issue and Challenges
Hardware Challenges
- Stabilizing the motion sensor signals to avoid false positives due to environmental noise.
  The motion sensor did not generate sufficient voltage to reliably trigger the GPIO pin
  Software Challenges
- The button debouncing implementation was not entirely successful, leading to occasional multiple triggers from a single press. 
  Debugging delay conflicts between LED blinking and buzzer.

Conclusion
The Home Security System project demonstrates the effective application of embedded systems concepts. Using the Tiva TM4C123GH6PM microcontroller, the system successfully integrates hardware and software components to detect motion, provide visual and auditory alerts, and allow user control through push buttons.
Key achievements of the project include real-time responsiveness enabled by interrupt-driven mechanisms, precise timing using the SysTick timer, and the integration of GPIO for seamless interaction with peripheral devices like the buzzer, motion sensor, and  an RGB LED. Despite challenges such as stabilizing the motion sensor signals, insufficient voltage levels, and button debouncing issues, the system is able to performed its intended functions, as demonstrated by its ability to arm, disarm, and alert users of unauthorized motion.
This project highlights the importance of robust hardware design and optimized software logic in achieving reliable performance. While there are areas for improvement, such as enhancing sensor signal processing and refining button debouncing, the system provides a strong foundation for future iterations or expansions, such as adding remote monitoring or additional sensors.

