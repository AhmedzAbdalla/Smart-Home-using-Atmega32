/*
 * EXTI_Private.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H


/*******************************TIMER0********************************/
// Force Output Compare
#define TIMER0_FOC0_OFF                    0x00
#define TIMER0_FOC0_ON                     0x01

#define FOC0_STATE                         TIMER0_FOC0_OFF


// Waveform Generation Mode
#define TIMER0_WAVE_GEN_NORMAL             0X00
#define TIMER0_WAVE_GEN_PWM                0X01
#define TIMER0_WAVE_GEN_CTC                0X02
#define TIMER0_WAVE_GEN_PWM_FAST           0X03

#define TIMER0_WAVE_GEN_MODE               TIMER0_WAVE_GEN_NORMAL

// Compare Match Output Mode
/*the function of the COM01:0 bits depends on the WGM01:0
bit setting.*/
/*******************************************************/
//important: FOR wave gen set to NON-PWM MODE
#define   OC0_disconnected                       0x00
#define   OC0_TOGGLE                             0x01
#define   OC0_CLEAR                              0x02
#define   OC0_SET                                0x03

//important: FOR wave gen set to FAST PWM MODE
#define   OC0_disconnected                       0x00
#define   OC0_CLEAR_NON_INVERT                   0x02
#define   OC0_SET_INVERT                         0x03


//important: FOR wave gen set to PHASE CORRECT PWM MODE
#define   OC0_disconnected                       0x00
#define   OC0_CLEAR_UP_COUNT_SET_DOWN_COUNT      0x02
#define   OC0_SET_UP_COUNT_CLEAR_DOWN_COUNT      0x03

#define TIMER0_Compare_Match_Output_Mode                OC0_disconnected 
/*******************************************************/
// END O FCompare Match Output Mode

// Clock Select
#define TIMER0_enable                                    0Xf0 //to enable counter
#define TIMER0_STOP                                      0X00 //to disable counter
#define TIMER0_ON_OFF                                    TIMER0_enable

#define TIMER0_DIVISION_FACTOR_1                         0X01
#define TIMER0_DIVISION_FACTOR_8                         0X02
#define TIMER0_DIVISION_FACTOR_64                        0X03
#define TIMER0_DIVISION_FACTOR_256                       0X04
#define TIMER0_DIVISION_FACTOR_1024                      0X05
#define TIMER0_EXT_CKI_FALLING_EDGE                      0X06
#define TIMER0_EXT_CKI_RISING_EDGE                       0X07

#define CLOCK_SELECT                              TIMER0_DIVISION_FACTOR_8

// END OF Clock Select

#define TIMER0_OCIE0_ON                                  0X01
#define TIMER0_OCIE0_OFF                                 0X00

#define TIMER0_INTERUPT_OCM_STATUS                       TIMER0_OCIE0_OFF


#define TIMER0_TOIE0_ON                                  0X01
#define TIMER0_TOIE0_OFF                                 0X00

#define TIMER0_INTERUPT_TOIE0_STATUS                     TIMER0_TOIE0_ON

/*******************************END OF TIMER0********************************/

/*******************************TIMER1********************************/

#define  TIMER1_channel_A_ON         0x01
#define  TIMER1_channel_A_OFF        0x00

#define TIMER1_channel_A_State      TIMER1_channel_A_ON

#define  TIMER1_channel_B_ON         0x01
#define  TIMER1_channel_B_OFF        0x00

#define TIMER1_channel_B_State      TIMER1_channel_B_OFF

/*these bits must be set to zero when TCCR1A is written when operating in a PWM mode.*/
#define TIMER1_FOC1_OFF                    0x00
#define TIMER1_FOC1_ON                     0x01

#define FOC1_STATE                         TIMER1_FOC1_ON


//important: [TIMER1_channel_A] FOR wave gen set to NON-PWM MODE 
#define   OC1_A_disconnected                       0x00
#define   OC1_A_TOGGLE                             0x01
#define   OC1_A_CLEAR                              0x02
#define   OC1_A_SET                                0x03


//important: [TIMER1_channel_B] FOR wave gen set to NON-PWM MODE 
#define   OC1_B_disconnected_id4                       0x00
#define   OC1_B_TOGGLE                             0x01 //WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
#define   OC1_B_CLEAR                              0x02
#define   OC1_B_SET                                0x03

//important: [TIMER1_channel_A] FOR wave gen set to FAST PWM MODE
#define   OC1_A_disconnected                       0x00
#define   OC1_A_TOGGLE                             0x01 //WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
#define   OC1_A_CLEAR_NON_INVERT                   0x02
#define   OC1_A_SET_INVERT                         0x03  


//important: [TIMER1_channel_B] FOR wave gen set to FAST PWM MODE
#define   OC1_B_disconnected_id0                       0x00
#define   OC1_B_disconnected_id1                      0x01
#define   OC1_B_CLEAR_NON_INVERT                   0x02
#define   OC1_B_SET_INVERT                         0x03   

//important: [TIMER1_channel_A] FOR wave gen set to Phase Correct and Phase and Frequency Correct PWM
#define   OC1_A_disconnected                       0x00
#define   OC1_A_TOGGLE                             0x01 //  WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
#define   OC1_A_CLEAR_UP_COUNT_SET_DOWN_COUNT      0x02
#define   OC1_A_SET_UP_COUNT_CLEAR_DOWN_COUNT      0x03


//important: [TIMER1_channel_B] FOR wave gen set to Phase Correct and Phase and Frequency Correct PWM
#define   OC1_B_disconnected_id2                       0x00
#define   OC1_B_TOGGLE                             0x01 //  WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
#define   OC1_B_CLEAR_UP_COUNT_SET_DOWN_COUNT      0x02
#define   OC1_B_SET_UP_COUNT_CLEAR_DOWN_COUNT      0x03


#define TIMER1_A_Compare_Match_Output_Mode                OC1_B_CLEAR_NON_INVERT
#define TIMER1_B_Compare_Match_Output_Mode                OC1_B_CLEAR_NON_INVERT

//Waveform Generation Mode

#define Normal                                  0x00
#define PWM_Phase_Correct_8bit                  0x01                
#define PWM_Phase_Correct_9bit                  0x02               
#define PWM_Phase_Correct_10bit                 0x03                 
#define CTC_4                                   0x04
#define Fast_PWM_8_bit                          0x05        
#define Fast_PWM_9_bit                          0x06        
#define Fast_PWM_10_bit                         0x07         
#define PWM_Phase_and_Frequency_Correct_8       0x08                           
#define PWM_Phase_and_Frequency_Correct_9       0x09                           
#define PWM_Phase_Correct_10                    0x0a           
#define PWM_Phase_Correct_11                    0x0b           
#define CTC_12                                  0x0c
#define Reserved                                0x0d  
#define Fast_PWM_14                             0x0e     
#define Fast_PWM_15                             0x0f     

#define TIMER1_WAVE_GEN_MODE                    Fast_PWM_14

// Clock Select
#define TIMER1_enable                                    0Xf0 //to enable counter
#define TIMER1_STOP                                      0X00 //to disable counter
#define TIMER1_ON_OFF                                    TIMER0_enable

#define TIMER1_DIVISION_FACTOR_1                         0X01
#define TIMER1_DIVISION_FACTOR_8                         0X02
#define TIMER1_DIVISION_FACTOR_64                        0X03
#define TIMER1_DIVISION_FACTOR_256                       0X04
#define TIMER1_DIVISION_FACTOR_1024                      0X05
#define TIMER1_EXT_CKI_FALLING_EDGE                      0X06
#define TIMER1_EXT_CKI_RISING_EDGE                       0X07

#define TIMER1_CLOCK_SELECT                              TIMER0_DIVISION_FACTOR_8

// END OF Clock Select

#define TIMER1_A_OCIE1_ON                                  0X01
#define TIMER1_A_OCIE1_OFF                                 0X00

#define TIMER1_A_INTERUPT_OCM_STATUS                       TIMER1_A_OCIE1_OFF

#define TIMER1_B_OCIE1_ON                                  0X01
#define TIMER1_B_OCIE1_OFF                                 0X00

#define TIMER1_B_INTERUPT_OCM_STATUS                       TIMER1_B_OCIE0_OFF


#define TIMER1_TOIE1_ON                                  0X01
#define TIMER1_TOIE1_OFF                                 0X00

#define TIMER_INTERUPT_TOIE1_STATUS                     TIMER1_TOIE1_OFF


/*******************************END OF TIMER1********************************/


/*******************************TIMER2********************************/

/*******************************END OF TIMER2********************************/



#endif //TIMERS_CONFIG_H
