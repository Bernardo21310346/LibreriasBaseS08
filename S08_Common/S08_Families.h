/*!
	@file 	S08_Families.h
	@brief	Definicion de parametros de arquitectura
	@author	Bernardo Iñiguez 
	@date	07/12/24

	Este archivo contiene las definiciones de las familias soportadas y los parametros para configurar los modulos
*/
#ifndef S08_FAMILIES_H
#define S08_FAMILIES_H
/*!
 * 	@defgroup Microcontroladores Microcontroladores soportados

	Aqui se definen las familias de S08 que las librerias pueden manejar de manera segura
	
	@{
 */
/*! 
	@brief Serie de microcontoladores MC9S08QE (MC9S08QE128 testeado)
    @ingroup Microcontroladores
*/
#define S08_QE  0x01
/*! 
	@brief Serie de microcontoladores MC9S08PB (MC9S08PB16 testeado)
    @ingroup Microcontroladores
 */
#define S08_PB  0x02
/*! @} */

/*!
 * @defgroup Control Etiquetas de control
 * @{
 */
/*! @brief Estado definido
    @ingroup Control
*/
#define DEFINED 0x01
/*! @} */


/*!
 * @defgroup TimerMachines Tipos de maquinas de eTimers
 * @{
 */
/*! @brief Usar RTC como Maquina de temporizador
    @ingroup TimerMachines
*/
#define RTC_TIMER_MACHINE 0x01
/*! @} */

#endif
