/*
 * KPD_prog.c
 *
 *  Created on: Jul 24, 2025
 *      Author: DeLL
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "KPD_int.h"
#include "KPD_config.h"

#include <util/delay.h>

void HKPD_vInit(void) {
	MDIO_vSetPortDir(KPD_PORT, 0x0F);
	MDIO_vSetPortVal(KPD_PORT, 0xFF);
}

u8 HKPD_u8PressedKey(void) {
	u8 L_u8PressedKey = 0;
	for (u8 L_u8Col = 0; L_u8Col < KPD_COLS; L_u8Col++) {
		MDIO_vSetPinVal(KPD_PORT, L_u8Col, DIO_LOW);

		for (u8 L_u8Row = 0; L_u8Row < KPD_ROWS; L_u8Row++) {
			if(!MDIO_u8GetPinVal(KPD_PORT, 4 + L_u8Row)){
				while(!MDIO_u8GetPinVal(KPD_PORT, 4 + L_u8Row));
				// Delay
				_delay_ms(10);
				// Action
				L_u8PressedKey = KeyMap [L_u8Row][L_u8Col];
				return L_u8PressedKey;
			}
		}
		MDIO_vSetPinVal(KPD_PORT, L_u8Col, DIO_HIGH);
	}
	// If no key is pressed, return 0xFF
	return 255;
}
