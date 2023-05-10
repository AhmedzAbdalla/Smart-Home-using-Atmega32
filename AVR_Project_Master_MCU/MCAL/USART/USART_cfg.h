/*
 * USART_cfg.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ahmed Abdalla
 */



//USART Operation control
#define TX_enable       0x01
#define TX_disable      0x00

#define TX_state        TX_enable


#define RX_enable       0x01
#define RX_disable      0x00

#define RX_state        RX_enable


//USART MODE
#define Asynchronous_mode       0x01
#define Synchronous_mode        0x00

#define USART_MODE              Asynchronous_mode

//USART speed
#define Speed_double            0x01
#define Speed_normal            0x00

#define USART_speed             Speed_normal


//USART Parity Mode
#define Parity_Disabled         0x00
#define Parity_Even             0x02
#define Parity_Odd              0x03

#define USART_Parity            Parity_Disabled

//USARt Stop Bit Select
#define Stop_1bit               0x00
#define Stop_2bit               0x01

#define USART_Stop_bit          Stop_1bit

//Character Size
#define Char_5_bit              0x00
#define Char_6_bit              0x01
#define Char_7_bit              0x02
#define Char_8_bit              0x03
#define Char_9_bit              0x07 //UCSZ2=1 UCSZ1=1 UCSZ0=1

#define character_size          Char_9_bit

//configuring Multi_processor_comm_
#define Multi_processor_comm_enable         0x01
#define Multi_processor_comm_disable        0x00

#define Multi_processor_comm_state          Multi_processor_comm_disable

//configuring baudrate for freq = 8 MHz and normal speed
#define Baud_rate_9600bps       51
#define Baud_rate_4800bps       103

#define baud_rate               Baud_rate_9600bps

//transmit interrupt configuration
#define TX_interrupt_enable      0x01
#define TX_interrupt_disable     0x00

#define TX_interrupt_state       TX_interrupt_enable


//recieeve interrupt configuration
#define RX_interrupt_enable      0x01
#define RX_interrupt_disable     0x00

#define RX_interrupt_state       RX_interrupt_enable

//UCPOL Bit Settings This bit is used for Synchronous mode only. Write this bit to zero when Asynchronous mode isused.
/**Out of scope*/