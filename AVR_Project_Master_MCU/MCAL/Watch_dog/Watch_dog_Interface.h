/*
 * Watch_dog_cfg.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Ahmed Abdalla
 */


#ifndef MCAL_WATCH_DOG_WATCH_DOG_INTERFACE_H_
#define MCAL_WATCH_DOG_WATCH_DOG_INTERFACE_H_

#define Reset_Time 0b00000111




void WDT_vod_Enable(void);

void WDT_vod_Disable(void);

void WDT_vod_Set_Time(u8 Copy_u8_time);




#endif /* MCAL_WATCH_DOG_WATCH_DOG_INTERFACE_H_ */
