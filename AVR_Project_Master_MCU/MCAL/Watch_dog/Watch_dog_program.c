/*
 * Watch_dog_cfg.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Ahmed Abdalla
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"

#include "Watch_dog_Interface.h"
#include "Watch_dog_private.h"
#include "Watch_dog_cfg.h"

void WDT_vod_Enable(void)
{
	SET_BIT(WDTCR , WDTCR_WDE);
	SET_BIT(WDTCR, WDTCR_WDP0);
	SET_BIT(WDTCR, WDTCR_WDP1);
	SET_BIT(WDTCR, WDTCR_WDP2);
}

void WDT_vod_Disable(void)
{

	/* Write logical one to WDTOE and WDE */
	WDTCR |= (1<<WDTCR_WDE) | (1<<WDTCR_WDTOE);
	/* Turn off WDT */
	WDTCR = 0x00;
}

void WDT_vod_Set_Time(u8 Copy_u8_time)
{
	WDTCR &= 0x11111000;

	WDTCR |= Copy_u8_time;
}
