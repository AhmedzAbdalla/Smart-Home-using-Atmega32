/*
 * EXTI_Private.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

/************************Timer 0 Interfaces****************************/
void Timer_0_void_Init(void);
void Timer_0_void_Set_Preload_val(const u8 Copy_u8_val);
void Timer_0_void_Set_OCR0_val(const u8 Copy_u8_val);

void set_TIMER_0_handler(void (*pf) (void));
void set_TIMER_0_OC0_handler(void (*pf) (void));
/************************End of Timer 0 Interfaces****************************/


/************************Timer 1 Interfaces****************************/
void Timer_1_void_Init(void);
void Timer_1_void_Set_Preload_val(const u16 Copy_u16_val);
void Timer_1_void_Set_ICR2_val(const u16 Copy_u16_val);
void Timer_1_void_Set_OCR1_A_val(const u16 Copy_u16_val);
void set_TIMER_1_handler(void (*pf) (void));

void Timer_1_void_delay_ms(const u16 Copy_u16_val);
/************************End of Timer 1 Interfaces****************************/



#endif //TIMERS_INTERFACE_H