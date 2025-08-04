/*
 * USART_int.h
 *
 *  Created on: Jul 30, 2025
 *      Author: DeLL
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_

void MUSART_vInit (void);
void MUSART_vTransmit(u8 A_u8Byte);
u8 MUSART_u8Receive(void);

#endif /* MCAL_USART_USART_INT_H_ */
