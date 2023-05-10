/*
 * EEPROM_Interface.h
 *
 *  Created on: Apr 18, 2023
 *      Author: Ahmed Abdalla
 */


#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H


void EEPROM_void_Send_Data_Byte(const u16 Copy_u16LocationAddress,const u8 Copy_u8DataByte);

u8 EEPROM_u8_Read_Data_Byte(const u16 Copy_u16LocationAddress);

void EEPROM_void_write_4digit_num( u16 Copy_u16_num);

void EEPROM_void_read_4digit_num(  u16 *const ref_u16_num ,  u8 Copy_u8_user_code);

u8 app_u16_Get_Pass(u16 Copy_u16_num);

#endif //EEPROM_INTERFACE_H
