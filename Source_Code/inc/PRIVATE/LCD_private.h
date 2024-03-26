/*
 ============================================================================
 Name        : LCD_private.h
 Author      : Omar Medhat Mohamed
 Description : Header private file for the LCD driver
 Date        : 30/12/2023
 ============================================================================
 */
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define EIGHT_BIT_MODE	8
#define FOUR_BIT_MODE	4

#define LCD_ZERO_COMMAND				0x00
#define FOUR_BITS_DATA_MODE				0x02
#define LCD_CLEAR_COMMAND              	0x01
#define LCD_GO_TO_HOME                 	0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  	0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   	0x28
#define LCD_CURSOR_OFF                 	0x0C
#define LCD_CURSOR_ON                  	0x0E
#define LCD_SET_CURSOR_LOCATION        	0x80

#define NUMBER_OF_MAX_COMMAND 	0xFF
#define NUMBER_OF_MAX_DATA 		0xFF
#define D0						0
#define D1						1
#define D2						2
#define D3						3
#define D4						4
#define D5						5
#define D6						6
#define D7						7
#define LCD_DISPLAY_LINE1		0
#define LCD_DISPLAY_LINE2		1
#define LCD_DISPLAY_LINE3		3
#define LCD_DISPLAY_LINE4		4


#endif
