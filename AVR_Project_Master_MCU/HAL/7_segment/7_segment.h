/*
 * 7_segment.h
 *
 *  Created on: Mar 27, 2023
 *  Author       : Ahmed Abdalla
 */

#ifndef HAL_7_SEGMENT_7_SEGMENT_H_
#define HAL_7_SEGMENT_7_SEGMENT_H_
//#include  "../../LIB/STD_Types.h"
//#include  "../../LIB/BIT_MATH.h"


typedef struct
{
	u8 ports[4];
	u8 pin[4];
	u8 direction[4];
	u8 logic[4];
}seven_segment_t;


void seven_segment_void_Initialize(const seven_segment_t *segment);
void seven_segment_void_write(const seven_segment_t *segment , const u8 Copy_u8val);
#endif /* HAL_7_SEGMENT_7_SEGMENT_H_ */
