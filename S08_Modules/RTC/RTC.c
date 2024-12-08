/*!
	@file 	RTC.c
	@brief	Funciones para el manejo de RTC
	@author	Bernardo Iñiguez 
	@date	07/12/24

	Este archivo contiene las funciones para el manejo del RTC de los MCUs con procesador S08 de NXP-Freescale
*/
#include "RTC.h"

#if MCU_ON_BOARD == S08_QE

void RTC_setPrescaler(ePrescaler prescaler_source)
{
	if(prescaler_source == ePrescaler_off)
	{
		RTCSC_RTCPS = 0x00;
	}
	else if((prescaler_source == ePrescaler_8) || ((prescaler_source == ePrescaler_1024) && (RTC_getClockSource() == 0x01)))
	{
		RTCSC_RTCPS = 0x01;
	}
	else if((prescaler_source == ePrescaler_32) || (prescaler_source == ePrescaler_2048))
	{
		RTCSC_RTCPS = 0x02;
	}
	else if((prescaler_source == ePrescaler_64) || (prescaler_source == ePrescaler_4096))
	{
		RTCSC_RTCPS = 0x03;
	}
	else if((prescaler_source == ePrescaler_128) || (prescaler_source == ePrescaler_8192))
	{
		RTCSC_RTCPS = 0x04;
	}
	else if((prescaler_source == ePrescaler_256) || (prescaler_source == ePrescaler_16384))
	{
		RTCSC_RTCPS = 0x05;
	}
	else if((prescaler_source == ePrescaler_512) || (prescaler_source == ePrescaler_32748))
	{
		RTCSC_RTCPS = 0x06;
	}
	else if((prescaler_source == ePrescaler_512) || (prescaler_source == ePrescaler_32748))
	{
		RTCSC_RTCPS = 0x06;
	}
	else if(((prescaler_source == ePrescaler_1024) && (RTC_getClockSource() == 0x00)) || (prescaler_source == ePrescaler_65536))
	{
		RTCSC_RTCPS = 0x07;
	}
	else if((prescaler_source == ePrescaler_1) || ((prescaler_source == ePrescaler_1024) && (RTC_getClockSource() == 0x01)))
	{
		RTCSC_RTCPS = 0x08;
	}
	else if((prescaler_source == ePrescaler_2) || (prescaler_source == ePrescaler_2000))
	{
		RTCSC_RTCPS = 0x09;
	}
	else if((prescaler_source == ePrescaler_4) || (prescaler_source == ePrescaler_5000))
	{
		RTCSC_RTCPS = 0x0A;
	}
	else if((prescaler_source == ePrescaler_10) || (prescaler_source == ePrescaler_10000))
	{
		RTCSC_RTCPS = 0x0B;
	}
	else if((prescaler_source == ePrescaler_16) || (prescaler_source == ePrescaler_20000))
	{
		RTCSC_RTCPS = 0x0C;
	}
	else if((prescaler_source == ePrescaler_100) || (prescaler_source == ePrescaler_50000))
	{
		RTCSC_RTCPS = 0x0D;
	}
	else if((prescaler_source == ePrescaler_500) || (prescaler_source == ePrescaler_100000))
	{
		RTCSC_RTCPS = 0x0E;
	}
	else if(((prescaler_source == ePrescaler_1000) && (RTC_getClockSource() == 0x00)) || (prescaler_source == ePrescaler_200000))
	{
		RTCSC_RTCPS = 0x07;
	}
}

void RTC_setClockSource(eClock clock_source)
{
	if(clock_source == eSource_1kHz)
	{
		RTCSC_RTCLKS = 0x00;
	}
	else if(clock_source == eSource_external)
	{
		RTCSC_RTCLKS = 0x01;
	}
	else if(clock_source == eSource_internal)
	{
		RTCSC_RTCLKS = 0x10;
	}
}

void RTC_enableInterrupt(void)
{
	RTCSC_RTIE = 0x01;
}

void RTC_disableInterrupt(void)
{
	RTCSC_RTIE = 0x00;
}

void RTC_setCount(uint8_t u8count)
{
	RTCMOD = u8count;
}

void RTC_reset(void)
{
	RTCSC = RTCSC | 0x80;
}

uint8_t RTC_getCount(void)
{
	return RTCCNT;
}

#endif

#if MCU_ON_BOARD == S08_PB

#endif
