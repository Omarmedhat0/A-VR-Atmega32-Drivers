 /*
 ============================================================================
 Name        :Keypad.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the Keypad driver
 Date        :9/1/2024
 ============================================================================
 */

#include "CFG/Keypad_cfg.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* Global configuration array for Keypad Pins and its communication with AVR
   based on the mode of connection, whether it was 4 or 8 bit mode */
#if ((KEYPAD_NUM_ROWS ==3 ) && (KEYPAD_NUM_COLS == 3))
Keypad_strCfg Keypad[KEYPAD_NUMBER_OF_PINS] =
{
	[PIN1]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 1 configuration */
	[PIN2]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 2 configuration */
	[PIN3]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 3 configuration */
	[PIN4]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 4 configuration */
	[PIN5]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 5 configuration */
	[PIN6]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 6 configuration */
};
#elif ((KEYPAD_NUM_ROWS == 4 ) && (KEYPAD_NUM_COLS == 3))
Keypad_strCfg Keypad[KEYPAD_NUMBER_OF_PINS] =
{
	[PIN1]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 1 configuration */
	[PIN2]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 2 configuration */
	[PIN3]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 3 configuration */
	[PIN4]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 4 configuration */
	[PIN5]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 5 configuration */
	[PIN6]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 6 configuration */
	[PIN7]={.PORT=Keypad_enumPortA , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 7 configuration */
};
#elif ((KEYPAD_NUM_ROWS == 4 ) && (KEYPAD_NUM_COLS == 4))
Keypad_strCfg Keypad[KEYPAD_NUMBER_OF_PINS] =
{
	[PIN1]={.PORT=Keypad_enumPortB , .PIN=Keypad_enumPin0} ,  /* Keypad Pin 1 configuration */
	[PIN2]={.PORT=Keypad_enumPortB , .PIN=Keypad_enumPin1} ,  /* Keypad Pin 2 configuration */
	[PIN3]={.PORT=Keypad_enumPortB , .PIN=Keypad_enumPin2} ,  /* Keypad Pin 3 configuration */
	[PIN4]={.PORT=Keypad_enumPortB , .PIN=Keypad_enumPin3} ,  /* Keypad Pin 4 configuration */
	[PIN5]={.PORT=Keypad_enumPortB , .PIN=Keypad_enumPin4} ,  /* Keypad Pin 5 configuration */
	[PIN6]={.PORT=Keypad_enumPortB , .PIN=Keypad_enumPin5} ,  /* Keypad Pin 6 configuration */
	[PIN7]={.PORT=Keypad_enumPortB , .PIN=Keypad_enumPin6} ,  /* Keypad Pin 7 configuration */
	[PIN8]={.PORT=Keypad_enumPortB , .PIN=Keypad_enumPin7} ,  /* Keypad Pin 8 configuration */
};
#else
/* Error message for incorrect keypad configuration */
#error "Wrong number of rows or column"  
#endif
