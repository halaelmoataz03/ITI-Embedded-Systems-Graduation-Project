/*
 * DOOR_prog.c
 *
 *  Created on: Aug 4, 2025
 *      Author: DeLL
 */

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/TIMERS/TIMERS_int.h"

#include "DOOR_int.h"

void HDOOR_vOpen(void) {
	u8 angle = 180;
	MTIMERS_vSetCompareMatch(TIM_1A, ((125 * angle) / 180) + 125);
	_delay_ms(2000);
}

void HDOOR_vClose(void) {
	u8 angle = 0;
	MTIMERS_vSetCompareMatch(TIM_1A, ((125 * angle) / 180) + 125);
	_delay_ms(2000);

}
