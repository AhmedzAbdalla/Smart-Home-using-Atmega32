/*
 * DC_Motor_Program.h
 *
 *  Created on: Apr 7, 2023
 *      Author: Ahmed Abdalla
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "DC_Motor_Interface.h"
#include "DC_Motor_cfg.h"

void DC_MOTOR_Init(void)
{
	DIO_void_Pin_Initialize(DC_MOTOR_PORT, CONTROL_0, OUTPUT);
	DIO_void_Pin_Initialize(DC_MOTOR_PORT, CONTROL_1, OUTPUT);
}


void DC_MOTOR_TURN_ON(const u8 Copy_u8_Direction)
{
	switch(Copy_u8_Direction)
	{
	case ANTI_CLOCK_WISE:
		DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, CONTROL_0, HIGH);
		DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, CONTROL_1, LOW);
		break;
	case CLOCK_WISE:
		DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, CONTROL_0, LOW);
		DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, CONTROL_1, HIGH);
		break;
	default:
		break;
	}
}


void DC_MOTOR_TURN_OFF(void)
{
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, CONTROL_0, LOW);
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, CONTROL_1, LOW);
}
