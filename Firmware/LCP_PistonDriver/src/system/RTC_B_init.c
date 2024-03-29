/*
 *  This file is automatically generated and does not require a license
 *
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 */
#include <driverlib/inc/hw_memmap.h>
#include <driverlib/rtc_c.h>
#include <system/System.h>

/* USER CODE START (section: RTC_C_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: RTC_C_init_c_prologue) */

static RTC_C_configureCalendarAlarmParam alarmParam = {
      .minutesAlarm = 59,
      .hoursAlarm = RTC_C_ALARMCONDITION_OFF,
      .dayOfWeekAlarm = RTC_C_ALARMCONDITION_OFF,
      .dayOfMonthAlarm = RTC_C_ALARMCONDITION_OFF
 
};

/*
 *  ======== RTC_C_Init ========
 *  Initialize Config for the MSP430 RTC_C
 */
void RTC_C_Init(void)
{
    /* Struct to pass to RTC_C_CalendarInit() */
    Calendar calendarTime;

    /* USER CODE START (section: RTC_C_Init_prologue) */
    /* User initialization code */
    /* USER CODE END (section: RTC_C_Init_prologue) */
    

    /* Initialize the Calendar struct */
    calendarTime.Seconds = 0;
    calendarTime.Minutes = 0;
    calendarTime.Hours = 0;
    calendarTime.DayOfWeek = 3;
    calendarTime.DayOfMonth = 1;
    calendarTime.Month = 1;
    calendarTime.Year = 2020;

    /* Initialize the settings to operate the RTC in Calendar mode */
    RTC_C_initCalendar(RTC_C_BASE, &calendarTime, RTC_C_FORMAT_BCD);

    /* Set and enable the desired Calendar Alarm settings */
    RTC_C_configureCalendarAlarm(RTC_C_BASE, &alarmParam);


    /* Set a single specified Calendar interrupt condition */
    RTC_C_setCalendarEvent(RTC_C_BASE, RTC_C_CALENDAREVENT_MINUTECHANGE);

    /* Enable selected RTC interrupt sources */
    RTC_C_enableInterrupt(RTC_C_BASE, RTC_C_CLOCK_ALARM_INTERRUPT);

    /* Start the RTC */
    RTC_C_startClock(RTC_C_BASE);

    /* USER CODE START (section: RTC_C_Init_epilogue) */
    /* User code */
    /* USER CODE END (section: RTC_C_Init_epilogue) */
}

