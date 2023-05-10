/*
 * lcd_program.c
 *
 *  Created on: Mar 28, 2023
 *  Author: hamad
 *  version 1.2
 */

#include <util/delay.h>
#include  "../../LIB/STD_Types.h"
#include  "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "lcd_interface.h"
#include "lcd_cfg.h"

/******************************************************************/
/*Func. Name: lcd_void_lcd_init                  							  */
/*i/p arguments: void                                      					  */
/*return: void                                                  						  */
/******************************************************************/
void lcd_void_lcd_init(void)
{

	DIO_void_Pin_Initialize( lcd_CR, RS ,OUTPUT ); //initialize RS pin as output
	DIO_void_Pin_Initialize( lcd_CR, RW ,OUTPUT );//initialize RW pin as output
	DIO_void_Pin_Initialize( lcd_CR, EN ,OUTPUT );//initialize EN pin as output

	DIO_void_PORT_Direction_Initialize(PORTC , 0xff); // initialize port as output

	/*Starting the initializing Process*/

	_delay_ms(40);
	lcd_void_send_command(_LCD_8BIT_2_LINE_MODE);

	_delay_us(50);
	lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_OFF_CHAR_BLINK_OFF);

	_delay_us(50);
	lcd_void_send_command(_LCD_CLEAR);

	_delay_ms(5);
	lcd_void_send_command(_LCD_ENTRY_MODE_INC_SHIFT_OFF);
}

/******************************************************************/
/*Func. Name: lcd_void_send_command                  			  */
/*i/p arguments: Copy_u8_command                                    */
/*return: void                                                  						  */
/******************************************************************/
void lcd_void_send_command(u8 Copy_u8_command)
{

	/*Writing logic low  to RS to send command*/
	DIO_void_Pin_Write_Logic(lcd_CR, RS , LOW);

	/*Writing logic low  to RW to Write command*/
	DIO_void_Pin_Write_Logic(lcd_CR, RW , LOW);

	/*Writing 8-bit data to data port*/
	DIO_void_PORT_Write_Logic(lcd_DR , Copy_u8_command);

	/*Sending Falling signal to Enable command */
	DIO_void_Pin_Write_Logic(lcd_CR, EN , HIGH);
	_delay_us(5);
	DIO_void_Pin_Write_Logic(lcd_CR, EN , LOW);
}


/******************************************************************/
/*Func. Name: lcd_void_send_char                  			 		      */
/*i/p arguments: Copy_u8_char                                 		   		   */
/*Version: 1.1                                    										   	*/
/*return: void                                                  						 		 */
/******************************************************************/
void lcd_void_send_char(u8 Copy_u8_char)
{
	static u8 local_u8_exceed_row1 = 0;
	static u8 local_u8_exceed_row2 = 0;
	/*Writing logic low  to RS to send data*/
	DIO_void_Pin_Write_Logic(lcd_CR, RS , HIGH);

	/*Writing logic low  to RW to Write command*/
	DIO_void_Pin_Write_Logic(lcd_CR, RW , LOW);

	/*Writing 8-bit data to data port*/

	DIO_void_PORT_Write_Logic(lcd_DR , Copy_u8_char);


	/*Sending Falling signal to Enable command */
	DIO_void_Pin_Write_Logic(lcd_CR, EN , HIGH);
	_delay_us(5);
	DIO_void_Pin_Write_Logic(lcd_CR, EN , LOW);

	// counting number of busy segment on row one
	local_u8_exceed_row1++;
	// if row1 is complete so modify address counter of DDRAM to 0xC0 (Row 2)
	if(local_u8_exceed_row1 >15)
		{
			lcd_void_send_command( (0xc0) + local_u8_exceed_row2 );
			// counting number of busy segment on row two
			local_u8_exceed_row2++;
		}

	// if row2 is complete so modify address counter of DDRAM to 0x80 (Row 1)
	if(local_u8_exceed_row2 >17)
	{
		//clearing Display
		lcd_void_send_command(_LCD_CLEAR);
		lcd_void_send_command(0x80 );
		//clear local_u8_exceed_row1
		//local_u8_exceed_row2
		local_u8_exceed_row1 = 0;
		local_u8_exceed_row2 = 0;
	}

}


/************************************************************************/
/*Func. Name: lcd_void_send_char_pos                  			 		       */
/*i/p arguments: Copy_u8_char , Copy_u8_row , Copy_u8_Column*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_char_pos(u8 Copy_u8_char , u8 Copy_u8_row , u8 Copy_u8_Column )
{
	//decrementing column because it is zero indexed
	Copy_u8_Column--;

	//Validation of row and column
	if((Copy_u8_row >1) || (Copy_u8_Column>16))
	{
		/*Nothing*/
	}
	{
		switch(Copy_u8_row)
		{
		case ROW_1:
			//sending command to adjust DDRAM address counter
			lcd_void_send_command( (0x80) +Copy_u8_Column );
			//sending character normally
			lcd_void_send_char(Copy_u8_char);
			break;
		case ROW_2:
			//sending command to adjust DDRAM address counter
			lcd_void_send_command( (0xc0) +Copy_u8_Column );
			//sending character normally
			lcd_void_send_char(Copy_u8_char);
			break;

		}
	}
}

/*************************************************************************/
/*Func. Name: lcd_void_send_str                  			 		       			*/
/*i/p arguments: Ref_u8_str																*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_str(s8 *Ref_u8_str)
{
	//looping until dereferencing termination character
	while(*Ref_u8_str)
	{
		lcd_void_send_char(*Ref_u8_str++);
	}
}


/*************************************************************************/
/*Func. Name: lcd_void_send_str_pos                  			 		       	*/
/*i/p arguments: Ref_u8_str	, Copy_u8_row	, Copy_u8_Column		*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_str_pos(s8 *Ref_u8_str , u8 Copy_u8_row , u8 Copy_u8_Column)
{
	//looping until dereferencing termination character
	while(*Ref_u8_str)
		{
		// Sending each character using lcd_void_send_char_pos and post-incrementing the column
			lcd_void_send_char_pos(*Ref_u8_str++ , Copy_u8_row , Copy_u8_Column++);
		}
}



/*************************************************************************/
/*Func. Name: lcd_void_send_num                  			 		       		*/
/*i/p arguments: Copy_u8_char														*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_num(u16 Copy_u8_char)
{
	//array to store each digit in a number as character
	u8 temp[6] = {'\0','\0','\0','\0','\0','\0'};
	u8 counter = 0;
	if(Copy_u8_char == 0)
	{
		lcd_void_send_char(0x30);
	}
	while(Copy_u8_char !=0)
	{
		temp[counter] = Copy_u8_char % 10;
		//lcd_void_send_char((temp[counter] + 0x30)); //sending digit as character
		Copy_u8_char = Copy_u8_char / 10;
		counter++;
	}
	for(s8 i = counter-1; i>=0 ; i--)
	{
		lcd_void_send_char((temp[i] + 0x30));
	}
}


/*************************************************************************/
/*Func. Name: lcd_void_send_num_pos                  			 		       	*/
/*i/p arguments: Copy_u8_char , Copy_u8_row , 	Copy_u8_Column	*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_num_pos(u16 Copy_u8_char , u8 Copy_u8_row , u8 Copy_u8_Column)
{
	u8 temp[6] = {'\0','\0','\0','\0','\0','\0'};
	u8 counter = 0;
if(Copy_u8_char == 0)
{
	lcd_void_send_char_pos( 0x30 ,Copy_u8_row , Copy_u8_Column++ );
}
	while(Copy_u8_char !=0)
	{
		temp[counter] = Copy_u8_char % 10;
		//lcd_void_send_char_pos( (temp[counter] + 0x30) ,Copy_u8_row  , Copy_u8_Column++); //sending digit as character
		Copy_u8_char = Copy_u8_char / 10;
		counter++;
	}
	for(s8 i = counter-1; i>=0 ; i--)
	{
		lcd_void_send_char_pos((temp[i] + 0x30) ,Copy_u8_row , Copy_u8_Column++ );
	}

}



/*************************************************************************/
/*Func. Name: lcd_void_send_custom_char                  			 		 */
/*i/p arguments: ref_u8_char , lcd_void_send_custom_char 			*/
 /*  					  Copy_u8_row , Copy_u8_Column							*/
/*return: void                                                  								   */
/************************************************************************/
void lcd_void_send_custom_char(u8 *ref_u8_char, u8 Copy_u8_seq ,u8 Copy_u8_row , u8 Copy_u8_Column)
{
	//send command to access CGRAM and initializing  the address counter to the address of CGRAM
	lcd_void_send_command( 0x40 + (Copy_u8_seq * 8) );

	//looping to send and store 8 bytes of custom character in CGRAM
	for(u8 counter = 0 ; counter <=7 ; counter++)
	{
		lcd_void_send_char(*(ref_u8_char + counter));
	}

	//READING the memory of CGRAM and passing arguments to set address counter to the address of custom character in CGRAM
	lcd_void_send_char_pos(Copy_u8_seq , Copy_u8_row , Copy_u8_Column);
}
