/*
 * TIMERS_int.h
 *
 *  Created on: Jul 30, 2025
 *      Author: DeLL
 */

#ifndef MCAL_TIMERS_TIMERS_INT_H_
#define MCAL_TIMERS_TIMERS_INT_H_

/* -----------TIMERS ID----------- */
#define TIM_0 					0
#define TIM_1 					1
#define TIM_1A 					2
#define TIM_1B 					3
#define TIM_2 					4
#define ICU 					5

/* ---------TRIGGER TYPES--------- */
#define TRIG_TYPE_RISING	 	0
#define TRIG_TYPE_FALLING 		1


/* ---------FUNCTIONS--------- */
void MTIMERS_vInit (void);
// Normal
// A_u8_TimerID: TIM_0, TIM_1, TIM_2
void MTIMERS_vSetIntervalAsynch(void (*Fptr)(void), u8 A_u8_TimerID, u32 A_u32_TimeRequired);

// CTC
// A_u8_TimerID: TIM_0, TIM_1A, TIM_1B, TIM_2
void MTIMERS_vSetInterval_CTC(void (*Fptr)(void), u8 A_u8_TimerID, u32 A_u32_TimeRequired, u16 A_u16_OCRVal);
void MTIMERS_vSetCompareMatch(u8 A_u8TimerID, u16 A_u16OCRVal);

void MTIMERS_vSetICU_CB (void (*Fptr)(void));
u16 MTIMERS_u16GetCapturedValue (void);

// A_u8Trigger_Type: TRIG_TYPE_RISING, TRIG_TYPE_FALLING
void MTIMERS_vSetICUTrigger (u8 A_u8Trigger_Type);

// A_u8_TimerID: TIM_0, TIM_1, TIM_2
void MTIMERS_vEnableInterrupt (u8 A_u8TimerID, u8 A_u8TimerMode);
void MTIMERS_vDisableInterrupt (u8 A_u8TimerID, u8 A_u8TimerMode);

// A_u8_TimerID: TIM_0, TIM_1, TIM_2
void MTIMERS_vStartTimer(void);
void MTIMERS_vStopTimer(void);

#endif /* MCAL_TIMERS_TIMERS_INT_H_ */
