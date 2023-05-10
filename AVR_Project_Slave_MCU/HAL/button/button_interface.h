/*
 * button_interface.h
 *
 *  Created on: Mar 31, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

/*************************/
/*Ports Macros*/
/*
#define PORTA  						0
#define PORTB  						1
#define PORTC  						2
#define PORTD  						3
*/
/*Pin Macros*/
/*
#define PIN0  							0
#define PIN1  							1
#define PIN2  							2
#define PIN3  							3
#define PIN4  							4
#define PIN5  							5
#define PIN6  							6
#define PIN7  							7
*/
/************************************/

#define SINK                            0
#define source                          1
typedef struct 
{
    u8 port : 3;
    u8 pin :3;
    u8 SINK_SRC : 1;
    u8 reserved :1;

}button_obj_t;



void button_void_buton_initialize(const button_obj_t *ref_button_obj_t_btn);
u8 button_u8_get_status(const button_obj_t *ref_button_obj_t_btn);

#endif //BUTTON_INTERFACE_H
