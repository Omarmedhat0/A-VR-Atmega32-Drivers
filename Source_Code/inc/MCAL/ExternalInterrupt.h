/*
 ============================================================================
 Name        : ExternalInterrupt.h
 Author      : Omar Medhat Mohamed
 Description : Header file for the ExternalInterrupt driver
 Date        : 30/12/2023
 ============================================================================
 */
#ifndef EXINT_H_
#define EXINT_H_

/*******************************************************************************
 *                                Includes	                                  *
 *******************************************************************************/
#include  	"LIB/std_types.h"
#include  	"LIB/common_macros.h"
#include  	"LIB/Reg_Add.h"
#include 	"CFG/ExternalInterrupt_cfg.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*Options :
State which Interrupt will be Enable or Disable
*/
#define INT0_Mode	Enable
#define INT1_Mode	Enable
#define INT2_Mode	Enable

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/**
 *@brief : The ports Type of the AVR Atmega32                            
 */
typedef enum
{  
	EXINT_enumPortA,
	EXINT_enumPortB,
	EXINT_enumPortC,
	EXINT_enumPortD
}EXINT_enumPorts_t;

/**
 *@brief :  The PINS Type of the AVR Atmega32                                                 
 */
typedef enum
{
	EXINT_enumPin0,
	EXINT_enumPin1,
	EXINT_enumPin2,
	EXINT_enumPin3,
	EXINT_enumPin4,
	EXINT_enumPin5,
	EXINT_enumPin6,
	EXINT_enumPin7
}EXINT_enumPins_t;


/**
 *@brief : The Error List Type                                           
 */
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	EXINT_enumOk,             
	/**
	 *@brief : NULL Pointer is passed.
	 */
	EXINT_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	EXINT_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	EXINT_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	EXINT_enumWrongConfig  ,
	/**
	 *@brief : Select External Interrupt type Not Found .
	 */     
	EXINT_enumWrongEXINT  


}EXINT_enumError_t;

/**
 *@brief : The Configuration Type of Pins to be Input or Output !        
 */
typedef enum
{	
 EXINT_enumINT0 ,
 EXINT_enumINT1 ,
 EXINT_enumINT2
}EXINT_enumName_t;



/*******************************************************************************
 *                  	    Functions Prototypes                               *
 *******************************************************************************/
/**
 * @brief   : Function to initiat Pins as external Interrupt
 * @param   : Nothing
 * @return  : Error State
 **/
EXINT_enumError_t EXINT_INIT (void);

/**
 * @brief   : Set callback function for External Interrupt INT0
 * @param   : a_ptr - Pointer to the callback function
 * @return  : None
 **/
void EXINT0_setCallBack(void(*a_ptr)(void)) ;
/**
 * @brief   : Set callback function for External Interrupt INT1
 * @param   : a_ptr - Pointer to the callback function
 * @return  : None
 **/
void EXINT1_setCallBack(void(*a_ptr)(void)) ;
/**
 * @brief   : Set callback function for External Interrupt INT2
 * @param   : a_ptr - Pointer to the callback function
 * @return  : None
 **/
void EXINT2_setCallBack(void(*a_ptr)(void)) ;

#endif /* EXINT_H_ */
