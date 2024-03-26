/*
 ============================================================================
 Name        : SevenSegment_cfg.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the SevenSegment driver
 Date        : 18/12/2023
 ============================================================================
 */
#ifndef SevenSegment_CFG_H_
#define SevenSegment_CFG_H_

#include "LIB/std_types.h"
#include "PRIVATE/SevenSegment_private.h"

/* Number of SevenSegments in System*/
#define NUM_OF_SEVENSEGMENTS 4
/*Number OF PINS for each Seven Segment*/
#define NUM_OF_PINS_PER_SEVENSEGMENTS 8
/******SevenSegment_lIST*****/
#define SEVENSEGMENTS1 0
#define SEVENSEGMENTS2 1
#define SEVENSEGMENTS3 2
#define SEVENSEGMENTS4 3


/**
 *@brief : The ports Type of the AVR Atmega32                            
 */
typedef enum 
{
	SevenSegment_enumPORTA,
	SevenSegment_enumPORTB,
	SevenSegment_enumPORTC,
	SevenSegment_enumPORTD,
}SevenSegment_enumPortNumber_t;

/**
 *@brief :  Pins Type of the AVR Atmega32                                                
 */
typedef enum 
{
	SevenSegment_enumPIN0 ,
	SevenSegment_enumPIN1 , 
	SevenSegment_enumPIN2 ,
	SevenSegment_enumPIN3 ,
	SevenSegment_enumPIN4 ,
	SevenSegment_enumPIN5 ,
	SevenSegment_enumPIN6 ,
	SevenSegment_enumPIN7 ,
}SevenSegment_enumPinNumber_t;

/**
 *@brief : Active Status type                                                    
 */
typedef enum 
{
	SevenSegment_enum_CommonCathode,
	SevenSegment_enum_CommonAnode,
}SevenSegment_enumActiveStatus_t;

/**
 *@brief :  LEDS of Seven Segment Names                                                   
 */
typedef enum 
{
	SevenSegment_enumLedA ,
	SevenSegment_enumLedB , 
	SevenSegment_enumLedC ,
	SevenSegment_enumLedD ,
	SevenSegment_enumLedE ,
	SevenSegment_enumLedF ,
	SevenSegment_enumLedG ,
	SevenSegment_enumLedDP ,
}SevenSegment_enumLedID_t;

/**
 *@brief : Struct for Each SevenSegment in the driver                                                  
 */
typedef struct 
{
	SevenSegment_enumPortNumber_t 	LEDA_Port ;
	SevenSegment_enumPinNumber_t 	LEDA_Pin ;
	SevenSegment_enumPortNumber_t 	LEDB_Port ;
	SevenSegment_enumPinNumber_t 	LEDB_Pin ;
	SevenSegment_enumPortNumber_t 	LEDC_Port ;
	SevenSegment_enumPinNumber_t 	LEDC_Pin ;
	SevenSegment_enumPortNumber_t 	LEDD_Port ;
	SevenSegment_enumPinNumber_t 	LEDD_Pin ;
	SevenSegment_enumPortNumber_t 	LEDE_Port ;
	SevenSegment_enumPinNumber_t 	LEDE_Pin ;
	SevenSegment_enumPortNumber_t 	LEDF_Port ;
	SevenSegment_enumPinNumber_t 	LEDF_Pin ;
	SevenSegment_enumPortNumber_t 	LEDG_Port ;
	SevenSegment_enumPinNumber_t 	LEDG_Pin ;
	SevenSegment_enumPortNumber_t 	LEDDP_Port ;
	SevenSegment_enumPinNumber_t 	LEDDP_Pin ;				
	SevenSegment_enumActiveStatus_t Active_Status ;
}SevenSegment_strCfg;

#endif
