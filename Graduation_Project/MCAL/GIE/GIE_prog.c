/*
 * GIE_prog.c
 *
 *  Created on: Jul 24, 2025
 *      Author: DeLL
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_int.h"
#include "GIE_priv.h"

void MGIE_vEnableInterrupt (void) {
	SET_BIT(SREG, 7);
}
void MGIE_vDisableInterrupt (void) {
	CLR_BIT(SREG, 7);
}
