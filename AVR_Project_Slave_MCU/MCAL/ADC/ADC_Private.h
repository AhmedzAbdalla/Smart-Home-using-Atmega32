/*
 * EXTI_Config.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Ahmed Abdalla
 */
 //file guard
#ifndef _ADC_PRIVATE_
#define _ADC_PRIVATE_

//ADC Rgisters 
#define ADMUX          *((volatile u8*)0x27)
#define ADCSRA         *((volatile u8*)0x26)
#define ADCL           *((volatile u8*)0x24)
#define ADCH           *((volatile u8*)0x25)

//macro funtion
#define CLR_MUX()               ( ADMUX &=0xE0) 
#define SET_MUX(MASK)           ( ADMUX |=MASK)

// ADMUX Regiter pins

#define ADMUX_MUX0          0x00u
#define ADMUX_MUX1          0x01u
#define ADMUX_MUX2          0x02u
#define ADMUX_MUX3          0x03u
#define ADMUX_MUX4          0x04u
#define ADMUX_ADLAR         0x05u
#define ADMUX_REFS0         0x06u
#define ADMUX_REFS1         0x07u

//=====================================

#define ADCSRA_ADPS0        0x00u
#define ADCSRA_ADPS1        0x01u
#define ADCSRA_ADPS2        0x02u
#define ADCSRA_ADIE         0x03u
#define ADCSRA_ADIF         0x04u
#define ADCSRA_ADATE        0x05u
#define ADCSRA_ADSC         0x06u
#define ADCSRA_ADEN         0x07u

#endif //_ADC_PRIVATE_