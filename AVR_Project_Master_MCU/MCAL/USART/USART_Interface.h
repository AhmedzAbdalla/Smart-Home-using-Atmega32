/*
 * USART_Interface.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ahmed Abdalla
 */

void UART_voidInit();

void UART_voidTransmit_bolcking(u8 Copy_u8Data);
void UART_voidTransmit_non_bolcking(u8 Copy_u8Data);

void UART_voidReceive_bolcking(u8* Copy_u8Data);
u8 UART_voidReceive_non_bolcking(u8* Copy_u8Data);

/*
this fnuction must be used when enabling the interrupt for RX so that the MCU can read next tranmitted data
*/
u8 UART_u8_Get_UDRE_reg(); 

void UART_transmit_Set_ISR_Handler(void (*pf) (void));
void UART_receieve_Set_ISR_Handler(void (*pf) (void));


