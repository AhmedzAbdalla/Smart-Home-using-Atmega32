/*
 * I2C_Program.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Ahmed Abdalla
 */
#include <util/delay.h>

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "../../HAL/LCD/lcd_interface.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_cfg.h"

void TWI_void_Master_Init(const u8 Copy_u8Address)
{
    // Setting Acknowledgment bit
    SET_BIT(TWCR_REG , TWCR_TWEA);

    //Setting prescalar
    #if I2C_Prescalr == I2C_DIVISION_FACTOR_double_1
        TWSR_REG |= I2C_DIVISION_FACTOR_double_1;
    #elif I2C_Prescalr == I2C_DIVISION_FACTOR_double_4
        TWSR_REG |= I2C_DIVISION_FACTOR_double_4;
    #elif I2C_Prescalr == I2C_DIVISION_FACTOR_double_16
        TWSR_REG |= I2C_DIVISION_FACTOR_double_16;
    #elif I2C_Prescalr == I2C_DIVISION_FACTOR_double_64
        TWSR_REG |= I2C_DIVISION_FACTOR_double_64;
    #endif

    //setting TWI baud rate
    /*Set SCL frequency to 100KHz, with 8MHz system frequency*/
    TWBR_REG = 2;

    TWSR_REG |= I2C_DIVISION_FACTOR_double_1;
    //configuring address of master
    if(0 == Copy_u8Address )
    {
        /*Nothing*/
    }
    else
    {
        TWAR_REG = (Copy_u8Address << 1);
    }

    //Enabling TWI
    SET_BIT(TWCR_REG , TWCR_TWEN);
}

void TWI_void_Slave_Init(const u8 Copy_u8Address)
{
    // Setting Acknowledgment bit
    SET_BIT(TWCR_REG , TWCR_TWEA);

    //configuring address of master
    if(0 == Copy_u8Address )
    {
        /*Nothing*/
    }
    else
    {
        TWAR_REG = (Copy_u8Address << 1);
    }

    //Enabling TWI
    SET_BIT(TWCR_REG , TWCR_TWEN);

}

TWI_ErrorStatus_t TWI_ErrorStatus_Send_Start_Condition_With_ACK(void)
{
    TWI_ErrorStatus_t local_error_status = StartConditionError;

    //Sending Start Condition
    SET_BIT(TWCR_REG , TWCR_TWSTA);

    //Clearing TWI interrupt flag
    SET_BIT(TWCR_REG , TWCR_TWINT);

    //polling TWI interrupt flag
    while((READ_BIT(TWCR_REG , TWCR_TWINT)) == 0);
    
    if((TWSR_REG & STATUS_REG_MASK) != START_ACK)
    {
        /*Nothing*/
    }
    else
    {
        local_error_status = NoError;
    }
     
    return local_error_status;
}


TWI_ErrorStatus_t TWI_ErrorStatus_Send_Repeated_Start_Condition_With_ACK(void)
{
    TWI_ErrorStatus_t local_error_status = RepeatedStartError;
    
    //Sending Start Condition
    SET_BIT(TWCR_REG , TWCR_TWSTA);

    //	 TWI interrupt flag
    SET_BIT(TWCR_REG , TWCR_TWINT);

    //polling TWI interrupt flag
    while((READ_BIT(TWCR_REG , TWCR_TWINT)) == 0);

    if((TWSR_REG & STATUS_REG_MASK) != REPEATED_START_ACK)
    {
        /*Nothing*/
    }
    else
    {
        local_error_status = NoError;
    }
    return local_error_status;
}



TWI_ErrorStatus_t TWI_ErrorStatus_Send_Slave_Address_With_Write_ACK(u8 Copy_u8SlaveAddress)
{
    TWI_ErrorStatus_t local_error_status = SLA_W_NACK;

    //Writing slave address in TWAR_REG
    TWDR_REG = (Copy_u8SlaveAddress << 1);

    //Setting write operation
    CLR_BIT(TWDR_REG , 0 );

    //clearing start condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTA);

    //clearing stop condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTO);

    //clearing TWI Interrupt flag
    SET_BIT(TWCR_REG , TWCR_TWINT);

    //polling TWI Interrupt flag
    while((READ_BIT(TWCR_REG , TWCR_TWINT)) == 0);

    /*Check For The Condition Status Code*/
    if((TWSR_REG & STATUS_REG_MASK) == SLA_W_ACK)
    {
        local_error_status = NoError;
    }
    else if((TWSR_REG & STATUS_REG_MASK) == Arbitration_lost)
    {
        local_error_status = Arbitration_lost_Error;
    }
    else
    {
        /*nothing*/
    }
    return local_error_status;
}

TWI_ErrorStatus_t TWI_ErrorStatus_Send_Slave_Address_With_Read_ACK(const u8 Copy_u8SlaveAddress)
{
    TWI_ErrorStatus_t local_error_status = SLA_R_NACK;

    //Writing slave address in TWAR_REG
    TWDR_REG = (Copy_u8SlaveAddress << 1);

    //Setting Read operation
    SET_BIT(TWDR_REG , 0 );

    //clearing Start condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTA);

    //clearing Stop condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTO);

    //clearing TWI Interrupt flag
    SET_BIT(TWCR_REG , TWCR_TWINT);

    //polling TWI Interrupt flag
    while ((READ_BIT(TWCR_REG , TWCR_TWINT)) == 0);
    
    //Reading status code from TWSR_REG 

    if((TWSR_REG & STATUS_REG_MASK) == SLA_R_ACK)
    {
        local_error_status = NoError;
    }
    else if((TWSR_REG & STATUS_REG_MASK) == Arbitration_lost)
    {
        local_error_status = Arbitration_lost_Error;
    }
    else
    {
        /*nothing*/
    }
    return local_error_status;
}

TWI_ErrorStatus_t TWI_ErrorStatus_Master_Write_Data_Byte_With_ACK(const u8 Copy_u8SendData)
{
    TWI_ErrorStatus_t local_error_status = MasterWriteByteWithACKError;

    //Writing data in TWAR_REG
    TWDR_REG = (Copy_u8SendData);

    //clearing start condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTA);

    //clearing stop condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTO);

    //clearing TWI Interrupt flag
    SET_BIT(TWCR_REG , TWCR_TWINT);

    //polling TWI Interrupt flag
    while ((READ_BIT(TWCR_REG , TWCR_TWINT)) == 0);

    //Reading status code from TWSR_REG 
    if((TWSR_REG & STATUS_REG_MASK) == MSTR_W_BYTE_ACK)
    {
        local_error_status = NoError;
    }
    else if((TWSR_REG & STATUS_REG_MASK) == Arbitration_lost)
    {
        local_error_status = Arbitration_lost_Error;
    }
    else
    {
        /*nothing*/
    }
    
    return local_error_status;
}

TWI_ErrorStatus_t TWI_ErrorStatus_Master_Read_Data_Byte_With_ACK(u8 * Copy_u8ReadData)
{
    TWI_ErrorStatus_t  local_error_status = MasterReadByteWithACKError;

    // Setting Acknowledgment bit
    CLR_BIT(TWCR_REG , TWCR_TWEA);

    /*Clear The TWINT Flag, To Make The Slave To Send its Data*/
	SET_BIT(TWCR_REG , TWCR_TWINT);

    //polling TWI Interrupt flag
    while ((READ_BIT(TWCR_REG , TWCR_TWINT)) == 0);


    //Reading status code from TWSR_REG
    *Copy_u8ReadData = TWDR_REG; 

    if((TWSR_REG & STATUS_REG_MASK) == MSTR_R_BYTE_ACK)
    {
        local_error_status = NoError;
        
    }
    else if((TWSR_REG & STATUS_REG_MASK) == Arbitration_lost)
    {
        local_error_status = Arbitration_lost_Error;
    }
    else
    {
        /*nothing*/
    }
    
    return local_error_status;
}

void TWI_void_Stop_Condition(void)
{
    /*Send a stop condition on the bus*/
	SET_BIT(TWCR_REG , TWCR_TWSTO);

	/*Clear The TWINT Flag*/
	SET_BIT(TWCR_REG , TWCR_TWINT);
}


TWI_ErrorStatus_t TWI_ErrorStatus_Slave_Read_Data_Byte( u8 *const Copy_u8ReadData)
{
    TWI_ErrorStatus_t local_error_status = SlaveReadByteWithACKError;

    // Setting ACK
    SET_BIT(TWCR_REG , TWCR_TWEA);

    //clearing start condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTA);

    //clearing stop condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTO);

    /*Clear The TWINT Flag*/
	SET_BIT(TWCR_REG , TWCR_TWINT);

    while((READ_BIT(TWCR_REG , TWCR_TWINT)) == 0);

    if((TWSR_REG & STATUS_REG_MASK) == SLAVE_ADDRESS_R_RECEIEVED_WITH_ACK)
    {
        local_error_status = NoError;
        *Copy_u8ReadData  = TWDR_REG;
    }
    else
    {
        /*nothing*/
    }
    //TWDR_REG = 0;
    return local_error_status;
}


TWI_ErrorStatus_t TWI_ErrorStatus_Slave_Write_Data_Byte( const u8 Copy_u8ReadData)
{
    //
    SET_BIT(TWCR_REG , TWCR_TWEA);

    //clearing start condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTA);

    //clearing stop condition bit
    CLR_BIT(TWCR_REG , TWCR_TWSTO);

    /*Clear The TWINT Flag*/
	SET_BIT(TWCR_REG , TWCR_TWINT);

    while((READ_BIT(TWCR_REG , TWCR_TWINT)) == 0);

    if((TWSR_REG & STATUS_REG_MASK) == 0xA8)
    {
        //local_error_status = NoError;
        TWDR_REG = Copy_u8ReadData;
    }

}


void TWI_void_get_frame_from_slave_MC(const u8 Copy_u8_slave_address , u8 * ref_u8ReadData , const u8 Copy_u8_op_code)
{
    TWI_ErrorStatus_t local_error_status = SlaveReadByteWithACKError;
    u8 local_u8_data = 0;

    //sending start condition
    local_error_status = TWI_ErrorStatus_Send_Start_Condition_With_ACK();
    //selecting slave
    local_error_status = TWI_ErrorStatus_Send_Slave_Address_With_Write_ACK(Copy_u8_slave_address);

    
	if(GET_TWSR_REG_VAL == 0x18)
	{
        /*SLA+W has been transmitted;ACK has been received*/
		TWI_ErrorStatus_Master_Write_Data_Byte_With_ACK(Copy_u8_op_code);
	}

    /*cheching if Data byte[Copy_u8_op_code] has been transmitted ACK has been received*/
    	if(GET_TWSR_REG_VAL == 0x28)
		{	
			/*sending repeated start to switch*/
            TWI_ErrorStatus_Send_Repeated_Start_Condition_With_ACK();
            /*switching to master reciever mode*/
			TWI_ErrorStatus_Send_Slave_Address_With_Read_ACK(Copy_u8_slave_address);

            /*SLA+R has been transmitted ACK has been received*/
			if(GET_TWSR_REG_VAL == 0x40)
			{
				for(u8 counter = 0 ; counter <frame_len ; counter++)
				{
					_delay_us(150);
					TWI_ErrorStatus_Master_Read_Data_Byte_With_ACK(&local_u8_data);
					if(local_u8_data == 'C')
					{
						break;
					}
					else
					{
						ref_u8ReadData[counter] = local_u8_data;
					}

				}
				_delay_ms(100);
				
			}
		}

}
