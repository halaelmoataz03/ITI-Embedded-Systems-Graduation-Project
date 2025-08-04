/*
 * ADC_prog.c
 *
 *  Created on: Jul 28, 2025
 *      Author: DeLL
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_priv.h"
#include "ADC_int.h"

void MADC_vInit(void) {
	/* REFERENCE VOLTAGE: AREF, AVCC, INT 2.56
	 * ADMUX: AVCC BIT7:BIT6 = 01*/
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);

	/* DATA ADJUSTMENT
	 * ADMUX: RIGHT ADJUSTMENT BIT5 = 0*/
	CLR_BIT(ADMUX, ADLAR);

	/* PRESCALER
	 * FREQ/64  */
	ADCSRA = (ADCSRA & (0xF8)) | ((0x07) & (PRESCALER));

	/* AUTO TRIGGER OR MANUAL
	 * Bit 5 – ADATE:0 MANUAL*/
	CLR_BIT(ADCSRA, ADATE);

	/* INTERRUPT OR POLLING
	 *  Bit 3 – ADIE:0 DISABLE INTERRUPT */
	CLR_BIT(ADCSRA, ADIE);

	/* ENABLE ADC
	 *  Bit 7 – ADEN */
	SET_BIT(ADCSRA, ADEN);
}

u16 MADC_u16AnalogRead(u8 A_u8Channel) {
	/* Select Channel */
	ADMUX = (ADMUX & (0xE0)) | (A_u8Channel & (0x07));

	/* Start Conversion
	 * Set ADSC bit 6 in ADCSRA */
	SET_BIT(ADCSRA, ADSC);

	/* Wait for the Flag to be raised
	 * until ADIF bit 4 is 1*/
	while(GET_BIT(ADCSRA, ADIF) == 0);

	/* Clear ADIF flag
	 * ADIF is cleared by writing a logical one to the flag */
	SET_BIT(ADCSRA, ADIF);

	return ADC;
}
