/*
 ============================================================================
 Name        : Keypad_cfg.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the Keypad driver
 Date        : 9/1/2024
 ============================================================================
 */
#ifndef Keypad_CFG_H_
#define Keypad_CFG_H_

#include "LIB/std_types.h"
#include "PRIVATE/Keypad_private.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NULL ((void*)0)

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                  4
#define KEYPAD_NUM_ROWS                  4
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH

/* Define keypad number of pins */
#if ((KEYPAD_NUM_ROWS ==3 ) && (KEYPAD_NUM_COLS == 3))
#define KEYPAD_NUMBER_OF_PINS	6
#elif ((KEYPAD_NUM_ROWS == 4 ) && (KEYPAD_NUM_COLS == 3))
#define KEYPAD_NUMBER_OF_PINS	7
#elif ((KEYPAD_NUM_ROWS == 4 ) && (KEYPAD_NUM_COLS == 4))
#define KEYPAD_NUMBER_OF_PINS	8
#else
#error "Wrong number of rows or column"
#endif

typedef enum
{  
	Keypad_enumPortA,
	Keypad_enumPortB,
	Keypad_enumPortC,
	Keypad_enumPortD
}Keypad_enumPorts_t;

/**
 *@brief : The PINS Type of the AVR Atmega32                            
 */
typedef enum
{
	Keypad_enumPin0,
	Keypad_enumPin1,
	Keypad_enumPin2,
	Keypad_enumPin3,
	Keypad_enumPin4,
	Keypad_enumPin5,
	Keypad_enumPin6,
	Keypad_enumPin7
}Keypad_enumPins_t;


typedef struct
{
	Keypad_enumPorts_t 	PORT ;
	Keypad_enumPins_t	PIN	 ;
}Keypad_strCfg;

#endif
