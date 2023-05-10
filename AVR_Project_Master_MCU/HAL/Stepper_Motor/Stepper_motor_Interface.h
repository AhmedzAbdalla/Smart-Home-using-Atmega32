/*
 * Stepper_motor_Interface.h
 *
 *  Created on: Apr 7, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_

void Stepper_MOTOR_Init(void);

void Stepper_MOTOR_TURN_ON(const u8 Copy_u8_Direction , const u16 Copy_u16_Angle);

void Stepper_MOTOR_TURN_OFF(void);


#endif /* HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_ */
