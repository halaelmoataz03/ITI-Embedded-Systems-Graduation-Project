/*
 * LIGHTS_prog.c
 *
 *  Created on: Aug 4, 2025
 *      Author: DeLL
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "LIGHTS_int.h"
#include "../../MCAL/DIO/DIO_int.h"

void HLIGHTS_vRoomLightOn(u8 Room) {
	MDIO_vSetPinVal(LightsPort, Room, DIO_HIGH);
}

void HLIGHTS_vRoomLightOff(u8 Room) {
	MDIO_vSetPinVal(LightsPort, Room, DIO_LOW);
}
