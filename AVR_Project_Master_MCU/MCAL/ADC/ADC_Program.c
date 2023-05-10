/*
 * EXTI_Config.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Ahmed Abdalla
 */
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

static void ADC_void_Set_prescalar(const u8 Copy_u8_prescalar);

void ADC_VOID_Init(void)
{
	#if ADC_POWER == ADC_ON
        //ADC is working
        SET_BIT(ADCSRA , ADCSRA_ADEN);
        //Configuring Reference voltage
		#if Voltage_Reference == AVCC
			SET_BIT(ADMUX , ADMUX_REFS0);
			CLR_BIT(ADMUX , ADMUX_REFS1);
        #elif Voltage_Reference == AREF
            CLR_BIT(ADMUX , ADMUX_REFS0);
            CLR_BIT(ADMUX , ADMUX_REFS1);
        #elif Voltage_Reference == Internal_2_56v
            SET_BIT(ADMUX , ADMUX_REFS0);
            SET_BIT(ADMUX , ADMUX_REFS1);

		#endif

        //Configuring justification
        #if justification == Left_justified 
            SET_BIT(ADMUX , ADMUX_ADLAR);
        #elif justification == Right_justified
            CLR_BIT(ADMUX , ADMUX_ADLAR);
        #endif

        //Configuring ADC_AUTO_TRIGGER_STATE
        #if ADC_AUTO_TRIGGER_STATE == ADC_AUTO_TRIGGER_OFF
            CLR_BIT(ADCSRA , ADCSRA_ADATE);
        #elif ADC_AUTO_TRIGGER_STATE == ADC_AUTO_TRIGGER_ON
            CLR_BIT(ADCSRA , ADCSRA_ADATE);
        #endif

        //Configuring PIE 
        #if PIE_STATE == ADC_INTERRUPT_ENABLE
            CLR_BIT(ADCSRA , ADCSRA_ADIE);
        #elif PIE_STATE == ADC_INTERRUPT_DISABLE
            SET_BIT(ADCSRA , ADCSRA_ADIE);
        #endif

        //Configuring ADC Prescalar
        switch (Prescalar)
        {
        case DIVISION_FACTOR_2:
            ADC_void_Set_prescalar(DIVISION_FACTOR_2);
            break;
        case DIVISION_FACTOR_4:
            ADC_void_Set_prescalar(DIVISION_FACTOR_4);
            break;
        case DIVISION_FACTOR_8:
            ADC_void_Set_prescalar(DIVISION_FACTOR_8);
            break;
        case DIVISION_FACTOR_16:
            ADC_void_Set_prescalar(DIVISION_FACTOR_16);
            break;
        case DIVISION_FACTOR_32:
            ADC_void_Set_prescalar(DIVISION_FACTOR_32);
            break;
        case DIVISION_FACTOR_64:
            ADC_void_Set_prescalar(DIVISION_FACTOR_64);
            break;
        case DIVISION_FACTOR_128:
            ADC_void_Set_prescalar(DIVISION_FACTOR_128);
            break;
        default:
            break;
        }


	#endif
}

u16 ADC_u16_Get_Read(u8 copy_u8_ch_sel)
{
    //Clear MUx
    CLR_MUX();

    //Setting new Channel
    switch (copy_u8_ch_sel)
    {
    case ADC_ch0:
        SET_MUX(ADC_ch0);
        break;
    case ADC_ch1:
        SET_MUX(ADC_ch1);
        break;
    case ADC_ch2:
        SET_MUX(ADC_ch2);
        break;
    case ADC_ch3:
        SET_MUX(ADC_ch3);
        break;
    case ADC_ch4:
        SET_MUX(ADC_ch4);
        break;
    case ADC_ch5:
        SET_MUX(ADC_ch5);
        break;
    case ADC_ch6:
        SET_MUX(ADC_ch6);
        break;
    case ADC_ch7:
        SET_MUX(ADC_ch7);
        break;
    
    default:
        break;
    }

    //starting Conversion
    SET_BIT(ADCSRA , 6);

    //polling the flag
    while (READ_BIT(ADCSRA , ADCSRA_ADIF ) == 0)
    {
        /*Nothing*/
    }

    //Clearing the ADIF

    u16 resL= ADCL ;
    u16 resh= ADCH * 256;

    SET_BIT(ADCSRA , ADCSRA_ADIF);

   //ADCL_REG | (ADCH_REG << 8)  ;

    u16 result = resL + resh ;

    return result;
    
}

//===========================================================
static void ADC_void_Set_prescalar(const u8 Copy_u8_prescalar)
{
    for( u8 counter =0 ; counter <=2 ; counter++ )
    {
        if(((Copy_u8_prescalar>>counter) & 0x01) == 0x01)
        {
            SET_BIT(ADCSRA ,counter );
        }
        else
        {
            CLR_BIT(ADCSRA ,counter );
        }
    }
}
