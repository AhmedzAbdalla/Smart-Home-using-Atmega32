/*
 * app.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Ahmed Abdalla
 */
#include <util/delay.h>
#include <math.h>

/*
#include  "../Free_RTOS/FreeRTOSConfig.h"
#include  "../Free_RTOS/FreeRTOS.h"
#include  "../Free_RTOS/croutine.h"
#include  "../Free_RTOS/list.h"
#include  "../Free_RTOS/macros.h"
#include  "../Free_RTOS/mpu_wrappers.h"
#include  "../Free_RTOS/portable.h"
#include  "../Free_RTOS/portmacro.h"
#include  "../Free_RTOS/projdefs.h"
#include  "../Free_RTOS/queue.h"
#include  "../Free_RTOS/semphr.h"
#include  "../Free_RTOS/StackMacros.h"
#include  "../Free_RTOS/task.h"
#include  "../Free_RTOS/timers.h"
*/
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/Timers/Timers_Interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/Watch_dog/Watch_dog_Interface.h"

#include "../HAL/LCD/lcd_interface.h"
#include "../HAL/LCD/lcd_cfg.h"
#include "../HAL/7_segment/7_segment.h"
#include "../HAL/Keypad/keypad_interface.h"
#include "../HAL/button/button_interface.h"
#include "../HAL/DC_Motor/DC_Motor_Interface.h"
#include "../HAL/Stepper_Motor/Stepper_motor_Interface.h"
#include "../HAL/EEPROM/EEPROM_Interface.h"
#include "../HAL/RTC_DS1307/RTC_DS1307_interface.h"

#include "app.h"
#define GIE_ENABLE() (*((volatile u8 *)0x5F)) = 0x80
#define GIE_DISABLE() (*((volatile u8 *)0x5F)) = 0x00

u8 data[6] = {0};

u8 pass_setup = 25;
u8 login_status = 0;
u16 password = 0;
u16 op = 0;
u16 option = 0;
u8 user_code = 0;
s32 main()
{
	//app_applications_init();
	lcd_void_lcd_init();
	keypad_void_init();

		/*SPI Operations*/
		DIO_void_Pin_Initialize(PORTB, PIN7, OUTPUT);
		DIO_void_Pin_Initialize(PORTB, PIN6, INPUT);
		DIO_void_Pin_Initialize(PORTB, PIN5, OUTPUT);
		DIO_void_Pin_Initialize(PORTB, PIN4, OUTPUT);

		SPI_void_init();
		TWI_void_Master_Init(0);

	//EEPROM_void_Send_Data_Byte(0x00,0);
		//EEPROM_void_Send_Data_Byte(0x00,0);
//		EEPROM_void_Send_Data_Byte(0x05,5);
//		EEPROM_void_Send_Data_Byte(0x06,4);
//		EEPROM_void_Send_Data_Byte(0x07,6);
//		EEPROM_void_Send_Data_Byte(0x08,2);
//		EEPROM_void_Send_Data_Byte(0x0a,4);
//		EEPROM_void_Send_Data_Byte(0x09,7);
//		EEPROM_void_Send_Data_Byte(0x0b,2);
//		EEPROM_void_Send_Data_Byte(0x0c,2);
//		EEPROM_void_Send_Data_Byte(0x0d,4);
//		EEPROM_void_Send_Data_Byte(0x0e,8);
//		EEPROM_void_Send_Data_Byte(0x0f,6);
//		EEPROM_void_Send_Data_Byte(0x10,6);
//		EEPROM_void_Send_Data_Byte(0x11,8);
//		EEPROM_void_Send_Data_Byte(0x12,2);
//		EEPROM_void_Send_Data_Byte(0x13,3);

	pass_setup = EEPROM_u8_Read_Data_Byte(0x00);
	while(1)
	{
			lcd_void_send_str_pos("1)Amr", ROW_1, 1);
			lcd_void_send_str_pos("2)ALI", ROW_1, 7);
			lcd_void_send_str_pos("3)MAI", ROW_2, 1);
			lcd_void_send_str_pos("4)RANA", ROW_2, 7);
			lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_ON_CHAR_BLINK_ON);
			lcd_void_send_char_pos('>' , ROW_2 , 14);
			user_code = keypad_u8_read_num(&op);
			if((user_code == 0) || (user_code >4))
			{
				lcd_void_send_command(_LCD_CLEAR);
				lcd_void_send_command(0x80);
				_delay_ms(20);
				lcd_void_send_str_pos("Invalid user" , ROW_2, 1 );
				_delay_ms(20);
				lcd_void_send_str_pos("Invalid user" , ROW_2, 1 );
				_delay_ms(2000);
				lcd_void_send_command(0x80);
				lcd_void_send_command(_LCD_CLEAR);
			}
			else
			{
				break;
			}
	}


	if(pass_setup == 0 )
	{
		//the password length is 4 digits only

		lcd_void_send_str("Setup password");
		lcd_void_send_command(0xc0);
		lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_ON_CHAR_BLINK_ON);
		password = keypad_u8_read_num(&op);

		if(op == 99)
		{
			EEPROM_void_write_4digit_num(password);
			EEPROM_void_Send_Data_Byte(0x00,1);
			lcd_void_send_command(_LCD_CLEAR);
			lcd_void_send_str_pos("Restart Me", 2, 4);
			while(1);

		}
	}
	else
	{
		u16 pass = 0;

		EEPROM_void_read_4digit_num(&pass , user_code);
		lcd_void_send_str_pos("Enter Password" , ROW_1 , 1);
		_delay_ms(2000);
		login_status =app_u16_Get_Pass(pass);

	}
	if(login_status == 33)
	{
		lcd_void_send_str_pos("Restart Me", 2, 4);
		while(1);
	}
	else
	{
		switch(user_code)
		{
		case 1:
			lcd_void_send_str_pos("Welcome Amr", 2, 1);
			break;
		case 2:
			lcd_void_send_str_pos("Welcome ALI", 2, 1);
			break;
		case 3:
			lcd_void_send_str_pos("Welcome MAI", 2, 1);
			break;
		case 4:
			lcd_void_send_str_pos("Welcome RANA", 2, 1);
			break;

		default:
			break;
		}
		//lcd_void_send_command(_LCD_CLEAR);
		//lcd_void_send_str_pos("Welcome ya User", 2, 1);
	}
	while(1)
	{
		_delay_ms(1000);

		RTC_DS1307_RTC_t_Get_Date_Time(data);
		RTC_DS1307_RTC_t_Get_Date_Time(data);
		RTC_DS1307_RTC_t_Get_Date_Time(data);

		RTC_DS1307_RTC_t_Print_Date_Time(data);
		RTC_DS1307_RTC_t_Print_Date_Time(data);

		_delay_ms(2000);

		while(1)
		{
			lcd_void_send_command(_LCD_CLEAR);
			lcd_void_send_str_pos("1)PumpOn", ROW_1, 1);
			lcd_void_send_str_pos("2)PumpOFF", ROW_2, 1);
			lcd_void_send_str_pos(" 3)GetTemp", ROW_1, 8);
			lcd_void_send_str_pos("1)PumpOn", ROW_1, 1);
			_delay_ms(10);
			lcd_void_send_str_pos("2)PumpOFF", ROW_2, 1);
			_delay_ms(10);
			lcd_void_send_str_pos(" 3)GetTemp", ROW_1, 8);
			_delay_ms(10);
			lcd_void_send_command(0x80);
			lcd_void_send_command(_LCD_DISPLAY_ON_CURSOR_ON_CHAR_BLINK_ON);
			//lcd_void_send_command(_LCD_CLEAR);
			//lcd_void_send_command(0x80);
			option = keypad_u8_read_num(&op);
			if(option == 0 || option >3)
			{
				lcd_void_send_command(_LCD_CLEAR);
				lcd_void_send_command(0x80);
				lcd_void_send_str_pos("Invalid option" , ROW_1, 1 );

				_delay_ms(2000);
				lcd_void_send_command(0x80);
				lcd_void_send_command(_LCD_CLEAR);
			}
			else
			{
				break;
			}
		}


		switch(option)
		{
		DIO_void_Pin_Write_Logic(PORTB, PIN4, LOW);
		case 1:
			_delay_ms(150);
			SPI_voidTransmit_bolcking(0x01);
			break;
	//activating slave 1

		case 2:
			_delay_ms(150);
			SPI_voidTransmit_bolcking(0x02);
			//_delay_ms(60);
			//SPI_voidTransmit_bolcking(0x04);
			lcd_void_send_command(_LCD_CLEAR);
			lcd_void_send_str_pos("temp:", ROW_1, 1);
			lcd_void_send_num_pos((*((volatile u8*)0x2F)), ROW_2, 2);
			lcd_void_send_char_pos(223 , ROW_2 , 4);
			lcd_void_send_char_pos('C' , ROW_2 , 5);
			_delay_ms(5000);
			break;
		default:
			break;
		}


		//lcd_void_send_command(_LCD_CLEAR);

		_delay_ms(500);


	}
	return 0;
}

void app_applications_init(void)
{

}
