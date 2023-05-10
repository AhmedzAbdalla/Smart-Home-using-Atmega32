/*
 * DIO_Program.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Ahmed Abdalla
 */

/**********Includes************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"


#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"

/******************************************************************/
/*Func. Name: DIO_void_Pin_Direction_Initialize                   */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*Copy_u8_Direction: INPUT , OUTPUT                                         */
/*return: void                                                    */
/******************************************************************/
void DIO_void_Pin_Direction_Initialize(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id , u8 Copy_u8_Direction )
{
	if( (Copy_u8_Port_Id >3)  || (Copy_u8_Pin_Id>7) )
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Direction)
			{
					case INPUT:
						switch (Copy_u8_Port_Id)
						{
							case PORTA:
								CLR_BIT(DDRA_REG ,Copy_u8_Pin_Id );
								break;
							case PORTB:
								CLR_BIT(DDRB_REG ,Copy_u8_Pin_Id );
								break;
							case PORTC:
								CLR_BIT(DDRC_REG ,Copy_u8_Pin_Id );
								break;
							case PORTD:
								CLR_BIT(DDRD_REG ,Copy_u8_Pin_Id );
								break;
						}
						break;
						case OUTPUT:
							switch (Copy_u8_Port_Id)
								{
									case PORTA:
										SET_BIT(DDRA_REG ,Copy_u8_Pin_Id );
										break;
									case PORTB:
										SET_BIT(DDRB_REG ,Copy_u8_Pin_Id );
										break;
									case PORTC:
										SET_BIT(DDRC_REG ,Copy_u8_Pin_Id );
										break;
									case PORTD:
										SET_BIT(DDRD_REG ,Copy_u8_Pin_Id );
										break;
								}
							break;
					}
			}
	}





/******************************************************************/
/*Func. Name: DIO_void_Pin_Write_Logic                  		  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*Copy_u8_Logic: LOW , HIGH										  */
/*return: void                                                    */
/******************************************************************/
void DIO_void_Pin_Write_Logic(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id , u8 Copy_u8_Logic )
{
	if( (Copy_u8_Port_Id >3)  || (Copy_u8_Pin_Id>7) )
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Logic)
			{
					case LOW :
						switch (Copy_u8_Port_Id)
						{
							case PORTA:
								CLR_BIT(PORTA_REG ,Copy_u8_Pin_Id );
								break;
							case PORTB:
								CLR_BIT(PORTB_REG ,Copy_u8_Pin_Id );
								break;
							case PORTC:
								CLR_BIT(PORTC_REG ,Copy_u8_Pin_Id );
								break;
							case PORTD:
								CLR_BIT(PORTD_REG ,Copy_u8_Pin_Id );
								break;
						}
						break;
						case HIGH:
							switch (Copy_u8_Port_Id)
								{
									case PORTA:
										SET_BIT(PORTA_REG ,Copy_u8_Pin_Id );
										break;
									case PORTB:
										SET_BIT(PORTB_REG ,Copy_u8_Pin_Id );
										break;
									case PORTC:
										SET_BIT(PORTC_REG ,Copy_u8_Pin_Id );
										break;
									case PORTD:
										SET_BIT(PORTD_REG ,Copy_u8_Pin_Id );
										break;
								}
							break;
					}
			}
}

/******************************************************************/
/*Func. Name: DIO_u8_Pin_Get_Direction                  		  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*return: u8                                                   */
/******************************************************************/
u8 DIO_u8_Pin_Get_Direction(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id)
{
	u8 Local_u8_Variable = 55;
	if( (Copy_u8_Port_Id > 3) || (Copy_u8_Pin_Id > 7))
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Port_Id)
		{
			case PORTA:
				Local_u8_Variable = READ_BIT(DDRA_REG , Copy_u8_Pin_Id);
				break;
			case PORTB:
				Local_u8_Variable = READ_BIT(DDRB_REG , Copy_u8_Pin_Id);
				break;
			case PORTC:
				Local_u8_Variable = READ_BIT(DDRC_REG , Copy_u8_Pin_Id);
				break;
			case PORTD:
				Local_u8_Variable = READ_BIT(DDRD_REG , Copy_u8_Pin_Id);
				break;

		}
	}
	return Local_u8_Variable;
}


/******************************************************************/
/*Func. Name: DIO_u8_Pin_Read_Logic                  	     	  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*return: u8 (HIGH , LOW , error code(55)                                                     */
/******************************************************************/
u8 DIO_u8_Pin_Read_Logic(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id)
{
	u8 Local_u8_Variable = 55; // in main application if the returned value equal 55 then there is an error
	if( (Copy_u8_Port_Id > 3) || (Copy_u8_Pin_Id > 7))
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Port_Id)
		{
			case PORTA:
				Local_u8_Variable = READ_BIT(PINA_REG , Copy_u8_Pin_Id);
				break;
			case PORTB:
				Local_u8_Variable = READ_BIT(PINB_REG , Copy_u8_Pin_Id);
				break;
			case PORTC:
				Local_u8_Variable = READ_BIT(PINC_REG , Copy_u8_Pin_Id);
				break;
			case PORTD:
				Local_u8_Variable = READ_BIT(PIND_REG , Copy_u8_Pin_Id);
				break;

		}
	}
	return Local_u8_Variable;
}


/******************************************************************/
/*Func. Name: DIO_void_Pin_Toggle                  		          */
/*i/p arguments: Copy_u8PortId: PORTA, PORTB, PORTC, PORTD*/
/*						   Copy_u8PinId  : PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*return: void                                                    */
/******************************************************************/
void DIO_void_Pin_Toggle(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id )
{
	if((Copy_u8_Port_Id > 3) || (Copy_u8_Pin_Id > 7))
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Port_Id)
		{
			case PORTA:
				Toggle_BIT(PORTA_REG , Copy_u8_Pin_Id);
				break;
			case PORTB:
				Toggle_BIT(PORTB_REG , Copy_u8_Pin_Id);
				break;
			case PORTC:
				Toggle_BIT(PORTC_REG , Copy_u8_Pin_Id);
				break;
			case PORTD:
				Toggle_BIT(PORTD_REG , Copy_u8_Pin_Id);
				break;
		}
	}
}

/******************************************************************/
/*Func. Name: DIO_void_Pin_Initialize                  		          */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8PinId: PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7    */
/*return: void                                                    */
/******************************************************************/
void DIO_void_Pin_Initialize(u8 Copy_u8_Port_Id , u8 Copy_u8_Pin_Id , u8 Copy_u8_Direction )
{
	switch(Copy_u8_Direction)
	{
		case OUTPUT:
			DIO_void_Pin_Direction_Initialize(Copy_u8_Port_Id , Copy_u8_Pin_Id , Copy_u8_Direction);
			//in case output pin then initialize it to low logic by default
			DIO_void_Pin_Write_Logic(Copy_u8_Port_Id ,Copy_u8_Pin_Id , LOW );
			break;
		case INPUT:
			DIO_void_Pin_Direction_Initialize(Copy_u8_Port_Id , Copy_u8_Pin_Id , Copy_u8_Direction);
			break;
		default:
			break;
	}
}


//==================================================================================

/******************************************************************/
/*Func. Name: DIO_void_PORT_Direction_Initialize                  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8_Direction: 0 : 255                                    */
/*return: void                                                    */
/******************************************************************/
void DIO_void_PORT_Direction_Initialize(u8 Copy_u8_Port_Id ,u8 Copy_u8_Direction )
{
	if( (Copy_u8_Port_Id > 3) )
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Port_Id)
		{
			case PORTA :
				DDRA_REG = Copy_u8_Direction;
				break;
			case PORTB :
				DDRB_REG = Copy_u8_Direction;
				break;
			case PORTC :
				DDRC_REG = Copy_u8_Direction;
				break;
			case PORTD :
				DDRD_REG = Copy_u8_Direction;
				break;
		}
	}
}

/******************************************************************/
/*Func. Name: DIO_void_PORT_Write_Logic                           */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*Copy_u8_Logic: 0 : 255                              		      */
/*return: void                                                    */
/******************************************************************/
void DIO_void_PORT_Write_Logic(u8 Copy_u8_Port_Id ,u8 Copy_u8_Logic )
{
	if( (Copy_u8_Port_Id > 3) )
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Port_Id)
		{
			case PORTA :
				PORTA_REG = Copy_u8_Logic;
				break;
			case PORTB :
				PORTB_REG = Copy_u8_Logic;
				break;
			case PORTC :
				PORTC_REG = Copy_u8_Logic;
				break;
			case PORTD :
				PORTD_REG = Copy_u8_Logic;
				break;
		}
	}
}


/******************************************************************/
/*Func. Name: DIO_u8_PORT_Get_Direction                  */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*return: u8                                                    */
/******************************************************************/
u8 DIO_u8_PORT_Get_Direction(u8 Copy_u8_Port_Id)
{
	u8 Local_u8_Variable = 22;
	if( (Copy_u8_Port_Id > 3) )
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Port_Id)
		{
			case PORTA :
				Local_u8_Variable = DDRA_REG;
				break;
			case PORTB :
				Local_u8_Variable = DDRB_REG;
				break;
			case PORTC :
				Local_u8_Variable = DDRC_REG;
				break;
			case PORTD :
				Local_u8_Variable = DDRD_REG;
				break;
		}
	}
	return Local_u8_Variable;
}



/******************************************************************/
/*Func. Name: DIO_u8_PORT_Read_Logic              			      */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*return: void                                                    */
/******************************************************************/
u8 DIO_u8_PORT_Read_Logic(u8 Copy_u8_Port_Id)
{
	u8 Local_u8_Variable = 22;
	if( (Copy_u8_Port_Id > 3) )
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Port_Id)
		{
			case PORTA :
				Local_u8_Variable = PINA_REG;
				break;
			case PORTB :
				Local_u8_Variable = PINB_REG;
				break;
			case PORTC :
				Local_u8_Variable = PINC_REG;
				break;
			case PORTD :
				Local_u8_Variable = PIND_REG;
				break;
		}
	}
	return Local_u8_Variable;
}


/******************************************************************/
/*Func. Name: DIO_void_PORT_Toggle              			      */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB, PORTC, PORTD*/
/*return: void                                                    */
/******************************************************************/
void DIO_void_PORT_Toggle(u8 Copy_u8_Port_Id)
{
	if( (Copy_u8_Port_Id > 3) )
	{
		/*Nothing*/
	}
	else
	{
		switch(Copy_u8_Port_Id)
		{
			case PORTA :
				PORTA_REG = ~(PORTA_REG);
				break;
			case PORTB :
				PORTB_REG = ~(PORTB_REG);
				break;
			case PORTC :
				PORTC_REG = ~(PORTC_REG);
				break;
			case PORTD :
				PORTD_REG = ~(PORTD_REG);
				break;
		}
	}
}
