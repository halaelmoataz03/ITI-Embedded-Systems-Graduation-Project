/*
 * USART_prog.c
 *
 *  Created on: Jul 30, 2025
 *      Author: DeLL
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "USART_int.h"
#include "USART_priv.h"

void MUSART_vInit (void) {
	// ENABLE RX & TX
	UCSRB = 0b00011000;

	// ENABLE UCSRC REG | ASYNCH MODE |
	// NO PARITY | 1 STOP BIT | 8 BIT DATA | NO CLK POLARITY
	UCSRC = 0b10000110;

	// baud rate = 9600
	UBRRL = 51;
	UBRRH = 0;
}


void MUSART_vTransmit(u8 A_u8Byte) {
	/* Wait for empty transmit buffer */
	 while ( !( UCSRA & (1<<UDRE)) )
	 ;
	 /* Put data into buffer, sends the data */
	 UDR = A_u8Byte;
}


u8 MUSART_u8Receive(void) {
	 /* Wait for data to be received */
	 while ( !(UCSRA & (1<<RXC)) )
	 ;
	 /* Get and return received data from buffer */
	 return UDR;
}

