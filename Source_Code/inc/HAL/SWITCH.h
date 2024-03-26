/*
 ============================================================================
 Name        : SWITCH.h
 Author      : Omar Medhat Mohamed
 Description : Header file for the SWITCH driver
 Date        : 12/12/2023
 ============================================================================
 */
#ifndef SWITCH_H_
#define SWITCH_H_

/*Include here Your Standard Types File that contains  typedef, SET,CLEAR,Toggle...etc */
#include "LIB/std_types.h"
#include "LIB/common_macros.h"
#include "LIB/Reg_Add.h"
#include "CFG/SWITCH_Cfg.h"
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
	SWITCH_enumOk,  
	 /**
	 *@brief : Non Ok Configuration.
	 */
	SWITCH_enumNotOk,          
	/**
	 *@brief : NULL Pointer is passed.
	 */
	SWITCH_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	SWITCH_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	SWITCH_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	SWITCH_enumWrongConfig,
	/**
	 *@brief : Select Active state Not Found .
	 */  
	SWITCH_enumWrongActiveStatus,
	/**
	 *@brief : Select Output State Not Found .
	 */  
	SWITCH_enumWrongInputState,
	/**
	 *@brief : Select SWITCH Not Found .
	 */
	SWITCH_enumWrongSWITCH,
	
}SWITCH_enumErrorStatus_t;

/**
 *@brief :  Logic State Type : HIGH (5V) or LOW(0V )                     
 */
typedef enum
{   
	SWITCH_enumLogicLow,
	SWITCH_enumLogicHigh
}SWITCH_enumLogicState_t;

/**
 *@brief  : Function to Configure the Pins of SWITCH.
 *@param  :Void.
 *@return : Error State                                               
 */	
SWITCH_enumErrorStatus_t SWITCH_enumInit (void);

/**
 *@brief  : Function to Read value to specific SWITCH
 *@param  : SWITCH name , Value of desired Output
 *@return : Error State                                                                      
 */
SWITCH_enumErrorStatus_t SWITCH_enumReadValue(uint8 Copy_u8SwitchName,uint8 * Add_u8State);

/* Extern for global configuration Array*/
extern SWITCH_strCfg SWITCHS[NUM_OF_SWITCHS] ; 

#endif /* DIO_H_ */
