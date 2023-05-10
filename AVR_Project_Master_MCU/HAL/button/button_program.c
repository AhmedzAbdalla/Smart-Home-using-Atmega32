/*
 * button_program.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Ahmed Abdalla
 */

#include  "../../LIB/STD_Types.h"
#include  "../../LIB/BIT_MATH.h"


#include "../../MCAL/DIO/DIO_Interface.h"
#include "button_interface.h"


void button_void_buton_initialize(const button_obj_t *ref_button_obj_t_btn)
{

    DIO_void_Pin_Initialize(ref_button_obj_t_btn->port ,ref_button_obj_t_btn->pin , INPUT );

    //initializing PULL up OR PULL down

    switch (ref_button_obj_t_btn->SINK_SRC)
    {
    case SINK:
        DIO_void_Pin_Write_Logic(ref_button_obj_t_btn->port ,ref_button_obj_t_btn->pin , HIGH );
        break;
    case source:
        break;
    default:
        break;
    }
}


u8 button_u8_get_status(const button_obj_t *ref_button_obj_t_btn)
{

    u8 status;
    status = DIO_u8_Pin_Read_Logic(ref_button_obj_t_btn->port ,ref_button_obj_t_btn->pin);

    return status;
}
