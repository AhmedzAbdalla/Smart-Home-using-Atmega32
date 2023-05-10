/*
 * RTC_DS1307_program.c
 *
 *  Created on: Apr 27, 2023
 *      Author: Ahmed Abdalla
 */
//#include <util/delay.h>

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/I2C/I2C_Interface.h"

#include "../../HAL/LCD/lcd_interface.h"

#include "RTC_DS1307_Interface.h"
#include "RTC_DS1307_cfg.h"
#include "RTC_DS1307_Private.h"

//static RTC_t Static_RTC_t_my_RTC;

void RTC_DS1307_RTC_t_Get_Date_Time(u8 *const Ref_u8_ret_rtc )
{
    for(u8 counter = 0 ; counter<6 ; counter++)
    {
        //sending repeated start
        TWI_ErrorStatus_Send_Start_Condition_With_ACK();

        TWI_ErrorStatus_Send_Slave_Address_With_Write_ACK(RTC_DS1307_address);
        if(counter >= 3)
        {
            TWI_ErrorStatus_Master_Write_Data_Byte_With_ACK(SECONDS_REG + counter + 1);
        }
        else
        {
            TWI_ErrorStatus_Master_Write_Data_Byte_With_ACK(SECONDS_REG + counter);
        }
        


        TWI_ErrorStatus_Send_Repeated_Start_Condition_With_ACK();
        //sending slave address
        TWI_ErrorStatus_Send_Slave_Address_With_Read_ACK(RTC_DS1307_address);

        //reading seconds from RTC
        TWI_ErrorStatus_Master_Read_Data_Byte_With_ACK(Ref_u8_ret_rtc + counter );

        //_delay_us(100);
        //sending stop condition
        TWI_void_Stop_Condition();
    }
    

}


void RTC_DS1307_RTC_t_Print_Date_Time(u8 *const Ref_RTC_t_ret_rtc )
{

	//clear dispaly
	lcd_void_send_command(0x01);
    //print date info on first line
    lcd_void_send_str_pos("date:", ROW_1, ROW_1);
    lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[3] >>BCD_LOW_NIBBLE_MASK ), ROW_1, 6 );
	lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[3] & BCD_HIGH_NIBBLE_MASK ), ROW_1,7);
    lcd_void_send_char_pos('-', ROW_1, 8);
    lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[4] >>BCD_LOW_NIBBLE_MASK ), ROW_1, 9 );
	lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[4] & BCD_HIGH_NIBBLE_MASK ), ROW_1,10);
    lcd_void_send_char_pos('-', ROW_1, 11);
    lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[5] >>BCD_LOW_NIBBLE_MASK ), ROW_1, 12 );
	lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[5] & BCD_HIGH_NIBBLE_MASK ), ROW_1,13);

    //print time info on first line
    lcd_void_send_str_pos("Time:", ROW_2, ROW_1);
    lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[2] >>BCD_LOW_NIBBLE_MASK ), ROW_2, 6 );
	lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[2] & BCD_HIGH_NIBBLE_MASK ), ROW_2,7);
    lcd_void_send_char_pos('-', ROW_2, 8);
    lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[1] >>BCD_LOW_NIBBLE_MASK ), ROW_2, 9 );
	lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[1] & BCD_HIGH_NIBBLE_MASK ), ROW_2,10);
    lcd_void_send_char_pos('-', ROW_2, 11);
    lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[0] >>BCD_LOW_NIBBLE_MASK ), ROW_2, 12 );
	lcd_void_send_num_pos((Ref_RTC_t_ret_rtc[0] & BCD_HIGH_NIBBLE_MASK ), ROW_2,13);
}
