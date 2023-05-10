/*
 * USART_Private.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ahmed Abdalla
 */

//USART Registers
#define USART_UDR                    (*((volatile u8*)0x2C))
#define USART_UCSRA                  (*((volatile u8*)0x2B))
#define USART_UCSRB                  (*((volatile u8*)0x2A))
#define USART_UCSRC                  (*((volatile u8*)0x40))
#define USART_UBRRH                  (*((volatile u8*)0x40))
#define USART_UBRRL                  (*((volatile u8*)0x29))

//UCSRA Bits
#define UCSRA_MPCM     0x00
#define UCSRA_U2X      0x01
#define UCSRA_PE       0x02
#define UCSRA_DOR      0x03
#define UCSRA_FE       0x04
#define UCSRA_UDRE     0x05
#define UCSRA_TXC      0x06
#define UCSRA_RXC      0x07


//UCSRB Bits
#define UCSRB_TXB8     0x00
#define UCSRB_RXB8     0x01
#define UCSRB_UCSZ2    0x02
#define UCSRB_TXEN     0x03
#define UCSRB_RXEN     0x04
#define UCSRB_UDRIE    0x05
#define UCSRB_TXCIE    0x06
#define UCSRB_RXCIE    0x07


//UCSRC Bits
#define UCSRC_UCPOL     0x00
#define UCSRC_UCSZ0     0x01
#define UCSRC_UCSZ1     0x02
#define UCSRC_USBS      0x03
#define UCSRC_UPM0      0x04
#define UCSRC_UPM1      0x05
#define UCSRC_UMSEL     0x06
#define UCSRC_URSEL     0x07

