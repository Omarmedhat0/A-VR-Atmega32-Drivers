/*
 ============================================================================
 Name        : SevenSegment.h
 Author      : Omar Medhat Mohamed
 Description : Header file for the SevenSegment driver
 Date        : 18/12/2023
 ============================================================================
 */
#ifndef SevenSegment_H_
#define SevenSegment_H_

/*Include here Your Standard Types File that contains  typedef, SET,CLEAR,Toggle...etc */
#include "LIB/std_types.h"
#include "LIB/common_macros.h"
#include "LIB/Reg_Add.h"
#include "CFG/SevenSegment_Cfg.h"
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
	SevenSegment_enumOk,  
	 /**
	 *@brief : Non Ok Configuration.
	 */
	SevenSegment_enumNotOk,          
	/**
	 *@brief : NULL Pointer is passed.
	 */
	SevenSegment_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	SevenSegment_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	SevenSegment_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	SevenSegment_enumWrongConfig,
	/**
	 *@brief : Select Active state Not Found .
	 */  
	SevenSegment_enumWrongActiveStatus,
	/**
	 *@brief : Select Output State Not Found .
	 */  
	SevenSegment_enumWrongValue,
	/**
	 *@brief : Select SevenSegment Not Found .
	 */
	SevenSegment_enumWrongSevenSegment,
	
}SevenSegment_enumErrorStatus_t;

/**
 *@brief :  Logic State Type : HIGH (5V) or LOW(0V )                     
 */
typedef enum
{   
	SevenSegment_enumLogicLow,
	SevenSegment_enumLogicHigh
}SevenSegment_enumLogicState_t;

/**
 *@brief  : Function to Configure the Pins of SevenSegment.
 *@param  :Void.
 *@return : Error State                                               
 */	
SevenSegment_enumErrorStatus_t SevenSegment_enumInit (void);

/**
 *@brief  : Function to set value to specific SevenSegment
 *@param  : SevenSegment name , Value of desired Output
 *@return : Error State                                                                      
 */
SevenSegment_enumErrorStatus_t SevenSegment_enumSetValue(uint8 Copy_u8SegName, uint8 Value);

/**
 * @brief   Function to set a common value for all SevenSegment displays.
 * @param   Value: The value to be displayed on all SevenSegment displays.
 * @return  Error State indicating the success or failure of the operation.
 * 
 */
SevenSegment_enumErrorStatus_t SevenSegment_enumSetValueForAll(uint32 Value);

/* Extern for global configuration Array*/
extern SevenSegment_strCfg SevenSegmentS[NUM_OF_SEVENSEGMENTS] ; 

#endif /* DIO_H_ */
