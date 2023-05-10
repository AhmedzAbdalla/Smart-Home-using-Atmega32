/*
 * EXTI_Program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Ahmed Abdalla
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

void (*EXTI_0_handler)(void) = NULL;
void (*EXTI_1_handler)(void) = NULL;
void (*EXTI_2_handler)(void) = NULL;


void EXTI_void_EXTI_init(void)
{

    #if INT_ENABLE == INT0
        
        SET_BIT(GICR , GICR_INT0); /**Enable PIE for EXTI 0*/
        DIO_void_Pin_Initialize(PORTD , PIN2 , INPUT);/*Set pin as input*/
        SET_BIT(GIFR , GIFR_INTf0);
        #if INT_SENSE_CONTROL == FALLING_EDGE
            DIO_void_Pin_Write_Logic(PORTD , PIN2 , HIGH);/*Set pull up resistance to use falling edge only*/
            CLR_BIT(MCUCR , MCUCR_ISC00);
            SET_BIT(MCUCR , MCUCR_ISC01);
        #elif INT_SENSE_CONTROL == RISING_EDGE
            SET_BIT(MCUCR , MCUCR_ISC00);
            SET_BIT(MCUCR , MCUCR_ISC01);
        #elif INT_SENSE_CONTROL == LOW_LEVEL
            CLR_BIT(MCUCR , MCUCR_ISC00);
            CLR_BIT(MCUCR , MCUCR_ISC01);
        #elif INT_SENSE_CONTROL == ON_CHANGE
            SET_BIT(MCUCR , MCUCR_ISC00);
            CLR_BIT(MCUCR , MCUCR_ISC01);
        #endif
    #elif INT_ENABLE == INT1
        SET_BIT(GICR , GICR_INT1);/**Enable PIE for EXTI 1*/
        DIO_void_Pin_Initialize(PORTD , PIN3 , INPUT);/*Set pin as input*/
        SET_BIT(GIFR , GIFR_INTf1);
        #if INT_SENSE_CONTROL == FALLING_EDGE
            DIO_void_Pin_Write_Logic(PORTD , PIN3 , HIGH);/*Set pull up resistance to use falling edge only*/
            CLR_BIT(MCUCR , MCUCR_ISC10);
            SET_BIT(MCUCR , MCUCR_ISC11);
        #elif INT_SENSE_CONTROL == RISING_EDGE
            SET_BIT(MCUCR , MCUCR_ISC10);
            SET_BIT(MCUCR , MCUCR_ISC11);
        #elif INT_SENSE_CONTROL == LOW_LEVEL
            CLR_BIT(MCUCR , MCUCR_ISC10);
            CLR_BIT(MCUCR , MCUCR_ISC11);
        #elif INT_SENSE_CONTROL == ON_CHANGE
            SET_BIT(MCUCR , MCUCR_ISC10);
            CLR_BIT(MCUCR , MCUCR_ISC11);
        #endif
    #elif INT_ENABLE == INT2
        SET_BIT(GICR , GICR_INT2);/**Enable PIE for EXTI 2*/
        DIO_void_Pin_Initialize(PORTB , PIN2 , INPUT);
        SET_BIT(GIFR , GIFR_INTf2);
        #if INT_SENSE_CONTROL == FALLING_EDGE
            DIO_void_Pin_Write_Logic(PORTB , PIN2 , HIGH);/*Set pull up resistance to use falling edge only*/
            CLR_BIT(MCUCSR , MCUCSR_ISC2);
        #elif INT_SENSE_CONTROL == RISING_EDGE
            SET_BIT(MCUCSR , MCUCSR_ISC2);
		#endif
    #endif
}

void EXTI_void_EXTI_enable(u8 Copy_u8_EXTI_ID ,u8 Copy_u8_EXTI_Sense )
{
    if((Copy_u8_EXTI_ID >2) || (Copy_u8_EXTI_Sense >3))
    {
        /*NOTHING*/
    }
    else
    {
        //Clear all flags


	    //SET_BIT(GIFR , GIFR_INTf1);
        switch (Copy_u8_EXTI_ID)
        {
        case INT0:
            SET_BIT(GICR , GICR_INT0); /*Enable PIE for external int0*/
            SET_BIT(GIFR , GIFR_INTf0);//clear flag
            DIO_void_Pin_Initialize(PORTD , PIN2 , INPUT); /*Seting pin 2 at portd as input*/
            switch (Copy_u8_EXTI_Sense)
            {
            case FALLING_EDGE:
                DIO_void_Pin_Write_Logic(PORTD , PIN2 , HIGH);/*Set pull up resistance to use falling edge only*/
                CLR_BIT(MCUCR , MCUCR_ISC00);
                SET_BIT(MCUCR , MCUCR_ISC01);
                break;
            case RISING_EDGE:
            	SET_BIT(MCUCR , MCUCR_ISC00);
                SET_BIT(MCUCR , MCUCR_ISC01);
                break;
            case LOW_LEVEL:
                CLR_BIT(MCUCR , MCUCR_ISC00);
                CLR_BIT(MCUCR , MCUCR_ISC01);
                break;
            case ON_CHANGE:  
                SET_BIT(MCUCR , MCUCR_ISC00);
                CLR_BIT(MCUCR , MCUCR_ISC01);
                break;
            default:
                break;
            }
            break;
        case INT1:
            SET_BIT(GICR , GICR_INT1); /*Enable PIE for external int1*/
            DIO_void_Pin_Initialize(PORTD , PIN3 , INPUT); /*Seting pin 3 at portd as input*/
            SET_BIT(GIFR , GIFR_INTf1);//clear flag
            switch (Copy_u8_EXTI_Sense)
            {
            case FALLING_EDGE:
                DIO_void_Pin_Write_Logic(PORTD , PIN3 , HIGH);/*Set pull up resistance to use falling edge only*/
                CLR_BIT(MCUCR , MCUCR_ISC10);
                SET_BIT(MCUCR , MCUCR_ISC11);
                break;
            case RISING_EDGE:
            	SET_BIT(MCUCR , MCUCR_ISC10);
                SET_BIT(MCUCR , MCUCR_ISC11);
                break;
            case LOW_LEVEL:
                CLR_BIT(MCUCR , MCUCR_ISC10);
                CLR_BIT(MCUCR , MCUCR_ISC11);
                break;
            case ON_CHANGE:  
                SET_BIT(MCUCR , MCUCR_ISC10);
                CLR_BIT(MCUCR , MCUCR_ISC11);
                break;
            default:
                break;
            }
            break;
        case INT2:
            SET_BIT(GICR , GICR_INT2); /*Enable PIE for external int2*/
            DIO_void_Pin_Initialize(PORTB , PIN2 , INPUT); /*Seting pin 2 at portb as input*/
            SET_BIT(GIFR , GIFR_INTf2);//clear flag
            switch (Copy_u8_EXTI_Sense)
            {
            case FALLING_EDGE:
                DIO_void_Pin_Write_Logic(PORTB , PIN2 , HIGH);/*Set pull up resistance to use falling edge only*/
                CLR_BIT(MCUCSR , MCUCSR_ISC2);
                break;
            case RISING_EDGE:
                SET_BIT(MCUCSR , MCUCSR_ISC2);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void EXTI_void_EXTI_clear_flags(void)
{
	SET_BIT(GIFR , GIFR_INTf0);
	SET_BIT(GIFR , GIFR_INTf1);
	SET_BIT(GIFR , GIFR_INTf2);
}

/*====================================================================================*/
void set_EXTI_0_handler(void (*pf) (void))
{
	if(NULL != pf)
	{
		EXTI_0_handler = pf;
	}

}
void set_EXTI_1_handler(void (*pf) (void))
{
	if(NULL != pf)
	{
			EXTI_1_handler = pf;
	}

}
void set_EXTI_2_handler(void (*pf) (void))
{
	if(NULL != pf)
	{
			EXTI_2_handler = pf;
	}

}

//===============================================
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(NULL != EXTI_0_handler)
		{
			EXTI_0_handler();
			SET_BIT(GIFR , GIFR_INTf0);
		}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(NULL !=EXTI_1_handler )
	{
		EXTI_1_handler();
		SET_BIT(GIFR , GIFR_INTf1);
	}

}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(NULL !=EXTI_2_handler )
	{
		EXTI_2_handler();
		SET_BIT(GIFR , GIFR_INTf2);
	}

}

