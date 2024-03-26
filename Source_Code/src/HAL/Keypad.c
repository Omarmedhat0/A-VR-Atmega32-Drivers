/*
 ============================================================================
 Name        : Keypad.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the Keypad driver
 Date        : 9/1/2024
 ============================================================================
 */
#include "HAL/Keypad.h"
#include "LIB/Delay.h"
#include "MCAL/DIO.h"

/**
 * @brief   : Function to key number based on number of rows and number of column
 * @param   :(button_number) which will be send based on number of rows and number of column
			 (*Add_Pu8GetChar) pointer to store the charcter related to he number which will be pressed
 * @return  : Error State
 **/
static Keypad_enumErrorStatus_t KEYPAD_enumadjustKeyNumber(uint8 button_number , uint8* Add_Pu8GetChar);


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/**
 * @brief   : Function to initiat Keypad Driver based on mode of connection
 * 			  whether it was 4 or 8 bit mode 
 * @param   : Nothing
 * @return  : Error State
 **/
Keypad_enumErrorStatus_t Keypad_INIT (void)
{
	/* Variable to store the Keypad initialization status, initialized to Keypad_enumOk */
	Keypad_enumErrorStatus_t Loc_enumReturnKeypadErrorStatus = Keypad_enumOk ;
	/* Variable to store the DIO (Digital I/O) initialization status, initialized to DIO_enumOk */
	DIO_enumError_t 		Loc_enumReturnDIOErrorStatus = DIO_enumOk ;
	/* Loop through each pin used for Keypad control */
	uint8 Keypad_InitItr = 0 ; 
	for (Keypad_InitItr =0 ; Keypad_InitItr < KEYPAD_NUMBER_OF_PINS ;Keypad_InitItr ++)
	{
/* Case of 4*3 Keypad */
#if (KEYPAD_NUMBER_OF_PINS == 7)
        /* Configure input pins with internal pull-up for the first half of pins */
		if (Keypad_InitItr <= (KEYPAD_NUMBER_OF_PINS/2))
		{
			Loc_enumReturnDIOErrorStatus =DIO_enumSetPinConfig (Keypad[Keypad_InitItr].PORT,Keypad[Keypad_InitItr].PIN,DIO_enumInputInternalPU);
		}
		/* Configure output pins with logic high for the second half of pins */
		else if (Keypad_InitItr > (KEYPAD_NUMBER_OF_PINS/2))
		{
			DIO_enumSetPinConfig (Keypad[Keypad_InitItr].PORT,Keypad[Keypad_InitItr].PIN,DIO_enumOutput);
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(Keypad[Keypad_InitItr].PORT,Keypad[Keypad_InitItr].PIN,DIO_enumLogicHigh);
		}
/* Case of 3*3 Keypad or  4*4 Keypa */
#elif(KEYPAD_NUMBER_OF_PINS==6 || KEYPAD_NUMBER_OF_PINS ==8)
		if (Keypad_InitItr < (KEYPAD_NUMBER_OF_PINS/2))
		{
            /* If there is an issue with DIO configuration, set the Keypad status accordingly and exit the loop */
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPinConfig (Keypad[Keypad_InitItr].PORT,Keypad[Keypad_InitItr].PIN,DIO_enumInputInternalPU);
		}
		else if ( Keypad_InitItr >= (KEYPAD_NUMBER_OF_PINS/2))
		{
			DIO_enumSetPinConfig (Keypad[Keypad_InitItr].PORT,Keypad[Keypad_InitItr].PIN,DIO_enumOutput);
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(Keypad[Keypad_InitItr].PORT,Keypad[Keypad_InitItr].PIN,DIO_enumLogicHigh);
		}
#endif
		/* If there is an issue with DIO configuration, set the Keypad status accordingly and exit the loop */		if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
		{
			Loc_enumReturnKeypadErrorStatus = Keypad_enumNotOkDioProblem ;
			break ;
		}
		/* Continue with the next iteration */
		else{}
	}

	/* Return the Keypad initialization status */
	return Loc_enumReturnKeypadErrorStatus ;
}

/**
 * @brief   : 	Function to write data on Keypad  based on mode of connection
 * 			  	whether it was 6 or 7 or 8 bins mode 
 * @param   :	(* Add_Pu8PinData) pointer to store the state of 
 * 				switches of keypad and return the character equivalent to it
 * @return  : 	Error State
 **/
Keypad_enumErrorStatus_t Keypad_enuGetKey(uint8* Add_Pu8PinData)
{
	/* Variable to store the Keypad write data status, initialized to Keypad_enumOk */
	Keypad_enumErrorStatus_t 	Loc_enumReturnKeypadErrorStatus = Keypad_enumOk ;
	/* Variable to store the DIO (Digital I/O) status, initialized to DIO_enumOk */
	DIO_enumError_t 		Loc_enumReturnDIOErrorStatus = DIO_enumOk ;
    /* Iterators for the rows and columns of the Keypad */
	uint8 Keypad_GetItr1 = 0 ; 
	uint8 Keypad_GetItr2 = 0 ; 
    /* Variable to store the state of the pressed key */
	uint8 Keypad_ReadStatus = 0 ;
	uint8 flag_press = 0 ;
    /* Flag to indicate if a key press has been detected */
    /* Continue scanning until a key press is detected */
	while(flag_press==0)
	{
        /* Loop through the columns of the Keypad */
		for (Keypad_GetItr2 =  KEYPAD_NUM_ROWS; Keypad_GetItr2 < KEYPAD_NUMBER_OF_PINS ; Keypad_GetItr2 ++)
		{
            /* Set the current column pin to logic low to enable reading */
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(Keypad[Keypad_GetItr2].PORT,Keypad[Keypad_GetItr2].PIN,DIO_enumLogicLow);
            /* Loop through the rows of the Keypad */
			for (Keypad_GetItr1 =0 ; Keypad_GetItr1 < KEYPAD_NUM_ROWS ; Keypad_GetItr1++)
			{
                /* Read the state of the current row pin */
				Loc_enumReturnDIOErrorStatus = DIO_enumReadState(Keypad[Keypad_GetItr1].PORT,Keypad[Keypad_GetItr1].PIN,&Keypad_ReadStatus);
                /* Check for any DIO configuration issues */
				if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
				{
					Loc_enumReturnKeypadErrorStatus = Keypad_enumNotOkDioProblem ;
					break ;
				}
				else
				{}
                /* If a key is pressed, adjust the key number and store the corresponding character */
				if (Keypad_ReadStatus==KEYPAD_BUTTON_PRESSED)
				{
                    /* Adjust the key number based on the row and column, and get the corresponding character */
					Loc_enumReturnKeypadErrorStatus = KEYPAD_enumadjustKeyNumber (((Keypad_GetItr1*KEYPAD_NUM_COLS)+(Keypad_GetItr2-KEYPAD_NUM_ROWS) +1),&Keypad_ReadStatus);
                    /* Store the obtained character in the provided pointer */
					*Add_Pu8PinData = Keypad_ReadStatus ;
                    /* Set the flag to indicate that a key press has been detected */
					flag_press=1;
				}

			}
            /* Set the current column pin to logic high to disable reading */
			Loc_enumReturnDIOErrorStatus = DIO_enumSetPin(Keypad[Keypad_GetItr2].PORT,Keypad[Keypad_GetItr2].PIN,DIO_enumLogicHigh);
            /* Check for any DIO configuration issues */
			if (Loc_enumReturnDIOErrorStatus != DIO_enumOk)
			{
				Loc_enumReturnKeypadErrorStatus = Keypad_enumNotOkDioProblem ;
				break ;
			}
			else
			{}
		}
	}
	/* Return the Keypad error status */
	return Loc_enumReturnKeypadErrorStatus ;
}

/**
 * @brief   : Function to key number based on number of rows and number of column 
 * @param   :(button_number) which will be send based on number of rows and number of column 
			 (*Add_Pu8GetChar) pointer to store the charcter related to he number which will be pressed 
 * @return  : Error State   	
 **/
#if (KEYPAD_NUMBER_OF_PINS == 6)
static Keypad_enumErrorStatus_t KEYPAD_enumadjustKeyNumber(uint8 button_number , uint8* Add_Pu8GetChar)
{
	/* Variable to store the Keypad write data status, initialized to Keypad_enumOk */
	Keypad_enumErrorStatus_t 	Loc_enumReturnKeypadErrorStatus = Keypad_enumOk ;
	/* Check for a null pointer */
	if (Add_Pu8GetChar == NULL)
	{
		Loc_enumReturnKeypadErrorStatus = Keypad_enumNullPointer ;
	}
    /* Check if the button number is out of the valid range (1-9) */
	else if ((button_number ==0) || (button_number > 9))
	{
		Loc_enumReturnKeypadErrorStatus = Keypad_enumWrongCharacters ;
	}
	else
	{
        /* Adjust the key number by directly assigning it to the character pointer */
		*Add_Pu8GetChar = button_number ;
	}
	/* Return the Keypad error status */
	return Loc_enumReturnKeypadErrorStatus ;
}

#elif (KEYPAD_NUMBER_OF_PINS == 7)
static Keypad_enumErrorStatus_t KEYPAD_enumadjustKeyNumber(uint8 button_number , uint8* Add_Pu8GetChar)
{
	/* Variable to store the Keypad write data status, initialized to Keypad_enumOk */
	Keypad_enumErrorStatus_t 	Loc_enumReturnKeypadErrorStatus = Keypad_enumOk ;
    /* Check for a null pointer */
	if (Add_Pu8GetChar == NULL)
	{
		Loc_enumReturnKeypadErrorStatus = Keypad_enumNullPointer ;
	}
    /* Check if the button number is out of the valid range (1-9) */
	else if (button_number > 9)
	{
		Loc_enumReturnKeypadErrorStatus = Keypad_enumWrongCharacters ;
	}
	else
	{
        /* Adjust the key number based on a switch-case for special keys */
		switch (button_number)
		{
		case 10 :
			*Add_Pu8GetChar = '*' ;
			break ;
		case 11 :
			*Add_Pu8GetChar = '0' ;
			break ;
		case 12 :
			*Add_Pu8GetChar = '#' ;
			break ;

		default :
			*Add_Pu8GetChar = button_number ;
			break ;
		}

	}
	/* Return the Keypad error status */
	return Loc_enumReturnKeypadErrorStatus ;
}
#else 
static Keypad_enumErrorStatus_t KEYPAD_enumadjustKeyNumber(uint8 button_number , uint8* Add_Pu8GetChar)
{
	/* Variable to store the Keypad write data status, initialized to Keypad_enumOk */
	Keypad_enumErrorStatus_t 	Loc_enumReturnKeypadErrorStatus = Keypad_enumOk ;
    /* Check for a null pointer */
	if (Add_Pu8GetChar == NULL)
	{
		Loc_enumReturnKeypadErrorStatus = Keypad_enumNullPointer ;
	}
    /* Check if the button number is out of the valid range (1-16) */
	else if (button_number > 16)
	{
		Loc_enumReturnKeypadErrorStatus = Keypad_enumWrongCharacters ;
	}
	else
	{
        /* Adjust the key number based on a switch-case for special keys */
		switch (button_number)
		{
		case 1: *Add_Pu8GetChar = 7;
		break;
		case 2: *Add_Pu8GetChar = 8;
		break;
		case 3: *Add_Pu8GetChar = 9;
		break;
		case 4: *Add_Pu8GetChar = '/'; /* ASCII Code of '/' */
		break;
		case 5: *Add_Pu8GetChar = 4;
		break;
		case 6: *Add_Pu8GetChar = 5;
		break;
		case 7: *Add_Pu8GetChar = 6;
		break;
		case 8: *Add_Pu8GetChar = '*'; /* ASCII Code of '*' */
		break;
		case 9: *Add_Pu8GetChar = 1;
		break;
		case 10: *Add_Pu8GetChar = 2;
		break;
		case 11: *Add_Pu8GetChar = 3;
		break;
		case 12: *Add_Pu8GetChar = '-'; /* ASCII Code of '-' */
		break;
		case 13: *Add_Pu8GetChar = 13;  /* ASCII of Enter */
		break;
		case 14: *Add_Pu8GetChar = 0;
		break;
		case 15: *Add_Pu8GetChar = '='; /* ASCII Code of '=' */
		break;
		case 16: *Add_Pu8GetChar = '+'; /* ASCII Code of '+' */
		break;
		default: *Add_Pu8GetChar = button_number;
		break;
		}
	}
	/* Return the Keypad error status */
	return Loc_enumReturnKeypadErrorStatus ;
}
#endif
