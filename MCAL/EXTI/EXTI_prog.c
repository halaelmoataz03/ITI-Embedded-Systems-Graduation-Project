/*
 * EXTI_prog.c
 *
 *  Created on: Jul 23, 2025
 *      Author: DeLL
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../GIE/GIE_int.h"

#include "EXTI_int.h"
#include "EXTI_priv.h"

static void (*G_EXTISaveAddArr[3])(void) = {NULL};  /* Static in order to be accessed only by you "private" */

void MEXTI_vInit (void) {
	/* Select interrupt pin (INT0, INT1 or INT2) */
#if EXTI_INT0 == ENABLE

	/* Make user choose mode (rising, falling, on change, or low level) */
#if EXTI_INT0_MODE == EXTI_MODE_LOWLEVEL
	// LOW-LEVEL
	CLR_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);
#elif EXTI_INT0_MODE == EXTI_MODE_ONCHANGE
	// ON CHANGE
	SET_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);
#elif EXTI_INT0_MODE == EXTI_MODE_FALLING_EDGE
	// FALLING
	CLR_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);
#elif EXTI_INT0_MODE == EXTI_MODE_RISING_EDGE
	// RISING
	SET_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);
#else
#error "This option is not allowed"
#endif

	/* Set Peripheral Interrupt Enable (INT0, INT1 or INT2) */
	SET_BIT(GICR, 6);

	/* Set Global Interrupt Enable */
	MGIE_vEnableInterrupt();
#endif


#if EXTI_INT1 == ENABLE
	/* Make user choose mode (rising, falling, on change, or low level) */
#if EXTI_INT1_MODE == EXTI_MODE_LOWLEVEL
	// LOW-LEVEL
	CLR_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);
#elif EXTI_INT1_MODE == EXTI_MODE_ONCHANGE
	// ON CHANGE
	SET_BIT(MCUCR, 2);
	CLR_BIT(MCUCR, 3);
#elif EXTI_INT1_MODE == EXTI_MODE_FALLING_EDGE
	// FALLING
	CLR_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);
#elif EXTI_INT1_MODE == EXTI_MODE_RISING_EDGE
	// RISING
	SET_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);
#else
#error "This option is not allowed"
#endif

	/* Set Peripheral Interrupt Enable (INT0, INT1 or INT2) */
	SET_BIT(GICR, 7);

	/* Set Global Interrupt Enable */
	MGIE_vEnableInterrupt();
#endif


#if EXTI_INT2 == ENABLE
	/* Make user choose mode (rising, falling, on change, or low level) */
#if EXTI_INT2_MODE == EXTI_MODE_FALLING_EDGE
	// FALLING
	CLR_BIT(MCUCSR, 6);
#elif EXTI_INT2_MODE == EXTI_MODE_RISING_EDGE
	// RISING
	SET_BIT(MCUCSR, 6);
#else
#error "This option is not allowed"
#endif

	/* Set Peripheral Interrupt Enable (INT0, INT1 or INT2) */
	SET_BIT(GICR, 5);

	/* Set Global Interrupt Enable */
	MGIE_vEnableInterrupt();
#endif
}

void MEXTI_vCallBackFunction (void (*F_ptr) (void), u8 L_u8Index){
	G_EXTISaveAddArr[L_u8Index] = F_ptr;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if (G_EXTISaveAddArr[0] != NULL)
		// Call Function
		G_EXTISaveAddArr[0]();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if (G_EXTISaveAddArr[1] != NULL)
		// Call Function
		G_EXTISaveAddArr[1]();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if (G_EXTISaveAddArr[2] != NULL)
		// Call Function
		G_EXTISaveAddArr[2]();
}
