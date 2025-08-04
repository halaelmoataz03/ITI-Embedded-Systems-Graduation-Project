/*
 * TIMERS_prog.c
 *
 *  Created on: Jul 30, 2025
 *      Author: DeLL
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_priv.h"
#include "TIMERS_int.h"
#include "TIMERS_config.h"

static void (*G_TIMER0_OVF_CB)(void) = NULL;
static void (*G_TIMER1_OVF_CB)(void) = NULL;
static void (*G_TIMER2_OVF_CB)(void) = NULL;

static void (*G_TIMER0_CTC_CB)(void) = NULL;
static void (*G_TIMER1A_CTC_CB)(void) = NULL;
static void (*G_TIMER1B_CTC_CB)(void) = NULL;
static void (*G_TIMER2_CTC_CB)(void) = NULL;

static void (*G_TIMER_ICU_CB)(void) = NULL;

static u32 G_u32TimeRequired_0 = 0;
static u32 G_u32TimeRequired_1_OVF = 0;
static u32 G_u32TimeRequired_1A_CTC = 0;
static u32 G_u32TimeRequired_1B_CTC = 0;
static u32 G_u32TimeRequired_2 = 0;

void MTIMERS_vInit(void) {
#if TIMER0 == ENABLE
#if TIMER0_MODE == NORMAL
	/* ENABLE NORMAL MODE | OC0 DISCONNECTED | NO CLK */
	CLR_BIT(TCCR0, WGM01);
	CLR_BIT(TCCR0, WGM00);

#elif TIMER0_MODE == CTC
	/* ENABLE CTC MODE | OC0 DISCONNECTED | NO CLK */
	SET_BIT(TCCR0, WGM01);
	CLR_BIT(TCCR0, WGM00);

#elif TIMER0_MODE == FAST_PWM
	/* ENABLE FAST PWM MODE | NO CLK */
	SET_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, WGM00);

#if TIMER0_CMP_OUT_MODE == NON_INVERTING
	SET_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);
#elif TIMER0_CMP_OUT_MODE == INVERTING
	SET_BIT(TCCR0, COM01);
	SET_BIT(TCCR0, COM00);
#endif

#elif TIMER0_MODE == PC_PWM
	/* ENABLE PHASE CORRECTED PWM MODE | NO CLK */
	CLR_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, WGM00);

#if TIMER0_CMP_OUT_MODE == NON_INVERTING
	SET_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);

#elif TIMER0_CMP_OUT_MODE == INVERTING
	SET_BIT(TCCR0, COM01);
	SET_BIT(TCCR0, COM00);
#endif

#else
#error "INCORRECT MODE"
#endif

#if INTERRUPT_CONTROL == ENABLE
	MTIMERS_vEnableInterrupt(TIM_0, TIMER0_MODE);

#elif INTERRUPT_CONTROL == DISABLE
	MTIMERS_vDisableInterrupt(TIM_0, TIMER0_MODE);

#else
#error "INCORRECT VALUE"
#endif

	/* STOP TIMER */
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

#endif

#if TIMER1 == ENABLE
#if TIMER1_MODE == NORMAL
	/* ENABLE NORMAL MODE | OC0 DISCONNECTED | NO CLK */
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

#elif TIMER1_MODE == CTC
	/* ENABLE CTC MODE, TOP: OCR1 | OC0 DISCONNECTED | NO CLK */
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM103);

#elif TIMER1_MODE == FAST_PWM
	/* ENABLE FAST PWM MODE, TOP: ICR1 | NO CLK */
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);
	// COMPARE OUTPUT MODE
#if TIMER1A_CMP_OUT_MODE == NON_INVERTING
	SET_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
#elif TIMER1A_CMP_OUT_MODE == INVERTING
	SET_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1A0);
#endif

#if TIMER1B_CMP_OUT_MODE == NON_INVERTING
	SET_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1B_CMP_OUT_MODE == INVERTING
	SET_BIT(TCCR1A, COM1B1);
	SET_BIT(TCCR1A, COM1B0);
#endif
	/* ICR1 VALUE*/
	ICR1 = ICR1_VALUE;

#elif TIMER1_MODE == PC_PWM
	/* ENABLE PHASE CORRECTED PWM MODE | NO CLK */
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM103);
	// COMPARE OUTPUT MODE
#if TIMER1A_CMP_OUT_MODE == NON_INVERTING
	SET_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
#elif TIMER1A_CMP_OUT_MODE == INVERTING
	SET_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1A0);
#endif

#if TIMER1B_CMP_OUT_MODE == NON_INVERTING
	SET_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1B_CMP_OUT_MODE == INVERTING
	SET_BIT(TCCR1A, COM1B1);
	SET_BIT(TCCR1A, COM1B0);
#endif
	/* ICR1 VALUE*/
	ICR1 = ICR1_VALUE;

#elif ICU_MODE == ENABLE
	SET_BYTE(TCCR1B, 0x00);
	SET_BIT(TCCR1B, ICES1);

#else
#error "INCORRECT MODE"

#endif

#if INTERRUPT_CONTROL == ENABLE
	MTIMERS_vEnableInterrupt(TIM_1, TIMER1_MODE);

#elif INTERRUPT_CONTROL == DISABLE
	MTIMERS_vDisableInterrupt(TIM_1, TIMER1_MODE);

#else
#error "INCORRECT VALUE"
#endif
	/* STOP TIMER */
	CLR_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);
#endif

#if TIMER2 == ENABLE
#if TIMER2_MODE == NORMAL
	/* ENABLE NORMAL MODE | OC0 DISCONNECTED | NO CLK */
	CLR_BIT(TCCR2, WGM21);
	CLR_BIT(TCCR2, WGM20);

#elif TIMER2_MODE == CTC
	/* ENABLE CTC MODE | OC0 DISCONNECTED | NO CLK */
	SET_BIT(TCCR2, WGM21);
	CLR_BIT(TCCR2, WGM20);

#elif TIMER2_MODE == FAST_PWM
	/* ENABLE FAST PWM MODE | NO CLK */
	SET_BIT(TCCR2, WGM21);
	SET_BIT(TCCR2, WGM20);
#if TIMER2_CMP_OUT_MODE == NON_INVERTING
	SET_BIT(TCCR2, COM21);
	CLR_BIT(TCCR2, COM20);
#elif TIMER2_CMP_OUT_MODE == INVERTING
	SET_BIT(TCCR2, COM21);
	SET_BIT(TCCR2, COM20);
#endif

#elif TIMER2_MODE == PC_PWM
	/* ENABLE PHASE CORRECTED PWM MODE | NO CLK */
	CLR_BIT(TCCR2, WGM21);
	SET_BIT(TCCR2, WGM20);
#if TIMER2_CMP_OUT_MODE == NON_INVERTING
	SET_BIT(TCCR2, COM21);
	CLR_BIT(TCCR2, COM20);
#elif TIMER0_CMP_OUT_MODE == INVERTING
	SET_BIT(TCCR2, COM21);
	SET_BIT(TCCR2, COM20);
#endif

#else
#error "INCORRECT MODE"
#endif

#if INTERRUPT_CONTROL == ENABLE
	MTIMERS_vEnableInterrupt(TIM_2, TIMER2_MODE);

#elif INTERRUPT_CONTROL == DISABLE
	MTIMERS_vDisableInterrupt(TIM_2, TIMER2_MODE);

#else
#error "INCORRECT VALUE"
#endif

	/* STOP TIMER */
	CLR_BIT(TCCR2, CS20);
	CLR_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS22);

#endif
}

// NORMAL
void MTIMERS_vSetIntervalAsynch(void (*Fptr)(void), u8 A_u8TimerID,
		u32 A_u32_TimeRequired) {
	switch (A_u8TimerID) {
	case TIM_0:
		G_u32TimeRequired_0 = A_u32_TimeRequired;
		G_TIMER0_OVF_CB = Fptr;
		break;
	case TIM_1:
		G_u32TimeRequired_1_OVF = A_u32_TimeRequired;
		G_TIMER1_OVF_CB = Fptr;
		break;
	case TIM_2:
		G_u32TimeRequired_2 = A_u32_TimeRequired;
		G_TIMER2_OVF_CB = Fptr;
		break;
	}
}

// CTC
void MTIMERS_vSetInterval_CTC(void (*Fptr)(void), u8 A_u8TimerID,
		u32 A_u32TimeRequired, u16 A_u16OCRVal) {
	switch (A_u8TimerID) {
	case TIM_0:
		G_u32TimeRequired_0 = A_u32TimeRequired;
		G_TIMER0_CTC_CB = Fptr;
		break;
	case TIM_1A:
		G_u32TimeRequired_1A_CTC = A_u32TimeRequired;
		G_TIMER1A_CTC_CB = Fptr;
		break;
	case TIM_1B:
		G_u32TimeRequired_1B_CTC = A_u32TimeRequired;
		G_TIMER1B_CTC_CB = Fptr;
		break;
	case TIM_2:
		G_u32TimeRequired_2 = A_u32TimeRequired;
		G_TIMER2_CTC_CB = Fptr;
		break;
	}

	MTIMERS_vSetCompareMatch(A_u8TimerID, A_u16OCRVal);
}

void MTIMERS_vSetCompareMatch(u8 A_u8TimerID, u16 A_u16OCRVal) {
	switch (A_u8TimerID) {
	case TIM_0:
		OCR0 = (u8)A_u16OCRVal;
		break;
	case TIM_1A:
		OCR1A = A_u16OCRVal;
		break;
	case TIM_1B:
		OCR1B = A_u16OCRVal;
		break;
	case TIM_2:
		OCR2 = A_u16OCRVal;
		break;
	}
}

void MTIMERS_vStartTimer(void) {
#if TIMER0 == ENABLE
	TCCR0 = (TCCR0 & (0xF8)) | (TIMER0_PRESCALER & (0x07));
#endif

#if TIMER1 == ENABLE
	TCCR1B = (TCCR1B & (0xF8)) | (TIMER1_PRESCALER & (0x07));
#endif

#if TIMER2 == ENABLE
	TCCR2 = (TCCR2 & (0xF8)) | (TIMER2_PRESCALER & (0x07));
#endif
}

void MTIMERS_vStopTimer(void) {
#if TIMER0 == ENABLE
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
#endif

#if TIMER1 == ENABLE
	CLR_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);
#endif

#if TIMER2 == ENABLE
	CLR_BIT(TCCR2, 0);
	CLR_BIT(TCCR2, 1);
	CLR_BIT(TCCR2, 2);
#endif
}

void MTIMERS_vSetICU_CB(void (*Fptr)(void)) {
	G_TIMER_ICU_CB = Fptr;
}

u16 MTIMERS_u16GetCapturedValue(void) {
	return ICR1;
}

void MTIMERS_vSetICUTrigger(u8 A_u8Trigger_Type) {
	switch (A_u8Trigger_Type) {
	case TRIG_TYPE_FALLING:
		CLR_BIT(TCCR1B, 6);
		break;
	case TRIG_TYPE_RISING:
		SET_BIT(TCCR1B, 6);
		break;
	}
}

void MTIMERS_vEnableInterrupt(u8 A_u8TimerID, u8 A_u8TimerMode) {

	if (A_u8TimerID == TIM_0) {
		switch (TIMER0_MODE) {
		case NORMAL:
			SET_BIT(TIMSK, 0);
			break;
		case CTC:
			SET_BIT(TIMSK, 1);
			break;
		}
	} else if (A_u8TimerID == TIM_1) {
		switch (TIMER1_MODE) {
		case NORMAL:
			SET_BIT(TIMSK, 2);
			break;
		case CTC:
			if (TIMER1A == ENABLE)
				SET_BIT(TIMSK, 4);
			if (TIMER1B == ENABLE)
				SET_BIT(TIMSK, 3);
			if (ICU_MODE == ENABLE)
				SET_BIT(TIMSK, 5);
			break;
		}
	} else if (A_u8TimerID == TIM_2) {
		switch (TIMER2_MODE) {
		case NORMAL:
			SET_BIT(TIMSK, 6);
			break;
		case CTC:
			SET_BIT(TIMSK, 7);
			break;
		}
	}
}

void MTIMERS_vDisableInterrupt(u8 A_u8TimerID, u8 A_u8TimerMode) {
	if (A_u8TimerID == TIM_0) {
		switch (TIMER0_MODE) {
		case NORMAL:
			CLR_BIT(TIMSK, 0);
			break;
		case CTC:
			CLR_BIT(TIMSK, 1);
			break;
		}
	} else if (A_u8TimerID == TIM_1) {
		switch (TIMER1_MODE) {
		case NORMAL:
			CLR_BIT(TIMSK, 2);
			break;
		case CTC:
			if (TIMER1A == ENABLE)
				CLR_BIT(TIMSK, 4);
			if (TIMER1B == ENABLE)
				CLR_BIT(TIMSK, 3);
			if (ICU_MODE == ENABLE)
				CLR_BIT(TIMSK, 5);
			break;
		}
	} else if (A_u8TimerID == TIM_2) {
		switch (TIMER2_MODE) {
		case NORMAL:
			CLR_BIT(TIMSK, 6);
			break;
		case CTC:
			CLR_BIT(TIMSK, 7);
			break;
		}
	}
}

// TIMER0 OVF INTERRUPT
void __vector_11(void)__attribute((signal));
void __vector_11(void) {
	static u32 L_u32TIM0_OVF = 0;
	L_u32TIM0_OVF++;

	if (L_u32TIM0_OVF == G_u32TimeRequired_0) {
		if (G_TIMER0_OVF_CB != NULL) {
			G_TIMER0_OVF_CB();
			L_u32TIM0_OVF = 0;
		}
	}
}

// TIMER0 CMP INTERRUPT
void __vector_10(void)__attribute((signal));
void __vector_10(void) {
	static u32 L_u32TIM0_Counter = 0;
	L_u32TIM0_Counter++;

	if (L_u32TIM0_Counter == G_u32TimeRequired_0) {
		if (G_TIMER0_CTC_CB != NULL) {
			G_TIMER0_CTC_CB();
			L_u32TIM0_Counter = 0;
		}
	}
}

// TIMER1 OVF INTERRUPT
void __vector_9(void)__attribute((signal));
void __vector_9(void) {
	static u32 L_u32TIM1_OVF = 0;
	L_u32TIM1_OVF++;

	if (L_u32TIM1_OVF == G_u32TimeRequired_1_OVF) {
		if (G_TIMER1_OVF_CB != NULL) {
			G_TIMER1_OVF_CB();
			L_u32TIM1_OVF = 0;
		}
	}
}

// TIMER1 CMPB INTERRUPT
void __vector_8(void)__attribute((signal));
void __vector_8(void) {
	static u32 L_u32TIM1B_Counter = 0;
	L_u32TIM1B_Counter++;

	if (L_u32TIM1B_Counter == G_u32TimeRequired_1B_CTC) {
		if (G_TIMER1B_CTC_CB != NULL) {
			G_TIMER1B_CTC_CB();
			L_u32TIM1B_Counter = 0;
		}
	}
}

// TIMER1 CMPA INTERRUPT
void __vector_7(void)__attribute((signal));
void __vector_7(void) {
	static u32 L_u32TIM1A_Counter = 0;
	L_u32TIM1A_Counter++;

	if (L_u32TIM1A_Counter == G_u32TimeRequired_1A_CTC) {
		if (G_TIMER1A_CTC_CB != NULL) {
			G_TIMER1A_CTC_CB();
			L_u32TIM1A_Counter = 0;
		}
	}

}

// TIMER1 ICU INTERRUPT
void __vector_6(void)__attribute((signal));
void __vector_6(void) {
	if (G_TIMER_ICU_CB != NULL) {
		G_TIMER_ICU_CB();
	}
}

// TIMER2 OVF INTERRUPT
void __vector_5(void)__attribute((signal));
void __vector_5(void) {
	static u32 L_u32TIM2_OVF = 0;
	L_u32TIM2_OVF++;

	if (L_u32TIM2_OVF == G_u32TimeRequired_2) {
		if (G_TIMER2_OVF_CB != NULL) {
			G_TIMER2_OVF_CB();
			L_u32TIM2_OVF = 0;
		}
	}
}

// TIMER2 CMP INTERRUPT
void __vector_4(void)__attribute((signal));
void __vector_4(void) {
	static u32 L_u32TIM2_Counter = 0;
	L_u32TIM2_Counter++;

	if (L_u32TIM2_Counter == G_u32TimeRequired_2) {
		if (G_TIMER2_CTC_CB != NULL) {
			G_TIMER2_CTC_CB();
			L_u32TIM2_Counter = 0;
		}
	}
}
