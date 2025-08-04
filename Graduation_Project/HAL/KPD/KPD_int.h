/*
 * KPD_int.h
 *
 *  Created on: Jul 24, 2025
 *      Author: DeLL
 */

#ifndef HAL_KPD_KPD_INT_H_
#define HAL_KPD_KPD_INT_H_

#include "../../LIB/STD_TYPES.h"

#define KPD_PORT 	DIO_PORTA

#define KPD_C1		DIO_PIN0
#define KPD_C2		DIO_PIN1
#define KPD_C3		DIO_PIN2
#define KPD_C4		DIO_PIN3

#define KPD_R1		DIO_PIN4
#define KPD_R2		DIO_PIN5
#define KPD_R3		DIO_PIN6
#define KPD_R4		DIO_PIN7

#define KPD_ROWS	3
#define KPD_COLS	3

static u8 KeyMap [KPD_ROWS][KPD_COLS] = {{'1', '2', '3'},
						   	   	   	   	 {'4', '5', '6'},
										 {'7', '8', '9'}};

void HKPD_vInit (void);
u8 HKPD_u8PressedKey (void);

#endif /* HAL_KPD_KPD_INT_H_ */
