/*
 ============================================================================
 Name        : SWITCH.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the SWITCH driver
 Date        : 12/12/2023
 ============================================================================
 */

#include "MCAL/DIO.h"
#include "CFG/SWITCH_cfg.h"
#include "HAL/SWITCH.h"

/**
 * @brief  : Function to Configure the Pins of SWITCH.
 * @param  : Void.
 * @return : Error State
 */
SWITCH_enumErrorStatus_t SWITCH_enumInit(void)
{
    /* Declare variables to store error states for DIO and SWITCH operations */
    DIO_enumError_t Loc_enumReturnErrorDIOErrorState = DIO_enumOk;
    SWITCH_enumErrorStatus_t Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumOk;

    /* Check if the total number of SWITCHs is within the valid range */
    if (NUM_OF_SWITCHS <= (NUM_OF_PORTS * NUM_OF_PINS))
    {
    	/* Set SWITCH error state to OK */
        Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumOk; 
    }
    else
    {
    	/* Set SWITCH error state to WrongPin */
        Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongPin; 
    }

    /* Loop through each SWITCH and configure its corresponding DIO pin */
    for (int counter = 0; ((counter < NUM_OF_SWITCHS) && (Loc_enumReturnErrorSWITCHErrorState == SWITCH_enumOk)); counter++)
    {

    if (SWITCHS[counter].Active_Status==SWITCH_enum_PullUpRes)
    {
        /* Set the DIO pin configuration for the current SWITCH */
        Loc_enumReturnErrorDIOErrorState = DIO_enumSetPinConfig(SWITCHS[counter].Port, SWITCHS[counter].Pin, DIO_enumInputInternalPU);
        /* Handle different DIO error states */
        switch (Loc_enumReturnErrorDIOErrorState)
        {
        case DIO_enumWrongPort:
        	/* Set SWITCH error state to WrongPort */
            Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongPort; 
            break;
        case DIO_enumWrongPin:
        	/* Set SWITCH error state to WrongPin */
            Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongPin; 
            break;
        case DIO_enumWrongConfig:
        	/* Set SWITCH error state to WrongConfig */
            Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongConfig; 
            break;
        default:
        	/* Set SWITCH error state to OK */
            Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumOk; 
            break;
        }
    }
    else if (SWITCHS[counter].Active_Status==SWITCH_enum_ExternalPullDown)
    {
        /* Set the DIO pin configuration for the current SWITCH */
        Loc_enumReturnErrorDIOErrorState = DIO_enumSetPinConfig(SWITCHS[counter].Port, SWITCHS[counter].Pin, DIO_enumInputExternalPD);
        /* Handle different DIO error states */
        switch (Loc_enumReturnErrorDIOErrorState)
        {
        case DIO_enumWrongPort:
            /* Set SWITCH error state to WrongPort */
            Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongPort; 
            break;
        case DIO_enumWrongPin:
            /* Set SWITCH error state to WrongPin */
            Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongPin; 
            break;
        case DIO_enumWrongConfig:
            /* Set SWITCH error state to WrongConfig */
            Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongConfig; 
            break;
        default:
            /* Set SWITCH error state to OK */
            Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumOk; 
            break;
        }
    }
      
    else
    {
         Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongConfig;   
    }
    }
    /* Return the final SWITCH error state */
    return Loc_enumReturnErrorSWITCHErrorState;
}

/**
 *@brief  : Function to Read value to specific SWITCH
 *@param  : SWITCH name , Value of desired Output
 *@return : Error State                                                                      
 */
SWITCH_enumErrorStatus_t SWITCH_enumReadValue(uint8 Copy_u8SwitchName,uint8* Add_u8State)
{
    /* Declare variables to store error states for DIO and SWITCH operations */
    SWITCH_enumErrorStatus_t Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumOk;
    DIO_enumError_t Loc_enumReturnErrorDIOErrorState = DIO_enumOk;

    /* Check if the SWITCH index is within the valid range */
    if (Copy_u8SwitchName > NUM_OF_SWITCHS)
    {
    	/* Set SWITCH error state to WrongSWITCH */
        Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumWrongSWITCH; 
    }
    /* Check if the SWITCH value is within the valid range */
    else if (Add_u8State == NULL)
    {
    	/* Set SWITCH error state to WrongConfig */
        Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumNullPointer; 
    }
    else
    {
    	/* Set SWITCH error state to OK */
        Loc_enumReturnErrorSWITCHErrorState = SWITCH_enumOk; 
        Loc_enumReturnErrorDIOErrorState= DIO_enumReadState(SWITCHS[Copy_u8SwitchName].Port,SWITCHS[Copy_u8SwitchName].Pin,Add_u8State);
    }
    return Loc_enumReturnErrorSWITCHErrorState;
}
