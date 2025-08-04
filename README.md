# ITI-Embedded-Systems-Graduation-Project
##  Bluetooth-Controlled Home Automation System
###  Overview:
Design a home automation system that allows users to control home appliances (like lights, fans, etc.) remotely using a smartphone via Bluetooth. This system will include real-time control, status display, and manual override options.

### Core Features:
####  1. Appliance Control via Bluetooth:
Hardware: Bluetooth module (e.g., HC-05)(Extra Hardware), relays, DC motor, LEDs, DIP switches.
Control appliances like lights (simulated by LEDs), fans (using a DC motor), and other devices through Bluetooth commands from a smartphone app.

#### 2. Manual Override:
Hardware: DIP switches, push buttons.
Allow the user to manually control appliances in case of Bluetooth failure or preference for physical control.

#### 3. Status Display:
Hardware: Character LCD, LEDs.
Show the current status of appliances (on/off, speed, etc.) on the LCD. LEDs serve as indicators of system status.

#### 4. Data Logging & System Monitoring:
Hardware: External EEPROM.
 ○ Log data related to system usage (e.g., appliance on/off times) and store them in the EEPROM for future analysis.

#### 5. Real-Time Task Management:
Hardware: FreeRTOS for task scheduling.
Manage real-time tasks such as Bluetooth communication, manual input handling, and system monitoring using FreeRTOS.

#### 6. Feedback System for User:
 ○ Hardware: Buzzer (for sound feedback).
 ○ Notify the user when an action is taken via sound, providing auditory confirmation for successful commands.

