/*!
	@file 	RTC.h
	@brief	definiciones de funciones para el manejo de RTC
	@author	Bernardo Iniguez 
	@date	07/12/24

	Este archivo contiene las definiciones funciones para el manejo del RTC de los MCUs con procesador S08 de NXP-Freescale
*/
#ifndef RTC_H //RTC_IF
#define RTC_H

#include "S08_Common/S08_Families.h"
#include "S08_Common/S08_Variables.h"
#include "S08_Board.h"

#if MCU_ON_BOARD == S08_QE
	/*!
		@brief Bandera de interrupcion por RTC (QE)
	*/
	#define RTC_getFlag() 			RTCSC_RTIF		//Bandera de RTC
	/*!
		@brief Bandera de interrupcion por RTC (QE)
	*/
	#define RTC_getClockSource()	RTCSC_RTCLKS	//Fuente de reloj para el RTC
	/*!
		@enum eClock
		@brief Enum para seleccionar las fuentes de reloj
	*/
	typedef enum{
		eSource_1kHz, 		/*!< Fuente de reloj interna de 1kHz*/
		eSource_external, 	/*!< Fuente de reloj externa (Valor de RM: 1MHz)*/
		eSource_internal 	/*!< Fuente de reloj interna de 32kHz*/
	}eClock;
	/*!
		@enum ePrescaler
		@brief Enum para seleccionar el prescaler para el RTC
	*/
	typedef enum{
		ePrescaler_off,			/*!< Prescaler apagado*/
		ePrescaler_1,			/*!< Sin Prescaler*/
		ePrescaler_2,			/*!< Prescaler de 2*/
		ePrescaler_4,			/*!< Prescaler de 4*/
		ePrescaler_8,			/*!< Prescaler de 8*/
		ePrescaler_16,			/*!< Prescaler de 16*/
		ePrescaler_32,			/*!< Prescaler de 32*/
		ePrescaler_64,			/*!< Prescaler de 64*/
		ePrescaler_128,			/*!< Prescaler de 128*/
		ePrescaler_256,			/*!< Prescaler de 256*/
		ePrescaler_512,			/*!< Prescaler de 512*/
		ePrescaler_1024,		/*!< Prescaler de 1024*/
		ePrescaler_2048,		/*!< Prescaler de 2048*/
		ePrescaler_4096,		/*!< Prescaler de 4096*/
		ePrescaler_8192,		/*!< Prescaler de 8192*/
		ePrescaler_16384,		/*!< Prescaler de 16384*/
		ePrescaler_32748,		/*!< Prescaler de 32748*/
		ePrescaler_65536,		/*!< Prescaler de 65536*/
		ePrescaler_10,			/*!< Prescaler de 10*/
		ePrescaler_100,			/*!< Prescaler de 100*/
		ePrescaler_1000,		/*!< Prescaler de 1000*/
		ePrescaler_10000,		/*!< Prescaler de 10000*/
		ePrescaler_100000,		/*!< Prescaler de 100000*/
		ePrescaler_2000,		/*!< Prescaler de 2000*/
		ePrescaler_20000,		/*!< Prescaler de 20000*/
		ePrescaler_200000,		/*!< Prescaler de 200000*/
		ePrescaler_500,			/*!< Prescaler de 500*/
		ePrescaler_5000,		/*!< Prescaler de 5000*/
		ePrescaler_50000		/*!< Prescaler de 50000*/
	}ePrescaler;

#elif MCU_ON_BOARD == S08_PB
	/*!
		@brief Bandera de interrupcion por RTC (PB)
	*/
	#define RTC_getFlag() 			RTC_SC1_RTIF 
	/*!
		@brief Bandera de interrupcion por RTC (PB)
	*/
	#define RTC_getClockSource()	RTC_SC2_RTCLKS
	/*!
		@enum eClock
		@brief Enum para seleccionar las fuentes de reloj
	*/
	typedef enum{
		eSource_1kHz,		/*!< Fuente de reloj interna de 1kHz*/
		eSource_external,	/*!< Fuente de reloj externa (Valor de RM: 1MHz)*/
		eSource_internal,	/*!< Fuente de reloj interna de 32kHz*/
		eSource_bus			/*!< Fuente de reloj proveida por reloj de bus*/
	}eClock;
	/*!
		@enum ePrescaler
		@brief Enum para seleccionar el prescaler para el RTC
	*/
	typedef enum{
		ePrescaler_off,			/*!< Prescaler apagado*/
		ePrescaler_1,			/*!< Sin Prescaler*/
		ePrescaler_2,			/*!< Prescaler de 2*/
		ePrescaler_4,			/*!< Prescaler de 4*/
		ePrescaler_8,			/*!< Prescaler de 8*/
		ePrescaler_16,			/*!< Prescaler de 16*/
		ePrescaler_32,			/*!< Prescaler de 32*/
		ePrescaler_64,			/*!< Prescaler de 64*/
		ePrescaler_128,			/*!< Prescaler de 128*/
		ePrescaler_256,			/*!< Prescaler de 256*/
		ePrescaler_512,			/*!< Prescaler de 512*/
		ePrescaler_1024,		/*!< Prescaler de 1024*/
		ePrescaler_2048,		/*!< Prescaler de 2048*/
		ePrescaler_100,			/*!< Prescaler de 100*/
		ePrescaler_1000,		/*!< Prescaler de 1000*/
	}ePrescaler;
#endif

/*!
	@brief Seleccionar Prescaler para el RTC

	Esta funcion sirve para seleccionar el prescaler por el que pasara la senal de reloj fuente para generar diferentes tiempos, revisar el RM del microcontrolador para verificar las posibles combinaciones

	@param	prescaler_source valor deseado en el prescaler,
	
	ejemplo: ePrescaler_1024, para un prescaler de 1024; verificar los valores disponibles en el enum ePrescaler
	
	@warning Esta funcion depende de RTC_setClockSource, verificar en el RM para revisar las combinaciones posibles

	@return void
*/
void RTC_setPrescaler(ePrescaler prescaler_source);

/*!
	@brief Seleccionar la fuente de reloj para el RTC

	Esta funcion sirve para seleccionar la fuente del reloj para el RTC

	@param	clock_source seleccion de la fuente de reloj

			eSource_1kHz, para usar el oscilador interno de 1kHz
			eSource_external, para usar el oscilador externo
			eSource_internal, para usar el oscilador interno de 32kHz
	
	@return void
*/
void RTC_setClockSource(eClock clock_source);

/*!
	@brief Habilitar la interrupcion para el RTC
	
	@return void
*/
void RTC_enableInterrupt(void);

/*!
	@brief Deshabilitar la interrupcion para el RTC
	
	@return void
*/
void RTC_disableInterrupt(void);

/*!
	@brief Borra la bandera de termino de cuenta del RTC
	
	@return void
*/
void RTC_reset(void);

#if MCU_ON_BOARD == S08_QE
	/*!
		@brief Colocar cuenta objetivo para RTC

		Esta función sirve para colocar la cuenta con la cual el RTC encenderá el flag de terminacion y asi poder entrar a la interrupcion

		@param	u8count Cuenta objetivo

		@return void
	*/
	void 		RTC_setCount(uint8_t u8count);
	/*!
		@brief Obtener la cuenta actual del RTC 

		@return uint8_t
	*/
	uint8_t 	RTC_getCount(void);
#elif MCU_ON_BOARD == S08_PB
	/*!
		@brief Colocar cuenta objetivo para RTC

		Esta función sirve para colocar la cuenta con la cual el RTC encenderá el flag de terminacion y asi poder entrar a la interrupcion

		@param	u16count Cuenta objetivo

		@return void
	*/
	void 		RTC_setCount(uint16_t u16count);
	/*!
		@brief Obtener la cuenta actual del RTC 

		@return uint16_t
	*/
	uint16_t 	RTC_getCount(void);
#endif
	
#endif //End RTC_IF
