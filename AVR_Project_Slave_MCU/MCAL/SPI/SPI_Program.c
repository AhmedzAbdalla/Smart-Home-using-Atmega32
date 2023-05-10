/*
 * SPI_Program.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Ahmed Abdalla
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_cfg.h"

void (*SPI_transfer_Handler) (void) = NULL;



void SPI_void_init(void)
{
    #if SPI_status == SPI_enable
         //Data order configuration
        #if SPI_data_order == SPI_MSB_first
            CLR_BIT(SPI_SPCR , SPCR_DORD);
        #elif SPI_data_order == SPI_LSB_first
            SET_BIT(SPI_SPCR , SPCR_DORD);
         #endif

         //SPI Mode Configuration [master/slave]
        #if SPI_mode == SPI_Master_mode
            SET_BIT(SPI_SPCR , SPCR_MSTR);
        #elif SPI_mode == SPI_Slave_mode
            CLR_BIT(SPI_SPCR , SPCR_MSTR);
        #endif

         // Clock Polarity Configuration

        #if Clock_Polarity == Leading_Edge_Rising 
            CLR_BIT(SPI_SPCR , SPCR_CPOL);
        #elif Clock_Polarity == Leading_Edge_Falling
            SET_BIT(SPI_SPCR , SPCR_CPOL);
        #endif

         // Clock Phase Configuration

        #if Clock_Phase == Leading_Edge_Setup 
            SET_BIT(SPI_SPCR , SPCR_CPHA);
        #elif Clock_Phase == Leading_Edge_Sample
            CLR_BIT(SPI_SPCR , SPCR_CPHA);
        #endif

         // Double SPI Speed Configuration

        #if speed_state == Speed_normal 
            CLR_BIT(SPI_SPSR , SPSR_SPI2X);

            //SPI Clock Rate Configuration
            #if Clock_Rate == SPI_DIVISION_FACTOR_normal_4
                CLR_BIT(SPI_SPCR , SPCR_SPR0);
                CLR_BIT(SPI_SPCR , SPCR_SPR1);
            #elif Clock_Rate == SPI_DIVISION_FACTOR_normal_16
                SET_BIT(SPI_SPCR , SPCR_SPR0);
                CLR_BIT(SPI_SPCR , SPCR_SPR1);
            #elif Clock_Rate == SPI_DIVISION_FACTOR_normal_64
                CLR_BIT(SPI_SPCR , SPCR_SPR0);
                SET_BIT(SPI_SPCR , SPCR_SPR1);
            #elif Clock_Rate == SPI_DIVISION_FACTOR_normal_128
                SET_BIT(SPI_SPCR , SPCR_SPR0);
                SET_BIT(SPI_SPCR , SPCR_SPR1);
            #endif


        #elif speed_state == Speed_double
            SET_BIT(SPI_SPSR , SPSR_SPI2X);
            //SPI Clock Rate Configuration
            #if Clock_Rate == SPI_DIVISION_FACTOR_double_2
                CLR_BIT(SPI_SPCR , SPCR_SPR0);
                CLR_BIT(SPI_SPCR , SPCR_SPR1);
            #elif Clock_Rate == SPI_DIVISION_FACTOR_double_8
                SET_BIT(SPI_SPCR , SPCR_SPR0);
                CLR_BIT(SPI_SPCR , SPCR_SPR1);
            #elif Clock_Rate == SPI_DIVISION_FACTOR_double_32
                CLR_BIT(SPI_SPCR , SPCR_SPR0);
                SET_BIT(SPI_SPCR , SPCR_SPR1);
            #elif Clock_Rate == SPI_DIVISION_FACTOR_double_64
                SET_BIT(SPI_SPCR , SPCR_SPR0);
                SET_BIT(SPI_SPCR , SPCR_SPR1);
            #endif
        #endif

        //SPI Interrupt Configuration
        #if SPI_Interrupt_status == SPI_Interrupt_disable
            CLR_BIT(SPI_SPCR , SPCR_SPIE);
        #elif SPI_Interrupt_status == SPI_Interrupt_enable
            SET_BIT(SPI_SPCR , SPCR_SPIE);
            //clear flag
            SET_BIT(SPI_SPSR , SPSR_SPIF);

        #endif


        /*at last enable the SPI*/
        SET_BIT(SPI_SPCR , SPCR_SPE);

    #elif SPI_status == SPI_disable
        CLR_BIT(SPI_SPCR , SPCR_SPE);
    #endif
}


void SPI_voidTransmit_bolcking(u8 Copy_u8Data)
{
	SPI_SPDR = Copy_u8Data;
	while((READ_BIT(SPI_SPSR ,SPSR_SPIF )) == 0);

}
void SPI_voidTransmit_non_bolcking(u8 Copy_u8Data)
{

}

void SPI_voidReceive_bolcking(u8* Copy_u8Data)
{
    //send dummy data
    //SPI_SPDR = 'k';
    while ((READ_BIT(SPI_SPSR ,SPSR_SPIF )) == 0);
    
    *Copy_u8Data = SPI_SPDR;
    
}

u8 SPI_get_data(void)
{
    return SPI_SPDR;
}

u8 SPI_voidReceive_non_bolcking(u8* Copy_u8Data)
{
    
}

void SPI_transfer_Set_ISR_Handler(void (*pf) (void))
{
    if(NULL == pf)
    {
        /*nothing*/
    }
    else
    {
        SPI_transfer_Handler = pf;
    }
}


//ISR for SPI
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	SPI_transfer_Handler();
}
