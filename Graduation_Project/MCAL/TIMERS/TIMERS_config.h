/*
 * TIMERS_config.h
 *
 *  Created on: Jul 31, 2025
 *      Author: DeLL
 */

#ifndef MCAL_TIMERS_TIMERS_CONFIG_H_
#define MCAL_TIMERS_TIMERS_CONFIG_H_

/* -----------ENABLE TIMERS----------- */
/*	Options:
 * ENABLE
 * DISABLE
 */
#define TIMER0 					ENABLE
#define TIMER1 					ENABLE
#define TIMER1A 				ENABLE
#define TIMER1B 				DISABLE
#define TIMER2 					DISABLE
#define ICU_MODE 				DISABLE

/* -----------TIMER MODES----------- */
/*	Options:
 * NORMAL
 * CTC
 * FAST_PWM
 * PC_PWM
 */
#define TIMER0_MODE 			FAST_PWM
#define TIMER1_MODE 			FAST_PWM
#define TIMER2_MODE 			NORMAL

/* -----------TIMER0 AND TIMER1 PRESCALER----------- */
/*	Options:
 * NO_CLK
 * CLK_1
 * CLK_8
 * CLK_64
 * CLK_256
 * CLK_1024
 * CLK_EXT_FALLING
 * CLK_EXT_RISING
 */
#define TIMER0_PRESCALER		CLK_8
#define TIMER1_PRESCALER		CLK_64

/* -----------TIMER2 PRESCALER----------- */
/*	Options:
 * NO_CLK2
 * CLK2_1
 * CLK2_8
 * CLK2_32
 * CLK2_64
 * CLK2_128
 * CLK2_256
 * CLK2_1024
 */
#define TIMER2_PRESCALER		CLK2_8

/* -----------TIMER COMPARE OUTPUT MODES----------- */
/*	Options:
 * NON_INVERTING
 * INVERTING
 *
 * FOR FAST PWM:
 * NON_INVERTING: Clear OCn on compare match. Set OCn at BOTTOM
 * INVERTING: Set OCn on compare match. Clear OCn at BOTTOM
 *
 * FOR PHASE CORRECT PWM:
 * NON_INVERTING: Clear OCn on compare match when up-counting. Set OCn on compare match when down-counting.
 * INVERTING: Set OCn on compare match when up-counting. Clear OCn on compare match when down-counting.
*/
#define TIMER0_CMP_OUT_MODE 	NON_INVERTING
#define TIMER1A_CMP_OUT_MODE 	NON_INVERTING
#define TIMER1B_CMP_OUT_MODE 	NON_INVERTING
#define TIMER2_CMP_OUT_MODE 	NON_INVERTING

/* -----------INTERRUPT AND FLAG CONTROL----------- */
/*	Options:
 * ENABLE
 * DISABLE
*/
#define INTERRUPT_CONTROL		DISABLE
#define FLAG_CONTROL			DISABLE

/* -----------ISELECT ICR1 VALUE----------- */
#define ICR1_VALUE				2499

#endif /* MCAL_TIMERS_TIMERS_CONFIG_H_ */
