/*
 * DC_Motor_Interface.h
 *
 *  Created on: Apr 7, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_

void DC_MOTOR_Init(void);

void DC_MOTOR_TURN_ON(const u8 Copy_u8_Direction);

void DC_MOTOR_TURN_OFF(void);

#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
