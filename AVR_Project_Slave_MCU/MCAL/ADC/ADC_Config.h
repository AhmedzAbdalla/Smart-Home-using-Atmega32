/*
 * EXTI_Config.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Ahmed Abdalla
 */
 //file guard
#ifndef _ADC_CONFIG_
#define _ADC_CONFIG_

//options for Voltage Reference Selection
#define AREF                    0x00u
#define AVCC                    0x01u
#define Internal_2_56v          0x02u

#define Voltage_Reference       AVCC
//options for ADC result Justification
#define Left_justified         0x01u
#define Right_justified        0x00u

#define justification          Right_justified 

//options for ADC channel selection
#define ADC_ch0                0x00u
#define ADC_ch1                0x01u
#define ADC_ch2                0x02u
#define ADC_ch3                0x03u
#define ADC_ch4                0x04u
#define ADC_ch5                0x05u
#define ADC_ch6                0x06u
#define ADC_ch7                0x07u

#define ADC_Channel            ADC_ch0
//options for ADC operation
#define ADC_ON                  0x01u
#define ADC_OFF                 0x00u

#define ADC_POWER               ADC_ON

#define ADC_START               0x01u

//options for Trigger feature
#define ADC_AUTO_TRIGGER_ON     0x01u
#define ADC_AUTO_TRIGGER_OFF    0x00u

#define ADC_AUTO_TRIGGER_STATE  ADC_AUTO_TRIGGER_OFF

//Interrupt options for ADC
#define ADC_INTERRUPT_FLAG      4 // it's index in register for polling
#define ADC_INTERRUPT_ENABLE    0x01u
#define ADC_INTERRUPT_DISABLE   0x00u

#define PIE_STATE               ADC_INTERRUPT_ENABLE
//ADC Prescalar options
#define DIVISION_FACTOR_2       0x00u         
//#define DIVISION_FACTOR_2       0x01u //these duplicate option         
#define DIVISION_FACTOR_4       0x02u         
#define DIVISION_FACTOR_8       0x03u         
#define DIVISION_FACTOR_16      0x04u         
#define DIVISION_FACTOR_32      0x05u         
#define DIVISION_FACTOR_64      0x06u         
#define DIVISION_FACTOR_128     0x07u

#define Prescalar               DIVISION_FACTOR_64




#endif //_ADC_CONFIG_
