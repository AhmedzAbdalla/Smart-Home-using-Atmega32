/*
 * RTC_DS1307_inteface.h
 *
 *  Created on: Apr 27, 2023
 *      Author: Ahmed Abdalla
 */


#ifndef RTC_DS1307_INTERFACE_H
#define RTC_DS1307_INTERFACE_H

typedef struct {
    u8 seconds;
    u8 minutes;
    u8 hours;
    u8 days;
    u8 months;
    u8 years;
}RTC_t;

void RTC_DS1307_RTC_t_Get_Date_Time(u8 *const Ref_RTC_t_ret_rtc );

void RTC_DS1307_RTC_t_Print_Date_Time(u8 *const Ref_RTC_t_ret_rtc );

#endif //RTC_DS1307_INTERFACE_H