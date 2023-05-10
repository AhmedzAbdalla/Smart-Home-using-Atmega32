/*
 * keypad_interface.h
 *
 *  Created on: Mar 29, 2023
 *  Author: Ahmed Abdalla
 * Version: 1.1
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

void keypad_void_init(void);

u8 keypad_u8_read_digit(void);

u16 keypad_u8_read_num(u16 *op);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
