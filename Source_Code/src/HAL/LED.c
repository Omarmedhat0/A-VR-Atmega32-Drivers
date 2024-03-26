/*
 ============================================================================
 Name        : LED.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the LED driver
 Date        : 12/12/2023
 ============================================================================
 */
#include "MCAL/DIO.h"
#include "HAL/LED.h"

extern LED_strCfg LEDS[NUM_OF_LEDS] ;

/**
 * @brief  : Function to Configure the Pins of LED.
 * @param  : Void.
 * @return : Error State
 */
LED_enumErrorStatus_t LED_enumInit(void)
{
    /* Declare variables to store error states for DIO and LED operations */
    DIO_enumError_t Loc_enumReturnErrorDIOErrorState = DIO_enumOk;
    LED_enumErrorStatus_t Loc_enumReturnErrorLEDErrorState = LED_enumOk;

    /* Check if the total number of LEDs is within the valid range */
    if (NUM_OF_LEDS <= (NUM_OF_PORTS * NUM_OF_PINS))
    {
    	/* Set LED error state to OK */
        Loc_enumReturnErrorLEDErrorState = LED_enumOk; 
    }
    else
    {
    	/* Set LED error state to WrongPin */
        Loc_enumReturnErrorLEDErrorState = LED_enumWrongPin; 
    }

    /* Loop through each LED and configure its corresponding DIO pin */
    for (int counter = 0; ((counter < NUM_OF_LEDS) && (Loc_enumReturnErrorLEDErrorState == LED_enumOk)); counter++)
    {
        /* Set the DIO pin configuration for the current LED */
        Loc_enumReturnErrorDIOErrorState = DIO_enumSetPinConfig(LEDS[counter].Port, LEDS[counter].Pin, DIO_enumOutput);

        /* Handle different DIO error states */
        switch (Loc_enumReturnErrorDIOErrorState)
        {
        case DIO_enumWrongPort:
        	/* Set LED error state to WrongPort */
            Loc_enumReturnErrorLEDErrorState = LED_enumWrongPort; 
            break;
        case DIO_enumWrongPin:
        	/* Set LED error state to WrongPin */
            Loc_enumReturnErrorLEDErrorState = LED_enumWrongPin; 
            break;
        case DIO_enumWrongConfig:
        	/* Set LED error state to WrongConfig */
            Loc_enumReturnErrorLEDErrorState = LED_enumWrongConfig; 
            break;
        default:
        	/* Set LED error state to OK */
            Loc_enumReturnErrorLEDErrorState = LED_enumOk; 
            break;
        }

        /* If DIO operation is successful, configure the LED's active and output status */
        if (Loc_enumReturnErrorLEDErrorState == LED_enumOk)
        {
            switch (LEDS[counter].Active_Status)
            {
            case LED_enum_ActiveLow:
                /* Configure the DIO pin based on active and output status for ActiveLow LED */
                switch (LEDS[counter].Output_Status)
                {
                case LED_enum_Off:
                	/* Turn off the LED */
                    Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(LEDS[counter].Port, LEDS[counter].Pin, DIO_enumLogicHigh); 
                    break;
                case LED_enum_On:
                	/* Turn on the LED */
                    Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(LEDS[counter].Port, LEDS[counter].Pin, DIO_enumLogicLow); 
                    break;
                default:
                	/* Set LED error state to WrongOutputState */
                    Loc_enumReturnErrorLEDErrorState = LED_enumWrongOutputState; 
                    break;
                }
                break;
            case LED_enum_ActiveHigh:
                /* Configure the DIO pin based on active and output status for ActiveHigh LED */
                switch (LEDS[counter].Output_Status)
                {
                case LED_enum_Off:
                	/* Turn off the LED */
                    Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(LEDS[counter].Port, LEDS[counter].Pin, DIO_enumLogicLow); 
                    break;
                case LED_enum_On:
                	/* Turn on the LED */
                    Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(LEDS[counter].Port, LEDS[counter].Pin, DIO_enumLogicHigh); 
                    break;
                    /* Set LED error state to WrongOutputState */
                default:
                    Loc_enumReturnErrorLEDErrorState = LED_enumWrongOutputState; 
                    break;
                }
                break;
            default:
            	/* Set LED error state to WrongActiveStatus */
                Loc_enumReturnErrorLEDErrorState = LED_enumWrongActiveStatus; 
                break;
            }
        }
        else
        {
            /* Do Nothing */
        }
    }

    /* Return the final LED error state */
    return Loc_enumReturnErrorLEDErrorState;
}

/**
 * @brief  : Function to set value to a specific LED.
 * @param  : LED name, Value of desired Output
 * @return : Error State
 */
LED_enumErrorStatus_t LED_enumSetLedState(uint8 Copy_u8LedName, uint8 Copy_u8State)
{
    /* Declare variables to store error states for DIO and LED operations */
    LED_enumErrorStatus_t Loc_enumReturnErrorLEDErrorState = LED_enumOk;
    DIO_enumError_t Loc_enumReturnErrorDIOErrorState = DIO_enumOk;

    /* Check if the LED index is within the valid range */
    if (Copy_u8LedName > NUM_OF_LEDS)
    {
    	/* Set LED error state to WrongLed */
        Loc_enumReturnErrorLEDErrorState = LED_enumWrongLed; 
    }
    /* Check if the LED value is within the valid range */
    else if (Copy_u8State > LED_enumLogicHigh)
    {
    	/* Set LED error state to WrongConfig */
        Loc_enumReturnErrorLEDErrorState = LED_enumWrongConfig; 
    }
    else
    {
    	/* Set LED error state to OK */
        Loc_enumReturnErrorLEDErrorState = LED_enumOk; 

        /* Check the active status of the LED and set the corresponding DIO pin */
        switch (LEDS[Copy_u8LedName].Active_Status)
        {
        case LED_enum_ActiveLow:
        {
            /* Configure the DIO pin based on the active and output status for ActiveLow LED */
            if (Copy_u8State == LED_enumLogicLow)
            {	
            	/* Turn LED Off*/
                Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(LEDS[Copy_u8LedName].Port, LEDS[Copy_u8LedName].Pin, DIO_enumLogicHigh);
            }
            else if (Copy_u8State == LED_enumLogicHigh)
            {	
            	/* Turn LED On*/
                Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(LEDS[Copy_u8LedName].Port, LEDS[Copy_u8LedName].Pin, DIO_enumLogicLow);
            }
            else
            {	/* Set LED error state to WrongOutputState */
                Loc_enumReturnErrorLEDErrorState = LED_enumWrongOutputState; 
            }
            break;
        }
        case LED_enum_ActiveHigh:
        {
            /* Configure the DIO pin based on the active and output status for ActiveHigh LED */
            if (Copy_u8State == LED_enumLogicLow)
            {
            	/* Turn LED Off*/
                Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(LEDS[Copy_u8LedName].Port, LEDS[Copy_u8LedName].Pin, DIO_enumLogicLow);
            }
            else if (Copy_u8State == LED_enumLogicHigh)
            {
            	/* Turn LED On*/
                Loc_enumReturnErrorDIOErrorState = DIO_enumSetPin(LEDS[Copy_u8LedName].Port, LEDS[Copy_u8LedName].Pin, DIO_enumLogicHigh);
            }
            else
            {
            	/* Set LED error state to WrongOutputState */
                Loc_enumReturnErrorLEDErrorState = LED_enumWrongOutputState; 
            }
            break;
        }
        default:
        	/* Set LED error state to WrongActiveStatus */
            Loc_enumReturnErrorLEDErrorState = LED_enumWrongActiveStatus; 
            break;
        }
    }

    /* Return the final LED error state */
    return Loc_enumReturnErrorLEDErrorState;
}
