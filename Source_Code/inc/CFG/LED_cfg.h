/*
 ============================================================================
 Name        : LED_cfg.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the LED driver
 Date        : 12/12/2023
 ============================================================================
 */

#ifndef LED_CFG_H_
#define LED_CFG_H_
#include "LIB/std_types.h"
/* Number of LEds in System*/
#define NUM_OF_LEDS 3

/******LED_lIST*****/
#define LED1 0
#define LED2 1
#define LED3 2

/**
 *@brief : The ports Type of the AVR Atmega32
 */
typedef enum
{
	LED_enumPORTA,
	LED_enumPORTB,
	LED_enumPORTC,
	LED_enumPORTD,
}LED_enumPortNumber_t;

/**
 *@brief :  Pins Type
 */
typedef enum
{
	LED_enumPIN0 ,
	LED_enumPIN1 ,
	LED_enumPIN2 ,
	LED_enumPIN3 ,
	LED_enumPIN4 ,
	LED_enumPIN5 ,
	LED_enumPIN6 ,
	LED_enumPIN7 ,
}LED_enumPinNumber_t;

/**
 *@brief : Active Status type
 */
typedef enum
{
	LED_enum_ActiveLow,
	LED_enum_ActiveHigh,
}LED_enumActiveStatus_t;

/**
 *@brief : Output Status type
 */
typedef enum
{
	LED_enum_Off,
	LED_enum_On,
}LED_enumOutputState_t;


/**
 *@brief : Struct for Each LED in the driver
 */
typedef struct
{
	LED_enumPortNumber_t 	Port ;
	LED_enumPinNumber_t 	Pin ;
	LED_enumActiveStatus_t 	Active_Status ;
	LED_enumOutputState_t 	Output_Status;
}LED_strCfg;

#endif
