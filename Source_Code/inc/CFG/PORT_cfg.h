/*
 ============================================================================
 Name        : PORT_cfg.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the PORT driver
 Date        : 3/12/2023
 ============================================================================
 */
#ifndef PORT_CFG_H_
#define PORT_CFG_H_
#include "LIB/std_types.h"
#include "LIB/common_macros.h"
#include "PRIVATE/PORT_private.h"
/********************** Options **********************/

#define PORT_HIGH LOGIC_HIGH
#define PORT_LOW LOGIC_LOW

/********************** Micro Configuration **********************/
/*Options :
For NUM_OF_PORTS :
{
	 TWO_PORTS 	
	 THREE_PORTS 
	 FOUR_PORTS 
}

For NUM_OF_PINS & TOTAL_NUMBER_OF_PINS 
{
	 ONE_PIN 			
	 TWO_PINS 			
	 THREE_PINS			
	 FOUR_PINS			
	 FIVE_PINS			
	 SIX_PINS			
	 SEVEN_PINS			
	 EIGHT_PINS			
	 NINE_PINS       	
	 TEN_PINS        	
	 ELEVEN_PINS     	
	 TWELVE_PINS     	
	 THIRTEEN_PINS   	
	 FOURTEEN_PINS   	
	 FIFTEEN_PINS    	
	 SIXTEEN_PINS    	
	 SEVENTEEN_PINS  	
	 EIGHTEEN_PINS   	
	 NINETEEN_PINS   	
	 TWENTY_PINS     	
	 TWENTY_ONE_PINS 	
	 TWENTY_TWO_PINS 	
	 TWENTY_THREE_PINS 	
	 TWENTY_FOUR_PINS  	
	 TWENTY_FIVE_PINS  	
	 TWENTY_SIX_PINS   	
	 TWENTY_SEVEN_PINS 	
	 TWENTY_EIGHT_PINS 	
	 TWENTY_NINE_PINS  	
	 THIRTY_PINS       	
	 THIRTY_ONE_PINS   	
	 THIRTY_TWO_PINS   	
}

For CONFIGURATION_TYPE : 
{
	 Pre_Compile_Configuration 
	 POST_Compile_Configuration
}
*/
#define NUM_OF_PORTS 	FOUR_PORTS/*Place one of NUM_OF_PORTS Options*/
#define NUM_OF_PINS 	EIGHT_PINS/*Place one of NUM_OF_PINS*/
#define TOTAL_NUMBER_OF_PINS THIRTY_TWO_PINS
#define CONFIGURATION_TYPE	POST_Compile_Configuration/*Place one of Post_&Pre_CONFIGURATION Options*/

/**********************PINS Configuration**********************/
/*
Set a value from those 4 values to each PIN will be used
{
	INPUT_PU
	INPUT_HI
	OUTPUT_HIGH
	OUTPUT_LOW
}
*/

#define PORT_PIN0 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN1 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN2 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN3		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN4 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN5 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN6 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN7 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN8 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN9 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN10 		OUTPUT_LOW/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN11 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN12		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN13		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN14		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN15		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN16		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN17		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN18		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN19		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN20		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN21		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN22		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN23 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN24		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN25		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN26		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN27		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN28 		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN29		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN30		INPUT_HI/*Place one of PIN_CONFIGURATION Options */
#define PORT_PIN31		INPUT_HI/*Place one of PIN_CONFIGURATION Options */

/**********************Post compile configuration**********************/
typedef enum
{
	PORT_enumINPUT_PU,
	PORT_enumINPUT_HI,
	PORT_enumOUTPUT_HIGH,
	PORT_enumOUTPUT_LOW,
}PORT_enumpinopt_t;

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
}PORT_enumPortNum_t;


#endif /* PORT_CFG_H_ */
