/*
 ============================================================================
 Name        : SWITCH_cfg.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the SWITCH driver
 Date        : 12/12/2023
 ============================================================================
 */
#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

#include "LIB/std_types.h"

/* Number of SWITCHs in System*/
#define NUM_OF_SWITCHS 3

/******SWITCH_lIST*****/
#define SWITCH1 0
#define SWITCH2 1
#define SWITCH3 2

/**
 *@brief : The ports Type of the AVR Atmega32                            
 */
typedef enum 
{
	SWITCH_enumPORTA,
	SWITCH_enumPORTB,
	SWITCH_enumPORTC,
	SWITCH_enumPORTD,
}SWITCH_enumPortNumber_t;

/**
 *@brief :  Pins Type                                                    
 */
typedef enum 
{
	SWITCH_enumPIN0 ,
	SWITCH_enumPIN1 , 
	SWITCH_enumPIN2 ,
	SWITCH_enumPIN3 ,
	SWITCH_enumPIN4 ,
	SWITCH_enumPIN5 ,
	SWITCH_enumPIN6 ,
	SWITCH_enumPIN7 ,
}SWITCH_enumPinNumber_t;

/**
 *@brief : Active Status type                                                    
 */
typedef enum 
{
	SWITCH_enum_PullUpRes,
	SWITCH_enum_ExternalPullDown,
}SWITCH_enumActiveStatus_t;

/**
 *@brief : Struct for Each SWITCH in the driver                                                  
 */
typedef struct 
{
	SWITCH_enumPortNumber_t 	Port ;
	SWITCH_enumPinNumber_t 		Pin ;
	SWITCH_enumActiveStatus_t 	Active_Status ;
}SWITCH_strCfg;

#endif
