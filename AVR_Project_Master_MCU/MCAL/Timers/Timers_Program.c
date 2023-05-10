/*
 * EXTI_Private.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Ahmed Abdalla
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "timers_Interface.h"
#include "timers_Private.h"
#include "timers_Config.h"

void (*TIMER_0_handler)(void) = NULL;
void (*TIMER_0_OC_handler)(void) = NULL;
void (*TIMER_1_handler)(void) = NULL;

void Timer_0_void_Init(void)
{
    #if TIMER0_ON_OFF == TIMER0_STOP
        /*NOTHING*/
    #elif TIMER0_ON_OFF == TIMER0_enable
    
        #if TIMER0_WAVE_GEN_MODE == TIMER0_WAVE_GEN_NORMAL
            CLR_BIT(TIMER0_TCCR0 , TCCR0_WGM00);
            CLR_BIT(TIMER0_TCCR0 , TCCR0_WGM01);
            /*The FOC0 bit is only active when the WGM00 bit specifies a non-PWM mode.*/
            SET_BIT(TIMER0_TCCR0 , TCCR0_FOC0); //Force Output Compare

            //configuring Compare output mode
            #if TIMER0_Compare_Match_Output_Mode == OC0_disconnected
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_TOGGLE
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_CLEAR
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_SET
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #endif
            //END OF configuring Compare output mode

        #elif TIMER0_WAVE_GEN_MODE == TIMER0_WAVE_GEN_CTC
            CLR_BIT(TIMER0_TCCR0 , TCCR0_WGM00);
            SET_BIT(TIMER0_TCCR0 , TCCR0_WGM01);
            /*The FOC0 bit is only active when the WGM00 bit specifies a non-PWM mode.*/
            SET_BIT(TIMER0_TCCR0 , TCCR0_FOC0); //Force Output Compare

            //configuring Compare output mode
            #if TIMER0_Compare_Match_Output_Mode == OC0_disconnected
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_TOGGLE
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_CLEAR
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_SET
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #endif
            //END OF configuring Compare output mode

        #elif TIMER0_WAVE_GEN_MODE == TIMER0_WAVE_GEN_PWM
            SET_BIT(TIMER0_TCCR0 , TCCR0_WGM00);
            CLR_BIT(TIMER0_TCCR0 , TCCR0_WGM01);
            /*this bit must be set to zero when TCCR0 is written when operating in PWM mode*/
            CLR_BIT(TIMER0_TCCR0 , TCCR0_FOC0);//Force Output Compare

            #if TIMER0_Compare_Match_Output_Mode == OC0_disconnected
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_CLEAR_UP_COUNT_SET_DOWN_COUNT
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_SET_UP_COUNT_CLEAR_DOWN_COUNT
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM01);

            #endif
        #elif TIMER0_WAVE_GEN_MODE == TIMER0_WAVE_GEN_PWM_FAST
            SET_BIT(TIMER0_TCCR0 , TCCR0_WGM00);
            SET_BIT(TIMER0_TCCR0 , TCCR0_WGM01);
            /*this bit must be set to zero when TCCR0 is written when operating in PWM mode*/
            CLR_BIT(TIMER0_TCCR0 , TCCR0_FOC0);//Force Output Compare

            #if TIMER0_Compare_Match_Output_Mode == OC0_disconnected
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_CLEAR_NON_INVERT
                CLR_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #elif TIMER0_Compare_Match_Output_Mode == OC0_SET_INVERT
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM00);
                SET_BIT(TIMER0_TCCR0 , TCCR0_COM01);
            #endif
        #endif

        //Configuring Clock Select
        #if CLOCK_SELECT == TIMER0_DIVISION_FACTOR_1 
            TIMER0_TCCR0 |= TIMER0_DIVISION_FACTOR_1;
        #elif CLOCK_SELECT == TIMER0_DIVISION_FACTOR_8
            TIMER0_TCCR0 |= TIMER0_DIVISION_FACTOR_8;
        #elif CLOCK_SELECT == TIMER0_DIVISION_FACTOR_64
            TIMER0_TCCR0 |= TIMER0_DIVISION_FACTOR_64;
        #elif CLOCK_SELECT == TIMER0_DIVISION_FACTOR_256
            TIMER0_TCCR0 |= TIMER0_DIVISION_FACTOR_256;
        #elif CLOCK_SELECT == TIMER0_DIVISION_FACTOR_1024
            TIMER0_TCCR0 |= TIMER0_DIVISION_FACTOR_1024;
        #elif CLOCK_SELECT == TIMER0_EXT_CKI_FALLING_EDGE
            TIMER0_TCCR0 |= TIMER0_EXT_CKI_FALLING_EDGE;
        #elif CLOCK_SELECT == TIMER0_EXT_CKI_RISING_EDGE
            TIMER0_TCCR0 |= TIMER0_EXT_CKI_RISING_EDGE;
        #endif
        //END OF Configuring Clock Select

        //Configuring Interrupt on timer0
        #if TIMER0_WAVE_GEN_MODE == TIMER0_WAVE_GEN_NORMAL
            #if TIMER0_INTERUPT_TOIE0_STATUS == TIMER0_TOIE0_OFF 
                CLR_BIT(TIMER0_TIMSK , TIMSK_TOIE0);
            #elif TIMER0_INTERUPT_TOIE0_STATUS == TIMER0_TOIE0_ON
                SET_BIT(TIMER0_TIMSK , TIMSK_TOIE0);
            #endif 
        #elif TIMER0_WAVE_GEN_MODE == TIMER0_WAVE_GEN_CTC
            #if TIMER0_INTERUPT_OCM_STATUS ==   TIMER0_OCIE0_OFF
                CLR_BIT(TIMER0_TIMSK , TIMSK_OCIE0);
            #elif TIMER0_INTERUPT_OCM_STATUS ==   TIMER0_OCIE0_ON
                SET_BIT(TIMER0_TIMSK , TIMSK_OCIE0);
            #endif
        #endif

    #endif
    

    
}

void Timer_1_void_Init(void)
{
    #if TIMER1_ON_OFF == TIMER1_STOP
        /*Nothing*/
    #elif TIMER1_ON_OFF == TIMER1_enable

        #if TIMER1_WAVE_GEN_MODE == Normal
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == PWM_Phase_Correct_8bit
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == PWM_Phase_Correct_9bit
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == PWM_Phase_Correct_10bit
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == CTC_4
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == Fast_PWM_8_bit
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == Fast_PWM_9_bit
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == Fast_PWM_10_bit
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == PWM_Phase_and_Frequency_Correct_8
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == PWM_Phase_Correct
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == CTC_12
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == Reserved
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == Fast_PWM_14

            CLR_BIT(TCCR1A , TCCR1A_FOC1A);//Mandatory 
            CLR_BIT(TCCR1A , TCCR1A_FOC1B);//Mandatory 

            //Selecting Mode
            CLR_BIT(TCCR1A , TCCR1A_WGM10);
            SET_BIT(TCCR1A , TCCR1A_WGM11);
            SET_BIT(TCCR1B , TCCR1B_WGM12);
            SET_BIT(TCCR1B , TCCR1B_WGM13);

            #if TIMER1_channel_A_State == TIMER1_channel_A_OFF
                /*Nothing*/
            #elif TIMER1_channel_A_State == TIMER1_channel_A_ON //Compare Match output for Channel A
                
                #if TIMER1_A_Compare_Match_Output_Mode == OC1_A_disconnected
                    CLR_BIT(TCCR1A , TCCR1A_COM1A0);
                    CLR_BIT(TCCR1A , TCCR1A_COM1A1);
                    #elif TIMER1_A_Compare_Match_Output_Mode == OC1_A_TOGGLE
                    SET_BIT(TCCR1A , TCCR1A_COM1A0);
                    CLR_BIT(TCCR1A , TCCR1A_COM1A1);
                    #elif TIMER1_A_Compare_Match_Output_Mode == OC1_A_CLEAR_NON_INVERT
                    CLR_BIT(TCCR1A , TCCR1A_COM1A0);
                    SET_BIT(TCCR1A , TCCR1A_COM1A1);
                    #elif TIMER1_A_Compare_Match_Output_Mode == OC1_A_SET_INVERT
                    SET_BIT(TCCR1A , TCCR1A_COM1A0);
                    SET_BIT(TCCR1A , TCCR1A_COM1A1);
                #endif

            #endif
            //============================================
            #if TIMER1_channel_B_State == TIMER1_channel_B_OFF //Compare Match output for Channel A
                /*Nothing*/
            #elif TIMER1_channel_B_State == TIMER1_channel_B_ON //Compare Match output for Channel A
                
                #if TIMER1_B_Compare_Match_Output_Mode == OC1_B_disconnected
                    CLR_BIT(TCCR1A , TCCR1A_COM1B0);
                    CLR_BIT(TCCR1A , TCCR1A_COM1B1);
                    #elif TIMER1_B_Compare_Match_Output_Mode == OC1_B_disconnected
                    SET_BIT(TCCR1A , TCCR1A_COM1B0);
                    CLR_BIT(TCCR1A , TCCR1A_COM1B1);
                    #elif TIMER1_B_Compare_Match_Output_Mode == OC1_B_CLEAR_NON_INVERT
                    CLR_BIT(TCCR1A , TCCR1A_COM1B0);
                    SET_BIT(TCCR1A , TCCR1A_COM1B1);
                    #elif TIMER1_B_Compare_Match_Output_Mode == OC1_B_SET_INVERT
                    SET_BIT(TCCR1A , TCCR1A_COM1B0);
                    SET_BIT(TCCR1A , TCCR1A_COM1B1);
                #endif

            #endif
        /*Code*/
        #elif TIMER1_WAVE_GEN_MODE == Fast_PWM_15
        CLR_BIT(TCCR1A , TCCR1A_FOC1A);
        CLR_BIT(TCCR1A , TCCR1A_FOC1B);
        /*Code*/
        #endif

        //Configuring Clock Select

        #if TIMER1_CLOCK_SELECT == TIMER1_DIVISION_FACTOR_1
            /*Code*/
            TCCR1B |= TIMER1_DIVISION_FACTOR_1;
        #elif TIMER1_CLOCK_SELECT == TIMER1_DIVISION_FACTOR_8
            /*Code*/
            TCCR1B |= TIMER1_DIVISION_FACTOR_8;
        #elif TIMER1_CLOCK_SELECT == TIMER1_DIVISION_FACTOR_64
            /*Code*/
            TCCR1B |= TIMER1_DIVISION_FACTOR_64;
        #elif TIMER1_CLOCK_SELECT == TIMER1_DIVISION_FACTOR_256
            /*Code*/
            TCCR1B |= TIMER1_DIVISION_FACTOR_256;
        #elif TIMER1_CLOCK_SELECT == TIMER1_DIVISION_FACTOR_1024
            /*Code*/
            TCCR1B |= TIMER1_DIVISION_FACTOR_1024;
        #elif TIMER1_CLOCK_SELECT == TIMER1_EXT_CKI_FALLING_EDGE
            /*Code*/
            TCCR1B |= TIMER1_EXT_CKI_FALLING_EDGE;
        #elif TIMER1_CLOCK_SELECT == TIMER1_EXT_CKI_RISING_EDGE
        TCCR1B |= TIMER1_EXT_CKI_RISING_EDGE;
        #endif //END OF Configuring Clock Select

        //Configuring Interrupts 


    #endif
}

void Timer_1_void_delay_ms(const u16 Copy_u16_val)
{
    f32 counter = 0.0;
    u16 counter_int_part = 0;
    //calculations freq = 8MHz , prescalar = 8
    counter = (Copy_u16_val/65.536);
    counter_int_part = (u16)counter;

    //set Waveform Generation Mode to normal mode
    CLR_BIT(TCCR1A , TCCR1A_WGM10);
    CLR_BIT(TCCR1A , TCCR1A_WGM11);
    CLR_BIT(TCCR1B , TCCR1B_WGM12);
    CLR_BIT(TCCR1B , TCCR1B_WGM13);

    //set prescalar to division factor = 1
    TCCR1B |= TIMER1_DIVISION_FACTOR_8;

    // Set Compare Output Mode
    CLR_BIT(TCCR1A , TCCR1A_COM1A0);
    CLR_BIT(TCCR1A , TCCR1A_COM1A1);

    //
   // lcd_void_send_num_pos(counter_int_part, 2, 1);
    Timer_1_void_Set_Preload_val((u16)(((counter - counter_int_part) * 100)) );
    for(u16 counter = 0 ; counter < counter_int_part ; counter++)
    {
    	//lcd_void_send_num_pos(counter, 2, 1);
        while(READ_BIT(TIMER0_TIFR , TIFR_TOV1) == 0)
        {
            /*nothing*/

        }
        SET_BIT(TIMER0_TIFR , TIFR_TOV1);
    }
}

void Timer_0_void_Set_Preload_val(const u8 Copy_u8_val)
{
    TIMER0_TCNT0 = Copy_u8_val;
}


void Timer_0_void_Set_OCR0_val(const u8 Copy_u8_val)
{
    TIMER0_OCR0 = Copy_u8_val;
}

void Timer_1_void_Set_Preload_val(const u16 Copy_u16_val)
{
    TCNT1 = Copy_u16_val;
}

void Timer_1_void_Set_ICR2_val(const u16 Copy_u16_val)
{
    ICR1 = Copy_u16_val;
}

void Timer_1_void_Set_OCR1_A_val(const u16 Copy_u16_val)
{
    OCR1A = Copy_u16_val;
}

void set_TIMER_0_handler(void (*pf) (void))
{
    if(NULL != pf)
    {
        TIMER_0_handler = pf;
    }
    
}

void set_TIMER_0_OC0_handler(void (*pf) (void))
{
    if(NULL != pf)
    {
        TIMER_0_OC_handler = pf;
    }
}

void set_TIMER_1_handler(void (*pf) (void))
{
    if(NULL != pf)
    {
        TIMER_1_handler = pf;
    }
}

//ISR for timer 0 ovf
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    static u16 counter =0;
    counter++;
    if(counter == 3)
    {
        /*Action*/
        if(TIMER_0_handler != NULL)
        {
            TIMER_0_handler();
        }
        counter = 0;
        Timer_0_void_Set_Preload_val(192);
    }
}

// ISR for OC0
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    static u16 counter = 0;
    counter++;
    if(counter == 3000)
    {
        /*Action*/
        if(TIMER_0_OC_handler != NULL)
        {
            TIMER_0_OC_handler();
        }
        counter = 0;
        Timer_0_void_Set_OCR0_val(192);
    }
}


//ISR for timer 1 ovf
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
    
}
