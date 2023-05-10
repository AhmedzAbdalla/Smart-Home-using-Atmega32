/*
 * app.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Ahmed Abdalla
 */
#include <util/delay.h>
#include <math.h>

#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/Timers/Timers_Interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/Watch_dog/Watch_dog_Interface.h"

#include "../HAL/LCD/lcd_interface.h"
#include "../HAL/LCD/lcd_cfg.h"
#include "../HAL/7_segment/7_segment.h"
#include "../HAL/Keypad/keypad_interface.h"
#include "../HAL/button/button_interface.h"
#include "../HAL/DC_Motor/DC_Motor_Interface.h"
#include "../HAL/Stepper_Motor/Stepper_motor_Interface.h"
#include "../HAL/EEPROM/EEPROM_Interface.h"
#include "../HAL/RTC_DS1307/RTC_DS1307_interface.h"

#include "app.h"

#define GIE_ENABLE() (*((volatile u8 *)0x5F)) = 0x80
#define GIE_DISABLE() (*((volatile u8 *)0x5F)) = 0x00

button_obj_t BTN_1 = {.port = PORTD,
									.pin = PIN2,
									.SINK_SRC = SINK,
									.reserved = 0
};


float vin = 0.0;
u16 temp = 0.0;
u16 adc_res_fract = 0;
u8 stepper_motor_counter = 0;
u8 data = 0;
u8 volatile counter = 0;
s32 main()
{
	app_applications_init();





//	DIO_void_Pin_Write_Logic(PORTB , PIN1 ,HIGH );

	_delay_ms(500);
	while(1)
	{
		//LDR sensor
		app_void_sensor_LDR();

		//LM35 Temperature sensor
		app_void_sensor_LM35();


		//Timer_1_void_Set_OCR1_A_val(1799);
		_delay_ms(500);
	}


	return 0;
}

void app_applications_init()
{
	/*Peripheral initialization*/
	ADC_VOID_Init();

	Timer_1_void_Set_ICR2_val(19999);
	Timer_1_void_Set_Preload_val(0);
	Timer_1_void_Init();
	//Timer_1_void_Set_OCR1_A_val(1799);
	_delay_ms(200);
	//TWI_void_Slave_Init(0xc0);

	Stepper_MOTOR_Init();



	//pin PA4 as Input to control get reading from LDR
	DIO_void_Pin_Initialize(PORTA, PIN4, INPUT);

	//pin PA5 as Input to control get reading from lm35
	DIO_void_Pin_Initialize(PORTA, PIN5, INPUT);

	//pin PB1 as output to control outer led
	DIO_void_Pin_Initialize(PORTB, PIN1, OUTPUT);

	//initialize PD5 as input pull up
	DIO_void_Pin_Initialize(PORTD, PIN5, OUTPUT);
	//DIO_void_Pin_Write_Logic(PORTD, PIN5, HIGH);

	//initialize PC2 as output to control conditioner
	DIO_void_Pin_Initialize(PORTC , PIN2, OUTPUT);

	//initialize PC3 as output to control outter light
	DIO_void_Pin_Initialize(PORTC , PIN3, OUTPUT);

	//initialize PB0 as output for buzzer
	DIO_void_Pin_Initialize(PORTB, PIN0, OUTPUT);

	//============================
	//SPI Operations
	DIO_void_Pin_Initialize(PORTB, PIN7, INPUT);
	DIO_void_Pin_Initialize(PORTB, PIN6, OUTPUT);
	DIO_void_Pin_Initialize(PORTB, PIN5, INPUT);
	DIO_void_Pin_Initialize(PORTB, PIN4, INPUT);

	//Slave initialization
	SPI_void_init();
	//Setting Callback functions
	SPI_transfer_Set_ISR_Handler(&func_1);

	//initializing push button as input
	button_void_buton_initialize(&BTN_1);

	//setting up external interrupt peripheral
	EXTI_void_EXTI_init();
	EXTI_void_EXTI_enable(0 , 0);
	set_EXTI_0_handler(&EXTI_handler);

	//enabling global interrupt
	GIE_ENABLE();
}

//LDR sensor
void app_void_sensor_LDR(void)
{
	//LDR sensor
	vin= ADC_u16_Get_Read(4);
	vin *=5.0;
	vin /=1024.0;

	if(vin > 3.0)
	{
		DIO_void_Pin_Write_Logic(PORTC , PIN3 ,HIGH );
	}
	else
	{
		DIO_void_Pin_Write_Logic(PORTC , PIN3 ,LOW );
	}
}

//LM35 Temperature sensor
void app_void_sensor_LM35(void)
{
	//LM35 Temperature sensor
			vin= ADC_u16_Get_Read(0x05u);
			vin *= 5;
			vin = vin / 1024.0;
			vin = vin * 1000.0;
			temp =  vin  / 10.0;
			adc_res_fract = ((vin  / 10.0) - temp) * 100;
			GIE_DISABLE();
			(*((volatile u8*)0x2F)) = temp;
			GIE_ENABLE();

			if(temp >= 30 )
			{
				DIO_void_Pin_Write_Logic(PORTC , PIN2 ,HIGH );
			}
			else
			{
				DIO_void_Pin_Write_Logic(PORTC , PIN2 ,LOW );
			}

}


void func_1(void)
{
	data = SPI_get_data();
	_delay_ms(200);
	if(0x01 == data)
	{
		Timer_1_void_Set_OCR1_A_val(1799);
	}
	else if(0x02 == data)
	{
		Timer_1_void_Set_OCR1_A_val(0);
		Stepper_MOTOR_TURN_ON(1, 14);
	}


}


void EXTI_handler(void)
{
	DIO_void_Pin_Toggle(PORTB, PIN0);
}
