/*
 * RTC_DS1307_private.h
 *
 *  Created on: Apr 27, 2023
 *      Author: Ahmed Abdalla
 */


#ifndef RTC_DS1307_PRIVATE_H
#define RTC_DS1307_PRIVATE_H

#define SECONDS_REG     0x00
#define MINUTES_REG     0x01
#define HOURS_REG       0x02
#define DAYS_REG        0x03
#define MONTHS_REG      0x04
#define YEARS_REG       0x05

#define RTC_DS1307_address  0x68

#define ROW_1   0x01
#define ROW_2   0x02

#define BCD_HIGH_NIBBLE_MASK	0x0f
#define BCD_LOW_NIBBLE_MASK	0x04

#endif //RTC_DS1307_PRIVATE_H
