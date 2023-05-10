/*
 * EEPROM_Program.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Ahmed Abdalla
 */
#include <util/delay.h>

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/I2C/I2C_Interface.h"
#include "../LCD/lcd_interface.h"
#include "../LCD/lcd_cfg.h"
#include "../Keypad/keypad_interface.h"

#include "EEPROM_Interface.h"
#include "EEPROM_cfg.h"
#include "EEPROM_Private.h"

void EEPROM_void_Send_Data_Byte(const u16 Copy_u16LocationAddress,const u8 Copy_u8DataByte)
{
    TWI_ErrorStatus_t status = 0;
    u8 Local_u8_add = EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (Copy_u16LocationAddress >> 8);

    //sending start condition
    status |= TWI_ErrorStatus_Send_Start_Condition_With_ACK();

    //selecting the EEPROM as slave
    status |= TWI_ErrorStatus_Send_Slave_Address_With_Write_ACK(Local_u8_add);

    // sending the rest of of location address 
    status |= TWI_ErrorStatus_Master_Write_Data_Byte_With_ACK((u8)Copy_u16LocationAddress);

    //sending the data to be stored 
    status |= TWI_ErrorStatus_Master_Write_Data_Byte_With_ACK(Copy_u8DataByte);

    //sending the stop condition
    TWI_void_Stop_Condition();

    //Delay until the write cycle is finished
	_delay_ms(10);

}



u8 EEPROM_u8_Read_Data_Byte(u16 Copy_u16LocationAddress)
{
    u8 local_u8_data = 0;
    TWI_ErrorStatus_t status = 0;
    u8 Local_u8_add = EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (Copy_u16LocationAddress >> 8);

    //sending start condition
    status |= TWI_ErrorStatus_Send_Start_Condition_With_ACK();

    //selecting the EEPROM as slave
    status |= TWI_ErrorStatus_Send_Slave_Address_With_Write_ACK(Local_u8_add);

    // sending the rest of of location address 
    status |= TWI_ErrorStatus_Master_Write_Data_Byte_With_ACK((u8)Copy_u16LocationAddress);

    //Sending repeated start condition to switch from write mode to read mode
    status |= TWI_ErrorStatus_Send_Repeated_Start_Condition_With_ACK();

    //Send the address packet with read request
    status |=TWI_ErrorStatus_Send_Slave_Address_With_Read_ACK(Local_u8_add);

    //reading data from EEPROM
    status |= TWI_ErrorStatus_Master_Read_Data_Byte_With_ACK(&local_u8_data);

    //sending stop condition
    TWI_void_Stop_Condition();

    //Delay until the write cycle is finished
	_delay_ms(20);

    return local_u8_data;
}

//========================================
void EEPROM_void_write_4digit_num( u16 Copy_u16_num )
{
	for(u8 counter = 5 ; counter > 0; counter--)
	{
		EEPROM_void_Send_Data_Byte(counter - 1 , Copy_u16_num %(10 )  );
		Copy_u16_num = Copy_u16_num / 10;
	}
}

void EEPROM_void_read_4digit_num(  u16 *const ref_u16_num , u8 Copy_u8_user_code)
{
			u16 power = 1;
			u16 pass = 0;
			u8 num = 0;
			for(int i =0 ; i<4 ; i++)
			{
				for(u8 j = 1 ; j <(4 -i ) ; j++)
				{
					power = power *10;
				}
				num = EEPROM_u8_Read_Data_Byte((4 * Copy_u8_user_code) + i);
				pass += num *power;
				power = 1;
			}
			*ref_u16_num = pass;
}

u8 app_u16_Get_Pass(u16 Copy_u16_num)
{
		u8 status = 55;
		u16 op = 1;
		u16 entered_pass = 1234;
		lcd_void_send_command(_LCD_CLEAR);
		//lcd_void_send_str_pos("Welcome ya User" , ROW_1 , 1);
		//_delay_ms(500);
		lcd_void_send_command(_LCD_CLEAR);
		lcd_void_send_str_pos("Enter Password" , ROW_1 , 1);
		lcd_void_send_command( (0xc0));
		lcd_void_send_str_pos("Enter Password" , ROW_1 , 1);
		lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_ON_CHAR_BLINK_ON);

		for(u8 counter = 0; counter <3 ; counter++)
		{
			entered_pass = keypad_u8_read_num(&op);
			if(entered_pass == Copy_u16_num)
			{
				status = 44;
				lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_OFF_CHAR_BLINK_OFF);
				break;
			}
			else
			{
				lcd_void_send_command(_LCD_CLEAR);
				lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_OFF_CHAR_BLINK_OFF);
				lcd_void_send_str_pos("Wrong" , ROW_1 , 1);
				_delay_ms(300);
				lcd_void_send_command(_LCD_CLEAR);
				lcd_void_send_str_pos("Enter Password" , ROW_1 , 1);
				lcd_void_send_command( (0xc0));
				lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_ON_CHAR_BLINK_ON);

			}
			if(counter == 2)
			{
				lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_OFF_CHAR_BLINK_OFF);
				status = 33;
				lcd_void_send_command(_LCD_CLEAR);
				lcd_void_send_str_pos("7ramy" , ROW_1 , 1);
				_delay_ms(3000);
			}
		}
		op=0;
		return status;
}
