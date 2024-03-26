/*
 ============================================================================
 Name        : LED.h
 Author      : Omar Medhat Mohamed
 Description : Header file for the LED driver
 Date        : 12/12/2023
 ============================================================================
 */
#ifndef LED_H_
#define LED_H_

/*Include here Your Standard Types File that contains  typedef, SET,CLEAR,Toggle...etc */
#include "LIB/std_types.h"
#include "LIB/common_macros.h"
#include "LIB/Reg_Add.h"
#include "CFG/LED_cfg.h"
//define NULL
#define NULL ((void*)0)
/**
 *@brief : The Error List Type                                           
 */
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	LED_enumOk,  
	 /**
	 *@brief : Non Ok Configuration.
	 */
	LED_enumNotOk,          
	/**
	 *@brief : NULL Pointer is passed.
	 */
	LED_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	LED_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	LED_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	LED_enumWrongConfig,
	/**
	 *@brief : Select Active state Not Found .
	 */  
	LED_enumWrongActiveStatus,
	/**
	 *@brief : Select Output State Not Found .
	 */  
	LED_enumWrongOutputState,
	/**
	 *@brief : Select LED Not Found .
	 */
	LED_enumWrongLed,
	
}LED_enumErrorStatus_t;

/**
 *@brief :  Logic State Type : HIGH (5V) or LOW(0V )                     
 */
typedef enum
{   
	LED_enumLogicLow,
	LED_enumLogicHigh
}LED_enumLogicState_t;

/**
 *@brief  : Function to Configure the Pins of LED.
 *@param  :Void.
 *@return : Error State                                               
 */	
LED_enumErrorStatus_t LED_enumInit (void);

/**
 *@brief  : Function to set value to specific LED
 *@param  : LED name , Value of desired Output
 *@return : Error State                                                                      
 */
LED_enumErrorStatus_t LED_enumSetLedState(uint8 Copy_u8LedName, uint8 Copy_u8State);
/* Extern for global configuration Array*/


#endif /* DIO_H_ */
