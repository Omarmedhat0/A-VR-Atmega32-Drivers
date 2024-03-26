/*
 ============================================================================
 Name        : LCD.h
 Author      : Omar Medhat Mohamed
 Description : Header file for the LCD driver
 Date        : 30/12/2023
 ============================================================================
 */
#ifndef LCD_H_
#define LCD_H_
#define NULL ((void*)0)

/*******************************************************************************
 *                                Includes	                                  *
 *******************************************************************************/
#include  	"LIB/std_types.h"
#include  	"LIB/common_macros.h"
#include  	"LIB/Reg_Add.h"
#include 	"CFG/LCD_cfg.h"

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
	LCD_enumOk,               
	/**
	 *@brief : WRITE WRONG DATA ! .
	 */
	LCD_enumWrongDATA ,
	/**
	 *@brief : Error Duo to DIO.
	 */     
	LCD_enumNotOkDioProblem  ,
	/**
	 *@brief : Select Wrong Command.
	 */     
	LCD_enumWrongCommand  ,
	/**
	 *@brief : Select Wrong Number of Lines.
	 */
	LCD_enumWrongNumberOfLines , 
	/**
	 *@brief : Select Wrong Number of Characters.
	 */
	LCD_enumWrongNumberOfCharacters,
	/**
	 *@brief : Pinter carry NULL Value.
	 */
	LCD_enumNullPointer , 
	/**
	 *@brief : Select Wrong Number of Block on GRAM
	 */
	LCD_enumWrongBlockNumberOnGram


}LCD_enumErrorStatus_t;


/*******************************************************************************
 *                  	    Functions Prototypes                               *
 *******************************************************************************/
/**
 * @brief   : Function to initiat LCD Driver based on mode of connection
 * 			  whether it was 4 or 8 bit mode 
 * @param   : Nothing
 * @return  : Error State
 **/
LCD_enumErrorStatus_t LCD_INIT (void);

/**
 * @brief   : Function to write data on LCD  based on mode of connection
 * 			  whether it was 4 or 8 bit mode
 * @param   : (Copy_u8Data) Data which wanted to be write
 * @return  : Error State
 **/
LCD_enumErrorStatus_t LCD_enuWriteData(uint8 Copy_u8Data);

/**
 * @brief   : Function to write Command on LCD  based on mode of connection
 * 			  whether it was 4 or 8 bit mode
 * @param   : (Copy_u8Command) Command which wanted to be send to LCD MicroController
 * @return  : Error State
 * note some options for commands : 
		LCD_ZERO_COMMAND				
		FOUR_BITS_DATA_MODE				
		LCD_CLEAR_COMMAND              	
		LCD_GO_TO_HOME                 	
		LCD_TWO_LINES_EIGHT_BITS_MODE  	
		LCD_TWO_LINES_FOUR_BITS_MODE   	
		LCD_CURSOR_OFF                 	
		LCD_CURSOR_ON                  	
		LCD_SET_CURSOR_LOCATION        	
 **/
LCD_enumErrorStatus_t LCD_enuWriteCommand(uint8 Copy_u8Command);

/**
 * @brief   : 	Function to write on DDRam which responsible to print characters on LCD like move
 * 				the cursor to write a character on specific location
 * @param   :	(Copy_u8X) Which is number of row that user will write on it 
 * 				Options for Copy_u8X (LCD_DISPLAY_LINE1 , LCD_DISPLAY_LINE2 , LCD_DISPLAY_LINE3 , LCD_DISPLAY_LINE4)
 * 
 * 				(Copy_u8Y) Which is number of column that user will write on it 
 * 				Options for Copy_u8X (0:16)
 * @return  : 	Error State
 **/
LCD_enumErrorStatus_t LCD_enuGotoDDRAM_XY(uint8 Copy_u8X, uint8 Copy_u8Y);

/**
 * @brief   : 	Function to print an intgeral value on LCD
 * @param   :	(Copy_u8Number) Value in itegral form
 * @return  : 	Error State
 **/
LCD_enumErrorStatus_t LCD_enuWriteNumber(uint64 Copy_u8Number);

/**
 * @brief   : 	Function to print an a sting on LCD
 * @param   :	(Copy_pchPattern) Pointer to the string 
 * 				(Copy_u8Length) String Length
 * @return  : 	Error State
 **/
LCD_enumErrorStatus_t LCD_enuWriteString(uint8* Copy_pchPattern, uint8 Copy_u8Length);

/**
 * @brief   : 	Function to print an a special character on LCD based on it's drawing
 * @param   :	(Copy_pu8Patternn) Pointer to the array whice carry the shape of the character
 * 				(Copy_u8CGRAMBlockNumber) Number of block in GRAM which will save the character on it
 * 				(Copy_u8X) Which is number of row that user will write on it 
 * 				Options for Copy_u8X (LCD_DISPLAY_LINE1 , LCD_DISPLAY_LINE2 , LCD_DISPLAY_LINE3 , LCD_DISPLAY_LINE4)
 * 
 * 				(Copy_u8Y) Which is number of column that user will write on it 
 * 				Options for Copy_u8X (0:16)
 * 			
 * @return  : 	Error State
 **/
LCD_enumErrorStatus_t LCD_enuDisplaySpecialPattern(uint8* Copy_pu8Pattern, uint8 Copy_u8CGRAMBlockNumber, uint8 Copy_u8X, uint8 Copy_u8Y);

/*extern for Global configuartion array in LCD_cfg.c*/
extern LCD_strCfg LCD[LCD_PINS_MODE] ;

#endif /* LCD_H_ */
