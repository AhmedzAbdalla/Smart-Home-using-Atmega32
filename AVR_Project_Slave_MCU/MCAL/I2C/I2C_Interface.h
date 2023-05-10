/*
 * I2C_Interface.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Ahmed Abdalla
 */


#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#define frame_len		3

#define GET_TWSR_REG_VAL   (((*(volatile u8 *)(0x21))) & 0xF8)

typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteWithACKError,
	MasterReadByteWithACKError,
    Arbitration_lost_Error,
	SlaveReadByteWithACKError,
	
}TWI_ErrorStatus_t;

void TWI_void_Master_Init( const u8 Copy_u8Address);

void TWI_void_Slave_Init(const u8 Copy_u8Address);

TWI_ErrorStatus_t TWI_ErrorStatus_Send_Start_Condition_With_ACK(void);

TWI_ErrorStatus_t TWI_ErrorStatus_Send_Repeated_Start_Condition_With_ACK(void);


TWI_ErrorStatus_t TWI_ErrorStatus_Send_Slave_Address_With_Write_ACK(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus_t TWI_ErrorStatus_Send_Slave_Address_With_Read_ACK(const u8 Copy_u8SlaveAddress);

TWI_ErrorStatus_t TWI_ErrorStatus_Master_Write_Data_Byte_With_ACK(const u8 Copy_u8SendData);

TWI_ErrorStatus_t TWI_ErrorStatus_Master_Read_Data_Byte_With_ACK(u8 * Copy_u8ReadData);

TWI_ErrorStatus_t TWI_ErrorStatus_Slave_Read_Data_Byte( u8 *const Copy_u8ReadData);

TWI_ErrorStatus_t TWI_ErrorStatus_Slave_Write_Data_Byte( const u8 Copy_u8ReadData);



void TWI_void_Stop_Condition(void);


void TWI_void_get_frame_from_slave_MC(const u8 Copy_u8_slave_address , u8 * ref_u8ReadData , const u8 Copy_u8_op_code);

#endif  //I2C_INTERFACE_H
