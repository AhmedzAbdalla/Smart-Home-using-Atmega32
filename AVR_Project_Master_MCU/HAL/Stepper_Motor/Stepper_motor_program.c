/*
 * Stepper_motor_program.c
 *
 *  Created on: Apr 7, 2023
 *      Author: Ahmed Abdalla
 */
#include <util/delay.h>

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Stepper_motor_Interface.h"
#include "Stepper_motor_cfg.h"

void Stepper_MOTOR_Init(void)
{
	DIO_void_Pin_Initialize(DC_MOTOR_PORT , CONTROL_0 , OUTPUT);
	DIO_void_Pin_Initialize(DC_MOTOR_PORT , CONTROL_1 , OUTPUT);
	DIO_void_Pin_Initialize(DC_MOTOR_PORT , CONTROL_2 , OUTPUT);
	DIO_void_Pin_Initialize(DC_MOTOR_PORT , CONTROL_3 , OUTPUT);
}


void Stepper_MOTOR_TURN_ON(const u8 Copy_u8_Direction , const u16 Copy_u16_Angle)
{
	u16 iterator =(u16)(Copy_u16_Angle/0.175)/4 ;

	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT , CONTROL_0 , HIGH);
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT , CONTROL_1 , HIGH);
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT , CONTROL_2 , HIGH);
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT , CONTROL_3 , HIGH);
	if(Copy_u8_Direction == ANTI_CLOCK_WISE)
	{
		for(u16 counter = 0 ; counter < iterator ; counter++ )
		{
			for(u8 k = 0 ; k<4 ; k++)
			{
				DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, k, (0x0E >> k) & 0x01);
			}
			_delay_ms(10);

			for(u8 k = 0 ; k<4 ; k++)
			{
					DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, k, (0x0D >> k) & 0x01);
			}
			_delay_ms(10);

			for(u8 k = 0 ; k<4 ; k++)
			{
				DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, k, (0x0B >> k) & 0x01);
			}
			_delay_ms(10);

			for(u8 k = 0 ; k<4 ; k++)
			{
				DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, k, (0x07 >> k) & 0x01);
			}
			_delay_ms(10);
		}
	}
	else if(Copy_u8_Direction == CLOCK_WISE)
	{
		for(u16 counter = 0 ; counter < iterator ; counter++)
		{
			for(u8 k = 0 ; k<4 ; k++)
			{
				DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, k, (0x07 >> k) & 0x01);
			}
			_delay_ms(10);

			for(u8 k = 0 ; k<4 ; k++)
			{
				DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, k, (0x0B >> k) & 0x01);
			}
			_delay_ms(10);

			for(u8 k = 0 ; k<4 ; k++)
			{
					DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, k, (0x0D >> k) & 0x01);
			}
			_delay_ms(10);

			for(u8 k = 0 ; k<4 ; k++)
			{
				DIO_void_Pin_Write_Logic(DC_MOTOR_PORT, k, (0x0E >> k) & 0x01);
			}
			_delay_ms(10);
		}
	}
}


void Stepper_MOTOR_TURN_OFF(void)
{
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT , CONTROL_0 , HIGH);
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT , CONTROL_1 , HIGH);
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT , CONTROL_2 , HIGH);
	DIO_void_Pin_Write_Logic(DC_MOTOR_PORT , CONTROL_3 , HIGH);
}
