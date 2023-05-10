/*
 * 7_segment.h
 *
 *  Created on: Mar 27, 2023
 *  Author       : Ahmed Abdalla
 */

/********************Includes********************/
#include  "../../LIB/STD_Types.h"
#include  "../../LIB/BIT_MATH.h"


#include "../../MCAL/DIO/DIO_Interface.h"
#include "7_segment.h"


void seven_segment_void_Initialize(const seven_segment_t *segment)
{

	DIO_void_Pin_Initialize(segment->ports[0] , segment->pin[0] , segment->direction[0]);
	DIO_void_Pin_Initialize(segment->ports[1] , segment->pin[1] , segment->direction[1]);
	DIO_void_Pin_Initialize(segment->ports[2] , segment->pin[2] , segment->direction[2]);
	DIO_void_Pin_Initialize(segment->ports[3] , segment->pin[3] , segment->direction[3]);
}


void seven_segment_void_write(const seven_segment_t *segment , const u8 Copy_u8val)
{
	DIO_void_Pin_Write_Logic(segment->ports[0] , segment->pin[0] ,Copy_u8val>>0 & (0x01));
	DIO_void_Pin_Write_Logic(segment->ports[1] , segment->pin[1] ,Copy_u8val>>1 & (0x01) );
	DIO_void_Pin_Write_Logic(segment->ports[2] , segment->pin[2] ,Copy_u8val>>2 & (0x01) );
	DIO_void_Pin_Write_Logic(segment->ports[3] , segment->pin[3] ,Copy_u8val>>3 & (0x01) );
}
