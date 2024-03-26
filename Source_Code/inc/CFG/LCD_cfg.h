/*
 ============================================================================
 Name        : LCD_cfg.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the LCD driver
 Date        : 30/12/2023
 ============================================================================
 */
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "LIB/std_types.h"
#include "PRIVATE/LCD_private.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NULL ((void*)0)

/*Configure mode of LCD connection whether it is FOUR_BIT_MODE or EIGHT_BIT_MODE */
#define LCD_PINS_MODE FOUR_BIT_MODE
/*Configure Maximum number of rows in LCD */
#define MAX_NUM_OF_LINES 		2
/*Configure Maximum number of column in LCD */
#define MAX_NUM_OF_CHARACTERS 	16

/* Define number of control PINS for LCD based on 
 mode of LCD connection whether it is FOUR_BIT_MODE or EIGHT_BIT_MODE*/
#if (LCD_PINS_MODE == EIGHT_BIT_MODE )
#define LCD_PINS_CONTROL 11
#define	RS						8
#define	RW						9
#define	E						10
#elif (LCD_PINS_MODE == FOUR_BIT_MODE)
#define LCD_PINS_CONTROL 7
#define	RS						4
#define	RW						5
#define	E						6
#endif
			

/**
 *@brief : The PORTS Type of the AVR Atmega32                            
 */
typedef enum
{  
	LCD_enumPortA,
	LCD_enumPortB,
	LCD_enumPortC,
	LCD_enumPortD
}LCD_enumPorts_t;

/**
 *@brief : The PINS Type of the AVR Atmega32                            
 */
typedef enum
{
	LCD_enumPin0,
	LCD_enumPin1,
	LCD_enumPin2,
	LCD_enumPin3,
	LCD_enumPin4,
	LCD_enumPin5,
	LCD_enumPin6,
	LCD_enumPin7
}LCD_enumPins_t;

/**
 *@brief : 	Struct for carry information about PORT and PIN number for each pin
 * 			on AVR connected to LCD                          
 */
typedef struct 
{
	LCD_enumPorts_t	 PORT	;
	LCD_enumPins_t	 PIN	;
}LCD_strCfg;

#endif
