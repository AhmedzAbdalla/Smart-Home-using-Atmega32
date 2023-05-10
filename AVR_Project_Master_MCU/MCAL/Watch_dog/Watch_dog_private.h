/*
 * Watch_dog_cfg.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef MCAL_WATCH_DOG_WATCH_DOG_PRIVATE_H_
#define MCAL_WATCH_DOG_WATCH_DOG_PRIVATE_H_

#define WDTCR 						(*((volatile u8 *)0x41))

#define WDTCR_WDP0 			0x00
#define WDTCR_WDP1 			0x01
#define WDTCR_WDP2 			0x02
#define WDTCR_WDE 			0x03
#define WDTCR_WDTOE 		0x04



#endif /* MCAL_WATCH_DOG_WATCH_DOG_PRIVATE_H_ */
