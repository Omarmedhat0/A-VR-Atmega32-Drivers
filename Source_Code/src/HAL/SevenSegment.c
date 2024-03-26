/*
 ============================================================================
 Name        : SevenSegment.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the SevenSegment driver
 Date        : 12/12/2023
 ============================================================================
 */

#include "MCAL/DIO.h"
#include "CFG/SevenSegment_cfg.h"
#include "HAL/SevenSegment.h"

/**
 * @brief  : Function to Configure the Pins of SevenSegment.
 * @param  : Void.
 * @return : Error State
 */
SevenSegment_enumErrorStatus_t SevenSegment_enumInit(void)
{
	/* Declare variables to store error states for DIO and SevenSegment operations */
	DIO_enumError_t Loc_enumReturnErrorDIOErrorState = DIO_enumOk;
	/* Declare variables to store error states for SevenSegment operations */
	SevenSegment_enumErrorStatus_t Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk;
	/* Declare variables to store the number of SevenSegments and Pins */
	uint8 Loc_U8SevenSegmentNum = 0 ;
	/* Declare variables to store current LED in Seven segment */
	uint8 Loc_u8LedNum = 0 ;
	/*Declare counter to Loop */
	uint8 counter = 0 ;
	/* Declare variables to store error states for DIO and SevenSegment operations */
	uint8 Loc_u8SevenSegmentActiveStatus = 0 ;
	/* Check the active status of the seven-segment display (Common Cathode or Common Anode) */

	for (counter = 0; ((counter < NUM_OF_SEVENSEGMENTS*NUM_OF_PINS_PER_SEVENSEGMENTS) && (Loc_enumReturnErrorSevenSegmentErrorState == SevenSegment_enumOk)); counter++)
	{

		/*Detect which Seven segment i work on*/
		Loc_U8SevenSegmentNum = (uint8)(counter / NUM_OF_PINS_PER_SEVENSEGMENTS) ;
		/*Detect which LED from Seven segment i work on*/
		Loc_u8LedNum =  (uint8)(counter % NUM_OF_PINS_PER_SEVENSEGMENTS) ;
		/*Handle Common Cathode case*/
		if (SevenSegmentS[Loc_U8SevenSegmentNum].Active_Status==SevenSegment_enum_CommonCathode)
		{
			/* Set Error status variable to Ok*/
			Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk ;
			/*Initiate Common Cathode Led by Zero at first*/
			Loc_u8SevenSegmentActiveStatus = DIO_enumLogicLow ;
		}
		else if (SevenSegmentS[Loc_U8SevenSegmentNum].Active_Status==SevenSegment_enum_CommonAnode)
		{
			/* Set Error status variable to Ok*/
			Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk ;
			/*Initiate Common Anode Led by Zero at first*/
			Loc_u8SevenSegmentActiveStatus = DIO_enumLogicHigh;
		}
		else
		{
			/* REturn error status with wrong configuration */
			Loc_enumReturnErrorSevenSegmentErrorState= SevenSegment_enumWrongConfig;
		}
		/*Check if error state variable is Ok or not*/
		if (Loc_enumReturnErrorSevenSegmentErrorState==SevenSegment_enumOk)
		{
			/* Set the DIO pin configuration for the current SevenSegment */
			switch (Loc_u8LedNum)
			{
			/*For Led A in 7 Segment*/
			case SevenSegment_enumLedA :
				/*Set PIN as an Output PIN*/
				DIO_enumSetPinConfig(SevenSegmentS[Loc_U8SevenSegmentNum].LEDA_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDA_Pin, DIO_enumOutput);
				/*Put an Initial Value to The PIN  according to it's active status*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(SevenSegmentS[Loc_U8SevenSegmentNum].LEDA_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				break ;
			/*For Led B in 7 Segment*/
			case SevenSegment_enumLedB :
				/*Set PIN as an Output PIN*/
				DIO_enumSetPinConfig(SevenSegmentS[Loc_U8SevenSegmentNum].LEDB_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDB_Pin, DIO_enumOutput);
				/*Put an Initial Value to The PIN  according to it's active status*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(SevenSegmentS[Loc_U8SevenSegmentNum].LEDB_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDB_Pin,Loc_u8SevenSegmentActiveStatus);
				break ;
			/*For Led C in 7 Segment*/
			case SevenSegment_enumLedC :
				/*Set PIN as an Output PIN*/
				DIO_enumSetPinConfig(SevenSegmentS[Loc_U8SevenSegmentNum].LEDC_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDC_Pin, DIO_enumOutput);
				/*Put an Initial Value to The PIN according to it's active status*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(SevenSegmentS[Loc_U8SevenSegmentNum].LEDC_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDC_Pin,Loc_u8SevenSegmentActiveStatus);
				break ;
			/*For Led D in 7 Segment*/
			case SevenSegment_enumLedD :
				/*Set PIN as an Output PIN*/
				DIO_enumSetPinConfig(SevenSegmentS[Loc_U8SevenSegmentNum].LEDD_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDD_Pin, DIO_enumOutput);
				/*Put an Initial Value to The PIN according to it's active status*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(SevenSegmentS[Loc_U8SevenSegmentNum].LEDD_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDD_Pin,Loc_u8SevenSegmentActiveStatus);
				break ;
			/*For Led E in 7 Segment*/
			case SevenSegment_enumLedE :
				/*Set PIN as an Output PIN*/
				DIO_enumSetPinConfig(SevenSegmentS[Loc_U8SevenSegmentNum].LEDE_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDE_Pin, DIO_enumOutput);
				/*Put an Initial Value to The PIN according to it's active status*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(SevenSegmentS[Loc_U8SevenSegmentNum].LEDE_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDE_Pin,Loc_u8SevenSegmentActiveStatus);
				break ;
			/*For Led F in 7 Segment*/
			case SevenSegment_enumLedF :
				/*Set PIN as an Output PIN*/
				DIO_enumSetPinConfig(SevenSegmentS[Loc_U8SevenSegmentNum].LEDF_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDF_Pin, DIO_enumOutput);
				/*Put an Initial Value to The PIN according to it's active status*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(SevenSegmentS[Loc_U8SevenSegmentNum].LEDF_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDF_Pin,Loc_u8SevenSegmentActiveStatus);
				break ;
			/*For Led G in 7 Segment*/
			case SevenSegment_enumLedG :
				/*Set PIN as an Output PIN*/
				DIO_enumSetPinConfig(SevenSegmentS[Loc_U8SevenSegmentNum].LEDG_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDG_Pin, DIO_enumOutput);
				/*Put an Initial Value to The PIN according to it's active status*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(SevenSegmentS[Loc_U8SevenSegmentNum].LEDG_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDG_Pin,Loc_u8SevenSegmentActiveStatus);
				break ;
			/*For Led DP in 7 Segment*/
			case SevenSegment_enumLedDP :
				/*Set PIN as an Output PIN*/
				DIO_enumSetPinConfig(SevenSegmentS[Loc_U8SevenSegmentNum].LEDDP_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDDP_Pin, DIO_enumOutput);
				/*Put an Initial Value to The PIN according to it's active status*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(SevenSegmentS[Loc_U8SevenSegmentNum].LEDDP_Port, SevenSegmentS[Loc_U8SevenSegmentNum].LEDDP_Pin,Loc_u8SevenSegmentActiveStatus);
				break ;
			default :
				/*Return Error State by Wrong configuration*/
				Loc_enumReturnErrorDIOErrorState = DIO_enumWrongConfig;
				break ;
			}
		}
		else
		{
			/*Return Error State by Wrong Active status configuration*/
			Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumWrongActiveStatus;
		}

	}

	/* Handle different DIO error states */
	switch (Loc_enumReturnErrorDIOErrorState)
	{
	case DIO_enumWrongPort:
		/* Set SevenSegment error state to WrongPort */
		Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumWrongPort;
		break;
	case DIO_enumWrongPin:
		/* Set SevenSegment error state to WrongPin */
		Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumWrongPin;
		break;
	case DIO_enumWrongConfig:
		/* Set SevenSegment error state to WrongConfig */
		Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumWrongConfig;
		break;
	default:
		/* Set SevenSegment error state to OK */
		Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk;
		break;
	}



	/* Return the final SevenSegment error state */
	return Loc_enumReturnErrorSevenSegmentErrorState;
}

/**
 *@brief  : Function to set value to specific SevenSegment
 *@param  : SevenSegment name , Value of desired Output
 *@return : Error State                                                                      
 */
SevenSegment_enumErrorStatus_t SevenSegment_enumSetValue(uint8 Copy_u8SegName, uint8 Value)
{
	/* Declare variables to store error states for DIO and SevenSegment operations */
	SevenSegment_enumErrorStatus_t Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk;
	/* Declare variables to store error states for DIO and SevenSegment operations */
	uint8 Loc_u8SevenSegmentActiveStatus = 0 ;
	/* Check if the provided seven-segment index is within valid range */
	if (Copy_u8SegName >= NUM_OF_SEVENSEGMENTS)
	{
		Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumWrongSevenSegment ;
	}
	/* Check if the provided value is within the valid range (0-9) */
	else if (!((Value>=0)&&(Value<=9)))
	{
		Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumWrongValue ;
	}
	else 
	{
		/* Check the active status of the seven-segment display (Common Cathode or Common Anode) */
		if (SevenSegmentS[Copy_u8SegName].Active_Status==SevenSegment_enum_CommonCathode)
		{	
			/*Set return status variable for seven segment by OK*/
			Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk ;
			/*Set a value in Loc_u8SevenSegmentActiveStatus to Illuminate common cathode LEDS in 7 segment*/
			Loc_u8SevenSegmentActiveStatus = DIO_enumLogicHigh ;
		}
		else if (SevenSegmentS[Copy_u8SegName].Active_Status==SevenSegment_enum_CommonAnode)
		{
			/*Set return status variable for seven segment by OK*/
			Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk ;
			/*Set a value in Loc_u8SevenSegmentActiveStatus to Illuminate common Anode LEDS in 7 segment*/
			Loc_u8SevenSegmentActiveStatus = DIO_enumLogicLow ;
		}
		else
		{
			/*Return Error State by Wrong configuration*/
			Loc_enumReturnErrorSevenSegmentErrorState= SevenSegment_enumWrongConfig;
		}

		if (Loc_enumReturnErrorSevenSegmentErrorState == SevenSegment_enumOk )
		{
			/* Set the appropriate LED segments for the Common Cathode display */
			switch (Value)
			{
			/*Print the value of number '0' on Seven Segment*/
			case 0 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '1' on Seven Segment*/
			case 1 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '2' on Seven Segment*/
			case 2 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '3' on Seven Segment*/
			case 3 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '4' on Seven Segment*/
			case 4 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '5' on Seven Segment*/
			case 5 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '6' on Seven Segment*/
			case 6 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '7' on Seven Segment*/
			case 7 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '8' on Seven Segment*/
			case 8 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
				/*Print the value of number '9' on Seven Segment*/
			case 9 :
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDA_Port, SevenSegmentS[Copy_u8SegName].LEDA_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDB_Port, SevenSegmentS[Copy_u8SegName].LEDB_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDC_Port, SevenSegmentS[Copy_u8SegName].LEDC_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDD_Port, SevenSegmentS[Copy_u8SegName].LEDD_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDE_Port, SevenSegmentS[Copy_u8SegName].LEDE_Pin, !Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDF_Port, SevenSegmentS[Copy_u8SegName].LEDF_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDG_Port, SevenSegmentS[Copy_u8SegName].LEDG_Pin, Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(SevenSegmentS[Copy_u8SegName].LEDDP_Port, SevenSegmentS[Copy_u8SegName].LEDDP_Pin,!Loc_u8SevenSegmentActiveStatus);
				break;
			default :
				break ;
			}
		}
	}
	/*Return error status*/
	return Loc_enumReturnErrorSevenSegmentErrorState ;
}

/**
 * @brief   Function to set a common value for all SevenSegment displays.
 * @param   Value: The value to be displayed on all SevenSegment displays.
 * @return  Error State indicating the success or failure of the operation.
 *
 */
SevenSegment_enumErrorStatus_t SevenSegment_enumSetValueForAll(uint32 Value)
{
	/* Declare variables to store error states for DIO and SevenSegment operations */
	SevenSegment_enumErrorStatus_t Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk;
	/* Declare variables to store the value which we are operationg on */
	uint32 Loc_u32CountNumberOfDigits = Value ;
	/* Declare a counter for looping*/
	uint8 counter =0 ;
	/*Count number of digits for given decimal number from value variable*/
	while (Loc_u32CountNumberOfDigits>=1)
	{
		counter ++ ;
		Loc_u32CountNumberOfDigits=Loc_u32CountNumberOfDigits/10 ;
	}
	/*Check if the value exceed uint32 range and if the number is suitable for number of seven segment or not*/
	if ( (Value>MAX_UINT32_NUM) || (NUM_OF_SEVENSEGMENTS < counter) )
	{
		Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumWrongValue ;
	}
	else
	{
		Loc_enumReturnErrorSevenSegmentErrorState = SevenSegment_enumOk ;
		/*Reset counter value by zero*/
		counter = 0 ;
		/*Reassign Loc_u32CountNumberOfDigits with value*/
		Loc_u32CountNumberOfDigits = Value ;
		/*Assign each digit in suitable seven segment for it*/
		for (counter =0 ;  counter<NUM_OF_SEVENSEGMENTS ; counter++)
		{
			/*Detect the number while be assigned it the current seven segment*/
			Value = Loc_u32CountNumberOfDigits % 10 ;
			/*Assign the number in the current seven segment*/
			SevenSegment_enumSetValue(counter,Value);
			/*Calculate the new number for next iterate*/
			Loc_u32CountNumberOfDigits = Loc_u32CountNumberOfDigits /10 ;
		}
	}
	/*Return error status*/
	return Loc_enumReturnErrorSevenSegmentErrorState ;
}




