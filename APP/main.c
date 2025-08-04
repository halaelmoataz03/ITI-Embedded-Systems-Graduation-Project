/*
 * main.c
 *
 *  Created on: Aug 3, 2025
 *      Author: DeLL
 */
#define F_CPU 8000000UL
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIMERS/TIMERS_int.h"
#include "../MCAL/USART/USART_int.h"

#include "../HAL/LIGHTS/LIGHTS_int.h"
#include "../HAL/DOOR/DOOR_int.h"

#include <util/delay.h>


int main() {
	MDIO_vSetPinDir(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);	//light
	MDIO_vSetPinDir(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);	//DOOR
	MDIO_vSetPinDir(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);	//Fan

	MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);
	MTIMERS_vInit();
	MTIMERS_vStartTimer();

	u8 SaveData = 0;
	MUSART_vInit();

	while (1) {

		SaveData = MUSART_u8Receive();

		if (SaveData == 'A') {			// turn on the lights
			MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_HIGH);

		} else if (SaveData == 'B') {	// turn off the lights
			MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);

		} else if (SaveData == 'C') {	// open the door
			HDOOR_vOpen();

		} else if (SaveData == 'D') {	// close the door
			HDOOR_vOpen();

		} else if (SaveData == 'E') {	// fan, speed 1
			MTIMERS_vSetCompareMatch(TIM_0, 127);

		} else if (SaveData == 'F') {	// fan, speed 2
			MDIO_vSetPinVal(DIO_PORTB, DIO_PIN3, DIO_HIGH);
		}

	}
	return 0;
}
