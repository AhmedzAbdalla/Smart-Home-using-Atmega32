/*
 * I2C_Private.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef I2C_PPRIVATE_H
#define I2C_PPRIVATE_H

#define TWCR_REG   ((*(volatile u8 *)(0x56))) //TWI Control Register
#define TWDR_REG   ((*(volatile u8 *)(0x23))) //TWI Data Register
#define TWAR_REG   ((*(volatile u8 *)(0x22))) //TWI [Slave] Address Register
#define TWSR_REG   ((*(volatile u8 *)(0x21))) //TWI Status Register
#define TWBR_REG   ((*(volatile u8 *)(0x20))) //TWI Bit Rate Register

//TWCR REG Bits
#define TWCR_TWIE       0x0
#define TWCR_TWEN       0x2
#define TWCR_TWWC       0x3
#define TWCR_TWSTO      0x4
#define TWCR_TWSTA      0x5
#define TWCR_TWEA       0x6
#define TWCR_TWINT      0x7


//TWSR REG Bits
#define TWSR_TWPS0      0x0
#define TWSR_TWPS1      0x1


//TWAR REG Bits
#define TWGCE_BIT    0


/************************ Status Code***********************/


//status code for Master Transmitter mode
#define START_ACK               0x08
#define REPEATED_START_ACK      0x10
#define SLA_W_ACK               0x18
#define SLA_W_NACK              0x20
#define MSTR_W_BYTE_ACK         0x28
#define MSTR_W_BYTE_NACK        0x30
#define Arbitration_lost        0x38

//status code for Master reciever mode
#define SLA_R_ACK               0x40
#define SLA_R_NACK              0x48     
#define MSTR_R_BYTE_ACK         0x50
#define MSTR_R_BYTE_NACK        0x58


//status code for slave reciever mode
#define SLAVE_ADDRESS_W_RECEIEVED_WITH_ACK    0X60
#define SLAVE_ADDRESS_R_RECEIEVED_WITH_ACK    0X80



//==========================================
#define STATUS_REG_MASK         0xF8

#endif //I2C_PPRIVATE_H