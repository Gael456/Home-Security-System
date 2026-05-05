# ECE 425 – Microprocessor Systems  
## Final Project: Home Security System

**Gael Esparza Lobatos**  
Instructor: Aaron Nanas  
Fall 2024

---

## Introduction
This project focuses on the development of a **Home Security System** using the **Tiva TM4C123GH6PM microcontroller**. The objective of the system is to detect unauthorized motion within a monitored area and trigger both visual and auditory alerts when movement is detected.

The system integrates multiple hardware peripherals, including a **motion detection sensor**, **RGB LED**, **passive buzzer**, and **push button interface** for arming and disarming the device. To achieve reliable real-time performance, the implementation utilizes several embedded software drivers such as interrupt-based motion sensing, SysTick delay generation, GPIO control, and UART communication for debugging and status monitoring.

This project demonstrates the practical application of microprocessor and embedded systems concepts to solve a real-world security problem. By leveraging the Tiva microcontroller’s GPIO, interrupt, and timer modules, the design provides efficient event-driven operation while maintaining user control and responsiveness.

---

## Methodology

### Embedded Systems Concepts Applied

#### Interrupt Handling
Interrupts were implemented to handle both motion detection and user button input, allowing the system to respond immediately to external events without relying on continuous polling.

**Drivers using interrupts:**
- `SR_Sensor_Interrupt.c`
- `BTN_Interrupt.c`

#### GPIO Interfacing
General Purpose Input/Output (GPIO) pins were configured to interface with the buzzer, motion sensor, push button, and RGB LED. These GPIO connections provide the communication path between the microcontroller and external hardware peripherals.

#### SysTick Delay
The SysTick timer was used to generate precise software delays required for:
- buzzer tone timing,
- LED blinking intervals,
- and short timing control functions throughout the program.

#### General-Purpose Timer Module
A general-purpose hardware timer was configured to generate periodic interrupts every **1 millisecond**. This timer was primarily used for:
- LED state timing,
- button debouncing,
- and periodic system monitoring tasks.

The outcome of this implementation is a functional home security system capable of detecting motion, sounding an alarm, and allowing the user to arm or disarm the device.

---

## Hardware Components

| Component | Description |
|-----------|-------------|
| TM4C123GH6PM | Main microcontroller used for system control |
| HC-SR105 Motion Sensor | Detects motion and triggers system interrupts |
| Passive Buzzer | Generates audible alarm when motion is detected |
| RGB LED | Provides visual feedback for system state |
| Push Button | Allows the user to arm or disarm the security system |

---

## Software Components

| File | Description |
|------|-------------|
| `SR_Sensor_Interrupt.c` | Handles motion sensor interrupt detection |
| `SysTick_Delay.c` | Generates accurate software timing delays |
| `BTN_Interrupt.c` | Handles push button interrupt input |
| `UART.c` | Provides UART communication for debugging/logging |
| `RGB_LED.c` | Controls RGB LED color output |
| `buzzer.c` | Generates buzzer tones for alarm indication |

---

## Pin Layout

| Component | Pin | Direction |
|-----------|-----|-----------|
| Passive Buzzer | PA4 | Output |
| Push Button | PE2 | Input |
| LED Red | PD0 | Output |
| LED Green | PD1 | Output |
| LED Blue | PD2 | Output |
| Motion Sensor | PB0 | Input |

---

## Analysis and Results

### Results Obtained
The completed system was able to successfully perform the following tasks:

- Arm and disarm the security system using the push button input.
- Detect motion using the HC-SR105 motion sensor.
- Provide visual feedback using the RGB LED:
  - **Green LED:** System armed, no motion detected
  - **Red LED:** Motion detected
  - **LED Off:** System disarmed
- Activate the passive buzzer whenever unauthorized motion is detected.

These results demonstrate that the core functionality of the home security system was achieved.

---

## Issues and Challenges

### Hardware Challenges
One of the major hardware issues encountered was stabilizing the output signal from the motion sensor. Due to environmental noise and inconsistent sensor voltage levels, false motion triggers occasionally occurred. Additionally, the motion sensor did not always generate sufficient voltage to reliably register a valid logic high on the GPIO input pin.

### Software Challenges
A software challenge encountered during development involved the push button debouncing implementation. The debouncing routine was not fully optimized, which sometimes caused multiple interrupts to register from a single button press.

Another issue involved managing timing conflicts between LED blinking routines and buzzer tone generation, requiring additional adjustments to delay logic.

---

## Conclusion
The Home Security System project demonstrates the effective application of embedded systems and microprocessor concepts using the **Tiva TM4C123GH6PM microcontroller**. Through the integration of motion sensing, GPIO control, timer modules, interrupts, and user interfaces, the system successfully detects unauthorized motion, activates visual and audible alarms, and allows the user to arm or disarm the device.

Key accomplishments of the project include the implementation of interrupt-driven responsiveness, precise timing through SysTick and general-purpose timers, and successful peripheral interfacing with the buzzer, motion sensor, RGB LED, and push button.

Although several challenges were encountered—such as unstable sensor voltage levels, false motion triggers, and imperfect button debouncing—the system was still able to perform its intended security functions.

Overall, this project highlights the importance of combining robust hardware design with efficient software logic in embedded system applications. Future improvements may include enhanced sensor filtering, improved debouncing algorithms, remote monitoring capability, and the addition of multiple motion sensors for expanded coverage.
