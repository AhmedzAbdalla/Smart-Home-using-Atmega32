/*
 * USART_Program.c
 *
 *  Created on: Apr 12, 2023
 *      Author: Ahmed Abdalla
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_cfg.h"


void (*UART_transmit_Handler) (void) = NULL;
void (*UART_receive_Handler) (void) = NULL;

void UART_voidInit()
{
    #if TX_state == TX_enable || RX_state == RX_enable

        //configuring buadrate
        // The URSEL must be zero when writing the UBRRH.
        CLR_BIT(USART_UCSRC , UCSRC_URSEL);

        #if USART_speed == Speed_normal
            CLR_BIT(USART_UCSRA , UCSRA_U2X);
            #if baud_rate == Baud_rate_9600bps
                USART_UBRRL = (u8)Baud_rate_9600bps;
                USART_UBRRH = (u8)(Baud_rate_9600bps>>8);
            #elif baud_rate == Baud_rate_4800bps
                USART_UBRRL = (u8)Baud_rate_4800bps;
                USART_UBRRH = (u8)(Baud_rate_4800bps>>8);

            #endif
        #elif USART_speed == Speed_double
            SET_BIT(USART_UCSRA , UCSRA_U2X);
        #endif


        //The URSEL must be one when writing the UCSRC.
        SET_BIT(USART_UCSRC , UCSRC_URSEL);


        //configuring USART mode
        #if USART_MODE == Asynchronous_mode
            CLR_BIT(USART_UCSRC , UCSRC_UMSEL);
            CLR_BIT(USART_UCSRC , UCSRC_UCPOL);
        #elif USART_MODE == Synchronous_mode
            SET_BIT(USART_UCSRC , UCSRC_UMSEL);
        #endif

        //confuring parity
        #if USART_Parity == Parity_Disabled
            CLR_BIT(USART_UCSRC , UCSRC_UPM0);
            CLR_BIT(USART_UCSRC , UCSRC_UPM1);
        #elif USART_Parity == Parity_Even
            CLR_BIT(USART_UCSRC , UCSRC_UPM0);
            SET_BIT(USART_UCSRC , UCSRC_UPM1);
        #elif USART_Parity == Parity_Odd
            SET_BIT(USART_UCSRC , UCSRC_UPM0);
            SET_BIT(USART_UCSRC , UCSRC_UPM1);
        #endif

        //configuring stop bits
        #if USART_Stop_bit == Stop_1bit
            CLR_BIT(USART_UCSRC , UCSRC_USBS);
        #elif USART_Stop_bit == Stop_2bit
            SET_BIT(USART_UCSRC , UCSRC_USBS);
        #endif

        //configuring charcater size
        #if character_size ==Char_9_bit
            SET_BIT(USART_UCSRC ,UCSRC_UCSZ0);
            SET_BIT(USART_UCSRC ,UCSRC_UCSZ1);
            SET_BIT(USART_UCSRB ,UCSRB_UCSZ2);
        #elif character_size == Char_5_bit
            CLR_BIT(USART_UCSRC ,UCSRC_UCSZ0);
            CLR_BIT(USART_UCSRC ,UCSRC_UCSZ1);
            CLR_BIT(USART_UCSRB ,UCSRB_UCSZ2);
        #elif character_size == Char_6_bit
            SET_BIT(USART_UCSRC ,UCSRC_UCSZ0);
            CLR_BIT(USART_UCSRC ,UCSRC_UCSZ1);
            CLR_BIT(USART_UCSRB ,UCSRB_UCSZ2);
        #elif character_size == Char_7_bit
            CLR_BIT(USART_UCSRC ,UCSRC_UCSZ0);
            SET_BIT(USART_UCSRC ,UCSRC_UCSZ1);
            CLR_BIT(USART_UCSRB ,UCSRB_UCSZ2);
        #elif character_size == Char_8_bit
            SET_BIT(USART_UCSRC ,UCSRC_UCSZ0);
            SET_BIT(USART_UCSRC ,UCSRC_UCSZ1);
            CLR_BIT(USART_UCSRB ,UCSRB_UCSZ2);
        #endif

        //configuring Multi processor communication
        #if Multi_processor_comm_state == Multi_processor_comm_enable
            SET_BIT(USART_UCSRA , UCSRA_MPCM);
        #elif Multi_processor_comm_state == Multi_processor_comm_disable
            CLR_BIT(USART_UCSRA , UCSRA_MPCM);
        #endif

        SET_BIT(USART_UCSRA , UCSRA_TXC);
        SET_BIT(USART_UCSRA , UCSRA_RXC);
        SET_BIT(USART_UCSRA , UCSRA_UDRE);
        
    #endif

    #if RX_state == RX_enable
        SET_BIT(USART_UCSRB , UCSRB_RXEN);
        //configuring RX Interrupt
        #if RX_interrupt_state == RX_interrupt_enable
            SET_BIT(USART_UCSRB , UCSRB_RXCIE);
        #elif RX_interrupt_state == RX_interrupt_disable
            CLR_BIT(USART_UCSRB , UCSRB_RXCIE);
        #endif
    #elif RX_state == RX_disable
        CLR_BIT(USART_UCSRB , UCSRB_RXEN);
    #endif
    
    #if TX_state == TX_enable
            SET_BIT(USART_UCSRB , UCSRB_TXEN);
        //configuring TX Interrupt
        #if TX_interrupt_state == TX_interrupt_enable
            SET_BIT(USART_UCSRB , UCSRB_TXCIE);
        #elif TX_interrupt_state == TX_interrupt_disable
            CLR_BIT(USART_UCSRB , UCSRB_TXCIE);
        #endif
    #elif TX_state == TX_disable
        CLR_BIT(USART_UCSRB , UCSRB_TXEN);
    #endif

    //SET_BIT(USART_UCSRB , UCSRB_TXCIE);
    //SET_BIT(USART_UCSRB , UCSRB_RXCIE);
}
void UART_voidTransmit_bolcking(u8 Copy_u8Data)
{
    #if TX_state == TX_enable
        //poll until the shift register is empty 
        while((READ_BIT(USART_UCSRA , UCSRA_UDRE)) == 0);

        USART_UDR = Copy_u8Data;

    //clear flag
        SET_BIT(USART_UCSRA , UCSRA_TXC);
    #endif
    
}

void UART_voidTransmit_non_bolcking(u8 Copy_u8Data)
{
    #if TX_state == TX_enable
         
        if((READ_BIT(USART_UCSRA , UCSRA_UDRE)) == 1)
        {
            //poll until the shift register is empty
            USART_UDR = Copy_u8Data;
             //clear flag
            SET_BIT(USART_UCSRA , UCSRA_TXC);
            //SET_BIT(USART_UCSRA , UCSRA_UDRE);
        }
    #endif
}

void UART_voidReceive_bolcking(u8* Copy_u8Data)
{
    #if RX_state == RX_enable
        if(NULL != Copy_u8Data)
        {
            //polling until the recieve flag is set
            while((READ_BIT(USART_UCSRA , UCSRA_RXC)) == 0);

            //retrieve data 
            *Copy_u8Data = USART_UDR;
        }
     
    #endif
    
}

u8 UART_voidReceive_non_bolcking(u8* Copy_u8Data)
{
    u8 ret = 0;
    #if RX_state == RX_enable
        if(NULL != Copy_u8Data)
        {
            //polling until the recieve flag is set
            if((READ_BIT(USART_UCSRA , UCSRA_RXC)) == 1)
            {
                 //retrieve data 
                *Copy_u8Data = USART_UDR;
                ret = 1;
            }
            else
            {
                ret = 0;
            }
        }
     
    #endif
        return ret ;
}

u8 UART_u8_Get_UDRE_reg()
{
    return (*((volatile u8*)0x2C));
}
void UART_transmit_Set_ISR_Handler(void (*pf) (void))
{
    if(NULL == pf)
    {
        /*nothing*/
    }
    else
    {
        UART_transmit_Handler = pf;
    }
}

void UART_receieve_Set_ISR_Handler(void (*pf) (void))
{
    if(NULL == pf)
    {
        /*nothing*/
    }
    else
    {
        UART_receive_Handler = pf;
    }
}
//ISR for USART, Tx Complete
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	UART_transmit_Handler();
    //clear flag
            SET_BIT(USART_UCSRA , UCSRA_TXC);
            SET_BIT(USART_UCSRA , UCSRA_UDRE);
}


//ISR for USART, Tx Complete
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	UART_receive_Handler();
    //clear flag
    SET_BIT(USART_UCSRA , UCSRA_RXC);
}
