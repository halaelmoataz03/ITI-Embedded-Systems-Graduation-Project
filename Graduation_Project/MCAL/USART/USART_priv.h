/*
 * USART_priv.h
 *
 *  Created on: Jul 30, 2025
 *      Author: DeLL
 */

#ifndef MCAL_USART_USART_PRIV_H_
#define MCAL_USART_USART_PRIV_H_

#define UCSRC		*((volatile u8*)(0x40))
#define UDR			*((volatile u8*)(0x2C))
#define UCSRA		*((volatile u8*)(0x2B))
#define UCSRB		*((volatile u8*)(0x2A))
#define UBRRL		*((volatile u8*)(0x29))
#define UBRRH		*((volatile u8*)(0x40))

#define UDRE		5
#define RXC			7

#endif /* MCAL_USART_USART_PRIV_H_ */
