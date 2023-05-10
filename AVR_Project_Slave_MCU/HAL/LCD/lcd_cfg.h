/*
 * lcd_cfg.h
 *
 *  Created on: Mar 28, 2023
 *      Author: hamad
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

/*Row and Column value*/
#define ROW_1 (u8)1
#define ROW_2 (u8)2
/*Column values range 1:16*/

/*Control port and pins*/
#define lcd_CR 				PORTB

#define RS 						PIN5
#define RW 					PIN6
#define EN						PIN7

/*8-bit Data port*/
#define lcd_DR 				PORTA

/*LCD Macro Configuration */

/*Display Clear Control*/
#define _LCD_CLEAR																		0x01

/*Display Return Home*/
#define _LCD_RETRUN_HOME															0x02

/*Function Set Control*/
#define _LCD_8BIT_1_LINE_MODE 													0x30
#define _LCD_8BIT_2_LINE_MODE 													0x38

#define _LCD_4BIT_1_LINE_MODE 													0x20
#define _LCD_4BIT_2_LINE_MODE 													0x28

/*Display ON/OFF Control*/
#define _LCD_DISPLAY_ON_CURSOR_OFF_CHAR_BLINK_OFF 			0x0C
#define _LCD_DISPLAY_ON_CURSOR_ON_CHAR_BLINK_OFF			0x0E
#define _LCD_DISPLAY_ON_CURSOR_ON_CHAR_BLINK_ON			0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF_CHAR_BLINK_OFF			0x08


/*Entry Mode Set*/
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF									0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON									0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF									0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON									0X07

/*Cursor or Display Shift*/
#define _LCD_DISPLAY_SHIFT_LEFT													0X18
#define _LCD_DISPLAY_SHIFT_RIGHT												0X1C

#endif /* HAL_LCD_LCD_CFG_H_ */
