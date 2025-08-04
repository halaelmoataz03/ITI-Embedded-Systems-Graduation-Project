/*
 * TIMERS_priv.h
 *
 *  Created on: Jul 30, 2025
 *      Author: DeLL
 */

#ifndef MCAL_TIMERS_TIMERS_PRIV_H_
#define MCAL_TIMERS_TIMERS_PRIV_H_

/* -------------TIMER 0------------- */
#define TCCR0	*((volatile u8*)(0x53))
#define TCNT0	*((volatile u8*)(0x52))
#define OCR0	*((volatile u8*)(0x5C))
#define TIMSK	*((volatile u8*)(0x59))
#define TIFR	*((volatile u8*)(0x58))
#define SFIOR	*((volatile u8*)(0x50))

/* -------------TIMER 1------------- */
#define TCCR1A	*((volatile u8*)(0x4F))
#define TCCR1B	*((volatile u8*)(0x4E))
#define TCNT1	*((volatile u16*)(0x4C))
#define OCR1A	*((volatile u16*)(0x4A))
#define OCR1B	*((volatile u16*)(0x48))
#define ICR1	*((volatile u16*)(0x46))

/* -------------TIMER 2------------- */
#define TCCR2	*((volatile u8*)(0x45))
#define TCNT2	*((volatile u8*)(0x44))
#define OCR2	*((volatile u8*)(0x43))


/* --------TIMER Configuration-------- */
#define ENABLE 					1
#define DISABLE 				0

/* -----------TIMERS MODES----------- */
#define NORMAL					0
#define CTC						1
#define FAST_PWM				2
#define PC_PWM					3

/* --------TIMER PreScaler-------- */
// ONLY TIMER0 AND TIMER1
#define NO_CLK 					0
#define CLK_1 					1
#define CLK_8 					2
#define CLK_64 					3
#define CLK_256 				4
#define CLK_1024 				5
#define CLK_EXT_FALLING			6
#define CLK_EXT_RISING			7

// ONLY TIMER2
#define NO_CLK2 				0
#define CLK2_1 					1
#define CLK2_8 					2
#define CLK2_32 				3
#define CLK2_64 				4
#define CLK2_128 				5
#define CLK2_256 				6
#define CLK2_1024 				7

/* ------TIMER COMPARE OUTPUT------ */
#define NON_INVERTING 			0
#define INVERTING 				1

/* -----------REGISTERS----------- */
/* TCCRO */
#define FOC0					7
#define WGM01					6
#define COM01					5
#define COM00					4
#define WGM00					3
#define CS02					2
#define CS01					1
#define CS00					0

/* TCCR1A */
#define COM1A1					7
#define COM1A0					6
#define COM1B1					5
#define COM1B0					4
#define FOC1A					3
#define FOC1B					2
#define WGM11					1
#define WGM10					0

/* TCCR1B */
#define ICNC1					7
#define ICES1					6
#define RES						5
#define WGM13					4
#define WGM12					3
#define CS12					2
#define CS11					1
#define CS10					0

/* TCCR2 */
#define FOC2					7
#define WGM20					6
#define COM21					5
#define COM20					4
#define WGM21					3
#define CS22					2
#define CS21					1
#define CS20					0

#endif /* MCAL_TIMERS_TIMERS_PRIV_H_ */
