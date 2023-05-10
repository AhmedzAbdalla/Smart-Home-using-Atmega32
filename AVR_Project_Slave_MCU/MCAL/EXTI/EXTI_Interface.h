/*
 * EXTI_Interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_




void EXTI_void_EXTI_init(void);
void EXTI_void_EXTI_enable(u8 Copy_u8_EXTI_ID ,u8 Copy_u8_EXTI_Sense );
void EXTI_void_EXTI_disable(u8 Copy_u8_EXTI_ID );
void EXTI_void_EXTI_clear_flags(void);


void set_EXTI_0_handler(void (*pf) (void));
void set_EXTI_1_handler(void (*pf) (void));
void set_EXTI_2_handler(void (*pf) (void));


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
