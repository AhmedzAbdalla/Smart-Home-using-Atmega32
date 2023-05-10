/*
 * BIT_MATH.h
 *
 *  Created on: Mar 27, 2023
 *      Author: hamad
 */

#ifndef HEADER_FILES_BIT_MATH_H_
#define HEADER_FILES_BIT_MATH_H_

#define BIT_MASK (u8)0x01

#define SET_BIT(REG , POS) 	 	(REG|=(1<<POS))
#define CLR_BIT(REG , POS)  	(REG&=(~(1<<POS)))
#define Toggle_BIT(REG , POS)   (REG^=(1<<POS))
#define READ_BIT(REG , POS) 	((REG>>POS) & BIT_MASK)

#endif /* HEADER_FILES_BIT_MATH_H_ */
