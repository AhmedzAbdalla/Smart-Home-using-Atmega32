/*
 * DIO_Interface.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Ahmed Abdalla
 */


#ifndef HEADER_FILES_DIO_INTERFACE_H_
#define HEADER_FILES_DIO_INTERFACE_H_
#include "../../LIB/STD_Types.h"

/*
 * Macros in  Interface file are that one that could be passed to functions as arguments
 *
 * */
/*PortId Macros*/
#define PORTA  						0
#define PORTB  						1
#define PORTC  						2
#define PORTD  						3

/*PinId Macros*/
#define PIN0  							0
#define PIN1  							1
#define PIN2  							2
#define PIN3  							3
#define PIN4  							4
#define PIN5  							5
#define PIN6  							6
#define PIN7  							7

/*Direction Macros*/
#define INPUT 						0
#define OUTPUT 					1

/*Logic Macros*/
#define LOW 							0
#define HIGH 							1
/*********************************DataType Defintions*********************************/


/******************************************************************/
/*Func. Name: DIO_void_Pin_Direction_Initialize                   */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*Copy_u8_Direction: INPUT , OUTPUT                                         */
/*return: void                                                    */
/******************************************************************/
void DIO_void_Pin_Direction_Initialize(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id , u8 Copy_u8_Direction );

/******************************************************************/
/*Func. Name: DIO_u8_Pin_Get_Direction                  		  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*return: u8                                                   */
/******************************************************************/
u8 DIO_u8_Pin_Get_Direction(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id);

/******************************************************************/
/*Func. Name: DIO_void_Pin_Write_Logic                  		  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*Copy_u8_Logic: LOW , HIGH										  */
/*return: void                                                    */
/******************************************************************/
void DIO_void_Pin_Write_Logic(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id , u8 Copy_u8_Logic );



/******************************************************************/
/*Func. Name: DIO_u8_Pin_Read_Logic                  	     	  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*return: u8 (HIGH , LOW , error code(55)                                                        */
/******************************************************************/
u8 DIO_u8_Pin_Read_Logic(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id);

/******************************************************************/
/*Func. Name: DIO_void_Pin_Toggle                  		          */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*return: void                                                    */
/******************************************************************/
void DIO_void_Pin_Toggle(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id );


/******************************************************************/
/*Func. Name: DIO_void_Pin_Initialize                  		          */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*return: void                                                    */
/******************************************************************/
void DIO_void_Pin_Initialize(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id , u8 Copy_u8_Direction);

//============================================================================



/******************************************************************/
/*Func. Name: DIO_void_PORT_Direction_Initialize                  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8_Direction: 0 : 255                                    */
/*return: void                                                    */
/******************************************************************/
void DIO_void_PORT_Direction_Initialize(u8 Copy_u8_Port_Id ,u8 Copy_u8_Direction );

/******************************************************************/
/*Func. Name: DIO_u8_PORT_Get_Direction                  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*return: u8                                                    */
/******************************************************************/
u8 DIO_u8_PORT_Get_Direction(u8 Copy_u8_Port_Id);



/******************************************************************/
/*Func. Name: DIO_void_PORT_Write_Logic                  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8_Direction: 0 : 255                                    */
/*return: void                                                    */
/******************************************************************/
void DIO_void_PORT_Write_Logic(u8 Copy_u8_Port_Id ,u8 Copy_u8_Logic );

/******************************************************************/
/*Func. Name: DIO_u8_PORT_Read_Logic              			      */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*return: void                                                    */
/******************************************************************/
u8 DIO_u8_PORT_Read_Logic(u8 Copy_u8_Port_Id);


/******************************************************************/
/*Func. Name: DIO_void_PORT_Toggle              			      */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*return: void                                                    */
/******************************************************************/
void DIO_void_PORT_Toggle(u8 Copy_u8_Port_Id);

#endif /* HEADER_FILES_DIO_INTERFACE_H_ */
