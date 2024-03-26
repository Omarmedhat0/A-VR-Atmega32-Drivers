/*
 ============================================================================
 Name        : DIO.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the DIO driver
 Date        : 3/12/2023
 ============================================================================
 */
#include "MCAL/DIO.h"

/* Function to set the configuration of an individual pin */
/**
 @brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 @param  : Port Number,Pin Number,Configuration type(Input/Output).
 @return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig)
{
	/* Variable to hold the error status */
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk ;

	/* Check if the provided port number is valid */
	if (Copy_enumPortNum > NUM_OF_PORTS)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort ;
	}
	/* Check if the provided pin number is valid */
	else if (Copy_enumPinNum > NUM_OF_PINS)
	{
		Ret_enumErrorStatus = DIO_enumWrongPin ;
	}
	/* Check if the provided configuration is valid */
	else if (Copy_enumConfig > DIO_enumInputExternalPD)
	{
		Ret_enumErrorStatus = DIO_enumWrongConfig  ;
	}
	/* If all parameters are valid, proceed with the configuration */
	else
	{
		Ret_enumErrorStatus = DIO_enumOk ;
		/* Switch based on the provided port number */
		switch (Copy_enumPortNum)
		{
		case DIO_enumPortA :
		{
			/* Switch based on the provided configuration */
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput :
			{
				/* Set the pin as an output for Port A */
				SET_BIT(DDRA,Copy_enumPinNum);
				break ;
			}
			case DIO_enumInputInternalPU :
			{
				/* Set the pin as an input with internal pull-up resistor for Port A */
				CLEAR_BIT(DDRA,Copy_enumPinNum);
				SET_BIT(PORTA,Copy_enumPinNum);
				break ;
			}
			case DIO_enumInputExternalPD :
			{
				/* Set the pin as an input with external pull-down resistor for Port A */
				CLEAR_BIT(DDRA,Copy_enumPinNum);
				CLEAR_BIT(PORTA,Copy_enumPinNum);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortD :
		{
			/* Switch based on the provided configuration */
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput :
			{
				/* Set the pin as an output for Port D */
				SET_BIT(DDRD,Copy_enumPinNum);
				break ;
			}
			case DIO_enumInputInternalPU :
			{
				/* Set the pin as an input with internal pull-up resistor for Port D */
				CLEAR_BIT(DDRD,Copy_enumPinNum);
				SET_BIT(PORTD,Copy_enumPinNum);
				break ;
			}
			case DIO_enumInputExternalPD :
			{
				/* Set the pin as an input with external pull-down resistor for Port D */
				CLEAR_BIT(DDRD,Copy_enumPinNum);
				CLEAR_BIT(PORTD,Copy_enumPinNum);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortB :
		{
			/* Switch based on the provided configuration */
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput :
			{
				/* Set the pin as an output for Port B */
				SET_BIT(DDRB,Copy_enumPinNum);
				break ;
			}
			case DIO_enumInputInternalPU :
			{
				/* Set the pin as an input with internal pull-up resistor for Port B */
				CLEAR_BIT(DDRB,Copy_enumPinNum);
				SET_BIT(PORTB,Copy_enumPinNum);
				break ;
			}
			case DIO_enumInputExternalPD :
			{
				/* Set the pin as an input with external pull-down resistor for Port B */
				CLEAR_BIT(DDRB,Copy_enumPinNum);
				CLEAR_BIT(PORTB,Copy_enumPinNum);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortC :
		{ /* Set the pin as an output for Port C */
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput :
			{
				SET_BIT(DDRC,Copy_enumPinNum);
				break ;
			}
			case DIO_enumInputInternalPU :
			{
				/* Set the pin as an input with internal pull-up resistor for Port C */
				CLEAR_BIT(DDRC,Copy_enumPinNum);
				SET_BIT(PORTC,Copy_enumPinNum);
				break ;
			}
			case DIO_enumInputExternalPD :
			{
				/* Set the pin as an input with external pull-down resistor for Port C */
				CLEAR_BIT(DDRC,Copy_enumPinNum);
				CLEAR_BIT(PORTC,Copy_enumPinNum);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		default :
			break ;
		}
	}
	/* Return the error status */
	return Ret_enumErrorStatus;
}

/* Function to set the configuration of an entire port */
/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	/* Variable to hold the error status */
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk ;

	/* Check if the provided port number is valid */
	if (Copy_enumPortNum > NUM_OF_PORTS)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort ;
	}
	/* Check if the provided configuration is valid */
	else if (Copy_enumConfig > DIO_enumInputExternalPD)
	{
		Ret_enumErrorStatus = DIO_enumWrongConfig  ;
	}
	/* If all parameters are valid, proceed with the configuration */
	else
	{
		Ret_enumErrorStatus = DIO_enumOk ;

		/* Switch based on the provided port number */
		switch(Copy_enumPortNum)
		{
		case DIO_enumPortA :
		{
			/* Switch based on the provided configuration */
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput:
			{
				/* Set the entire port as output for Port A */
				ASSIGN_REG(DDRA,0xFF);
				break ;
			}
			case DIO_enumInputInternalPU:
			{
				/* Set the entire port as input with internal pull-up resistors for Port A */
				ASSIGN_REG(DDRA,0x00);
				ASSIGN_REG(PORTA,0xFF);
				break ;
			}
			case DIO_enumInputExternalPD:
			{
				/* Set the entire port as input with external pull-down resistors for Port A */
				ASSIGN_REG(DDRA,0x00);
				ASSIGN_REG(PORTA,0x00);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortB :
		{
			/* Switch based on the provided configuration */
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput:
			{
				/* Set the entire port as output for Port B */
				ASSIGN_REG(DDRB,0xFF);
				break ;
			}
			case DIO_enumInputInternalPU:
			{
				/* Set the entire port as input with internal pull-up resistors for Port B */
				ASSIGN_REG(DDRB,0x00);
				ASSIGN_REG(PORTB,0xFF);
				break ;
			}
			case DIO_enumInputExternalPD:
			{
				/* Set the entire port as input with external pull-down resistors for Port B */
				ASSIGN_REG(DDRB,0x00);
				ASSIGN_REG(PORTB,0x00);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortC :
		{
			/* Switch based on the provided configuration */
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput:
			{
				/* Set the entire port as output for Port C */
				ASSIGN_REG(DDRC,0xFF);
				break ;
			}
			case DIO_enumInputInternalPU:
			{
				/* Set the entire port as input with internal pull-up resistors for Port C */
				ASSIGN_REG(DDRC,0x00);
				ASSIGN_REG(PORTC,0xFF);
				break ;
			}
			case DIO_enumInputExternalPD:
			{
				/* Set the entire port as input with external pull-down resistors for Port C */
				ASSIGN_REG(DDRC,0x00);
				ASSIGN_REG(PORTC,0x00);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortD :
		{
			/* Switch based on the provided configuration */
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput:
			{
				/* Set the entire port as output for Port D */
				ASSIGN_REG(DDRD,0xFF);
				break ;
			}
			case DIO_enumInputInternalPU:
			{
				/* Set the entire port as input with internal pull-up resistors for Port D */
				ASSIGN_REG(DDRD,0x00);
				ASSIGN_REG(PORTD,0xFF);
				break ;
			}
			case DIO_enumInputExternalPD:
			{
				/* Set the entire port as input with external pull-down resistors for Port D */
				ASSIGN_REG(DDRD,0x00);
				ASSIGN_REG(PORTD,0x00);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		default :
			break ;
		}
	}
	/* Return the error status */
	return Ret_enumErrorStatus ;
}

/* Function to set the logic state of an individual pin */
/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	/* Variable to hold the error status */
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk ;

	/* Check if the provided port number is valid */
	if (Copy_enumPortNum > NUM_OF_PORTS)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort ;
	}
	/* Check if the provided pin number is valid */
	else if (Copy_enumPinNum > NUM_OF_PINS)
	{
		Ret_enumErrorStatus = DIO_enumWrongPin ;
	}
		/* If all parameters are valid, proceed with setting the logic state */
	else
	{
		Ret_enumErrorStatus = DIO_enumOk ;

		/* Switch based on the provided port number */
		switch(Copy_enumPortNum)
		{
		case DIO_enumPortA :
		{
			/* Switch based on the provided logic state */
			switch(Copy_enumLogicState)
			{
			case DIO_enumLogicLow :
			{
				/* Set the pin to logic low for Port A */
				CLEAR_BIT(PORTA,Copy_enumPinNum);
				break ;
			}
			case DIO_enumLogicHigh :
			{
				/* Set the pin to logic high for Port A */
				SET_BIT(PORTA,Copy_enumPinNum);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortB :
		{
			/* Set the pin to logic high for Port B */
			switch(Copy_enumLogicState)
			{
			case DIO_enumLogicLow :
			{
				/* Set the pin to logic low for Port B */
				CLEAR_BIT(PORTB,Copy_enumPinNum);
				break ;
			}
			case DIO_enumLogicHigh :
			{
				/* Set the pin to logic high for Port B */
				SET_BIT(PORTB,Copy_enumPinNum);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortC :
		{
			/* Switch based on the provided logic state */
			switch(Copy_enumLogicState)
			{
			case DIO_enumLogicLow :
			{
				/* Set the pin to logic low for Port C */
				CLEAR_BIT(PORTC,Copy_enumPinNum);
				break ;
			}
			case DIO_enumLogicHigh :
			{
				/* Set the pin to logic high for Port C */
				SET_BIT(PORTC,Copy_enumPinNum);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortD :
		{
			/* Switch based on the provided logic state */
			switch(Copy_enumLogicState)
			{
			case DIO_enumLogicLow :
			{
				/* Set the pin to logic low for Port D */
				CLEAR_BIT(PORTD,Copy_enumPinNum);
				break ;
			}
			case DIO_enumLogicHigh :
			{
				/* Set the pin to logic high for Port D */
				SET_BIT(PORTD,Copy_enumPinNum);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		default :
			break;
		}
	}
	/* Return the error status */
	return Ret_enumErrorStatus ;
}

/* Function to set the logic state of an entire port */
/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	/* Variable to hold the error status */
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk ;
	if (Copy_enumPortNum > NUM_OF_PORTS)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort ;
	}
	/* If the port number is valid, proceed with setting the logic */
	else
	{
		Ret_enumErrorStatus = DIO_enumOk ;
		/* Switch based on the provided port number */
		switch(Copy_enumPortNum)
		{
		case DIO_enumPortA :
		{
			/* Switch based on the provided logic state */
			switch(Copy_enumLogicState)
			{
			case DIO_enumLogicLow :
			{
				/* Set the entire port to logic low for Port A */
				ASSIGN_REG(PORTA,0x00);
				break ;
			}
			case DIO_enumLogicHigh :
			{
				/* Set the entire port to logic high for Port A */
				ASSIGN_REG(PORTA,0XFF);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortB :
		{
			/* Switch based on the provided logic state */
			switch(Copy_enumLogicState)
			{

			case DIO_enumLogicLow :
			{
				/* Set the entire port to logic low for Port B */
				ASSIGN_REG(PORTB,0x00);
				break ;
			}
			case DIO_enumLogicHigh :
			{
				/* Set the entire port to logic high for Port B */
				ASSIGN_REG(PORTB,0XFF);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortC :
		{
			/* Switch based on the provided logic state */
			switch(Copy_enumLogicState)
			{
			case DIO_enumLogicLow :
			{
				/* Set the entire port to logic low for Port C*/
				ASSIGN_REG(PORTC,0x00);
				break ;
			}
			case DIO_enumLogicHigh :
			{
				/* Set the entire port to logic high for Port C */
				ASSIGN_REG(PORTC,0XFF);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		case DIO_enumPortD :
		{
			/* Switch based on the provided logic state */
			switch(Copy_enumLogicState)
			{
			case DIO_enumLogicLow :
			{
				/* Set the entire port to logic low for Port D */
				ASSIGN_REG(PORTD,0x00);
				break ;
			}
			case DIO_enumLogicHigh :
			{
				/* Set the entire port to logic high for Port D */
				ASSIGN_REG(PORTD,0XFF);
				break ;
			}
			default :
				break ;
			}
			break ;
		}
		default :
			break;
		}
	}
	/* Return the error status */
	return Ret_enumErrorStatus ;
}

/* Function to read the logic state of an individual pin */
/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	/* Variable to hold the error status */
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumOk ;

	/* Check if the provided port number is valid */
	if (Copy_enumPortNum > NUM_OF_PORTS)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort ;
	}
	/* Check if the provided pin number is valid */
	else if (Copy_enumPinNum > NUM_OF_PINS)
	{
		Ret_enumErrorStatus = DIO_enumWrongPin ;
	}
	else if (Add_Pu8PinValue == NULL)
	{
		Ret_enumErrorStatus =DIO_enumNullPointer ;
	}
	/* If all parameters are valid, proceed with reading the logic state */
	else
	{
		Ret_enumErrorStatus = DIO_enumOk ;
		/* Switch based on the provided port number */
		switch(Copy_enumPortNum)
		{
		case DIO_enumPortA :
		{
			/* Check the logic state of the pin for Port A and update the pointer value accordingly */
			if (PINA & (1<<Copy_enumPinNum))
			{
				*Add_Pu8PinValue = DIO_enumLogicHigh ;
			}
			else
			{
				*Add_Pu8PinValue =DIO_enumLogicLow;
			}
			break ;
		}
		case DIO_enumPortB :
		{
			/* Check the logic state of the pin for Port B and update the pointer value accordingly */
			if (PINB & (1<<Copy_enumPinNum))
			{
				*Add_Pu8PinValue = DIO_enumLogicHigh ;
			}
			else
			{
				*Add_Pu8PinValue =DIO_enumLogicLow;
			}
			break ;
		}
		case DIO_enumPortC :
		{
			/* Check the logic state of the pin for Port C and update the pointer value accordingly */
			if (PINC & (1<<Copy_enumPinNum))
			{
				*Add_Pu8PinValue = DIO_enumLogicHigh ;
			}
			else
			{
				*Add_Pu8PinValue =DIO_enumLogicLow;
			}
			break ;
		}
		case DIO_enumPortD :
		{
			/* Check the logic state of the pin for Port D and update the pointer value accordingly */
			if (PIND & (1<<Copy_enumPinNum))
			{
				*Add_Pu8PinValue = DIO_enumLogicHigh ;
			}
			else
			{
				*Add_Pu8PinValue =DIO_enumLogicLow;
			}
			break ;
		}
		default :
			break ;
		}
	}
	/* Return the error status */
	return Ret_enumErrorStatus ;
}
//Delay Function
/*
 * @brief   : Function to create a delay in milliseconds using a simple loop.
 * @param   : time - The duration of the delay in milliseconds.
 * @return  : None
 */
void DIO_DelayMs (uint16 time)
{
	uint16 i , j ;
	for (i=0;i<time;i++)
		for(j=0;j<100;j++);
}


