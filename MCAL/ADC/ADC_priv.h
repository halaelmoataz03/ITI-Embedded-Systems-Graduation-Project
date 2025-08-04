/*
 * ADC_priv.h
 *
 *  Created on: Jul 28, 2025
 *      Author: DeLL
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define ADMUX 		*((volatile u8*)(0x27))
#define ADCSRA 		*((volatile u8*)(0x26))
#define ADCH 		*((volatile u8*)(0x25))
#define ADCL 		*((volatile u8*)(0x24))

#define ADC 		*((volatile u16*)(0x24))



#define REFS0		6
#define REFS1		7

#define ADLAR		5

#define CLK_2		0
#define CLK_4		2
#define CLK_8		3
#define CLK_16		4
#define CLK_32		5
#define CLK_64		6
#define CLK_128		7

#define PRESCALER	CLK_64

#define ADATE		5
#define ADIE		3
#define ADEN		7

#define ADSC		6
#define ADIF		4

#endif /* MCAL_ADC_ADC_PRIV_H_ */
