/*
 * SPI_Private.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Ahmed Abdalla
 */


//SPI Registers

#define SPI_SPCR        (*((volatile u8*)0x2D))
#define SPI_SPSR        (*((volatile u8*)0x2E))
#define SPI_SPDR        (*((volatile u8*)0x2F))


//SPI_SPCR Bits

#define SPCR_SPR0       0x00
#define SPCR_SPR1       0x01
#define SPCR_CPHA       0x02
#define SPCR_CPOL       0x03
#define SPCR_MSTR       0x04
#define SPCR_DORD       0x05
#define SPCR_SPE        0x06
#define SPCR_SPIE       0x07


//SPI_SPSR Bits

#define SPSR_SPI2X      0x00
#define SPSR_WCOL       0x06
#define SPSR_SPIF       0x07