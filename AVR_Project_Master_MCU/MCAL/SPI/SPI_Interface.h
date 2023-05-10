/*
 * SPI_Inteface.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Ahmed Abdalla
 */


void SPI_void_init(void);

void SPI_voidTransmit_bolcking(u8 Copy_u8Data);
void SPI_voidTransmit_non_bolcking(u8 Copy_u8Data);

void SPI_voidReceive_bolcking(u8* Copy_u8Data);
u8 SPI_voidReceive_non_bolcking(u8* Copy_u8Data);

void SPI_void_set_master(void);
void SPI_void_set_slave(void);


/*
use this function in interrupt handler to action on the receieved data every spi transfer
*/
u8 SPI_get_data(void);

//put dummy data in SPI_SPDR register after reading it 


void SPI_transfer_Set_ISR_Handler(void (*pf) (void));
