/*
 * SPI_cfg.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Ahmed Abdalla
 */


//SPI opertaion status

#define SPI_disable                        0x00
#define SPI_enable                         0x01

#define SPI_status       SPI_enable

//Data order configuration

#define SPI_MSB_first                      0x00
#define SPI_LSB_first                      0x01

#define SPI_data_order  SPI_MSB_first

//SPI Mode Configuration [master/slave]
/*If SS is configured as an input and is driven low while MSTR is set, MSTR will be cleared,
and SPIF in SPSR will become set. The user will then have to set MSTR to re-enable SPI Master mode.*/

#define SPI_Slave_mode                     0x00
#define SPI_Master_mode                    0x01

#define SPI_mode      SPI_Slave_mode

// Clock Polarity Configuration
/**Clock state when during Idle state*/
#define Leading_Edge_Rising                0x00 //Trailing_Edge_Falling [in case no active data transmission the CLK is logic low ]
#define Leading_Edge_Falling               0x01 //Trailing_Edge_Rising

#define  Clock_Polarity          Leading_Edge_Rising 

// Clock Phase Configuration
/*determines when the spi reads(samples) bits and when to setup bit to be sent out*/

#define Leading_Edge_Sample                0x00 //Trailing_Edge_Setup [spi reads bit at leading edge]
#define Leading_Edge_Setup                 0x01 //Trailing_Edge_Sample[spi (prepares)setup bit to be sent out]

#define Clock_Phase             Leading_Edge_Setup

//SPI Clock Rate Configuration

//Normal speed  SPI2X = 0
#define SPI_DIVISION_FACTOR_normal_4       0x00
#define SPI_DIVISION_FACTOR_normal_16      0x01
#define SPI_DIVISION_FACTOR_normal_64      0x02
#define SPI_DIVISION_FACTOR_normal_128     0x03

//Double speed  SPI2X = 1
#define SPI_DIVISION_FACTOR_double_2       0x00
#define SPI_DIVISION_FACTOR_double_8       0x01
#define SPI_DIVISION_FACTOR_double_32      0x02
#define SPI_DIVISION_FACTOR_double_64      0x03

#define Clock_Rate      SPI_DIVISION_FACTOR_normal_64

// Double SPI Speed Configuration

#define Speed_normal                       0x00
#define Speed_double                       0x01

#define speed_state     Speed_normal

//SPI Interrupt Configuration

#define SPI_Interrupt_disable              0x00
#define SPI_Interrupt_enable               0x01

#define SPI_Interrupt_status    SPI_Interrupt_enable
