   /*
 ============================================================================
 Name        : LCD_cfg.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the LCD driver
 Date        : 30/12/2023
 ============================================================================
 */

#include "CFG/LCD_cfg.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* 	Global configuration array for LCD Pins and it's communication with AVR
	based on the mode of connectionwhether it was 4 or 8 bit mode */
#if (LCD_PINS_MODE ==EIGHT_BIT_MODE )
LCD_strCfg LCD[LCD_PINS_CONTROL]=
{
	[D0]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin0} ,
	[D1]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin1} ,
	[D2]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin2} ,
	[D3]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin3} ,
	[D4]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin4} ,
	[D5]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin5} ,
	[D6]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin6} ,
	[D7]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin7} ,
	[RS]={.PORT=LCD_enumPortA ,.PIN=LCD_enumPin2} ,
	[RW]={.PORT=LCD_enumPortA ,.PIN=LCD_enumPin1} ,
	[E]={.PORT=LCD_enumPortA ,.PIN=LCD_enumPin0} 
};

#elif (LCD_PINS_MODE == FOUR_BIT_MODE)
LCD_strCfg LCD[LCD_PINS_CONTROL]=
{
	[D0]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin4} ,
	[D1]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin5} ,
	[D2]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin6} ,
	[D3]={.PORT=LCD_enumPortC ,.PIN=LCD_enumPin7} ,
	[RS]={.PORT=LCD_enumPortA ,.PIN=LCD_enumPin2} ,
	[RW]={.PORT=LCD_enumPortA ,.PIN=LCD_enumPin1} ,
	[E]={.PORT=LCD_enumPortA ,.PIN=LCD_enumPin0} 
};

#else 
#error "Wrong configuration for number of control bits"

#endif
