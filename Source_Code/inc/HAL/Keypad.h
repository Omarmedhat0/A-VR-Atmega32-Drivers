/*
 ============================================================================
 Name        : Keypad.h
 Author      : Omar Medhat Mohamed
 Description : Header file for the Keypad driver
 Date        : 9/1/2024
 ============================================================================
 */
#ifndef Keypad_H_
#define Keypad_H_
#define NULL ((void*)0)

/*******************************************************************************
 *                                Includes	                                  *
 *******************************************************************************/
#include  	"LIB/std_types.h"
#include  	"LIB/common_macros.h"
#include  	"LIB/Reg_Add.h"
#include 	"CFG/Keypad_cfg.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


/**
 *@brief : The Error List Type                                           
 */
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	Keypad_enumOk,               
	/**
	 *@brief : Error Duo to DIO.
	 */     
	Keypad_enumNotOkDioProblem  ,
	/**
	 *@brief : Select Wrong Number of Characters.
	 */
	Keypad_enumWrongCharacters,
	/**
	 *@brief : Pinter carry NULL Value.
	 */
	Keypad_enumNullPointer 
}Keypad_enumErrorStatus_t;


/*******************************************************************************
 *                  	    Functions Prototypes                               *
 *******************************************************************************/
/**
 * @brief   : Function to initiat Keypad Driver based on mode of connection
 * 			  whether it was 4 or 8 bit mode 
 * @param   : Nothing
 * @return  : Error State
 **/
Keypad_enumErrorStatus_t Keypad_INIT (void) ;

/**
 * @brief   : 	Function to write data on Keypad  based on mode of connection
 * 			  	whether it was 6 or 7 or 8 bins mode 
 * @param   :	(* Add_Pu8PinData) pointer to store the state of 
 * 				switches of keypad and return the character equivalent to it
 * @return  : 	Error State
 **/
Keypad_enumErrorStatus_t Keypad_enuGetKey(uint8* Add_Pu8PinData) ;


#if ((KEYPAD_NUM_ROWS ==3 ) && (KEYPAD_NUM_COLS == 3))
/* External declaration for Keypad array with 6 pins */
extern Keypad_strCfg Keypad[KEYPAD_NUMBER_OF_PINS] ;
#elif ((KEYPAD_NUM_ROWS == 4 ) && (KEYPAD_NUM_COLS == 3))
/* External declaration for Keypad array with 7 pins */
extern Keypad_strCfg Keypad[KEYPAD_NUMBER_OF_PINS];
#elif ((KEYPAD_NUM_ROWS == 4 ) && (KEYPAD_NUM_COLS == 4))
/* External declaration for Keypad array with 8 pins */
extern Keypad_strCfg Keypad[KEYPAD_NUMBER_OF_PINS]; 
#else
/* External declaration for Keypad array with 8 pins */
#error "Wrong number of rows or column"
#endif
#endif /* Keypad_H_ */
