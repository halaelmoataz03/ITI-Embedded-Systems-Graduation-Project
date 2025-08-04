/*
 * EXTI_int.h
 *
 *  Created on: Jul 23, 2025
 *      Author: DeLL
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#define ENABLE 						1
#define DISABLE						0

#define EXTI_INT0 					ENABLE
#define EXTI_INT1 					DISABLE
#define EXTI_INT2 					DISABLE

#define EXTI_MODE_LOWLEVEL 			0
#define EXTI_MODE_ONCHANGE		 	1
#define EXTI_MODE_FALLING_EDGE		2
#define EXTI_MODE_RISING_EDGE		3

#define EXTI_INT0_MODE 				EXTI_MODE_FALLING_EDGE
#define EXTI_INT1_MODE				EXTI_MODE_LOWLEVEL
#define EXTI_INT2_MODE				EXTI_MODE_FALLING_EDGE

void MEXTI_vInit (void);
void MEXTI_vCallBackFunction (void (*F_ptr) (void), u8 L_u8Index);

#endif /* MCAL_EXTI_EXTI_INT_H_ */
