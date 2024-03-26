/*
 ============================================================================
 Name        : LCD.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the LCD driver
 Date        : 30/12/2023
 ============================================================================
 */
#include "HAL/LCD.h"
#include "LIB/Delay.h"
#include "MCAL/DIO.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/**
 * @brief   : Function to initiat LCD Driver based on mode of connection
 * 			  whether it was 4 or 8 bit mode 
 * @param   : Nothing
 * @return  : Error State
 **/
LCD_enumErrorStatus_t LCD_INIT (void)
{
	/* Variable to store the LCD initialization status, initialized to LCD_enumOk */
	LCD_enumErrorStatus_t Loc_enumReturnLCDErrorStatus = LCD_enumOk ;
	/* Variable to store the DIO (Digital I/O) initialization status, initialized to DIO_enumOk */
	DIO_enumError_t 		Loc_enumReturnDIOErrorStatus = DIO_enumOk ;
	/* Loop through each pin used for LCD control */
	uint8 Itr_LCD_init =0 ;
	for (Itr_LCD_init=0 ; Itr_LCD_init<LCD_PINS_CONTROL ; Itr_LCD_init ++)
	{
        /* Set the pin configuration for the current LCD pin as an output */
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPinConfig(LCD[Itr_LCD_init].PORT,LCD[Itr_LCD_init].PIN,DIO_enumOutput);
        /* Check if there is an error in setting the pin configuration */
		if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
		{
            /* If an error occurs, set the LCD initialization status accordingly and break out of the loop */
			Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
			break ;
		}
        /* No error in setting the pin configuration, continue with the next iteration */
		else{}
	}
    /* If LCD is configured in eight-bit mode */
	#if ((LCD_PINS_MODE == EIGHT_BIT_MODE ))
    /* Check if there was no error in DIO initialization */
	if(Loc_enumReturnLCDErrorStatus == LCD_enumOk)
	{
        /* Write commands to initialize the LCD in eight-bit mode */
		Loc_enumReturnLCDErrorStatus = LCD_enuWriteCommand (LCD_TWO_LINES_EIGHT_BITS_MODE);
		delay(1);
		Loc_enumReturnLCDErrorStatus = LCD_enuWriteCommand (LCD_CURSOR_OFF);
		delay(1);
		Loc_enumReturnLCDErrorStatus = LCD_enuWriteCommand (LCD_CLEAR_COMMAND);
		delay(1);
	}
	else{}
	/* Check if LCD is configured in four-bit mode */
	#elif (LCD_PINS_MODE == FOUR_BIT_MODE)
    /* Check if there was no error in DIO initialization */
	if(Loc_enumReturnLCDErrorStatus == LCD_enumOk)
	{
		/* Write commands to initialize the LCD in four-bit mode */
		Loc_enumReturnLCDErrorStatus = LCD_enuWriteCommand (FOUR_BITS_DATA_MODE);
		delay(1);
		Loc_enumReturnLCDErrorStatus = LCD_enuWriteCommand (LCD_TWO_LINES_FOUR_BITS_MODE);
		delay(1);
		Loc_enumReturnLCDErrorStatus = LCD_enuWriteCommand (LCD_CURSOR_OFF);
		delay(1);
		Loc_enumReturnLCDErrorStatus = LCD_enuWriteCommand (LCD_CLEAR_COMMAND);
		delay(1);
	}
    /* No need for additional actions if there was an error in DIO initialization */
	else{}
	#endif
	/* Return the LCD initialization status */
	return Loc_enumReturnLCDErrorStatus ;
}

/**
 * @brief   : Function to write data on LCD  based on mode of connection
 * 			  whether it was 4 or 8 bit mode
 * @param   : (Copy_u8Data) Data which wanted to be write
 * @return  : Error State
 **/
LCD_enumErrorStatus_t LCD_enuWriteData(uint8 Copy_u8Data)
{
    /* Variable to store the LCD write data status, initialized to LCD_enumOk */
	LCD_enumErrorStatus_t 	Loc_enumReturnLCDErrorStatus = LCD_enumOk ;
    /* Variable to store the DIO (Digital I/O) status, initialized to DIO_enumOk */
	DIO_enumError_t 		Loc_enumReturnDIOErrorStatus = DIO_enumOk ;
    /* Iterator for LCD pins */
	uint8 LCD_itr 		= 0 ;
    /* Variable to store the state of the LCD data bit */
	uint8 LCD_BitState 	= 0 ;
    /* Variable to carry four nibbles in four-bit mode */
	#if (LCD_PINS_MODE == FOUR_BIT_MODE)
	uint8 LCD_CarryFourNibbles 	= 0 ;
	#endif

	/* Check if the provided data is within the valid range */
	if (Copy_u8Data > NUMBER_OF_MAX_DATA)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumWrongDATA;
	}
	else
	{
		/* Set LCD data pins to output high (logic high) if state of eoor variable is ok */
		Loc_enumReturnLCDErrorStatus = LCD_enumOk ;
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[RS].PORT,LCD[RS].PIN,DIO_enumLogicHigh) ;
        /* Check if there is an error in setting the RS pin */
		if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
		{
			Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
		}
        /* No error in setting the RS pin, continue with the next operation */
		else{}
        /* Set the R/W pin to logic low (write operation) */
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[RW].PORT,LCD[RW].PIN,DIO_enumLogicLow) ;

        /* Check if there is an error in setting the R/W pin */
		if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
		{
			Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
		}
        /* No error in setting the R/W pin, continue with the next operation */
		else{}
        /* If there is no error in previous operations, proceed with setting data pins */
		if (Loc_enumReturnLCDErrorStatus==LCD_enumOk)
		{
            /* In Case of Eight BIT MODE
            	Loop through each bit of the data */
			#if (LCD_PINS_MODE == EIGHT_BIT_MODE)
			for (LCD_itr=0 ; LCD_itr<LCD_PINS_MODE ; LCD_itr++)
			{
                /* Get the state of the current bit */
				LCD_BitState = Copy_u8Data % 2 ;

                /* Set the corresponding LCD data pin to the current bit state */
				Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[LCD_itr].PORT,LCD[LCD_itr].PIN,LCD_BitState) ;

                /* Check if there is an error in setting the data pin */
				if (Loc_enumReturnDIOErrorStatus!=DIO_enumOk)
				{
					Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
					break ;
				}
                /* No error in setting the data pin, continue with the next iteration */
				else{}
                /* Move to the next bit */
				Copy_u8Data=Copy_u8Data / 2 ;
			}

			/* Check if LCD is configured in four-bit mode */
			#elif (LCD_PINS_MODE == FOUR_BIT_MODE)
		    /* Extract the high nibble of the data */
			LCD_CarryFourNibbles = GET_HIGH_NIB(Copy_u8Data);
		    /* Loop through each bit of the high nibble */
			for (LCD_itr=0 ; LCD_itr<LCD_PINS_MODE ; LCD_itr++)
			{
		        /* Get the state of the current bit in the high nibble */
				LCD_BitState = LCD_CarryFourNibbles % 2 ;

		        /* Set the corresponding LCD data pin to the current bit state */
				Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[LCD_itr].PORT,LCD[LCD_itr].PIN,LCD_BitState) ;

		        /* Check if there is an error in setting the data pin */
				if (Loc_enumReturnDIOErrorStatus!=DIO_enumOk)
				{
					Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
					break ;
				}
	            /* No error in setting the data pin, continue with the next iteration */
				else{}
		        /* Move to the next bit in the high nibble */
				LCD_CarryFourNibbles=LCD_CarryFourNibbles / 2 ;
			}

		    /* Reset the variable holding the high nibble value */
			LCD_CarryFourNibbles=0;
		    /* Set the Enable (E) pin to logic high */
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[E].PORT,LCD[E].PIN,DIO_enumLogicHigh) ;
			delay(2);
		    /* Set the Enable (E) pin to logic low */
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[E].PORT,LCD[E].PIN,DIO_enumLogicLow) ;
		    /* Extract the low nibble of the data */
			LCD_CarryFourNibbles=GET_LOW_NIB(Copy_u8Data);
		    /* Loop through each bit of the low nibble */
			for (LCD_itr=0 ; LCD_itr<LCD_PINS_MODE ; LCD_itr++)
			{
		        /* Get the state of the current bit in the low nibble */
				LCD_BitState = LCD_CarryFourNibbles % 2 ;
		        /* Set the corresponding LCD data pin to the current bit state */
				Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[LCD_itr].PORT,LCD[LCD_itr].PIN,LCD_BitState) ;
		        /* Check if there is an error in setting the data pin */
				if (Loc_enumReturnDIOErrorStatus!=DIO_enumOk)
				{
					Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
					break ;
				}
	            /* No error in setting the data pin, continue with the next iteration */
				else{}
		        /* Move to the next bit in the low nibble */
				LCD_CarryFourNibbles=LCD_CarryFourNibbles / 2 ;
			}

			#endif
		}
		/* Set the Enable (E) pin to logic high */
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[E].PORT,LCD[E].PIN,DIO_enumLogicHigh) ;
		delay(2);
	    /* Set the Enable (E) pin to logic low */
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[E].PORT,LCD[E].PIN,DIO_enumLogicLow) ;    /* Check if there is an error in setting the Enable (E) pin */
	
	    /* Check if there is an error in setting the Enable (E) pin */
		if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
		{
			Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
		}
	}
	/* Return the LCD write data status */
	return Loc_enumReturnLCDErrorStatus ;;
}

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
LCD_enumErrorStatus_t LCD_enuWriteCommand(uint8 Copy_u8Command)
{
    /* Variable to store the LCD write data status, initialized to LCD_enumOk */
	LCD_enumErrorStatus_t 	Loc_enumReturnLCDErrorStatus = LCD_enumOk ;
    /* Variable to store the DIO (Digital I/O) status, initialized to DIO_enumOk */
	DIO_enumError_t 		Loc_enumReturnDIOErrorStatus = DIO_enumOk ;
    /* Iterator for LCD pins */
	uint8 LCD_itr 		= 0 ;
    /* Variable to store the state of the LCD data bit */
	uint8 LCD_BitState 	= 0 ;
    /* Variable to carry four nibbles in four-bit mode */
	#if (LCD_PINS_MODE == FOUR_BIT_MODE)
	uint8 LCD_CarryFourNibbles 	= 0 ;
	#endif
	/* Check if the provided data is within the valid range */
	if (Copy_u8Command > NUMBER_OF_MAX_COMMAND)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumWrongCommand;
	}
	else
	{
		/* Set LCD data pins to output high (logic high) if state of error variable is ok */
		Loc_enumReturnLCDErrorStatus = LCD_enumOk ;
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[RS].PORT,LCD[RS].PIN,DIO_enumLogicLow) ;
        /* Check if there is an error in setting the RS pin */
		if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
		{
			Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
		}
        /* No error in setting the RS pin, continue with the next operation */
		else{}
        /* Set the R/W pin to logic low (write operation) */
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[RW].PORT,LCD[RW].PIN,DIO_enumLogicLow) ;

        /* Check if there is an error in setting the R/W pin */
		if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
		{
			Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
		}
        /* No error in setting the R/W pin, continue with the next operation */
		else{}
        /* If there is no error in previous operations, proceed with setting data pins */
		if (Loc_enumReturnLCDErrorStatus==LCD_enumOk)
		{
			/* In Case of Eight BIT MODE
            Loop through each bit of the data */
			#if (LCD_PINS_MODE == EIGHT_BIT_MODE )
			for (LCD_itr=0 ; LCD_itr<LCD_PINS_MODE ; LCD_itr++)
			{
                /* Get the state of the current bit */
				LCD_BitState = Copy_u8Command % 2 ;

                /* Set the corresponding LCD data pin to the current bit state */
				Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[LCD_itr].PORT,LCD[LCD_itr].PIN,LCD_BitState) ;
                /* Check if there is an error in setting the data pin */
				if (Loc_enumReturnDIOErrorStatus!=DIO_enumOk)
				{
					Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
					break ;
				}
                /* No error in setting the data pin, continue with the next iteration */
				else{}
                /* Move to the next bit */
				Copy_u8Command=Copy_u8Command / 2 ;
			}

			/* Check if LCD is configured in four-bit mode */
			#elif (LCD_PINS_MODE == FOUR_BIT_MODE)
		    /* Extract the high nibble of the data */
			LCD_CarryFourNibbles = GET_HIGH_NIB(Copy_u8Command);
		    /* Loop through each bit of the high nibble */
			for (LCD_itr=0 ; LCD_itr<LCD_PINS_MODE ; LCD_itr++)
			{
		        /* Get the state of the current bit in the high nibble */
				LCD_BitState = LCD_CarryFourNibbles % 2 ;
		        /* Set the corresponding LCD data pin to the current bit state */
				Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[LCD_itr].PORT,LCD[LCD_itr].PIN,LCD_BitState) ;
		        /* Check if there is an error in setting the data pin */
				if (Loc_enumReturnDIOErrorStatus!=DIO_enumOk)
				{
					Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
					break ;
				}
	            /* No error in setting the data pin, continue with the next iteration */
				else{}
		        /* Move to the next bit in the high nibble */
				LCD_CarryFourNibbles=LCD_CarryFourNibbles / 2 ;
			}
		    /* Reset the variable holding the high nibble value */
			LCD_CarryFourNibbles=0;
		    /* Set the Enable (E) pin to logic high */
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[E].PORT,LCD[E].PIN,DIO_enumLogicHigh) ;
			delay(2);
		    /* Set the Enable (E) pin to logic low */
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[E].PORT,LCD[E].PIN,DIO_enumLogicLow) ;
		    /* Extract the low nibble of the data */
			LCD_CarryFourNibbles=GET_LOW_NIB(Copy_u8Command);
		    /* Loop through each bit of the low nibble */
			for (LCD_itr=0 ; LCD_itr<LCD_PINS_MODE ; LCD_itr++)
			{
		        /* Get the state of the current bit in the low nibble */
				LCD_BitState = LCD_CarryFourNibbles % 2 ;
		        /* Set the corresponding LCD data pin to the current bit state */
				Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[LCD_itr].PORT,LCD[LCD_itr].PIN,LCD_BitState) ;
		        /* Check if there is an error in setting the data pin */
				if (Loc_enumReturnDIOErrorStatus!=DIO_enumOk)
				{
					Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
					break ;
				}
	            /* No error in setting the data pin, continue with the next iteration */
				else{}
		        /* Move to the next bit in the low nibble */
				LCD_CarryFourNibbles=LCD_CarryFourNibbles / 2 ;
			}

			#endif
		}
		/* Set the Enable (E) pin to logic high */
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[E].PORT,LCD[E].PIN,DIO_enumLogicHigh) ;
		delay(2);
	    /* Set the Enable (E) pin to logic low */
		Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(LCD[E].PORT,LCD[E].PIN,DIO_enumLogicLow) ;

	    /* Check if there is an error in setting the Enable (E) pin */
		if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
		{
			Loc_enumReturnLCDErrorStatus = LCD_enumNotOkDioProblem ;
		}
	}
	/*  the LCD write data status */
	return Loc_enumReturnLCDErrorStatus ;
}

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
LCD_enumErrorStatus_t LCD_enuGotoDDRAM_XY(uint8 Copy_u8X, uint8 Copy_u8Y)
{
    /* Variable to store the LCD goto DDRAM status, initialized to LCD_enumOk */
	LCD_enumErrorStatus_t Loc_enumReturnLCDErrorStatus = LCD_enumOk ;

    /* Variable to store the location on DDRAM based on X and Y coordinates */
	uint8 Loc_u8LCDLoctaionOnDDRAM = 0 ;
    /* Check if the X coordinate is within the number of lines supported by the LCD */
	if (Copy_u8X >= MAX_NUM_OF_LINES)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumWrongNumberOfLines ;
	}
    /* Check if the Y coordinate is within the number of characters per line supported by the LCD */
	else if (Copy_u8Y >= MAX_NUM_OF_CHARACTERS)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumWrongNumberOfCharacters ;
	}
	else
	{
        /* Calculate the location on DDRAM based on X and Y coordinates */
        /* If the desired row which will print the character on it is row 1 */
		if (Copy_u8X==LCD_DISPLAY_LINE1)
		{
			Loc_u8LCDLoctaionOnDDRAM = Copy_u8Y ;
		}
		 /* If the desired row which will print the character on it is row 2 */
		else if (Copy_u8X==LCD_DISPLAY_LINE2)
		{
			Loc_u8LCDLoctaionOnDDRAM = Copy_u8Y +0x40 ;
		}
		 /* If the desired row which will print the character on it is row 3 */
		else if (Copy_u8X==LCD_DISPLAY_LINE3)
		{
			Loc_u8LCDLoctaionOnDDRAM = Copy_u8Y +0x10 ;
		}
		 /* If the desired row which will print the character on it is row 4 */
		else if (Copy_u8X==LCD_DISPLAY_LINE4)
		{
			Loc_u8LCDLoctaionOnDDRAM = Copy_u8Y +0x50 ;
		}
        /* Invalid X coordinate value */
		else{}
        /* Write the command to set the cursor position in DDRAM */
		Loc_enumReturnLCDErrorStatus= LCD_enuWriteCommand(128+Loc_u8LCDLoctaionOnDDRAM);
	}

    /* Return the LCD goto DDRAM status */
	return Loc_enumReturnLCDErrorStatus ;
}

/**
 * @brief   : 	Function to print an intgeral value on LCD
 * @param   :	(Copy_u8Number) Value in itegral form
 * @return  : 	Error State
 **/
LCD_enumErrorStatus_t LCD_enuWriteNumber(uint64 Copy_u8Number)
{
    /* Variable to store the LCD write  error status, initialized to LCD_enumOk */
	LCD_enumErrorStatus_t Loc_enumReturnLCDErrorStatus = LCD_enumOk ; 
    /* Buffer to hold the ASCII representation of the number */
	uint8 buff[16]; /* String to hold the ascii result */
	/*Local variable to hold number of character in provided number*/
	uint8 Char_num =0 ; 
	/*Local variable to holdthe ASCI represnation to the required number*/
	uint8 ASCIReb =0 ;
	/*Temp Variable to hold the desired number to convert it to string */
	uint64 Temp =Copy_u8Number ;

	/*While loop to count the number of character in provided number*/
	while(Temp>=1)
	{
		if (Copy_u8Number==0)
		{
			Char_num ++ ;
			break ;
		}
		else
		{
			Char_num ++ ;
			Temp=Temp/10;
		}
	}
	/*Put a null operator at the end of buffer array after calculate
	  the number of character in the provided number
	*/
	buff[Char_num]='\0';
	/*While loop to convert each digit in the number to a character and store it in buffer array*/
	while(Char_num!=0)
	{
		/* get the number which wll be converted*/
		Temp=Copy_u8Number%10;
		/*Store the ASCI of the number */
		ASCIReb = '0' + Temp ;
		/*But the ASCI of the number in the buffer array*/
		buff[Char_num-1]=ASCIReb;
		/*Switch to the next digit*/
		Copy_u8Number=Copy_u8Number/10;
		/*Decreament the counter */
		Char_num--;
	}
   	/* Display the string on the LCD */
   	LCD_enuWriteString(buff,16); /* Display the string */

    /* Return the LCD write error status */
	return Loc_enumReturnLCDErrorStatus ;
}

/**
 * @brief   : 	Function to print an a sting on LCD
 * @param   :	(Copy_pchPattern) Pointer to the string 
 * 				(Copy_u8Length) String Length
 * @return  : 	Error State
 **/
LCD_enumErrorStatus_t LCD_enuWriteString(uint8* Copy_pchPattern, uint8 Copy_u8Length)
{
    /* Variable to store the LCD write string error status, initialized to LCD_enumOk */
	LCD_enumErrorStatus_t Loc_enumReturnLCDErrorStatus = LCD_enumOk ;

    /* Iterator for writing each character of the string */
	uint8 Loc_u8LCDWRitr = 0 ;
    /* Check for a null pointer */
	if (Copy_pchPattern == NULL)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumNullPointer ; 
	}
    /* Check if the length of the string exceeds the maximum number of characters supported by the LCD */
	else if (Copy_u8Length>MAX_NUM_OF_CHARACTERS)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumWrongNumberOfCharacters ;
	}
	else 
	{
        /* Loop through each character in the string and write it to the LCD */
		for (Loc_u8LCDWRitr=0 ; ((Copy_pchPattern[Loc_u8LCDWRitr]!='\0')&&(Loc_u8LCDWRitr < Copy_u8Length)) ; Loc_u8LCDWRitr++)
		{
			Loc_enumReturnLCDErrorStatus= LCD_enuWriteData(Copy_pchPattern[Loc_u8LCDWRitr]);
		}
	}
    /* Return the LCD write string error status */
	return Loc_enumReturnLCDErrorStatus ;
}

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
LCD_enumErrorStatus_t LCD_enuDisplaySpecialPattern(uint8* Copy_pu8Pattern, uint8 Copy_u8CGRAMBlockNumber, uint8 Copy_u8X, uint8 Copy_u8Y)
{
	/* Variable to store the LCD display special pattern error status, initialized to LCD_enumOk */
	LCD_enumErrorStatus_t Loc_enumReturnLCDErrorStatus = LCD_enumOk ;
    /* Variables to store the location on CGRAM, iterator, and pattern */
	uint8 Loc_u8LCDLoctaionOnCGRAM = 0 ;
	uint8 Loc_u8LCDDSPitr = 0 ;

	/* Check for a null pointer */
	if (Copy_pu8Pattern == NULL)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumNullPointer ; 
	}
    /* Check if the CGRAM block number is within the valid range (0-7) */
	else if (Copy_u8CGRAMBlockNumber > 7)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumWrongBlockNumberOnGram ;
	}
    /* Check if the X coordinate is within the number of lines supported by the LCD */
	else if (Copy_u8X >=  MAX_NUM_OF_LINES)
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumWrongNumberOfLines ;
	}
    /* Check if the Y coordinate is within the number of characters per line supported by the LCD */
	else if (Copy_u8Y>= MAX_NUM_OF_CHARACTERS )
	{
		Loc_enumReturnLCDErrorStatus = LCD_enumWrongNumberOfCharacters ;
	}
	else
	{
        /* Calculate the location on CGRAM based on the CGRAM block number */
		Loc_u8LCDLoctaionOnCGRAM = Copy_u8CGRAMBlockNumber * 8 ;
        /* Write command to set the cursor position in CGRAM */
		Loc_enumReturnLCDErrorStatus= LCD_enuWriteCommand (64 + Loc_u8LCDLoctaionOnCGRAM) ;
        /* Loop through each pattern byte in the CGRAM block and write it to the LCD */
		for (Loc_u8LCDDSPitr=0 ; Loc_u8LCDDSPitr < 8 ;Loc_u8LCDDSPitr++)
		{
			Loc_enumReturnLCDErrorStatus = LCD_enuWriteData(Copy_pu8Pattern[Loc_u8LCDDSPitr]);
			
		}
        /* Set the cursor position in DDRAM based on X and Y coordinates */
		Loc_enumReturnLCDErrorStatus = LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
        /* Write the CGRAM block number to the LCD */
		Loc_enumReturnLCDErrorStatus = LCD_enuWriteData(Copy_u8CGRAMBlockNumber);
		 
	}
    /* Return the LCD display special pattern status */
	return Loc_enumReturnLCDErrorStatus ;
}
