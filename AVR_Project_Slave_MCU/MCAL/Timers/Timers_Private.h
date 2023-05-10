/*
 * EXTI_Private.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/************************************Timer 0*************************************/

//Timer0 Registers
#define TIMER0_TCCR0    (*((volatile u8*)0x53))
#define TIMER0_TIMSK    (*((volatile u8*)0x59))
#define TIMER0_TIFR     (*((volatile u8*)0x58))
#define TIMER0_TCNT0    (*((volatile u8*)0x52))
#define TIMER0_OCR0     (*((volatile u8*)0x5C))


// TCCR0 Rgister Bits
#define TCCR0_CS00       0x00
#define TCCR0_CS01       0x01
#define TCCR0_CS02       0x02
#define TCCR0_WGM01      0x03
#define TCCR0_COM00      0x04
#define TCCR0_COM01      0x05
#define TCCR0_WGM00      0x06
#define TCCR0_FOC0       0x07


// TIMSK Rgister Bits
#define TIMSK_TOIE0       0x00
#define TIMSK_OCIE0       0x01
#define TIMSK_TOIE1       0x02
#define TIMSK_OCIE1B      0x03
#define TIMSK_OCIE1A      0x04
#define TIMSK_TICIE1      0x05
#define TIMSK_TOIE2       0x06
#define TIMSK_OCIE2       0x07

// TIFR Rgister Bits
#define TIFR_TOV0         0x00
#define TIFR_OCF0         0x01
#define TIFR_TOV1         0x02
#define TIFR_OCF1B        0x03
#define TIFR_OCF1A        0x04
#define TIFR_ICF1         0x05
#define TIFR_TOV2         0x06
#define TIFR_OCF2         0x07
/************************************End of Timer 0*************************************/

/************************************Timer 1*************************************/

//Timer0 Registers
#define TCCR1A        (*((volatile u8 *)0x4F))
#define TCCR1B        (*((volatile u8 *)0x4E))
  
#define TCNT1H        (*((volatile u8 *)0x4D))
#define TCNT1L        (*((volatile u8 *)0x4C))
#define TCNT1         (*((volatile u16 *)0x4C))

#define OCR1AH        (*((volatile u8 *)0x4B))
#define OCR1AL        (*((volatile u8 *)0x4A))
#define OCR1A         (*((volatile u16 *)0x4A))


#define OCR1BH        (*((volatile u8 *)0x49))
#define OCR1BL        (*((volatile u8 *)0x48))
#define OCR1B         (*((volatile u16 *)0x48))


#define ICR1H         (*((volatile u8 *)0x47))
#define ICR1L         (*((volatile u8 *)0x46))
#define ICR1          (*((volatile u16 *)0x46))

//TCCR1A register Bits
#define TCCR1A_WGM10     0x00
#define TCCR1A_WGM11     0x01
#define TCCR1A_FOC1B     0x02
#define TCCR1A_FOC1A     0x03
#define TCCR1A_COM1B0    0x04
#define TCCR1A_COM1B1    0x05
#define TCCR1A_COM1A0    0x06
#define TCCR1A_COM1A1    0x07


//TCCR1B register Bits
#define TCCR1B_CS10      0x00
#define TCCR1B_CS11      0x01
#define TCCR1B_CS12      0x02
#define TCCR1B_WGM12     0x03
#define TCCR1B_WGM13     0x04
//#define TCCR1B_ COM1B1    0x05 /* unimplemented*/
#define TCCR1B_ICES1     0x06
#define TCCR1B_ICNC1     0x07


//TIMSK register Bits
#define TIMSK_TOIE1      0x02
#define TIMSK_OCIE1B     0x03
#define TIMSK_OCIE1A     0x04
#define TIMSK_TICIE1     0x05

//TIFR register Bits
#define TIFR_TOV1       0x02
#define TIFR_OCF1B      0x03
#define TIFR_OCF1A      0x04
#define TIFR_ICF1       0x05



#endif //TIMERS_PRIVATE_H