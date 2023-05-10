/*
 * EXTI_Config.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Ahmed Abdalla
 */
 //file guard
#ifndef _ADC_INTERFACE_
#define _ADC_INTERFACE_

//options for ADC channel selection
#define ADC_ch0                0x00u
#define ADC_ch1                0x01u
#define ADC_ch2                0x02u
#define ADC_ch3                0x03u
#define ADC_ch4                0x04u
#define ADC_ch5                0x05u
#define ADC_ch6                0x06u
#define ADC_ch7                0x07u

//Funvtion Prototypes

void ADC_VOID_Init(void);

u16 ADC_u16_Get_Read(u8 copy_u8_ch_sel);

#endif //_ADC_INTERFACE_
