/*
 * EXTI_Private.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define  MCUCR              *((volatile u8*)0x55)
#define  MCUCSR             *((volatile u8*)0x54)
#define  GICR               *((volatile u8*)0x5b)  
#define  GIFR               *((volatile u8*)0x5a) 

#define GIE                 *((volatile u8*) 0x5f)// = 0b10000000;

/*interrupt bits at MCUCR */
#define MCUCR_ISC00               0
#define MCUCR_ISC01               1
#define MCUCR_ISC10               2
#define MCUCR_ISC11               3

/*interrupt bits at MCUCSR */
#define MCUCSR_ISC2                6

/*interrupt bits at GICR */
#define GICR_INT2                5
#define GICR_INT0                6
#define GICR_INT1                7

/*interrupt bits at GIFR */
#define GIFR_INTf2                5
#define GIFR_INTf0                6
#define GIFR_INTf1                7



#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
