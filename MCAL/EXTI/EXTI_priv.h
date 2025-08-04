/*
 * EXTI_priv.h
 *
 *  Created on: Jul 23, 2025
 *      Author: DeLL
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_


#define MCUCR		*((volatile u8*)(0X55))
#define MCUCSR		*((volatile u8*)(0X54))
#define GICR		*((volatile u8*)(0X5B))
#define GIFR		*((volatile u8*)(0X5A))


#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
