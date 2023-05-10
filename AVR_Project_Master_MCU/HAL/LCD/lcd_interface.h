/*
 * lcd_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: hamad
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_



/******************************************************************/
/*Func. Name: lcd_void_lcd_init                  							  */
/*i/p arguments: void                                      					  */
/*return: void                                                  						  */
/******************************************************************/
void lcd_void_lcd_init(void);


/******************************************************************/
/*Func. Name: lcd_void_send_command                  			  */
/*i/p arguments: Copy_u8_command                                    */
/*return: void                                                  						  */
/******************************************************************/
void lcd_void_send_command(u8 Copy_u8_command);


/******************************************************************/
/*Func. Name: lcd_void_send_char                  			 		      */
/*i/p arguments: Copy_u8_char                                 		      */
/*return: void                                                  						  */
/******************************************************************/
void lcd_void_send_char(u8 Copy_u8_char);


/************************************************************************/
/*Func. Name: lcd_void_send_char_pos                  			 		       */
/*i/p arguments: Copy_u8_char , Copy_u8_row , Copy_u8_Column*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_char_pos(u8 Copy_u8_char , u8 Copy_u8_row , u8 Copy_u8_Column );


/*************************************************************************/
/*Func. Name: lcd_void_send_str                  			 		       			*/
/*i/p arguments: Ref_u8_str																*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_str(s8 *Ref_u8_str);


/*************************************************************************/
/*Func. Name: lcd_void_send_str_pos                  			 		       	*/
/*i/p arguments: Ref_u8_str	, Copy_u8_row	, Copy_u8_Column		*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_str_pos(s8 *Ref_u8_str , u8 Copy_u8_row , u8 Copy_u8_Column);


/*************************************************************************/
/*Func. Name: lcd_void_send_num                  			 		       		*/
/*i/p arguments: Copy_u8_char														*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_num(u16 Copy_u8_char);

/*************************************************************************/
/*Func. Name: lcd_void_send_num_pos                  			 		       	*/
/*i/p arguments: Copy_u8_char , Copy_u8_row , 	Copy_u8_Column	*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_num_pos(u16 Copy_u8_char , u8 Copy_u8_row , u8 Copy_u8_Column);


/*************************************************************************/
/*Func. Name: lcd_void_send_custom_char                  			 		 */
/*i/p arguments: ref_u8_char , lcd_void_send_custom_char 			*/
 /*  					  Copy_u8_row , Copy_u8_Column							*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_custom_char(u8 *ref_u8_char, u8 lcd_void_send_custom_char ,u8 Copy_u8_row , u8 Copy_u8_Column);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
